#define KERNEL
#include <string.h>
#include <freehdl/kernel-dump.hh>
#include <freehdl/kernel-register.hh>
#include <freehdl/kernel-fhdl-stream.hh>


//Constructor
signal_dump::signal_dump(name_stack &in, sig_info_base *s, acl *a) : process_base(in) 
{
  // Setup connection to the kernel data base 
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);

  instance_name = sig_info_ext.get (s).instance_name;
  sname = sig_info_ext.get (s).name;

  // Find characters that are not compatible with the VCD format and
  // replace them with '-'
  string dumped_name = sig_info_ext.get (s).name;
  int pos = -1;
  while ((pos = dumped_name.find (':', pos + 1)) >= 0)
    dumped_name [pos] = '-';
  // Determine name of signal 
  dump_buffer.clean();
  dump_buffer << dumped_name;

  if (!a->end())
    for (int i = 0; i < a->get_size(); i++)
      dump_buffer << "(" << a->get(i) << ")";
  name = dump_buffer.str();

  reader_pointer = s->reader_pointer;
  type = s->type;

  if (! a->end()) {
    reader_pointer = s->type->element(s->reader_pointer, a);
    type = s->type->get_info(s->reader_pointer, a);

  } else {
    reader_pointer = s->reader_pointer;
    type = s->type;
  }
  sigacl_list sal(1);
  sal.add(s, a);
  winfo_instance = kernel.setup_wait_info(sal ,this);
  // Store the wait id for later use. Note that this special process
  // has only a SINGLE wait_info instance
  wait_id = active_wait_id; 
  // if call true, then use the user-defined translation table
  translation_table = find_table(type);
}



//This method is called each time the corresponding signal changes
int old_cycle_id = -1;


// A temporary buffer used for printing. It is declared globally in
// order to save time for creating 
bool
signal_dump::execute()
{
  dump_buffer.clean();

  // displays dumped signals on screen if requested
  if (!quiet) 
    kernel_output_stream << "signal " << instance_name << " changed\n"; 

  //store the time after its conversion in vcd file:
  const int current_cycle_id = kernel.get_cycle_id();
  if (old_cycle_id != current_cycle_id) {
    old_cycle_id = current_cycle_id;
    const lint tval = kernel.get_sim_time();

    // flush the file buffer if necessary
    if (file_buffer.str_len() >= LIMIT_SIZE) 
      write_in_file(file_buffer);

    file_buffer << '#' << time_conversion(tval, coef_str_length) <<'\n';

  }
  // call the write_value to calculate vcd value of the signal 
  //and stores this value in file_buffer  
  write_value();

  return true;
}



// find_translation table
char *
signal_dump::find_table(type_info_interface* type)
{
  switch(type->id)
    {
    case ARRAY:
      return find_table(((array_info*)type)->element_type);
      break;
    case ENUM:
      {
	Xinfo_type_info_interface_descriptor* desc = get_type_registry_entry(type, Xinfo_descriptors);
	if (desc != NULL) {
	  const char *test_name = desc->long_name;
	  Tmap::iterator it = mapping_translation_table.find(test_name);
	  if (it != mapping_translation_table.end())
	    return (*it).second;
	  }
	break;
      }
    default: break;
    }
  return NULL;
}


Tmap 
signal_dump::get_default_translation_table()
{
  Tmap table;
  table[":std:standard:bit"] = "01";
  table[":std:standard:boolean"] = "01";
  // the std_ulogic real table is "UX01ZWLH-", which is converted to
  table[":ieee:std_logic_1164:std_ulogic"] = "XX01Z001X";
  table[":ieee:std_logic_1164:std_logic"] = table[":ieee:std_logic_1164:std_ulogic"];

  return table;
}




//List to store the "dumping processes"	   
list<signal_dump*> signal_dump_process_list;

Tmap mapping_translation_table;











