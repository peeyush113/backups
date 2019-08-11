#define KERNEL // Include internal kernel definitions

#include <freehdl/kernel-error.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <freehdl/kernel-reader-info.hh>
#include <freehdl/kernel-driver-info.hh>
#include <freehdl/kernel-attributes.hh>



/* *************************************************************
 *  Function kind attributes for signals
 * ************************************************************* */

/* Event attribute for a composite signal! */
int attr_composite_EVENT(sig_info_core *sinfo, acl *a)
{
  int start = 0, end = 0;

  // Convert acl to start and end index for the reader_info array 
  sinfo->type->acl_to_index(a, start, end);

  // Check each corresponding reader_info instance to test whether an
  // event occured on that scalar element. If at least one item has an
  // event then return 1.
  const int cycle_id = kernel.get_cycle_id();
  for (int i = start; i <= end; i++) 
    if (cycle_id == sinfo->readers[i]->last_event_cycle_id)
      return 1;

  return 0;
}


/* Last_event attribute for a composite signal! */
vtime attr_composite_LAST_EVENT (sig_info_core *sinfo, acl *a)
{
  int start = 0, end = 0;

  // Convert acl to start and end index for the reader_info array 
  sinfo->type->acl_to_index(a, start, end);

  // Check each corresponding reader_info instance to search for the
  // minimum time.
  vtime t = L3std_Q8standard_I4time_INFO.low_bound;
  for (int i = start; i <= end; i++) 
    t = max (t, fqueue<long long int, vtime>::key (sinfo->readers[i]->last_event_tr_item));
  
  if (t < 0)
    return L3std_Q8standard_I4time_INFO.high_bound;
  else
    return kernel.get_sim_time () - t;
}



/* Active attribute for a composite signal! */
int attr_composite_ACTIVE(sig_info_core *sinfo, acl *a)
{
  int start = 0, end = 0;

  // Convert acl to start and end index for the reader_info array 
  sinfo->type->acl_to_index(a, start, end);

  // Check each corresponding reader_info instance to test whether an
  // event occured on that scalar element. If at least one item has an
  // event then return 1.
  const int cycle_id = kernel.get_cycle_id();
  for (int i = start; i <= end; i++) {
    const reader_info &rinfo = *sinfo->readers[i];
    if(cycle_id == rinfo.last_event_cycle_id || cycle_id == rinfo.last_active_cycle_id)
      return 1;
  }

  return 0;
}
