#define KERNEL

#include <freehdl/kernel-wait-info.hh>
#include <freehdl/kernel-reader-info.hh>
#include <freehdl/kernel-driver-info.hh>
#include <freehdl/kernel-resolver-process.hh>


bool
resolver_process::execute()
{
  // Execute resolution function
  (*handler)(resolved_reader, driver, &driver_array, (array_info*)driver_array.info->index_type);
}


// Creates a resolver process which will be used to resolve signal
// values
resolver_process::resolver_process(sig_info_base *signal, signal_source_list *source_list, void *comp, int level)
{
  // initialize resolver_process. This procss will be responsible for
  // resolving a signal or group of signals.
  handler = source_list->resolver->handler;
  
  list<signal_source> &sources = source_list->sources;
  array_info *base_array_info = (array_info*)source_list->resolver->ainfo;

  // Create the driver array and initialize elements with the
  // corresponding value of the resolved signal
  driver_array.info = NULL;
  driver_array.data = NULL;
  (new array_info(base_array_info->element_type, base_array_info, sources.size(), -1))->init(&driver_array);
  array_info *ainfo = (array_info*)driver_array.info;
  type_info_interface *driver_type_info = ainfo->element_type;
  char *src_element = (char*)signal->type->element(signal->reader_pointer, source_list->index_start);
  char *dest_element = driver_array.data;
  // Copy initial value to each of the drivers
  for (unsigned int i = 0; i < sources.size(); i++) {
    driver_type_info->copy(dest_element, src_element);
    dest_element += driver_type_info->size;
  }

  // Create object to store the result of the resolution operation.
  resolved_reader = base_array_info->element_type->create();
  resolved_type_id = base_array_info->element_type->id;
  active_wait_id = 0;
  jmp = level;

  const bool scalar = base_array_info->element_type->scalar();

  // Create and initialize drivers for the resolution process. Note
  // that the resolution process has its own driver(s) which is (are)
  // used to assign the resolved value. These driver(s) is (are)
  // actually nothing else than a copy of the original drivers of the
  // signal sources. Note that a reolution process may be associated
  // with more than a single scalar value (e.g., if a resolution
  // process is associated with a record type, then all scalars
  // (directly or indirectly) belonging to the record are associated
  // with this process).
  if (scalar)
    driver = new driver_info(this, signal, source_list->index_start);

  else {
    driver_info **drv_array = new driver_info*[source_list->size];

    for (int i = 0; i < source_list->size; i++)
      drv_array[i] = new driver_info(this, signal, source_list->index_start + i);

    driver = new driver_info(this, NULL, driver_type_info, 0, drv_array, source_list->size);
  }

  // Next, create appropriate reader_info instance. The original
  // read_info instances which were used at the first place are now
  // replaced by some *special* instances. These special instances do
  // not directly belong to the corresponding signal. Instead, they
  // are connected with the resolution process. Hence, if a source
  // writes to a signal it does create a transaction to be assigned to
  // this *special* reader (instead of the original signal
  // reader). This *special* reader will then trigger the resolution
  // process to perform the resolution mechanism. Note that the
  // resolution process is a special process.
  const int driver_size = ainfo->element_type->size;
  // Create a wait info element. This element will be used to trigger
  // the resolution process. Note that we set the wait_id of the
  // wait_info instance to PRIORITY_PROCESS to indicate a special
  // internal process. This process will be executed *before* normal
  // processes.
  wait_info wait_elem(PRIORITY_PROCESS, this); 
  // Analyze each scalar for all sources of the resolved signal.
  int driver_index = 0;
  for (list<signal_source>::iterator iter = sources.begin();
       iter != sources.end();
       iter++, driver_index++) {
    // The driver array takes the different driver values of the
    // signal sources. Hence, select a different element of the array
    // for each source.
    void *driver_p = &driver_array.data[driver_index * driver_size];
    // Next, step through each scalar of a single source. Note that
    // each source may consist of more than a single scalar! 
    for (unsigned int scalar_index = 0; scalar_index < (*iter).drivers.size(); scalar_index++) {
      // Create a new reader_info instance which is connected with the
      // corresponding driver_array element. Further, make the
      // resolution process sensitive on this reader so that it is
      // executed whenever the value changes.
      (*iter).drivers[scalar_index]->rinfo = 
	new reader_info(scalar? driver_p : driver_type_info->element(driver_p, scalar_index),
			scalar? driver_type_info : driver_type_info->get_info(scalar_index));
      (*iter).drivers[scalar_index]->rinfo->wait_elements.push_back(wait_elem);
    }
  }

  // Finally, create a new "virtual" source to store all drivers of
  // the resolution process. Note this source is not a "real" source.
  signal_source &virtual_source = source_list->add_source(comp);
  if (scalar)
    virtual_source.drivers[0] = driver;
  else
    for (unsigned int i = 0; i < virtual_source.drivers.size(); i++)
      virtual_source.drivers[i] = driver->drivers[i];
}
