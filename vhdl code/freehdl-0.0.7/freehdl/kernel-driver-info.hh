#ifndef FREEHDL_KERNEL_DRIVER_INFO_H
#define FREEHDL_KERNEL_DRIVER_INFO_H

#include <assert.h>
#include <freehdl/kernel-classes.hh>
#include <freehdl/kernel-list.hh>
#include <freehdl/std-standard.hh>

extern const vtime zero_time;


class driver_info {
public:
  // If the signal is of a scalar type then the queue stores long long
  // int values which can be used to take all other scalar VHDL type
  // values if the signal is of a scalar type. Otherwise, the queue
  // does not store any useful information
  fqueue<long long int, vtime> transactions;
  // Points to the corresponding reader_info instance
  reader_info *rinfo;   
  // Type of the corresponding signal
  type_info_interface *type;
  // Signal this driver is connected with
  sig_info_base *signal;
  // Process this driver belongs to
  process_base *process;
  // Start index number. If the signal is of a composite type then
  // index_start stores the first index identifier of the SCALAR
  // signal which is driven by this driver. size is the length of the
  // drivers array.
  int index_start, size;
  // If the driven signal is of a composite
  // type then drivers is pointing to an array which stores
  // driver_info pointers for the corresponding scalar drivers.
  driver_info **drivers;

  // Constructors
  driver_info(process_base *proc, sig_info_base *sig, int i = 0);
  driver_info(process_base *proc, sig_info_base *sig, type_info_interface *t, int i, driver_info **drvs, int sz);

  // Returns scalar driver. Note, this method return invalid results
  // if it is called for a scalar driver_info instance!
  inline driver_info *scalar_driver(acl *a) const {
    int first = 0, last;
    return drivers[type->acl_to_index(a, first, last) - index_start]; 
  }

  // Returns scalar driver of a composite signal. Note, this method
  // return invalid results if it is called for a scalar driver_info
  // instance! It is used to create a transaction for a scalar element
  // of an composite signal. Index i denotes the index identifier of
  // the scalar element.
  inline driver_info *scalar_driver(int i) const {
    return drivers[i - index_start]; 
  }

  // Notes on composite signals: Each scalar element of a composite
  // signal is assigend an unique INDEX identifier. Index identifier
  // calculation is based on index offsets: 
  //
  //   1. The index offset value of a scalar type is 0. 
  //   2. The index offset value of an array element (which is either 
  //      scalar or non scalar) is the absolute value of the 
  //      corresponding array index of the element minus 
  //      array'left and then multiplied by the number of scalars 
  //      each array element consists of. 
  //   3. The index offset value of a specific record element "x" is 
  //      sum of the scalar elements of all record items preceeding
  //      the corresponding element definition "x" within the record. 
  //
  // Finally, the index identifier of a scalar element is calculated
  // by summing up the index offset values of all composite elements
  // which cover the corresponding scalar element.

  // Create transactions for array signals. This methods are used to
  // create transactions for more than a single scalar element of a
  // array signal (or if the compiler can not determine the number of
  // scalar elements which are affected by the assignment
  // operation). first is the (smallest) index identifier of the first
  // SCALAR element affected by the assignment, last is the last
  // (greatest) index identifier of the target SCALAR element.
  void transport_assign(const array_base &value, int first, const vtime &time_value);
  void transport_assign(const array_base &value, const vtime &time_value) {
    transport_assign(value, 0, time_value);
  }
  void inertial_assign(const array_base &value, int first, const vtime &time_value, 
		       const vtime &start_time = zero_time);

  void transport_assign(const record_base &value, int first, const vtime &time_value);
  void transport_assign(const record_base &value, const vtime &time_value) {
    transport_assign(value, 0, time_value);
  }
  void inertial_assign(const record_base &value, int first, const vtime &time_value, 
		       const vtime &start_time = zero_time);
  // Similar to the methods before but the start index is derived form
  // the acl instance a.
  void transport_assign(const array_base &value, acl *a, const vtime &time_value) {
    transport_assign(value, type->acl_to_index(a), time_value);
  }
  void inertial_assign(const array_base &value, acl *a, const vtime &time_value, 
		       const vtime &start_time = zero_time) {
   inertial_assign(value, type->acl_to_index(a), time_value, start_time);
  }
  void transport_assign(const record_base &value, acl *a, const vtime &time_value)
  {
    transport_assign(value, type->acl_to_index(a), time_value);
  }
  void inertial_assign(const record_base &value, acl *a, const vtime &time_value, 
		       const vtime &start_time = zero_time)
  {
    inertial_assign(value, type->acl_to_index(a), time_value, start_time);
  }

  // Creates transactios for scalar signals
  void transport_assign(const enumeration value, const vtime &time_value);
  void inertial_assign(const enumeration value, const vtime &time_value);
  void inertial_assign(const enumeration value, const vtime &time_value, 
		       const vtime &start_time);

  void transport_assign(const integer value, const vtime &time_value);
  void inertial_assign(const integer value, const vtime &time_value);
  void inertial_assign(const integer value, const vtime &time_value, 
		       const vtime &start_time);

  void transport_assign(const floatingpoint value, const vtime &time_value);
  void inertial_assign(const floatingpoint value, const vtime &time_value);
  void inertial_assign(const floatingpoint value, const vtime &time_value, 
		       const vtime &start_time);

  void transport_assign(const physical value, const vtime &time_value);
  void inertial_assign(const physical value, const vtime &time_value);
  void inertial_assign(const physical value, const vtime &time_value, 
		       const vtime &start_time);

  // A special method which removes all pending transactions from the
  // current driver list, initializes the driver to the given value
  // and assigns a new transaction.
  void reset_assign(const enumeration reset_value, const enumeration value,
		    const vtime &time_value);

  // This methods assigns the first transactions with time stamp time_value
  // on the local driver list on the corresponding reader. It returns whether
  // there was really a transaction with a corresponding time stamp or not.
  // Note that the method is defined in "global_event_queue.cc"!!!!
  inline bool assign_first_transactions(const vtime &time_value);
};


/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

// Assign a scalar. This function is NOT used by the generated code
// but is called by kernel code.
inline void
do_scalar_zero_delay_assignment(type_id id, driver_info *driver, void *reader)
{
  switch (id) {
  case INTEGER: 
    driver->transport_assign(*(integer*)reader, zero_time); 
    break;
  case ENUM:
    driver->transport_assign(*(enumeration*)reader, zero_time); 
    break;
  case FLOAT:
    driver->transport_assign(*(floatingpoint*)reader, zero_time); 
    break;
  case PHYSICAL:
    driver->transport_assign(*(physical*)reader, zero_time); 
    break;
  default:
    assert(true);
  }
}


#endif


#endif
