#ifndef FREEHDL_KERNEL_PROCESS_BASE_H
#define FREEHDL_KERNEL_PROCESS_BASE_H

#include <string>
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-name-stack.hh>

// Each process is derived from this class
struct process_base {
  virtual ~process_base() {};
  // next_process is used to build up a linked list of processes which
  // must be executed in the current simulation cycle. If
  // next_proccess is equal to NULL then the process is currently not
  // on the list. If it is equal to -1 then the process is the last
  // element of the list. Otherwise next_process points to the next
  // process on the list.
  process_base *next_process;
  short jmp;
  // Id of the currently active wait statement. Each wait statement
  // is associated an unique id number.
  short active_wait_id;
  // Constructor
  process_base(name_stack &in);
  // Constructor for "internal" processes
  process_base();
  // Activates a specific wait statement of the process. The wait
  // statement is identified by an id.
  void wait(short i) { active_wait_id = i; }
  // This method executes the process
  virtual bool execute() = 0;
};


/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

#include <freehdl/kernel-db.hh>


define_db_key_type (process_base*, process_base_p);
define_db_entry_type (int, process_id);



#endif

#endif
