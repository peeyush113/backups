#define KERNEL

#include <freehdl/kernel-flags.hh>
#include <freehdl/kernel-process-base.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-wait-info.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <freehdl/kernel-handle-info.hh>
#include <freehdl/kernel-driver-info.hh>
#include <freehdl/kernel-reader-info.hh>
#include <freehdl/kernel-register.hh>
#include <freehdl/kernel-db.hh>
#include <freehdl/kernel-map-list.hh>
#include <freehdl/kernel-signal-source-list-array.hh>
#include <freehdl/kernel-resolver-process.hh>
#include <freehdl/kernel-resolver-descriptor.hh>
#include <freehdl/kernel-fhdl-stream.hh>

// Arguments that are passed in form the command line
int main_argc;
char **main_argv;


// Number of processes
int kernel_class::process_counter; 
// Array to store the processes which will be executed before the
// processes listed in process_to_execute are executed
process_base *kernel_class::priority_processes_to_execute;
// Array to store the processes which will be executed next
process_base *kernel_class::processes_to_execute;
// Each simulation cycle is assigned a unique cycle id. The cycle id
// may be used to easily distinguish between different simulation
// cycles. The id is incremented before a new simulation cycle
// starts.
int kernel_class::cycle_id;
// End simulation time
vtime kernel_class::end_sim_time;

// Number of processes which were executed during the simulation. Is
// only enabled if corresponding macro is defined. See "flags.hh"
STATISTICS(int kernel_class::executed_processes_counter;);
// Number of transactions which were created during simulation. Is
// only enabled if corresponding macro is defined. See "flags.hh"
STATISTICS(int kernel_class::created_transactions_counter;);



g_trans_queue kernel_class::global_transaction_queue;


// Basic constructor for the kernel
kernel_class::kernel_class() 
{
  process_counter = 0;
  priority_processes_to_execute = (process_base*)-1;
  processes_to_execute = (process_base*)-1;
  automatic_wait_id_counter = 0;
  current_process = NULL;
  cycle_id = 0;
  STATISTICS(executed_processes_counter = 0;);
}


// Elaborates the VHDL model. During elaboration all components,
// signals and processes are instantiated and linked to the kernel
void
kernel_class::elaborate_model (handle_info *hinfo) 
{
  instance_name.push("");

  // Elaborate first component found in component list
  elaborate_architecture (hinfo, instance_name, "", NULL, NULL, 0);

  // Cleanup signal component stack as it is used during elaboration
  // only.
  signal_component_stack.clear();
  
  // Setup connection to the kernel data base to retrieve all
  // process_base related entries.
  db_explorer<db_key_type::process_base_p, db_entry_type::process_id> process_id_accessor (kernel_db);
  int i = 0;
  for (db::key_iterator iter = kernel_db.begin (); iter != kernel_db.end (); iter++)
    {
      // First check whether iter refers actually to a process_base
      // entry in the database. If not, contiunue.
      if (process_id_accessor.find (*iter) == NULL) continue;
      // Get back the process_base pointer from iter.
      process_base *proc = process_id_accessor.get_key (*iter);
      
      // All processes must be executed at least once at simulation startup.
      // So add each process to the process_to_execute list here.
      proc->next_process = processes_to_execute;
      processes_to_execute = proc;
      i++;
    }
  
#ifdef READER_INFO_STATISTICS
  // Determine how many processes are sensitive on one, two, three,
  // ... signals. First create an array of counters and initialize
  // them with 0.
#ifdef HAVE_ALLOCA
  int *reader_info_counters = (int*)alloca(process_counter * sizeof(int));
#else
  int *reader_info_counters = (int*)malloc(process_counter * sizeof(int));
#endif
  for (int j = 0; j < process_counter; j++)
    reader_info_counters[j] = 0;
  
  // Visit all reader_info instances and get number of processes which
  // are sensitive on the corresponding scalar reader element. Note,
  // only signals which do not have any father are taken into account.

  // Setup connection to the kernel data base
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  
  for (db::key_iterator iter = kernel_db.begin (); iter != kernel_db.end (); iter++)
    {
      // First check whether iter refers actually to a process_base
      // entry in the database. If not, continue.
      if (!sig_info_ext.is_valid (*iter)) continue;
      sig_info_base *signal = sig_info_ext.get_key (*iter);

      if (!signal->signal_links.begin()) // Does signal has no father?
	for (int j = 0; j < signal->scalar_count; j++)
	  // Get number of sensitive processes for each scalar element
	  // of the signal
	  reader_info_counters[signal->readers[j]->wait_elements.size()]++;
      it++;
    }

  // Plot results.
  kernel_output_stream << "reader_info statistics:" << endl;
  for (int j = 0; j < process_counter; j++)
    if (reader_info_counters[j])
      kernel_output_stream << reader_info_counters[j] << " of length " << j << endl;

#ifndef HAVE_ALLOCA
  free (reader_info_counters);
#endif
#endif

  instance_name.pop();
}


