#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <freehdl/vaul.h>
#include "v2cc-chunk.h"
#include "mapping.h"
#include "v2cc-util.h"


void test (RegionStack &rstack)
{
  cout << "----------------------" << endl;
  for (pIIR_DeclarationList l = extended_declarations (RootDeclarativeRegion (rstack)); l; l = l->rest)
    {
      cout << l->first->declarator->text.to_chars() << endl;
    }
  cout << "----------------------" << endl;
}

// used to generate error messages
extern vaul_error_printer codegen_error;


/* Emit global declaration code of the current context stack */
void
emit_global_internal_object_declarations(pIIR_DeclarativeRegion region, string &str, RegionStack &rstack)
{
  // *******************************************************************
  // Emit global prototypes
  // *******************************************************************
  for (pIIR_DeclarationList decls = extended_declarations(region);
       decls; decls = decls->rest)
    if (decls->first->is(V2CC_INTERNAL_CODE)) {
      pV2CC_InternalCode ic = pV2CC_InternalCode(decls->first);
      if (ic->flags & DECLARE_GLOBALLY)
	str += ic->cpp_header_string;
    }
}


/* Define all global internal objects */
void
emit_global_internal_object_definitions(pIIR_DeclarativeRegion region, string &str, RegionStack &rstack)
{
  // *******************************************************************
  // declare all internal global objects
  // *******************************************************************
  for (pIIR_DeclarationList decls = extended_declarations(region);
       decls; decls = decls->rest) {

    if (decls->first->is(V2CC_INTERNAL_CODE)) {
      // *******************************************************************
      // Internal code object
      // *******************************************************************
      pV2CC_InternalCode ic = pV2CC_InternalCode(decls->first);
      if (ic->flags & DECLARE_GLOBALLY)
	str += ic->cpp_impl_string;

    } else if (((decls->first->is(IR_OBJECT_DECLARATION) && 
		pIIR_ObjectDeclaration(decls->first)->alias_base != NULL) ||
	       decls->first->is(IR_CONSTANT_DECLARATION)) ||
	       decls->first->is(V2CC_INTERNAL_OBJECT_DECLARATION)) {
      // **************************************************************************
      // constant or type declaration
      // **************************************************************************
      vector<string> get_decl (pIIR_Declaration decl, RegionStack &rstack);
      vector<string> result = get_decl (decls->first, rstack);
      string &type_str = result[0];
      string &obj_str = result[1];
      string &init_str = result[2];
      str += type_str + " " + obj_str + init_str + ";\n";
    }
  }
}


/* Define all global internal objects */
void
emit_global_internal_object_init(pIIR_DeclarativeRegion region, string &str, RegionStack &rstack)
{
  // Create a temporary region stack which contains the root region
  // only. Note that this stack is removed automatically on function
  // return.
  RegionStack root_tmp_stack;
  root_tmp_stack.push(RootDeclarativeRegion(rstack));

  // *******************************************************************
  // analyze all internal global objects
  // *******************************************************************
  for (pIIR_DeclarationList decls = extended_declarations(region);
       decls; decls = decls->rest) {

    if (decls->first->is(V2CC_INTERNAL_OBJECT_DECLARATION)) {
      // *******************************************************************
      // Internal object declaration
      // *******************************************************************
      pV2CC_InternalObjectDeclaration obj = pV2CC_InternalObjectDeclaration(decls->first);
      if (obj->flags & DECLARE_GLOBALLY) {
	string type_str = get_internal_object_type_string(obj, rstack);
	if (!(obj->flags & DECLARE_AND_INIT)) {
	  string initial_str = get_internal_object_initial_string(obj, rstack);
	  if (initial_str != "") 
	    str += obj->declarator->text.to_chars() + initial_str + ";\n";
	}
      }

    } else if ((decls->first->is(IR_OBJECT_DECLARATION) && 
		pIIR_ObjectDeclaration(decls->first)->alias_base != NULL)
	       || decls->first->is(IR_CONSTANT_DECLARATION)) {
      void emit_decls_init_item (pIIR_DeclarationList dl, string &str, RegionStack &rstack, int l);
      emit_decls_init_item (decls, str, root_tmp_stack, 0);

    } else if ((decls->first->is(IR_TYPE_DECLARATION))) {
      void emit_decls_init_item (pIIR_DeclarationList dl, string &str, RegionStack &rstack, int l);
      emit_decls_init_item (decls, str, root_tmp_stack, 0);
    }
  }
}


/* Refer to a type. If it has a name, use that. Otherwise be more
   verbose.
*/
void
emit_type_name (pIIR_Type t, string &str, RegionStack &rstack, int l = 0)
{
  emit_id (t->declaration, str, rstack);
}



string
get_design_file_name(string &library, string &unit)
{
  char *fn = vaul.mapper->find_design_file(library.c_str(), unit.c_str());
  
  if (fn == NULL) {
    fprintf(stderr, "Internal error in file %s at line %i: could not find unit '%s' in library '%s'.\n",
	    __FILE__, __LINE__, unit.c_str(), library.c_str());
    exit(1);
  }
    
  string result = fn;
  delete fn;

  return result;
}


// Emit declaration of external definitions used within the current
// desing(s)
void
emit_external_decls (decl_flag_list &ext_decls_list,
		     pIIR_Declaration ref_decl,
		     string &str, RegionStack &rstack, int l)
{
  str += "/* External declarations */\n";

  /* Get source file name of declaration */
  string ref_fn = string (get_source_file_name (ref_decl));

  string obj_decls;
  pIIR_DeclarationList odl = new IIR_DeclarationList(NULL, NULL, NULL);
  tree_protect(odl); // odl shall not be removed by the garbage collector
    
  for (decl_flag_list::iterator iter = ext_decls_list.begin();
       iter != ext_decls_list.end(); iter++)
    {
      pIIR_Declaration decl = pIIR_Declaration((*iter).first);

      // If the bool value is set to true then the declaration has been
      // already emitted, i.e. there is nothing left to do.
      if ((*iter).second)
	continue;

      // Continue if the current declaration is predefined in
      // library std but not std.textio.
      vector<string> libunit = get_library_and_unit_name (decl);
      if (libunit[0] == "std" && libunit[1] != "textio")
	continue;

      // Compare file name of declaration with reference design. Do not
      // emit declaration if file names are equal.
      if (string (get_source_file_name (decl)) == ref_fn)
	continue;

      // If declaration is an object declaration then we use function
      // "emit_decl" to create the corresponding declarations. Note that
      // the keyword "extern" must be prepended in this case.
      if (decl->is(IR_OBJECT_DECLARATION)) 
	{
	  odl->first = decl;
	  emit_decls (odl, obj_decls = "", rstack, l);
	  // Prepend "extern".
	  if (obj_decls.size() > 0)
	    str += "extern " + obj_decls;
	}
      else
	{
	  // Otherwise, just emit header code.
	  emit_hdr (decl, str, rstack, l);
	}

      (*iter).second = true; // Mark entry, i.e. the declaration must
                             // not be emitted again.
    }
  
  str += "/* End of external declarations */\n";
  odl->first = NULL;

  tree_unprotect(odl); // ok, odl can now be removed by the garbage
                       // collector
}

static string
make_absolute (string fn)
{
  if (fn.size() == 0 || fn[0] == '/')
    {
#ifdef _WIN32
      for (int i = 0; i < fn.size(); i++) if (fn[i] == '\\') fn[i] ='/';
#endif
      return fn;
    }
  else
    {
      const int buffer_size = 4096;
      char *buffer = (char*)malloc (sizeof (char) * buffer_size);
      assert (getcwd (buffer, buffer_size) != NULL);
#ifdef _WIN32
      for (int i = 0; buffer[i] && i < buffer_size; i++)
	if (buffer[i] == '\\') buffer[i] ='/';
#endif
      fn = string (buffer) + "/" + fn;
      free (buffer);
      return fn;
    }
}

void
emit_source_file_register_code(pIIR_DeclarativeRegion r, string &str, RegionStack &rstack, int l)
{
  string ref_fn = string (get_source_file_name (r));
  str += spaces(l) + "register_source_file(\"" + make_absolute (ref_fn) + "\",\"" + ref_fn + "\");\n";
}


