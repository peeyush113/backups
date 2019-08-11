#define KERNEL // Include internal kernel definitions

using namespace std;
#include <freehdl/kernel-error.hh>
#include <freehdl/kernel-db.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <freehdl/kernel-reader-info.hh>
#include <freehdl/kernel-driver-info.hh>
#include <freehdl/kernel-register.hh>
#include <freehdl/kernel-signal-source-list-array.hh>
#include <freehdl/kernel-map-list.hh>

// signal_table is a hash tables (map) to associate signal names with
// the corresponding sig_info_base pointers.
signal_map_t signal_name_table;

// A stack which is used to keep track which signals has been created
// within which component during elaboration. Note that this stack
// does only include any valid data during elaboration. It is cleared
// before simulation starts.
signal_component_stack_t signal_component_stack;



sig_info_base::sig_info_base(name_stack &iname, const char *n, const char *sln, map_list *mlist,
			     type_info_interface *ty, char dir, void *sr)
{
  // Setup connection to the kernel data base and create a new entry
  // associated with the current sig info pointer.
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  sig_info_extensions &extra_sig_info_data = sig_info_ext.get (this);

  // Put signal name on top of name stack
  iname.set(n);

  extra_sig_info_data.kernel_flags = 0;
  extra_sig_info_data.instance_name = iname.get_name();
  if (signal_name_table.find (extra_sig_info_data.instance_name) != signal_name_table.end())
    error((string("Dublicate instance name '") + extra_sig_info_data.instance_name + string("'")).c_str());
  signal_name_table [extra_sig_info_data.instance_name] = this; // Store sig_info_base pointer into global hash table
  extra_sig_info_data.name = iname.get_top();
  type = ty;
  extra_sig_info_data.sig_type = vREGISTER;
  extra_sig_info_data.kind = vPLAIN;
  extra_sig_info_data.mode = dir;

  extra_sig_info_data.scalar_count = type->element_count(); // Get number of scalar elements of the current formal

  list<signal_link*> link_list;
  bool associated_with_signal = false;
  bool associated_with_constant = false;
  // Test whether the signal has a father
  if (mlist != NULL &&
      query_signal(mlist, link_list, extra_sig_info_data.name))
    {
      if (link_list.size() > 1) // Currently only an entire formal can be mapped! 
	error(ERROR_NOT_SUPPORTED, "Sorry, currently only an entire formal can be mapped!");
      // Check whether the entire acutal is empty (i.e., formal is
      // asscociated with open) or the entire formal has been
      // asscoiated.
      unsigned int associated_elements = 0;
      for (list<signal_link*>::iterator  iter = link_list.begin ();
	   iter != link_list.end ();
	   iter++)
	if ((*iter)->actual_signal != NULL) 
	  {
	    // Associated with a signal
	    associated_with_signal = true;
	    associated_elements ++;
	  }
	else if ((*iter)->value != NULL) 
	  {
	    // Associated with a constant value
	    associated_with_constant = true;
	    associated_elements ++;
	  }
      
      if (associated_elements != 0 &&
	  associated_elements != link_list.size ())
	error((string("Not all elements of formal '") + iname.get_name () + string("' are left open!")).c_str());
    }
      
  if (associated_with_signal)
    { 
      fl_link connection;
      connection.formal_aclp = NULL;
      connection.actual_aclp = link_list.front()->actual_aclp->clone();
      connection.wrapper_fn_formal = NULL; // Currently not supported
      connection.wrapper_fn_actual = NULL; // Currently not supported
      connection.actual = link_list.front()->actual_signal;
      
      port_signal_link_map[this].push_back(connection);
      
      sig_info_base &actual = *connection.actual;
      
      // If scalar count < 0 then formal is an unconstrained array type
      // and we must determine the array bounds from the actual
      if (extra_sig_info_data.scalar_count < 0) 
	{
	  vector<int> left, right;
	  vector<range_direction> range_dir;
	  // Calculate the array bounds from the association list and create a new
	  // array_info instance. Note, this instance will be not removed until end
	  // of simulation.
	  array_info *ainfo_pointer = (array_info*)type;
	  get_unconstrained_port_array_bounds (&link_list, extra_sig_info_data.name, ainfo_pointer, left, range_dir, right);
	  // Note that the array may be a multi-dimensional array. Hence,
	  // we have do do a little bit more here... First, collect all
	  // array info pointer that belong to the (multi-dimensional)
	  // array.
	  type = create_array_info_for_unconstrained_link_array (ainfo_pointer, left, range_dir, right, -1);
	  // Recalculate number of scalar elements 
	  extra_sig_info_data.scalar_count = type->element_count ();
	  // Get reader of the signal 
	  reader_pointer = actual.type->element (actual.reader_pointer, connection.actual_aclp);
	  // Free type info instance
	  if (ainfo_pointer != NULL) 
	    ainfo_pointer->remove_ref ();
	  
	} 
      else if (type->id == ARRAY) 
	{
	  // Create a new array instance with its info and data pointer
	  // set to NULL
	  array_base *new_array = (array_base*)type->create();
	  new_array->set_info((array_info*)type); // Set info instance of array
	  
	  // First, determine the last acl level value. Note that an acl
	  // "level" is either an single number or a range desciptor (in
	  // case of an array slice).
	  acl *last_aclp = get_level(connection.actual_aclp, count_levels(connection.actual_aclp));
	  if (last_aclp->end() ||
	      last_aclp->get() != ACL_RANGE)
	    // If the last level is not an slice, then an entire array is
	    // mapped. Hence, get the array and extract the data pointer
	    // from this array.
	    new_array->data = ((array_base*)actual.type->element(actual.reader_pointer, connection.actual_aclp))->data;
	  else
	    // A slice of an array is mapped. Hence, get the pointer to
	    // the very first left element that is mapped. Note that
	    // method "element" returns the address of the left element in
	    // case of the acl (second parameter) is a range.
	    new_array->data = (char*)actual.type->element(actual.reader_pointer, connection.actual_aclp);
	  
	  reader_pointer = (void*)new_array;
	} 
      else
	// Get actual and assign actual pointer to current
	// reader_pointer
	reader_pointer = actual.type->element(actual.reader_pointer, connection.actual_aclp);
      

      // Get reader_info pointers
      readers = new reader_info*[extra_sig_info_data.scalar_count];
      int start = 0, end;
      actual.type->acl_to_index(connection.actual_aclp, start, end);
      for (int i = 0, j = start; i < extra_sig_info_data.scalar_count; i++, j++)
	readers[i] = actual.readers[j];
      
      
      // Initialize reader value of signal if mode is not in or
      // inout. Note that we initialize the reader to its default value
      // in case of no explicit default value is specified for this
      // signal. The new value will override any start value of the
      // father signal.
      if (dir != vIN && dir != vINOUT) 
	{
	  void *init_value = type->create();
	  type->copy(reader_pointer, init_value);
	  type->remove(init_value);
	}
    } 
  else 
    { 
      // The signal has no father, hence a new signal is created
      reader_pointer = type->create();
      readers = new reader_info*[extra_sig_info_data.scalar_count];
      for (int i = 0; i < extra_sig_info_data.scalar_count; i++)
	readers[i] = new reader_info(type->element(reader_pointer, i), type->get_info(i));
    }
  
  // Next, set all correspondig reader elements that are associated
  // with an expression in the port map aspect.
  for (list<signal_link*>::iterator  iter = link_list.begin ();
       iter != link_list.end ();
       iter++)
    if ((*iter)->value != NULL) 
      {
	(*iter)->type->copy (type->element (reader_pointer, (*iter)->formal_aclp), (*iter)->value);
      }
  

  // Set value of event and last_value transaction
  for (int i = 0; i < extra_sig_info_data.scalar_count; i++) 
    {
      type_info_interface *etype = type->get_info(i);
      void *element = type->element(reader_pointer, i);
      etype->fast_copy(&fqueue<long long int, vtime>::content(readers[i]->last_event_tr_item), element);
      etype->fast_copy(&fqueue<long long int, vtime>::content(readers[i]->last_value_tr_item), element);
    }
  
  // Create data structure to store the signal sources for this signal
  signal_source_map [this].init(type);
  
  kernel.add_signal (this);
  
  // Register signal
  if (do_Xinfo_registration)
    register_signal (this, sln, n, sr);
}