// Calls constructor of an component specified by library, entity, and
// architecture. An empty string "" can be used as wildcard for library,
// entity, or architecture.

struct int_pair_compare_less : public binary_function<pair<int,int>, pair<int,int>, bool> {
  bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
    return a.first < b.first;
  }
};

void
kernel_class::elaborate_architecture (const char *library, const char *entity,
				      const char *architecture,
				      name_stack &iname, const char *name,
				      map_list *mlist, void *father, int level)
{
  handle_info *hinfo = get_handle(library, entity, architecture);

  if (hinfo == NULL) // Bail out if component not found
    error(("Component " + string(entity) + "(" + string(architecture) + ")" + " from library " + 
	   string(library) + " not found in executable").c_str());

  elaborate_architecture (hinfo, iname, name, mlist, father, level);
}


void
kernel_class::elaborate_architecture (handle_info *hinfo,
				      name_stack &iname, const char *name,
				      map_list *mlist, void *father, int level)
{
  assert (hinfo != NULL);
  
  // ***************************************************************
  // Execute global initialization function for component
  // ***************************************************************
  // First, execute the initialization function for the
  // component. Note that each design unit has an own initialization
  // function, that inits some globally visible data
  // structure. Typically, these data structures are used by ALL
  // instances of the design unit (e.g., of the aarchitecture). E.g.,
  // if an locally static constant is defined within the architecture,
  // then the init function sets up this constant. Note that these
  // init functions are called only ONCE for each design unit.
  if (!hinfo->init_done)
    {
      // Set flag so that this init function is not called again.
      hinfo->init_done = true;
      // Make call to init function.
      (*hinfo->init_function) ();
    }

  iname.set(name);

  // ***************************************************************
  // Execute component constructor
  // ***************************************************************
  // Next, create a new stack entry on the signal component stack to
  // keep track which signals has been created within the new
  // component (we are only interested in signals which are directly
  // created within this component, not signals which belong to
  // enclosed components...).
  signal_component_stack.push_back(list<sig_info_base *>());
  // Next, create new component
  void *comp = (*hinfo->function)(iname, mlist, father, level + 1);

  // Create shortcut to the list of signals directly defined within
  // the elaborated component.
  list<sig_info_base *> &current_signal_list = signal_component_stack.back();

  // ***************************************************************
  // Check sources of all signals included in the instantiated
  // component. Further, create resolver processes.
  // ***************************************************************

  // Setup connection to the kernel data base
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  for (db::key_iterator iter = kernel_db.begin (); iter != kernel_db.end (); iter++)
    {
      // First check whether iter refers actually to a process_base
      // entry in the database. If not, continue.
      if (!sig_info_ext.is_valid (*iter)) continue;

      // Find sources for signal
      signal_source_map_t::iterator source_iter = 
	signal_source_map.find (sig_info_ext.get_key (*iter));
      if (source_iter == signal_source_map.end()) break;
      // Check each scalar of signal
      sig_info_base *signal = (*source_iter).first;
      vector<signal_source_list*> &source_list_array = (*source_iter).second.source_list_array;
      // Note that we are looking at each scalar signal group which
      // belongs to the current signal. A signal group consists either
      // of a single scalar signal or may cover several signals which
      // are associated with a resolver function (e.g., if a resolution
      // function is defined for a record type then the signal group
      // consists of all scalars belonging to the record).
      for (unsigned int i = 0; 
	   i < source_list_array.size();      
	   i += source_list_array[i]->size) {
	// Check whether the scalar belongs to a signal group which has
	// more than one source but is not associated with a resolution
	// function.
	if (source_list_array[i]->sources.size() > 1 &&
	    source_list_array[i]->resolver == NULL) {
	  // In case of an error generate an error message.
	  string errstr = "Unresolved signal '" + sig_info_ext.get (signal).instance_name + "' has more than one source!\n" +
	    "Sources are: ";
	  // Analyze all sources. Note that a source might either be a
	  // process or a component.
	  string sep = "";
	  for (list<signal_source>::iterator source_iter = source_list_array[i]->sources.begin();
	       source_iter != source_list_array[i]->sources.end(); 
	       source_iter++) {
	    Xinfo_data_descriptor *descriptor = get_registry_entry((*source_iter).driving_id, Xinfo_descriptors);
	    if (descriptor->object_kind_id.get_major_id() == Xinfo_kind::ID_PROCESS)
	      errstr += sep + " process ";
	    else
	      errstr += sep + " component ";
	    errstr += "'" + get_instance_long_name(descriptor, Xinfo_descriptors) + "'";
	    sep = ",";
	  }
	  errstr += ".";
	  // Finally, print error message
	  error(errstr.c_str());
	  
	}
	
	// Next, create resolver processes to implement the resolution
	// mechanism. Note that the resolution function must be executed
	// only if there are more than one driver or -- in case of a
	// single driver -- the resolution function is not ideal (a
	// resolver function is called ideal if in case of a single
	// driver it always returns the driver value).
	if (source_list_array[i]->resolver != NULL &&
	    source_list_array[i]->sources.size() >= 1 &&
	    (source_list_array[i]->sources.size() >= 2 || 
	     !source_list_array[i]->resolver->ideal))
	  new resolver_process(signal, source_list_array[i], comp, level);
      }
    }
  
  
  // ***************************************************************
  // Next, create sources from the port signals. Port signals are
  // called "formals" in the following.
  // ***************************************************************
  // The following two maps are used to check for mapping errors
  map<signal_source_list*, list<fl_link>::iterator> source_list_link_check_map;
  map<signal_source_list*, vector<pair<int, int> > > source_index_check_map;
  map<signal_source_list*, bool> single_source_check_map;

  for (list<sig_info_base *>::iterator signal_iter = current_signal_list.begin();
       signal_iter != current_signal_list.end(); 
       signal_iter++) {
    sig_info_base *formal = (*signal_iter);
    // Lookup signal in the port_signal_link_map.
    port_signal_link_map_t::iterator port_signal_link_iter = 
      port_signal_link_map.find(formal);
    // Skip over signals which are not ports or are not of mode OUT,
    // INOUT, BUFFER or LINKAGE!
    if (sig_info_ext.get (formal).mode == vIN || 
	port_signal_link_iter == port_signal_link_map.end())
      continue;

    list<fl_link> &link_list = (*port_signal_link_iter).second;
    for (list<fl_link>::iterator link_iter = link_list.begin();
	 link_iter != link_list.end();
	 link_iter++) {
      // Get actuals associated with the current formal (note that
      // there may be several actuals associated with the current
      // formal; i.e., it may be associated with more than a single
      // actual if the formal is of a composite type).
      sig_info_base *actual = (*link_iter).actual;
      // Get current sources of actual associated with the current
      // formal.
      vector<signal_source_list*> &source_list_array = 
	signal_source_map[actual].source_list_array;
      // Next, get index range of actual and formal as sepcified in
      // the link
      int actual_start = 0, actual_end = 0;
      actual->type->acl_to_index((*link_iter).actual_aclp, actual_start, actual_end);
      int formal_start = 0, formal_end = 0;
      formal->type->acl_to_index((*link_iter).formal_aclp, formal_start, formal_end);
      // Lookup sources info structure of the current formal and
      // calculate the index range specified by the link.
      signal_source_map_t::iterator formal_source_iter = signal_source_map.find(formal);
      // Next, determine whether the actual is a slice or subelement
      // of a resolved signal group (is_single_source == true). Note
      // that in this case the entire component instantiation operates
      // as a *single* source for this signal group.
      const int left_index = source_list_array[actual_start]->index_start;
      const int right_index = source_list_array[actual_start]->index_start + source_list_array[actual_start]->size - 1;
      const bool sliced_actual = !(*link_iter).actual_aclp->back()->end() && 
	(*link_iter).actual_aclp->back()->get() == ACL_RANGE;
      const bool is_single_source = !((actual_start == left_index && actual_end == right_index && !sliced_actual) ||
				      actual_start > left_index || actual_end < right_index);
      // Create new sources for the actual. The new source are
      // assoicated with the current component.
      for (int i = actual_start; i <= actual_end; i += source_list_array[i]->size) {
	// Store some information to be used for error checking!
	source_list_link_check_map[source_list_array[i]] = link_iter;
	source_index_check_map[source_list_array[i]].
	  push_back(pair<int,int>(i, min(i + source_list_array[i]->size - 1, actual_end)));
	single_source_check_map[source_list_array[i]] = is_single_source;
	// Create a new source if there is not already a source
	// associated with the current component or if the component
	// is not a single source for the current signal group.
	if (source_list_array[i]->sources.size() == 0 ||
	    source_list_array[i]->sources.back().driving_id != comp ||
	    !is_single_source)
	  source_list_array[i]->add_source(comp);
	if (formal_source_iter == signal_source_map.end()) continue;
	vector<signal_source_list*> &formal_source_list_array = (*formal_source_iter).second.source_list_array;
	// Fill the driver array of the newly created "component"
	// source.
	for (int a_index = i, f_index = i - actual_start + formal_start; 
	     a_index < i + source_list_array[i]->size; 
	     a_index++, f_index++) 
	  {
	    // Check out whether this group of signals has any drivers
	    // at all before trying to copy anything. Note that e.g. a
	    // port signal of mode out is a source but there may be no
	    // process (or other source) that is driving this signal. In
	    // this case the drivers array will be empty!
	    if (source_list_array[a_index]->sources.size () != 0 &&
		formal_source_list_array[f_index]->sources.size () != 0)
	      {
		signal_source &actual_source = source_list_array[a_index]->sources.back();
		signal_source &formal_source = formal_source_list_array[f_index]->sources.back();
		if (formal_source.drivers.size() != 0)
		  actual_source.drivers[a_index - source_list_array[a_index]->index_start] = 
		    formal_source.drivers[f_index - formal_source_list_array[f_index]->index_start];
	      }
	  }
      }
    }
  }

  // Next, check sources generated from the component
  for (map<signal_source_list*, list<fl_link>::iterator >::iterator source_list_iter = 
	 source_list_link_check_map.begin();
       source_list_iter != source_list_link_check_map.end();
       source_list_iter++) {
    sig_info_base *actual = (*(*source_list_iter).second).actual;
    signal_source_list *source_list_p = (*source_list_iter).first;
    const bool single_source = single_source_check_map[source_list_p];
    vector<pair<int, int> > &index_list = source_index_check_map[source_list_p];
    bool multiple_sources = false, missing_sources = false;
    if (single_source) {
      // If the component builds a single source for the resolved
      // signal group then check whether each scalar of the grouped is
      // exactly "sourced" once.  Sort the index ranges based on the
      // left index value. Note that int_pair_compare_less is a
      // binary_function class defined above!
      sort(index_list.begin(), index_list.end(), int_pair_compare_less());
      // Check whether the index number ranged are contiguous and do
      // not overlap!
      int last_index = source_list_p->index_start - 1;
      for (vector<pair<int, int> >::iterator index_iter = index_list.begin();
	   index_iter != index_list.end();
	   index_iter++) {
	if (last_index + 1 != (*index_iter).first) 
	  if (last_index >= (*index_iter).first)
	    multiple_sources = true;
	  else
	    missing_sources = true;
	last_index = (*index_iter).second;
      }

    } else {
      // Ok, just make sure that each source drives each scalar of
      // resolved signal group.  Note that in this case actual
      // association sets up an separate source for the actual signal
      // group.
      const int index_first = source_list_p->index_start;
      const int index_last = index_first + source_list_p->size - 1;
      for (vector<pair<int, int> >::iterator index_iter = index_list.begin();
	   index_iter != index_list.end();
	   index_iter++)
	if (index_first != (*index_iter).first || 
	    index_last != (*index_iter).second)
	  missing_sources = true;
    }

    // Report any errors
    if (missing_sources) {
      string errstr = "Not all resolved elements of actual '" + sig_info_ext.get (actual).instance_name 
	+ "' are driven by component '" + 
	get_instance_long_name(get_registry_entry(comp, Xinfo_descriptors), Xinfo_descriptors) + "'!";
      // Finally, print error message
      error(errstr.c_str());
    }

    if (multiple_sources) {
      string errstr = "Some resolved elements of actual '" + sig_info_ext.get (actual).instance_name 
	+ "' are driven by component '" + 
	get_instance_long_name(get_registry_entry(comp, Xinfo_descriptors), Xinfo_descriptors) + 
	"' more than once. This is not permitted if the corresponding elements are not associated as a whole!";
      // Finally, print error message
      error(errstr.c_str());
    }
  }

  
  // ***************************************************************
  // Remove signal_source_map entries which are not needed any
  // more. 
  // ***************************************************************
  for (list<sig_info_base *>::iterator signal_iter = current_signal_list.begin();
       signal_iter != current_signal_list.end(); 
       signal_iter++) {
    signal_source_map_t::iterator source_iter = signal_source_map.find(*signal_iter);
    if (source_iter == signal_source_map.end()) break;
    signal_source_map.erase(source_iter);
  }

  // ***************************************************************
  // Register component
  // ***************************************************************
  register_entity_architecture(comp, strdup((string(":") + hinfo->library).c_str()), 
			       strdup((string(":") + hinfo->primary + "(" + hinfo->architecture + ")").c_str()), 
			       strdup(iname.get_top().c_str()), father);

  // Finally, pop last stack entry from signal component stack. The
  // last entry lists all signals that were directly created within
  // the component that was directly elaborated here.
  signal_component_stack.pop_back();
}