vector<string>
get_decl (pIIR_Declaration decl, RegionStack &rstack)
{
  vector<string> result;
  string type_str = "";
  string obj_str = "";
  string init_str = "";

  // Now, generate code depending on the object type
  if (decl->is(IR_OBJECT_DECLARATION) && 
      pIIR_ObjectDeclaration(decl)->alias_base != NULL) {
    // **************************************************************************
    // Alias declaration
    // **************************************************************************
    pIIR_ObjectDeclaration alias_decl = pIIR_ObjectDeclaration(decl);
    // Determine aliased object
    pIIR_ObjectDeclaration aliased_object = get_object_declaration(alias_decl->alias_base);
    
    if (aliased_object->is(IR_CONSTANT_DECLARATION) ||
	aliased_object->is(IR_VARIABLE_DECLARATION) ||
	aliased_object->is(IR_CONSTANT_INTERFACE_DECLARATION) ||
	aliased_object->is(IR_VARIABLE_INTERFACE_DECLARATION)) {
      // Aliased object is a variable or a constant.
      if (is_array_type(alias_decl->subtype)) {
	// Array alias objects are implemented as a special array type
	// array_alias object
	type_str = "array_alias<" + qid(get_declaration(pIIR_ObjectDeclaration(decl)->subtype), rstack, TYPE) + " >";
	obj_str = qid(decl, rstack, id_type());
      } else {
	// The other alias objects are implemented via pointers
	type_str = qid (get_declaration(pIIR_ObjectDeclaration (decl)->subtype), rstack, TYPE);
	obj_str = "*" + qid (decl, rstack, id_type());
      }
      
    } else if (aliased_object->is (IR_SIGNAL_DECLARATION) ||
	       aliased_object->is (IR_SIGNAL_INTERFACE_DECLARATION)) {
      // Aliased object is a signal
      type_str = "sig_info<" + qid (get_declaration(pIIR_ObjectDeclaration(decl)->subtype), rstack, TYPE) + ">";
      obj_str = "*" + qid (decl, rstack, id_type());

    } else {
      codegen_error.error("%:error: sorry, this alias declaration is currently not supported", decl);
      exit(1);
    }
    
  } else if (decl->is(V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR)) {
    // **************************************************************************
    // an implicit signal to implement wait statements with time out 
    // clauses shall be created
    // **************************************************************************
    pV2CC_ImplicitSignalDeclaration_WaitFor obj = pV2CC_ImplicitSignalDeclaration_WaitFor(decl);
    
    type_str = "sig_info<enumeration>";
    obj_str = "*" + qid(obj, rstack, id_type());
    
  } else if (decl->is(IR_SIGNAL_DECLARATION) ||
	     decl->is(IR_SIGNAL_INTERFACE_DECLARATION)) { 
    // **************************************************************************
    // signal declaration
    // **************************************************************************
    pIIR_SignalDeclaration sig = pIIR_SignalDeclaration(decl);
    type_str = "sig_info<" + qid(get_declaration(sig->subtype), rstack, TYPE) + ">";
    obj_str = "*" + qid(sig, rstack, id_type());
    
  } else if (decl->is(IR_CONSTANT_DECLARATION) ||
	     decl->is(IR_CONSTANT_INTERFACE_DECLARATION) ||
	     decl->is(IR_VARIABLE_DECLARATION)) {
    // **************************************************************************
    // constant or variable declaration
    // **************************************************************************
    type_str = qid(get_declaration(pIIR_ObjectDeclaration(decl)->subtype), rstack, TYPE);
    obj_str = qid(decl, rstack, id_type());
    
  } else if (decl->is(IR_FILE_DECLARATION)) {
    // **************************************************************************
    // File declaration
    // **************************************************************************
    type_str = qid(get_declaration(pIIR_ObjectDeclaration(decl)->subtype), rstack, TYPE);
    obj_str = qid(decl, rstack, id_type());
    
  } else if (decl->is(V2CC_INTERNAL_OBJECT_DECLARATION)) {
    // **************************************************************************
    // an internal object required by the generated code
    // **************************************************************************
    pV2CC_InternalObjectDeclaration obj = pV2CC_InternalObjectDeclaration(decl);
    
    type_str = get_internal_object_type_string(obj, rstack);
    obj_str = obj->declarator->text.to_chars();
    // If the internal object shall be declared and initialized at
    // the same time, then get the initial value.
    if (obj->flags & DECLARE_AND_INIT)
      init_str = get_internal_object_initial_string(obj, rstack);
    
  } else if (decl->is(IR_TYPE_DECLARATION)) {
    // **************************************************************************
    // A new type has been declared
    // **************************************************************************
    return result;
    
  } else
    // otherwise, skip item
    return result;
  
  result.resize(3);
  result[0] = type_str;
  result[1] = obj_str;
  result[2] = init_str;

  return result;
}


void
emit_decls (pIIR_DeclarationList decl_list, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration type = NULL;
  string type_str = "";
  string old_type_str = "";
  string obj_str = "";

  // Analyze each item on the declaration list
  for (pIIR_DeclarationList dl = decl_list; dl; dl = dl->rest) {
    pIIR_Declaration decl = (pIIR_Declaration)dl->first;

    vector<string> result = get_decl(decl, rstack);
    if (result.size() == 0) continue;
    type_str = result[0];
    obj_str = result[1];
    
    // several items of the same type will be declared in a single
    // declaration statement
    if (type_str != old_type_str) {
      if (old_type_str != "")
	str += ";\n";
      str += spaces(l) + type_str + " " + obj_str;
      old_type_str = type_str;
    } else 
      str += "," + obj_str;
  }

  if (type_str != "")
    str += ";\n";
}


/*
 * emit IIR Declarations
 */

void
m_emit_decl (pIIR_Declaration d, string &str, RegionStack &rstack, int l)
{
  // catch-all for ignored declarations.
  str += spaces(l) + string("/* ") + d->kind_name();
  emit_id (d, str, rstack);
  str += " */\n";
}

void
m_emit_decl (pIIR_SubprogramDeclaration s, string &str, RegionStack &rstack, int l)
{
  assert(false);
}

void
m_emit_decl (pIIR_VariableDeclaration v, string &str, RegionStack &rstack, int l)
{
  str += spaces(l);
  emit_type_name (v->subtype, str, rstack, 0);
  str += " ";
  emit_id (v, str, rstack);
  if (v->initial_value) 				// should be done only in constr.
    {
      str += " = ";
      emit_expr (v->initial_value, str, rstack, DEFAULT);
    }
  str += ";\n";
}

void
m_emit_decl (pIIR_ConstantDeclaration c, string &str, RegionStack &rstack, int l)
{
  str += spaces(l);
  if (!c->initial_value)
    str += "extern ";
  str += "const ";
  emit_type_name (c->subtype, str, rstack, 0);
  str += " ";
  emit_id (c, str, rstack);
  if (c->initial_value) 
    {
      str += " = ";
      emit_expr (c->initial_value, str, rstack, 0);
    }
  str += ";\n";
}

void
m_emit_decl (pIIR_FileDeclaration f, string &str, RegionStack &rstack, int l)
{
  // A file. The file name is in the INITIAL_VALUE slot.

  str += spaces(l);
  emit_type_name (f->subtype, str, rstack, 0);
  str += " ";
  emit_id(f, str, rstack);
  if (f->file_logical_name)
    {
      str += " = open (";
      emit_expr (f->file_logical_name, str, rstack, 0);
      if (f->file_open_expression) 
	{
	  str += ", ";
	  emit_expr (f->file_open_expression, str, rstack, 0);
	}
      str += ")";
    }
  str += ";\n";
}

void
m_emit_decl (pIIR_SignalDeclaration s, string &str, RegionStack &rstack, int l)
{
  str += "sig_info<" + qid(s->subtype->declaration, rstack, TYPE) 
    + "> *" + qid(s, rstack, id_type()) + ";\n";
}


void
m_emit_decl (pIIR_TypeDeclaration t, string &str, RegionStack &rstack, int l)
{
  // A type. We give types names with typedef and then later refer
  // to them via these names
  str += "typedef " + qid (t->type->declaration, rstack, id_type()) + " " + 
    qid(t, rstack, id_type()) + ";\n";
}

void
emit_init_func (pIIR_LibraryUnit l, string &str, const string &body, 
		RegionStack &rstack)
{
  string lid = qid (l, rstack, id_type());

  /* Emit prototypes for init funcs of units that we depend on. */

  // Print line and file info
  last_pos_info = emit_posinfo (NO_SOURCE_LINE, str, last_pos_info, 0);

  if (l->continued)
    str += "int " + qid (l->continued, rstack, id_type ()) + "_init ();\n";
  for (pIIR_LibraryUnitList ul = l->used_units; ul; ul = ul->rest)
    if (ul->first != l->continued)
      str += "int " + qid (ul->first, rstack, id_type ()) + "_init ();\n";

  str += "bool " + lid + "_init_done = false;\n";
  str += "int " + lid + "_init(){\n";
  str += "if (" + lid + "_init_done) return 1;\n";
  str += lid + "_init_done=true;\n";

  /* Emit calls to init funcs of units that we depend on. */
  if (l->continued)
    str += qid (l->continued, rstack, id_type ()) + "_init ();\n";
  for (pIIR_LibraryUnitList ul = l->used_units; ul; ul = ul->rest)
    if (ul->first != l->continued)
      str += qid (ul->first, rstack, id_type ()) + "_init ();\n";

  emit_source_file_register_code(l, str, rstack, 0);

  str += "name_stack iname;\n";
  str += "iname.push(\"\");\n";
  str += body;
  str += "iname.pop();\n";

  if (l->is (IR_PACKAGE_DECLARATION))
    {
      // If the body handle pointer is valid, then call the initialization
      // function for the package body!
      str += "handle_info *h = get_handle (\"" + 
	string (l->library_name->text.to_chars()) + 
	"\",\"" +  nid (l, BARE) + "\",NULL);\n";
      str += "if (h != NULL) (*h->init_function) ();\n";
    }

  str += "return 1;\n";
  str += "}\n";

  if (l->is (IR_PACKAGE_BODY_DECLARATION))
    {
      pIIR_PackageBodyDeclaration pb = (pIIR_PackageBodyDeclaration)l;
      str += "/* handle for simulator to find package body initialization function */\n";	// handle func
      str += "handle_info *";					// dummy var
      str += qid (pb, rstack, id_type());
      str += "_hinfo =\n";
      str += "  add_handle(\"";
      str += string (pb->package->library_name->text.to_chars()) + "\",\"" +  nid (pb->package, BARE) + "\",NULL";
      str += ",NULL";
      str += ",&" + qid (pb, rstack, id_type()) + "_init);\n";
    }
  //str += "int " + lid + "_init_var=register_init_func (" + lid + "_init);\n";
}

void
m_emit_decl (pIIR_PackageDeclaration p, string &str, RegionStack &rstack, int l)
{
  // Do nothing, if no code shall be generated for this library unit
  if (!generate_code (p)) return;

  // A package.  Just emit all declarations in it.
  rstack.push(p);

  // Perform some optimizations
  optimize (p, rstack);

  str += "\n/* package " + get_long_name(p) + " */\n";
  string impl_str, hdr_str, init_str;
  last_pos_info = NO_SOURCE_LINE;
  // emit implementation code. Note that during this call internal
  // code objects may also be generated which are finally outputted by
  // calling emit_global_internal_object_init and
  // emit_global_internal_object_declarations.
  emit_impl (p, impl_str, rstack, l);

  last_pos_info = NO_SOURCE_LINE;
  emit_external_decls(external_decls_list, p, str, rstack, l);
  last_pos_info = NO_SOURCE_LINE;
  emit_hdr (p, hdr_str, rstack, l);

  // *******************************************************************
  // Define all internal global objects initializations
  // *******************************************************************
  emit_global_internal_object_init(RootDeclarativeRegion(rstack), init_str, rstack);

  // *******************************************************************
  // First, emit global prototypes
  // *******************************************************************
  emit_global_internal_object_declarations(RootDeclarativeRegion(rstack), str, rstack);

  // The sequence of declarations is as follows: 1. external
  // declarations, 2. internal declarations, 3. other declarations
  str += hdr_str;

  // *******************************************************************
  // Define all internal global objects
  // *******************************************************************
  emit_global_internal_object_definitions(RootDeclarativeRegion(rstack), str, rstack);

  str += "/* Initialization function for package "+get_long_name(p)+" */\n";
  emit_init_func (p, str,
		  "void *sref=register_package(\":" + nid(p, LIBRARY|BARE) +
		  "\",\":" + nid(p, BARE) + "\");\n" + 
		  init_str + impl_str, rstack);
  str += "\n/* end of package " + get_long_name(p) + " */\n";

  rstack.pop();
}

