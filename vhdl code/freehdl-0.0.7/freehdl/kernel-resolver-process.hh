#ifndef FREEHDL_KERNEL_RESOLVER_H
#define FREEHDL_KERNEL_RESOLVER_H

#ifdef KERNEL

#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-process-base.hh>
#include <freehdl/kernel-signal-source-list-array.hh>


// Currently not used
struct resolver_process : public process_base {
  // Array to store the drivers to be resolved
  array_base driver_array;
  // The actual resolver handler function
  resolver_handler_p handler;
  // Points to a newly allocated object to store the result of the
  // resolution function call
  void *resolved_reader;
  // Stores type id of resolved value
  type_id resolved_type_id;
  // Array to store the drivers associated with the resolved value
  driver_info *driver;

  // Performs the actual signal resolution
  bool execute();

  resolver_process(sig_info_base *signal, signal_source_list *source_list, void *comp, int level);
};


#endif
#endif
