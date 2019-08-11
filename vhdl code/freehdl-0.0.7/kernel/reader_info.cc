#define KERNEL
#include <freehdl/kernel-wait-info.hh>
#include <freehdl/kernel-reader-info.hh>
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
const shared_array<wait_info> *last_active_wait_elements = NULL;
// An empty wait element list.
const shared_array<wait_info> dummy_wait_elements;


reader_info::reader_info(void *r, type_info_interface *type) 
{
  reader = r;
  // Get transaction item to hold the current event transaction and
  // initialize its value. The initialization value is set to
  // L3std_Q8standard_I4time_INFO.low_bound to -1.
  last_event_tr_item = fqueue<long long int, vtime>::get_new_item();
  type->fast_copy(&fqueue<long long int, vtime>::content(last_event_tr_item), reader);
  fqueue<long long int, vtime>::key(last_event_tr_item) = -1;
  // Set value to -1 to show that up to now no event occured on this reader
  last_event_cycle_id = -1; 
  // Get transaction item to hold the last value
  last_value_tr_item = fqueue<long long int, vtime>::get_new_item();
  type->fast_copy(&fqueue<long long int, vtime>::content(last_value_tr_item), reader);
  fqueue<long long int, vtime>::key(last_value_tr_item) = -1;
  // Set value to -1 to show that up to now no transaction has been
  // assigned to this reader
  last_active_cycle_id = -1;
}


