// FreeHDL global event queue class
// Author: Geir Harris Hedemark (geirhe@ifi.uio.no)
// Created: 19981014
// Global variables:

#define KERNEL

#include <freehdl/kernel-global-event-queue.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <freehdl/kernel-reader-info.hh>
#include <freehdl/kernel-error.hh>
#ifdef EVENT_PROFILE
#include <fstream.h>
#endif


g_trans_queue::g_trans_queue()
{
#ifdef EVENT_PROFILE
  int i;
#endif

  sim_time=0;
  delta=0;

#ifdef EVENT_PROFILE
#ifdef EVENT_DEBUG
  debug("Initializing profile info", __FILE__, __LINE__);
#endif
  for (i=0;i<65536;i++) {
    event_times[i]=0;
  }
  for (i=0;i<1024;i++) {
    event_number[i]=0;
  }
#endif /* EVENT_PROFILE */
}

g_trans_queue::~g_trans_queue()
{
}

//********************************************************************
// Attention: This is the definition of a method of class driver_info!
//********************************************************************
// This methods assigns the first transactions with time stamp
// time_value located on the local driver list to the corresponding
// reader. It returns true if there was really a transaction with a
// corresponding time stamp on the list or false otherwise.
inline bool
driver_info::assign_first_transactions(const vtime &time_value) 
{
  void *pos = transactions.begin();

  // Perhaps the corresponding transaction has been removed
  // meanwhile. If this is true then return false
  if (pos == NULL || 
      transactions.key(pos) != time_value) 
    return false;
  
  reader_info &rinfo_ref = *rinfo;

  // Assign new value to reader and test whether its value changed
  bool event = type->fast_assign(rinfo_ref.reader, &transactions.content(pos));

  if (event) {
    // Unlink the transaction from the list
    transactions.unlink(pos);
    // If the signal values changed then activate processes which are
    // currently sensitive on this signal. First, free transaction
    // item last_value_tr_item because it is not needed any more
    transactions.free_item(rinfo_ref.last_value_tr_item);
    // Now, the current event transaction is copied to
    // last_value_tr_item, i.e. it becomes the "last_value" transaction
    rinfo_ref.last_value_tr_item = rinfo_ref.last_event_tr_item;
    // This transaction becomes the current event transaction
    rinfo_ref.last_event_tr_item = pos;
    // Store event cycle id
    rinfo_ref.last_event_cycle_id = kernel.get_cycle_id();
    // Now, activate processes
    rinfo_ref.activate_processes();
    
  } else {
    // Remove and free transaction
    transactions.remove(pos);
    // Ok, the transaction did not cause an event. Hence, store the
    // current simulation time and cycle id.
    transactions.key(rinfo_ref.last_value_tr_item) = kernel.get_sim_time();
    rinfo_ref.last_active_cycle_id = kernel.get_cycle_id();
  }

  return true;
}




bool
g_trans_queue::assign_next_transactions()
{
  bool assignment_done = false;
  void *pos = global_transaction_queue.begin();
#ifdef EVENT_PROFILE
  int eventcount = 0;
#endif  

  // Reset last active wait elements. last_active_wait_elements is a
  // pointer which references the last wait element list that was used
  // to activate processes. This pointer is used to skip over wait
  // element lists which were already processed. E.g., if a process is
  // sensitive on a vector signal then the readers of all elements
  // will reference the same wait element list. If several elements of
  // a vector are assigned a new value then the corresponding readers
  // are usually processed sequentially. When the wait element list is
  // processed the first time then last_active_wait_elements will be
  // set to point to the wait element list. If another vector element
  // gets an event then last_active_wait_elements will be used to
  // detect that this wait element list has been processed
  // already. Hence, the list is not processed again!
  reset_last_active_wait_elements();

  while (pos && global_transaction_queue.key(pos) == sim_time) {
#ifdef EVENT_PROFILE
     eventcount++;
#endif  

    // Assign transaction to the reader if it has not been removed already
    bool result = global_transaction_queue.content(pos)->assign_first_transactions(sim_time);
    assignment_done = assignment_done || result;

    // Remove the entry from the global queue
    pos = global_transaction_queue.remove(pos);
  }

#ifdef EVENT_PROFILE
  event_number[eventcount]++;
#endif
  return assignment_done;
}

// Execute a simulation cycle. Returns whether there is still
// an transaction on the event list
bool
g_trans_queue::next_cycle() 
{
#ifdef EVENT_DEBUG
  debug("Next simulation cycle", __FILE__, __LINE__);
#endif
  // If there is no transaction on the global transaction queue
  // then return
  if (global_transaction_queue.begin() == NULL)
    return false;
  
  // Set simulation time (including delta counter)
  vtime new_sim_time = global_transaction_queue.key(global_transaction_queue.begin());
  if (new_sim_time == sim_time)
    delta++;
  else 
    delta=0;
  sim_time=new_sim_time;

  // Assign transactions
  assign_next_transactions();

  return true;
}

void g_trans_queue::add_to_queue(driver_info *driver, const vtime &time_value)
{
#ifdef EVENT_PROFILE
  long long int difference;
#endif
#ifdef EVENT_DEBUG
  debug("Added event", __FILE__, __LINE__);
#endif
#ifdef EVENT_PROFILE
  difference = time_value.value - sim_time.value;
  difference = difference / 1000;
  if (difference>65535) difference=65535;
  event_times[difference]++; 
#endif
  global_transaction_queue.inqueue(driver, time_value);
}

#ifdef EVENT_PROFILE
int g_trans_queue::event_report(char *filename) {
  int i;
  ofstream profilefile(filename,ios::out);
 
  if (profilefile.bad()) return false;

  profilefile << "Number of events per timetick:\n";
  for (i=0; i<1024; i++) {
    profilefile <<event_number[i]<< ": " << i  << "\n";
  }
  profilefile << "Delta time for events:\n";
  for (i=0; i<65536; i++) {
    profilefile <<event_times[i]<< ": " << i << "\n";
  }  
  profilefile.close();

  return true;
}
#endif

