#define KERNEL // Include internal kernel definitions

#include <freehdl/kernel-error.hh>
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-register.hh>
#include <list>

// List of descriptors. Note that this global variable must be defined
// *here* (in this file) because it is (indirectly) used by the
// initialization function of the standard VHDL data types (defined
// below). As this initialization function is called *before* main
// starts the definition location of Xinfo_descriptors *does* matter!
list<Xinfo_data_descriptor*> *Xinfo_descriptors_p = NULL;

// Procedure to initlialize list Xinfo_descriptors.
void Xinfo_data_descriptor_init ()
{
  Xinfo_descriptors_p = new list<Xinfo_data_descriptor*>;
}


// Flag to control whether registration shall be done or not
bool do_Xinfo_registration = true;


// Get the registry entry corresponding to the object address
// addr. Returns NULL is there is no such entry for this address.
Xinfo_data_descriptor *
get_registry_entry(void *addr, list<Xinfo_data_descriptor*> &desc)
{
  if (addr == NULL)
    return NULL;

  db_generic_explorer<db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  return *Xinfo_explorer.find (addr);
}

// Same as get_registry_entry, however, only
// Xinfo_scope_descriptors are considered.
Xinfo_data_descriptor *
get_scope_registry_entry(void *addr, list<Xinfo_data_descriptor*> &desc)
{
  if (addr == NULL)
    return NULL;

  db_generic_explorer<db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  Xinfo_data_descriptor **x = Xinfo_explorer.find (addr);
  if(!x) return NULL;
  Xinfo_data_descriptor *p = *x;

  return p->is_Xinfo_scope_descriptor() ? p : NULL;
}

// Same as get_registry_entry, however, only
// Xinfo_type_info_interface_descriptors are considered.
Xinfo_type_info_interface_descriptor *
get_type_registry_entry(type_info_interface *type, list<Xinfo_data_descriptor*> &desc)
{
  db_generic_explorer<db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  Xinfo_data_descriptor *p = *Xinfo_explorer.find ((void*)type);
  return p->is_Xinfo_type_info_descriptor() ? (Xinfo_type_info_interface_descriptor*)p : NULL;
}


// Determine instance long name
string
get_instance_long_name(Xinfo_data_descriptor *desc, list<Xinfo_data_descriptor*> &xinfo_desc)
{
  if (desc == NULL)
    return "";

  // First, get instance name of scope region
  Xinfo_data_descriptor *scope = get_scope_registry_entry(desc->scope_reference, xinfo_desc);
  string name;
  if (desc->is_Xinfo_scope_descriptor()) {
    Xinfo_scope_descriptor *scope_desc = (Xinfo_scope_descriptor*)desc;
    name += scope_desc->instance_short_name;
  } else
    name += desc->name;
  
  if (scope == NULL &&
      !desc->is_Xinfo_scope_descriptor())
    return string(desc->scope_long_name) + name;
  else
    return get_instance_long_name(scope, xinfo_desc) + name; 
}


define_db_key_type(void *,entity_architecture_p);

/* Register entity/architecture pair */
void *
register_entity_architecture(void *mor, const char *slname, const char *name, const char *isname, void *sr)
{
  // Create a new descriptor for the entity/architecture pair
  db_explorer<db_key_type::entity_architecture_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  Xinfo_explorer.get (mor) = 
    new Xinfo_scope_descriptor(mor, Xinfo_kind(Xinfo_kind::ID_ENTITY_ARCHITECTURE), slname, name, isname, sr);

  return Xinfo_explorer.get (mor)->object_reference;
}

/* Register process */
process_base *
register_process(process_base *mor, const char *slname, const char *name, void *sr)
{
  // Create a new descriptor for the process. Note that "name" and
  // "instance_short_name" are equal!
  db_explorer<db_key_type::process_base_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  Xinfo_explorer.get (mor) = 
    new Xinfo_scope_descriptor(mor, Xinfo_kind(Xinfo_kind::ID_PROCESS), slname, name, name, sr);
  
  return mor;
}


define_db_key_type(void *,package_p); 

/* Register package */
void *
register_package(const char *slname, const char *name)
{
  // Create a new descriptor for the process. Note that "name" and
  // "instance_short_name" are equal! Futher, as a pacakge actually is
  // nor represented by an object the "object_reference" is created
  // via an unique memory address.
  db_explorer<db_key_type::package_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  void *addr = malloc (1);
  Xinfo_explorer.get (addr) = 
    new Xinfo_scope_descriptor(addr, Xinfo_kind(Xinfo_kind::ID_PACKAGE), slname, name, name, NULL);

  return Xinfo_explorer.get (addr)->object_reference;
}


define_db_key_type(void *,package_body_p); 

/* Register package body */
void *
register_package_body(const char *slname, const char *name)
{
  // Create a new descriptor for the process. Note that "name" and
  // "instance_short_name" are equal! Futher, as a pacakge actually is
  // nor represented by an object the "object_reference" is created
  // via an unique memory address.
  db_explorer<db_key_type::package_body_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  void *addr = malloc (1);
  Xinfo_explorer.get (addr) = 
    new Xinfo_scope_descriptor(addr, Xinfo_kind(Xinfo_kind::ID_PACKAGE_BODY), slname, name, name, NULL);

  return Xinfo_explorer.get (addr)->object_reference;
}



