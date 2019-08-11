#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <math.h>
#include <limits.h>

#include <freehdl/vaul.h>
#include "v2cc-chunk.h"
#include "mapping.h"
#include "v2cc-util.h"

using namespace std;

// Used to generate error messages
extern vaul_error_printer codegen_error;


// Dummy filter function which does not filter out anything! This
// class is necessary to implement unfiltered filter_list operations.
struct no_filter {
  no_filter() {};
  no_filter(pIIR_Declaration d) {};
  operator bool() { return true; }
};


// This class is used to filter out interface declarations which are
// NOT an alias declaration!
struct filter_local_declarations {
  const pIIR_Declaration node;
  filter_local_declarations() : node(NULL) { }
  filter_local_declarations(pIIR_Declaration n) : node(n) { }
  operator bool() {
    if (node->is(IR_OBJECT_DECLARATION)) {
      return (!node->is(IR_INTERFACE_DECLARATION)) || (pIIR_ObjectDeclaration(node)->alias_base != NULL);
    } else
      return true;
  }
};


// Template function to create a copy of a interface or declaration
// list. Further, for each anonymous type used within the declarations
// a implicitly declaration entry is created and added to the list. T
// denotes the list type (either IIR_DeclarationList or
// IIR_InterfaceList).
template<class T, class F>
pIIR_DeclarationList
build_extended_declaration_list(T* list, RegionStack &rstack)
{
  // First, create a copy of the original list
  pIIR_DeclarationList new_list = filter_list<T, IIR_DeclarationList, F>(list);
  // Analyze each declaration included in the list
  //return new_list;
  for (pIIR_DeclarationList l = new_list, *last_rest_p = &new_list; l; last_rest_p = &l->rest, l = l->rest) {
    // Search for object declarations where the object type is an
    // implicity delcared subtype (e.g., "variable var : integer range
    // 0 to 7"). For this kind of anonymouse subtypes an implicit
    // named subtype declaration shall be created. 
    if (!l->first->is(IR_OBJECT_DECLARATION) ||
	!is_implicit_subtype(pIIR_ObjectDeclaration(l->first)->subtype))
      continue;
    // If the object is defined within a procedure or function that is
    // declared in a package, then do not create an explicit anonymous
    // type because this might generate initialization races if the
    // function/subrogram is used to initialize a constant of the
    // package! E.g., 

    // package race is
    //  function func return integer; 
    //  constant const : integer := func;
    // end package;
    // package body race is 
    //  function func return integer is 
    //   constant const2 : integer := const;
    //  begin 
    //   return const2;
    //  end func;
    // end package body;

    // In the C++ code the package body is elaborated AFTER the package
    // declaration. Hence, if const2 is initialized globally, if will
    // get its initial value too late!
    if (l->first->declarative_region->is(IR_SUBPROGRAM_DECLARATION) &&
	pIIR_SubprogramDeclaration (l->first->declarative_region)
	->declarative_region->is(IR_PACKAGE_BODY_DECLARATION))
      continue;
    pIIR_ObjectDeclaration object = pIIR_ObjectDeclaration(l->first);
    pIIR_Subtype implicit_subtype = pIIR_Subtype(pIIR_ObjectDeclaration(l->first)->subtype);
    // Skip this subtype if it is already associated with an implicit
    // subtype declaration.
    if (implicit_subtype_declaration(implicit_subtype) != NULL) 
      continue;
    // Create a unique name for the new implicit type
    // declaration. Note that this name is actually NOT a valid VHDL
    // subtype name.
    pIIR_TextLiteral new_subtype_name = to_TextLiteral("_t" + to_string(get_unique_int_id()));
    // Create an "implicit subtype declaration  node".
    pV2CC_ImplicitSubtypeDeclaration new_implicit_subtype_declaration = 
      new V2CC_ImplicitSubtypeDeclaration(l->pos, new_subtype_name, ActiveDeclarativeRegion(rstack), NULL, -1, implicit_subtype);
    // Link subtype node with the implicit subtype declaration!
    implicit_subtype_declaration(implicit_subtype) = new_implicit_subtype_declaration;
    // Create a new entry for the declaration list and put it before
    // the current declaration into the list.
    *last_rest_p = new IIR_DeclarationList(l->pos, new_implicit_subtype_declaration, l);
  }

  return new_list;
}


int
check_for_static_names(pIIR_Expression expr, IR_StaticLevel slevel, RegionStack &rstack)
{
  int error_count = 0;

  ContextInfo tmp_ctxt;
  // Determine all objects which are accessed in expr
  get_context(expr, tmp_ctxt, rstack, false, 0);

  // Analyze all accessed objects besides the primary name.
  for (list<AccessDescriptor>::iterator iter = tmp_ctxt.accessed_objects.begin();
       iter != tmp_ctxt.accessed_objects.end(); iter++)

    // Skip primary name
    if ((*iter).level > 0) {
      pIIR_Declaration decl = (*iter).declaration;

      // Check for function call. Check whether the result of the
      // function call matches the required static level.
      if (decl->is(IR_FUNCTION_DECLARATION)) {
	assert (((*iter).access_type & FUNCTION_CALL));
	pIIR_FunctionDeclaration fdecl = pIIR_FunctionDeclaration((*iter).declaration);
	if (!level_match((*iter).access_expr->static_level, slevel)) {
	  codegen_error.error("%:error: result of function %n is not %s static.", 
			      expr, (*iter).access_expr, 
			      (slevel == IR_LOCALLY_STATIC? "locally" : "globally"));
	  error_count++;
	}
	
	continue;
      }

      // Check for alias object. Bail out if locally static is
      // required.
      if (decl->is(IR_OBJECT_DECLARATION) &&
	  pIIR_ObjectDeclaration(decl)->alias_base != NULL && 
	  slevel == IR_GLOBALLY_STATIC)
	continue;

      // Check for constant object. If constant is deferred then
      // report an error if name shall be locally static.
      if (decl->is(IR_CONSTANT_DECLARATION))
	if (pIIR_ConstantDeclaration(decl)->initial_value != NULL ||
	    slevel == IR_GLOBALLY_STATIC)
	  continue;

      // Check for generic parameter. Bail out if name shall be
      // locally static
      if (decl->is(IR_CONSTANT_INTERFACE_DECLARATION) &&
	  slevel == IR_GLOBALLY_STATIC)
	continue;

      codegen_error.error("%:error: %n is not a %s static name as %n is not %s static.", 
			  expr, expr, (slevel == IR_LOCALLY_STATIC? "locally" : "globally"), 
			  decl, (slevel == IR_LOCALLY_STATIC? "locally" : "globally"));
      error_count++;
    }

  return error_count;
}


void
merge_accessed_objects_lists(list<AccessDescriptor> &target, 
			     pIIR_DeclarativeRegion target_region,
			     list<AccessDescriptor> &src)
{
  // Create a list of declarative region pointers beginning from the
  // target region up to the root region
  list<pIIR_DeclarativeRegion> RegionList = create_region_list(target_region);

  // Check accessed objects 
  for (list<AccessDescriptor>::iterator iter = src.begin(); iter != src.end(); iter++ ) {
    if ((*iter).declaration == NULL ||
	(!(*iter).declaration->is(IR_OBJECT_DECLARATION) &&  
	 !(*iter).declaration->is(IR_TYPE_DECLARATION))) continue;
    // Test whether the source region of the declared object is
    // included in the region list. I.e., check whether the object is
    // visible from the target scope
    pIIR_DeclarativeRegion obj_decl_region = (*iter).declaration->declarative_region;
    if (find(RegionList.begin(), RegionList.end(), obj_decl_region) != RegionList.end())
      // Add access descriptor to target context
      target.push_back(*iter);
  }
}

// Return the more `inner' one of R1 and R2.  This is used to
// determine the static region of an item that is known to be static
// in R1 and R2.

pIIR_DeclarativeRegion
max_inner (pIIR_DeclarativeRegion r1, pIIR_DeclarativeRegion r2, RegionStack &rstack)
{
  // Step up from R1 until hitting R2.  If we don't hit R2, R2 is more
  // `inner' than R1; else R1 is more inner than R2.

  // XXX - what about `continued' declarative regions?  Continued
  // declarative regions only occur on LibraryUnits (i.e. file scope),
  // and BlockConfigs.  We should be safe from LibraryUnits, at least.

  for (pIIR_DeclarativeRegion r = r1; r != NULL; r = get_parent_declarative_region(r, rstack)) {
    //cerr << r->kind_name() << " " << r2->kind_name() << endl;
    if (r == r2)
      return r1;
  }
  return r2;
}


/* Removes entries from the external declaration list which shall not
   be converted into "extern" declarations. */
void
cleanup_external_declaration_list (decl_flag_list &ext_decl_list)
{
  decl_flag_list::iterator iter = ext_decl_list.begin ();

  while (iter != ext_decl_list.end ())
    {
      pIIR_Declaration decl = iter->first;
      if (decl->is (IR_CONSTANT_INTERFACE_DECLARATION) ||
	  decl->is (IR_SIGNAL_INTERFACE_DECLARATION))
	{
	  iter = ext_decl_list.erase (iter);
	}
      else
	iter ++;
    }
}


// ******************************************************************************************
// Name: m_explore_and_check, generic function
//
// Description: explore (collect informations about node) and check
// node for correctness
//
// Return value: returns number of errors found
//
// ******************************************************************************************

int
m_explore_and_check (pIIR_InterfaceDeclaration id, RegionStack &rstack, bool collect_access_info)
{
  if (done(id) & EXPLORED) return 0; else  done(id) |= EXPLORED;

  int error_count = 0;
  ContextInfo &ctxt = *ActiveContext(rstack);

  error_count += explore_and_check(id->subtype, rstack, collect_access_info);

  if (id->initial_value &&
      id->initial_value->is(IR_EXPRESSION)) {
    if (collect_access_info) {
      get_context(id->initial_value, ctxt, rstack, false, 0);
      get_context(id->initial_value->subtype, ctxt, rstack, false, 0);
    }
    error_count += explore_and_check(id->initial_value->subtype, rstack, collect_access_info);
    error_count += constant_fold(id->initial_value, rstack);
    error_count += check_expression(id->initial_value, rstack);
  }

  return error_count;
}

int
m_explore_and_check (pIIR_PredefinedFunctionDeclaration sp,
		     RegionStack &rstack, bool collect_access_info)
{
  if (done(sp) & EXPLORED) return 0; else  done(sp) |= EXPLORED;
  
  rstack.push(sp);

  int error_count = 0;
  if (sp->interface_declarations != NULL) {
    extended_interface_declarations(sp) = clone_list<IIR_InterfaceList, IIR_DeclarationList>(sp->interface_declarations);
    error_count += explore_and_check(extended_interface_declarations(sp), rstack, collect_access_info);
  }

  rstack.pop();

  return error_count;
}



int
m_explore_and_check (pIIR_SubprogramDeclaration sp, RegionStack &rstack, bool collect_access_info)
{
  if (done(sp) & EXPLORED) return 0; else  done(sp) |= EXPLORED;

  rstack.push(sp);
  int error_count = 0;

  if (sp->interface_declarations != NULL) {
    if (sp->subprogram_body != NULL)
      extended_interface_declarations(sp) = 
	build_extended_declaration_list<IIR_InterfaceList, no_filter>(sp->interface_declarations, rstack);
    else
      extended_interface_declarations(sp) = clone_list<IIR_InterfaceList, IIR_DeclarationList>(sp->interface_declarations);
    error_count += explore_and_check(extended_interface_declarations(sp), rstack, collect_access_info);
  }

  if (sp->declarations != NULL) {
    // Build extended declaration list. However, any interface
    // decalrations which are usually also included in the declaration
    // list are NOT copied to the extended_declaration list! The class
    // filter_local_declarations implements a unary function which
    // performs the check operation for each item on the original
    // list.
    extended_declarations(sp) = 
      build_extended_declaration_list<IIR_DeclarationList, filter_local_declarations>(sp->declarations, rstack);
    // Because the extended_declaration list may be empty (in spite of
    // the original declaration list being NOT empty) check for empty
    // list again!
    if (extended_declarations(sp) != NULL)
      error_count += explore_and_check(extended_declarations(sp), rstack, collect_access_info);
  }
  
  if (sp->subprogram_body != NULL)
    error_count += explore_and_check(sp->subprogram_body, rstack, collect_access_info);

  if (sp->is(IR_FUNCTION_DECLARATION))
    error_count += explore_and_check(pIIR_FunctionDeclaration(sp)->return_type, rstack, collect_access_info);


  // **********************************************************************
  // Analyze all objects which were directly or indirectly referenced
  // within the subprogram code. Note that while in VHDL it is
  // permitted to directly access objects declared outside of the
  // subprogram code this cannot be directly mapped to C++. Hence,
  // these objects are passed over to the generated subprogram as
  // additional interface parameters.
  // **********************************************************************

  // Create a list of declarative region pointers beginning from the
  // father region of the subprogram up to (but not including) the
  // root region
  list<pIIR_DeclarativeRegion> RegionList = create_region_list(sp->declarative_region);
  // Remove any package regions and package body regions because these
  // objects will be globally declared and hence can be accessed
  // directly from the generated subprogram code.
  while (RegionList.begin() != RegionList.end() &&
	 is_PackageDeclarativeRegion(*RegionList.begin()))
    RegionList.pop_front();

  list<AccessDescriptor> &objects = context(sp).accessed_objects;
  list<AccessDescriptor> &extra_interface_objects = context(sp).extra_interface_objects;
  // Analyze all objects directly or indirectly accessed within the
  // subprogram
  for (list<AccessDescriptor>::iterator obj = objects.begin(); obj != objects.end(); obj++) {
    if ((*obj).declaration == NULL) continue;
    // Test whether the object is defined within predecessor region of
    // the current region
    list<pIIR_DeclarativeRegion>::iterator home_region = 
      find(RegionList.begin(), RegionList.end(), (*obj).declaration->declarative_region);
    if (home_region == RegionList.end()) continue;
    // Ok, obviously the current object has been accessed without
    // being passed over into the subprogram via the interface. Hence,
    // add it to the list of extra interface objects if the object is
    // not already on the list. Otherwise, merge the access types of
    // both entries.
    list<AccessDescriptor>::iterator old_entry = extra_interface_objects.begin(); 
    for (; old_entry != extra_interface_objects.end(); old_entry++)
      if ((*old_entry).declaration != NULL &&
	  (*old_entry).declaration == (*obj).declaration)
	break;
    // If a corresponding entry is already on the extra interface list
    // then merge access types. Otherwise, create a new entry. Note
    // that only the declaration pointer and the access type are stored
    // in the extra interface list.
    if (old_entry != extra_interface_objects.end())
      (*old_entry).access_type |= (*obj).access_type;
    else
      extra_interface_objects.push_back(AccessDescriptor(pIIR_ObjectDeclaration((*obj).declaration), 
							 NULL, (*obj).access_type));
  }

  // Check whether this is a procedure and a timeout clause
  // has been used directly or indirectly within the subprogram. If
  // yes, then add a signal driver as well as a reference to the
  // timeout variable as an extra parameter to the function,
  if (sp->is(IR_PROCEDURE_DECLARATION) && 
      has_wait_for(pIIR_ProcedureDeclaration(sp))) {
    pIIR_ProcedureDeclaration proc = pIIR_ProcedureDeclaration(sp);
    // First, create an 
    pV2CC_ImplicitSignalDeclaration_WaitFor implicit_signal = 
      new V2CC_ImplicitSignalDeclaration_WaitFor (sp->pos, to_TextLiteral("_implicit_wait_for"), sp, NULL, -1, 
						  NULL /* subtype */, NULL, NULL, IR_NO_SIGNAL_KIND); 
    // Add this to the list of extra interface objects. The signal
    // value is read, write, an signal function attribute is used and
    // the procedure is sensitive on it. This will cause the sig_info
    // pointer, a driver as well as the reader pointer passed over to
    // the subprogram.
    extra_interface_objects.push_back(AccessDescriptor(implicit_signal, NULL, 
						       READ | WRITE | SIGNAL_FUNCTION_ATTRIBUTE | SENSITIVE));

    // Also, add it to the extended_declarations list.
    //extended_declarations(sp) =
    // new IIR_DeclarationList (sp->pos, implicit_signal,
    //		       extended_declarations (sp));
  }
   

  // Finally, check whether the current procedure is an implicity
  // declared "deallocate" procedure. As the subprogram is decalared
  // implicitly there is no subprogram body. Further, the subprogram
  // is named "deallocate".
  string subprog_name = convert_string(sp->declarator->text.to_chars(), tolower);
  if (sp->is(IR_PREDEFINED_PROCEDURE_DECLARATION)) {
    // Remove any extra subprogram parameters
    extra_interface_objects.clear();
    if (subprog_name == "deallocate") {
      // Get the access type (= type of the parameter). Add type
      // declaration to extra interface list of procedure so that the
      // corresponding type info pointer is passed over to the
      // subprogram.
      pIIR_TypeDeclaration access_type_decl = get_declaration(sp->interface_declarations->first->subtype->base);
      extra_interface_objects.push_back(AccessDescriptor(access_type_decl, TYPE_USED));
    }
  } 

  if (sp->is(IR_PREDEFINED_FUNCTION_DECLARATION)) 
    // Remove any extra subprogram parameters
    extra_interface_objects.clear();

  rstack.pop();

  return error_count;
}


int
m_explore_and_check (pIIR_EntityDeclaration e, RegionStack &rstack, bool collect_access_info)
{
  if (done(e) & EXPLORED) return 0; else  done(e) |= EXPLORED;

  rstack.push(e);
  int error_count = 0;

  // Explore initial values of generics
  if (e->generic_clause != NULL) {
    extended_generic_clause(e) = build_extended_declaration_list<IIR_InterfaceList, no_filter>(e->generic_clause, rstack);
    error_count += explore_and_check(extended_generic_clause(e), rstack, collect_access_info);
  }
  
  // Explore initial values of port signals
  if (e->port_clause != NULL) {
    extended_port_clause(e) = build_extended_declaration_list<IIR_InterfaceList, no_filter>(e->port_clause, rstack);
    error_count += explore_and_check(extended_port_clause(e), rstack, collect_access_info);
  }
  
  // Explore entity declarations (not ports and generics; those are
  // handled above)
  if (e->declarations) {
    extended_declarations(e) = build_extended_declaration_list<IIR_DeclarationList, no_filter>(e->declarations, rstack);
    explore_and_check(extended_declarations(e), rstack, collect_access_info);
  }

  // Explore concurrent statements of entity
  if (e->entity_statement_part)
    explore_and_check(e->entity_statement_part, rstack, collect_access_info);

  // Collect all external delcarations into 
  if (collect_access_info)
    merge (external_decls_list, e->external_decls, rstack);

  // Also, explore and check all referenced external declarations
  if (e->external_decls != NULL)
    {
      explore_and_check (e->external_decls, rstack, true);
      cleanup_external_declaration_list (external_decls_list);
    }
  
  rstack.pop();

  return error_count;
}


