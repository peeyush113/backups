#define KERNEL

#include <stdlib.h>
#include <freehdl/kernel-flags.hh>
#include <freehdl/std-standard.hh>
#include <freehdl/kernel-reader-info.hh>
#include <freehdl/kernel-driver-info.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <freehdl/kernel-fhdl-stream.hh>

const vtime zero_time = 0;

// free_items points to a list of free transaction items. Note, all
// transaction lists share the SAME free_item list.
template<>
void *fqueue<long long int, vtime>::free_items = NULL;


driver_info::driver_info(process_base *proc, sig_info_base *sig, int i) 
{
  process = proc;
  signal = sig;
  type = signal->type->get_info(i);
  index_start = i;
  rinfo = signal->readers[i];
  drivers = NULL;
  size = 0;
}



driver_info::driver_info(process_base *proc, sig_info_base *sig, type_info_interface *t, 
			 int i, driver_info **drvs, int sz) 
{
  process = proc;
  signal = sig;
  type = t;
  index_start = i;
  rinfo = NULL;
  drivers = drvs;
  size = sz;
}



/*************************************************************************
 *
 * Templates to create transactions for scalar signals
 *
 *************************************************************************/



// Creates a transaction with transport delay
template<class T>
inline int
do_scalar_transport_assignment(driver_info &driver, const T value, const vtime &time_value) 
{
  fqueue<lint, vtime> &transactions = driver.transactions;
  void *pos = transactions.start();
  vtime tr_time = kernel.get_sim_time() + time_value;
  
  while (transactions.next(pos)) {
    void *npos = transactions.next(pos);
    if (transactions.key(npos) >= tr_time) {
      transactions.cut_remove(npos);
      break;
    }
    pos = npos;
  }

  (T&)transactions.content(transactions.push_back(pos, tr_time)) = value;
  kernel.add_to_global_transaction_queue(&driver, tr_time);
  STATISTICS(kernel.created_transactions_counter++;);
  REPORT(kernel_output_stream << "Transaction (transport delay) for signal " << signal->instance_name <<
	 " (value=" << driver.type->str(value) << ", time=";
	 kernel_output_stream << L3std_Q8standard_I4time_INFO->str(&tr_time) << ") created." << endl;);

  return 1;
}


inline int
do_scalar_transport_assignment(driver_info &driver, type_info_interface *type,
			       const void *value, const vtime &tr_time) 
{
  fqueue<lint, vtime> &transactions = driver.transactions;
  void *pos = transactions.start();
  
  while (transactions.next(pos)) {
    void *npos = transactions.next(pos);
    if (transactions.key(npos) >= tr_time) {
      transactions.cut_remove(npos);
      break;
    }
    pos = npos;
  }

  type->fast_copy(&transactions.content(transactions.insert(pos, tr_time)), value);
  kernel.add_to_global_transaction_queue(&driver, tr_time);
  STATISTICS(kernel.created_transactions_counter++;);
  REPORT(kernel_output_stream << "Transaction (transport delay) for signal " << signal->instance_name <<
	 " (value=" << driver.type->str(value) << ", time=";
	 kernel_output_stream << L3std_Q8standard_I4time_INFO->str(&tr_time) << ") created." << endl;);

  return 1;
}




// Creates a transaction with inertial delay
template<class T>
inline int
do_scalar_inertial_assignment(driver_info &driver, const T value, 
			      const vtime &time_value, const vtime &start_time) 
{
  fqueue<lint, vtime> &transactions = driver.transactions;
  void *pos = transactions.start();
  vtime rm_time = kernel.get_sim_time() + start_time;

  while (transactions.next(pos) && transactions.key(transactions.next(pos)) < rm_time)
    pos = transactions.next(pos);
  void *start_pos = pos;

  void *rpos = NULL;
  vtime tr_time = kernel.get_sim_time() + time_value;
  while (transactions.next(pos)) {
    void *npos = transactions.next(pos);
    if (transactions.key(npos) >= tr_time) {
      transactions.cut_remove(npos);
      break;
    }
    if (value != ((T&)transactions.content(npos))) {
      if (rpos)
	while (rpos != npos)
	  rpos = transactions.remove(npos);
      transactions.remove(npos);
      rpos = NULL;
      pos = start_pos;
    } else {
      rpos = rpos? rpos : npos;
      pos = npos;
    }
  }
    
  (T&)transactions.content(transactions.push_back(pos, tr_time)) = value;
  kernel.add_to_global_transaction_queue(&driver, tr_time);
  STATISTICS(kernel.created_transactions_counter++;);
  REPORT(kernel_output_stream << "Transaction (inertial delay) for signal " << signal->instance_name <<
	 " (value=" << type->str(value) << ", time=";
	 kernel_output_stream << L3std_Q8standard_I4time_INFO->str(&tr_time) << ") created." << endl;);

  return 1;
}


