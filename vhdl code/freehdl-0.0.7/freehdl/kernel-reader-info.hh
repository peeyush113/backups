#ifndef FREEHDL_KERNEL_READER_INFO_H
#define FREEHDL_KERNEL_READER_INFO_H

#include <freehdl/kernel-list.hh>
#include <freehdl/kernel-wait-info.hh>
#include <freehdl/kernel-classes.hh>

// This class stores the processes which are sensitive
// on a reader of a signal
class reader_info {
public:
  // Points to the reader
  void *reader;
  // Array of wait_info instances
  shared_array<wait_info> wait_elements;
  // Stores the transaction which caused the last event on the signal
  void *last_event_tr_item;
  // Cycle id of the simulation cycle in which the most recent event
  // on the signal appeared
  int last_event_cycle_id;
  // Points to a transaction element. The value stores the last value
  // before the signal changed to the current value (needed for the
  // last_value attribute). The time element of the transaction
  // contains the time stamp of the most recent assignment to the
  // signal which caused NO event.
  void *last_value_tr_item;
  // Cycle id of the last signal assignment which caused NO event.
  int last_active_cycle_id;
  // Constructor
  reader_info(void *r, type_info_interface *type);
  // Activates all processes in wait_elements. This means the
  // processes will be exceuted during the current simulation cycle if
  // the corresponding wait_info element is active.
  inline void activate_processes();
};



/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

#include <freehdl/kernel-kernel-class.hh>

// last_active_wait_elements is a pointer which references the last
// wait element list that was used to activate processes. This pointer
// is used to skip over wait element lists which were already
// processed. E.g., if a process is sensitive on a vector signal then
// the readers of all elements will reference the same wait element
// list. If several elements of a vector are assigned a new value then
// the corresponding readers are usually processed sequentially. When
// the wait element list is processed the first time then
// last_active_wait_elements will be set to point to the wait element
// list. If another vector element gets an event then
// last_active_wait_elements will be used to detect that this wait
// element list has been processed already. Hence, the list is not
// processed again!
extern const shared_array<wait_info> *last_active_wait_elements;
// An empty wait element list.
extern const shared_array<wait_info> dummy_wait_elements;
// Set last_active_wait_elements to the dummy wait element list.
inline void reset_last_active_wait_elements() {
  last_active_wait_elements = &dummy_wait_elements;
};

inline void
reader_info::activate_processes()
{
  // Test whether the same wait element list or a list which includes
  // same set of wait_infos has been processed already. If yes, then
  // do not try to activate the corresponding processes as this has
  // been done already!
  if (last_active_wait_elements->is_linked(wait_elements)) {
    return;
  } else
    last_active_wait_elements = &wait_elements;

  // Test all wait_info instances associated with the reader
  for (int i = 0; i < wait_elements.size(); i++) {
    wait_info &winfo = wait_elements.content(i);
    // Check whether the wait_info instance is active, i.e. whether
    // the wait statement associated with this wait_info instance is
    // currently used by the corresponding process. This is done by
    // comparing the active_wait_id of the process with the wait_id of
    // the wait_info instance. Note that each wait statement of a
    // process is associated with an unique wait id.
    if (winfo.process->active_wait_id == winfo.wait_id)
      // If both wait ids are equal then the process is scheduled for
      // execution.
      kernel.add_process_to_execute(winfo.process);
    else if (winfo.wait_id == PRIORITY_PROCESS)
      // If the wait id stored in the wait_info instance is euqal to
      // PRIORITY_PROCESS then the process is activated in each
      // case. Further, it is added to the priority process list which
      // is processed BEFORE the "normal" processes are executed. This
      // "high priority" process list is used to handle special VHDL
      // mechanisms like signal resolution.
      kernel.add_priority_process_to_execute(winfo.process);
  }
}


#endif

#endif