// Note that this is NOT a generic function!
int
explore_and_check_alias (pIIR_ObjectDeclaration od, RegionStack &rstack, bool collect_access_info)
{
  int error_count = 0;
  ContextInfo &ctxt = *ActiveContext(rstack);
  
  if(collect_access_info)
    get_context(od->alias_base->subtype, ctxt, rstack, false, 0);
  error_count += explore_and_check(od->alias_base->subtype, rstack, collect_access_info);
  error_count += constant_fold(od->alias_base, rstack);
  error_count += check_expression(od->alias_base, rstack);

  // Determine final declarative region
  static_declarative_region(od) = 
    get_combined_static_region(static_declarative_region(od->alias_base->subtype),
			       static_declarative_region(od->alias_base), 
			       rstack);
  
  // The aliased object must denote a globally static name
  int sn_error_count =  check_for_static_names(od->alias_base, IR_GLOBALLY_STATIC, rstack);
  if (sn_error_count > 0) {
    codegen_error.error("%:error: aliased object name is not globally static.", od);
    error_count += sn_error_count;

    return error_count;
  }

  if (is_scalar_type(od->subtype)) {
    // ********************************************************************
    // The alias object is scalar!
    // ********************************************************************
    // If alias declaration is scalar then the subtype range and the
    // range of the aliased object must match
    lint alias_left, alias_right;
    IR_Direction alias_dir;
    vector<RangeDescriptor> range_alias = 
      get_discrete_range(od->subtype, rstack, IR_NOT_STATIC);
    error_count += range_alias[0].constant_fold_rangedes(rstack);
    StaticRangeDescriptor<lint, IR_Direction> alias_static_range =
      range_alias[0].rangedes_to_lint(rstack);

    vector<RangeDescriptor> range_aliased = 
      get_discrete_range(od->alias_base->subtype, rstack, IR_NOT_STATIC);
    error_count += range_aliased[0].constant_fold_rangedes(rstack);
    StaticRangeDescriptor<lint, IR_Direction> aliased_static_range =
      range_aliased[0].rangedes_to_lint(rstack);

    // Check whether the bounds and directions of the alias type and
    // the aliased type match. If the bounds are not static then
    // appropriate runtime code must be added to perform the check
    // operation.
    alias_check_bounds(od) = false;
    // Check left bound
    if (alias_static_range.valid[0] && aliased_static_range.valid[0]) {
      if (alias_static_range.left != aliased_static_range.left) {
	codegen_error.error("%:error: left bounds of alias (sub)type (=%i) and aliased (sub)type (=%i) do not match.", 
			    od, (int)alias_static_range.left, (int)aliased_static_range.left);
	error_count++;
      }
    } else
      alias_check_bounds(od) = true; // The bounds must be checked at runtime!

    // Check direction
    if (alias_static_range.valid[1] && aliased_static_range.valid[1]) {
      if (alias_static_range.dir != aliased_static_range.dir) {
	codegen_error.error("%:error: range directions of alias (sub)type (=%s) and aliased (sub)type (=%s) do not match.",
			    od, (alias_static_range.dir == IR_DIRECTION_UP? "to" : "downto"), 
			    (aliased_static_range.dir == IR_DIRECTION_UP? "to" : "downto"));
	error_count++;
      }
    } else
      alias_check_bounds(od) = true; // The bounds must be checked at runtime!

    // Check right bound
    if (alias_static_range.valid[2] && aliased_static_range.valid[2]) {
      if (alias_static_range.right != aliased_static_range.right) {
	codegen_error.error("%:error: right bounds of alias (sub)type (=%i) and aliased (sub)type (=%i) do not match.", 
			    od, (int)alias_static_range.right, (int)aliased_static_range.right);
	error_count++;
      }
    } else
      alias_check_bounds(od) = true; // The bounds must be checked at runtime!


  } else if (is_array_type(od->subtype)) {
    // ********************************************************************
    // The alias object is an array!
    // ********************************************************************

    // First, assume that the bounds must be checked at runtime
    alias_check_bounds(od) = true; 
    
    vector<RangeDescriptor> range_aliased;
    if (od->alias_base->is(IR_SLICE_REFERENCE))
      // If the aliased array is a slice then determine slice range
      range_aliased = get_discrete_range(od->alias_base, rstack, IR_NOT_STATIC);
    else
      // Otherwise determine range of array subtype
      range_aliased = get_discrete_range(od->alias_base->subtype, rstack, IR_NOT_STATIC);

    error_count += range_aliased[0].constant_fold_rangedes(rstack);
    // get_static_range should return only a single range
    // descriptor!
    assert(range_aliased.size() == 1); 
    // Determine value of bounds if range is static
    StaticRangeDescriptor<lint, IR_Direction> aliased_static_range = 
      range_aliased[0].rangedes_to_lint(rstack);
    lint aliased_length = -1; // First, set length to unknown
    // If bound and direction are static then determine length
    if ((od->alias_base->is(IR_SLICE_REFERENCE) ||
	 is_constrained_array_type (get_basic_type (od->alias_base->subtype))) && 
	and_reduce(aliased_static_range.valid)) 
      aliased_length = range_to_length(aliased_static_range.left, 
				       aliased_static_range.dir, 
				       aliased_static_range.right);
    
    // Next, determine alias range
    lint alias_length = -1; // First, set length to unknown

    // Is alias type a constrained array?
    if (is_constrained_array_type(od->subtype)) {
      // Ok, alias array is constrained. For this case try to
      // determine the length of the array and test whether it matches
      // the length of the aliased array.
      vector<RangeDescriptor> range_alias = 
	get_discrete_range(od->subtype, rstack, IR_NOT_STATIC);
      error_count += range_alias[0].constant_fold_rangedes(rstack);
      // get_static_range should return only a single range
      // descriptor!
      assert(range_alias.size() == 1); 
      // Determine value of bounds if range is static
      StaticRangeDescriptor<lint, IR_Direction> alias_static_range = 
	range_alias[0].rangedes_to_lint(rstack);
      // If bound and direction are static then determine length
      if (and_reduce(alias_static_range.valid)) 
	alias_length = range_to_length(alias_static_range.left, 
				       alias_static_range.dir, 
				       alias_static_range.right);
      
      if (aliased_length != -1 && alias_length != -1) {
	// If the length of the alias array and the aliased array
	// could be determined then check whether they are equal.
	if (aliased_length != alias_length) {
	  codegen_error.error("%:error: length of alias array (=%s) does not match length of aliased array (=%s).", 
			      od->subtype, to_string(alias_length).c_str(), 
			      to_string(aliased_length).c_str());
	  error_count++;
	} else
	  // If they are equal then no runtime checks must be done!
	  alias_check_bounds(od) = false;

      }
	
    } else {
      // If alias type is unconstrained then alias length and aliased
      // length are equal and no bounds checking must be done at
      // runtime.
      alias_length = aliased_length;
      alias_check_bounds(od) = false;
    }
    
  } else {
    // ********************************************************************
    // The alias object is a record!
    // ********************************************************************
    codegen_error.error("%:error: type %n is currently not supportd in alias declarations.", od->subtype);
    error_count++;
  }
      
  return error_count;
}

/* XXX - what if dlist is NULL, which is very legal for a list.  The
   type dispatching mechanism does not work for NULL.
*/

int
m_explore_and_check (pIIR_DeclarationList dlist, RegionStack &rstack, bool collect_access_info)
{
  if (done(dlist) & EXPLORED) return 0; else  done(dlist) |= EXPLORED;

  ContextInfo &ctxt = *ActiveContext(rstack);  
  int error_count = 0;

  for (pIIR_DeclarationList dl = dlist; dl; dl = dl->rest) {
    pIIR_Declaration d = dl->first;

    if (d->is(V2CC_INTERNAL_OBJECT_DECLARATION)) {
      continue;

    } else if (d->is(IR_OBJECT_DECLARATION)) {
      // Object declaration
      pIIR_ObjectDeclaration od = pIIR_ObjectDeclaration(d);

      if (collect_access_info)
	get_context(od->subtype, ctxt, rstack, false, 0);

      error_count += explore_and_check(od->subtype, rstack, collect_access_info);
      // Explore initial value of declarations
      if (od->initial_value &&
	  od->initial_value->is(IR_EXPRESSION)) {
	if (collect_access_info)
	  get_context(od->initial_value, ctxt, rstack, false, 0);
	error_count += constant_fold(od->initial_value, rstack);
	error_count += check_expression(od->initial_value, rstack);
	RuntimeCheckFlags runtime_checks; // Hack: currently no
	// runtime checks are performed for this case!
	error_count += 
	  check_for_target_type(d, od->subtype, od->initial_value,
				rstack, runtime_checks, true, 
				" illegal initial value:");
	// If the object is defined in a concurrent declaration
	// region, then the initial value is not allowed to contain
	// any signals!
	pIIR_DeclarativeRegion base_region = BaseDeclarativeRegion(rstack);
	if (base_region->is (IR_PACKAGE_DECLARATION) ||
	    base_region->is(IR_PACKAGE_BODY_DECLARATION) ||
	    base_region->is(IR_ARCHITECTURE_DECLARATION) ||
	    base_region->is(IR_ENTITY_DECLARATION))
	  {
	    // Ok, next collect all objects that are used within the
	    // intial value expression. From these objects extract the
	    // signals!
	    ContextInfo tmp_ctxt;
	    get_context(od->initial_value, tmp_ctxt, rstack, false, 0);
	    list<AccessDescriptor> sig_list =
	      filter_unique(tmp_ctxt.accessed_objects, ACCESS, 
			    tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));
	    for (list<AccessDescriptor>::iterator iter = sig_list.begin ();
		 iter != sig_list.end ();
		 iter++)
	      codegen_error.error("%:error: inital value of %n must not contain signals (%n).", 
				  od, od, iter->declaration);
	  }
      }
      // Check whether the current object has been created by an alias
      // declaration and check alias declaration.
      if (od->alias_base != NULL)
	error_count += explore_and_check_alias(od, rstack, collect_access_info);

      // Determine static declarative region
      if (od->is(IR_CONSTANT_DECLARATION) && 
	  pIIR_ConstantDeclaration(od)->initial_value != NULL) {
	pIIR_DeclarativeRegion r1;
	if (valid_folded_value(od->initial_value))
	  r1 = RootDeclarativeRegion(rstack);
	else if (static_declarative_region(od->initial_value) != NULL)
	  r1 = static_declarative_region(od->initial_value);
	else
	  r1 = od->declarative_region;
	static_declarative_region (od) =
	  max_inner (r1, static_declarative_region (od->subtype), rstack);

// 	if (od->declarator != NULL)
// 	  {
// 	    cout << "testing: " << od->declarator->text.to_chars() << endl;
// 	    cout << "valid_folded_value: " << valid_folded_value(od->initial_value) << endl;
// 	    cout << "r1: " << (int)r1 << endl;
// 	  }
// 	if (static_declarative_region (od) != NULL && 
// 	    static_declarative_region (od)->declarator != NULL)
// 	  cout << "static_declarative_region: " << static_declarative_region (od)->declarator->text.to_chars() << endl;

      } else if (od->is(IR_CONSTANT_INTERFACE_DECLARATION)) {
	static_declarative_region (od) = ActiveDeclarativeRegion(rstack);

      } else
	static_declarative_region(od) = NULL;
      
      if (d->is(IR_FILE_DECLARATION)) {
	// If d is a file declaration then check file mode and file name
	pIIR_FileDeclaration file_decl = pIIR_FileDeclaration(d);
	if (file_decl->file_open_expression != NULL) {
	  error_count += explore_and_check(file_decl->file_open_expression->subtype, rstack, collect_access_info);
	  error_count += constant_fold(file_decl->file_open_expression, rstack);
	  error_count += check_expression(file_decl->file_open_expression, rstack);
	}
	if (file_decl->file_logical_name != NULL) {
	  error_count += explore_and_check(file_decl->file_logical_name->subtype, rstack, collect_access_info);
	  error_count += constant_fold(file_decl->file_logical_name, rstack);
	  error_count += check_expression(file_decl->file_logical_name, rstack);
	}
      }
      
    } else if (d->is(IR_TYPE_DECLARATION)) {
      // **************************************************************************
      // A new type has been declared
      // **************************************************************************
      pIIR_TypeDeclaration tdecl = pIIR_TypeDeclaration(d);
      pIIR_Type type = tdecl->type;
      error_count += explore_and_check(tdecl->type, rstack, collect_access_info);
      // Determine combined declarative region
      static_declarative_region(tdecl) = static_declarative_region(tdecl->type);

    } else if (d->is(IR_SUBPROGRAM_DECLARATION)) {
      // **************************************************************************
      // Explore subprogram
      // **************************************************************************
      error_count += explore_and_check(d, rstack, collect_access_info);
      
    } else if (d->is(IR_COMPONENT_DECLARATION)) {
      // **************************************************************************
      // Explore component declaration
      // **************************************************************************
      pIIR_ComponentDeclaration comp = pIIR_ComponentDeclaration(d);

      for (pIIR_InterfaceList il = comp->local_generic_clause; il; il = il->rest) 
	error_count += explore_and_check(il->first, rstack, collect_access_info);

      for (pIIR_InterfaceList il = comp->local_port_clause; il; il = il->rest) 
	error_count += explore_and_check(il->first, rstack, collect_access_info);

    }
  }

  return error_count;
}



int
m_explore_and_check (pIIR_Type st, RegionStack &rstack, bool collect_access_info)
{
  if (done(st) & EXPLORED) return 0; else  done(st) |= EXPLORED;

  int error_count = constant_fold(st, rstack);

  // Determine combined declarative region
  static_declarative_region(st) = RootDeclarativeRegion(rstack);

  return error_count;
}

int
m_explore_and_check (pIIR_RecordType rt, RegionStack &rstack, bool collect_access_info)
{
  if (done(rt) & EXPLORED) return 0; else  done(rt) |= EXPLORED;

  int error_count = 0;

  static_declarative_region(rt) = RootDeclarativeRegion(rstack);

  // Explore and check types of record elements.  If any element type
  // is not static in the RootDeclarativeRegion, put the record type
  // into the TopDeclarativeRegion.

  // XXX - the above is not done yet since type declarations except in
  // the RootDeclarativeRegion do not work.

  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest)
    {
      error_count += explore_and_check (edl->first->subtype, rstack,
					collect_access_info);
#if 0 // XXX - see above
      if (static_declarative_region (edl->first->subtype)
	  != RootDeclarativeRegion (rstack))
	static_declarative_region (rt) = TopDeclarativeRegion (rstack);
#endif
    }

  error_count += constant_fold(rt, rstack);

  // Determine combined declarative region

  return error_count;
}

int
m_explore_and_check (pIIR_ArrayType at, RegionStack &rstack, bool collect_access_info)
{
  if (done(at) & EXPLORED) return 0; else  done(at) |= EXPLORED;

  int error_count = explore_and_check(at->element_type, rstack, collect_access_info); 
  for (pIIR_TypeList tl = at->index_types; tl; tl = tl->rest)
    error_count += explore_and_check(tl->first, rstack, collect_access_info);
    
  error_count += constant_fold(at, rstack);

  // Determine combined declarative region
  static_declarative_region(at) = RootDeclarativeRegion(rstack);

  return error_count;
}


int
m_explore_and_check (pIIR_ArraySubtype sst, RegionStack &rstack, bool collect_access_info)
{
  if (done(sst) & EXPLORED) return 0; else  done(sst) |= EXPLORED;
  
  int error_count = explore_and_check(get_base_type(sst), rstack, collect_access_info);
  if (sst->resolution_function != NULL)
    error_count += explore_and_check (sst->resolution_function, rstack, collect_access_info);

  error_count += constant_fold(sst, rstack);

  // Determine combined declarative region
  static_declarative_region(sst) = RootDeclarativeRegion(rstack);

  // Explore and check immediate base type. If the element type is
  // locally defined then the subtype will be declared locally as well
  error_count += explore_and_check(sst->immediate_base, rstack, collect_access_info);
  if (static_declarative_region(sst->immediate_base) != RootDeclarativeRegion(rstack))
    static_declarative_region(sst) = BaseDeclarativeRegion(rstack);

  // Check contraints. If at least one of the contraints includes
  // bounds which cannot be determined a compile time then the array
  // subtype must be declared locally.
  pIIR_Type base_type = get_basic_type(sst->immediate_base);
  pIIR_TypeList target_tl = base_type->is(IR_ARRAY_SUBTYPE)? 
    pIIR_ArraySubtype(base_type)->constraint : pIIR_ArrayType(base_type)->index_types;
  pIIR_TypeList tl = sst->constraint;
  for (; tl; tl = tl->rest, target_tl = target_tl->rest) {
    error_count += explore_and_check(tl->first, rstack, collect_access_info);
    if (static_declarative_region(tl->first) != RootDeclarativeRegion(rstack))
      static_declarative_region(sst) = BaseDeclarativeRegion(rstack);

    // Check bounds
    vector<RangeDescriptor> range_desc = 
      get_discrete_range(tl->first, rstack, IR_NOT_STATIC);
    StaticRangeDescriptor<lint, IR_Direction> static_range = 
      range_desc[0].rangedes_to_lint(rstack);

    // Check left bound
    if (static_range.valid[0]) {
      // rt_checks stores information on what checks must be done at runtime
      RuntimeCheckFlags rt_checks; 
      error_count += check_scalar_against_bounds(sst, static_range.left, target_tl->first, rstack, rt_checks, 
						 true, " array index range out of bounds:");
      // If the left index could not be verified against the array
      // bounds of the base type then the checks must be done at
      // compile time
      if (rt_checks) 
	runtime_checks(tl->first) |= RT_CHECK_LEFT_ARRAY_BOUND;
    } else
      runtime_checks(tl->first) |= RT_CHECK_LEFT_ARRAY_BOUND;

    // Check right bound
    if (static_range.valid[2]) {
      // rt_checks stores information on what checks must be done at runtime
      RuntimeCheckFlags rt_checks;
      error_count += check_scalar_against_bounds(sst, static_range.right, target_tl->first, rstack, rt_checks, 
						 true, " array index range out of bounds:");
      // If the left index could not be verified against the array
      // bounds of the base type then the checks must be done at
      // compile time
      if (rt_checks) 
	runtime_checks(tl->first) |= RT_CHECK_RIGHT_ARRAY_BOUND;
    } else
      runtime_checks(tl->first) |= RT_CHECK_RIGHT_ARRAY_BOUND;
  }

  return error_count;
}


int
m_explore_and_check (pIIR_Subtype st, RegionStack &rstack, bool collect_access_info)
{
  if (done(st) & EXPLORED) return 0; else  done(st) |= EXPLORED;

  int error_count = 0;
  if (st->immediate_base != NULL)
    error_count += explore_and_check (st->immediate_base, rstack, collect_access_info);
  
  if (st->resolution_function != NULL)
    error_count += explore_and_check (st->resolution_function, rstack, collect_access_info);
  
  return error_count;
}


int
m_explore_and_check (pIIR_ScalarSubtype sst, RegionStack &rstack, bool collect_access_info)
{
  if (done(sst) & EXPLORED) return 0; else  done(sst) |= EXPLORED;
  
  int error_count = 0;

  // First, explore the type the current subtype has been derived
  // from
  if (sst->immediate_base != NULL)
    error_count += explore_and_check (sst->immediate_base, rstack, collect_access_info);
  if (sst->resolution_function != NULL)
    error_count += explore_and_check (sst->resolution_function, rstack, collect_access_info);

  error_count += constant_fold(sst, rstack);

  pIIR_Type basic_type = get_basic_type(sst->immediate_base);
  vector<RangeDescriptor> range_desc = get_discrete_range(sst, rstack, IR_NOT_STATIC);
  
  // Determine combined declarative region
  static_declarative_region(sst) = RootDeclarativeRegion(rstack);

  // Test whether the scalar subtype is constrained
  if (sst->range == NULL) {
    
  } else if (sst->base->is(IR_ENUMERATION_TYPE) ||
	     sst->base->is(IR_INTEGER_TYPE) ||
	     sst->base->is(IR_PHYSICAL_TYPE)) {
    // ****************************************************************************
    // Enumeration, integer or physical subtype
    // ****************************************************************************
    StaticRangeDescriptor<lint, IR_Direction> range = range_desc[0].rangedes_to_lint(rstack);
    // Check left bound
    if (range.valid[0])
      error_count += check_scalar_against_bounds(sst, range.left, basic_type, rstack, runtime_checks(sst), true);
    else
      runtime_checks(sst) |= RT_CHECK_LEFT_BOUND;
    // Check right bound
    if (range.valid[2])
      error_count += check_scalar_against_bounds(sst, range.right, basic_type, rstack, runtime_checks(sst), true);
    else
      runtime_checks(sst) |= RT_CHECK_RIGHT_BOUND;
    // If bounds are not static then the type info object must be
    // declared locally
    if (!and_reduce(range.valid))
      static_declarative_region(sst) = BaseDeclarativeRegion(rstack);
    
  } else if (sst->base->is(IR_FLOATING_TYPE)) {
    // ****************************************************************************
    // Floatingpoint subtype
    // ****************************************************************************
    StaticRangeDescriptor<double, IR_Direction> range = range_desc[0].rangedes_to_double(rstack);
    // Check left bound
    if (range.valid[0])
      error_count += check_scalar_against_bounds(sst, range.left, basic_type, rstack, runtime_checks(sst), true);
    else
      runtime_checks(sst) |= RT_CHECK_LEFT_BOUND;
    // Check right bound
    if (range.valid[2])
      error_count += check_scalar_against_bounds(sst, range.right, basic_type, rstack, runtime_checks(sst), true);
    else
      runtime_checks(sst) |= RT_CHECK_RIGHT_BOUND;
    // If bounds are not static then the type info object must be
    // declared locally
    if (!and_reduce(range.valid))
      static_declarative_region(sst) = BaseDeclarativeRegion(rstack);
    
  } else {
    codegen_error.error("%:error: sorry, this subtype declaration is currently not supported", sst);
    error_count++;
  }

  return error_count;
}


int
m_explore_and_check (pIIR_EnumerationType et, RegionStack &rstack, bool collect_access_info)
{
  if (done(et) & EXPLORED) return 0; else  done(et) |= EXPLORED;

  int enum_count = 0, error_count = 0;

  // Count number of elements
  for (pIIR_EnumerationLiteralList ell = et->enumeration_literals; ell; ell = ell->rest) {
    error_count += constant_fold(ell->first, rstack);
    enum_count++;
  }
  // And store result into node structure
  enum_item_number(et) = enum_count;
  // Determine combined declarative region
  static_declarative_region(et) = RootDeclarativeRegion(rstack);

  return error_count;
}


