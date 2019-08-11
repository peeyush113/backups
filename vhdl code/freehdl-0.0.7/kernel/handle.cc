#define KERNEL

#include <freehdl/kernel-flags.hh>
#include <freehdl/kernel-handle.hh>
#include <freehdl/kernel-handle-info.hh>
#include <freehdl/kernel-fhdl-stream.hh>


handle_info::handle_info(const char *lib, const char *prim, const char *arch, handle func, init_handle ifunc) :
  library(lib == NULL? "" : lib), primary(prim == NULL? "" : prim), architecture(arch == NULL? "" : arch), 
  function (func), init_function (ifunc)
{
  init_done = false;
  scope_long_name = string (":") + lib + string (":") + prim;
}


handle_info::handle_info(const handle_info &h) : 
  library (h.library), primary (h.primary), architecture (h.architecture),
  function (h.function), init_function (h.init_function),
  init_done (h.init_done), scope_long_name (h.scope_long_name)
{
}


handle_info::handle_info() : 
  library (""), primary (""), architecture (""), function (NULL),
  init_function (NULL),  init_done (false), scope_long_name ("")
{
}


handle_info *
add_handle(const char *library, const char *primary, const char *architecture, const handle func, const init_handle ifunc) 
{
  // Setup connection to the kernel data base
  db_explorer<db_key_type::handle_identifier, db_entry_type::handle_info> handle_entries (kernel_db);
  // Insert new handle entry into database
  handle_identifier *ident = new handle_identifier;
  handle_entries.get (ident) = handle_info(library, primary, architecture, func, ifunc);
  
  REPORT(kernel_output_stream << "Component " << library << ":" << primary << ":" << architecture <<
	 " added to component list." << endl;);

  return &handle_entries.get (ident);
}


// Returns handle function pointer to the design unit, which matches
// 'library', 'primary', and 'architecture'. An empty string "" is
// treated as wildcard.
handle_info *
get_handle(const char *library, const char *primary, const char *architecture)
{
  // Setup connection to the kernel data base
  db_explorer<db_key_type::handle_identifier, db_entry_type::handle_info> handle_entries (kernel_db);
  
  for (db::key_iterator iter = kernel_db.begin (); iter != kernel_db.end (); iter++)
    {
      // First check whether iter refers actually to a process_base
      // entry in the database. If not, continue.
      if (!handle_entries.is_valid (*iter)) continue;
      if (handle_entries.get (handle_entries.get_key (*iter)).match (library, primary, architecture))
	return &handle_entries.get (handle_entries.get_key (*iter));
    }

  return (handle_info*)NULL;
}
