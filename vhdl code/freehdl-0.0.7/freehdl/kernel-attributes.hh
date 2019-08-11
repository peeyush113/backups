#ifndef FREEHDL_KERNEL_ATTRIBUTES_H
#define FREEHDL_KERNEL_ATTRIBUTES_H

/* *************************************************************
 *  Function kind attributes for signals
 * ************************************************************* */

/* Event attribute for a scalar signal! Note that sinfo must reference
 * a scalar signal! */
inline int attr_scalar_EVENT (sig_info_core *sinfo)
{
  extern kernel_class kernel;
  return kernel.get_cycle_id() == sinfo->readers[0]->last_event_cycle_id;
}

/* Last_event attribute for a scalar signal! Note that sinfo must
 * reference a scalar signal! */
inline vtime attr_scalar_LAST_EVENT (sig_info_core *sinfo)
{
  if (fqueue<long long int, vtime>::key (sinfo->readers[0]->last_event_tr_item) < 0)
    return L3std_Q8standard_I4time_INFO.high_bound;
  else
    return kernel.get_sim_time () - 
      fqueue<long long int, vtime>::key (sinfo->readers[0]->last_event_tr_item);
}

/* Event attribute for a composite signal! */
int attr_composite_EVENT(sig_info_core *sinfo, acl *a);

/* Last_event attribute for a composite signal! */
vtime attr_composite_LAST_EVENT (sig_info_core *sinfo, acl *a);

/* Active attribute for a scalar signal! Note that sinfo must reference
 * a scalar signal! */
inline int attr_scalar_ACTIVE (sig_info_core *sinfo)
{
  extern kernel_class kernel;
  const reader_info &rinfo = *sinfo->readers[0];
  const int cycle_id = kernel.get_cycle_id();
  return (cycle_id == rinfo.last_event_cycle_id) || (cycle_id == rinfo.last_active_cycle_id);
}

/* Active attribute for a composite signal! */
int attr_composite_ACTIVE (sig_info_core *sinfo, acl *a);


/* Last vaue attribute for a scalar signal! Note that sinfo must
 * reference a scalar signal! */
template<class T>
T attr_scalar_LAST_VALUE (sig_info_core *sinfo)
{
  const reader_info &rinfo = *sinfo->readers[0];
  return (T&)fqueue<long long int, vtime>::content (rinfo.last_value_tr_item);
}


/* Attribute LAST_VALUE applied on a scalar part of a composite
 * signal! */
template<class T>
T attr_composite_LAST_VALUE (sig_info_core *sinfo, acl *a)
{
  int start = 0, end = 0;

  // Convert acl to start and end index for the reader_info array 
  sinfo->type->acl_to_index(a, start, end);
  const reader_info &rinfo = *sinfo->readers [start];
  return (T&)fqueue<long long int, vtime>::content (rinfo.last_value_tr_item);
}


/* Composite LAST_VALUE attribute for a composite signal! Note that
 * "value" is the part of the signal which is referenced by acl
 * "a". Moreover, "value" contains the *current* signal value. */
template<class T>
T attr_composite_LAST_VALUE (sig_info_core *sinfo, acl *a, T value)
{
  int start = 0, end = 0;

  // Convert acl to start and end index for the reader_info array 
  sinfo->type->acl_to_index (a, start, end);

  // First, determine the most recent event time of all considered
  // scalar readers
  vtime most_recent_event_time = LONG_LONG_MIN;
  for (int i = start; i <= end; i++) {
    const reader_info &rinfo = *sinfo->readers[i];
    most_recent_event_time =  
      max(most_recent_event_time, fqueue<long long int, vtime>::key (rinfo.last_value_tr_item));
  }

  // For each scalar element for which the last event time is equal to
  // the most recent event time: copy the "last value" into the
  // corresponding element. Note that "value" is initialized with the
  // current value of the signal.
  for (int i = start, j = 0; i <= end; i++, j++) {
    const reader_info &rinfo = *sinfo->readers[i];
    type_info_interface *scalar_type = sinfo->type->get_info(i);
    if (most_recent_event_time == fqueue<long long int, vtime>::key (rinfo.last_value_tr_item))
      scalar_type->copy (value.info->type_info_interface::element((void*)&value, j), 
			&fqueue<long long int, vtime>::content (rinfo.last_value_tr_item));
  }

  return value;
}



#endif