void
m_emit_decl (pIIR_PackageBodyDeclaration pb, string &str, RegionStack &rstack, int l)
{
  // Do nothing, if no code shall be generated for this library unit
  if (!generate_code (pb)) return;

  // A package body.  Just emit all declarations in it.
  rstack.push(pb);

  // Perform some optimizations
  optimize (pb, rstack);

  str += "\n/* package body " + get_long_name(pb) + " */\n";
  string impl_str, hdr_str, init_str;
  last_pos_info = NO_SOURCE_LINE;
  // emit implementation code. Note that during this call internal
  // code objects may also be generated which are finally outputted by
  // calling emit_global_internal_object_init and
  // emit_global_internal_object_declarations.
  emit_impl (pb, impl_str, rstack, l);
  last_pos_info = NO_SOURCE_LINE;
  emit_external_decls (external_decls_list, pb, str, rstack, l);
  last_pos_info = NO_SOURCE_LINE;
  emit_hdr (pb, hdr_str, rstack, l);

  // *******************************************************************
  // Define all internal global objects initializations
  // *******************************************************************
  emit_global_internal_object_init(RootDeclarativeRegion(rstack), init_str, rstack);

  // *******************************************************************
  // First, emit global prototypes
  // *******************************************************************
  emit_global_internal_object_declarations(RootDeclarativeRegion(rstack), str, rstack);

  // The sequence of declarations is as follows: 1. external
  // declarations, 2. internal declarations, 3. other declarations
  str += hdr_str;

  // *******************************************************************
  // Define all internal global objects
  // *******************************************************************
  emit_global_internal_object_definitions(RootDeclarativeRegion(rstack), str, rstack);

  str += "/* Initialization function for package body " + get_long_name(pb)
         + " */\n";
  emit_init_func (pb, str, 
		  "void *sref=register_package_body(\":" +
		  nid(pb, LIBRARY|BARE) + "\",\":" + nid(pb, BARE) + "\");\n"
		  + init_str + impl_str,
		  rstack);
  str += "\n/* end of package body " + get_long_name(pb) + " */\n";

  rstack.pop();
}


void
m_emit_decl (pIIR_EntityDeclaration e, string &str, RegionStack &rstack, int l)
{
  // Do nothing, if no code shall be generated for this library unit
  if (!generate_code (e)) return;

  rstack.push(e);

  // Perform some optimizations
  optimize (e, rstack);

  string impl_str, hdr_str, init_str;
  last_pos_info = NO_SOURCE_LINE;
  // emit implementation code. Note that during this call internal
  // code objects may also be generated which are finally outputted by
  // calling emit_global_internal_object_init and
  // emit_global_internal_object_declarations.
  emit_impl (e, impl_str, rstack, l);

  last_pos_info = NO_SOURCE_LINE;
  emit_external_decls(external_decls_list, e, str, rstack, l);
  last_pos_info = NO_SOURCE_LINE;
  emit_hdr(e, hdr_str, rstack, l);

  // *******************************************************************
  // Define all internal global objects initializations
  // *******************************************************************
  emit_global_internal_object_init(RootDeclarativeRegion(rstack), init_str, rstack);

  // *******************************************************************
  // First, emit global prototypes
  // *******************************************************************
  emit_global_internal_object_declarations(RootDeclarativeRegion(rstack), str, rstack);

  str += hdr_str;

  // *******************************************************************
  // Define all internal global objects
  // *******************************************************************
  emit_global_internal_object_definitions(RootDeclarativeRegion(rstack), str, rstack);

  str += impl_str;

  str += "\n";

  str += "/* Initialization function for entity "+get_long_name(e)+" */\n";
  emit_init_func (e, str, init_str, rstack);
  str += "\n/* end of " + qid(e, rstack, id_type()) + " Entity */\n";

  rstack.pop();
}

void				// emit Arch decl=hdr+impl+procs
m_emit_decl (pIIR_ArchitectureDeclaration a, string &str, RegionStack &rstack, int l)
{
  // Do nothing, if no code shall be generated for this library unit
  if (!generate_code (a)) return;

  rstack.push(a->entity);
  rstack.push(a);
  pIIR_EntityDeclaration e = a->entity;

  // Perform some optimizations
  optimize (a, rstack);

  string impl_str, hdr_str, init_str;
  last_pos_info = NO_SOURCE_LINE;
  // emit implementation code. Note that during this call internal
  // code objects may also be generated which are finally outputted by
  // calling emit_global_internal_object_init and
  // emit_global_internal_object_declarations.
  emit_impl (a, impl_str, rstack, l);

  last_pos_info = NO_SOURCE_LINE;
  emit_external_decls(external_decls_list, a, str, rstack, l);
  last_pos_info = NO_SOURCE_LINE;
  emit_hdr (a, hdr_str, rstack, l);

  // *******************************************************************
  // Define all internal global objects initializations
  // *******************************************************************
  emit_global_internal_object_init(RootDeclarativeRegion(rstack), init_str, rstack);

  // *******************************************************************
  // First, emit global prototypes
  // *******************************************************************
  emit_global_internal_object_declarations(RootDeclarativeRegion(rstack), str, rstack);

  str += hdr_str;

  // *******************************************************************
  // Define all internal global objects
  // *******************************************************************
  emit_global_internal_object_definitions(RootDeclarativeRegion(rstack), str, rstack);

  str += impl_str;

  str += "\n";

  str += "/* Initialization function for architecture " + get_long_name(a) + " */\n";
  emit_init_func (a, str, init_str, rstack);
  str += "\n/* end of " + get_long_name(a) + " Architecture */\n";

  rstack.pop();
  rstack.pop();
}

void
m_emit_decl (pIIR_ConfigurationDeclaration c, string &str, RegionStack &rstack, int l)
{
  // Do nothing, if no code shall be generated for this library unit
  if (!generate_code (c)) return;

  str += "\n/* configuration " +  qid(c, rstack, id_type()) + " */\n";
}

void
m_emit_decl (pIIR_ComponentDeclaration c, string &str, RegionStack &rstack, int l)
{
  // A component. Emit its interface.

  str += "component " + qid(c, rstack, id_type()) + " (\n";
  str += ");\n";
}


/*
 * Main cc file
 */

void
m_emit_main (pIIR_Declaration d, string &str, RegionStack &rstack, int l)
{
}

void
m_emit_main (pIIR_ConfigurationDeclaration c, string &str, RegionStack &rstack, int l)
{
  codegen_error.error ("%: sorry configurations are currently not supported!", c);
}

void
m_emit_main (pIIR_ArchitectureDeclaration a, string &str, RegionStack &rstack, int l)
{
  rstack.push(a->entity);
  rstack.push(a);
  pIIR_EntityDeclaration e = a->entity;

  string lid = qid (a, rstack, id_type());
  str += "/* Main function for architecture " + get_long_name(a) + " */\n";
  str += string ("#include<freehdl/kernel-handle.hh>\n") + 
    "int main (int argc, char *argv[]) \n" +
    "\n" +
    "{\n" +
    "  extern handle_info *" + qid (a, rstack, id_type()) + "_hinfo;\n" +
    "  extern int kernel_main (int, char *[], handle_info*);\n" + 
    "  return kernel_main (argc, argv, " +  qid (a, rstack, id_type()) + "_hinfo);\n" + 
    "}\n";
  
  str += "\n/* end of " + get_long_name(a) + " main function */\n";
  rstack.pop();
  rstack.pop();
}



/*
 * Headers
 */

void
m_emit_hdr (pIIR_EntityDeclaration e, string &str, RegionStack &rstack, int l)		// Entity header
{
  str += string ("/* Entity class declaration */\n") +
    string ("class ") + qid(e, rstack, id_type()) + string(" {\n") +
    string ("public:\n") +
    string ("   void *father_component;\n") +
    string ("  ") + qid(e, rstack, id_type()) + string (" (name_stack &iname, map_list *mlist, void *father);\n") +
    string ("  ~") + qid(e, rstack, id_type()) + string ("() {};\n");

  emit_decls (extended_generic_clause(e), str, rstack, 2);				// emit signal decls
  emit_decls (extended_port_clause(e), str, rstack, 2);				// emit signal decls

  str += "};\n\n";
}

void							// Arch header
m_emit_hdr (pIIR_ArchitectureDeclaration a, string &str, RegionStack &rstack, int l)
{
  pIIR_EntityDeclaration e = a->entity;
  str += string("/* Architecture class declaration */\n") + 
    string("class ") + qid(a, rstack, id_type()) + string(" : public ") + 
    qid(e, rstack, id_type()) + string(" {\n") +
    string("public:\n") +
    "  " + qid(a, rstack, id_type()) + string(" (name_stack &iname, map_list *mlist, void *father, int level);\n") +
    "  " + string("~") + qid(a, rstack, id_type()) + string("();\n");

  emit_decls (extended_declarations(a), str, rstack, 2);				// emit signal decls
  str += "};\n";										
  
  emit_hdr(a->architecture_statement_part, str, rstack, 2);		// emit process hdrs
}

void							// ConcStat headers
m_emit_hdr (pIIR_ConcurrentStatementList csl, string &str, RegionStack &rstack, int l)
{
  str += "\n/* Concurrent statement class declaration(s) */\n\n";
  while (csl)
    {
      emit_hdr (csl->first, str, rstack, l);  
      csl = csl->rest;
    }
}

void												
m_emit_hdr (pIIR_ConcurrentStatement p, string &str, RegionStack &rstack, int l)
{ 
  rstack.push(p);
  str += "/* Concurrent Statement header */\n"; 
  rstack.pop();
}

void
m_emit_hdr (pIIR_BlockStatement bs, string &str, RegionStack &rstack, int l)
{ 
  rstack.push(bs);
  str += "/* Block Statement header */\n"; 
  rstack.pop();
}

