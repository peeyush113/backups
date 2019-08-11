#ifndef FREEHDL_KERNEL_DELAYED_PROCEDURE_BASE_H
#define FREEHDL_KERNEL_DELAYED_PROCEDURE_BASE_H

#include <freehdl/kernel-winfo-item.hh>

// Each procedure which contains at least one wait statement (or calls
// another procedure that contains one) will be converted into a
// corresponding class derived from delayed_procedure_base. Note that
// such a procedure is actually handled similar to a VHDL process. The
// major difference is that the procedure is created and deleted
// dynamically while processes are static.
struct delayed_procedure_base {
  // points to wait info instance
  winfo_item *winfo;
  // points the the process that called this procedure 
  process_base *process;
  // stores jmp variable
  short jmp;
  // constructor
  delayed_procedure_base (process_base *p)
    : process (p), jmp (0) {};
  // Activates a specific wait statement of the procedure/process. The
  // wait statement is identified by an id.
  void wait(short i) { process->active_wait_id = i; }
};

#endif
 