// Creates a transaction with inertial delay
inline int
do_scalar_inertial_assignment(driver_info &driver, type_info_interface *type, const void *value, 
			      const vtime &tr_time, const vtime &rm_time) 
{
  fqueue<lint, vtime> &transactions = driver.transactions;
  void *pos = transactions.start();

  while (transactions.next(pos) && transactions.key(transactions.next(pos)) < rm_time)
    pos = transactions.next(pos);
  void *start_pos = pos;

  void *rpos = NULL;
  while (transactions.next(pos)) {
    void *npos = transactions.next(pos);
    if (transactions.key(npos) >= tr_time) {
      transactions.cut_remove(npos);
      break;
    }
    if (!type->fast_compare(value, &transactions.content(npos))) {
      if (rpos)
	while (rpos != npos)
	  rpos = transactions.remove(npos);
      transactions.remove(npos);
      rpos = NULL;
      pos = start_pos;
    } else {
      rpos = rpos? rpos : npos;
      pos = npos;
    }
  }
    
  type->fast_copy(&transactions.content(transactions.insert(pos, tr_time)), value);
  kernel.add_to_global_transaction_queue(&driver, tr_time);
  STATISTICS(kernel.created_transactions_counter++;);
  REPORT(kernel_output_stream << "Transaction (inertial delay) for signal " << signal->instance_name <<
	 " (value=" << type->str(value) << ", time=";
	 kernel_output_stream << L3std_Q8standard_I4time_INFO->str(&tr_time) << ") created." << endl;);

  return 1;
}




// Creates a transaction with inertial delay where the plus reject
// interval is equal to the delay value.
template<class T>
inline int
do_scalar_inertial_assignment(driver_info &driver, const T value, const vtime &time_value) 
{
  fqueue<lint, vtime> &transactions = driver.transactions;
  void *pos = transactions.start();

  // Check if the new value and the current value of the signal are
  // equal. If they are equal then the assignment cannot produce an
  // *event*. Hence, the transaction can be skipped if the transaction
  // queue of the driver is empty (otherwise the assignement may
  // remove other pending transactions). Note, this technique can be
  // used only if the signal is *not resolved* and none of the
  // attributes TRANSACTION or QUIET or ... are applied on this
  // signal!
  if (value == *((T*)driver.rinfo->reader) && 
      pos == NULL) 
    return 1;
  
  void *new_pos = transactions.new_item();
  vtime tr_time = kernel.get_sim_time() + time_value;

  (T&)transactions.content(new_pos) = value;
  transactions.key(new_pos) = tr_time;
  
  void *rpos = NULL;
  while (transactions.next(pos)) {
    void *npos = transactions.next(pos);
    if (transactions.key(npos) >= tr_time) {
      transactions.cut_remove(npos);
      break;
    }
    if (value != ((T&)transactions.content(npos))) {
      if (rpos)
	while (rpos != npos)
	  rpos = transactions.remove(npos);
      transactions.remove(npos);
      rpos = NULL;
      pos = transactions.start();
    } else {
      rpos = rpos? rpos : npos;
      pos = npos;
    }
  }
    
  transactions.push_back(pos, new_pos);
  kernel.add_to_global_transaction_queue(&driver, tr_time);
  STATISTICS(kernel.created_transactions_counter++;);
  REPORT(kernel_output_stream << "Transaction (inertial delay) for signal " << signal->instance_name <<
	 " (value=" << driver.type->str(value) << ", time=";
	 kernel_output_stream << L3std_Q8standard_I4time_INFO->str(&tr_time) << ") created." << endl;);

  return 1;
}