void
kernel_class::elaborate_component (const char *unit,
				   const char *default_library,
				   const char *default_unit,
				   name_stack &iname, const char *name,
				   map_list *mlist, void *father, int level)
{
  if (default_library == NULL || default_unit == NULL) 
    error(("Sorry, only default component binding is currently supported. No default binding for component " +
	   string(unit) + " found!").c_str());
  cerr << "default component instantiation for unit '" << iname.get_name() + name << 
    "'. Using '" << default_library << "." << default_unit << "'!\n";

  elaborate_architecture(default_library, default_unit, NULL, iname, name,
			 mlist, father, level);
}

#if 0
// Calls constructor of a configured component specified by
// libraray, entity, and (optinal) architecture. An empty string ""
// can be used as wildcard for library, entity, or architecture.
void 
kernel_class::elaborate_configured_component(const char *library, const char *entity,
					     const char *architecture, 
					     name_stack &iname, const char *name, 
					     map_list *mlist, void *father, int level)
{
  elaborate_architecture(library, entity, architecture, iname, name, mlist, father, level);
}
#endif

// Create and setup wait_info instances
short 
kernel_class::setup_wait_info(const short wait_id, const sigacl_list &salist, process_base *proc)
{
  wait_info wait_elem(wait_id, proc);
  
  // Declare the current wait_info instance as active. Hence, if only
  // a single wait_info instance is associated with the process, it
  // does not have to be actived in the process code explicitly.
  proc->wait (wait_id);

  for (int i = 0; i < salist.count; i++) {
    if (salist.list[i].signal->type->scalar())
      // If the signal is scalar then add wait element to reader
      salist.list[i].signal->readers[0]->wait_elements.push_back(wait_elem);
    else {
      // The signal is a composite signal. Hence, the process is
      // sensitive on each scalar element of the signal which is
      // addressed by the corresponding acl instance. First, get
      // index bounds.
      int start = 0, end;
      salist.list[i].signal->type->acl_to_index(salist.list[i].aclp, start, end);
      reader_info **readers = salist.list[i].signal->readers;
      for (int j = start; j <= end; j++) {
	assert(readers[j] != NULL);
	readers[j]->wait_elements.push_back(wait_elem);
      }
    }
  }
  return wait_id;
}  