void										
m_emit_hdr (pIIR_ConcurrentGenerateStatement gs, string &str, RegionStack &rstack, int l)
{ 
  rstack.push(gs);

  // Create a list of declarative region pointers beginning from the
  // target region up to the root region
  list<pIIR_DeclarativeRegion> RegionList = create_region_list(gs);
  RegionList.pop_front();

  str += "\n/* Class generate statement " + nid(gs, BARE) + " */\n" +
    "class " + qid(gs, rstack, id_type()) + " {\n" + 
    "public:\n";

  // Create constructor parameters from extended_interface_dclarations
  // list
  string constructor_pars, separator;
  for (pIIR_DeclarationList eil = extended_interface_declarations(gs); eil; eil = eil->rest)
    if (eil->first->is(V2CC_INTERNAL_OBJECT_DECLARATION)) {
      pV2CC_InternalObjectDeclaration iobj = pV2CC_InternalObjectDeclaration(eil->first);
      constructor_pars += separator + iobj->cpp_type_string + " " + iobj->declarator->text.to_chars() + "_PAR";
      separator = ",";
    }

  // Declare constructor
  str +=  spaces(2) + qid(gs, rstack, id_type()) + "(" + constructor_pars + ",name_stack &iname,int level);\n";

  // Emit code to initialize some interal process members
  if (extended_interface_declarations(gs)!= NULL)
    emit_decls(extended_interface_declarations(gs), str, rstack, 2);

  if (extended_declarations(gs) != NULL)
    emit_decls(extended_declarations(gs), str, rstack, 2);

  str += "};\n";

  // Emit header code of included concurrent statements
  emit_hdr(gs->concurrent_statement_part, str, rstack, 2);

  rstack.pop();
}

void								
m_emit_hdr (pIIR_ComponentInstantiationStatement ci, string &str, RegionStack &rstack, int l)
{ 
}

void							//emit hdr for Process
m_emit_hdr (pIIR_ProcessStatement p, string &str, RegionStack &rstack, int l)
{
  rstack.push(p);

  // Create parameter list for class contructor 
  string separator, constructor_pars;
  for (pIIR_DeclarationList eil = extended_interface_declarations(p); eil; eil = eil->rest)
    if (eil->first->is(V2CC_INTERNAL_OBJECT_DECLARATION)) {
      pV2CC_InternalObjectDeclaration iobj = pV2CC_InternalObjectDeclaration(eil->first);
      constructor_pars += separator + iobj->cpp_type_string + " " + iobj->declarator->text.to_chars() + "_PAR";
      separator = ",";
    }

  str += "\n/* Class decl. process " + nid(p, BARE) + " */\n" +
    "class " + qid(p, rstack, id_type()) + " : public process_base {\n" +
    "public:\n" +
    "  " + qid(p, rstack, id_type()) + "(" + constructor_pars + ",name_stack &iname);\n" +
    "  ~" + qid(p, rstack, id_type()) + "() {};\n" +
    "  bool execute();\n";		// execute()
  

  // get context object. The contex stores various informations needed during
  // the code generation process
  ContextInfo &pctxt = *ActiveContext(rstack);

  // Declare additional class member
  if (extended_interface_declarations(p) != NULL) 
    emit_decls(extended_interface_declarations(p), str, rstack, 2);

  // *****************************************************************************
  // create the driver pointer for each signal that is written by the
  // process
  // *****************************************************************************
  bool first = true;
  const char *sep = " ";
  // first, get a list of driven signals
  access_list driven_sigs = 
    filter_unique(pctxt.accessed_objects, WRITE, 
		  tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));
  for (access_list::iterator i = driven_sigs.begin(); i != driven_sigs.end(); i++)
    {
      if (first) {
	first = false;
	str += "  driver_info";
      }
      str += string(sep) + "*" + qid((*i).declaration, rstack, DRIVER);
      sep = ",";
    }
  if (!first) str += ";\n";


  // *****************************************************************************
  // get reader pointer for all signals that are read within the
  // process
  // *****************************************************************************
  pIIR_TypeDeclaration old_type = NULL;
  first = true;
  sep = " ";
  // first, get a list of read signals
  access_list read_sigs = 
    filter_unique(pctxt.accessed_objects, READ, 
		  tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));
  for (access_list::iterator i = read_sigs.begin(); i != read_sigs.end(); i++)
    {
      pIIR_Type subtype = pIIR_ObjectDeclaration((*i).declaration)->subtype;
      pIIR_TypeDeclaration type = subtype != NULL? get_declaration(subtype) : NULL;
      if (type != old_type ||
	  (type == NULL && old_type == NULL)) {
	if (!first) str +=";\n";
	str += "  " + ((type != NULL)? qid(type, rstack, TYPE) : "enumeration");
	first = false;
	sep = " ";
	old_type = type;
      }
      str += string(sep) + "*" + qid((*i).declaration, rstack, READER);
      sep = ",";
    }
  if (read_sigs.size()) str += ";\n";


  // *****************************************************************************
  // Create local copy of sig_info pointer for signals that are prefix
  // of a signal function kind attribute (e.g. event, active,
  // last_event, last_active,...)
  // *****************************************************************************
  old_type = NULL;
  first = true;
  sep = " ";
  // first, get a list of signals which are prefix of an attribute
  access_list attr_sigs = 
    filter_unique(pctxt.accessed_objects, SIGNAL_FUNCTION_ATTRIBUTE, 
		  tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));
  for (access_list::iterator i = attr_sigs.begin(); i != attr_sigs.end(); i++)
    {
      pIIR_TypeDeclaration type = get_declaration(pIIR_ObjectDeclaration((*i).declaration)->subtype);
      if (type != old_type) {
	if (!first) str +=";\n";
	str += "  sig_info<" + qid(type, rstack, TYPE) + ">";
	first = false;
	sep = " ";
	old_type = type;
      }
      str += string(sep) + "*" + qid((*i).declaration, rstack, DEFAULT);
      sep = ",";
    }
  if (attr_sigs.size()) str += ";\n";


  // *****************************************************************************
  // declare variables and constants
  // *****************************************************************************
  emit_decls(extended_declarations(p), str, rstack, l);


  // *****************************************************************************
  // declare winfo_item array
  // *****************************************************************************
  if (pctxt.wait_statements.size() > 0)
    str += string("  winfo_item winfo[") + to_string (pctxt.wait_statements.size()) 
      + string("];\n");
  

  // *****************************************************************************
  // ptr to parent architecture
  // *****************************************************************************
  str += string("  ") + qid(p->declarative_region, rstack, id_type()) + 
    string(" *arch;\n") + string("};\n");

  rstack.pop();
} // emit_hdr for Process



// Emit subprogram prototype. Parameter full_prototype controls
// whether the parameter names of the subprogram (full_prototype=true)
// are printed or not.
string
emit_subprogram_prototype(pIIR_SubprogramDeclaration sbp, RegionStack &rstack, 
			  bool full_prototype, int l)
{
  string str, return_type_str;
  string separator = "";

  // Check whether sbp is a function or a procedure
  bool is_function = sbp->is(IR_FUNCTION_DECLARATION); 

  // Determine return type of generated function
  if (sbp->is(IR_FUNCTION_DECLARATION))
    return_type_str = qid(get_declaration(pIIR_FunctionDeclaration(sbp)->return_type), rstack, TYPE);
  else
    return_type_str = "void";

  // Print return type and name 
  str += return_type_str + " " + qid(sbp, rstack, DEFAULT) + "(";
  
  // ****************************************************************************
  // Analyze normal subprogram parameter
  // ****************************************************************************
  for (pIIR_DeclarationList il = extended_interface_declarations(sbp); il; il = il->rest) {
    if (!il->first->is(IR_INTERFACE_DECLARATION)) continue;
    pIIR_InterfaceDeclaration par = pIIR_InterfaceDeclaration(il->first);
    // The parameter is passed in by reference if it is a non scalar
    // type or if the parameter is of mode OUT, INOUT or BUFFER.
    bool call_by_reference = !is_scalar_type(par->subtype) ||
      par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || 
      par->mode == IR_BUFFER_MODE;
    // Determine whether the parameter must be copied back
    bool copy_back = is_scalar_type(par->subtype) && 
      (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || 
       par->mode == IR_BUFFER_MODE);
    // Determine whether the parameter must be copied in
    bool copy_in = copy_back && 
      (par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE);
    // Determine whether the parameter can be used directly or an
    // temporary must be created. It cannot be used directly if the
    // parameter value must be copied back or the parameter type is a
    // constrained array type.
    bool direct_use = !(copy_back || is_constrained_array_type(par->subtype));

    if (par->is(IR_VARIABLE_INTERFACE_DECLARATION)) {
      str += separator + qid(get_declaration(par->subtype), rstack, TYPE) + 
	(call_by_reference? " &" : " ");
      if (full_prototype)
	str += qid(par, rstack, DEFAULT) + (!direct_use? "_PAR" : "");

    } else if (par->is(IR_CONSTANT_INTERFACE_DECLARATION)) {
      str += separator + "const " + qid(get_declaration(par->subtype), rstack, TYPE) + 
	(call_by_reference? " &" : " ");
      if (full_prototype)
	str += qid(par, rstack, DEFAULT) + (!direct_use? "_PAR" : "");

    } else if (par->is(IR_FILE_INTERFACE_DECLARATION)) {
      str += separator + qid(get_declaration(par->subtype), rstack, TYPE) + 
	(call_by_reference? " &" : " ");
      if (full_prototype)
	str += qid(par, rstack, DEFAULT) + (!direct_use? "_PAR" : "");

    } else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION)) {
      // Signal values are NOT copied back! Instead, any operations
      // are directly applied on the corresponding reader/driver...
      copy_back = false;
      direct_use = true;
      // First, append sig_info pointer
      str += separator + "sig_info<" + qid(get_declaration(par->subtype), rstack, TYPE) + "> *";
      if (full_prototype)
	str += qid(par, rstack, SIGNAL);
      // Next, append reader if signal is of mode in or inout or buffer
      if (par->mode == IR_IN_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	str += "," + qid(get_declaration(par->subtype), rstack, TYPE) + " *";
	if (full_prototype)
	  str += qid(par, rstack, READER);
      }
      // Finally, append driver if mode is of out or inout or buffer
      if (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	str += ",driver_info *";
	if (full_prototype)
	  str += qid(par, rstack, DRIVER);
      }

    }

    // Set separator for next parameter
    separator = ",";
  }

  // ****************************************************************************
  // Analyze extra subprogram parameter
  // ****************************************************************************
  list<AccessDescriptor> &extra_parameter = context(sbp).extra_interface_objects;
  for (list<AccessDescriptor>::iterator iter = extra_parameter.begin();
       iter != extra_parameter.end(); iter++) {
    pIIR_Declaration par = (*iter).declaration;

    if (par->is(IR_VARIABLE_INTERFACE_DECLARATION) ||
	par->is(IR_VARIABLE_DECLARATION) ||
	par->is(IR_CONSTANT_INTERFACE_DECLARATION) ||
	par->is(IR_CONSTANT_DECLARATION) || 
	par->is(IR_FILE_DECLARATION) ||
	par->is(IR_FILE_INTERFACE_DECLARATION)) {
      str += separator + qid(get_declaration(pIIR_ObjectDeclaration(par)->subtype), rstack, TYPE) + " &";
      if (full_prototype)
	str += qid(par, rstack, DEFAULT);
 
    } else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION) ||
	       par->is(IR_SIGNAL_DECLARATION)) {
      pIIR_ObjectDeclaration opar = pIIR_ObjectDeclaration(par);
      AccessFlags &aflags = (*iter).access_type;

      string decl_type;
      if (opar->is(V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR))
	decl_type = "enumeration";
      else
	decl_type = qid(get_declaration(opar->subtype), rstack, TYPE);

      // Add sig_info pointer if a signal function kind attribute has
      // been applied on the parameter

      if (aflags & SIGNAL_FUNCTION_ATTRIBUTE) {
	str += separator + "sig_info<" + decl_type + "> *";
	if (full_prototype)
	  str += qid(par, rstack, SIGNAL);
	separator = ",";
      }
      // Next, append reader if signal is read
      if (aflags & READ) {
	str += separator + decl_type + " *";
	if (full_prototype)
	  str += qid(par, rstack, READER);
	separator = ",";
      }
      // Finally, append driver if signal is written
      if (aflags & WRITE) {
	str += separator + "driver_info *";
	if (full_prototype)
	  str += qid(par, rstack, DRIVER);
      }

    } else if (par->is(IR_TYPE_DECLARATION) ||
	       par->is(IR_SUBTYPE_DECLARATION)) {
      // A type has been used and we need to pass over the type info
      // pointer of that type!
      str += separator + qid(par, rstack, INFO) + " &";
      if (full_prototype)
	str += qid(par, rstack, INFO) + "_INFO";
    }

    // Set separator for next parameter
    separator = ",";
  }
  

  str += ")";

  return str;
}