sig_info_base::sig_info_base(name_stack &iname, const char *n, const char *sln, type_info_interface *ty, 
			     char sty, void *sr)
{
  // Setup connection to the kernel data base and create a new entry
  // associated with the current sig info pointer.
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  sig_info_extensions &extra_sig_info_data = sig_info_ext.get (this);

  // Put signal name on top of name stack
  iname.set(n);

  extra_sig_info_data.kernel_flags = 0;
  extra_sig_info_data.instance_name = iname.get_name();
  if (signal_name_table.find(extra_sig_info_data.instance_name) != signal_name_table.end())
    error((string("Dublicate instance name '") + extra_sig_info_data.instance_name + string("'")).c_str());
  signal_name_table [extra_sig_info_data.instance_name] = this; // Store sig_info_base pointer into global hash table
  extra_sig_info_data.name = iname.get_top();
  type = ty;
  extra_sig_info_data.sig_type = sty;
  extra_sig_info_data.kind = vPLAIN;
  extra_sig_info_data.mode = 0;
  reader_pointer = type->create();

  extra_sig_info_data.scalar_count = type->element_count(); // Get number of scalar objects
  readers = new reader_info* [extra_sig_info_data.scalar_count];
  for (int i = 0; i < extra_sig_info_data.scalar_count; i++)
    readers [i] = new reader_info (type->element(reader_pointer,i), type->get_info(i));

  // Create data structure to store the signal sources for this signal
  signal_source_map [this].init (type);

  kernel.add_signal (this);

  // Register signal
  if (do_Xinfo_registration)
    register_signal (this, sln, n, sr);
}