// Get wait id, create and setup wait_info instances
short
kernel_class::setup_wait_info(const sigacl_list &salist, process_base *proc)
{
  // Test whether an automatic wait id has been created for the
  // current process. If not, then initialize
  // automatic_wait_id_counter. Note, all automatically created wait
  // ids are less than 0.
  if (proc != current_process) {
    current_process = proc;
    automatic_wait_id_counter = 0;
  }

  // Create and setup wait_info instance. Make sure that the
  // automatic_wait_id_counter does not overflow! PRIORIY_PROCESS is a
  // special id value which is used to mark processes which shall be
  // added to the priority execution queue.
  --automatic_wait_id_counter;
  assert(automatic_wait_id_counter != PRIORITY_PROCESS);
  return setup_wait_info(automatic_wait_id_counter, salist, proc);
}


// Init a generic value
void 
kernel_class::init_generic(void *generic, type_info_interface *info, name_stack &iname, 
			   const char *n, const char *sln, map_list *mlist, const void *default_value,
			   void *sr)
{
  // Get generic parameter value
  list<generic_link*> link_list;
  query_generic(mlist, link_list, n);

  // Count number of scalars
  int scalar_count = info->element_count();
  
  // If scalar count < 0 then formal is an unconstrained array type
  // and we must determine the array bounds from the actual or the
  // default value
  if (scalar_count < 0)
    if (link_list.size () > 0) 
      {
	// Is there an actual? If yes, then try to extract bounds from
	// actual.
	vector<int> left, right;
	vector<range_direction> range_dir;
	// Calculate the array bounds from the association list and create a new
	// array_info instance. Note, this instance will be not removed until end
	// of simulation.
	array_info *ainfo_pointer = (array_info*)info;
	get_unconstrained_generic_array_bounds(&link_list, n, ainfo_pointer, left, range_dir, right);
	// Note that the array may be a multi-dimensional array. Hence,
	// we have do do a little bit more here... First, collect all
	// array info pointer that belong to the (multi-dimensional)
	// array.
	info = create_array_info_for_unconstrained_link_array(ainfo_pointer, left, range_dir, right, -1);
	// Recalculate number of scalar elements 
	scalar_count = info->element_count();
	// Free type info instance
	if (ainfo_pointer != NULL) 
	  ainfo_pointer->remove_ref();      
      } 

    else if (default_value != NULL)
      {
	// Extract array info from detault value.
	info = ((array_base*)default_value)->info;
	// Recalculate number of scalar elements 
	scalar_count = info->element_count();
      }

  // Bail out if generic type is still unbound!
  if (scalar_count < 0)
    error((string("Cannot determine type of generic '") + sln + n + string("'!")).c_str());

  // Initialize generic constant
  info->reset(generic);
  info->init(generic);

  // This array is used to store which elements of the generic has
  // been specified in the association
  vector<bool> scalar_set(scalar_count);
  fill(scalar_set.begin(), scalar_set.end(), false);

  // Iterate through all associations belonging to the current generic
  // parameter
  for (list<generic_link*>::iterator pos = link_list.begin(); 
       pos != link_list.end(); 
       pos++) 
    {
      generic_link* link = *pos;
      // Convert formal acl to index values
      int start = 0, end = 0;
      info->acl_to_index(link->formal_aclp, start, end);
      assert(end < scalar_count);
      // Next, copy each scalar from src to dest
      for (int i = start, j = 0; i <= end; i++, j++)
	{
	  void *dest = info->element(generic, i);
	  type_info_interface *element_info = info->get_info(i);
	  void *src = link->type->element(link->value, j);
	  element_info->copy(dest, src);
	  // Check whether the scalar has not already been set in the
	  // association
	  if (scalar_set[i])
	    error((string("An element of the generic '") + sln + n + 
		   string("' has been associated more than once!")).c_str());
	  // Store which scalar element has been set!
	  scalar_set[i] = true;
	}
    }

  // Make sure that either all or no elements are associated. Further,
  // check whether a open generic has a default value.
  if (link_list.size() > 0)
    {
      if (find(scalar_set.begin(), scalar_set.end(), false) != scalar_set.end())
	error((string("Not all elements of generic '") + sln + n + string("' are associated!")).c_str());
    }

  else if (default_value == NULL)
    error((string("Generic '") + sln + n + string("' is open but has no detault value!")).c_str());

  else   if (default_value != NULL)
    // If there is a default value then initialize generic parameter
    // with default value
    info->copy(generic, default_value);

  // Register generic
  if (do_Xinfo_registration)
    register_generic(generic, sln, n, info, sr);
}