int
m_explore_and_check (pIIR_FileType ft, RegionStack &rstack, bool collect_access_info)
{
  if (done(ft) & EXPLORED) return 0; else  done(ft) |= EXPLORED;

  int error_count = explore_and_check(ft->type_mark, rstack, collect_access_info);
  // Determine combined declarative region
  static_declarative_region(ft) = static_declarative_region(ft->type_mark);

  return error_count;
}


int
m_explore_and_check (pIIR_AccessType at, RegionStack &rstack, bool collect_access_info)
{
  if (done(at) & EXPLORED) return 0; else  done(at) |= EXPLORED;

  int error_count = explore_and_check(at->designated_type, rstack, collect_access_info);
  // Determine combined declarative region
  static_declarative_region(at) = static_declarative_region(at->designated_type);
  
  return error_count;
}


int
m_explore_and_check (pIIR_ArchitectureDeclaration a, RegionStack &rstack, bool collect_access_info)
{
  if (done(a) & EXPLORED) return 0; else  done(a) |= EXPLORED;

  rstack.push(a->entity);
  rstack.push(a);
  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  // Explore architecture declarations 
  if (a->declarations != NULL) {
    extended_declarations(a) = build_extended_declaration_list<IIR_DeclarationList, no_filter>(a->declarations, rstack);
    error_count = explore_and_check(extended_declarations(a), rstack, collect_access_info);
  }

  // Explore concurrent statements of entity
  error_count += explore_and_check(a->architecture_statement_part, rstack, collect_access_info);

  // Collect all external declarations into 
  merge (external_decls_list, a->external_decls, rstack);

  // Also, explore and check all referenced external declarations
  if (a->external_decls != NULL)
    {
      explore_and_check (a->external_decls, rstack, true);
      cleanup_external_declaration_list (external_decls_list);
    }
  
  rstack.pop();
  rstack.pop();

  return error_count; // Return number of errors
}


int
m_explore_and_check (pIIR_ConcurrentStatementList csl, RegionStack &rstack, bool collect_access_info)
{
  if (done(csl) & EXPLORED) return 0; else  done(csl) |= EXPLORED;

  int error_count = 0;

  while (csl)
    {
      error_count += explore_and_check (csl->first, rstack, collect_access_info);  
      csl = csl->rest;
    }

  return error_count;
}


int
m_explore_and_check (pIIR_ProcessStatement p, RegionStack &rstack, bool collect_access_info)
{
  if (done(p) & EXPLORED) return 0; else  done(p) |= EXPLORED;

  int error_count = 0;
  // Check whether a name has been associated with the process 
  if (p->declarator == NULL) {
    // If the process has no name then create a default name
    string process_name = "_" + to_string(p->seqno) + process_default_postfix;
    p->declarator = new IIR_TextLiteral(0, process_name.c_str());
  }

  rstack.push(p);
  ContextInfo &ctxt = *ActiveContext(rstack);

  // if the process has a sensitivity list then a virtual wait
  // statement is created in order to setup a corresponding wait_info
  // instance. Further, some info about the sensitvity list must be
  // collected.
  pIIR_WaitStatement implicit_ws = NULL;
  if (p->is(IR_SENSITIZED_PROCESS_STATEMENT)) {
    // Add a virtual wait statement
    pIIR_SensitizedProcessStatement sp = (pIIR_SensitizedProcessStatement)p;
    // Constant-Fold on sensitivity list
    error_count += constant_fold(sp->sensitivity_list, rstack);
    implicit_ws = new IIR_WaitStatement(p->pos, NULL, NULL, NULL, sp->sensitivity_list);
    error_count += explore_and_check(implicit_ws, rstack, collect_access_info);
    // get_context(ws, ctxt, rstack, false, 0);
  }

  // Explore local declarations of process
  if (p->declarations != NULL) {
    extended_declarations(p) = build_extended_declaration_list<IIR_DeclarationList, no_filter>(p->declarations, rstack);
    error_count += explore_and_check(extended_declarations(p), rstack, collect_access_info);
  }

  // explore and check sequential statements
  if (p->process_statement_part != NULL)
    error_count += explore_and_check(p->process_statement_part, rstack, collect_access_info);

  // If process has a sensitivity list then check whether no wait
  // statements are directly and indrectly included in the process
  // statement part.
  if (p->is(IR_SENSITIZED_PROCESS_STATEMENT))
    {
      bool start_message_printed = false;
      // If there is more than a single wait statement, then bail out!
      if (ctxt.wait_statements.size() > 1) {
	// List all offending waits. However, do not list the implicit
	// wait statement created by the code generator.  Further,
	// check out whether the process calls procedures that contain
	// at least one wait statement. First, get get all procedure
	// that are called from this process.
	codegen_error.error("%:error: process has a sensitivity list and also contains wait statements (directly or via a procedure call). The offending wait statements (procedure calls) are:", p);
	for (list<pIIR_SequentialStatement>::iterator i = ctxt.wait_statements.begin(); 
	     i != ctxt.wait_statements.end(); i++)
	  if ((*i) != implicit_ws)
	    if ((*i)->is (IR_WAIT_STATEMENT))
	      {
		codegen_error.error("%:error: offending wait statement in process with sensitivity list.", (*i));
		error_count++; 
	      }
	    else if ((*i)->is (IR_PROCEDURE_CALL_STATEMENT))
	      {
		pIIR_ProcedureCallStatement subprog_call =
		  pIIR_ProcedureCallStatement (*i);
		codegen_error.error("%:error: offending procedure %n contains (directly or indirectly) a wait statement.", 
				    *i, subprog_call->procedure);
		error_count++;
	      }
      }
    }

  // ******************************************************************
  // Add implicit "wait for" signal if necessary
  // ******************************************************************
  if (has_wait_for(p)) {
    // If at least one wait statement inlcudes an timeout clause add
    // in implicit signal to the delcaration list. This signal is
    // required in order to implement the timeout clause.
    pV2CC_ImplicitSignalDeclaration_WaitFor implicit_signal = 
      new V2CC_ImplicitSignalDeclaration_WaitFor (p->pos, to_TextLiteral("_implicit_wait_for"), p, NULL, -1, 
						  NULL /* subtype */, NULL, NULL, IR_NO_SIGNAL_KIND); 
    extended_declarations(p) = new IIR_DeclarationList(p->pos, implicit_signal, extended_declarations(p));
    // Assume that the signal is also written so that a driver is
    // created for this signal!
    ctxt.accessed_objects.push_back(AccessDescriptor(implicit_signal, NULL, READ | WRITE | SENSITIVE));
  }

  rstack.pop();
  
  return error_count;
}




int
m_explore_and_check (pIIR_PackageDeclaration p, RegionStack &rstack, bool collect_access_info)
{
  if (done(p) & EXPLORED) return 0; else  done(p) |= EXPLORED;

  rstack.push(p);

  if (p->declarations) {
    extended_declarations(p) = build_extended_declaration_list<IIR_DeclarationList, no_filter>(p->declarations, rstack);
    explore_and_check(extended_declarations(p), rstack, collect_access_info);
  }

  // Collect all external delcarations into 
  if (collect_access_info)
    merge (external_decls_list, p->external_decls, rstack);

  // Also, explore and check all referenced external declarations
  if (p->external_decls != NULL)
    {
      explore_and_check (p->external_decls, rstack, true);
      cleanup_external_declaration_list (external_decls_list);
    }
  
  rstack.pop();

  return 0; // Flag no errors found
}

int
m_explore_and_check (pIIR_PackageBodyDeclaration pb, RegionStack &rstack, bool collect_access_info)
{
  if (done(pb) & EXPLORED) return 0; else  done(pb) |= EXPLORED;

  rstack.push(pb);

  if (pb->declarations) {
    extended_declarations(pb) = build_extended_declaration_list<IIR_DeclarationList, no_filter>(pb->declarations, rstack);
    explore_and_check(extended_declarations(pb), rstack, collect_access_info);
  }

  // Collect all external delcarations into 
  if (collect_access_info)
    merge (external_decls_list, pb->external_decls, rstack);
  
  // Also, explore and check all referenced external declarations
  if (pb->external_decls != NULL)
    {
      explore_and_check (pb->external_decls, rstack, true);
      cleanup_external_declaration_list (external_decls_list);
    }
  
  rstack.pop();

  return 0; // Flag no errors found
}


int
m_explore_and_check (pIIR_ConfigurationDeclaration c, RegionStack &rstack, bool collect_access_info)
{
  if (done(c) & EXPLORED) return 0; else  done(c) |= EXPLORED;

  rstack.push(c);

  // Collect all external delcarations into 
  if (collect_access_info)
    merge (external_decls_list, c->external_decls, rstack);

  // Also, explore and check all referenced external declarations
  if (c->external_decls != NULL)
    {
      explore_and_check (c->external_decls, rstack, true);
      cleanup_external_declaration_list (external_decls_list);
    }
  
  rstack.pop();

  return 0; // Flag no errors found
}

int
m_explore_and_check (pIIR_ComponentDeclaration c, RegionStack &rstack, bool collect_access_info)
{
  if (done(c) & EXPLORED) return 0; else  done(c) |= EXPLORED;

  return 0; // Flag no errors found
}


int
m_explore_and_check(pIIR_SequentialStatementList sl, RegionStack &rstack, bool collect_access_info)
{
  if (done(sl) & EXPLORED) return 0; else  done(sl) |= EXPLORED;

  int error_count = 0;

  while (sl)
    {
      error_count += explore_and_check(sl->first, rstack, collect_access_info);
      sl = sl->rest;
    }

  return error_count; // Flag no errors found
}



// Function to check a statement where the selection expression is scalar
int
explore_and_check_scalar_case_statement(pIIR_CaseStatement cs, RegionStack &rstack, bool collect_access_info)
{
  int error_count = 0, choice_error_count = 0;

  // Get basic type of choice expression. I.e., any subtypes which
  // only add a resolution function to a type are ignored.
  pIIR_Type basic_type = get_basic_type(cs->expression->subtype);
  
  // First, determine bounds of type
  vector<RangeDescriptor> range_desc = 
    get_discrete_range(cs->expression->subtype, rstack, IR_LOCALLY_STATIC);
  // Determine not static range and check whether both ranges are
  // the same
  vector<RangeDescriptor> not_static_range_desc = 
    get_discrete_range(cs->expression->subtype, rstack, IR_NOT_STATIC);
  
  if (!range_desc[0].is_equal_to(not_static_range_desc[0])) {
    // If both ranges are NOT the same then print a notification if
    // desired. Further, the range is determined from the base type.
    range_desc = get_discrete_range(basic_type, rstack, IR_LOCALLY_STATIC);
    // Note the following message is NOT an error. It's just a hint
    // for the user that the actual range which must be covered by
    // the case statement might be "unexpected".
    StaticRangeDescriptor<string, string> range =
      range_desc[0].rangedes_to_string(rstack, DEFAULT);
    
    codegen_error.error("%:note: range of (sub)type %n is not locally static.", cs, cs->expression->subtype);
    codegen_error.error("%:note: determining locally static range from base type...", cs);
    codegen_error.error("%:note: ...static range is %s %s %s.", 
			cs, range.left.c_str(), range.dir.c_str(), range.right.c_str());
  }
  
  // Convert range to ints
  error_count += range_desc[0].constant_fold_rangedes(rstack);
  StaticRangeDescriptor<lint, IR_Direction> range =
    range_desc[0].rangedes_to_lint(rstack);
  
  lint lower_type_bound = min (range.left, range.right); // Lower bound of expression type
  lint upper_type_bound = max (range.left, range.right); // Upper bound of expression type
  bool to_type_range = range.left < range.right;
  // Number of discrete items 
  lint item_type_count = upper_type_bound - lower_type_bound + 1; 
  lint item_count = 0;
  
  // Now analyze each alternative
  vector<lint> lower_vec; // Stores lower bounds of choices
  vector<lint> upper_vec; // Stores upper bounds of choices
  vector<pIIR_Choice> choice_vec; // Points to associated choice expression
  // with lower_vec and upper_vec
  for (pIIR_CaseStatementAlternativeList al = cs->case_statement_alternatives; al; al = al->rest) {
    pIIR_CaseStatementAlternative a = al->first;
    
    // Analyze choices
    for (pIIR_ChoiceList cl = a->choices; cl; cl = cl->rest) {
      
      if (cl->first->is(IR_CHOICE_BY_RANGE)) {
	//***************************************
	// Choice by range
	//***************************************
	
	pIIR_ChoiceByRange cbr = pIIR_ChoiceByRange(cl->first);
	
	// Constant fold choice expression
	error_count += constant_fold(cbr->range, rstack);
	
	// Get choice range. Note that choice must be locally static
	StaticRangeDescriptor<lint, IR_Direction> range;
	IR_Direction dir = IR_DIRECTION_UP;
	// Get range. Note that range_desc is empty if range is not
	// locally static!
	vector<RangeDescriptor> range_desc = get_discrete_range(cbr->range, rstack, IR_LOCALLY_STATIC);
	if (range_desc.size() == 0) {
	  codegen_error.error("%:error: choice %n is not locally static.", cbr->range, cbr->range);
	  choice_error_count++;
	} else {
	  // convert string values to long long ints
	  range = range_desc[0].rangedes_to_lint(rstack);
	}
	
	lint lower, upper;
	if (range.left == range.right) {
	  lower = range.left;
	  upper = range.right;
	} else if (range.left < range.right && range.dir == IR_DIRECTION_UP) {
	  lower = range.left;
	  upper = range.right;
	} else if (range.left > range.right && range.dir != IR_DIRECTION_UP) {
	  lower = range.right;
	  upper = range.left;
	}

	// Check whether choice is unique
	for (int i = 0; i < lower_vec.size(); i++) {
	  if ((lower <= lower_vec[i] && upper >= lower_vec[i]) ||
	      (lower <= upper_vec[i] && upper >= upper_vec[i])) {
	    if (choice_vec[i]->is(IR_CHOICE_BY_RANGE))
	      codegen_error.error("%:error: choice %n (line %i) conflicts with %n (line %i).", 
				  cbr, cbr->range, get_line_number(cbr->range),
				  pIIR_ChoiceByRange(choice_vec[i])->range, 
				  get_line_number(choice_vec[i]));
	    else
	      codegen_error.error("%:error: choice %n (line %i) conflicts with %n (line %i).", 
				  cbr, cbr->range, get_line_number(cbr->range),
				  pIIR_ChoiceByExpression(choice_vec[i])->value,
				  get_line_number(choice_vec[i]));
	    choice_error_count++;
	  }
	}
	
	// Add bounds to vectors 
	lower_vec.push_back(lower);
	upper_vec.push_back(upper);
	choice_vec.push_back(cbr);
	// Update item counter
	item_count += upper - lower + 1;
	
      } else if (cl->first->is(IR_CHOICE_BY_EXPRESSION)) {
	//***************************************
	// Choice by expression
	//***************************************
	
	lint value;
	pIIR_ChoiceByExpression cbe = pIIR_ChoiceByExpression(cl->first);
	
	// Constant fold choice expression
	error_count += constant_fold(cbe->value, rstack);
	
	// Choice must be locally static
	if (cbe->value->static_level != IR_LOCALLY_STATIC) {
	  codegen_error.error("%:choice %n (%p) is not locally static.", 
			      cl->first, cbe->value, cbe->value);
	  choice_error_count++;
	  value = lower_type_bound;
	} else
	  value = folded_value(cbe->value).long_value();
	
	// Check whether the value is within the type bounds
	if (value < lower_type_bound || value > upper_type_bound) {
	  codegen_error.error("%:choice %n is not within bounds of type %n.", 
			      cbe->value, cbe->value, cs->expression->subtype);
	  choice_error_count++;
	}
	
	// Check whether choice is unique
	for (int i = 0; i < lower_vec.size(); i++) {
	  if (value >= lower_vec[i] && value <= upper_vec[i]) {
	    codegen_error.error("%:choice %n (line %i) conflicts with %n (line %i).", 
				cbe->value, cbe->value, get_line_number(cbe->value), 
				choice_vec[i], get_line_number(choice_vec[i]));
	    choice_error_count++;
	  }
	}
	
	// Add bounds to vectors 
	lower_vec.push_back(value);
	upper_vec.push_back(value);
	choice_vec.push_back(cbe);
	// A single element was specified. Hence, increment item counter.
	item_count++;
	
      } else if (cl->first->is(IR_CHOICE_BY_OTHERS)) {
	//***************************************
	// Choice by others
	//***************************************
	
	// Check whether the others choice is last alternative in
	// choice list
	if (cl->rest != NULL || al->rest != NULL || al->first->choices != cl) {
	  codegen_error.error("%:others choice must be a single last alternative in choice list.", cl->first);
	  choice_error_count++;
	}
	// Ok, due to the others statement all discrete items of the
	// type are covered. Hence, set item_count to the number of
	// elements the expression type consists of
	item_count = item_type_count;
      }
    }
    
    if (a->sequence_of_statements != NULL)
      // Analyze sequential statements associated with alternative
      error_count += explore_and_check(a->sequence_of_statements, rstack, collect_access_info);
    
    }
  
  // Update error counter
  error_count += choice_error_count;
  
  // Check whether all items are covered by the choices
  if (choice_error_count != 0) {
    // If the choices contained errors then no choice coverage
    // checking is done but we warn the user.
    codegen_error.info("%:warning: no choice coverage checking is done due to previous errors.", cs);

  } else if (item_count != item_type_count) {
    // Not all items are covered! 
    
    // Determine missing choices and output some useful error
    // messages
    sort(lower_vec.begin(), lower_vec.end());
    sort(upper_vec.begin(), upper_vec.end());
    vector<lint> missing_lower, missing_upper;
    lint search_bound = lower_type_bound;
    // Determine missing ranges
    for (int i = 0; i < lower_vec.size(); i++) {
      if (search_bound < lower_vec[i]) {
	missing_lower.push_back(search_bound);
	missing_upper.push_back(lower_vec[i] - 1);
      }
      search_bound = upper_vec[i] + 1;
    }
    if (search_bound <= upper_type_bound) {
      missing_lower.push_back(search_bound);
      missing_upper.push_back(upper_type_bound);
    }
    // Generate error message string reporting the missing ranges
    string error_str;
    bool first = true;
    pIIR_Type base_type = get_base_type(cs->expression->subtype);
    for (int i = 0; i < missing_lower.size(); i++, first = false) {
      string low_value;
      string high_value;
      if (base_type->is(IR_ENUMERATION_TYPE)) {
	// If expression is an enumeration type then convert
	// position numbers into appropriate strings
	low_value = pos_to_literal(pIIR_EnumerationType(base_type)->enumeration_literals, (int)missing_lower[i])
	  ->declarator->text.to_chars();
	high_value = pos_to_literal(pIIR_EnumerationType(base_type)->enumeration_literals, (int)missing_upper[i])
	  ->declarator->text.to_chars();
      } else {
	// If expression is an integer type then convert integer
	// values to strings
	low_value = to_string((int)missing_lower[i]);
	high_value = to_string((int)missing_upper[i]);
      }
      if (missing_lower[i] == missing_upper[i])
	error_str += (first?"":", ") + low_value;
      else
	error_str += (first?"":", ") + 
	  (to_type_range? low_value + " to " + high_value : high_value + " downto " + low_value);
    }
    
    codegen_error.error("%:error: not all possible values of type %n are covered by the case statement.", 
			cs, cs->expression->subtype);
    codegen_error.error("%:error: missing element(s): %s.", cs, error_str.c_str());
    error_count++;      
  }
  
  return error_count; // We are done. Return number of errors found
}


// Converts an array literal string passed over as a vector of
// enumeration pos values into a corresponding string
string
array_literal_to_string(pIIR_EnumerationType etype, vector<int> &vec)
{
  string pattern_str = "\"";
  for (int i = 0; i < vec.size(); i++)
    pattern_str += 
      pos_to_literal(etype->enumeration_literals, vec[i])->declarator->text.to_chars()[1];
  pattern_str += "\"";

  return pattern_str;
}


// This list will store the different choice pattern
struct choice_descriptor {
  pIIR_Choice choice_node;
  vector<int> choice_value;
  choice_descriptor(pIIR_Choice c, vector<int> &cv) {
    choice_node = c;
    choice_value = cv;
  }
  choice_descriptor &operator=(const choice_descriptor &src) {
    choice_node = src.choice_node;
    choice_value = src.choice_value;
  }
};


