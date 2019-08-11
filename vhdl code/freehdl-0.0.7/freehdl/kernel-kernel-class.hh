#ifndef FREEHDL_KERNEL_KERNEL_CLASS_H
#define FREEHDL_KERNEL_KERNEL_CLASS_H

#include <freehdl/kernel-flags.hh>
#include <freehdl/kernel-classes.hh>
#include <freehdl/kernel-list.hh>
#include <freehdl/std-standard.hh>
#include <freehdl/kernel-process-base.hh>
#include <freehdl/kernel-wait-info.hh>
#include <freehdl/kernel-handle-info.hh>
#include <freehdl/kernel-global-event-queue.hh>


/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL


/******************************************************
 * End of internal kernel definitions    
 ******************************************************/
#endif


// Arguments that are passed in form the command line
extern int main_argc;
extern char **main_argv;


class sig_info_base;

class kernel_class {
public:
  // Executable name
  char *executable_name;
  // Number of processes
  static int process_counter; 
  // Each simulation cycle is assigned a unique cycle id. The cycle id
  // may be used to easily distinguish between different simulation
  // cycles. The id is incremented before a new simulation cycle
  // starts.
  static int cycle_id;
  // End simulation time
  static vtime end_sim_time;
  // Similar to processes_to_execute. However, in
  // priority_processes_to_execute the processes which must be
  // executed BEFORE the remaining processes in processes_to_execute
  // are listed. This allows us to give precendence to special
  // processes which are used to implement signal resolution and other
  // itnernal mechanisms.
  static process_base *priority_processes_to_execute;
  // Array to store the processes which will be executed
  // next. Actually, this pointer is the head of a linked list. The
  // last link pointer of the list stores -1. Usually, -1 is not a
  // valid process_base address. Hence, it can be used similar to
  // NULL.
  static process_base *processes_to_execute;
  // Global transation queue. Note that this queue actually does NOT
  // store the transactions but pointers to the corresponding driver
  // instances which hold the transactions!
  static g_trans_queue global_transaction_queue;
  // wait_id counter and current process
  int automatic_wait_id_counter;
  process_base *current_process;

  // Number of processes which were executed during the simulation. Is
  // only enabled if corresponding macro is defined. See "flags.hh"
  STATISTICS(static int executed_processes_counter;);
  // Number of transactions which were created during simulation. Is
  // only enabled if corresponding macro is defined. See "flags.hh"
  STATISTICS(static int created_transactions_counter;);

  // Basic constuctor
  kernel_class(); 

  // ******************************************
  // Methods executed during elaboration
  // ******************************************

  // Elaborates the model using a specific architecture/configuration handle
  void elaborate_model(handle_info *hinfo = NULL);
  // Adds a new process to the kernel. "scope_long_name" is the long
  // name of the scope the current process is defined within. "name"
  // is the name of the process and "father" points to the
  // corresponding father scope (usually this is a pointer to the
  // arcitecture)
  void add_process(process_base *proc, const char *scope_long_name, 
		   const char *name, void *father);
  // Calls constructor of an component specified by handle hinfo.
  void elaborate_architecture (handle_info *hinfo,
			       name_stack &iname, const char *name,
			       map_list *mlist, void *father, int level);
  // Calls constructor of an component specified by library, entity, and
  // architecture. An empty string "" can be used as wildcard for library,
  // entity, or architecture.
  void elaborate_architecture(const char *library, const char *entity,
			      const char *architecture, 
			      name_stack &iname, const char *name, 
			      map_list *mlist, void *father, int level);

  // Calls constructor of a configuration identified by LIBRARY and
  // NAME to instantiate it with NAME, within FATHER.
  //
  void elaborate_configuration (const char *library, const char *config,
				name_stack &iname, const char *name, 
				map_list *mlist, void *father, int level);

  // Calls constructor of the component identified by NAME and INAME.
  // The constructor should have been established already, via a call
  // to PUSH_CONFIGURATION.  Depending on the information provided via
  // PUSH_CONFIGURATION, this will ultimately result in a call to
  // ELABORATE_ARCHITECTURE or to ELABORATE_CONFIGURATION.
  //
  // When no information concerning NAME is found, DEFAULT_LIBRARY and
  // DEFAULT_UNIT are used to determine a unit to elaborate.
  // DEFAULT_UNIT can either be a entity or a configuration.
  //
  void elaborate_component (const char *unit,
			    const char *default_library,
			    const char *default_unit,
			    name_stack &iname, const char *name,
			    map_list *mlist, void *father, int level);

#if 0
  // XXX - remove?

  // Calls constructor of a configured component specified by
  // libraray, entity, and (optinal) architecture. An empty string ""
  // can be used as wildcard for library, entity, or architecture.
  void elaborate_configured_component(const char *library, const char *entity,
				      const char *architecture, 
				      name_stack &iname, const char *name, 
				      map_list *mlist, void *father, int level);
#endif