// Optimize wait_elements in order to save memory and runtime
void
kernel_class::compact_wait_elements()
{
  // The following hash map is used to find identical wait element
  // list associated with the various reader infos. Identical lists
  // are replaced by appropriate pointers to a single list in order to
  // save memory.
  typedef hash_multimap<unsigned int, reader_info *> wait_elements_map_t;
  wait_elements_map_t wait_elements_map;

  // Setup connection to the kernel data base
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  for (db::key_iterator iter = kernel_db.begin (); iter != kernel_db.end (); iter++)
    {
      // First check whether iter refers actually to a process_base
      // entry in the database. If not, continue.
      if (!sig_info_ext.is_valid (*iter)) continue;
      // Convert to correct key type.
      sig_info_base *sig = sig_info_ext.get_key (*iter);

      // For each scalar reader pointer which belongs to the signal...
      for (int i = 0; i < sig_info_ext.get (sig).scalar_count; i++) {
	reader_info *reader = sig->readers [i];
	if (reader == NULL) continue;
	// Determine hash number for wait element array
	unsigned int hash_num = get_hash (reader->wait_elements);
	// Next, lookup reader pointer stored in wait_elements_map that
	// have the same hash number.
	pair<wait_elements_map_t::iterator, wait_elements_map_t::iterator>
	  iter_range = wait_elements_map.equal_range(hash_num);
	// Search found items
	wait_elements_map_t::iterator iter = iter_range.first;
	for(; iter != iter_range.second; iter++)
	  if (reader->wait_elements.is_linked((*iter).second->wait_elements))
	    // If the current wait element array is already linked with
	    // the current item then nothing has to be done...
	    break;
	  else if (is_equal(reader->wait_elements, (*iter).second->wait_elements)) {
	    // If the current wait element array is not linked but
	    // identical to the current item then link together both
	    // items.
	    reader->wait_elements.link((*iter).second->wait_elements);
	    break;
	  }
	// If no matching arrays were found then create a new entry in
	// the temporary hash map.
	if (iter == iter_range.second)
	  wait_elements_map.insert(pair<const unsigned int, reader_info *>(hash_num, reader));
      }
    }
}

