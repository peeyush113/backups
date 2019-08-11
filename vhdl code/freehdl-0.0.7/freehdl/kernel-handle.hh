#ifndef FREEHDL_KERNEL_HANDLE_H
#define FREEHDL_KERNEL_HANDLE_H

#include <freehdl/kernel-name-stack.hh>
#include <freehdl/kernel-map-list.hh>


// For each architecture a separate handle functions to instantiate
// the architecture is declared.
typedef void* (*handle)(name_stack &, map_list *, void *, int);

// A function that is used to initialize some global structures.
typedef int (*init_handle) (void);

// Returns handle function pointer to the component which matches 'library',
// 'entity', and 'architecture'. An empty string "" is treated as wildcard.
struct handle_info;

// This function is used to collect all handle-functions which are 
// present in the current model. It is used to initialize some dummy
// variables. Hence it is executed BEFORE main() start.
handle_info *
add_handle(const char *library, const char *primary, const char *architecture, 
	   const handle func, const init_handle ifunc);

// Search for design unit handle (architecture/configuration/package
// body)
handle_info *
get_handle (const char *library, const char *primary, const char *architecture);

#endif