// Emit procedure class constructor (I.e., this subprograms contains
// waits and hence must be converted into a corresponding
// class). Parameter full_prototype controls whether the parameter
// names of the subprogram (full_prototype=true) are printed or not.
string
emit_delayed_procedure_constructor (pIIR_ProcedureDeclaration sbp, RegionStack &rstack, 
				    bool full_prototype, int l)
{
  string str;
  string separator = "";

  // Print return type and name 
  str += qid(sbp, rstack, DEFAULT) + " (process_base *" +
    string (full_prototype ? "process_PAR," : ",") + 
    + "winfo_item &" + string (full_prototype ? "winfo_PAR," : ","); 
  
  // ****************************************************************************
  // Analyze normal subprogram parameter
  // ****************************************************************************
  for (pIIR_DeclarationList il = extended_interface_declarations(sbp); il; il = il->rest) {
    if (!il->first->is(IR_INTERFACE_DECLARATION)) continue;
    pIIR_InterfaceDeclaration par = pIIR_InterfaceDeclaration(il->first);
    // The parameter is passed in by reference if it is a non scalar
    // type or if the parameter is of mode OUT, INOUT or BUFFER.
    bool call_by_reference = !is_scalar_type(par->subtype) ||
      par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || 
      par->mode == IR_BUFFER_MODE;
    // Determine whether the parameter must be copied back
    bool copy_back = is_scalar_type(par->subtype) && 
      (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || 
       par->mode == IR_BUFFER_MODE);
    // Determine whether the parameter must be copied in
    bool copy_in = copy_back && 
      (par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE);
    // Determine whether the parameter can be used directly or an
    // temporary must be created. It cannot be used directly if the
    // parameter value must be copied back or the parameter type is a
    // constrained array type.
    bool direct_use = !(copy_back || is_constrained_array_type(par->subtype));

    if (par->is(IR_VARIABLE_INTERFACE_DECLARATION)) {
      str += separator + qid(get_declaration(par->subtype), rstack, TYPE) + 
	(call_by_reference? " &" : " ");
      if (full_prototype)
	str += qid(par, rstack, DEFAULT) + "_PAR";

    } else if (par->is(IR_CONSTANT_INTERFACE_DECLARATION)) {
      str += separator + "const " + qid(get_declaration(par->subtype), rstack, TYPE) + 
	(call_by_reference? " &" : " ");
      if (full_prototype)
	str += qid(par, rstack, DEFAULT) + "_PAR";

    } else if (par->is(IR_FILE_INTERFACE_DECLARATION)) {
      str += separator + qid(get_declaration(par->subtype), rstack, TYPE) + 
	(call_by_reference? " &" : " ");
      if (full_prototype)
	str += qid(par, rstack, DEFAULT) + "_PAR";

    } else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION)) {
      // Signal values are NOT copied back! Instead, any operations
      // are directly applied on the corresponding reader/driver...
      copy_back = false;
      direct_use = true;
      // First, append sig_info pointer
      str += separator + "sig_info<" + qid(get_declaration(par->subtype), rstack, TYPE) + "> *";
      if (full_prototype)
	str += qid(par, rstack, SIGNAL) + "_PAR";
      // Next, append reader if signal is of mode in or inout or buffer
      if (par->mode == IR_IN_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	str += "," + qid(get_declaration(par->subtype), rstack, TYPE) + " *";
	if (full_prototype)
	  str += qid(par, rstack, READER) + "_PAR";
      }
      // Finally, append driver if mode is of out or inout or buffer
      if (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	str += ",driver_info *";
	if (full_prototype)
	  str += qid(par, rstack, DRIVER) + "_PAR";
      }

    } else
      continue;

    // Set separator for next parameter
    separator = ",";
  }

  // ****************************************************************************
  // Analyze extra subprogram parameter
  // ****************************************************************************
  list<AccessDescriptor> &extra_parameter = context(sbp).extra_interface_objects;
  for (list<AccessDescriptor>::iterator iter = extra_parameter.begin();
       iter != extra_parameter.end(); iter++) {
    pIIR_Declaration par = (*iter).declaration;

    if (par->is(IR_VARIABLE_INTERFACE_DECLARATION) ||
	par->is(IR_VARIABLE_DECLARATION) ||
	par->is(IR_CONSTANT_INTERFACE_DECLARATION) ||
	par->is(IR_CONSTANT_DECLARATION) || 
	par->is(IR_FILE_DECLARATION) ||
	par->is(IR_FILE_INTERFACE_DECLARATION)) {
      str += separator + qid(get_declaration(pIIR_ObjectDeclaration(par)->subtype), rstack, TYPE) + " &";
      if (full_prototype)
	str += qid(par, rstack, DEFAULT) + "_PAR";
 
    } else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION) ||
	       par->is(IR_SIGNAL_DECLARATION)) {
      pIIR_ObjectDeclaration opar = pIIR_ObjectDeclaration(par);
      AccessFlags &aflags = (*iter).access_type;

      string decl_type;
      if (opar->is(V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR))
	decl_type = "enumeration";
      else
	decl_type = qid(get_declaration(opar->subtype), rstack, TYPE);

      // Add sig_info pointer if a signal function kind attribute has
      // been applied on the parameter

      if ((aflags & SIGNAL_FUNCTION_ATTRIBUTE) ||
	  (aflags & SENSITIVE)) {
	str += separator + "sig_info<" + decl_type + "> *";
	if (full_prototype)
	  str += qid(par, rstack, SIGNAL) + "_PAR";
	separator = ",";
      }
      // Next, append reader if signal is read
      if (aflags & READ) {
	str += separator + decl_type + " *";
	if (full_prototype)
	  str += qid(par, rstack, READER) + "_PAR";
	separator = ",";
      }
      // Finally, append driver if signal is written
      if (aflags & WRITE) {
	str += separator + "driver_info *";
	if (full_prototype)
	  str += qid(par, rstack, DRIVER)+ "_PAR";
      }

    } else if (par->is(IR_TYPE_DECLARATION) ||
	       par->is(IR_SUBTYPE_DECLARATION)) {
      // A type has been used and we need to pass over the type info
      // pointer of that type!
      str += separator + qid(par, rstack, INFO) + " &";
      if (full_prototype)
	str += qid(par, rstack, INFO) + "_INFO_PAR";

    } else
      continue;

    // Set separator for next parameter
    separator = ",";
  }
  

  str += ")";

  return str;
}