// Executes all processes which are on the processes_to_execute array
void
kernel_class::execute_processes()
{
  // First, execute process in priority list in groups formed by
  // process level (stored in member jmp of process instance). During
  // execution of these processes NEW transactions for the same cycle
  // may be created. Hence, assign these transactions first. This may
  // put some processes on the priority list again. Continue until
  // priority process list stays empty! Note that the special
  // mechanism exploiting the priority levels of the processes makes
  // sure that the processes are executed in a specific order (i.e.,
  // processes with a higher level are executed before processes
  // associated with a lower level).
  process_base *proc = priority_processes_to_execute, *next_proc;
  while (proc != (process_base*)-1) {
    // Determine the process level of the current process group.
    const int level = proc->jmp;
    do {
      next_proc = proc->next_process;
      proc->next_process = NULL;
      proc->execute();
      proc = next_proc;
      // Continue until end of list is reached or the process level
      // does not match the level of the current process group.
    } while (proc != (process_base*)-1 &&
	     proc->jmp == level);
    priority_processes_to_execute = next_proc;
    // Assign any new transactions created during priority process
    // execution.
    global_transaction_queue.assign_next_transactions();
    proc = priority_processes_to_execute;
  }
  
  // Next, execute all "normal" processes.
  proc = processes_to_execute;
  STATISTICS(int processes_executed = 0;);

  while (proc != (process_base*)-1) {
    REPORT(kernel_output_stream << "Executing process " <<  processes_to_execute[i]->instance_name << 
	   "." << endl;)
    next_proc = proc->next_process;
    proc->next_process = NULL;
    proc->execute();
    proc = next_proc;
    STATISTICS(processes_executed++;);
  }
  
  STATISTICS(executed_processes_counter += processes_executed;);
  processes_to_execute = (process_base*)-1;
}