/* Register signal */
void *
register_signal(sig_info_base *sig, const char *slname, const char *n, void *sr)
{
  db_explorer<db_key_type::sig_info_base_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  // Create a descriptor for the signal
  Xinfo_explorer.get (sig) = new Xinfo_signal_descriptor(sig, slname, n, sr);

  return Xinfo_explorer.get (sig)->object_reference;
}



define_db_key_type(void *,constant_p); 

/* Register constant */
void *
register_constant(void *caddr, const char *slname, const char *name, type_info_interface *type, void *sr)
{
  db_explorer<db_key_type::constant_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  // Create a descriptor a constant
  Xinfo_explorer.get (caddr) =
    new Xinfo_plain_object_descriptor(caddr, Xinfo_kind::ID_CONSTANT, slname, name, type, sr);

  return Xinfo_explorer.get (caddr)->object_reference;
}


define_db_key_type(void *,variable_p); 

/* Register variable */
void *
register_variable(void *caddr, const char *slname, const char *name, type_info_interface *type, void *sr)
{
  db_explorer<db_key_type::variable_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  // Create a descriptor a variable
  Xinfo_explorer.get (caddr) =
    new Xinfo_plain_object_descriptor(caddr, Xinfo_kind::ID_VARIABLE, slname, name, type, sr);

  return Xinfo_explorer.get (caddr)->object_reference;
}


define_db_key_type(void *,generic_p); 

/* Register generic */
void *
register_generic(void *gaddr, const char *slname, const char *name, type_info_interface *type, void *sr)
{
  db_explorer<db_key_type::generic_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  // Create a descriptor a generic parameter
  Xinfo_explorer.get (gaddr) =
    new Xinfo_plain_object_descriptor(gaddr, Xinfo_kind::ID_GENERIC, slname, name, type, sr);

  return Xinfo_explorer.get (gaddr)->object_reference;
}


define_db_key_type(void *,source_file_p);

/* Register source file name */
void *
register_source_file(const char *fpname, const char *name)
{
  // First, check out whether the source file already has been
  // registered. Do NOT register is again!
  db_explorer<db_key_type::source_file_p, db_entry_type::Xinfo_data_descriptor_p> source_file_name_explorer (kernel_db);
  for (db::key_iterator iter = kernel_db.begin (); iter != kernel_db.end (); iter++)
    {
      // First check whether iter refers actually to a source file
      // name entry in the database. If not, continue.
      if (!source_file_name_explorer.is_valid (*iter)) continue;
      Xinfo_data_descriptor *desc = source_file_name_explorer.get (*iter);
      if (!strcmp(desc->source_path_name, fpname))
	return (void*)NULL;
    }

  // Ok, the file has not been registered. Hence, create a descriptor
  // for the source file. Note that a unique memory address is
  // allocated as a key for this database entry.
  void *addr = malloc (1);
  source_file_name_explorer.get (addr) = 
    new Xinfo_data_descriptor(NULL, Xinfo_kind(Xinfo_kind::ID_SOURCE_FILE), fpname,  name, NULL);
  
  return (void*)NULL;
}


/* Register type */
void *
register_type(void *taddr, const char *slname, const char *lname, const char *name, void *sr)
{
  db_explorer<db_key_type::type_info_interface_p, db_entry_type::Xinfo_data_descriptor_p> Xinfo_explorer (kernel_db);
  // Create a descriptor 
  Xinfo_explorer.get ((type_info_interface*)taddr) =
    new Xinfo_type_info_interface_descriptor(taddr, slname, lname, name, sr);

  return Xinfo_explorer.get ((type_info_interface*)taddr)->object_reference;
}


/* Add resolver to type */
void
add_resolver(type_info_interface *info, resolver_handler_p handler, type_info_interface *ainfo, bool ideal)
{
  // Create a new resolver descriptor entry and store it into table.
  resolver_descriptor descriptor(handler, ainfo, ideal);
  db_explorer<db_key_type::type_info_interface_p, db_entry_type::resolver_map>  resolver_map (kernel_db);
  resolver_map.get (info) = descriptor;
}

/* Register initialization function 
*/

typedef int (*init_function_pointer) ();

define_db_key_type(init_function_pointer, init_function_key);
define_db_entry_type(bool, init_function_info);

int
register_init_func (int (*func)())
{
  // Setup connection to the kernel data base and create a new entry
  // associated with the current sig info pointer.
  db_explorer<db_key_type::init_function_key, db_entry_type::init_function_info>  init_function_executed (kernel_db);
  init_function_executed.get (func) = false;
}

void
run_init_funcs ()
{
  // Setup connection to the kernel data base and create a new entry
  // associated with the current sig info pointer.
  db_explorer<db_key_type::init_function_key, db_entry_type::init_function_info>  init_function_executed (kernel_db);

  for (db::key_iterator iter = kernel_db.begin (); iter != kernel_db.end (); iter++)
    {
      // Continue if iter does not reference init funcion key.
      if (!init_function_executed.is_valid (*iter)) continue;
      (* init_function_executed.get_key (*iter)) ();
      init_function_executed.get (*iter) = true;
    }
}