  // Adds a new signal to the kernel
  void add_signal(sig_info_base *signal);
  // Returns a pointer to a driver_info instance. This method is 
  // called by processes during elaboration to get a driver. All
  // signal assignments done by a process are executed via a
  // corresponding driver instance.
  driver_info *get_driver(process_base *proc, sig_info_base *signal, acl *a = NULL);
  // Rebuilds driver array. This method is called by processes during
  // elaboration e.g. to get an additional driver for another scalar
  // instance of an composite signal. All signal assignments done by a
  // process are executed via a corresponding driver instance.
  void get_driver(driver_info *driver, process_base *proc, acl *a);
  // Create and setup wait_info instances. The wait id is created
  // automatically. Note, all automatically wait ids less then 0.
  short setup_wait_info(const sigacl_list &salist, process_base *proc);
  // Create and setup wait_info instance using wait_id as wait id.
  short setup_wait_info(const short wait_id, const sigacl_list &salist, process_base *proc);
  // Init a generic value
  void init_generic(void *generic, type_info_interface *info, name_stack &iname, 
		    const char *n, const char *sln, map_list *mlist, const void *default_value,
		    void *sr);
  // Optimize wait_elements in order to save memory and runtime
  void compact_wait_elements();

  // ******************************************
  // Methods executed during simulation
  // ******************************************

  // Returns current end simulation time
  const vtime &get_end_sim_time(void) { return end_sim_time; }
  // Set end simulation time
  void set_end_sim_time(const vtime &e) { end_sim_time = e; }
  // Returns the current simulation time
  const vtime &get_sim_time(void) { return global_transaction_queue.get_sim_time(); }
  // Returns time of the next pending event or -1 if event queue is empty
  const vtime get_next_pending_sim_time(void) { return global_transaction_queue.get_next_pending_event_time(); }
  // Returns the current delta count
  const int get_delta(void) { return global_transaction_queue.get_delta(); }
  // Get the current cycle id
  const int get_cycle_id(void) { return cycle_id; }
  // Execute all processes present on the processes_to_execute array
  void execute_processes();
  // Adds a process to be executed within the current simulation cycle
  void add_process_to_execute(process_base *process) {
    process_base &proc = *process;
    // Note, we check for NULL here (and not for -1). If the pointer
    // is equal to -1 then this element is at the end of the list. If
    // it is NULL then it is NOT on the list.
    if (proc.next_process == NULL) {
      proc.next_process = processes_to_execute;
      processes_to_execute = &proc;
    }
  }
  // Adds a process to be executed within the current simulation
  // cycle. The process is added to a special priority list which is
  // executed BEFORE "normal" processes. Note that this process is
  // declared inline but defined below. 
  inline void add_priority_process_to_execute(process_base *process);
  // Execute a simulation cycle. Returns false if there is still
  // an transaction on the event list, true otherwise
  bool next_cycle();
  // Assign all next transactions with the current simulation time to
  // the drivers. Returns wheter really some assginments have been done.
  // Note, if a transaction is removed from the driver, then it is not
  // removed from the global transaction list. Hence, we must first check
  // whether the first transaction of a driver list has the correct time
  // stamp.
  bool assign_next_transactions();
  // Add a transaction to the global transaction queue.
  void add_to_global_transaction_queue(driver_info *driver, const vtime &time_value) {
    global_transaction_queue.add_to_queue(driver, time_value);
  }
  // Perform simulation up to time less than end. Returns false if
  // simulation was stopped.
  bool do_sim(const vtime &end);
#ifdef EVENT_PROFILE
  int event_report(char *filename) {
    global_transaction_queue.event_report(filename);
  }
#endif

};


// The simulation kernel
extern kernel_class kernel; 


#ifdef KERNEL
// *************************************************************************
// The following definitions are only used by kernel code and not by
// code generated by the code generator!
// *************************************************************************

#include <list>

// Adds a process to be executed within the current simulation
// cycle. The process is added to a special priority list which is
// executed BEFORE "normal" processes.
inline void 
kernel_class::add_priority_process_to_execute(process_base *process) {
  process_base &proc = *process;
  // Note, we check for NULL here (and not for -1). If the pointer
  // is equal to -1 then this element is at the end of the list. If
  // it is NULL then it is NOT on the list.
  if (proc.next_process == NULL) {
    const int level = proc.jmp;
    process_base **p = &priority_processes_to_execute;
    // The priority processes are ordered accoring to the component
    // level value stored in member jmp. This approach is used to
    // force execution of the priority processes according to a
    // specific order.
    while (*p != (process_base*)-1) {
      if (level >= (*p)->jmp) break;
      p = &(*p)->next_process;
    }
    proc.next_process = *p;
    *p = &proc;
  }
}


#endif


#endif