/*************************************************************************
 *************************************************************************
 *
 * Methods to create transctions for array signals 
 *
 *************************************************************************
 *************************************************************************/


// Creates transaction composite signals. Returns number of assigned scalars.
inline int
do_array_transport_assignment(driver_info &driver, const array_base &value, int first, const vtime &tr_time) 
{
  type_info_interface *etype = value.info->element_type;

  if (etype->scalar()) {
    //******************************************************************************
    // If the elements of the array are scalar then ....  First get
    // index range of scalar elements that are target of the assigment
    //******************************************************************************
    int length = value.info->length; // Determine length of assignment
    int element_size = etype->size; // Get size of an array element
    int index_start = driver.index_start;
    //    first -= index_start;

    // Now create a separate transaction for each scalar element of
    // the target
    for (int i = 0, j = first - index_start, k = 0; i < length; i++, j++, k += element_size)
      // Note, the current driver_info instance does not store the
      // transaction lists but an array of pointers to scalar
      // driver_info instances!
      do_scalar_transport_assignment(*driver.drivers[j], etype, &value.data[k], tr_time);
    
    return length;

  } else {
    //******************************************************************************
    // If the elements are of a composite type ....
    //******************************************************************************
    // Get number of scalar elements each array element consist of
    int length = value.info->length; // Determine length of assignment
    int step = etype->element_count(); // Number of scalar elements
    int assigned_scalars = 0;
    // each array element consists of
    int element_size = etype->size; 
    for (int i = first, j = 0, k = 0; k < length; k++, j += element_size, i += step) {
      switch (etype->id) {
      case ARRAY:
	assigned_scalars += do_array_transport_assignment(driver, (array_base&)value.data[j], i, tr_time);
	break;
      case RECORD:
	inline int do_record_transport_assignment(driver_info &, const record_base &, int, const vtime &);
	assigned_scalars += do_record_transport_assignment(driver, (record_base&)value.data[j], i, tr_time);
	break;
      }
    }

    return assigned_scalars;
  }
}


// Creates transaction composite signals
void
driver_info::transport_assign(const array_base &value, int first, const vtime &time_value) 
{
  // Make sure that the assignement is not out of bounds of the
  // target array
  if (value.info->element_count() + first > ((array_info*)type)->element_count())
    error(ERROR_ARRAY_INDEX_OUT_OF_BOUNDS);

  // First calculate transaction time and remove time
  vtime tr_time = kernel.get_sim_time() + time_value;

  do_array_transport_assignment(*this, value, first, tr_time);
}


// Creates transaction for composite signals. Returns number of assigned scalars.
inline int
do_array_inertial_assignment(driver_info &driver,
			     const array_base &value, int first, 
			     const vtime &tr_time, const vtime &rm_time) 
{
  type_info_interface *etype = value.info->element_type;

  if (etype->scalar()) {
    //******************************************************************************
    // If the elements of the array are scalar then ....  First get
    // index range of scalar elements that are target of the assignment
    //******************************************************************************
    int length = value.info->length; // Determine length of assignment
    int element_size = etype->size; // Get size of an array element

    // Now create a separate transaction for each scalar element of
    // the target
    int index_start = driver.index_start;
    for (int i = 0, j = first - index_start, k = 0; i < length; i++, j++, k += element_size)
      // Note, the current driver_info instance does not store the
      // transaction lists but an array of pointers to scalar
      // driver_info instances!
      do_scalar_inertial_assignment(*driver.drivers[j], etype, &value.data[k], tr_time, rm_time);

    return length;

  } else {
    //******************************************************************************
    // If the elements are of a composite type ....
    //******************************************************************************
    // Get number of scalar elements each array element consist of
    int length = value.info->length; // Determine length of assignment
    // Number of scalar elements each array element consists of
    int step = etype->element_count(); 
    int element_size = etype->size;  
    int assigned_scalars = 0;
    for (int i = first, j = 0, k = 0; k < length; k++, j += element_size, i += step) {
      switch (etype->id) {
      case ARRAY:
	assigned_scalars += do_array_inertial_assignment(driver, (array_base&)value.data[j], i, tr_time, rm_time);
	break;
      case RECORD:
	inline int do_record_inertial_assignment(driver_info &, const record_base &, int,  
						  const vtime &, const vtime &); 
	assigned_scalars += do_record_inertial_assignment(driver, (record_base&)value.data[j], i, tr_time, rm_time);
	break;
      }
    }

    return assigned_scalars;
  }
}