// Function to check a statement where the selection expression is an
// one-dimensional array and its element type is an character type
int
explore_and_check_array_case_statement(pIIR_CaseStatement cs, RegionStack &rstack, bool collect_access_info)
{
  int error_count = 0, choice_error_count = 0;

  // Get basic type of choice expression. I.e., any subtypes which
  // only add a resolution function to a type are ignored.
  pIIR_Type basic_type = get_basic_type(cs->expression->subtype);
  
  // First, determine bounds of array type
  vector<RangeDescriptor> range_desc = 
    get_discrete_range(cs->expression->subtype, rstack, IR_LOCALLY_STATIC);
  // Bail out if array bounds are not locally static
  error_count = range_desc[0].constant_fold_rangedes(rstack);
  StaticRangeDescriptor<lint, IR_Direction> locally_static_range = 
    range_desc[0].rangedes_to_lint(rstack);
  if (error_count != 0 || !and_reduce(locally_static_range.valid)) {
    codegen_error.error("%:error: array bounds of selection expression must be locally static.", cs);
    return error_count + 1;
  }
  // Determine length of array
  lint length = range_to_length(locally_static_range.left, locally_static_range.dir, 
				locally_static_range.right);
  // Test whether the array is one-dimensional
  if (range_desc.size() > 1) {
    codegen_error.error("%:error: selection array expression must be one-dimensional.", cs);
    return error_count + 1;
  }
  // Array element type must be a character type
  pIIR_Type element_base_type = 
    get_base_type(pIIR_ArrayType(get_base_type(cs->expression->subtype))->element_type);
  if (!element_base_type->is(IR_ENUMERATION_TYPE)) {
    codegen_error.error("%:error: element base type of the array must be a character type.", cs);
    return error_count + 1;

  } else {
    pIIR_EnumerationType enum_type = pIIR_EnumerationType(element_base_type);
    for (pIIR_EnumerationLiteralList ell = enum_type->enumeration_literals; ell; ell = ell->rest)
      if (ell->first->declarator->text.to_chars()[0] != '\'') {
	codegen_error.error("%:error: element base type (%n) of the array is not character a type.", cs, enum_type);
	return error_count + 1;
      }
  }
  
  // Next, determine how many different patterns must be covered. Note
  // that if the number of patterns is greater than INTEGER_MAX then
  // INTEGER_MAX is assumed (there will be never a real design with
  // INTEGER_MAX explicitly defined choices).
  pIIR_Type element_basic_type = 
    get_basic_type(pIIR_ArrayType(get_base_type(cs->expression->subtype))->element_type);
  vector<RangeDescriptor> elem_range_desc = 
    get_discrete_range (element_basic_type, rstack, IR_NOT_STATIC);
  StaticRangeDescriptor<lint, IR_Direction> erange = 
    elem_range_desc[0].rangedes_to_lint(rstack);  
  // Check whether the element type of the array is locally static,
  // i.e., wehther we could determine its bounds at compile time.
  if (!and_reduce(erange.valid)) {
    codegen_error.error("%:error: element type (%n) of the array is not locally static.", cs, element_basic_type);
    return error_count + 1;    
  }
  int enum_item_number = range_to_length(erange.left, erange.dir, erange.right);
  lint item_type_count = calculate_pow((lint)enum_item_number, length);
  lint item_count = 0; 
  // This list stores all the choice patterns 
  list<choice_descriptor> choices_list;

  // Next, analyze case statements alternatives
  for (pIIR_CaseStatementAlternativeList al = cs->case_statement_alternatives; al; al = al->rest) {
    pIIR_CaseStatementAlternative a = al->first;
    
    // Analyze choices
    for (pIIR_ChoiceList cl = a->choices; cl; cl = cl->rest) {
      
      if (cl->first->is(IR_CHOICE_BY_EXPRESSION)) {
	//***************************************
	// Choice by expression
	//***************************************
	pIIR_Expression choice_value = pIIR_ChoiceByExpression(cl->first)->value;
	// Choice must be locally static, i.e. the compiler should be able to 
	// determine the value during constant folding. Hence, check wehther a
	// valid folded value could be determined for the choice.
	choice_error_count += constant_fold(choice_value, rstack);
	if (!valid_folded_value(choice_value)) {
	  codegen_error.error("%:choice %n (%p) is not locally static.",
			      cl->first, choice_value, choice_value);
	  choice_error_count++;
	  continue;
	}
	// Make sure that the length of choice array and the length
	// of the selection expression match.
	lint clength = folded_value(choice_value).array_literal_value().size(); // Length of choice array	  
	if (length != clength) {
	  codegen_error.error("%:error: length of selection array (=%i) does not match length of choice (=%i).",
			      cl, (int)length, (int)clength);
	  choice_error_count++;
	  continue;

	} else {
	  // Check whether the choice is unique
	  for (list<choice_descriptor>::iterator iter = choices_list.begin(); iter != choices_list.end(); iter++)
	    if ((*iter).choice_value == get_folded_value(choice_value).array_literal_value()) {
	      string pattern_str = array_literal_to_string(pIIR_EnumerationType(element_base_type), (*iter).choice_value);
	      codegen_error.error("%:error: choice %s in line %i conflicts with same choice in line %i.", 
				  choice_value, pattern_str.c_str(), get_line_number(choice_value), 
				  get_line_number((*iter).choice_node));
	      choice_error_count++;
	    }
	  // If the choice length is ok then just store the choice
	  // pattern future choice coverage checking
	  choices_list.push_back(choice_descriptor(cl->first, get_folded_value(choice_value).array_literal_value()));
	  item_count++;	  
	}

      } else if (cl->first->is(IR_CHOICE_BY_OTHERS)) {
	//***************************************
	// Choice by others
	//***************************************
	// Store that all possible patterns are covered by case statement
	item_count = item_type_count;
	// Check whether the others choice is last alternative in
	// choice list
	if (cl->rest != NULL || al->rest != NULL || al->first->choices != cl) {
	  codegen_error.error("%:error: others choice must be a single last alternative in choice list.", cl->first);
	  choice_error_count++;
	}

      } else if (cl->first->is(IR_CHOICE_BY_RANGE)) {
	//***************************************
	// Choice by range
	//***************************************
	codegen_error.error("%:error: choice by range is not allowed for arrays.", cl);
	choice_error_count++;
	continue;
	
      } else
	assert(false);
    }

    // Analyze sequential statements associated with alternative
    if (a->sequence_of_statements != NULL)
      error_count += explore_and_check(a->sequence_of_statements, rstack, collect_access_info);
  }
  
  // Check whether all items are covered by the choices
  if (choice_error_count != 0) {
    // If the choices contained errors then no choice coverage
    // checking is done but we warn the user.
    codegen_error.info("%:warning: no choice coverage checking is done due to previous errors.", cs);

  } else if (item_type_count != item_count) {
    // Obviously not all patterns are covered by the choices. Hence,
    // output an error message! Try to find a pattern which is not
    // covered by the choices in order to porduce some more useful
    // error message.
    string uncovered_pattern_str;
    vector<int> test_pattern(length);
    fill(test_pattern.begin(), test_pattern.end(), erange.left);
    // Preload missing_pattern with the number of missing pattern to
    // be printed in the error message. However, we will print at most
    // three pattern.
    const lint max_pattern_to_print = 3;
    lint missing_pattern = min(max_pattern_to_print, item_type_count - item_count);
    while (true) {
      // Check whether the test pattern is not included in the choices
      bool pattern_found = true;
      for (list<choice_descriptor>::iterator iter = choices_list.begin(); iter != choices_list.end() && pattern_found; iter++)
	if ((*iter).choice_value == test_pattern)
	  pattern_found = false;
      // Print pattern into string if it is not covered by the choices
      if (pattern_found) {
	// Print pattern into string
	if (uncovered_pattern_str != "")
	  uncovered_pattern_str += ", ";
	uncovered_pattern_str += array_literal_to_string(pIIR_EnumerationType(element_base_type), test_pattern);
	// Exit loop if at most 3 unconvered pattern were detected
	if (--missing_pattern == 0)
	  break;
      }
      // Determine the next valid pattern
      for (int i = 0; i < length; i++) {
	test_pattern[i]++;
	if (test_pattern[i] > erange.right)
	  test_pattern[i] = erange.left;
	else 
	  break;
      }
    }
    // Append ", ..." to string if more than t3 pattern are missing
    if (item_type_count - item_count > max_pattern_to_print)
      uncovered_pattern_str += ", ...";
    // Output error message
    string item_type_count_str = item_type_count == INTEGER_MAX? (">" + to_string(INTEGER_MAX - 1)) : ("=" + to_string(item_type_count));
    codegen_error.error("%:error: only %i out of %i**%i (%s) possible choices are covered by the case statement. E.g., pattern %s is/are missing.", 
			cs, (int)item_count, (int)enum_item_number, (int)length, item_type_count_str.c_str(), uncovered_pattern_str.c_str());
  }

  error_count += choice_error_count;

  return error_count; // We are done. Return number of errors found
}



int
m_explore_and_check(pIIR_CaseStatement cs, RegionStack &rstack, bool collect_access_info)
{
  if (done(cs) & EXPLORED) return 0; else  done(cs) |= EXPLORED;
  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0, choice_error_count = 0;

  // Explore case expression
  error_count += explore_and_check(cs->expression->subtype, rstack, collect_access_info);
  if (collect_access_info)
    get_context(cs->expression, ctxt, rstack, false, 0);
  error_count += constant_fold(cs->expression, rstack);
  error_count += check_expression(cs->expression, rstack);

  // Get basic type of choice expression. I.e., any subtypes which
  // only add a resolution function to a type are ignored.
  pIIR_Type basic_type = get_basic_type(cs->expression->subtype);
  
  if (is_scalar_type(basic_type))
    //****************************************************
    //****************************************************
    // Expression is scalar. 
    //****************************************************
    //****************************************************
    return error_count + explore_and_check_scalar_case_statement(cs, rstack, collect_access_info);
  else
    //****************************************************
    //****************************************************
    // The expression is an array where the elements are characters
    //****************************************************
    //****************************************************
    return error_count + explore_and_check_array_case_statement(cs, rstack, collect_access_info);
}


int
m_explore_and_check(pIIR_IfStatement ifs, RegionStack &rstack, bool collect_access_info)
{
  if (done(ifs) & EXPLORED) return 0; else  done(ifs) |= EXPLORED;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;
  
  // Explore condition expression
  error_count += explore_and_check(ifs->condition->subtype, rstack, collect_access_info);
  if (collect_access_info)
    get_context(ifs->condition, ctxt, rstack, false, 0);
  error_count += constant_fold(ifs->condition, rstack);
  error_count += check_expression(ifs->condition, rstack);

  // Explore then branch
  if (ifs->then_sequence != NULL)
    error_count += explore_and_check(ifs->then_sequence, rstack, collect_access_info);

  // Explore else branch (if present)
  if (ifs->else_sequence != NULL)
    error_count += explore_and_check(ifs->else_sequence, rstack, collect_access_info);

  return error_count;
}


int
m_explore_and_check(pIIR_NullStatement n, RegionStack &rstack, bool collect_access_info)
{
  if (done(n) & EXPLORED) return 0; else  done(n) |= EXPLORED;

  return 0;
}


int
m_explore_and_check(pIIR_ForLoopStatement fs, RegionStack &rstack, bool collect_access_info)
{
  if (done(fs) & EXPLORED) return 0; else  done(fs) |= EXPLORED;

  // Set unique integer id for current loop
  loop_id(fs) = get_unique_int_id();

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  // Explore iteration range
  if (collect_access_info)
    get_context(pIIR_ScalarSubtype(fs->iterator->subtype)->range, ctxt, rstack, false, 0);
  error_count = constant_fold(pIIR_ScalarSubtype(fs->iterator->subtype)->range, rstack);
  error_count += check_expression(pIIR_ScalarSubtype(fs->iterator->subtype)->range, rstack);

  static_declarative_region (fs->iterator) = ActiveDeclarativeRegion (rstack);

  // Explore loop body
  if (fs->sequence_of_statements != NULL)
    error_count += explore_and_check(fs->sequence_of_statements, rstack, collect_access_info);

  return error_count; // Flag no errors found
}


int
m_explore_and_check(pIIR_LoopStatement ls, RegionStack &rstack, bool collect_access_info)
{
  if (done(ls) & EXPLORED) return 0; else  done(ls) |= EXPLORED;

  // Set unique integer id for current loop
  loop_id(ls) = get_unique_int_id();

  int error_count = 0;

  // Explore loop body
  if (ls->sequence_of_statements != NULL)
    error_count += explore_and_check(ls->sequence_of_statements, rstack, collect_access_info);

  return error_count;
}


