#ifndef FREEHDL_KERNEL_WAIT_INFO_H
#define FREEHDL_KERNEL_WAIT_INFO_H

#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-sigacl-list.hh>
#include <freehdl/kernel-process-base.hh>

#define PROCESS_STOP SHRT_MAX
#define PRIORITY_PROCESS SHRT_MIN


class wait_info {
 public:
  // Id of the wait info instance
  short wait_id;
  // Process this wait_info object belongs to
  process_base *process;
  // Setup a wait_info instance
  int init(const sigacl_list &salist, process_base *proc);
  wait_info() {};
  wait_info(int id, process_base *proc);
};


/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

inline bool
is_equal(const wait_info &a, const wait_info &b) {
  return (a.wait_id == b.wait_id) && (a.process == b.process);
}

inline unsigned long
get_hash(const wait_info &w) {
  return (unsigned long)w.wait_id + (unsigned long)w.process;
}

#endif

#endif
