#ifndef KERNEL_SOURCE_DESCRIPTOR_H
#define KERNEL_SOURCE_DESCRIPTOR_H

#ifdef KERNEL
/* ****************************************************************
 * These definitions are required by the kernel only
 * **************************************************************** */

#include <freehdl/kernel-db.hh>
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-resolver-descriptor.hh>

class resolver_descriptor;

// Decribes set of scalars which are resolved by a resolution
// function.
struct source_descriptor {
  // Index number of first scalar belonging to scalar set. size is the
  // number of scalars associated with the resolution function.
  int index_start, size;
  // Points to the corresponding resolver_descriptor.
  resolver_descriptor *resolver;
  source_descriptor() { index_start = size = 0; resolver = NULL; }
};


// Return source descriptor associated with type and index_start. Note
// that index_start is the index number of a scalar included in
// type. Note that index_start of the returned source_descriptor is
// the first scalar associated with a corresponding resolution
// function. Note further that the process of finding a resolved type
// is stopped as soon as a first resolution function is found (or type
// is scalar).
inline source_descriptor
get_source_descriptor(type_info_interface *type, const int index_start)
{
  source_descriptor result;
  int scalar_count = type->element_count();

  // First, determine whether type is resolved.
  db_explorer<db_key_type::type_info_interface_p, db_entry_type::resolver_map>  resolver_map (kernel_db);
  if (resolver_map.find (type) != NULL) {
    // If type is resolved then all scalars covered by type are
    // resolved by a reolution function.
    result.resolver = &resolver_map.get (type);
    result.index_start = 0;
    result.size = scalar_count;

    return result;
  }
  
  // If type is not resolved as a whole then some further type
  // analysis is necessary.
  switch (type->id) {
  case ARRAY:
    {
      // If type is an array then analyze the element type. 
      array_info &ainfo = *(array_info*)type;
      const int element_scalar_count = ainfo.element_type->element_count();
      // Determine index number of the corresponding element relative
      // to the element type of the array.
      const int remainder_index = index_start % element_scalar_count;
      result = get_source_descriptor(ainfo.element_type, remainder_index);
      result.index_start += index_start - remainder_index;
      
      return result;
    }
  
  case RECORD:
    {
      // If type is an record then search for the appropriate record
      // element that belongs to index_start.
      record_info &rinfo = *(record_info*)type;
      int remainder_index = index_start, i = 0, diff;
      while (remainder_index - (diff = rinfo.element_types[i++]->element_count()) >= 0)
	remainder_index -= diff;
      result = get_source_descriptor(rinfo.element_types[i - 1], remainder_index);
      result.index_start += index_start - remainder_index;
      
      return result;
    }
  
  default:
    // If type is scalar then there is no resolution function.
    assert(index_start == 0);
    result.index_start = 0;
    result.size = 1;
    
    return result;
  }
  
}



#endif
#endif