// Print subprogram prototype to str
void							//emit hdr for subprograms
m_emit_hdr (pIIR_PredefinedProcedureDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  rstack.push(sbp);

  str += "/* Prototype for predefined subprogram " + get_long_name(sbp) + " */\n";

  // Emit the various implicit subprogram prototypes
  string proc_name = convert_string(sbp->declarator->text.to_chars(), tolower);
  if (proc_name == "deallocate") {
    // ***************************************************************
    // Dellocate operation
    // ***************************************************************
    str += "#define " + qid(sbp, rstack, DEFAULT) + 
      "(p,a) p=(p!=NULL?(a.designated_type_info->remove(p),(void*)NULL):(void*)NULL)\n";

  } else if (proc_name == "file_open") {
    // ***************************************************************
    // File open operation
    // **************************************************************
    if (get_base_type(sbp->interface_declarations->first->subtype)->is(IR_FILE_TYPE)) {
      // If the first procedure parameter is of a file type then the
      // file_open procedure which does not return status information
      // is emitted.
      str += "#define " + qid(sbp, rstack, DEFAULT) + "(f,n,k) file_open(f,n,k)\n";
    } else {
      // Otherwise, the first parameter takes the file open status.
      str += "#define " + qid(sbp, rstack, DEFAULT) + "(s,f,n,k) file_open(s,f,n,k)\n";
    }

  } else if (proc_name == "read") {
    // ***************************************************************
    // File read operation
    // ***************************************************************
    pIIR_Type element_type = pIIR_FileType(sbp->interface_declarations->first->subtype)->type_mark; 
    // The actual file read opertation depends on the file element
    // type
    if (is_array_type(element_type)) {
      if (!is_constrained_array_type(element_type))
	// If the file elemement type is an unconstrained array then a
	// special file read operation must be used. This read operation
	// has an additional parameter to return the number of array
	// elements written into the destination array.
	str += "#define " + qid(sbp, rstack, DEFAULT) + "(f,v,l) file_read_array(f,&v,l)\n";
      else
	str += "#define " + qid(sbp, rstack, DEFAULT) + "(f,v) file_read_array(f,&v)\n";

    } else if (get_base_type(element_type)->is(IR_RECORD_TYPE)) {
      str += "#define " + qid(sbp, rstack, DEFAULT) + "(f,v) file_read_record(f,&v)\n"; 
    } else {
      string element_type_str = qid(get_base_type(element_type), rstack, TYPE);
      str += "#define " + qid(sbp, rstack, DEFAULT) + 
	"(f,v) file_read_scalar(f,&v,sizeof(" + element_type_str + "))\n"; 
    }

  } else if (proc_name == "write") {
    // ***************************************************************
    // File write operation
    // ***************************************************************
    pIIR_Type element_base_type = 
      get_base_type(pIIR_FileType(sbp->interface_declarations->first->subtype)->type_mark); 
    // The actual file write opertation depends on the file element
    // type
    if (element_base_type->is(IR_ARRAY_TYPE)) 
      str += "#define " + qid(sbp, rstack, DEFAULT) + "(f,v) file_write_array(f,const_pointer(v))\n";
    else if (element_base_type->is(IR_RECORD_TYPE))
      str += "#define " + qid(sbp, rstack, DEFAULT) + "(f,v) file_write_record(f,const_pointer(v))\n";
    else {
      string element_base_type_str = qid(element_base_type, rstack, TYPE);
      str += "#define " + qid(sbp, rstack, DEFAULT) + 
	"(f,v) file_write_scalar(f,const_pointer(v),sizeof(" + element_base_type_str + "))\n";
    }

  } else if (proc_name == "file_close") {
    // ***************************************************************
    // File write operation
    // ***************************************************************
    str += "#define " + qid(sbp, rstack, DEFAULT) + "(f) file_close(f)\n";    

  } else 
    assert(false);

  rstack.pop();
}


// Print subprogram prototype to str
void							//emit hdr for subprograms
m_emit_hdr (pIIR_PredefinedFunctionDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  rstack.push(sbp);

  str += "/* Prototype for predefined function " + get_long_name(sbp) + " */\n";
  
  // Emit the various implicit subprogram prototypes
  string func_name = convert_string(sbp->declarator->text.to_chars(), tolower);
  if (func_name == "endfile")
    str += "#define " + qid(sbp, rstack, DEFAULT) + "(f) file_eof(f)\n";

  rstack.pop();
}


// Print subprogram prototype to str
void							//emit hdr for subprograms
m_emit_hdr (pIIR_SubprogramDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  // Nothing to do if sbp is a standard operator
  if (sbp->is (IR_FUNCTION_DECLARATION) && 
      get_operator_type(sbp) == STD_OP)
    return;

  rstack.push(sbp);

  // Check out whether this is a normal plain subprogram or a
  // procedure that contain wait statements. 
  if (sbp->is (IR_PROCEDURE_DECLARATION) &&
      (has_wait (pIIR_ProcedureDeclaration (sbp)) ||
       has_wait_for (pIIR_ProcedureDeclaration (sbp))))
    {
      // Ok, there are waits in this procedure. Hence, we need some
      // special handling for this. Each such procedure is translated
      // into a corresponding class similar to a process class.

      // First, determine declarations that belong to corresponding
      // constructor parameters
      string decl_str;
      // ****************************************************************************
      // Analyze normal subprogram parameter
      // ****************************************************************************
      for (pIIR_DeclarationList il = extended_interface_declarations(sbp); il; il = il->rest) {
	if (!il->first->is(IR_INTERFACE_DECLARATION)) continue;
	pIIR_InterfaceDeclaration par = pIIR_InterfaceDeclaration(il->first);
	// The parameter is passed in by reference if it is not a scalar
	// type or if the parameter is of mode OUT, INOUT or BUFFER.
	bool call_by_reference = !is_scalar_type(par->subtype) ||
	  par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || 
	  par->mode == IR_BUFFER_MODE;
	// Determine whether the parameter must be copied back
	bool copy_back = (is_scalar_type(par->subtype) ||
			  is_constrained_array_type (get_basic_type (par->subtype))) && 
	  (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || 
	   par->mode == IR_BUFFER_MODE);
	// Determine whether the parameter must be copied in
	bool copy_in = copy_back && 
	  (par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE);
	// Determine whether the parameter can be used directly or an
	// temporary must be created. It cannot be used directly if the
	// parameter value must be copied back or the parameter type is a
	// constrained array type.
	bool direct_use = !(copy_back || is_constrained_array_type(par->subtype));

	if (par->is(IR_VARIABLE_INTERFACE_DECLARATION)) {
	  decl_str += spaces (l + 2) + qid (get_declaration(par->subtype), rstack, TYPE) + 
	    (call_by_reference && !copy_back? " &" : " ") + qid (par, rstack, DEFAULT) + ";\n";
	  if (copy_back)
	    decl_str += spaces (l + 2) + qid (get_declaration(par->subtype), rstack, TYPE) + 
	    " &" + qid (par, rstack, DEFAULT) + "_REF;\n";
	  
	} else if (par->is(IR_CONSTANT_INTERFACE_DECLARATION)) {
	  decl_str += spaces (l + 2) + "const " + qid(get_declaration(par->subtype), rstack, TYPE) + 
	    (call_by_reference? " &" : " ") + qid (par, rstack, DEFAULT) + ";\n";
	  
	} else if (par->is(IR_FILE_INTERFACE_DECLARATION)) {
	  decl_str += spaces (l + 2) + qid(get_declaration(par->subtype), rstack, TYPE) + 
	    (call_by_reference? " &" : " ") + qid(par, rstack, DEFAULT) + ";\n";
	  
	} else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION)) {
	  // Signal values are NOT copied back! Instead, any operations
	  // are directly applied on the corresponding reader/driver...
	  copy_back = false;
	  direct_use = true;
	  // First, append sig_info pointer
	  decl_str += spaces (l + 2) + "sig_info<" + qid(get_declaration(par->subtype), rstack, TYPE) + "> *"
	    + qid(par, rstack, SIGNAL) + ";\n";
	  // Next, append reader if signal is of mode in or inout or buffer
	  if (par->mode == IR_IN_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	    decl_str += spaces (l + 2) + qid(get_declaration(par->subtype), rstack, TYPE) + " *"
	      + qid(par, rstack, READER) + ";\n";
	  }
	  // Finally, append driver if mode is of out or inout or buffer
	  if (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	    decl_str += spaces (l + 2) + "driver_info *" + qid(par, rstack, DRIVER) + ";\n";
	  }
	}
      }

      // ****************************************************************************
      // Analyze extra subprogram parameter
      // ****************************************************************************
      list<AccessDescriptor> &extra_parameter = context(sbp).extra_interface_objects;
      for (list<AccessDescriptor>::iterator iter = extra_parameter.begin();
	   iter != extra_parameter.end(); iter++) {
	pIIR_Declaration par = (*iter).declaration;
	
	if (par->is(IR_VARIABLE_INTERFACE_DECLARATION) ||
	    par->is(IR_VARIABLE_DECLARATION) ||
	    par->is(IR_CONSTANT_INTERFACE_DECLARATION) ||
	    par->is(IR_CONSTANT_DECLARATION) || 
	    par->is(IR_FILE_DECLARATION) ||
	    par->is(IR_FILE_INTERFACE_DECLARATION)) {
	  decl_str += spaces (l + 2) + qid(get_declaration(pIIR_ObjectDeclaration(par)->subtype), rstack, TYPE) + " &"
	    + qid(par, rstack, DEFAULT) + ";\n";
	  
	} else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION) ||
		   par->is(IR_SIGNAL_DECLARATION)) {
	  pIIR_ObjectDeclaration opar = pIIR_ObjectDeclaration(par);
	  AccessFlags &aflags = (*iter).access_type;
	  
	  string decl_type;
	  if (opar->is(V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR))
	    decl_type = "enumeration";
	  else
	    decl_type = qid(get_declaration(opar->subtype), rstack, TYPE);
	  
	  // Add sig_info pointer if a signal function kind attribute has
	  // been applied on the parameter
	  
	  if ((aflags & SIGNAL_FUNCTION_ATTRIBUTE) ||
	      (aflags & SENSITIVE)) {
	    decl_str += spaces (l + 2) + "sig_info<" + decl_type + "> *" + qid(par, rstack, SIGNAL) + ";\n";
	  }
	  // Next, append reader if signal is read
	  if (aflags & READ) {
	    decl_str += spaces (l + 2) + decl_type + " *" + qid(par, rstack, READER) + ";\n";
	  }
	  // Finally, append driver if signal is written
	  if (aflags & WRITE) {
	    decl_str += spaces (l + 2) + "driver_info *" + qid(par, rstack, DRIVER) + ";\n";
	  }
	  
	} else if (par->is(IR_TYPE_DECLARATION) ||
		   par->is(IR_SUBTYPE_DECLARATION)) {
	  // A type has been used and we need to pass over the type info
	  // pointer of that type!
	  decl_str += spaces (l + 2) + qid(par, rstack, INFO) + " &" + qid(par, rstack, INFO) + "_INFO;\n";
	}
      }
  
      str += "/* Class decl. for subprogram " + get_long_name(sbp) + " (contains waits) */\n";
      str += "class " + qid(sbp, rstack, DEFAULT) + " : public delayed_procedure_base {\n";
      str += "public:\n";
      str += "  " + emit_delayed_procedure_constructor (pIIR_ProcedureDeclaration (sbp), 
							rstack, false, 2) + ";\n";
      str += "  ~" + qid(sbp, rstack, DEFAULT) + " ();\n";
      str += "  bool execute ();\n";
      str += "  /* declarations connected with subprogram interface */\n";
      str += decl_str;
      str += "  /* local declarations */\n";
      // *****************************************************************************
      // declare variables and constants
      // *****************************************************************************
      emit_decls(extended_declarations(sbp), str, rstack, l + 2);
      str += "};\n";
    } 
  else
    {
      // Ok, this is a plain subprogram.
      str += "/* Prototype for subprogram " + get_long_name(sbp) + " */\n";
      str += emit_subprogram_prototype(sbp, rstack, false, l);
      str += ";\n";
    }

  rstack.pop();
}


