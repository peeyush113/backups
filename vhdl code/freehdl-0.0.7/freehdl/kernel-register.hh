#ifndef FREEHDL_KERNEL_REGISTER_H
#define FREEHDL_KERNEL_REGISTER_H
#include <freehdl/kernel-db.hh>
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-name-stack.hh>
#include <freehdl/kernel-process-base.hh>
#include <freehdl/kernel-sig-info.hh>

/* *****************************************************************
 * This file contains types and functions needed to store additional
 * information about objects created by the generated code. E.g., some
 * additional information about type_info instances are maintained
 * using this function. As this additional information is rarely used
 * it is *not* directly stored into the corresponding type_info
 * classes.
 * **************************************************************** */

// Flag to control whether registration shall be done or not
extern bool do_Xinfo_registration;

#ifdef KERNEL
/* ****************************************************************
 * Some definitions required by the kernel only and not by the
 * generated code.
 * **************************************************************** */
#include <list>
#include <map>
#include <freehdl/kernel-Xinfo-data-descriptor.hh>
#include <freehdl/kernel-resolver-descriptor.hh>

// List of descriptors. HACK: The xinfo descriptors is actually
// accessed via a pointer. This hack is needed as the data structure
// is needed during program startup BEFORE main is
// callesd. Unfortunately, some compilers/linker fail do not
// initialize the data structure in time. Hence, we have to do it by
// ourself.
extern list<Xinfo_data_descriptor*> *Xinfo_descriptors_p;
#define Xinfo_descriptors (*Xinfo_descriptors_p) 

// Procedure to initlialize the Xinfo_descriptors list.
void Xinfo_data_descriptor_init ();

// Get the registry entry corresponding to the object address
// addr. Returns NULL is there is no such entry for this address.
Xinfo_data_descriptor 
*get_registry_entry(void *addr, list<Xinfo_data_descriptor*> &desc);

// Same as get_registry_entry, however, only
// Xinfo_type_info_interface_descriptors are considered.
Xinfo_type_info_interface_descriptor 
*get_type_registry_entry(type_info_interface *type, list<Xinfo_data_descriptor*> &desc);

// Determine instance long name
string
get_instance_long_name(Xinfo_data_descriptor *desc, list<Xinfo_data_descriptor*> &xinfo_desc);

#endif


/* Add resolver to type */
void
add_resolver(type_info_interface *info, resolver_handler_p handler, type_info_interface *ainfo, bool ideal);

/* Register type */
void *
register_type(void *taddr, const char *slname, const char *lname, const char *name, void *sr);

/* Register an entity/architecture instance */
void *
register_entity_architecture(void *mor, const char *slname, const char *name, const char *isname, void *sr);

/* Register a process instance */
process_base *
register_process(process_base *mor, const char *slname, const char *name, void *sr);

/* Register a package */
void *
register_package(const char *slname, const char *name);

/* Register a package body */
void *
register_package_body(const char *slname, const char *name);

/* Register signal */
void *
register_signal(sig_info_base *sig, const char *slname, const char *n, void *sr);

/* Register constant */
void *
register_constant(void *caddr, const char *slname, const char *name, type_info_interface *type, void *sr);

/* Register variable */
void *
register_variable(void *vaddr, const char *slname, const char *name, type_info_interface *type, void *sr);

/* Register generic */
void *
register_generic(void *gaddr, const char *slname, const char *name, type_info_interface *type, void *sr);

/* Register source file name */
void *
register_source_file(const char *fpname, const char *name);

/* Register a initialization function 
 */
int register_init_func (int (*init) ());

/* Run them.
 */
void run_init_funcs ();

#endif