// Creates transaction for composite signals
void
driver_info::inertial_assign(const array_base &value, int first, const vtime &time_value, 
			     const vtime &start_time) 
{
  // Make sure that the assignement is not out of bounds of the
  // target array
  if (value.info->element_count() + first > ((array_info*)type)->element_count())
    error(ERROR_ARRAY_INDEX_OUT_OF_BOUNDS);

  // First calculate transaction time and remove time
  vtime tr_time = kernel.get_sim_time() + time_value;
  vtime rm_time = kernel.get_sim_time() + start_time;

  do_array_inertial_assignment(*this, value, first, tr_time, rm_time);
}


/*************************************************************************
 *************************************************************************
 *
 * Methods to create record signals 
 *
 *************************************************************************
 *************************************************************************/

// Creates transaction record signals. Returns number of assigned scalars.
inline int
do_record_transport_assignment(driver_info &driver, const record_base &value, int first, const vtime &tr_time) 
{
  const record_info &rinfo = *value.info;
  int assigned_scalars = 0;

  for (int i = 0, j = first - driver.index_start;
       i < rinfo.record_size; 
       j += rinfo.element_types[i++]->element_count()) {
    switch (rinfo.element_types[i]->id) {
    case ARRAY:
      assigned_scalars += do_array_transport_assignment(driver, *(array_base*)(*rinfo.element_addr) (value.data, i),
							first + assigned_scalars, tr_time);
      break;
    case RECORD:
      assigned_scalars += do_record_transport_assignment(driver, *(record_base*)(*rinfo.element_addr) (value.data, i),
							 first + assigned_scalars, tr_time);
      break;
    default:
      do_scalar_transport_assignment(*driver.drivers[j], rinfo.element_types[i], 
				     (*rinfo.element_addr) (value.data, i), tr_time);
      assigned_scalars ++;
    }
  }

  return assigned_scalars;
}


void 
driver_info::transport_assign(const record_base &value, int first, const vtime &time_value)
{
  // First calculate transaction time and remove time
  vtime tr_time = kernel.get_sim_time() + time_value;

  do_record_transport_assignment(*this, value, first, tr_time);
}


// Creates transaction record signals. Returns number of assigned scalars.
inline int
do_record_inertial_assignment(driver_info &driver, const record_base &value, int first,  
			      const vtime &tr_time, const vtime &rm_time) 
{
  const record_info &rinfo = *value.info;
  int assigned_scalars = 0;

  for (int i = 0, j = first - driver.index_start; 
       i < rinfo.record_size; 
       j += rinfo.element_types[i++]->element_count()) {
    switch (rinfo.element_types[i]->id) {
    case ARRAY:
      assigned_scalars += do_array_inertial_assignment(driver, *(array_base*)(*rinfo.element_addr) (value.data, i),
						       first + assigned_scalars, tr_time, rm_time);
      break;
    case RECORD:
      assigned_scalars += do_record_inertial_assignment(driver, *(record_base*)(*rinfo.element_addr) (value.data, i), 
							first + assigned_scalars, tr_time, rm_time);
      break;
    default:
      do_scalar_inertial_assignment(*driver.drivers[j], rinfo.element_types[i], 
				    (*rinfo.element_addr) (value.data, i),
				    tr_time, rm_time);
      assigned_scalars ++;
    }
  }

  return assigned_scalars;
}


void 
driver_info::inertial_assign(const record_base &value, int first, const vtime &time_value, 
			     const vtime &start_time)
{
  // First calculate transaction time and remove time
  vtime tr_time = kernel.get_sim_time() + time_value;
  vtime rm_time = kernel.get_sim_time() + start_time;

  do_record_inertial_assignment(*this, value, first, tr_time, rm_time);
}