int
m_explore_and_check(pIIR_NextStatement ns, RegionStack &rstack, bool collect_access_info)
{
  if (done(ns) & EXPLORED) return 0; else  done(ns) |= EXPLORED;
  
  // Store that a next statement was used for the corresponding loop
  next_statement_used(ns->loop) = true;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  if (ns->condition != NULL) {
    error_count = explore_and_check(ns->condition->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(ns->condition, ctxt, rstack, false, 0);
    error_count += constant_fold(ns->condition, rstack);
    error_count += check_expression(ns->condition, rstack);
  }

  return error_count;
}


int
m_explore_and_check(pIIR_ExitStatement es, RegionStack &rstack, bool collect_access_info)
{
  if (done(es) & EXPLORED) return 0; else  done(es) |= EXPLORED;
  
  // Store that a next statement was used for the corresponding loop
  exit_statement_used(es->loop) = true;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  if (es->condition != NULL) {
    error_count = explore_and_check(es->condition->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(es->condition, ctxt, rstack, false, 0);
    error_count += constant_fold(es->condition, rstack);
    error_count += check_expression(es->condition, rstack);
  }

  return error_count;
}


int
m_explore_and_check(pIIR_WhileLoopStatement wls, RegionStack &rstack, bool collect_access_info)
{
  if (done(wls) & EXPLORED) return 0; else  done(wls) |= EXPLORED;

  // Set unique integer id for current loop
  loop_id(wls) = get_unique_int_id();

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  error_count = explore_and_check(wls->condition->subtype, rstack, collect_access_info);
  if (collect_access_info)
    get_context(wls->condition, ctxt, rstack, false, 0);
  error_count += constant_fold(wls->condition, rstack);
  error_count += check_expression(wls->condition, rstack);
  
  // Explore loop body
  if (wls->sequence_of_statements != NULL)
    error_count += explore_and_check(wls->sequence_of_statements, rstack, collect_access_info);

  return error_count;
}


int
m_explore_and_check(pIIR_WaitStatement ws, RegionStack &rstack, bool collect_access_info)
{
  if (done(ws) & EXPLORED) return 0; else  done(ws) |= EXPLORED;

  // Determine base declarative region (process, subprogram,
  // concurrent assignment)
  pIIR_DeclarativeRegion base_region = BaseDeclarativeRegion(rstack);

  if (ws->condition_clause == NULL &&
      ws->timeout_clause == NULL &&
      ws->sensitivity_list == NULL) {
    // If there is no condition clause and no timeout clause and no
    // sensitivity_list then this wait statements shall stop the
    // process for the rest of the simulation time. Hence, nothing has
    // to be done now.
    return 0;
  }

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  // Add ws to the list of wait statements of the current context
  ctxt.wait_statements.push_back(ws);

  if (ws->sensitivity_list) {
    // Wait statemen has an explicit sensitivity list.
    
    if (base_region->is (IR_IMPLICIT_PROCESS_STATEMENT))
      {
	// If this wait statement belongs to an implicit process
	// (e.g., derived from a concurrent signal assignement), then
	// the sensitivity list may contain signal names that are not
	// globally static. Hence, form the sensitivity list, the
	// static signal names must be extracted. First, collect
	// accessed objects...
	ContextInfo tmp_ctxt;
	for (pIIR_ExpressionList el = ws->sensitivity_list; el; el = el->rest)
	  {
	    error_count += explore_and_check(el->first->subtype, rstack, collect_access_info);
	    get_context(el->first, tmp_ctxt, rstack, false, 0);
	    error_count += constant_fold(el->first, rstack);
	    error_count += check_expression(el->first, rstack);
	    (*tmp_ctxt.accessed_objects.begin()).access_type = SENSITIVE;
	    ctxt.accessed_objects.push_back(*tmp_ctxt.accessed_objects.begin());
	  }

	assert (ws->condition_clause == NULL);
	
	// Now analyze accessed objects
	for (access_list::iterator i = tmp_ctxt.accessed_objects.begin(); 
	     i != tmp_ctxt.accessed_objects.end(); i++)
	  if ((*i).declaration->is(IR_OBJECT_DECLARATION)) {
	    // If the object is a signal then set access_type to
	    // SENSITIVE and READ as the process is sensitive on this
	    // signal. Otherwise set the access_type to READ as a process
	    // can be sensitive on signals only.
	    AccessFlags access_type = 
	      ((*i).declaration->is(IR_SIGNAL_DECLARATION) || 
	       (*i).declaration->is(IR_SIGNAL_INTERFACE_DECLARATION))? 
	      (SENSITIVE | SIGNAL_FUNCTION_ATTRIBUTE | READ) : READ;
	    ctxt.accessed_objects.push_back(AccessDescriptor(pIIR_ObjectDeclaration((*i).declaration), 
							     (*i).access_expr, access_type));
	  } else
	    // Add remaining access descriptors to access list.
	    ctxt.accessed_objects.push_back((*i));
      }
    else
      {
	// Set access type flag for sensitivity signals. If this wait
	// statment is included within a procedure, then the access_type
	// flags will also include flag SIGNAL_FUNCTION_ATTRIBUTE.
	AccessFlags sensitive_signal_access_type = 
	  base_region->is (IR_PROCEDURE_DECLARATION) ?
	  (SENSITIVE | SIGNAL_FUNCTION_ATTRIBUTE) : SENSITIVE;
	
	for (pIIR_ExpressionList el = ws->sensitivity_list; el; el = el->rest)
	  {
	    ContextInfo tmp_ctxt;
	    error_count += explore_and_check(el->first->subtype, rstack, collect_access_info);
	    get_context(el->first, tmp_ctxt, rstack, false, 0);
	    error_count += constant_fold(el->first, rstack);
	    error_count += check_expression(el->first, rstack);
	    int static_sl_count = check_for_static_names(el->first, IR_GLOBALLY_STATIC, rstack);
	    error_count += static_sl_count;
	    if (static_sl_count > 0)
	      codegen_error.error("%:error: signals on an explicit sensitivity list must denote globally static signal names.", 
				  ws);
	    else 
	      {
		(*tmp_ctxt.accessed_objects.begin()).access_type = sensitive_signal_access_type;
		ctxt.accessed_objects.push_back(*tmp_ctxt.accessed_objects.begin());
	      }
	  }

	if (ws->condition_clause) {
	  error_count += explore_and_check(ws->condition_clause->subtype, rstack, collect_access_info);
	  if (collect_access_info)
	    get_context(ws->condition_clause, ctxt, rstack, false, 0);
	  error_count += constant_fold(ws->condition_clause, rstack);
	  error_count += check_expression(ws->condition_clause, rstack);
	}
    }

  } else {
    // Wait statement does not have an explicit sensitivity
    // list. Hence, extract one from the wait condition.
    ContextInfo tmp_ctxt;
    if (ws->condition_clause != NULL) {
      error_count += explore_and_check(ws->condition_clause->subtype, rstack, collect_access_info);
      get_context(ws->condition_clause, tmp_ctxt, rstack, false, 0);
      if (collect_access_info)
	get_context(ws->condition_clause, ctxt, rstack, false, 0);
      error_count += constant_fold(ws->condition_clause, rstack);
      error_count += check_expression(ws->condition_clause, rstack);
    }
    for (access_list::iterator i = tmp_ctxt.accessed_objects.begin(); 
	 i != tmp_ctxt.accessed_objects.end(); i++)
      if ((*i).declaration->is(IR_OBJECT_DECLARATION)) {
	// If the object is a signal then set access_type to
	// SENSITIVE and READ as the process is sensitive on this
	// signal. Otherwise set the access_type to READ as a process
	// can be sensitive on signals only.
	AccessFlags access_type = 
	  ((*i).declaration->is(IR_SIGNAL_DECLARATION) || 
	   (*i).declaration->is(IR_SIGNAL_INTERFACE_DECLARATION))? 
	  (SENSITIVE | SIGNAL_FUNCTION_ATTRIBUTE | READ) : READ;
	ctxt.accessed_objects.push_back(AccessDescriptor(pIIR_ObjectDeclaration((*i).declaration), 
							 (*i).access_expr, access_type));
      } else
	// Add remaining access descriptors to access list.
	ctxt.accessed_objects.push_back((*i));
    // Ouptput a warning if the implicit sensitivity list is empty!
    if (tmp_ctxt.accessed_objects.size() == 0 && ws->timeout_clause == NULL)
      codegen_error.info("%:warning: the implictly defined sensitivity list is empty, i.e. the process will wait forever.", ws);
  }

  // Explore timeout expression
  if (ws->timeout_clause) {
    error_count += explore_and_check(ws->timeout_clause->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(ws->timeout_clause, ctxt, rstack, false, 0);
    error_count += constant_fold(ws->timeout_clause, rstack);
    error_count += check_expression(ws->timeout_clause, rstack);

    // Store that in the corresponding procedure or process that a
    // wait statement uses an timeout clause.
    pIIR_DeclarativeRegion base_region = BaseDeclarativeRegion(rstack);
    if (base_region->is(IR_PROCEDURE_DECLARATION))
      has_wait_for(pIIR_ProcedureDeclaration(base_region)) = true;
    else if (base_region->is(IR_PROCESS_STATEMENT))
      has_wait_for(pIIR_ProcessStatement(base_region)) = true;
    else
      assert(false);
  }

  // Store that in the corresponding procedure or process that a
  // wait statement.
  if (base_region->is(IR_PROCEDURE_DECLARATION))
    has_wait (pIIR_ProcedureDeclaration(base_region)) = true;
  else if (base_region->is(IR_PROCESS_STATEMENT))
    has_wait (pIIR_ProcessStatement(base_region)) = true;
  else
    assert(false);

  return error_count;
}


int
m_explore_and_check(pIIR_SignalAssignmentStatement sas, RegionStack &rstack, bool collect_access_info)
{
  if (done(sas) & EXPLORED) return 0; else  done(sas) |= EXPLORED;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  // Add sas to list of signal assignment statements
  ctxt.signal_assignment_statements.push_back(sas);

  error_count += explore_and_check(sas->target->subtype, rstack, collect_access_info);

  // Collect objects in target expression
  if (collect_access_info)
    get_context(sas->target, ctxt, rstack, true /* = true, because the signal is a target */, 0);

  // Check and fold target expression
  error_count += constant_fold(sas->target, rstack);
  error_count += check_expression(sas->target, rstack);

  // Collect signals in reject expression
  if (sas->reject_time_expression) {
    error_count += explore_and_check(sas->reject_time_expression->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(sas->reject_time_expression, ctxt, rstack, true, 0); 
    error_count += constant_fold(sas->reject_time_expression, rstack);
    error_count += check_expression(sas->reject_time_expression, rstack);
  }

  // Collect signals in waveforms
  for (pIIR_WaveformList wl = sas->waveform; wl; wl = wl->rest) {
    error_count += explore_and_check(wl->first->value->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(wl->first->value, ctxt, rstack, false, 0);
    error_count += constant_fold(wl->first->value, rstack);
    error_count += check_expression(wl->first->value, rstack);
    if (wl->first->time != NULL) {
      error_count += constant_fold(wl->first->time, rstack);
      error_count += check_expression(wl->first->time, rstack);
    }
    // Check assignment value. 
    error_count += check_for_target_type(wl->first, sas->target->subtype, wl->first->value, 
					 rstack, runtime_checks(wl->first->value), 
					 true, " illegal signal assignment:");
  }

  return error_count;
}



int
m_explore_and_check(pIIR_VariableAssignmentStatement vas, RegionStack &rstack, bool collect_access_info)
{
  if (done(vas) & EXPLORED) return 0; else  done(vas) |= EXPLORED;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  error_count += explore_and_check(vas->target->subtype, rstack, collect_access_info);

  // Collect objects in target expression
  if (collect_access_info)
    get_context(vas->target, ctxt, rstack, true /* = true, because the variable is a target */, 0);
  error_count += constant_fold(vas->target, rstack);
  error_count += check_expression(vas->target, rstack);

  // Collect objects in assignment expression
  error_count += explore_and_check(vas->expression->subtype, rstack, collect_access_info);
  if (collect_access_info)
    get_context(vas->expression, ctxt, rstack, false, 0);
  error_count += constant_fold(vas->expression, rstack);
  error_count += check_expression(vas->expression, rstack);
  
  // Check assignment value. 
  error_count += check_for_target_type(vas, vas->target->subtype, vas->expression, rstack, 
				       runtime_checks(vas->expression), true, 
				       " illegal variable assignment:");

  return error_count;
}



// Check association. Note that the parser converts complex
// associations of the form (a(0) => ..., a(1) => ...) into an
// "aritficial" array (or record) aggregate. actual points to an
// actual expression (perhaps and artificial aggregate). range_vec
// stores the ranges determined by the aggregate. I.e., in case of an
// multi-dimensional aggregate each vector entry covers one
// dimension. parameter level is used to keep track of these
// levels. The purpose of range_vec is to enable range checking.
int
check_association(pIIR_Expression actual, pIIR_Type formal_type, 
		  vector<vector<int> > &range_vec, int level,
		  RegionStack &rstack)
{
  int error_count = 0;
  
  if (actual == NULL) 
    {
      // Association with `open'.  If the formal element is left open
      // then the corresonding range vector must be empty.
      if (range_vec[level].size() != 0)
	error_count++;

      return error_count;
    }

  else if (actual->is(IR_OBJECT_REFERENCE))
    {
      // Association with a single signal object.  The corresponding
      // range vector includes only a single element
      if (range_vec[level].size() == 0) 
	{
	  range_vec[level] = vector<int>(1);
	  range_vec[level][0] = 0;
	} else if (range_vec[level].size() != 1)
	  error_count++;
	
      RuntimeCheckFlags runtime_checks;
      if (check_for_target_type(actual, formal_type, actual, rstack, runtime_checks, false) != 0)
	{
	  codegen_error.error("%:error: illegal association.", actual);
	  error_count++;
	}

      return error_count;
    }

  else if (actual->is(IR_ARTIFICIAL_ARRAY_AGGREGATE))
    {
      // If actual is actually an artificial array aggregate then the
      // formal has been associated individually. Hence, decent into
      // the aggregate expression and find all signal associations.
      pIIR_Type basic_dest_type = get_basic_type(formal_type);
      pIIR_TypeList tl = basic_dest_type->is(IR_ARRAY_TYPE) ? 
	pIIR_ArrayType(basic_dest_type)->index_types : pIIR_ArraySubtype(basic_dest_type)->constraint;
      // Next, determine number of dimensions.
      int dim_counter = 0;
      for (pIIR_TypeList tli = tl; tli; tli = tli->rest)
	dim_counter++;

      int dim_number = 1;
      pIIR_Type actual_type = actual->subtype;
      if (actual_type->is(VAUL_SUBARRAY_TYPE)) 
	{
	  // If the aggreate is a multi-dimensional array then a node
	  // VAUL_SubarrayType is used to describe the (sub)type of
	  // the sub-aggregate. Determine the index associated with
	  // the array aggregate. Note that we can only count how many
	  // dimensions are left from where the aggregate starts.
	  int current_dim_counter = 0;
	  for (pIIR_TypeList tl = pVAUL_SubarrayType(actual_type)->index_types; tl; tl = tl->rest)
	    current_dim_counter++;
	  // Now, determine the index number of the aggregate
	  dim_number = dim_counter - current_dim_counter + 1;
	} 
      
      // Next, get index type that belongs to the current dimension.
      for (int i = 1; i < dim_number; i++)
	tl = tl->rest;
      pIIR_Type formal_index_type = tl->first;
      // Determine bounds from this index type (if they are locally
      // static)
      vector<RangeDescriptor> formal_range_desc = 
	get_discrete_range(formal_index_type, rstack, IR_NOT_STATIC);
      StaticRangeDescriptor<lint, IR_Direction> formal_range = 
	formal_range_desc[0].rangedes_to_lint(rstack);

      // Get element type of array
      pIIR_Type element_type = basic_dest_type;
      if (dim_counter == dim_number)
	// If the elements of the formal array are associated
	// individually, then set element_type to the element type of
	// the formal array.
	element_type = pIIR_ArrayType(get_base_type(basic_dest_type))->element_type;

      // Analyze associations. low_index and high_index store the
      // range values that are connected with the formal.
      vector<int> low_index, high_index;
      bool locally_static_range = true;
      for (pIIR_IndexedAssociationList al = pIIR_ArrayAggregate(actual)->indexed_association_list;
	   al != NULL; 
	   al = al->rest) 
	{
	  pIIR_IndexedAssociation a = al->first;
	  
	  if (a->is(IR_SINGLE_INDEXED_ASSOCIATION)) 
	    {
	      // A single index of the formal array has been
	      // associated with a value.
	      pIIR_SingleIndexedAssociation ia = pIIR_SingleIndexedAssociation(a);
	      if (valid_folded_value(ia->index)) 
		{
		  const lint index = folded_value(ia->index).long_value();
		  low_index.push_back(index);
		  high_index.push_back(index);
		  RuntimeCheckFlags rt_checks; 
		  error_count += check_scalar_against_bounds(actual, index, formal_index_type, rstack, rt_checks, 
							     true, " formal index out of bounds:");
		} else
		  locally_static_range = false;

	      if (range_vec.size() < level + 2)
		range_vec.resize(level + 2);
	      // Decent into the next aggregate level (note that the
	      // aggregate might be multidimensional!)
	      error_count += check_association(a->value, element_type, range_vec, level + 1, rstack);
	    }
	  
	  else if (a->is(IR_RANGE_INDEXED_ASSOCIATION))
	    {
	      // An entire range of the formal is asscociated with an
	      // actual. The association is of the form "formal(0 to
	      // 3) => value(1 to 4)". The range associated with the
	      // formal will be denoted as "formal association range"
	      // while the range association with the value is named
	      // "actual range". Note that the formal itself might be
	      // also bounded ("formal range").
	      pIIR_RangeIndexedAssociation ra = pIIR_RangeIndexedAssociation(a);
	      // First, check whether the value of the association is
	      // either an array or slice of an array.
	      bool valid_value_object = 
		is_array_type(a->value->subtype) && a->value->is(IR_OBJECT_REFERENCE);
	      if (!valid_value_object) 
		{
		  codegen_error.error("%:error: actual must be an array object or slice thereof.", a->value); 
		  error_count++;
		}
	      // Determine association range.
	      vector<RangeDescriptor> range_desc = 
		get_discrete_range (ra->index_range, rstack, IR_NOT_STATIC);
	      // Try to determine formal association range bounds at
	      // compile time.
	      StaticRangeDescriptor<lint, IR_Direction> range = 
		range_desc[0].rangedes_to_lint(rstack);

	      if (range.valid[0])
		{
		  RuntimeCheckFlags rt_checks; 
		  error_count += check_scalar_against_bounds(actual, range.left, formal_index_type, rstack, rt_checks, 
							     true, " formal index range out of bounds:");
		}
	      
	      if (range.valid[2])
		{
		  RuntimeCheckFlags rt_checks; 
		  error_count += check_scalar_against_bounds(actual, range.right, formal_index_type, rstack, rt_checks, 
							     true, " formal index range out of bounds:");
		}

	      // If bounds as well as range direction are locally
	      // static (can be determined at compiler time) then put
	      // them on the low_index and high_index lists.
	      if (and_reduce(range.valid)) 
		{
		  low_index.push_back(range.dir == IR_DIRECTION_UP? range.left : range.right);
		  high_index.push_back(range.dir == IR_DIRECTION_UP? range.right : range.left);
		  // Check whether formal association range matches
		  // actual range.
		  if (valid_value_object)
		    {
		      // Determine length from formal association
		      // range.
		      const lint index_range_length = 
			range_to_length(range.left, range.dir, range.right);
		      // Get length of actual range.
		      vector<RangeDescriptor> range_desc_value_object = 
			get_discrete_range(a->value->subtype, rstack, IR_NOT_STATIC);
		      StaticRangeDescriptor<lint, IR_Direction> value_range = 
			range_desc_value_object[0].rangedes_to_lint(rstack);
		      const lint value_range_length = 
			range_to_length(value_range.left, value_range.dir, value_range.right);
		      // If the actual range length is static then
		      // check whether it matches the length of the
		      // formal association range length.
		      if (value_range_length != index_range_length)
			{
			  codegen_error.error("%:error: formal association range length (=%i) does not match array object length (=%i).", 
					      actual, (int)index_range_length, (int)value_range_length);
			  error_count++;
			}
		    }
		} else
		  locally_static_range = false;

	      // If the formal type is not unconstrained then check
	      // whether the range direction given in the formal
	      // association matches the direction of the formal
	      // range.
	      if (range.valid[1] && formal_range.valid[1] && 
		  !basic_dest_type->is(IR_ARRAY_TYPE) && range.dir != formal_range.dir) 
		{
		  codegen_error.error("%:error: range direction '%s' in association does not match formal range.", 
				      actual, (range.dir == IR_DIRECTION_UP? "to" : "downto"));
		  error_count++;
		}
	    }

	  else 
	    assert(false);
	}

      // Finally, after associations at the current level has been
      // processed, analyze index ranges. First, check whether the
      // ranges overlap.
      for (unsigned int i = 0; i < low_index.size() - 1; i++)
	for (unsigned int j = i + 1; j < low_index.size(); j++)
	  if (!(high_index[i] < low_index[j] ||
		low_index[i] > high_index[j])) 
	    {
	      codegen_error.error("%:error: formal ranges '%i %s %i' and '%i %s %i' overlap.", 
				  actual, 
				  (formal_range.dir == IR_DIRECTION_UP? low_index[i] : high_index[i]),
				  (formal_range.dir == IR_DIRECTION_UP? "to" : "downto"),
				  (formal_range.dir == IR_DIRECTION_UP? high_index[i] : low_index[i]),
				  (formal_range.dir == IR_DIRECTION_UP? low_index[j] : high_index[j]),
				  (formal_range.dir == IR_DIRECTION_UP? "to" : "downto"),
				  (formal_range.dir == IR_DIRECTION_UP? high_index[j] : low_index[j])
				  );
	      error_count++;
	    }
      // Next, if all ranges are locally static then check out whether
      // there are any holes in the association ranges. Otherwise,
      // this must be done at runtime.
      if (locally_static_range)
	{
	  sort(low_index.begin(), low_index.end());
	  sort(high_index.begin(), high_index.end());
	  for (unsigned int i = 0; i < low_index.size() - 1; i++)
	    if (high_index[i] + 1 < low_index[i + 1]) 
	      {
		codegen_error.error("%:error: formal association index range is incomplete. E.g., index %i is missing.", 
				    actual, high_index[i] + 1);
		error_count++;
	      }
	}

      // Check whether we were able to determine bounds from previous
      // processing of the same level.
      if (range_vec[level].size() == 0) 
	{
	  if (locally_static_range)
	    {
	      // Store range to range_vec in order to be able to check
	      // other associations at the same level. Note that the
	      // first element always stores the low value!
	      range_vec[level].push_back(low_index.front());
	      range_vec[level].push_back(formal_range.dir == IR_DIRECTION_UP? 0 : 1);
	      range_vec[level].push_back(high_index.back());
	    }
	}
      else 
	{
	  // Ok, we already found bounds during previous processing of
	  // the same level. Hence, try to match the new bounds
	  // against the old bounds.
	  if (locally_static_range)
	    {
	      // If the current range is locally static, then previous
	      // and current bounds must match exactly.
	      if (low_index.front() != range_vec[level][0])
		{
		  codegen_error.error("%:error: range bound mismatch (new low bound %i is not equal to previously determined low bound %i).", 
				      actual, low_index.front(), range_vec[level][0]);
		  error_count++;
		}
	      if (high_index.back() != range_vec[level][2])
		{
		  codegen_error.error("%:error: range bound mismatch (new high bound %i is not equal to previously determined high bound %i).", 
				      actual, high_index.back(), range_vec[level][2]);
		  error_count++;
		}

	    }
	  else
	    {
	      // If the current bounds are not static then we can only
	      // check wether the values we found are within the
	      // previously found bounds.
	      if (low_index.front() < range_vec[level][0])
		{
		  codegen_error.error("%:error: range bound mismatch (new low bound %i is less than previously determined low bound %i).", 
				      actual, low_index.front(), range_vec[level][0]);
		  error_count++;
		}
	      if (high_index.back() > range_vec[level][2])
		{
		  codegen_error.error("%:error: range bound mismatch (new high bound %i is larger than previously determined high bound %i).", 
				      actual, high_index.back(), range_vec[level][2]);
		  error_count++;
		}
	      
	    }
	}
    }
  
  else if (actual->is(IR_ARTIFICIAL_RECORD_AGGREGATE))
    {
      // If map is actually a record aggregate then the formal has
      // been associated individually. Hence, decent into the
      // aggregate expression and find all signal associations.
      for (pIIR_ElementAssociationList el = pIIR_RecordAggregate(actual)->element_association_list;
	   el != NULL;
	   el = el->rest) 
	{
	  pIIR_ElementAssociation e = el->first;
	  // Each association is handled separately, Hence, create an
	  // emty range_vec to be used for checking of the actuals.
	  vector<vector<int> > new_range_vec(1);
	  error_count += check_association(e->value, e->element->subtype, new_range_vec, 0, rstack);
	}
    } 
  
  else
    {
      // The formal is associated with an expression
      RuntimeCheckFlags runtime_checks;
      if (check_for_target_type(actual, formal_type, actual, rstack, runtime_checks, false) != 0)
	{
	  codegen_error.error("%:error: illegal association.", actual);
	  error_count++;
	}
    }  

  return error_count;
}


int
m_explore_and_check(pIIR_AssociationElement ae, RegionStack &rstack, bool collect_access_info)
{
  if (done(ae) & EXPLORED) return 0; else  done(ae) |= EXPLORED;
  
  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  if (!ae->is(IR_ASSOCIATION_ELEMENT_OPEN))
    error_count += explore_and_check(ae->actual->subtype, rstack, collect_access_info);
  if (collect_access_info) {
    get_context(ae->actual, ctxt, rstack, false, 0);
    get_context(ae->formal, ctxt, rstack, false, 0);
  }
  error_count += constant_fold(ae->actual, rstack);
  error_count += constant_fold(ae->formal, rstack);

  vector<vector<int> > actual_range_vec(1);
  error_count += check_association(ae->actual, ae->formal->subtype, actual_range_vec, 0, rstack);

  vector<vector<int> > formal_range_vec(1);
  error_count += check_association(ae->formal, ae->formal->subtype, formal_range_vec, 0, rstack);
  
  return error_count;
}


// Converts an acl_list into a vector of range descriptors.
vector<StaticRangeDescriptor<lint, IR_Direction> >
get_static_ranges(list<pair<pIIR_Expression, pIIR_Root> > &acl_list, RegionStack &rstack)
{
  vector<StaticRangeDescriptor<lint, IR_Direction> >  result;

  for (list<pair<pIIR_Expression, pIIR_Root> >::iterator iter = acl_list.begin ();
       iter != acl_list.end ();
       iter++)
    {
      const bool emit_directly = iter->first == NULL;
      pIIR_Root ex = iter->second;

      if (!emit_directly && ex->is(IR_RECORD_REFERENCE))
	{
	  // if the prefix is static then determine the declaration number
	  // of the record element (the first element is associated with
	  // number 0, the next element is associated with 1, ...)
	  int record_elem_num = pIIR_RecordReference(ex)->element->declaration_pos;
	  result.push_back (StaticRangeDescriptor<lint, IR_Direction> 
			    ((lint)record_elem_num, IR_DIRECTION_UP, (lint)record_elem_num));
	}
      else if (!emit_directly && ex->is(IR_EXPLICIT_RANGE))
	{
	  // Determine range 
	  vector<RangeDescriptor> range_desc = 
	    get_discrete_range (pIIR_ExplicitRange(ex), rstack, IR_NOT_STATIC);
	  // Convert to integer lints
	  StaticRangeDescriptor<lint, IR_Direction> range = 
	    range_desc[0].rangedes_to_lint(rstack);
	  result.push_back (range);
	}
      else
	{
	  pIIR_Expression expr = pIIR_Expression (ex);
	  if (valid_folded_value (expr))
	    result.push_back (StaticRangeDescriptor<lint, IR_Direction> 
			      (folded_value (expr).long_value (), 
			       IR_DIRECTION_UP, folded_value (expr).long_value ()));
	  else
	    result.push_back (StaticRangeDescriptor<lint, IR_Direction> (0, IR_DIRECTION_UP, -1));
	}
    }

  return result;
}


int 
check_association(pIIR_AssociationList assoc_list, list<pIIR_AssociationElement> &assoc, 
		  pIIR_InterfaceDeclaration decl, RegionStack &rstack)
{
  int error_count = 0;

  // association_range_vector holds for each association in assoc_list
  // the corresponding ranges extracted from the formal
  // designator. I.e., it stores the acl values (after converting to
  // static values -- if possible).
  vector<vector<StaticRangeDescriptor<lint, IR_Direction> > > 
    association_range_vectors;
  // association_type_vectors [i] stores the appropriate type vectors
  // that corespond with addociation_range_vectors.  E.g., in case of
  // a formal designator "f(3,2)(1 to 4)" (type = array(0 to 3, 0 to
  // 5) of bit_vector (0 to 7))the association range vector is "(3 to
  // 3), (2 to 2), (1 to 4)". The corresponding
  // association_type_vectors also contains 3 elements, where the
  // first pair (element) references the first index of the
  // 2-dimensional array type, the second pair references the second
  // index of the 2-dimensional array type, and the last pair is the
  // index type of the element array (bit_vector (0 to 7)).
  vector<vector<pair<pIIR_Type, pIIR_Type > > > association_type_vectors;

  for (list<pIIR_AssociationElement>::iterator iter = assoc.begin();
       iter != assoc.end();
       iter++)
    {
      pIIR_AssociationElement assoc_element = *iter;
      // First, test whether formal designator and actual designator
      // type match. E.g., "f(3) => a(2)" associates the third element
      // of formal f with second element of actual a. Hence, type of
      // f(3) and a(2) must match.
      RuntimeCheckFlags runtime_checks; // Hack
      if (!assoc_element->actual->is (IR_OPEN_EXPRESSION))
	error_count += 
	  check_for_target_type(assoc_element, assoc_element->formal->subtype, 
				assoc_element->actual, rstack, runtime_checks, 
				true, " illegal association of formal '" + 
				convert_string(decl->declarator->text.to_chars(), tolower) +
				"':");
      // Next, collect range information to analyze association for a
      // specific formal. Note that this is an somehow complex
      // process, as all association for a specific formal must be
      // collected (e.g., "f(3) => a(2), f(4) => x, ...").
      list<pair<pIIR_Expression, pIIR_Root> > formal_acl_list;
      get_acl(assoc_element->formal, formal_acl_list, rstack, IR_NOT_STATIC, true);
      if (formal_acl_list.size () == 0 &&
	  assoc.size () > 1)
	{
	  codegen_error.error("%:error: formal '%n' may not be associated individually and also associated as a whole.", 
			      assoc_list, decl);
	  error_count++;
	}
      association_range_vectors.push_back (get_static_ranges (formal_acl_list, rstack));
      association_type_vectors.push_back (get_types (formal_acl_list, decl->subtype));

      vector<StaticRangeDescriptor<lint, IR_Direction> > &rvec = association_range_vectors.back ();
      //for (vector<StaticRangeDescriptor<lint, IR_Direction> >::iterator it = rvec.begin ();
      //   it != rvec.end ();
      //   it++)
      //cout << "(" << (int)it->left << (it->dir == IR_DIRECTION_UP? " to " : " downto ") << (int)it->right << ") ";
      //cout << endl;
    }

  // Next, analyze the formal designator ranges. Build a map from the
  // ranges. For each designator add a set of entries starting by
  // using the first n elements of the range as key (n=0,1,2,...) and
  // storing element n + 1 as value. I.e., an formal designator that
  // consists of 3 range elements will add 3 entries to the map: 
  // (key = nil, value = element [0]), 
  // (key = element [0], value = element [1]), 
  // (key = element [0] & element [1], value = element [2]),
  // (key = element [0] & element [1] & element [2], value = element [3]).
  typedef map<vector<StaticRangeDescriptor<lint, IR_Direction> >, 
    list<StaticRangeDescriptor<lint, IR_Direction> > > association_map_t;
  association_map_t association_map;
  // association_type_map associates each entry in association_map
  // with a corresponding type vector. This map is used to obtain the
  // appropriate type definitions. 
  map<association_map_t::key_type, 
    vector<vector<pair<pIIR_Type, pIIR_Type > > >::iterator > association_type_map;
  // Map used to store only key that define a complete acl. This map
  // is used to check for double individual assoication.
  vector<association_map_t::key_type> complete_associations;
  for (unsigned int i = 0; i < association_range_vectors.size (); i++)
    {
      vector<StaticRangeDescriptor<lint, IR_Direction> > &range_vector = 
	association_range_vectors [i];
      if (range_vector.size () == 0) continue;
      // Create a key from each sequence starting from the first
      // vector element and ending at some element. The following
      // element is added to the list which is associated with the
      // key.
      association_map_t::key_type key;
      for (unsigned int j = 0; j < range_vector.size (); j++)
	{
	  // Add entries
	  association_map [key].push_back (range_vector [j]);
	  // XXX - why is the cast needed?
	  association_type_map [key] = (vector<vector<pair<pIIR_Type, pIIR_Type > > >::iterator) &association_type_vectors [i];
	  // Generate a new key
	  key.push_back (range_vector [j]);
	}
      // Add entry to list of complete acl vectors.
      complete_associations.push_back (key);
    }

  // The value of the association_map is rebuild so that it only
  // contains no or a single list entry. The various list elements are
  // compacted to form a single entry representing an appropriate
  // range.
  for (association_map_t::iterator map_iter = association_map.begin ();
       map_iter != association_map.end ();
       map_iter++)
    {
      // Next, sort ranges in increasing order of start index
      list<StaticRangeDescriptor<lint, IR_Direction> > &range_list = 
	map_iter->second;
      if (range_list.size () == 0) continue;
      // Get appropriate type vector
      vector<pair<pIIR_Type, pIIR_Type > > &type_vector = 
	*association_type_map [map_iter->first];

      // Check whether all ranges are locally static (i.e., whether
      // ranges could be determined at compile time)
      bool globally_static_ranges = true;
      for (list<StaticRangeDescriptor<lint, IR_Direction> >::iterator iter = 
	     range_list.begin ();
	   iter != range_list.end () && globally_static_ranges;
	   iter++)
	globally_static_ranges = globally_static_ranges && and_reduce(iter->valid);
      // Sort ranges
      range_list.sort (StaticRangeDescriptor_lint_Less ());
      
      bool unassociated_elements_reported = false;
      // Check for missing elements (gaps) as well as overlapping
      // ranges
      if (globally_static_ranges)
	{
	  int index = max (range_list.front ().left, range_list.front ().right) + 1;
	  for (list<StaticRangeDescriptor<lint, IR_Direction> >::iterator 
		 prev_range_iter = range_list.begin (), range_iter = ++ range_list.begin ();
	       range_iter != range_list.end ();
	       prev_range_iter = range_iter, range_iter++)
	    {
	      // Iterate through ranges in increasing range order
	      // (i.e., the range that includes the smallest index is
	      // analyzed first).
	      if (! and_reduce (range_iter->valid)) continue;
	      int next_index = min (range_iter->left, range_iter->right);
	      if (index != next_index)
		if (index > next_index)
		  {
		    // Finally, check out whether at least one of
		    // these range vectors is a complete individual
		    // association.  
		    association_map_t::key_type prev_complete_range_vec = map_iter->first;
		    association_map_t::key_type complete_range_vec = map_iter->first;
		    prev_complete_range_vec.push_back (*prev_range_iter);
		    complete_range_vec.push_back (*range_iter);
		    if (find (complete_associations.begin (), complete_associations.end (), prev_complete_range_vec) != 
			complete_associations.end () ||
			find (complete_associations.begin (), complete_associations.end (), complete_range_vec) != 
			complete_associations.end ())
		      {
			// Ranges overlap. Generate error message.
			vector<StaticRangeDescriptor<lint, IR_Direction> >  error_acl = 
			  map_iter->first;
			error_acl.push_back (StaticRangeDescriptor<lint, IR_Direction>
					     (next_index, IR_DIRECTION_UP, next_index));
			codegen_error.error("%:error: element(s) of composite formal '%n' is (are) associated more than once. "
					    "E.g., element %s is covered multiple times.", 
					    assoc_list, decl,
					    sprint_object_reference (decl, error_acl, rstack).c_str ());
			error_count ++;
		      }
		  }
		else
		  {
		    // There is a gap in the ranges. Note that gaps
		    // are only searched if all ranges are globally
		    // static (i.e., could be determined at compile
		    // time). However, report only one gap (to prevent
		    // flooding the screen with error messages).
		    if (! unassociated_elements_reported)
		      {
			vector<StaticRangeDescriptor<lint, IR_Direction> > error_acl = 
			  map_iter->first;
			error_acl.push_back (StaticRangeDescriptor<lint, IR_Direction>
					     (index, IR_DIRECTION_UP, index));
			codegen_error.error("%:error: not all elements of composite formal '%n' are associated. "
					    "E.g., element %s is un-associated.", 
					    assoc_list, decl,
					    sprint_object_reference (decl, error_acl, rstack).c_str ());
			unassociated_elements_reported = true;
		      }
		    error_count ++;
		  }
	      index = max (range_iter->left, range_iter->right) + 1;
	    }
	}

      // Replace list with a single entry that represents the entire
      // range. If the list does not contain an element, then the
      // entire formal (or part thereof) is associated.
      StaticRangeDescriptor<lint, IR_Direction>
	composed_range (range_list.front ().left,  range_list.front ().dir,
			range_list.back ().right);
      range_list.clear ();
      range_list.push_back (composed_range);

      // Skip range checks if ranges are not locally static
      if (!globally_static_ranges) continue;
      // Finally, check out whether index ranges are within bounds if
      // ranges could be determined at compile time.
      vector<pair<pIIR_Type, pIIR_Type > > &type_pair_vector =
	*association_type_map [map_iter->first];
      pair<pIIR_Type, pIIR_Type > &type_pair = type_pair_vector [map_iter->first.size ()];
      if (type_pair.first->is (IR_ARRAY_SUBTYPE))
	{
	  // Target type is a constrained array. Hence, formal index
	  // range must match exactly! First, get target range.
	  vector<RangeDescriptor> target_range_desc = 
	    get_discrete_range(type_pair.second, rstack, IR_NOT_STATIC);
	  StaticRangeDescriptor<lint, IR_Direction> target_range = 
	    target_range_desc [0].rangedes_to_lint(rstack);
	  // If target range can be determined at compile time, then
	  // compare number of elements of actual and formal. If
	  // length is not equal then output error message.
	  if (and_reduce (target_range.valid) &&
	      lint_abs (composed_range.left - composed_range.right) != lint_abs (target_range.left - target_range.right) &&
	      !unassociated_elements_reported)
	    {
	      const lint offending_index = 
		min (target_range.left, target_range.right) != min (composed_range.left, composed_range.right) ?
		target_range.left : target_range.right;
	      vector<StaticRangeDescriptor<lint, IR_Direction> > error_acl =
		map_iter->first;
	      error_acl.push_back (StaticRangeDescriptor<lint, IR_Direction> 
				   (offending_index, IR_DIRECTION_UP, offending_index));
	      codegen_error.error("%:error: not all elements of composite formal '%n' are associated. "
				  "E.g., element %s is un-associated.", 
				  assoc_list, decl,
				  sprint_object_reference (decl, error_acl, rstack).c_str ());
	      unassociated_elements_reported = true;
	      error_count ++;
	    }	      
	}
      else if (type_pair.first->is (IR_RECORD_TYPE))
	{
	  // Formal is a record. Make sure that all record elements
	  // are associated.
	  pIIR_RecordType record_type = pIIR_RecordType (type_pair.first);
	  const int record_element_count = list_size (record_type->element_declarations);
	  if (range_to_length (composed_range.left, composed_range.dir, composed_range.right ) !=
	      record_element_count)
	    {
	      // Generate error message. To print the error message,
	      // the name for the mising element is generated.
	      const int missing_index = composed_range.left != 0? 0 : record_element_count - 1;
	      vector<StaticRangeDescriptor<lint, IR_Direction> > error_acl = map_iter->first;
	      error_acl.push_back (StaticRangeDescriptor<lint, IR_Direction>
				   (missing_index, IR_DIRECTION_UP, missing_index));
	      codegen_error.error("%:error: not all elements of composite formal '%n' are associated. "
				  "E.g., element %s is un-associated.", 
				  assoc_list, decl, 
				  sprint_object_reference (decl, error_acl, rstack).c_str ());
	      error_count ++;
	    }
	}
    }

  return error_count; 
}


int 
check_associations(pIIR_AssociationList assoc_list, pIIR_InterfaceList interface_list, RegionStack &rstack)
{
  int error_count = 0;

  // Analyze the interface declaration of the corresponding entity,
  // subprogram, ...
  for (pIIR_InterfaceList il = interface_list; il; il = il->rest)
    {
      // Build a list of association elements that belong to the same
      // formal interface object
      pIIR_InterfaceDeclaration decl = il->first;
      list<pIIR_AssociationElement> formal_assoc;
      for (pIIR_AssociationList al = assoc_list; al; al = al->rest)
	if (al->first->formal_declaration == decl)
	  formal_assoc.push_back(al->first);
      // Finally, check associations assocaited with a formal
      error_count += check_association(assoc_list, formal_assoc, decl, rstack);
    }

  return error_count;
}


int
m_explore_and_check(pIIR_ComponentInstantiationStatement cs, RegionStack &rstack, bool collect_access_info)
{
  if (done(cs) & EXPLORED) return 0; else  done(cs) |= EXPLORED;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  // ************************************************************
  // Process generic parameter
  // ************************************************************
  for (pIIR_AssociationList al = cs->binding->generic_map_list;
       al; al = al->rest) {
    pIIR_AssociationElement ae = al->first;

    if (!ae->is(IR_ASSOCIATION_ELEMENT_OPEN))
      error_count += explore_and_check(ae->actual->subtype, rstack, collect_access_info);
    if (collect_access_info) {
      get_context(ae->actual, ctxt, rstack, false, 0);
      get_context(ae->formal, ctxt, rstack, false, 0);
    }
    error_count += constant_fold(ae->actual, rstack);
    error_count += check_expression(ae->actual, rstack);
    error_count += constant_fold(ae->formal, rstack);
    error_count += check_expression(ae->formal, rstack);
  }

  // Check whether all generic parameters without default value are
  // associated and check default value if it is used.
  pIIR_InterfaceList generic_clause = NULL;
  pIIR_InterfaceList port_clause = NULL;
  if (cs->binding->unit->is(IR_ARCHITECTURE_REF)) {
    // An architecture is directly instantiated. Hence, get the port
    // and generic clause of the corresponding entity declaration.
    pIIR_EntityDeclaration entity_decl = pIIR_ArchitectureRef(cs->binding->unit)->entity;
    generic_clause = entity_decl->generic_clause;
    port_clause = entity_decl->port_clause;

  } else if (cs->binding->unit->is(IR_COMPONENT_DECLARATION)) {
    // A *component* is instantiated. Hence, get port and generic
    // clause of the component declaration.
    generic_clause = pIIR_ComponentDeclaration(cs->binding->unit)->local_generic_clause;
    port_clause = pIIR_ComponentDeclaration(cs->binding->unit)->local_port_clause;
  }

  for (pIIR_InterfaceList il = generic_clause; il; il = il->rest) {
    pIIR_InterfaceDeclaration formal = il->first;
    // Find actual associated with a formal
    list<pIIR_AssociationElement> ae_list = find_matching_actuals(cs->binding->generic_map_list, il->first);
    if (ae_list.size() == 0 && formal->initial_value == NULL)
      codegen_error.error("%:error: generic parameter '%n' is left open but has no default value.", cs, formal);
  }

  error_count += check_associations (cs->binding->generic_map_list, generic_clause, rstack);


  // ************************************************************
  // Process port maps
  // ************************************************************
  for (pIIR_AssociationList al = cs->binding->port_map_list;
       al; al = al->rest) {
    pIIR_AssociationElement ae = al->first;

    if (!ae->is(IR_ASSOCIATION_ELEMENT_OPEN))
      error_count += explore_and_check(ae->actual->subtype, rstack, collect_access_info);
    if (collect_access_info) {
      get_context(ae->actual, ctxt, rstack, false, 0);
      get_context(ae->formal, ctxt, rstack, false, 0);
    }
    error_count += constant_fold(ae->actual, rstack);
    error_count += check_expression(ae->actual, rstack);
    error_count += constant_fold(ae->formal, rstack);
    error_count += check_expression(ae->formal, rstack);
  }
  //for (pIIR_AssociationList al = cs->binding->port_map_list;
  //   al; al = al->rest)
  //error_count += explore_and_check(al->first, rstack, collect_access_info);
  error_count += check_associations (cs->binding->port_map_list, port_clause, rstack);

#if 0
  if (cs->binding->unit->is(IR_COMPONENT_DECLARATION)) {
    //****************************************************************************
    // Component shall be instantiated
    //****************************************************************************
    pIIR_BindingIndication config = cs->configuration;
    if (config == NULL ||
	!config->unit->is(IR_ENTITY_DECLARATION)) {
      codegen_error.error("%:error: only component instantiation via default component binding are supported yet."
			  " However, there is no appropriate entity declaration visible at this point in the file!", cs);
      error_count++;
    }
  }
#endif

  return error_count;
}


int
m_explore_and_check(pIIR_ReturnStatement r, RegionStack &rstack, bool collect_access_info)
{
  if (done(r) & EXPLORED) return 0; else  done(r) |= EXPLORED;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  if (r->return_expression != NULL) {
    error_count += explore_and_check(r->return_expression->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(r->return_expression, ctxt, rstack, false, 0);
    error_count += constant_fold(r->return_expression, rstack);
    error_count += check_expression(r->return_expression, rstack);

    // Check return value. If the value could be determined at compile
    // time then try to check the value against the return type.
    if (valid_folded_value(r->return_expression) && 
	is_scalar_type(r->return_expression->subtype))
      error_count += check_scalar_against_bounds(r, get_folded_value(r->return_expression), 
						 pIIR_FunctionDeclaration(r->enclosing_subprogram)->return_type,
						 rstack, runtime_checks(r->return_expression), true, 
						 " illegal return value:");
  }

  return error_count;
}


int
m_explore_and_check(pIIR_AssertionStatement as, RegionStack &rstack, bool collect_access_info)
{
  if (done(as) & EXPLORED) return 0; else  done(as) |= EXPLORED;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  if (as->assertion_condition != NULL) {
    error_count += explore_and_check(as->assertion_condition->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(as->assertion_condition, ctxt, rstack, false, 0);
    error_count += constant_fold(as->assertion_condition, rstack);
    error_count += check_expression(as->assertion_condition, rstack);
  }

  if (as->report_expression != NULL) {
    error_count += explore_and_check(as->report_expression->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(as->report_expression, ctxt, rstack, false, 0);
    error_count += constant_fold(as->report_expression, rstack);
    error_count += check_expression(as->report_expression, rstack);
  }

  if (as->severity_expression != NULL) {
    error_count += explore_and_check(as->severity_expression->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(as->severity_expression, ctxt, rstack, false, 0);
    error_count += constant_fold(as->severity_expression, rstack);
    error_count += check_expression(as->severity_expression, rstack);
  }

  return error_count;
}


int
m_explore_and_check(pIIR_ReportStatement rs, RegionStack &rstack, bool collect_access_info)
{
  if (done(rs) & EXPLORED) return 0; else  done(rs) |= EXPLORED;

  ContextInfo &ctxt = *ActiveContext(rstack);
  int error_count = 0;

  if (rs->report_expression != NULL) {
    error_count += explore_and_check(rs->report_expression->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(rs->report_expression, ctxt, rstack, false, 0);
    error_count += constant_fold(rs->report_expression, rstack);
    error_count += check_expression(rs->report_expression, rstack);
  }

  if (rs->severity_expression != NULL) {
    error_count += explore_and_check(rs->severity_expression->subtype, rstack, collect_access_info);
    if (collect_access_info)
      get_context(rs->severity_expression, ctxt, rstack, false, 0);
    error_count += constant_fold(rs->severity_expression, rstack);
    error_count += check_expression(rs->severity_expression, rstack);
  }

  return error_count;
}


int
m_explore_and_check(pIIR_ProcedureCallStatement pc, RegionStack &rstack, bool collect_access_info)
{
  if (done(pc) & EXPLORED) return 0; else  done(pc) |= EXPLORED;

  int error_count = 0;
  ContextInfo &ctxt = *ActiveContext(rstack);

  // Analyze procedure declaration
  error_count += explore_and_check(pc->procedure, rstack, false);

  for (pIIR_InterfaceList il = pc->procedure->interface_declarations; il; il = il->rest) {
    pIIR_InterfaceDeclaration  idecl = il->first;
    // Find actual that corresponds to formal
    list<pIIR_AssociationElement> a_list = find_matching_actuals(pc->actual_parameter_part, il->first);

    if (a_list.size() > 1) 
      {
	codegen_error.error("%:error: sorry, individual associations are currently not supported for subprograms", pc);
	error_count++;
      }

    pIIR_AssociationElement a = a_list.size() == 0? NULL : a_list.front();

    // check whether the corresponding actual is left open
    if (a != NULL && a->actual != NULL && !a->actual->is(IR_OPEN_EXPRESSION)) {
      // The parameter was NOT left open...
  
      // if the mode is INOUT, OUT or BUFFER then the actual is written 
      if (collect_access_info && 
	  (idecl->mode == IR_INOUT_MODE || 
	   idecl->mode == IR_OUT_MODE ||
	   idecl->mode == IR_BUFFER_MODE))
	get_context(a->actual, ctxt, rstack, true /* = true, because the actual is a target */, 0);
      
      // if the mode is IN or BUFFER then the actual is read 
      if (collect_access_info && 
	  (idecl->mode == IR_INOUT_MODE || 
	   idecl->mode == IR_BUFFER_MODE))
	get_context(a->actual, ctxt, rstack, false, 0);
      
      // We assume that attributes are used for signal parameters
      if (collect_access_info && 
	  a->formal_declaration->is(IR_SIGNAL_INTERFACE_DECLARATION) && 
	  (idecl->mode == IR_IN_MODE ||
	   idecl->mode == IR_INOUT_MODE ||
	   idecl->mode == IR_BUFFER_MODE)) {
	// Collect signals included in the atual expression
	ContextInfo tmp_ctxt;
	get_context(a->actual, tmp_ctxt, rstack, false, 0);
	// Filter signal declarations
	list<AccessDescriptor> sig_list =
	  filter_unique(tmp_ctxt.accessed_objects, ACCESS, 
			tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));
	// Copy access descriptors into current context
	for (list<AccessDescriptor>::iterator it = sig_list.begin(); it != sig_list.end(); it++) {
	  // Only signal primaries are considered
	  if ((*it).level != 0) continue;
	  (*it).access_type |= SIGNAL_FUNCTION_ATTRIBUTE;
	  ctxt.accessed_objects.push_back(*it);
	}
	     
      }

      // fold and check actual expression
      error_count += explore_and_check(a->actual->subtype, rstack, collect_access_info);
      if (collect_access_info)
	get_context(a->actual, ctxt, rstack, false, 0);
      error_count += constant_fold(a->actual, rstack);	
      error_count += check_expression(a->actual, rstack);	

    } else
      // the parameter is left open. Hence, the default value will be used instead. 
      // Explore and check default value if present.
      if (idecl->initial_value != NULL) {
	error_count += explore_and_check(idecl->initial_value->subtype, rstack, collect_access_info);
	if (collect_access_info)
	  get_context(idecl->initial_value, ctxt, rstack, false, 0);
	error_count += constant_fold(idecl->initial_value, rstack);	
	error_count += check_expression(idecl->initial_value, rstack);	
      }
  }

  // Merge accessed object list of the current procedure into the
  // accessed object list of the base region (e.g. procedure, function
  // or proccess)
  if (&ctxt != &context (pc->procedure))
    merge_accessed_objects_lists(ctxt.accessed_objects, ActiveDeclarativeRegion(rstack), 
				 context(pc->procedure).accessed_objects);

  // If the procedure contains wait statements then add the procedure
  // call to the list of waits within the current context.
  if (has_wait (pc->procedure) || has_wait_for (pc->procedure))
    ctxt.wait_statements.push_back (pc);

  // If the base region this procedure was called from is a procedure
  // or a process then merge has_wait_for and has_wait flags
  pIIR_DeclarativeRegion base_region = BaseDeclarativeRegion(rstack);
  if (base_region->is(IR_PROCEDURE_DECLARATION)) {
    has_wait_for (pIIR_ProcedureDeclaration(base_region)) |= has_wait_for (pc->procedure);
    has_wait (pIIR_ProcedureDeclaration(base_region)) |= has_wait (pc->procedure);
  } else if (base_region->is(IR_PROCESS_STATEMENT)) {
    has_wait_for (pIIR_ProcessStatement(base_region)) |= has_wait_for (pc->procedure);
    has_wait (pIIR_ProcessStatement(base_region)) |= has_wait (pc->procedure);
  }

  // Store information about the procedure call into the access
  // descriptor list
  if (collect_access_info)
    ctxt.accessed_objects.push_back(AccessDescriptor(pc->procedure, PROCEDURE_CALL, 0));

  return error_count;
}


int
m_explore_and_check(pIIR_ConcurrentGenerateIfStatement gs, RegionStack &rstack, bool collect_access_info)
{
  if (done(gs) & EXPLORED) return 0; else  done(gs) |= EXPLORED;

  rstack.push(gs);

  int error_count = 0;
  ContextInfo &ctxt = *ActiveContext(rstack);

  if (gs->declarations != NULL) {
    extended_declarations(gs) = build_extended_declaration_list<IIR_DeclarationList, no_filter>(gs->declarations, rstack);
    error_count += explore_and_check(extended_declarations(gs), rstack, collect_access_info);
  }

  error_count += constant_fold(gs->condition, rstack);	
  error_count += check_expression(gs->condition, rstack);
  
  if (gs->concurrent_statement_part != NULL)
    error_count += explore_and_check(gs->concurrent_statement_part, rstack, collect_access_info);

  rstack.pop();

  return error_count;
}


int
m_explore_and_check(pIIR_ConcurrentGenerateForStatement gs, RegionStack &rstack, bool collect_access_info)
{
  if (done(gs) & EXPLORED) return 0; else  done(gs) |= EXPLORED;

  rstack.push(gs);

  int error_count = 0;
  ContextInfo &ctxt = *ActiveContext(rstack);

  if (gs->declarations != NULL) {
    extended_declarations(gs) = build_extended_declaration_list<IIR_DeclarationList, no_filter>(gs->declarations, rstack);
    error_count += explore_and_check(extended_declarations(gs), rstack, collect_access_info);
  }

  error_count += explore_and_check(gs->generate_parameter_specification->subtype, rstack, collect_access_info);
  static_declarative_region (gs->generate_parameter_specification) = 
    ActiveDeclarativeRegion (rstack);

  if (gs->concurrent_statement_part != NULL)
    error_count += explore_and_check(gs->concurrent_statement_part, rstack, collect_access_info);

  rstack.pop();

  return error_count;
}


// ******************************************************************************************
// Name: m_get_context, generic function
//
// Description: Analyzes statements and collects all abjects which are
// accessed. The information about the accessed objects are stored in
// a ContextInfo instance. A ContextInfo instance stores four
// different kinds of information sets: 
//
// 1. accessed_objects = all objects
// which are accessed (read, written, sensitive).
//
// 2. wait_statements = pointer to the wait statements included in the
// current context
//
// 3. signal_assignment_statements = list of pointers to all signal
// assignment statements included in the current context
//
// 4. internal_vars = internal objects required by the generated code
//
// Parameter: ctxt = context info instance
//   target = is true if the expression is target of an assignment
//   level = level the object is located at. The entire statement
// is assigned level 0. The level is increased each time an object is
// included in an argument to a subroutine or an index value of an
// array reference.
// 
// Return value: returns a pointer to the corresponding access
// descriptor if an expression is analyzed. Otherwise, NULL is
// returned.
//
// ******************************************************************************************

pAccessDescriptor
m_get_context(pIIR_AttrTypeFunc a, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  pAccessDescriptor p = get_context(a->prefix, ctxt, rstack, false, level);
  if (a->argument != NULL)
    get_context(a->argument, ctxt, rstack, false, level + 1);

  return p;
}


pAccessDescriptor
m_get_context(pIIR_AttrTypeValue a, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  pAccessDescriptor p = get_context(a->prefix, ctxt, rstack, false, level);
  if (a->argument != NULL)
    get_context(a->argument, ctxt, rstack, false, level + 1);

  return p;
}


pAccessDescriptor
m_get_context(pIIR_AttrArrayFunc a, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  pAccessDescriptor p = NULL;
  if (a->array != NULL)
    p = get_context(a->array, ctxt, rstack, false, level);
  else if (a->array_type != NULL)
    p = get_context(a->array_type, ctxt, rstack, false, level);

  return p;
}




pAccessDescriptor
m_get_context(pIIR_AttrSigFunc aev, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  pAccessDescriptor p = get_context(aev->signal, ctxt, rstack, false, level + 1);
  // Store that an attribute of the signal has been used
  p->access_type |= SIGNAL_FUNCTION_ATTRIBUTE; 

  return p;
}


pAccessDescriptor
m_get_context (pIIR_Type t, ContextInfo &ctxt, RegionStack &rstack,
	       bool target, int level)
{
  ctxt.accessed_objects.push_back(AccessDescriptor(get_declaration(t), TYPE_USED));

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_QualifiedExpression e, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  get_context(e->expression, ctxt, rstack, false, level + 1);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_FunctionCall fc, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  // Store information about the function call into the access
  // descriptor list
  ctxt.accessed_objects.push_back(AccessDescriptor(fc->function, fc, FUNCTION_CALL, level));
  pAccessDescriptor p = &ctxt.accessed_objects.back ();
  // Get context of function parameters
  for (pIIR_InterfaceList il = fc->function->interface_declarations; il; il = il->rest) {
    // Find actual that corresponds to formal
    list<pIIR_AssociationElement> a_list = find_matching_actuals(fc->parameter_association_list, il->first);

    for (list<pIIR_AssociationElement>::iterator iter = a_list.begin();
	 iter != a_list.end();
	 iter++)
      {
	pIIR_AssociationElement a = *iter;
	// Continue if the parameter was NOT left open...
	if (a == NULL || a->actual->is(IR_OPEN_EXPRESSION)) continue;
	
	get_context(a->actual, ctxt, rstack, false, level + 1);
	
	pIIR_InterfaceDeclaration  idecl = il->first;
	// We assume that attributes are used for signal parameters
	if (a->formal_declaration->is(IR_SIGNAL_INTERFACE_DECLARATION) && 
	    (idecl->mode == IR_IN_MODE ||
	     idecl->mode == IR_INOUT_MODE ||
	     idecl->mode == IR_BUFFER_MODE)) {
	  // Collect signals included in the atual expression
	  ContextInfo tmp_ctxt;
	  get_context(a->actual, tmp_ctxt, rstack, false, 0);
	  // Filter signal declarations
	  list<AccessDescriptor> sig_list =
	    filter_unique(tmp_ctxt.accessed_objects, ACCESS, 
			  tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));
	  // Copy access descriptors into current context
	  for (list<AccessDescriptor>::iterator it = sig_list.begin(); it != sig_list.end(); it++) {
	    // Only signal primaries are considered
	    if ((*it).level != 0) continue;
	    (*it).access_type |= SIGNAL_FUNCTION_ATTRIBUTE;
	    ctxt.accessed_objects.push_back(*it);
	  }
	}
      }
  }    

  // Merge accessed object list of the current function into the
  // accessed object list of the base region (e.g. procedure, function
  // or proccess)
  if (&ctxt != &context (fc->function))
    merge_accessed_objects_lists(ctxt.accessed_objects, ActiveDeclarativeRegion(rstack), 
				 context(fc->function).accessed_objects);

  return p;
}


pAccessDescriptor
m_get_context(pIIR_SimpleReference sr, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  if (sr->object->is(IR_SIGNAL_DECLARATION) || sr->object->is(IR_SIGNAL_INTERFACE_DECLARATION) || 
      sr->object->is(IR_VARIABLE_DECLARATION) || sr->object->is(IR_VARIABLE_INTERFACE_DECLARATION) || 
      sr->object->is(IR_CONSTANT_DECLARATION) || sr->object->is(IR_CONSTANT_INTERFACE_DECLARATION) ||
      sr->object->is(IR_FILE_DECLARATION) || sr->object->is(IR_FILE_INTERFACE_DECLARATION) ||
      sr->object->is(IR_ACCESS_REFERENCE)) {
    ctxt.accessed_objects.push_back(AccessDescriptor(sr->object, sr, target? WRITE : READ, level));
    return &ctxt.accessed_objects.back();
  } else
    return NULL;
}



pAccessDescriptor
m_get_context(pIIR_AccessReference ar, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  if (ar != NULL)
    return get_context (ar->access, ctxt, rstack, false, level + 1);
  
  return NULL;
}



pAccessDescriptor
m_get_context(pIIR_ArrayReference ar, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  pAccessDescriptor p = get_context(ar->array, ctxt, rstack, target, level);
  p->access_expr = ar;

  for (pIIR_ExpressionList el = ar->indices; el; el = el->rest)
    get_context(el->first, ctxt, rstack, false, level + 1);

  return p;
}




pAccessDescriptor
m_get_context(pIIR_ArrayRange ar, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  pAccessDescriptor p = NULL;
  if (ar->array != NULL)
    p = get_context(ar->array, ctxt, rstack, false, level);

  if (ar->index != NULL)
    get_context(ar->index, ctxt, rstack, false, level + 1);

  return p;
}


pAccessDescriptor
m_get_context(pIIR_ExplicitRange er, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  get_context(er->left, ctxt, rstack, false, level);
  get_context(er->right, ctxt, rstack, false, level);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_OthersIndexedAssociation ia, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  get_context(ia->value, ctxt, rstack, false, level);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_RangeIndexedAssociation ia, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  get_context(ia->index_range, ctxt, rstack, false, level);
  get_context(ia->value, ctxt, rstack, false, level);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_SingleIndexedAssociation ia, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  if (ia->index != NULL)
    get_context(ia->index, ctxt, rstack, false, level);
  get_context(ia->value, ctxt, rstack, false, level);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_SliceReference sr, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  pAccessDescriptor p = get_context(sr->array, ctxt, rstack, target, level);
  p->access_expr = sr;
  get_context(sr->range, ctxt, rstack, false, level + 1);

  return p;
}



pAccessDescriptor
m_get_context(pIIR_RecordReference rr, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  pAccessDescriptor p = get_context(rr->record, ctxt, rstack, target, level);
  p->access_expr = rr;

  return p;
}




pAccessDescriptor
m_get_context(pIIR_Expression e, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_Allocator a, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  get_context(a->subtype, ctxt, rstack, false, level);
  get_context(pIIR_AccessType(a->type_mark)->designated_type, ctxt, rstack, false, level + 1);
  if (a->value)
    get_context(a->value, ctxt, rstack, false, level + 1);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_ExpressionList el, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  for ( ; el; el = el->rest)
    get_context(el->first, ctxt, rstack, target, level);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_WaitStatement ws, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  if (ws->condition_clause == NULL &&
      ws->timeout_clause == NULL &&
      ws->sensitivity_list == NULL) {
    // If there is no condition clause and no timeout clause and no
    // sensitivity_list then this wait statements shall stop the
    // process for the rest of the simulation time. Hence, nothing has
    // to be done now.
    return NULL;
  }

  // Add ws to the list of wait statements of the current context
  ctxt.wait_statements.push_back(ws);

  if (ws->sensitivity_list) {
    // Wait statemen has an explicit sensitivity list
    for (pIIR_ExpressionList el = ws->sensitivity_list; el; el = el->rest)
      {
	ContextInfo tmp_ctxt;
	get_context(el->first, tmp_ctxt, rstack, false, 0);
	(*tmp_ctxt.accessed_objects.begin()).access_type = SENSITIVE;
	ctxt.accessed_objects.push_back(*tmp_ctxt.accessed_objects.begin());
      }

    if (ws->condition_clause) {
      get_context(ws->condition_clause, ctxt, rstack, false, 0);
    }

  } else {
    // Wait statement does not have an explicit sensitivity
    // list. Hence, extract one from the wait condition.
    ContextInfo tmp_ctxt;
    if (ws->condition_clause != NULL)
      get_context(ws->condition_clause, tmp_ctxt, rstack, false, 0);
    for (access_list::iterator i = tmp_ctxt.accessed_objects.begin(); 
	 i != tmp_ctxt.accessed_objects.end(); i++)
      if ((*i).declaration->is(IR_OBJECT_DECLARATION)) {
	// If the object is a signal then set access_type to
	// SENSITIVE and READ as the process is sensitive on this
	// signal. Otherwise set the access_type to READ as a process
	// can be sensitive on signals only.
	AccessFlags access_type = 
	  ((*i).declaration->is(IR_SIGNAL_DECLARATION) || 
	   (*i).declaration->is(IR_SIGNAL_INTERFACE_DECLARATION))? (SENSITIVE | READ) : READ;
	ctxt.accessed_objects.push_back(AccessDescriptor(pIIR_ObjectDeclaration((*i).declaration), 
							 (*i).access_expr, access_type));
      } else
	// Add remaining access descriptors to access list.
	ctxt.accessed_objects.push_back((*i));
  }

  // Explore timeout expression
  if (ws->timeout_clause) {
    get_context(ws->timeout_clause, ctxt, rstack, false, 0);
  }

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_ArrayAggregate aa, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  // First, determine context of asscociations
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list; al; al = al->rest)
    get_context(al->first, ctxt, rstack, false, level + 1);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_ElementAssociation ea, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  get_context(ea->value, ctxt, rstack, false, level + 1);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_RecordAggregate ra, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  // First, determine context of asscociations
  for (pIIR_ElementAssociationList al = ra->element_association_list; al; al = al->rest)
    get_context(al->first, ctxt, rstack, false, level + 1);

  return NULL;
}


pAccessDescriptor
m_get_context(pIIR_TypeConversion tc, ContextInfo &ctxt, RegionStack &rstack, 
	      bool target, int level)
{
  get_context(tc->expression, ctxt, rstack, false, level + 1);
  
  return NULL;
}




// ******************************************************************************************
// Name: m_check_expression , generic function
//
// Description: checks whether expression is valid and contains no
// errors. Any errors found are reportet. Parameter rstack is a
// reference to the current regions stack
// 
// Return value: returns number of errors which were found in the expression
//
// ******************************************************************************************


int
m_check_expression(pIIR_AttrSigFunc ase, RegionStack &rstack)
{
  int error_count = check_expression(ase->signal, rstack);
  static_declarative_region(ase) = NULL;

  return error_count;
}


int
m_check_expression(pIIR_FunctionCall fc, RegionStack &rstack)
{
  int error_count = 0;

  // Analyze function declaration
  error_count += explore_and_check(fc->function, rstack, false);
  
  list<pIIR_DeclarativeRegion> rlist;
  for (pIIR_AssociationList al = fc->parameter_association_list; al; al = al->rest) {
    error_count += check_expression(al->first->actual, rstack);
    // Store static declarative region of actuals
    rlist.push_back(static_declarative_region(al->first->actual));
  }

  // Check function type
  switch (get_operator_type(fc->function)) {
  case NO_OP:
    // We set the function result to be not static in case of a normal
    // function
    rlist.push_back(ActiveDeclarativeRegion(rstack)); break;
  default:
    // In case of a operator set the static declarative region to the
    // global region
    rlist.push_back(RootDeclarativeRegion(rstack)); break;
  }
  // Determine combined declarative region
  static_declarative_region(fc) = get_combined_static_region(rlist, rstack);

  return error_count;
}



int
m_check_expression(pIIR_SimpleReference sr, RegionStack &rstack)
{
  pIIR_ObjectDeclaration decl = sr->object;

  // Determine static declarative region is simple reference
  if (decl->is(IR_CONSTANT_DECLARATION)) {
      if (valid_folded_value(sr))
	static_declarative_region(sr) = RootDeclarativeRegion(rstack);
      else if (pIIR_ConstantDeclaration(decl)->initial_value != NULL)
	static_declarative_region(sr) = 
	  static_declarative_region(pIIR_ConstantDeclaration(decl)->initial_value);
      else
	static_declarative_region(sr) = RootDeclarativeRegion(rstack);

  } else if (decl->is(IR_CONSTANT_INTERFACE_DECLARATION)) {
    static_declarative_region(sr) = static_declarative_region(decl);

  } else
    static_declarative_region(sr) = NULL;

  return 0;
}



int
m_check_expression(pIIR_AccessReference ar, RegionStack &rstack)
{
  int error_count = check_expression(ar->access, rstack);
  return error_count;
}



int
m_check_expression(pIIR_ArrayReference ar, RegionStack &rstack)
{
  int error_count = check_expression(ar->array, rstack);

  list<pIIR_DeclarativeRegion> rlist;
  rlist.push_back(static_declarative_region(ar->array));
  
  pIIR_Type basic_type = get_basic_type(ar->array->subtype);
  pIIR_TypeList tl = basic_type->is(IR_ARRAY_TYPE) ? 
    pIIR_ArrayType(basic_type)->index_types : pIIR_ArraySubtype(basic_type)->constraint;

  for (pIIR_ExpressionList el = ar->indices; el; el = el->rest, tl = tl->rest) {
    error_count += check_expression(el->first, rstack);
    rlist.push_back(static_declarative_region(el->first));
    // If the index value could be determined then check value against
    // array bounds
    if (valid_folded_value(el->first))
      error_count += 
	check_scalar_against_bounds(el->first, folded_value(el->first).long_value(), tl->first, 
				    rstack, runtime_checks(ar), true);

  }
  // Determine combined declarative region
  static_declarative_region(ar) = get_combined_static_region(rlist, rstack);

  return error_count;
}



int
m_check_expression(pIIR_ArrayRange ar, RegionStack &rstack)
{
  int error_count = 0;
  list<pIIR_DeclarativeRegion> rlist;

  if (ar->array != NULL) {
    error_count += check_expression(ar->array, rstack);
    rlist.push_back(static_declarative_region(ar->array));
  }

  if (ar->index != NULL) {
    error_count += check_expression(ar->index, rstack);
    rlist.push_back(static_declarative_region(ar->index));
    // If the node represents an RANGE or REVERSE_RANGE attribute then
    // check whether the index value is locally static!
    if ((ar->is(IR_ATTR_ARRAY_RANGE) ||
	 ar->is(IR_ATTR_ARRAY_REVERSE_RANGE)) &&
	ar->index->static_level != IR_LOCALLY_STATIC) {
	codegen_error.error("%:error: index parameter of attributes RANGE/REVERSE_RANGE must be locally static", 
			    ar);
	error_count++;
    }
  }
  // Determine combined declarative region
  static_declarative_region(ar) = get_combined_static_region(rlist, rstack);

  return error_count;
}


int
m_check_expression(pIIR_ExplicitRange er, RegionStack &rstack)
{
  int error_count = check_expression(er->left, rstack);
  error_count += check_expression(er->right, rstack);
  static_declarative_region(er) = 
    get_combined_static_region(static_declarative_region(er->left), 
			       static_declarative_region(er->right), 
			       rstack);

  return error_count;
}


int
m_check_expression(pIIR_OthersIndexedAssociation ia, RegionStack &rstack)
{
  int error_count = check_expression(ia->value, rstack);
  static_declarative_region(ia) = static_declarative_region(ia->value);

  return error_count;
}


int
m_check_expression(pIIR_RangeIndexedAssociation ia, RegionStack &rstack)
{
  int error_count = check_expression(ia->index_range, rstack);
  error_count += check_expression(ia->value, rstack);
  static_declarative_region(ia) = 
    get_combined_static_region(static_declarative_region(ia->index_range), 
			       static_declarative_region(ia->value), 
			       rstack);

  return error_count;
}


int
m_check_expression(pIIR_SingleIndexedAssociation ia, RegionStack &rstack)
{
  int error_count = 0;
  list<pIIR_DeclarativeRegion> rlist;

  if (ia->index != NULL) {
    error_count = check_expression(ia->index, rstack);
    rlist.push_back(static_declarative_region(ia->index));
  }
  error_count += check_expression(ia->value, rstack);
  rlist.push_back(static_declarative_region(ia->value));
  static_declarative_region(ia) = get_combined_static_region(rlist, rstack);

  return error_count;
}


int
m_check_expression(pIIR_SliceReference sr, RegionStack &rstack)
{
  int error_count = check_expression(sr->array, rstack);
  error_count += check_expression(sr->range, rstack);
  static_declarative_region(sr) = 
    get_combined_static_region(static_declarative_region(sr->array), 
			       static_declarative_region(sr->range), 
			       rstack);

  return error_count;
}



int
m_check_expression(pIIR_RecordReference rr, RegionStack &rstack)
{
  int error_count = check_expression(rr->record, rstack);
  static_declarative_region(rr) = static_declarative_region (rr->record);

  return error_count;
}




int
m_check_expression(pIIR_Expression e, RegionStack &rstack)
{
  static_declarative_region (e) = valid_folded_value (e)? RootDeclarativeRegion (rstack) : NULL;
  return 0;
}


int
m_check_expression(pIIR_QualifiedExpression e, RegionStack &rstack)
{
  return check_expression(e->expression, rstack);
}


int
m_check_expression(pIIR_ExpressionList el, RegionStack &rstack)
{
  int error_count = 0;
  list<pIIR_DeclarativeRegion> rlist;

  for (pIIR_ExpressionList elp = el; elp; elp = elp->rest) {
    error_count += check_expression(elp->first, rstack);
    rlist.push_back(static_declarative_region(elp->first));
  }
  // Determine combined declarative region
  static_declarative_region(el) = get_combined_static_region(rlist, rstack);

  return error_count;
}



int
m_check_expression (pIIR_RecordAggregate ra, RegionStack &rstack)
{
  int error_count = 0;
  list<pIIR_DeclarativeRegion> rlist;

  // First, determine context of asscociations
  for (pIIR_ElementAssociationList al = ra->element_association_list; al; al = al->rest) {
    error_count += check_expression(al->first->value, rstack);
    error_count += check_for_target_type(al->first->value, al->first->element->subtype, 
					 al->first->value, rstack, runtime_checks(ra), 
					 true, " illegal record aggregate:");
    rlist.push_back(static_declarative_region(al->first));
  }
  // Determine combined declarative region
  static_declarative_region(ra) = get_combined_static_region(rlist, rstack);

  return error_count;
}


int
m_check_expression (pIIR_ArrayAggregate aa, RegionStack &rstack)
{
  int error_count = 0;
  list<pIIR_DeclarativeRegion> rlist;

  // First, determine context of asscociations
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list; al; al = al->rest) {
    error_count += check_expression(al->first, rstack);
    rlist.push_back(static_declarative_region(al->first));
  }
  // Determine combined declarative region
  static_declarative_region(aa) = get_combined_static_region(rlist, rstack);

  // Subtype of aggregate expression. At least the range direction will
  // be used...
  int dim_number = 1;
  pIIR_Type dest_type = aa->subtype;
  if (dest_type->is(VAUL_SUBARRAY_TYPE)) {
    // If the aggreate is an multi-dimensional then a node
    // VAUL_SubarrayType is used to describe the (sub)type of the
    // sub-aggregate. First, determine dimension of the main array the
    // aggregate belongs to
    dest_type = pVAUL_SubarrayType(aa->subtype)->complete_type->declaration->type;
    int dim_counter = 0;
    for (pIIR_TypeList tl = pVAUL_SubarrayType(aa->subtype)->complete_type->index_types; tl; tl = tl->rest)
      dim_counter++;
    // Next, determine the index associated with the array
    // aggregate. Note that we can only count how many dimensions are
    // left from where the aggregate starts.
    int current_dim_counter = 0;
    for (pIIR_TypeList tl = pVAUL_SubarrayType(aa->subtype)->index_types; tl; tl = tl->rest)
      current_dim_counter++;
    // Now, determine the index number of the aggregate
    dim_number = dim_counter - current_dim_counter + 1;

  } else if (dest_type->is(IR_ARRAY_TYPE))
    dest_type = aa->subtype->declaration->type;

  // Get range type of aggregate and determine left bound, right
  // bound, direction and length of aggregat. Note that if the
  // aggregate subtype cannot be determined from the context then
  // dest_range will point to the corresponding index range of the
  // unconstrained array associated with the aggregate.
  dest_length(aa) = -1; 
  known_subtype(aa) = true;
  // Get left and right bound as well as direction of the aggregate. If
  // the bounds are locally static then calculate length of aggregate.
  vector<RangeDescriptor> range_desc = 
    get_discrete_range (dest_type, rstack, IR_NOT_STATIC);
  StaticRangeDescriptor<lint, IR_Direction> range = 
    range_desc[dim_number-1].rangedes_to_lint(rstack);
  dest_direction(aa) = range.dir;
  if (and_reduce(range.valid)) {
    dest_left(aa) = range.left;
    dest_right(aa) = range.right;
    dest_length(aa) = abs(dest_left(aa) - dest_right(aa)) + 1;
  }
  // If type of aggregate is an unconstrained array then set length of
  // aggregate to -1 (unknown) and known_subtype to false.
  if (!is_constrained_array_type(aa->subtype)) {
    dest_length(aa) = -1;
    known_subtype(aa) = false;
  }

  has_others(aa) = false; // Is set to true if aggregate includes others choice
  min_index(aa) = INT_MAX; // Min index value
  max_index(aa) = INT_MIN; // Max index value
  locally_static_ranges(aa) = true; // We assume that all choice ranges are locally static
  total_length(aa) = -1; // Total length
  int choice_counter = 0;

  /* First, take a look at all choices to determine the number of
   * choices, whether an others choice is present and determine low
   * and high index range values. */
  int named_association_count = 0;
  int positional_association_count = 0;
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list; al; al = al->rest) { 

    if (al->first->is(IR_SINGLE_INDEXED_ASSOCIATION)) { // Single indexed association
      pIIR_SingleIndexedAssociation saa = pIIR_SingleIndexedAssociation(al->first);
      int value;
      total_length(aa) = max(total_length(aa), 0) + 1; // Increment length (min length is 1)
      if (saa->index != NULL) {	// Named association
	named_association_count++;
	if (expr_to_int(saa->index, value, rstack)) {
	  // Determine min/max values
	  min_index(aa) = min(value, min_index(aa));
	  max_index(aa) = max(value, max_index(aa));
	  // Set values of choice
	  min_index(saa) = value;
	  max_index(saa) = value;
	  locally_static_range(saa) = true;
	  length(saa) = 1;
	} else {
	  locally_static_ranges(aa) = false;
	  locally_static_range(saa) = false;
	}

      } else { // Positional association
	positional_association_count++;
	locally_static_range(saa) = true;
	length(saa) = 1;
	// Store number of choice into min_index and
	// max_index. Further, max_index of the aggregate expression
	// is set to the current choice counter and min_index of the
	// aggregate expression is set to 0.
	min_index(saa) = choice_counter;
	max_index(saa) = choice_counter;
	max_index(aa) = choice_counter;
	min_index(aa) = 0;
      }

    } else if (al->first->is(IR_RANGE_INDEXED_ASSOCIATION)) { // Range association
      named_association_count++; // Range indexed association is
      // always named association
      pIIR_RangeIndexedAssociation raa = pIIR_RangeIndexedAssociation(al->first);
      vector<RangeDescriptor> range_desc = 
	get_discrete_range(raa->index_range, rstack, IR_NOT_STATIC);
      StaticRangeDescriptor<lint, IR_Direction> range = 
	range_desc[0].rangedes_to_lint(rstack);
      if (and_reduce(range.valid)) {
	// Test whether range bound matches the direction
	if (range.left == range.right ||
	    (range.left < range.right && range.dir == IR_DIRECTION_UP) ||
	    (range.left > range.right && range.dir == IR_DIRECTION_DOWN)) {
	  // Determine min/max values
	  min_index(aa) = min(int(range.left), min_index(aa));
	  max_index(aa) = max(int(range.left), max_index(aa));
	  min_index(aa) = min(int(range.right), min_index(aa));
	  max_index(aa) = max(int(range.right), max_index(aa));
	  // Update length (min length is 1)
	  total_length(aa) = max((lint)max(total_length(aa), 0) + lint_abs(range.left - range.right) + 1, (lint)1); 
	  // Set values of choice
	  min_index(raa) = int(min(range.left, range.right));
	  max_index(raa) = int(max(range.left, range.right));
	  locally_static_range(raa) = true;
	  length(raa) = lint_abs(range.left - range.right) + 1;
	}
      } else {
	locally_static_ranges(aa) = false;
	locally_static_range(raa) = false;
      }
      
    } else if (al->first->is(IR_OTHERS_INDEXED_ASSOCIATION)) // Others clause
      has_others(aa) = true;

    choice_counter++; // Increment counter
  }

  // Set named_association flag to false if at least one positional
  // association was found.
  if (positional_association_count != 0) 
    named_association(aa) = false;
  else
    named_association(aa) = true;


  // Check whether only named or only positional association has been used
  if (named_association_count != 0 && positional_association_count != 0)
    codegen_error.error("%:error: array aggregates cannot contain positional and named associations", aa);

  // Check whether all ranges are locally static if more than a single
  // choice was given
  if (!locally_static_ranges(aa)) {
    assert(choice_counter == 1);
    return error_count;
  }

  // Next, make some checks to test the range of the choices. First,
  // check whether ranges do not overlap. 
  vector<int> from_vec, to_vec;
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list; al; al = al->rest) { 
    if (al->first->is(IR_OTHERS_INDEXED_ASSOCIATION)) continue;
    // Check new range against previous ranges
    for (unsigned int i = 0; i < from_vec.size(); i++) {
      if ((min_index(al->first) <= from_vec[i] && max_index(al->first) >= from_vec[i]) ||
	  (min_index(al->first) <= to_vec[i] && max_index(al->first) >= to_vec[i]))
	codegen_error.error("%:error: choice ranges do overlap (%i to %i conflicts with %i to %i)", 
			    aa, min_index(al->first), max_index(al->first), from_vec[i], to_vec[i]);
    }
    // Add new index range to vectors
    from_vec.push_back(min_index(al->first));
    to_vec.push_back(max_index(al->first));
  }
  // If aggregate has others choice then we are done
  if (has_others(aa)) 
    return error_count;
  
  // Otherwise, check whether there are no "holes" between the
  // ranges. We already checked that the ranges do not overlap. Hence,
  // we simply sort both arrays from_vec and to_vec which will move
  // associated entries in both vectors to the SAME position.
  sort(from_vec.begin(), from_vec.end());
  sort(to_vec.begin(), to_vec.end());
  for (unsigned int i = 1; i < from_vec.size(); i++)
    if (to_vec[i - 1] + 1 != from_vec[i]) {
      codegen_error.error("%:error: index %i of aggregate is undefined", 
			  aa, from_vec[i] - 1);
      return error_count + 1;
    }

  // Test whether the length as determined from the choices matches
  // the length of the aggregate subtype (if this length is known from
  // the context).
  if (dest_length(aa) != -1 &&
      dest_length(aa) != total_length(aa)) {
    codegen_error.error("%:error: length of array aggregate (=%i) does not match length of target (=%i)",
			aa, total_length(aa), dest_length(aa));
    error_count++;
  }

  return error_count;
}



int
m_check_expression (pIIR_ArrayLiteralExpression ale, RegionStack &rstack)
{
  int error_count = 0;

  // Bail out if the array element is not an enumeration type
  if (!get_base_type(ale->subtype)->is(IR_ARRAY_TYPE) ||
      !get_base_type(pIIR_ArrayType(get_base_type(ale->subtype))->element_type)->is(IR_ENUMERATION_TYPE)) {
    codegen_error.error("%:error: array element type is not an enumeration type", ale);
    error_count++;
    
    return error_count;
  }

  pIIR_EnumerationType etype = 
    pIIR_EnumerationType(get_base_type(pIIR_ArrayType(get_base_type(ale->subtype))->element_type));
  pIIR_EnumerationLiteralList enum_items = etype->enumeration_literals; // Get list of enumeration items
  assert(ale->value->is(IR_TEXT_LITERAL));

  // Determine max and minimal valid position number of the
  // enumeration items
  int min_pos, max_pos;
  pIIR_Type basic_etype = get_basic_type(pIIR_ArrayType(get_base_type(ale->subtype))->element_type);

  if (basic_etype->is(IR_SCALAR_SUBTYPE)) {
    // If the basic type is an scalar subtype then min and max pos
    // values are given by the corresponding position numbers of the
    // range.
    vector<RangeDescriptor> rdesc = get_discrete_range(basic_etype, rstack, IR_NOT_STATIC);
    StaticRangeDescriptor<lint, IR_Direction> range = 
      rdesc[0].rangedes_to_lint(rstack);
    min_pos = range.valid[0]? range.left : 0;
    max_pos = range.valid[2]? range.right : INTEGER_MAX;

  } else {
    // If the basic type is an scalar enumeration type then min pos
    // value is 0 and max pos value is determined from the number of
    // enumeration items
    pIIR_EnumerationType et = pIIR_EnumerationType(etype);
    min_pos = 0;
    max_pos = enum_item_number(et) - 1;
  }

  // Determine length of literal array
  char *literal = pIIR_TextLiteral(ale->value)->text.to_chars();
  int length = strlen(literal) - 2; // don't count leading and trailing \" 

  // Now, convert each element of the literal into an corresponding
  // number 
  for (int i = 1; i < length + 1; i++) {
    string literal_str = string("'") + literal[i] + string("'");
    int enum_pos = literal_to_pos(enum_items, literal_str); // Get pos number of literal item
    if (enum_pos < min_pos || enum_pos > max_pos) { // Bail out if number is not valid
      codegen_error.error("%:error: character %s does not belong to enumertion type %n",
			  ale, literal_str.c_str(), basic_etype);
      error_count++;
    }
  }

  return error_count;
}


/* Returns whether two types are closley related */
bool 
is_closely_related(pIIR_Type type1, pIIR_Type type2)
{
  pIIR_Type base_type1 = get_base_type(type1);
  pIIR_Type base_type2 = get_base_type(type2);

  // Two array types are closley related only if they have the same
  // dimensionality, their index types are closley related and the
  // element types are the same.
  if (is_array_type(base_type1)) {
    if (!is_array_type(base_type2)) return false;
    pIIR_ArrayType atype1 = pIIR_ArrayType(base_type1);
    pIIR_ArrayType atype2 = pIIR_ArrayType(base_type2);
    // check element types
    if (get_base_type(atype1->element_type) != get_base_type(atype2->element_type)) 
      return false;
    // Check index types
    pIIR_TypeList tl1 = atype1->index_types, tl2 = atype2->index_types;
    for ( ; tl1 != NULL && tl2 != NULL; tl1 = tl1->rest, tl2 = tl2->rest)
      if (!is_closely_related(tl1->first, tl2->first)) return false;
    // Finally, check whether the arrays have the same dimensionality
    return tl1 == tl2;
  }

  // Floating point types are closely related to integer types
  if ((base_type1->is(IR_FLOATING_TYPE) || base_type1->is(IR_INTEGER_TYPE)) &&
      (base_type2->is(IR_FLOATING_TYPE) || base_type2->is(IR_INTEGER_TYPE)))
    return true;

  // All other types are closely related to themself
  return base_type1 == base_type2;
}


int
m_check_expression (pIIR_TypeConversion tc, RegionStack &rstack)
{
  int error_count = 0;

  // Check expression that shal lbe converted
  error_count += check_expression(tc->expression, rstack);
  
  pIIR_Type target_base_type = get_base_type(tc->type_mark);
  pIIR_Type source_base_type = get_base_type(tc->expression->subtype);

  if (is_scalar_type(target_base_type)) {
    // ********************************************************************
    // Target type is a scalar
    // ********************************************************************
    if (!is_closely_related(tc->type_mark, tc->expression->subtype)) {
      codegen_error.error("%:error: illegal type conversion: "
			  "target type %n is not closely related to operand type %n.",
			  tc, target_base_type, source_base_type);
      error_count++;
      valid_folded_value(tc) = false;
      return error_count;
    }
    // If the converion expression could not be folded then the result
    // must be checked at runtime.
    if (!valid_folded_value(tc->expression))
      runtime_checks(tc) |= RT_CHECK_LEFT_BOUND | RT_CHECK_RIGHT_BOUND;

    return error_count;
    
  } else if (is_array_type(target_base_type)) {
    // ********************************************************************
    // Target type is an array
    // ********************************************************************
    // Two array types are closley related only if they have the same
    // dimensionality, their index types are closley related and the
    // element types are the same.
    if (!is_closely_related(target_base_type, source_base_type)) {
      if (!is_array_type(source_base_type)) {
	codegen_error.error("%:error: non array type %n cannot be converted into array type %n.",
			    tc, source_base_type, target_base_type);
      } else {
	pIIR_ArrayType atype1 = pIIR_ArrayType(target_base_type);
	pIIR_ArrayType atype2 = pIIR_ArrayType(source_base_type);
	// check element types
	if (get_base_type(atype1->element_type) != get_base_type(atype2->element_type))
	  codegen_error.error("%:error: illegal type conversion: "
			      "the element type (=%n) of target array type %n differs from "
			      "element type (=%n) of operand array type %n.",
			      tc, get_base_type(atype1->element_type), target_base_type, 
			      get_base_type(atype2->element_type), source_base_type);
	// Check index types
	pIIR_TypeList tl1 = atype1->index_types, tl2 = atype2->index_types;
	int dim_counter1 = 0, dim_counter2 = 0;
	for ( ; tl1 != NULL && tl2 != NULL; tl1 = tl1->rest, tl2 = tl2->rest) {
	  if (!is_closely_related(tl1->first, tl2->first))
	    codegen_error.error("%:error: illegal type conversion: "
				"index type %n of target array type %n is not closely related to "
				"the corresponding index type %n of operand array type %n.",
				tc, tl1->first, target_base_type, 
				tl2->first, source_base_type);
	  dim_counter1++;
	  dim_counter2++;
	}

	// Finally, check whether the arrays have the same dimensionality
	if (dim_counter1 != dim_counter2) 
	    codegen_error.error("%:error: illegal type conversion: "
				"target and operand type do not have the same dimensionality. "
				"Dimension of target type %n is %i while dimension of operand type %n is %i.",
				tc, target_base_type, dim_counter1, 
				source_base_type, dim_counter2);
      }

      error_count++;
      return error_count;
    }
  }

  return error_count;
}



// ******************************************************************************************
// Name: m_get_static_level , generic function
//
// Description: Determines static level of an type or expression
// 
// Return value: returns static level
//
// ******************************************************************************************

IR_StaticLevel
m_get_static_level (pIIR_Type t, RegionStack &rstack)
{
  return t->static_level;
}

IR_StaticLevel
m_get_static_level (pIIR_Expression e, RegionStack &rstack)
{
  return e->static_level;
}
