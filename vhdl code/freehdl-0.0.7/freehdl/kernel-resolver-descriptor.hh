#ifndef KERNEL_RESOLVER_DESCRIPTOR_H
#define KERNEL_RESOLVER_DESCRIPTOR_H

#include <freehdl/kernel-driver-info.hh>
#include <freehdl/std-vhdl-types.hh>

/* *************************************************************
 *  Further definitions required for signal resolution
 * ************************************************************* */

// The following template function is used to generate a wrapper
// function for the actual user defined resolution function. This
// mechanism is necessary because the kernel does not know anything
// about user defines types. Hence, he cannot call the user defined
// reolution function directly. Instead, each time a resolved type is
// created an appropriate pointer to a "resolver handle" function is
// generated (which uses only simple parameter types and no return
// type; hence, it can be called by the kernel) and passed over to the
// kernel. The kernel uses this handler to execute the resolver
// function indirectly. T is the type to be resolved while F points to
// the user defined resolution function.
template<class T, T (*F)(const array_type<T >&, array_info&) >
void resolver_handler(void *result, driver_info *driver, array_base *array, array_info *unc_ainfo)
{
  *(T*)result = (*F)(*(array_type<T >*)array, *unc_ainfo);
  driver->transport_assign(*(T*)result, zero_time);
}

// Similar to the previous template but the actual resolution function
// takes only a single argument. Both templates are required as some
// resolution function will actually take one and some other two
// arguments (the second arguments is actually an internal parameter
// to the function which is not specified in the VHDL source).
template<class T, T (*F)(const array_type<T >&) >
void resolver_handler(void *result, driver_info *driver, array_base *array, array_info *unc_ainfo)
{
  *(T*)result = (*F)(*(array_type<T >*)array);
  driver->transport_assign(*(T*)result, zero_time);
}




#ifdef KERNEL
/* ****************************************************************
 * These definitions are required by the kernel only
 * **************************************************************** */

#include <map>
#include <freehdl/kernel-db.hh>

struct resolver_descriptor {
  // Points to the wrapper function used by the kernel to call the
  // resolver.
  resolver_handler_p handler;
  // Points to the array_info instance describing the driver array
  type_info_interface *ainfo;
  // States whether the resolver function must be called for a single
  // driver. When ideal = true then it must be used only if more than
  // one driver is present.
  bool ideal;
 
  resolver_descriptor() : handler(NULL), ainfo(NULL) {};
 
  resolver_descriptor(resolver_handler_p h, type_info_interface *a, bool id) :
    handler(h), ainfo(a), ideal(id) { 
    // Increase reference counter so that the type_info insstance is
    // not removed.
    if (a != NULL)
      a->add_ref(); 
  };
 
  resolver_descriptor(const resolver_descriptor &d) : 
    handler(d.handler), ainfo(d.ainfo), ideal(d.ideal) {
    // Increase reference counter so that the type_info insstance is
    // not removed.
    if (ainfo != NULL)
      ainfo->add_ref();
  }

  ~resolver_descriptor() {
    // Decrease reference counter to enable type_info removing (if not
    // used somewhere else)
    if (ainfo != NULL)
      ainfo->remove_ref();
  }
};


// Generate an entry type for the kernel database. The entries are
// associated with type_info_interface pointers.
define_db_entry_type (resolver_descriptor, resolver_map);


#endif
#endif
