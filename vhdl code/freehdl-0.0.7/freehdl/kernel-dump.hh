#ifndef FREEHDL_KERNEL_DUMP_H
#define FREEHDL_KERNEL_DUMP_H

#define KERNEL

#include <freehdl/kernel-name-stack.hh>
#include <freehdl/kernel-process-base.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-winfo-item.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <list>
#include <map>
#include <string>
#include <fstream>

using namespace std;

typedef map<string, char*, less<string> > Tmap;
extern Tmap mapping_translation_table;

// For each signal which is dumped an virtual process is created. This
// process is sensitive on the corresponding signal and will be
// executed each time the signal changes.
class signal_dump : public process_base {
public:
  // Points to the signal info structure of the corresponding signal
  type_info_interface *type;
  void *reader_pointer;
  //instance_name and name of signal
  string instance_name;
  string name;
  string sname;
  // Wait info instance. This virtual process is only sensitive on a
  // single process.
  winfo_item winfo_instance;
  // Each signal which is dumped into a VCD file is assigned a short
  // name identifier
  char vcd_signal_identifier[6];
  // Constructor
  signal_dump(name_stack &in, sig_info_base *s, acl *a);
  // wait id number
  short wait_id;
  // This function will return an appropriate table entry (if
  // available)
  char *find_table(type_info_interface* type);
  //this variable is used by the read_type function
  char* translation_table;
  // This method is executed each time the signal value changes
  bool execute();
  // Continue dumping the signal.
  void dump_on() { wait(wait_id); };
  // Stop dumping the signal by setting the active wait id to a
  // invalid id. Hence, if the corresponding signal changes the
  // process will NOT be activated.
  void dump_off() { wait(wait_id + 1); };
  //writes the actual value in a buffer
  inline void write_value();
  // Returns a default translation table
  static Tmap get_default_translation_table();
};


//global variables
extern fstream file;
extern bool quiet;
extern int  coef_str_length;
extern buffer_stream dump_buffer;
extern buffer_stream file_buffer;

//converts the time value from ps to user-defined unit
extern char*  time_conversion(const lint&, const int&); 

//writes in the file the contenent of file_buffer
extern void write_in_file(buffer_stream &file_buffer);

// List to store the "dumping processes"
extern list<signal_dump*> signal_dump_process_list;

// Used to store the user_defined translation table types
extern  map<string, char*, less<string> >  mapping_translation_table;


/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

#define LIMIT_SIZE 200000 


// calls vcd_print function and writes the correspond value in file_buffer
inline 
void signal_dump::write_value()
{
  dump_buffer.clean();
  type->vcd_print(dump_buffer,reader_pointer,translation_table, false);

  // Flush buffer if the threshold has been reached
  if (file_buffer.str_len() >= LIMIT_SIZE) 
    write_in_file(file_buffer);

  file_buffer << dump_buffer.str() << vcd_signal_identifier <<'\n';
}

/******************************************************
 * End of internal kernel definitions    
 ******************************************************/
#endif

#endif