void
m_emit_hdr (pIIR_EnumerationType et, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = et->declaration;
  str += "/* Definitions for enumeration type " + get_long_name(decl) + " */\n";
  
  // Emit enum info class definition 
  str += "class " + qid(decl, rstack, INFO) + ":public enum_info_base{\n" +
    "   static const char *values[];\n" +
    "public:\n" +
    "   " + qid(decl, rstack, INFO) + "():enum_info_base(0,"+ to_string(enum_item_number(et) - 1) + ",values) {};\n" + 
    "   static const char **get_values() { return values; }\n" +
    "   static int low() { return 0; }\n" +
    "   static int high() { return " + to_string(enum_item_number(et) - 1) + "; }\n" +
    "   static int left() { return 0; }\n" +
    "   static int right() { return " + to_string(enum_item_number(et) - 1) + "; }\n" + 
    "};\n";

  // If the type shall be globally visible then add an external info
  // instance declaration
  if (static_declarative_region(et) == RootDeclarativeRegion(rstack))
    str += "extern " + qid(decl, rstack, INFO) + " " + qid(decl, rstack, INFO) + "_INFO;\n";
}

void
m_emit_hdr (pIIR_AccessType at, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = at->declaration;
  str += "/* Definitions for access type " + get_long_name(decl) + " */\n";
  // The derived info class is just a access_info_base!
  str += "#define " + qid(at, rstack, INFO) + " access_info_base\n";
  // If the type shall be globally visible then add an external info
  // instance declaration
  if (static_declarative_region(at) == RootDeclarativeRegion(rstack))
    str += "extern access_info_base " + qid(at, rstack, INFO) + "_INFO;\n";
}


void
m_emit_hdr (pIIR_FileType ft, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = ft->declaration;
  str += "/* Definitions for file type " + get_long_name(decl) + " */\n";
  // The derived info class is just a vhdlfile_info_base!
  str += "#define " + qid(ft, rstack, INFO) + " vhdlfile_info_base\n";
  // If the type shall be globally visible then add an external info
  // instance declaration
  if (static_declarative_region(ft) == RootDeclarativeRegion(rstack))
    str += "extern vhdlfile_info_base " + qid(ft, rstack, INFO) + "_INFO;\n";
}


void
m_emit_hdr (pIIR_ArrayType at, string &str, RegionStack &rstack, int l)
{
  int counter = 0;

  // Count number of dimensions
  for (pIIR_TypeList tl = at->index_types; tl; tl = tl->rest)
    counter++;
  
  // If the array hase more than a single dimension then first declare
  // the a separate internal array type for each dimension. Note that
  // e.g. a two-dimensional array "type mytype array(integer range <>,
  // positive range <>) of bit" is transformed into two one
  // dimentional arrays similar to: "type internal_array is
  // array(positive range <>) of bit" and "type mytype is
  // array(integer range <>) of internal_array".
  string array_type_str = qid(at->element_type, rstack, TYPE);
  for (int i = counter; i >= 1; i--) {
    pIIR_TypeList tl = at->index_types;
    for (int j = 1; j < i; j++)
      tl = tl->rest;
    array_type_str = "array_type<" + array_type_str + " >";
  }

  // If the type shall be globally visible then add an external info
  // instance declaration
  if (static_declarative_region(at) == RootDeclarativeRegion(rstack))
    str += "extern array_info " + qid(at->declaration, rstack, INFO) + "_INFO;\n";
  str += "#define " + qid(at->declaration, rstack, TYPE) + " " + array_type_str + "\n";
  str += "#define " + qid(at->declaration, rstack, INFO) + " array_info\n\n";
}


void
m_emit_hdr (pIIR_ArraySubtype ast, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = ast->declaration;

  // Test whether the array subtype introduces some constraints
  if (ast->constraint == NULL) {
    // Ok, no new constraints. Hence, derive array type and array info
    // from immediate base type

    // If the type shall be globally visible then add an external info
    // instance declaration
    if (static_declarative_region(ast) == RootDeclarativeRegion(rstack))
      str += "extern array_info " + qid(ast, rstack, INFO) + "_INFO;\n";
    str += "#define " + qid(ast, rstack, TYPE) + " " + qid(ast->immediate_base, rstack, TYPE) + "\n";
    str += "#define " + qid(ast, rstack, INFO) + " array_info\n\n";

  } else {
    // A constrained subtype. Get base type of array subtype.
    assert(ast->base->is(IR_ARRAY_TYPE));
    pIIR_ArrayType array_type = pIIR_ArrayType(ast->base);
    
    int counter = 0;
    
    // Count number of dimensions
    for (pIIR_TypeList tl = ast->constraint; tl; tl = tl->rest)
      counter++;
    
    // If the array hase more than a single dimension then first declare
    // the a separate internal array type for each dimension. Note that
    // e.g. a two-dimensional array "type mytype array(integer range <>,
    // positive range <>) of bit" is transformed into two one
    // dimentional arrays similar to: "type internal_array is
    // array(positive range <>) of bit" and "type mytype is
    // array(integer range <>) of internal_array".
    string array_type_str = qid(array_type->element_type, rstack, TYPE);
    for (int i = counter; i >= 1; i--) {
      pIIR_TypeList tl = array_type->index_types;
      for (int j = 1; j < i; j++)
	tl = tl->rest;
      array_type_str = "array_type<" + array_type_str + " >";
    }
    
    // If the type shall be globally visible then add an external info
    // instance declaration
    if (static_declarative_region(ast) == RootDeclarativeRegion(rstack))
      str += "extern array_info " + qid(ast, rstack, INFO) + "_INFO;\n";
    str += "#define " + qid(ast, rstack, TYPE) + " " + array_type_str + "\n";
    str += "#define " + qid(ast, rstack, INFO) + " array_info\n\n";
  }

}