sig_info_base::sig_info_base(name_stack &iname, const char *n, const char *sln, type_info_interface *ty, 
			     char attr, sig_info_base *base_sig, acl *aclp, vtime delay, void *sr) 
{
  // Setup connection to the kernel data base and create a new entry
  // associated with the current sig info pointer.
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  sig_info_extensions &extra_sig_info_data = sig_info_ext.get (this);

  // Put signal name on top of name stack
  iname.set(n);

  extra_sig_info_data.sig_type = vREGISTER;
  extra_sig_info_data.kind = attr;
  extra_sig_info_data.kernel_flags = 0;
  extra_sig_info_data.mode = 0;
  // Sorry, not supported yet

  // Create data structure to store the signal sources for this signal
  
  signal_source_map [this].init(type);
  kernel.add_signal (this);

  // Register signal
  if (do_Xinfo_registration)
    register_signal(this, sln, n, sr);
}


sig_info_base::sig_info_base(name_stack &iname, const char *n, const char *sln, type_info_interface *ty, 
			     sig_info_base *aliased_sig, acl *aclp, void *sr) 
{
  // Setup connection to the kernel data base and create a new entry
  // associated with the current sig info pointer and the aliased sig
  // info pointer.
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  sig_info_extensions &extra_sig_info_data = sig_info_ext.get (this);
  sig_info_extensions &aliased_extra_sig_info_data = sig_info_ext.get (aliased_sig);

  // Put signal name on top of name stack
  iname.set(n);

  extra_sig_info_data.kernel_flags = 0;
  extra_sig_info_data.instance_name = iname.get_name();
  if (signal_name_table.find(extra_sig_info_data.instance_name) != signal_name_table.end())
    error((string("Dublicate instance name '") + extra_sig_info_data.instance_name + string("'")).c_str());
  signal_name_table [extra_sig_info_data.instance_name] = this; // Store sig_info_base pointer into global hash table
  extra_sig_info_data.name = iname.get_top();
  type = ty;
  extra_sig_info_data.mode = aliased_extra_sig_info_data.mode;
  extra_sig_info_data.sig_type = vREGISTER;
  extra_sig_info_data.kind = vALIAS;

  extra_sig_info_data.scalar_count = type->element_count(); // Get number of scalar elements of the current formal
  
  if (type->id == ARRAY)
    {
      // Create a new array instance with its info and data pointer
      // set to NULL
      array_base *new_array = (array_base*)type->create();
      new_array->set_info((array_info*)type); // Set info instance of array
      
      // First, determine the last acl level value. Note that an acl
      // "level" is either an single number or a range desciptor (in
      // case of an array slice).
      acl *last_aclp = get_level(aclp, count_levels(aclp));
      if (last_aclp->end() ||
	  last_aclp->get() != ACL_RANGE)
	// If the last level is not an slice, then an entire array is
	// mapped. Hence, get the array and extract the data pointer
	// from this array.
	new_array->data = ((array_base*)aliased_sig->type->element(aliased_sig->reader_pointer, aclp))->data;
      else
	// A slice of an array is mapped. Hence, get the pointer to
	// the very first left element that is mapped. Note that
	// method "element" returns the address of the left element in
	// case of the acl (second parameter) is a range.
	new_array->data = (char*)aliased_sig->type->element(aliased_sig->reader_pointer, aclp);
	  
      reader_pointer = (void*)new_array;
    }
  else
    // If the type of the alias signal is scalar or an record, then
    // directly extract the reader pointer from the aliased signal.
    reader_pointer = aliased_sig->type->element(aliased_sig->reader_pointer, aclp);

  // Get reader_info pointers
  readers = new reader_info* [extra_sig_info_data.scalar_count];
  int start = 0, end;
  aliased_sig->type->acl_to_index (aclp, start, end);
  for (int i = 0, j = start; i < extra_sig_info_data.scalar_count; i++, j++)
    readers [i] = aliased_sig->readers [j];

  kernel.add_signal (this);
  
  // Register signal
  if (do_Xinfo_registration)
    register_signal (this, sln, n, sr);
}