/*************************************************************************
 *************************************************************************
 *
 * Methods to create transactions for scalar signals 
 *
 *************************************************************************
 *************************************************************************/

// A special method which removes all pending transactions from the
// current driver list, initializes the driver to the given value
// and assigns a new transaction.
void 
driver_info::reset_assign(const enumeration reset_value, const enumeration value,
			  const vtime &time_value)
{
  // Reset reader of signal
  *((enumeration*)rinfo->reader) = reset_value;
  // Caluclate transaction time
  const vtime tr_time = kernel.get_sim_time() + time_value;
  // Remove all transactions from the list
  void *pos = transactions.begin();
  if (pos) 
    transactions.cut_remove(pos);
  // Finally, add a new one
  void *new_pos = transactions.new_item();
  (enumeration&)transactions.content(new_pos) = value;
  transactions.key(new_pos) = tr_time;
  // Add new transaction to list and pass over driver pointer to the
  // kernel.
  transactions.push_back(transactions.start(), new_pos);
  kernel.add_to_global_transaction_queue(this, tr_time);
  STATISTICS(kernel.created_transactions_counter++;);
  REPORT(kernel_output_stream << "Transaction (inertial delay) for signal " << signal->instance_name <<
	 " (value=" << driver.type->str(value) << ", time=";
	 kernel_output_stream << L3std_Q8standard_I4time_INFO->str(&tr_time) << ") created." << endl;)
}



// Creates transaction for enumeration signals
void
driver_info::transport_assign(const enumeration value, const vtime &time_value) 
{
  do_scalar_transport_assignment<enumeration>(*this, value, time_value);
}



// Creates transaction for integer signals
void
driver_info::transport_assign(const integer value, const vtime &time_value) 
{
  do_scalar_transport_assignment<integer>(*this, value, time_value);
}



// Creates transaction for floating point signals
void
driver_info::transport_assign(const floatingpoint value, const vtime &time_value) 
{
  do_scalar_transport_assignment<floatingpoint>(*this, value, time_value);
}



// Creates transaction for physical signals
void
driver_info::transport_assign(const physical value, const vtime &time_value) 
{
  do_scalar_transport_assignment<physical>(*this, value, time_value);
}





// Creates transaction for enumeration signals
void
driver_info::inertial_assign(const enumeration value, const vtime &time_value, 
			     const vtime &start_time) 
{
  do_scalar_inertial_assignment<enumeration>(*this, value, time_value, start_time);
}



// Creates transaction for integer signals
void
driver_info::inertial_assign(const integer value, const vtime &time_value, 
			     const vtime &start_time) 
{
  do_scalar_inertial_assignment<integer>(*this, value, time_value, start_time);
}



// Creates transaction for floating point signals
void
driver_info::inertial_assign(const floatingpoint value, const vtime &time_value, 
			     const vtime &start_time) 
{
  do_scalar_inertial_assignment<floatingpoint>(*this, value, time_value, start_time);
}



// Creates transaction for physical signals
void
driver_info::inertial_assign(const physical value, const vtime &time_value, 
			     const vtime &start_time) 
{
  do_scalar_inertial_assignment<physical>(*this, value, time_value, start_time);
}






// Creates transaction for enumeration signals
void
driver_info::inertial_assign(const enumeration value, const vtime &time_value) 
{
  do_scalar_inertial_assignment<enumeration>(*this, value, time_value);
}


// Creates transaction for integer signals
void
driver_info::inertial_assign(const integer value, const vtime &time_value) 
{
  do_scalar_inertial_assignment<integer>(*this, value, time_value);
}


// Creates transaction for floatingpoint signals
void
driver_info::inertial_assign(const floatingpoint value, const vtime &time_value) 
{
  do_scalar_inertial_assignment<floatingpoint>(*this, value, time_value);
}


// Creates transaction for physical signals
void
driver_info::inertial_assign(const physical value, const vtime &time_value) 
{
  do_scalar_inertial_assignment<physical>(*this, value, time_value);
}