void
m_emit_hdr (pIIR_ScalarSubtype sst, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = get_declaration(sst);

  // Is the subtype constrained or at least a resolution function hase
  // been added?
  if (sst->range == NULL && sst->resolution_function == NULL) {
    // No, the subtype is not constrained. Hence, the type info
    // object is a copy of the type info object of the base type.
    str += "#define " + qid(decl, rstack, INFO) + " " + 
      qid(get_declaration(sst->immediate_base), rstack, INFO) + "\n";
    
  } else if (sst->base->is(IR_ENUMERATION_TYPE)) {
    // ****************************************************************************
    // Enumeration subtype
    // ****************************************************************************
    // The subtype is contrained! Determine range of the new
    // enumeration subtype.
    str += "/** Enumeration info class " + get_long_name(decl) + " */\n";
    vector<RangeDescriptor> range_desc = get_discrete_range(sst, rstack, IR_NOT_STATIC);
    // Check whether bounds and range direction could be determined at
    // compile time. Enumeration types with static bounds are defined
    // globally.
    StaticRangeDescriptor<lint, IR_Direction> range = 
      range_desc[0].rangedes_to_lint(rstack);
    if (and_reduce(range.valid)) {    
      // Emit enum info class definition 
      str += "class " + qid(decl, rstack, INFO) + ":public enum_info_base{\n" +
	"   static const char **values;\n" +
	"public:\n" +
	"   " + qid(decl, rstack, INFO) + "():enum_info_base(" + to_string(range.left) + 
	","+ to_string(range.right) + ",values) {};\n" + 
	"   static const char **get_values() { return values; }\n" +
	"   static int low() { return " + to_string(range.left) + "; }\n" +
	"   static int high() { return " + to_string(range.right) + "; }\n" +
	"   static int left() { return " + to_string(range.left) + "; }\n" +
	"   static int right() { return " + to_string(range.right) + "; }\n" + 
	"};\n";
    } else {
      // Enumeration info class definition with non static bounds
      // (i.e., the bounds must be calculated at runtime)
      str += "#define " + qid(decl, rstack, INFO) + " enum_info_base\n";
    }

    
  } else if (sst->base->is(IR_INTEGER_TYPE)) {
    // ****************************************************************************
    // Integer subtype
    // ****************************************************************************
    str += "/** Integer info class " + get_long_name(decl) + " */\n";
    vector<RangeDescriptor> range_desc = get_discrete_range(sst, rstack, IR_NOT_STATIC);
    // Check whether bounds and range direction could be determined at
    // compile time. Integer types which static bounds are defined
    // globally.
    StaticRangeDescriptor<lint, IR_Direction> range = 
      range_desc[0].rangedes_to_lint(rstack);
    if (and_reduce (range.valid)) {
      // Integer info class definition with static bounds
      str += "class " + qid(decl, rstack, INFO) + ":public integer_info_base{\n" +
	"public:\n" +
	"   " + qid(decl, rstack, INFO) + "():integer_info_base(" + 
	to_string(range.left) + ","+ to_string(range.right) + "," + 
	to_string(min(range.left,range.right)) + "," + to_string(max(range.left, range.right)) + ") {};\n" + 
	"   static integer low() { return " + to_string(min(range.left, range.right)) + "; }\n" +
	"   static integer high() { return " + to_string(max(range.left, range.right)) + "; }\n" +
	"   static integer left() { return " + to_string(range.left) + "; }\n" +
	"   static integer right() { return " + to_string(range.right) + "; }\n" + 
	"};\n";
    } else {
      // Integer info class definition with non static bounds (i.e.,
      // the bounds must be calculated at runtime)
      str += "#define " + qid(decl, rstack, INFO) + " integer_info_base\n";
    }

  } else if (sst->base->is(IR_FLOATING_TYPE)) {
    // ****************************************************************************
    // Floating point subtype
    // ****************************************************************************
    str += "/** Floating point info class " + get_long_name(decl) + " */\n";
    vector<RangeDescriptor> range_desc = get_discrete_range(sst, rstack, IR_NOT_STATIC);
    // Check whether bounds and range direction could be determined at
    // compile time. Floating point types which static bounds are
    // defined globally.
    StaticRangeDescriptor<double, IR_Direction> range = 
      range_desc[0].rangedes_to_double (rstack);
    if (and_reduce(range.valid)) {
      // Integer info class definition with static bounds
      str += "class " + qid(decl, rstack, INFO) + ":public float_info_base{\n" +
	"public:\n" +
	"   " + qid(decl, rstack, INFO) + "():float_info_base(" + 
	to_string(range.left) + ","+ to_string(range.right) + "," + 
	to_string(min(range.left,range.right)) + "," + to_string(max(range.left, range.right)) + ") {};\n" + 
	"   static floatingpoint low() { return " + to_string(min(range.left, range.right)) + "; }\n" +
	"   static floatingpoint high() { return " + to_string(max(range.left, range.right)) + "; }\n" +
	"   static floatingpoint left() { return " + to_string(range.left) + "; }\n" +
	"   static floatingpoint right() { return " + to_string(range.right) + "; }\n" + 
	"};\n";
    } else {
      // Integer info class definition with non static bounds (i.e.,
      // the bounds must be calculated at runtime)
      str += "#define " + qid(decl, rstack, INFO) + " floating_info_base\n";
    }

  } else if (sst->base->is(IR_PHYSICAL_TYPE)) {
    // ****************************************************************************
    // Physical subtype
    // ****************************************************************************
    lint left, right;
    IR_Direction dir;
    vector<RangeDescriptor> range_desc = get_discrete_range(sst, rstack, IR_NOT_STATIC);
    // Check whether bounds and range direction could be determined at
    // compile time. Physical types which static bounds are defined
    // globally.
    StaticRangeDescriptor<lint, IR_Direction> range = 
      range_desc[0].rangedes_to_lint(rstack);
    if (and_reduce(range.valid)) {
      string base_info_str = get_type_info_obj(sst->base, rstack, false);
      // Integer info class definition with static bounds
      str +=
	"/** Physical type info class " + get_long_name(decl) + " */\n";
      str +=
	"struct " + qid(decl, rstack, INFO) + ":public physical_info_base{\n";

      if (sst->base->declaration == sst->declaration)
	{
	  // For a `primary' subtype, emit the base information as well.
	  str += "   static const char *units[];\n";
	  str += "   static const lint scale[];\n";
	  str += "   static const int unit_count;\n";
	  str += "   " +
	    qid(decl, rstack, INFO) + "():physical_info_base(" + 
	    to_string(range.left) + "LL,"+ to_string(range.right) + "LL," + 
	    to_string(min(range.left,range.right)) + "LL," + to_string(max(range.left, range.right)) +
	    "LL, units, scale, unit_count) {};\n";
	}
      else
	{
	  // For a genuine subtype, refer to the already existing base
	  // type.
	  str +=
	    "   " +
	    qid(decl, rstack, INFO) + "():physical_info_base(" + 
	    to_string(range.left) + "LL,"+ to_string(range.right) + "LL," + 
	    to_string(min(range.left,range.right)) + "LL," + to_string(max(range.left, range.right)) +
	    "LL," + base_info_str + "->units," + base_info_str + "->scale," +
	    base_info_str + "->unit_count) {};\n";
	}
      
      str +=
	"   static physical low() { return " + to_string(min(range.left, range.right)) + "LL; }\n" +
	"   static physical high() { return " + to_string(max(range.left, range.right)) + "LL; }\n" +
	"   static physical left() { return " + to_string(range.left) + "LL; }\n" +
	"   static physical right() { return " + to_string(range.right) + "LL; }\n" + 
	"};\n";
    } else {
      // Physical info class definition with non static bounds (i.e.,
      // the bounds must be calculated at runtime)
      str += "/** Physical type info class " + get_long_name(decl) + " */\n";
      str += "#define " + qid(decl, rstack, INFO) + " physical_info_base\n";
    }

  } else
    codegen_error.error("%:error: sorry, this subtype declaration is currently not supported", sst);

  // If the type shall be globally visible then add an external info
  // instance declaration
  if (static_declarative_region(sst) == RootDeclarativeRegion(rstack))
    str += "extern " + qid(decl, rstack, INFO) + " " + qid(decl, rstack, INFO) + "_INFO;\n";
}


void
m_emit_hdr (pIIR_PackageDeclaration p, string &str, RegionStack &rstack, int l)
{
  if (extended_declarations(p) != NULL)
    emit_decls(extended_declarations(p), str, rstack, l);
}


void
m_emit_hdr (pIIR_PackageBodyDeclaration pb, string &str, RegionStack &rstack, int l)
{
  if (extended_declarations(pb) != NULL)
    emit_decls(extended_declarations(pb), str, rstack, l);
}

void
m_emit_hdr (pIIR_TypeDeclaration d, string &str, RegionStack &rstack, int l)
{
  emit_hdr (d->type, str, rstack, l);
}


void
m_emit_hdr (pIIR_RecordType rt, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = rt->declaration;
  str += "/* Definitions for record type " + get_long_name(decl) + " */\n";
  // The derived info class is just a record_base!
  str += "#define " + qid(rt, rstack, INFO) + " record_info\n";

  // Define prototpye of a function to get pointer to record members
  str += "void *" + qid(rt, rstack, DEFAULT) + "_ELEM_ADDR(void*,int);\n";

  // The instance class makes use of a auxilliary struct which gets
  // the suffix "_DATA".
  string data_class = qid(rt, rstack, DEFAULT) + "_DATA";
  str += "struct " + data_class + " {\n";
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest)
    {
      str += ("  " + qid(edl->first->subtype, rstack, TYPE) +
	      " " + nid(edl->first, DEFAULT) + ";\n");
    }
  // Emit constructor for aggregates
  str += "  " + data_class + "(";
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest)
    {
      str += qid (edl->first->subtype, rstack, TYPE)
	+ " " + nid(edl->first, DEFAULT);
      if (edl->rest)
	str += ", ";
    }
  str += ") : \n";
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest)
    {
      str += "    " + nid(edl->first, DEFAULT) +
	"(" + nid(edl->first, DEFAULT) + ")";
      if (edl->rest)
	str += ",\n";
    }
  str += "\n    { }\n";
  // Emit default constructor
  str += "  " + data_class + "() { }\n";
  
  // Emit method to initialize record instance with default values
  str += "  void init(type_info_interface *rinfo) {\n";
  str += "    type_info_interface **einfos = ((record_info*)rinfo)->element_types;\n";
  int i = 0;
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest, i++)
    {
      pIIR_Type element_type = get_base_type(edl->first->subtype);
      string i_str = to_string(i);
      if (element_type->is(IR_INTEGER_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + "=((integer_info_base*)einfos[" + i_str + "])->left_bound;\n";
      else if (element_type->is(IR_FLOATING_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + "=((float_info_base*)einfos[" + i_str + "])->left_bound;\n";
      else if (element_type->is(IR_PHYSICAL_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + "=((physical_info_base*)einfos[" + i_str + "])->left_bound;\n";
      else if (element_type->is(IR_ENUMERATION_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + "=((enum_info_base*)einfos[" + i_str + "])->left_bound;\n";
      else if (element_type->is(IR_ACCESS_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + "=NULL;\n";
      else if (element_type->is(IR_RECORD_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + ".init(einfos[" + i_str + "]);\n";
      else if (element_type->is(IR_ARRAY_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + ".init(einfos[" + i_str + "]);\n";
    }
  str += "  };\n";

  // Emit method to initialize record instance with values obtained
  // from a reference record instance.
  str += "  void init(type_info_interface *rinfo, const void *p) {\n";
  str += "    type_info_interface **einfos = ((record_info*)rinfo)->element_types;\n";
  str += "    const " + data_class + " &src_data = *(" + data_class + "*)((const record_base *)p)->data;\n";
  i = 0;
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest, i++)
    {
      pIIR_Type element_type = get_base_type(edl->first->subtype);
      string einfo_str = "einfos[" + to_string(i) + "]"; 
      if (element_type->is(IR_RECORD_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + ".init(" + einfo_str + ",(const void*)&src_data." + nid(edl->first, DEFAULT) + ");\n";
      else if (element_type->is(IR_ARRAY_TYPE))
	str += "    " + nid(edl->first, DEFAULT) + ".init(" + einfo_str + ",(const void*)&src_data." + nid(edl->first, DEFAULT) + ");\n";
      else
	str += "    " + nid(edl->first, DEFAULT) + "=src_data." + nid(edl->first, DEFAULT) + ";\n";
    }
  str += "  };\n";

  str += "};\n";

  str += "#define " + qid(rt, rstack, TYPE)
    + " record_type" + "<" + data_class + ">\n";
  
  // If the type shall be globally visible then add an external info
  // instance declaration
  if (static_declarative_region(rt) == RootDeclarativeRegion(rstack))
    str += "extern record_info " + qid(rt, rstack, INFO) + "_INFO;\n";
}


void
m_emit_hdr (pIIR_RecordSubtype rst, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = rst->declaration;

  // Derive array type and array info from immediate base type

  // If the type shall be globally visible then add an external info
  // instance declaration
  if (static_declarative_region(rst) == RootDeclarativeRegion(rstack))
    str += "extern record_info " + qid(rst, rstack, INFO) + "_INFO;\n";
  str += "#define " + qid(rst, rstack, TYPE) + " " + qid(rst->immediate_base, rstack, TYPE) + "\n";
  str += "#define " + qid(rst, rstack, INFO) + " record_info\n\n";
}


void
m_emit_hdr (pIIR_Root r, string &str, RegionStack &rstack, int l)
{
  str += "/* No header for " + string(r->kind_name()) + " */\n";
}
