#ifndef FREEHDL_KERNEL_GLOBAL_EVENT_QUEUE_H
#define FREEHDL_KERNEL_GLOBAL_EVENT_QUEUE_H

// FreeHDL global event queue class headers
// Author: Geir Harris Hedemark (geirhe@ifi.uio.no)
// Created: 19981014

#include <freehdl/std-standard.hh>
#include <freehdl/kernel-driver-info.hh>
#include <freehdl/kernel-list.hh>

class g_trans_queue {
  simple_queue<driver_info*, vtime> global_transaction_queue;
  vtime sim_time;
  int delta;

#ifdef EVENT_PROFILE
  //"time to scheduled event". Values >65535 is collapsed to 65535
  int event_times[65536];
  //"number of events". Counts the number of elements in a queue before
  //scheduling. No>1023 are are collapsed to 1023
  int event_number[1024];
#endif

public:
  g_trans_queue();
  ~g_trans_queue();
  bool assign_next_transactions();
  bool next_cycle();
  void add_to_queue(driver_info *driver, const vtime &time_value);
  inline bool empty() const { return (global_transaction_queue.begin() == NULL); }
  const vtime &get_sim_time(void) { return sim_time; }
  const vtime get_next_pending_event_time (void) { 
    return empty () ? LONG_LONG_MAX : global_transaction_queue.key(global_transaction_queue.begin());
  }
  int get_delta(void) { return delta; }

#ifdef EVENT_PROFILE
  int event_report(char *filename);
#endif
};

#endif