bool
kernel_class::assign_next_transactions()
{
  return global_transaction_queue.assign_next_transactions();
}

bool
kernel_class::next_cycle() 
{
  // Increment cycle id counter to separate the current simulation
  // cycle from the previous ones
  cycle_id++; 

  if (global_transaction_queue.next_cycle()) {
    // Next, execute priority and normal normal processes.
    execute_processes();

    return global_transaction_queue.empty(); 

  } else
    return true;
}


void 
kernel_class::add_process(process_base *proc, const char *scope_long_name, 
			  const char *name, void *father)
{
  // Setup connection to the kernel data base and create a new entry
  // associated with the current process pointer.
  db_explorer<db_key_type::process_base_p, db_entry_type::process_id> process_id_accessor (kernel_db);
  process_id_accessor.get (proc) = process_counter;

  // Link process information into a global data structure if
  // requested
  if (do_Xinfo_registration)
    register_process(proc, scope_long_name, name, father);
  process_counter++;
}

void
kernel_class::add_signal(sig_info_base *signal) 
{
  signal_component_stack.back().push_back(signal);
  REPORT(kernel_output_stream << "New signal " << signal->instance_name << endl);
}


// Returns a pointer to a driver_info instance. This method is 
// called by processes during elaboration to get a driver. All
// signal assignments done by a process are executed via a
// corresponding driver instance.
driver_info *
kernel_class::get_driver(process_base *proc, sig_info_base *signal, acl *a)
{
  int start = 0, end;

  // Get start and end index value of signal
  signal->type->acl_to_index(a, start, end);
  // Get sources of signal
  signal_source_list_array &source_list_array = signal_source_map[signal];

  if (start == end) {
    // Only a scalar signal element is target of this driver. Check
    // whether the process has already a driver for this scalar
    // signal. First, get source list associated with this scalar.
    signal_source_list *source_list_p = source_list_array[start];
    // Next, check whether the source is driven by a process or
    // component not equal to the current process.
    for (list<signal_source>::iterator iter = source_list_p->sources.begin();
	 iter != source_list_p->sources.end();
	 iter++)
      if ((*iter).driving_id == proc)
	// If an appropriate source is already defined then return a
	// pointer to the correspnding driver_info.
	return (*iter).drivers[start - source_list_p->index_start];
    
    // Add source 
    signal_source &source = source_list_p->add_source(proc);

    if (signal->type->scalar()) {
      // Create a new driver for the signal
      driver_info *driver = new driver_info(proc, signal, start);
      // Add driver to driver list of the signal
      source.drivers[start - source_list_p->index_start] = driver;      
      
      return driver;
    
    } else {
      driver_info **drivers = new driver_info*[1];
      // Add driver to driver list of the signal
      source.drivers[start - source_list_p->index_start] = 
	drivers[0] = new driver_info(proc, signal, start);

      return new driver_info(proc, signal, signal->type, start, drivers, 1);
    }

  } else {
    // Create drivers for several scalar elements of the signal.
    int driver_count = end - start + 1;
    driver_info **drivers = new driver_info*[driver_count];
    for (int i = start, j = 0; i <= end; i++, j++) {
      // Only a scalar signal element is target of this driver. Check
      // whether the process has already a driver for this scalar
      // signal.
      signal_source_list *source_list_p = source_list_array[i];
      // Next, check whether the source is driven by a process or
      // component not equal to the current process.
      signal_source *source_p = NULL;
      // Check sources associated with the current index number i.
      for (list<signal_source>::iterator iter = source_list_p->sources.begin();
	   iter != source_list_p->sources.end();
	   iter++)
	if ((*iter).driving_id == proc)
	  source_p = &(*iter);
      
      // If no approriate source was found then create a new one.
      if (source_p == NULL)
	source_p = &source_list_p->add_source(proc);
      
      // Initialize driver array of source if necessary.
      if (source_p->drivers[i - source_list_p->index_start] == NULL)
	source_p->drivers[i - source_list_p->index_start] = 
	  drivers[j] = new driver_info(proc, signal, i);
    }

    return new driver_info(proc, signal, signal->type, start, drivers, driver_count);
  }
}