void
sig_info_base::cleanup ()
{
  // Setup connection to the kernel data base and read entry
  // associated with the current sig info pointer.
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  sig_info_extensions &extra_sig_info_data = sig_info_ext.get (this);

  if (readers != NULL) delete[] readers;
  // Note that currently only reader_pointer of alias signals are
  // cleaned.
  if (extra_sig_info_data.kind == vALIAS)
    {
      if (type->id == ARRAY)
	{
	  array_base *array = (array_base*)reader_pointer;
	  // Set data part of array to NULL so that it is not
	  // removed. Note that the data part actually belongs to
	  // another signal.
	  array->data = NULL;
	  type->remove (array);
	}

      reader_pointer = NULL;
    }
}

void
sig_info_base::init_reader(const void *src)
{
  // Setup connection to the kernel data base and read entry
  // associated with the current sig info pointer.
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);
  sig_info_extensions &extra_sig_info_data = sig_info_ext.get (this);

  // Set reader value of signal
  type->copy(reader_pointer, src);
  
  // Set value of event and last_ value transaction
  for (int i = 0; i < extra_sig_info_data.scalar_count; i++) {
    type_info_interface *etype = type->get_info(i);
    void *element = type->element((void*)src, i);
    etype->fast_copy(&fqueue<long long int, vtime>::content(readers[i]->last_event_tr_item), element);
    etype->fast_copy(&fqueue<long long int, vtime>::content(readers[i]->last_value_tr_item), element);
  }
}



