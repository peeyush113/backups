#define KERNEL

#include <freehdl/kernel-driver-info.hh>
#include <freehdl/kernel-signal-source-list-array.hh>


// a map stores the sources for each signal. Note that each signal is
// associated with a vector of signal_source_list pointers (included
// in signal_source_list_array). 
signal_source_map_t signal_source_map;

// Initialize data structures. In detail source_list_array is
// allocated and filled. I.e., the necessary signal_source_list
// instaces are allocated and linked into the array.
void
signal_source_list_array::init(type_info_interface *type)
{
  const int scalar_count = type->element_count();
  source_list_array.resize(scalar_count);

  int i = 0;
  while (i < scalar_count) {
    // Create a signal_source_list item
    signal_source_list *source_list_p = new signal_source_list;
    // Get source descriptor that belongs to index number i. The
    // source descriptor stores the first index number which belongs
    // to the source, the number of scalars which are covered by the
    // source and a pointer to the resolver descriptor data structure
    // (is set to NULL if the signal is not resolved).
    source_descriptor source_desc = get_source_descriptor(type, i);
    source_list_p->index_start = source_desc.index_start;
    source_list_p->size = source_desc.size;
    source_list_p->resolver = source_desc.resolver;
    fill(source_list_array.begin() + source_desc.index_start, 
	 source_list_array.begin() + source_desc.index_start + source_desc.size,
	 source_list_p);
    i += source_desc.size;
  }
}