// Rebuilds driver array. This method is called by processes during
// elaboration e.g. to get an additional driver for another scalar
// instance of a composite signal. All signal assignments done by a
// process are executed via a corresponding driver instance.
void
kernel_class::get_driver(driver_info *driver, process_base *proc, acl *a)
{
  int start = 0, end;
  sig_info_base *signal = driver->signal;

  // Get start and end index value of signal
  signal->type->acl_to_index(a, start, end);

  // Get sources of signal
  signal_source_list_array &source_list_array = signal_source_map[signal];

  if (signal->type->scalar()) {
    assert(start == 0 && end == 0);
    return;

  } else {
    int old_start = driver->index_start;
    int old_end = old_start + driver->size - 1;
    int new_start = old_start < start? old_start : start;
    int new_end = old_end > end? old_end : end;
    bool size_changed = old_start != new_start || old_end != new_end;

    driver_info **drivers;
    if (size_changed) {
      // create a new drivers array and copy old pointer to the new array
      drivers = new driver_info*[new_end - new_start + 1];
      for (int j = 0; j <= old_end - old_start; j++)
	drivers[j + old_start - new_start] = driver->drivers[j];
      // delete old drivers array and set the drivers pointer to the
      // newly allocated array
      delete[] driver->drivers; 
      driver->drivers = drivers;

    } else
      drivers = driver->drivers;

    for (int i = start, j = start - new_start; i <= end; i++, j++) {
      // Check whether the process has already a driver for this
      // scalar signal.
      signal_source_list *source_list_p = source_list_array[i];

      // Check sources associated with index number.
      signal_source *source_p = NULL;
      for (list<signal_source>::iterator iter = source_list_p->sources.begin();
	   iter != source_list_p->sources.end();
	   iter++)
	if ((*iter).driving_id == proc)
	  source_p = &(*iter);

      // If no approriate source was found then create a new one.
      if (source_p == NULL)
	source_p = &source_list_p->add_source(proc);

      if (source_p->drivers[i - source_list_p->index_start] == NULL)
	source_p->drivers[i - source_list_p->index_start] = 
	  drivers[j] = new driver_info(proc, signal, i);
    }

    driver->index_start = new_start;
    driver->size = new_end - new_start + 1;
  }
}



// Perform simulation up to time less than end. Returns false if
// simulation was stopped.
bool 
kernel_class::do_sim(const vtime &end)
{
  set_end_sim_time(end);
  while (get_next_pending_sim_time() <= get_end_sim_time()) {
    // Execute next simulation cycle. Break if event queue is
    // empty (i.e., if next_cycle() returns true).
    if (kernel.next_cycle())
      break;
  }

  return get_end_sim_time() == end;
}
