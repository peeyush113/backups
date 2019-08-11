#ifndef FREEHDL_KERNEL_HANDLE_INFO_H
#define FREEHDL_KERNEL_HANDLE_INFO_H

#include <string>
#include <freehdl/kernel-handle.hh>
#include <freehdl/kernel-list.hh>

// For each data architecture a handle_info object is instantiated.
// It is used during elaboration to call the constructors of the 
// corresponding architecture class. Note, the architecture classes
// are unkown to the kernel at kernel compile time
struct handle_info {  
  string library; // Library the component belongs to
  string primary; // Entity or package name of the design unit
  string architecture; // Architecture name of the component
  // declared within.
  // Pointer to the handle function which instantiates the corresponding
  // architecture
  handle function;
  // A function that is used to initialize some global structures.
  init_handle init_function;
  // init_done is set to true, if the initialization function has been
  // already called. Note that the initialization function has to be
  // calles only once BEFORE the constructor of the coressponding
  // component is executed the first time.
  bool init_done;
  string scope_long_name; // Long name of the region the design is
  handle_info(const char *lib, const  char *prim, const char *arch, 
	      const handle func, const init_handle);
  handle_info(const handle_info &h);
  handle_info();
  bool match(const char *lib, const char *prim, const char *arch) {
    return (lib == NULL || lib[0] == '\0' || !strcmp(lib, library.c_str ())) &&
      (prim == NULL || prim[0] == '\0' || !strcmp(prim, primary.c_str ())) &&
      (arch == NULL || arch[0] == '\0' || !strcmp(arch, architecture.c_str ()));
  }
};


/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

#include <freehdl/kernel-db.hh>
 
struct handle_identifier { };

define_db_key_type (handle_identifier*, handle_identifier);
define_db_entry_type (handle_info, handle_info);

#endif
#endif
