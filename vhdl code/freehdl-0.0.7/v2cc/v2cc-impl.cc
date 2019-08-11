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


void
emit_subprogram_associations (string &str, RegionStack &rstack, pIIR_AssociationList assocs, 
			      pIIR_InterfaceList formals, list<AccessDescriptor> &extra_parameter)
{
  string separator = "";

  // ****************************************************************************
  // Add normal subprogram parameter
  // ****************************************************************************
  for (pIIR_InterfaceList fl = formals; fl; fl = fl->rest) {
    pIIR_InterfaceDeclaration par = fl->first; // select formal parameter

    /* Select association element from an association list which
     * corresponds with given formal */
    list<pIIR_AssociationElement> a_list = find_matching_actuals(assocs, par); 
    assert (a_list.size() <= 1); // Only simple assoication is currently supported here!
    pIIR_AssociationElement a = a_list.size() == 0? NULL : a_list.front();
    
    str += separator;
    
    if (a != NULL && !a->actual->is(IR_OPEN_EXPRESSION)) {
      // An actual is associated with the formal
      if (a->formal_conversion)  {
	str += "/* converted by ";
	emit_id (a->formal_conversion, str, rstack);
	str += " */";
      }

      // *******************************************************
      // Handle signal parameter
      // *******************************************************
      if (par->is(IR_SIGNAL_INTERFACE_DECLARATION)) {
	// First, append sig_info pointer
	emit_expr (a->actual, str, rstack, SIGNAL);
	// Next, append reader if signal is of mode in or inout or buffer
	if (par->mode == IR_IN_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	  str += ",";
	  emit_expr (a->actual, str, rstack, READER);
	}
	// Finally, append driver if mode is of out or inout or buffer
	if (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	  str += ",";
	  emit_expr (a->actual, str, rstack, DRIVER);
	}
	
      } else
	// *******************************************************
	// Handle normal parameter (non signal)
	// *******************************************************
	emit_expr (a->actual, str, rstack, id_type(READER, DEREF));
      
    } else if (par->initial_value != NULL)
      // If the parameter was left open then insert the default
      // value if one is defined in the interface declaration
      emit_expr (par->initial_value, str, rstack, DEFAULT);
    
    else 
      // If no default value is defined for the formal then create a
      // dummy instance of the appropriate type
      str += create_default_instance(par->subtype, rstack);
    
    
    separator = ",";
  }
  
  // ****************************************************************************
  // Add extra subprogram parameter
  // ****************************************************************************
  for (list<AccessDescriptor>::iterator iter = extra_parameter.begin();
       iter != extra_parameter.end(); iter++) {
    pIIR_Declaration par = (*iter).declaration;

    if (par->is(IR_VARIABLE_INTERFACE_DECLARATION) ||
	par->is(IR_VARIABLE_DECLARATION) ||
	par->is(IR_CONSTANT_INTERFACE_DECLARATION) ||
	par->is(IR_CONSTANT_DECLARATION) ||
	par->is(IR_FILE_DECLARATION) ||
	par->is(IR_FILE_INTERFACE_DECLARATION)) {
      str += separator + qid(par, rstack, DEFAULT);
 
    } else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION) ||
	       par->is(IR_SIGNAL_DECLARATION)) {
      pIIR_ObjectDeclaration opar = pIIR_ObjectDeclaration(par);
      AccessFlags &aflags = (*iter).access_type;
      // Add sign_info pointer if a signal function kind attribute has
      // been applied on the parameter
      if ((aflags & SIGNAL_FUNCTION_ATTRIBUTE)  ||
	  (aflags & SENSITIVE)) {
	str += separator + qid(par, rstack, SIGNAL);
	separator = ",";
      }
      // Next, append reader if signal is read
      if (aflags & READ) {
	str += separator + qid(par, rstack, READER);
	separator = ",";
      }
      // Finally, append driver if signal is written
      if (aflags & WRITE)
	str += separator + qid(par, rstack, DRIVER);

    } else if (par->is(IR_TYPE_DECLARATION) ||
	       par->is(IR_SUBTYPE_DECLARATION)) {
      // A type has been used and we need to pass over the type info
      // pointer of that type!
      str += separator + qid(par, rstack, INFO) + "_INFO";

    } else
      continue;

    // Set separator for next parameter
    separator = ",";
  }

}


// create code to initialize VHDL objects
void
emit_decls_init_item (pIIR_DeclarationList dl, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration type = NULL;
  string type_str = "";
  string init_str = "";
  string info_str = "";
  bool complex_info = false;
  pIIR_Declaration decl = pIIR_Declaration(dl->first);

  //***********************************************************************
  // first, check whether a info object has to be created at
  // runtime. This is required e.g. for objects of an implicit
  // created array subtype.
  // (e.g.: "variable var : bit_vector(0 to 3)")
  //***********************************************************************
  if (decl->is(IR_OBJECT_DECLARATION) &&
      pIIR_ObjectDeclaration(decl)->alias_base != NULL) {
    
  } else if (decl->is(V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR)) {
    // If this signal has not been used then do not output any
    // initialization for it!
    pV2CC_ImplicitSignalDeclaration_WaitFor obj = pV2CC_ImplicitSignalDeclaration_WaitFor(decl);
    info_str = "&L3std_Q8standard_I7boolean_INFO";
    complex_info = false;
    type = NULL;
    
  } else if (decl->is(IR_SIGNAL_DECLARATION) ||
	     decl->is(IR_VARIABLE_DECLARATION) ||
	     decl->is(IR_CONSTANT_DECLARATION)) {
    // currently, only signals, variables and constants are considered.
    // Try to find the corresponding type declaration.
    pIIR_ObjectDeclaration obj = pIIR_ObjectDeclaration(decl);
    complex_info = is_implicit_array_subtype(pIIR_ObjectDeclaration(decl)->subtype);
    type = get_declaration(obj->subtype);
    info_str = get_type_info_obj(obj->subtype, rstack, false);
    
  } else if (decl->is(V2CC_INTERNAL_OBJECT_DECLARATION)) {
    
  } else if (decl->is(IR_TYPE_DECLARATION)) {
    
  } else if (decl->is(IR_FILE_DECLARATION)) {
    
  } else if (decl->is(IR_SUBPROGRAM_DECLARATION)) {
    
  } else
    // all other kind of objects are not considered
    return;
  
  
  //***********************************************************************
  // Now, generate code to initialize objects depending on the object type
  //***********************************************************************
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
      
      if (is_array_type(alias_decl->subtype)) {
	// **************************************************************************
	// Array alias
	// **************************************************************************
	// Array alias objects are declared via a special array type
	// array_alias
	string array_info_str, array_data_str;
	
	// Check whether the aliased array is an array slice or the
	// entire array shall be aliased
	if (alias_decl->alias_base->is(IR_SLICE_REFERENCE)) {
	  pIIR_SliceReference sr = pIIR_SliceReference(alias_decl->alias_base);
	  // Get slice range
	  vector<RangeDescriptor> range_desc = get_discrete_range(sr, rstack, IR_NOT_STATIC);
	  StaticRangeDescriptor<string, string> range = 
	    range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));
	  // The array data pointer points to the left element of the slice
	  array_data_str += "&";
	  emit_expr(sr->array, array_data_str, rstack, id_type(READER, DEREF));
	  array_data_str += "[" + range.left + "]";
	  // Assume that no subtype is specified for the alias
	  // name. Hence, the array_info object is derived from the
	  // slice range.
	  array_info_str = create_array_info_obj(sr->subtype, sr->range, rstack, false);
	  
	} else {
	  // The entire array shall be aliased
	  emit_expr(alias_decl->alias_base, array_data_str, rstack, id_type(READER, DEREF));
	  array_data_str += ".data";
	  // Assume that no subtype is specified for the alias
	  // name. Hence, the array_info object is derived from the
	  // aliased array.
	  emit_expr(alias_decl->alias_base, array_info_str, rstack, id_type(READER, DEREF));
	  array_info_str += ".info";
	}
	
	// Compare subtypes of the alias array and the aliased
	// array. If they are equal then we assume that the array
	// subtype is dereived from the aliased array.
	if (alias_decl->subtype != alias_decl->alias_base->subtype)
	  array_info_str = get_type_info_obj(alias_decl->subtype, rstack, false);
	
	// Print line and file info
	last_pos_info = emit_posinfo(decl->pos, str, last_pos_info, l);
	
	str += spaces(l) + qid(decl, rstack, id_type()) + ".set(" + array_info_str + ", " + array_data_str + ");\n";
	
      } else {
	// Print line and file info
	last_pos_info = emit_posinfo(decl->pos, str, last_pos_info, l);
	
	// **************************************************************************
	// Remaining aliases
	// **************************************************************************
	// The other alias objects are implemented via
	// pointers. Hence, initialize the pointer with the address
	// of the aliased object address
	str += spaces(l) + qid(decl, rstack, id_type()) + "=&";
	emit_expr(alias_decl->alias_base, str, rstack, id_type(READER, DEREF));
	str += ";\n";
      }
      
    } else {
      codegen_error.error("%:error: sorry, this alias declaration is curently not supported", decl);
      exit(1);
    }
    
    
  } else if (decl->is(V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR)) { 
    // **************************************************************************
    // declaration of an implicit signal to handle waits with timeouts
    // **************************************************************************
    pV2CC_ImplicitSignalDeclaration_WaitFor sig = pV2CC_ImplicitSignalDeclaration_WaitFor(decl);
    // Print line and file info
    last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);
    // Create a new sig_info instance
    str += spaces(l) + qid(sig, rstack, id_type()) + string("=new sig_info<enumeration > ");
    str += "(iname, \":" + nid(sig->declarative_region,BARE) + ":" + nid(sig,BARE) + "\",\"" + 
      get_long_name(sig->declarative_region) + "\"," +
      info_str + ",vREGISTER,this);\n";
    
    
  } else if (decl->is(IR_SIGNAL_DECLARATION)) { 
    // **************************************************************************
    // signal declaration
    // **************************************************************************
    pIIR_SignalDeclaration sig = pIIR_SignalDeclaration(decl);
    // If the current signal is declared within a package then the scope
    // reference pointer from the package is passed over to the sig_info
    // constructor. Otherwise, the pointer to the current architecture
    // (or other declarative region) is used.
    string sref = is_PackageDeclarativeRegion(sig->declarative_region)? "sref" : "this";
    
    // Print line and file info
    last_pos_info = emit_posinfo(sig->pos, str, last_pos_info, l);
    
    // Create a new sig_info instance
    string type_str = type != NULL? qid(type, rstack, TYPE) : "enumeration";
    str += spaces(l) + qid(sig, rstack, id_type()) + string("=new sig_info<") + type_str + " > ";
    str += "(iname, \":" + nid(sig,BARE) + "\",\"" + get_long_name(sig->declarative_region) + "\"," +
      info_str + ",vREGISTER," + sref + ");\n";
    
    // generate code which initializes the object if an initial
    // value was given in the object declaration
    if (sig->initial_value) 
      {
	// Print line and file info
	last_pos_info = emit_posinfo(sig->pos, str, last_pos_info, l);
	
	str += spaces(l) + qid(sig, rstack, id_type()) + "->init(" ;
	emit_expr (sig->initial_value, str, rstack, DEFAULT);
	str += ");\n";
      }
    
    
  } else if (decl->is(IR_CONSTANT_DECLARATION) ||
	     decl->is(IR_VARIABLE_DECLARATION)) {
    // **************************************************************************
    // constant or variable declaration
    // **************************************************************************
    if (!pIIR_ObjectDeclaration(decl)->subtype->is(IR_ACCESS_TYPE) && 
	(complex_info || !is_scalar_type(pIIR_ObjectDeclaration(decl)->subtype)) &&
	(!is_array_type (pIIR_ObjectDeclaration(decl)->subtype) ||
	 is_constrained_array_type (pIIR_ObjectDeclaration(decl)->subtype))) {
      // if the corresponding info object is created at runtime or
      // the object is of a composite type then assign this info
      // instance to the object
      pIIR_Type base_subtype = get_base_type(pIIR_ObjectDeclaration(decl)->subtype);
      // If the object is an one-dimensional array of scalars then
      // determine the initial value of the scalars and pass it over
      // as an addditional argument to the init method. This helps
      // speeding up array initialization.
      string elem_init_value = "";
      if (is_array_type(base_subtype) &&
	  pIIR_ArrayType(base_subtype)->index_types->rest == NULL &&
	  is_scalar_type(pIIR_ArrayType(base_subtype)->element_type)) {
	// Get range of element type and determine left
	// bound. Usually, the left bound can be determined at
	// compile time. However, in some cases code must be
	// generated to access the info instance of the element
	// type.
	pIIR_Type element_type = pIIR_ArrayType(base_subtype)->element_type;
	vector<RangeDescriptor> range_desc = get_discrete_range(element_type, rstack, IR_NOT_STATIC);
	StaticRangeDescriptor<string, string> range = 
	  range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));
	elem_init_value = "," + range.left;
      }
      
      str += spaces(l) + qid(decl, rstack, id_type()) + ".init(" + info_str + elem_init_value + ");\n";
    }
    
    // skip if there is no initial value
    if (pIIR_ObjectDeclaration(decl)->initial_value != NULL &&
	is_array_type (pIIR_ObjectDeclaration(decl)->subtype) &&
	!is_constrained_array_type (pIIR_ObjectDeclaration(decl)->subtype) &&
	!is_constrained_array_type (pIIR_ObjectDeclaration(decl)->initial_value->subtype)) {
      // Enter this part if there is an initial value and the type of
      // the object is an unconstrained array and the type of the
      // initial value is also unconstrained. This might happen if the
      // initial value is determined from a function call that returns
      // an unconstrained array. In this case, the bounds of this
      // initial value are determined at runtime.
      id_type id = get_default_id_type(rstack);
      
      // Print line and file info
      last_pos_info = emit_posinfo(decl->pos, str, last_pos_info, l);
      
      str += spaces(l) + qid(decl, rstack, id_type()) + ".init(const_pointer(" ;
      emit_expr(((pIIR_ObjectDeclaration)decl)->initial_value, str, rstack, id);
      str += "));\n";

      // skip if there is no initial value
    } else if (pIIR_ObjectDeclaration(decl)->initial_value != NULL) {
      // processes or subprograms access objects declared within the
      // entity/architecture via pointers
      id_type id = get_default_id_type(rstack);
      
      // Print line and file info
      last_pos_info = emit_posinfo(decl->pos, str, last_pos_info, l);
      
      str += spaces(l) + qid(decl, rstack, id_type()) + "=" ;
      emit_expr(((pIIR_ObjectDeclaration)decl)->initial_value, str, rstack, id);
      str += ";\n";
      
    } else if (decl->is(IR_VARIABLE_DECLARATION)) {
      // Next, handle variable declarations without explicit initial
      // value
      id_type id = get_default_id_type(rstack);
      
      if (is_scalar_type(pIIR_VariableDeclaration(decl)->subtype)) {
	// Variable is scalar!
	// Get range of scalar subtype
	vector<RangeDescriptor> range_desc = 
	  get_discrete_range(pIIR_VariableDeclaration(decl)->subtype, rstack, IR_NOT_STATIC);
	
	// Print line and file info
	last_pos_info = emit_posinfo(decl->pos, str, last_pos_info, l);
	
	range_desc[0].constant_fold_rangedes(rstack);
	StaticRangeDescriptor<string, string> range = 
	  range_desc[0].rangedes_to_string(rstack, id);
	
	if (range.valid[0]) 
	  // If left bound is locally static then determine left
	  // bound at compile time
	  str += spaces(l) + qid(decl, rstack, id_type()) + "=" + range.left + ";\n";
	else
	  // If range is not locally static then use info pointer to
	  // determine intial value.
	  str += spaces(l) + qid(decl, rstack, id_type()) + "=" + info_str + "->left_bound;\n";
	
      } else if (pIIR_VariableDeclaration(decl)->subtype->is(IR_ACCESS_TYPE)) {
	// Variable is of an access type
	str += spaces(l) + qid(decl, rstack, id_type()) + "=NULL;\n";
	
      }
    }
    
    // Emit code to register constant/variable
    if (codegen_options.get_emit_register_code () && 
	!decl->declarative_region->is(IR_SUBPROGRAM_DECLARATION)) {
      pIIR_ObjectDeclaration odecl = pIIR_ObjectDeclaration(decl);
      
      // The current C++ source code is not associated with any real
      // VHDL source line
      last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);
      
      str += spaces(l);
      if (odecl->is(IR_VARIABLE_DECLARATION))
	str += "register_variable(&";
      else if (odecl->is(IR_CONSTANT_DECLARATION))
	str += "register_constant(&";
      
      // Get type_info pointer for object. If the object is scalar or
      // an access type then the pointer is retrieved from the
      // corresponding type. Otherwise the type_info pointer can be
      // extracted from the object itself (e.g., if the object is an
      // array then the type_info pointer is stored in the array
      // object).
      string info_str = 
	is_scalar_type(odecl->subtype) || 
	get_base_type (odecl->subtype)->is (IR_ACCESS_TYPE) ? 
	get_type_info_obj(odecl->subtype, rstack, false) :
	qid(odecl, rstack, id_type()) + ".info";

      string sref = "this";
      if (is_PackageDeclarativeRegion(odecl->declarative_region))
	sref = "sref";
      else if (static_declarative_region(odecl) == RootDeclarativeRegion(rstack))
	sref = "NULL";
      str += qid(odecl, rstack, id_type()) + ",\"" + get_long_name(odecl->declarative_region) + "\",\":" + 
	nid(odecl, BARE) + "\"," + info_str + "," + sref + ");\n";
    }
    
    
  } else if (decl->is(IR_FILE_DECLARATION)) {
    // ******************************************************************
    // initialize file object
    // ******************************************************************
    pIIR_FileDeclaration file_decl = pIIR_FileDeclaration(decl);
    
    // Print line and file info
    last_pos_info = emit_posinfo(file_decl->pos, str, last_pos_info, l);
    
    // File name given?
    if (file_decl->file_logical_name == NULL) return;
    // Add an corresponding call to file open
    str += spaces(l) + "file_open(" + qid(file_decl, rstack, id_type()) + ",";
    emit_expr(file_decl->file_logical_name, str, rstack, id_type(READER, DEREF));
    str += ",";
    if (file_decl->file_open_expression != NULL)
      emit_expr(file_decl->file_open_expression, str, rstack, id_type(READER, DEREF));
    else
      // If no open expression is present then set file mode to READ_MODE
      str += "enumeration(0)"; 
    str += ");\n";
    
    
  } else if (decl->is(V2CC_INTERNAL_OBJECT_DECLARATION)) {
    // ******************************************************************
    // initialize internal variables
    // ******************************************************************
    // Note that the process code must be emitted first because some 
    // internal variables are not created before code emission!       
    pV2CC_InternalObjectDeclaration obj = pV2CC_InternalObjectDeclaration(decl);
    
    // The current C++ source code is not associated with any real
    // VHDL source line
    last_pos_info = emit_posinfo(obj->pos != NULL? obj->pos : NO_SOURCE_LINE, 
				 str, last_pos_info, l);
    
    // Skip initialization if no inital value is given
    if (obj->cpp_initial_string == "" && obj->initial_value == NULL)
      return;
    init_str = get_internal_object_initial_string(obj, rstack);
    str += spaces(l) + obj->declarator->text.to_chars() + init_str + ";\n";
    
    
  } else if (decl->is(IR_TYPE_DECLARATION)) {
    // ******************************************************************
    // Declare a new type/subtype
    // ******************************************************************
    pIIR_TypeDeclaration tdecl = pIIR_TypeDeclaration(decl);
    pIIR_Type type = tdecl->type;
    string hdr, impl, info_init;
    emit_hdr(type, hdr, rstack, 0);
    emit_impl(type, impl, rstack, 0);
    // add internal code object to top region
    pIIR_DeclarativeRegion root_region = RootDeclarativeRegion(rstack);

    // emit type info
    emit_info_init(type, info_init, rstack, true, 0);
    if (static_declarative_region(decl) == root_region) {
      pIIR_DeclarationList *insert_pos = root_region == ActiveDeclarativeRegion(rstack) ? &dl->rest : NULL;
      insert_internal_code(insert_pos, root_region, decl->declarator->text.to_chars(), 
			   hdr, impl, DECLARE_GLOBALLY);
      // The new type is static. Hence, the type info object can be
      // globally defined.
      string register_str = ".register_type(\"" + get_long_name(tdecl->declarative_region) + "\"," + 
	"\"" + get_long_name(tdecl) + "\",\":" +  decl->declarator->text.to_chars() + "\",NULL)";
      // If the info instance is constant then declare it globally
      insert_internal_object_declaration(insert_pos, root_region, type->pos, qid(type, rstack, INFO) + "_INFO", 
					 qid(type, rstack, INFO), info_init + register_str, 
					 DECLARE_GLOBALLY);      

    } else {
      insert_internal_code(NULL, root_region, decl->declarator->text.to_chars(), 
			   hdr, impl, DECLARE_GLOBALLY);
      // emit code to register type if the type is not strictly bound
      // to a subprogram region. I.e., types which are only static
      // with respect to a subprogram are not registered.
      string register_str;
      if (static_declarative_region(decl) == NULL ||
	  !static_declarative_region(decl)->is(IR_SUBPROGRAM_DECLARATION))
	register_str = ".register_type(\"" + get_long_name(tdecl->declarative_region) + "\"," + 
	  "\"" + get_long_name(tdecl) + "\",\":" +  decl->declarator->text.to_chars() + "\",NULL)";
      // The new type is not static. Hence, the type info instance
      // is created locally. Note that non static type info
      // instances are not registered.
      insert_internal_object_declaration(&dl->rest, ActiveDeclarativeRegion(rstack), type->pos,
					 qid(type, rstack, INFO) + "_INFO", 
					 qid(type, rstack, INFO), info_init + register_str, DECLARE_LOCALLY);
    }
    

  } else if (decl->is(IR_SUBPROGRAM_DECLARATION)) {
    // **************************************************************************
    // Subprogram
    // **************************************************************************
    if (decl->is(IR_PREDEFINED_FUNCTION_DECLARATION)) {
      pIIR_PredefinedFunctionDeclaration pfunc = pIIR_PredefinedFunctionDeclaration(decl);
      if (get_operator_type(pfunc) == STD_OP) 
	// Predefined VHDL operators are implicitly defined. Hence,
	// there is nothing to do here.
	return;
    }
    
    string hdr, impl;
    // plot complete subprogram declaration into string
    emit_impl(decl, impl, rstack, 0);
    // plot subprogram prototype into string
    emit_hdr(decl, hdr, rstack, 0);
    // append internal code object to top region. This code is then
    // emitted globally. I.e., code for subprograms is collected in
    // internal code objects.
    pIIR_DeclarativeRegion root_region = RootDeclarativeRegion(rstack);
    insert_internal_code(NULL, root_region, decl->declarator->text.to_chars(), 
			 hdr, impl, DECLARE_GLOBALLY);
  }
}



// create code to initialize VHDL objects
void
emit_decls_init (pIIR_DeclarationList decl_list, string &str, RegionStack &rstack, int l)
{
  //***********************************************************************
  // Analyze each item on the declaration list
  //***********************************************************************
  for (pIIR_DeclarationList dl = decl_list; dl; dl = dl->rest) {
    emit_decls_init_item (dl, str, rstack, l);
  }
}


/*
 * Simulation Object Implementation
 */

void
m_emit_impl (pIIR_ArrayType at, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}

IR_StaticLevel
m_emit_info_init (pIIR_ArrayType at, string &str, RegionStack &rstack, bool static_info, int l)
{
  // Count number of dimensions
  int counter = 0;
  for (pIIR_TypeList tl = at->index_types; tl; tl = tl->rest)
    counter++;
  
  // If the array has more than a single dimension then first declare
  // a separate internal array type for each dimension. Note that
  // e.g. a two-dimensional array "type mytype array(integer range <>,
  // positive range <>) of bit" is transformed into two one
  // dimentional arrays similar to: "type internal_array is
  // array(positive range <>) of bit" and "type mytype is
  // array(integer range <>) of internal_array".
  string array_info_str = get_type_info_obj(at->element_type, rstack, static_info);
  for (int i = counter; i >= 1; i--) {
    pIIR_TypeList tl = at->index_types;
    for (int j = 1; j < i; j++)
      tl = tl->rest;
    
    if (i == 1)
      array_info_str = ".set(" + array_info_str + "," + 
	get_type_info_obj(get_basic_type(tl->first), rstack, static_info) + "," + (static_info?"-1":"0") + ")";
    else
      array_info_str = "(new array_info(" + array_info_str + "," + 
	get_type_info_obj(get_basic_type(tl->first), rstack, static_info) + "," + (static_info?"-1":"0") + "))";
  }

  str += array_info_str;

  return IR_LOCALLY_STATIC;
}


void
m_emit_impl (pIIR_ArraySubtype ast, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}


IR_StaticLevel
m_emit_info_init (pIIR_ArraySubtype ast, string &str, RegionStack &rstack, bool static_info, int l)
{
  pIIR_TypeDeclaration decl = ast->declaration;
  IR_StaticLevel slevel = IR_LOCALLY_STATIC;
  string array_info_str;

  // Check whether the array subtype introduces some new constraints
  if (ast->constraint == NULL) {
    // No, no new constraints! Hence, get array info from immediate
    // base type
    array_info_str = get_type_info_obj(ast->immediate_base, rstack, static_info);
    // Determine static level of type by analyzing static level of
    // ranges and element type.
    slevel = get_static_level(ast, rstack);

  } else {
    // Ok, this there are some new constraints. Get base type of array
    // subtype.
    assert(ast->base->is(IR_ARRAY_TYPE));
    pIIR_ArrayType base_type = pIIR_ArrayType(ast->base);
    pIIR_Type basic_type = pIIR_ArrayType(get_basic_type(ast->immediate_base));

    // Count number of dimensions
    int counter = 0;
    for (pIIR_TypeList tl = ast->constraint; tl; tl = tl->rest)
      counter++;
    
    // Determine whether the base type of the array is named (i.e.,
    // whether there is an explicit type declaration for the base
    // type)
    bool named_basic_type = (decl == NULL) && (basic_type->declaration != NULL);

    // If the array hase more than a single dimension then first
    // declare a separate internal array type for each dimension. Note
    // that e.g. a two-dimensional array "type mytype array(integer
    // range <>, positive range <>) of bit" is transformed into two
    // one dimentional arrays similar to: "type internal_array is
    // array(positive range <>) of bit" and "type mytype is
    // array(integer range <>) of internal_array".  Get element type
    if (named_basic_type) {
      // If the base type is named then the element type is derived
      // from the base array type
      array_info_str = get_type_info_obj(basic_type, rstack, static_info) + "->element_type";
      for (int i = counter; i > 1; i--)
	array_info_str = "parray_info(" + array_info_str + ")->element_type";

    } else
      // Otherwise, the element type is determined directly from the
      // corresponding element subtype 
      array_info_str = get_type_info_obj(base_type->element_type, rstack, static_info);

    // Step through each dimension of the array starting with the last
    // dimension.
    for (int i = counter; i >= 1; i--) {
      string base_info_str;
      pIIR_TypeList tl = ast->constraint;
      for (int j = 1; j < i; j++) tl = tl->rest;
      // Get index range
      vector<RangeDescriptor> range_desc = get_discrete_range(tl->first, rstack, IR_NOT_STATIC);
      slevel = merge_level(range_desc[0].static_level, slevel);
      // Bail out if more than a single range descriptor is returned
      assert(range_desc.size() <= 1);
      // Next convert range descriptor to int strings
      StaticRangeDescriptor<string, string> range = 
	range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));
      // Get index info instance for the corresponding array index
      string index_info_str;
      if (named_basic_type) {
	// If the base type of the current array subtype is named then
	// the corresponding index subtype is derived from this type
	index_info_str = get_type_info_obj(basic_type, rstack, static_info);
	for (int k = i; k > 1; k--) 
	  index_info_str = "parray_info(" + index_info_str + ")->element_type";
	index_info_str = "parray_info(" + index_info_str + ")->index_type";

      } else
	// Otherwise, the index info is directly derived from the
	// corresponding index subtype
	index_info_str = get_type_info_obj(get_base_type(tl->first), rstack, static_info);

      string left_checked_str = range.left, right_checked_str = range.right;
      // Shall we perform runtime range checks?
      if ((do_runtime_checks & CG_CHECK_COMPOSITE_TYPE_RANGE)) {
	// Could the left bound be checked at compile time or do we
	// have to do this at runtime?
	if (runtime_checks(ast) & RT_CHECK_LEFT_ARRAY_BOUND)
	  left_checked_str = index_info_str + "->check(" + range.left + ")";
	// Could the right bound be checked at compile time or do we
	// have to do this at runtime?
	if (runtime_checks(ast) & RT_CHECK_RIGHT_ARRAY_BOUND)
	  right_checked_str = index_info_str + "->check(" + range.right + ")";
      }
      // setup init value for array info instance
      if (i == 1)
	array_info_str = ".set(" + array_info_str + "," + index_info_str + "," +
	  left_checked_str + "," + range.dir + "," + right_checked_str + "," +  
	  (static_info?"-1":"0") + ")";
      else
	array_info_str = "(new array_info(" + array_info_str + "," + index_info_str + "," +
	  left_checked_str + "," + range.dir + "," + right_checked_str + "," +  
	  (static_info?"-1":"0") + "))";
    }
  }

  str += array_info_str;

  return slevel; // return compound static level of ranges
}


void
m_emit_impl (pIIR_ScalarSubtype sst, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = sst->declaration;

  // Is the subtype constrained or at least a resolution function hase
  // been added?
  if (sst->range == NULL && sst->resolution_function == NULL) {
    // No, the subtype is not constrained (e.g., "subtype color2 is
    // color;"). Hence, do nothing.
    
  } else if (sst->base->is(IR_ENUMERATION_TYPE)) {
    // ****************************************************************************
    // Enumeration subtype
    // ****************************************************************************
    // The subtype is constrained. Hence, left pos of new
    // enumeration subtype.
    vector<RangeDescriptor> range_desc = get_discrete_range(sst, rstack, IR_NOT_STATIC);
    // Check whether bounds and range direction are static
    StaticRangeDescriptor<string, string> range = 
      range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));
    if (and_reduce(range.valid)) {
      // The current C++ source code is not associated with any real
      // VHDL source line
      last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);
      
      str += "/* Implementation of enumeration type " + get_long_name(decl) + " */\n";
      str += "const char **" + qid(decl, rstack, INFO) + "::values=" + 
	"((enum_info_base&)" + qid(decl, rstack, INFO) + "_INFO).values=" +
	"&" + qid(sst->base->declaration, rstack, INFO) + "_INFO.get_values()[" + range.left + "];\n";
    }

  } else if (sst->base->is(IR_PHYSICAL_TYPE)) {
    pIIR_PhysicalType pt = pIIR_PhysicalType (sst->base);

    // The current C++ source code is not associated with any real
    // VHDL source line
    last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);
    
    str += ("/* Implementation of physical base type " +
	    get_long_name(decl) + " */\n");
    
    string pt_qid = qid (pt, rstack, INFO);

    str += "const char *" + pt_qid + "::units[] = {\n";
    int unit_count = 0;
    for (pIIR_UnitList ul = pt->units; ul; ul = ul->rest)
      {
	str += "  \"" + nid (ul->first, BARE) + "\"";
	if (ul->rest)
	  str += ",\n";
	unit_count++;
      }
    str += "\n};\n";
    
    str += "const lint " + pt_qid + "::scale[] = {\n";
    string scale_string = "1LL";
    str += "  " + scale_string;
    for (pIIR_UnitList ul = pt->units->rest; ul; ul = ul->rest)
      {
	pIIR_PhysicalUnit u = ul->first;
	string this_scale = "";
	emit_expr (u->multiplier, this_scale, rstack, DEFAULT);
	scale_string = this_scale + "*(" + scale_string + ")";
	str += ",\n  " + scale_string;
      }
    str += "\n};\n";
    
    str += ("const int " + pt_qid + "::unit_count = " + to_string (unit_count)
	    + ";\n");

  } else if (sst->base->is(IR_INTEGER_TYPE) ||
	     sst->base->is(IR_FLOATING_TYPE)) {

    // ****************************************************************************
    // Integer, physical or floating point subtype
    // ****************************************************************************

    
  } else
    codegen_error.error("%:error: sorry, this subtype declaration is currently not supported", sst);
}
  

IR_StaticLevel
m_emit_info_init(pIIR_ScalarSubtype sst, string &str, RegionStack &rstack, bool static_info, int l)
{
  // First, check out whether an resolution function is associated
  // with this type
  string add_resolver;
  if (sst->resolution_function != NULL) {
    vector<string> libunit = get_library_and_unit_name(sst->resolution_function);
    // Continue if the current declaration is predefined in
    // library std but not std.textio.
    string ideal_str = "false";
    if (libunit[0] == "ieee" && libunit[1] == "std_logic_1164") ideal_str = "true";
    // If a resolution function has been added then add code to
    // register the reolver handle
    add_resolver += ".add_resolver(resolver_handler<" + qid(sst, rstack, TYPE) + "," +
      qid(sst->resolution_function, rstack, DEFAULT) + ">," + 
      get_type_info_obj(sst->resolution_function->interface_declarations->first->subtype, rstack, INFO) + "," + 
      ideal_str + ")";
  }

  // Is the subtype constrained?
  if (sst->range == NULL) {
    // If not then the info instance is equal to the info instance of
    // the immedate base type
    str += ".set(" + get_type_info_obj(sst->immediate_base, rstack, false) + ")" + add_resolver;
    return get_static_level(sst, rstack);

  } else if (sst->base->is(IR_INTEGER_TYPE) ||
	     sst->base->is(IR_PHYSICAL_TYPE) ||
	     sst->base->is(IR_FLOATING_TYPE) ||
	     sst->base->is(IR_ENUMERATION_TYPE)) {
    // ****************************************************************************
    // Integer, enumeration, physical or floating point subtype
    // ****************************************************************************
    vector<RangeDescriptor> range_desc = get_discrete_range(sst, rstack, IR_NOT_STATIC);
    // Check whether bounds and range direction must be determined at
    // runtime
    StaticRangeDescriptor<string, string> range = 
      range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));
    if (!and_reduce(range.valid)) {
      // Ok, bounds are not static. Hence, they must be set at runtime
      // via the "set" method of integer_info_base.
      string left_checked_str = range.left, right_checked_str = range.right;
      // Shall we perform runtime range checks?
      if ((do_runtime_checks & CG_CHECK_SCALAR_TYPE_RANGE)) {
	string base_info_str = get_type_info_obj(get_basic_type(sst->immediate_base), rstack, false);
	// Could the left bound be checked at compile time or do we
	// have to do this at runtime?
	if (runtime_checks(sst) & RT_CHECK_LEFT_BOUND)
	  left_checked_str = base_info_str + "->check(" + range.left + ")";
	// Could the right bound be checked at compile time or do we
	// have to do this at runtime?
	if (runtime_checks(sst) & RT_CHECK_RIGHT_BOUND)
	  right_checked_str = base_info_str + "->check(" + range.right + ")";
      }
      if (sst->base->is(IR_PHYSICAL_TYPE)) {
	string info_base_str = get_type_info_obj(sst->base, rstack, false);
	str += ".set(" + left_checked_str + "," + right_checked_str + "," + 
	  "min(" + range.left + "," + range.right + ")," +
	  "max(" + range.left + "," + range.right + ")," + 
	  info_base_str + "->units," + info_base_str + "->scale," + info_base_str + "->unit_count)" + 
	  add_resolver;

      } else if (sst->base->is(IR_ENUMERATION_TYPE)) {
	string info_base_str = get_type_info_obj(sst->base, rstack, false);
	str += ".set(" + left_checked_str + "," + right_checked_str + "," + 
	  info_base_str + "->get_values()[" + range.left + "])" + add_resolver;
	

      } else 
	str += ".set(" + left_checked_str + "," + right_checked_str + "," + 
	  "min(" + range.left + "," + range.right + ")," +
	  "max(" + range.left + "," + range.right + "))" + add_resolver;
    }

    return range_desc[0].static_level;

  } else
    codegen_error.error("%:error: sorry, this subtype declaration is currently not supported", sst);

  return IR_LOCALLY_STATIC;
}



void
m_emit_impl (pIIR_EnumerationType et, string &str, RegionStack &rstack, int l)
{
  pIIR_TypeDeclaration decl = et->declaration;

  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  str += "/* Implementation of enumeration type " + get_long_name(decl) + " */\n";
  str += "const char *" + qid(decl, rstack, INFO) + "::values[" +/* + to_string(enum_item_number(et))+*/ "]={";
  const char *separator = "";
  for (pIIR_EnumerationLiteralList ell = et->enumeration_literals; ell; ell = ell->rest) {
    str += string(separator) + "\"" + string(ell->first->declarator->text.to_chars()) + "\"";
    separator = ",";
  }
  str += "};\n";
}


IR_StaticLevel
m_emit_info_init (pIIR_EnumerationType et, string &str, RegionStack &rstack, bool static_info, int l)
{
  pIIR_TypeDeclaration decl = et->declaration;
  //str += "new " + qid(decl, rstack, INFO);

  return get_static_level(et, rstack);
}

void
m_emit_impl (pIIR_AccessType at, string &str, RegionStack &rstack, int l)
{
}


IR_StaticLevel
m_emit_info_init (pIIR_FileType ft, string &str, RegionStack &rstack, bool static_info, int l)
{
  str += ".set(" + get_type_info_obj(ft->type_mark, rstack, false) + ")";
  
  return get_static_level(ft, rstack);
}


void
m_emit_impl (pIIR_FileType ft, string &str, RegionStack &rstack, int l)
{
}

void
m_emit_impl (pIIR_RecordType rt, string &str, RegionStack &rstack, int l)
{
  int ec = 0;
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest)
    ec += 1;

  string qid_t = qid(rt, rstack, TYPE);

  str += "const char *" + qid(rt, rstack, TYPE) + "_NAMES[] = {\n";
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest)
    {
      str += "  \"" + nid (edl->first, BARE) + "\"";
      if (edl->rest)
	str += ",";
      str += "\n";
    }
  str += "};\n";

  str += "void *" + qid(rt, rstack, TYPE) + "_ELEM_ADDR(void *p, int i)\n";
  str += "{\n";
  str += "  " + qid(rt, rstack, TYPE) + "_DATA &obj=*(" + qid(rt, rstack, TYPE) + "_DATA*)p;\n";
  str += "  switch (i) {\n";
  int i = 0;
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest, i++)
    {
      str += "  case " + to_string (i) + ": return (void*)&obj." + nid (edl->first, DEFAULT) + ";\n";
    }
  str += "  };\n";
  str += "};\n";
}

void
m_emit_impl (pIIR_RecordSubtype ast, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}



IR_StaticLevel
m_emit_info_init (pIIR_RecordType rt, string &str, RegionStack &rstack, bool static_info, int l)
{
  int ec = 0;
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest)
    ec += 1;
  
  // First, initialize record info instance with basic information
  string tqid = qid(rt, rstack, TYPE);
  str +=
    ".set(" + to_string(ec)
    + ",sizeof(" + tqid + "_DATA),"
    + tqid + "_NAMES,"
    + tqid + "_ELEM_ADDR," + (static_info? "-1" : "0") + ")";

  // Finally, set info pointer of the various record elements. For
  // each record element method "set(int,type_info_interface*)" is
  // called.
  int i = 0;
  for (pIIR_ElementDeclarationList edl = rt->element_declarations;
       edl; edl = edl->rest)
    str += ".set(" + to_string(i++) + "," + get_type_info_obj(edl->first->subtype, rstack, static_info) + ")";
}


IR_StaticLevel
m_emit_info_init (pIIR_RecordSubtype rst, string &str, RegionStack &rstack, bool static_info, int l)
{
  pIIR_TypeDeclaration decl = rst->declaration;
  IR_StaticLevel slevel = IR_LOCALLY_STATIC;

  // base type
  string record_info_str = get_type_info_obj(rst->immediate_base, rstack, static_info);
  // Determine static level of type by analyzing static level of
  // record elements
  slevel = get_static_level(rst, rstack);

  str += ".set(" + record_info_str + "," + (static_info? "-1" : "0") + ")";

  return slevel; // return compound static level of ranges
}



IR_StaticLevel
m_emit_info_init (pIIR_AccessType at, string &str, RegionStack &rstack, bool static_info, int l)
{
  str += ".set(" + get_type_info_obj(at->designated_type, rstack, false) + ")";
  
  return get_static_level(at, rstack);
}


void
m_emit_impl (pIIR_EntityDeclaration e, string &str, RegionStack &rstack, int l)
{
  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  str += "/* Implementation of entity methods */\n";
  str += qid(e, rstack, id_type());
  str += "::\n";
  str += qid(e, rstack, id_type());
  str += "(name_stack &iname, map_list *mlist, void *father) {\n";
  str += "    father_component = father;\n";
  str += "    iname.push(\"\");\n";

  // Generics
  if (extended_generic_clause(e) != NULL)
    emit_decls_init(extended_generic_clause(e), str, rstack, 4);
  for (pIIR_DeclarationList dl = extended_generic_clause(e); dl; dl = dl->rest)
    if (dl->first->is(IR_CONSTANT_INTERFACE_DECLARATION))
      emit_generic_interfacecon(pIIR_ConstantInterfaceDeclaration(dl->first), str, rstack, 4);

  // Ports
  if (extended_port_clause(e) != NULL)
    emit_decls_init(extended_port_clause(e), str, rstack, 4);
  for (pIIR_DeclarationList dl = extended_port_clause(e); dl; dl = dl->rest)
    if (dl->first->is(IR_SIGNAL_INTERFACE_DECLARATION))
      emit_sig_interfacecon(pIIR_SignalInterfaceDeclaration(dl->first), str, rstack, 4);

  str += "    iname.pop();\n";
  str += "};\n";

  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  str += "\n";
}


void
emit_handle (pIIR_ArchitectureDeclaration a ,string &str, RegionStack &rstack)
{
  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, 0);

  str += "/* handle for simulator to find architecture */\n";	// handle func
  str += "void*\n";
  str += qid (a, rstack, id_type());
  str += "_handle(name_stack &iname, map_list *mlist, void *father, int level) {\n";
  str += " REPORT(cout << \"Starting constructor ";
  str += qid (a, rstack, id_type());
  str += " ...\" << endl);\n";
  str += " return new " + qid (a, rstack, id_type());
  str += "(iname, mlist, father, level);\n";
  str += "};\n";
  str += "extern int " + qid (a, rstack, id_type()) + "_init ();\n";
  str += "handle_info *";					// dummy var
  str += qid (a, rstack, id_type());
  str += "_hinfo =\n";
  str += "  add_handle(\"";
  str += string(a->entity->library_name->text.to_chars()) + "\",\"" +  nid(a->entity, BARE) + "\",\"" + nid(a, BARE);
  str += "\",&";
  str += qid (a, rstack, id_type());
  str += "_handle,&";
  str +=  qid (a, rstack, id_type()) + "_init);\n";
}

void
m_emit_impl (pIIR_ArchitectureDeclaration a, string &str, RegionStack &rstack, int l)
{
  emit_impl (a->architecture_statement_part, str, rstack, 2);		// process impls
  emit_handle (a, str, rstack);					// handle for sim
  emit_constructor(a, str, rstack);					// arch constructor
}


void
m_emit_impl (pIIR_PackageBodyDeclaration pb, string &str, RegionStack &rstack, int l)
{
  if (extended_declarations(pb))
    emit_decls_init (extended_declarations(pb), str, rstack, l);
}


void
m_emit_impl (pIIR_PackageDeclaration p, string &str, RegionStack &rstack, int l)
{
  if (extended_declarations(p))
    emit_decls_init(extended_declarations(p), str, rstack, l);
}


void
emit_generic_map (pIIR_AssociationElement ae, string &str, RegionStack &rstack)
{
  list<pair<pIIR_Expression, pIIR_Root> > formal_acl_list;
  get_acl(ae->formal, formal_acl_list, rstack, IR_NOT_STATIC, true);
  
  string formal_acl_str = formal_acl_list.size() == 0? "NULL" : 
    (sprint_acl(formal_acl_list, "&(tmpacl1->clear()", rstack, id_type(SIGNAL, ARCHREF)) + ")");
  str += "tmpml.generic_map(\":" + 
    convert_string(string(ae->formal_declaration->declarator->text.to_chars()), tolower) + "\"," +
    formal_acl_str + ",";
  str += "const_pointer(";
  if (ae->actual != NULL)
    emit_expr(ae->actual, str, rstack, id_type(READER, DEREF));
  else
    emit_expr(ae->formal_declaration->initial_value, str, rstack, id_type(READER, DEREF));
  str += "),&" + qid(get_base_type(ae->formal->subtype), rstack, INFO) + "_INFO";
  str += "); ";
}


void
emit_signal_map (pIIR_AssociationElement ae, string &str, RegionStack &rstack)
{
  // Determine mode of formal signal
  string formal_mode;
  switch (ae->formal_declaration->mode) {
  case IR_IN_MODE: formal_mode = "vIN"; break;
  case IR_OUT_MODE: formal_mode = "vOUT"; break;
  case IR_INOUT_MODE: formal_mode = "vINOUT"; break;
  case IR_BUFFER_MODE: formal_mode = "vBUFFER"; break;
  case IR_LINKAGE_MODE: formal_mode = "vLINKAGE"; break;
  default: assert(false);
  };

  list<pair<pIIR_Expression, pIIR_Root> > formal_acl_list;
  get_acl(ae->formal, formal_acl_list, rstack, IR_NOT_STATIC, true);
  
  string formal_acl_str = formal_acl_list.size() == 0? "NULL" : 
    (sprint_acl(formal_acl_list, "&(tmpacl1->clear()", rstack, id_type(SIGNAL, ARCHREF)) + ")");

  // Store pointer to signal decalration if actual references a
  // signal. Otherwise set pointer to NULL.
  pIIR_ObjectDeclaration actual_sig = NULL;
  if (ae->actual->is(IR_OBJECT_REFERENCE))
    {
      ContextInfo tmp_ctxt;
      actual_sig = pIIR_ObjectDeclaration(get_context(ae->actual, tmp_ctxt, rstack, false, 0)->declaration);
      if (!(actual_sig->is(IR_SIGNAL_DECLARATION) || 
	    actual_sig->is(IR_SIGNAL_INTERFACE_DECLARATION)))
	actual_sig = NULL;
    }
  
  string arg_str;
  if (ae->actual == NULL ||
      ae->actual->is (IR_OPEN_EXPRESSION)) 
    {
      /* Association with `open'. */
      arg_str = formal_acl_str + "," + formal_mode;
    }
  else if (actual_sig != NULL)
    {
      /* Association with a single signal object. */
      arg_str = formal_acl_str + "," + formal_mode + ",";
      arg_str += qid (actual_sig, rstack, id_type(SIGNAL, ARCHREF)) + ",";
      
      // Append acl for actual. If the entire actuak is mapped then
      // only a NULL pointer is passed over to signal_map. Otherwise,
      // a termporary will store the corresponding acl sequence.
      list<pair<pIIR_Expression, pIIR_Root> > actual_acl_list;
      get_acl (ae->actual, actual_acl_list, rstack, IR_GLOBALLY_STATIC, true);
      string actual_acl = actual_acl_list.size() == 0? "NULL" : 
	("&(" + sprint_acl(actual_acl_list, "tmpacl2->clear()", rstack, id_type(SIGNAL, ARCHREF)) + ")");
      arg_str += actual_acl;
    }
  else
    {
      // The formal is associated with an expression
      arg_str = formal_acl_str + "," + formal_mode + ",const_pointer(";
      emit_expr (ae->actual, arg_str, rstack, id_type(READER, DEREF));
      arg_str += ")," + get_type_info_obj(ae->actual->subtype, rstack, false);
    }

  const string formal_name = convert_string(string(ae->formal_declaration->declarator->text.to_chars()), tolower);
  str += "tmpml.signal_map(\":" + formal_name + "\"," + arg_str + "); ";
}


// emit component instantiation code
void 
emit_component_instantiation(pIIR_ComponentInstantiationStatement cs, string &str, 
			     RegionStack &rstack, int l)
{
  // First, get generic and port clause which is used as interface
  // definition of the design to be instantiated
  pIIR_InterfaceList generic_clause, port_clause;
  if (cs->binding->unit->is(IR_ARCHITECTURE_REF)) {
    // An architecture is directly instantiated. Hence, get the port
    // and generic clause of the corresponding entity declaration.
    pIIR_EntityDeclaration entity_decl = pIIR_ArchitectureRef(cs->binding->unit)->entity;
    generic_clause = entity_decl->generic_clause;
    port_clause = entity_decl->port_clause;

  } else if (cs->binding->unit->is(IR_COMPONENT_DECLARATION)) {
    // An *component* is instantiated. Hence, get port and generic
    // clause of the component declaration.
    generic_clause = pIIR_ComponentDeclaration(cs->binding->unit)->local_generic_clause;
    port_clause = pIIR_ComponentDeclaration(cs->binding->unit)->local_port_clause;
  }


  // Print line and file info
  last_pos_info = emit_posinfo(cs->pos, str, last_pos_info, l);

  str += spaces(l) + "tmpml.reset(); ";

  // Process generic map
  for (pIIR_AssociationList al = cs->binding->generic_map_list; al; al = al->rest)
    emit_generic_map (al->first, str, rstack);

  // Process port map
  for (pIIR_AssociationList al = cs->binding->port_map_list; al; al = al->rest)
    emit_signal_map (al->first, str, rstack);

  string comp_label =
    "\":" + convert_string(cs->declarator->text.to_chars(), tolower) + "\"";

  if (cs->binding->unit->is(IR_ARCHITECTURE_REF)) {
    //****************************************************************************
    // Entity/architecture pair shall be instantiated
    //****************************************************************************
    pIIR_ArchitectureRef aref = (pIIR_ArchitectureRef)cs->binding->unit;
    string library_name = convert_string(aref->entity->library_name->text.to_chars(), tolower);
    string entity_name = convert_string(aref->entity->declarator->text.to_chars(), tolower);
    string architecture_name = 
      aref->architecture_name != NULL? convert_string(aref->architecture_name->text.to_chars(), tolower) : "";
    str += "kernel.elaborate_architecture(\"" + library_name + "\",";
    str += "\"" + entity_name + "\",\"" + architecture_name + "\",iname,";
    str += comp_label + ",&tmpml,this,level);\n";

  } else if (cs->binding->unit->is(IR_CONFIGURATION_DECLARATION)) {
    //******************************************************************
    // Configuration shall be instantiated
    //******************************************************************

    pIIR_ConfigurationDeclaration conf =
      pIIR_ConfigurationDeclaration (cs->binding->unit);
    
    string library_name =
      "\"" + convert_string (conf->library_name->text.to_chars (),
			     tolower) +
      "\"";
    string conf_name =
      "\"" + convert_string (conf->declarator->text.to_chars (),
			     tolower) +
      "\"";

    str += 
      "kernel.elaborate_configuration (" +
      library_name + ", " + conf_name + ", iname, " + comp_label + ", " + 
      ", &tmpml, this, level);\n";
    
  } else if (cs->binding->unit->is(IR_COMPONENT_DECLARATION)) {
    //*****************************************************************
    // Component shall be instantiated
    //*****************************************************************

    pIIR_ComponentDeclaration comp_decl =
      pIIR_ComponentDeclaration(cs->binding->unit);

    // Currently, only default binding to an entity is supported.
    // Anything else will be emited anyway, and will fail at compile
    // or run-time.

    string default_library;
    string default_unit;
    string unit;
    
    unit = "\"" + convert_string(comp_decl->declarator->text.to_chars(), 
				 tolower) +
      "\"";

    if (cs->configuration)
      {
	codegen_error.info("%:unit %n (%s)",
			   cs, cs->configuration->unit,
			   cs->configuration->unit->kind_name ());
	assert (cs->configuration->unit->is (IR_LIBRARY_UNIT));
	pIIR_LibraryUnit unit = pIIR_LibraryUnit (cs->configuration->unit);

	default_library = 
	  "\"" + convert_string (unit->library_name->text.to_chars (),
				 tolower) +
	  "\"";
	default_unit = 
	  "\"" + convert_string (unit->declarator->text.to_chars (),
				 tolower) +
	  "\"";
      }
    else
      default_library = default_unit = "NULL";
    
    str +=
      "kernel.elaborate_component (" + unit + "," + 
      default_library + ", " + default_unit + ", iname, " +
      comp_label + ", &tmpml, this, level);\n";
    
  } else
    assert(false);

}


// Emit code to instantiate concurrent statements (processes,
// component instantiations, generate statements, block statements)
void
emit_concurrent_statement_constructors(pIIR_ConcurrentStatementList cl, string &str, RegionStack &rstack, 
				       pIIR_DeclarativeRegion region, int l)
{
  for (pIIR_ConcurrentStatementList s = cl; s != NULL; s = s->rest) {
    if (s->first->is(IR_PROCESS_STATEMENT)) {
      // ***************************************************************
      // Add process 
      // ***************************************************************
      pIIR_ProcessStatement p = pIIR_ProcessStatement(s->first); // !!!
      // Print line and file info
      last_pos_info = emit_posinfo(last_pos_info, str, last_pos_info, 0);

      string constructor_pars = "this";
      for (pIIR_DeclarationList dl = extended_interface_declarations(p)->rest; dl; dl = dl->rest) {
	if (!dl->first->is(V2CC_INTERNAL_OBJECT_DECLARATION)) continue;
	pV2CC_InternalObjectDeclaration iobj = pV2CC_InternalObjectDeclaration(dl->first);
	constructor_pars += "," + string(iobj->declarator->text.to_chars());
      }
      constructor_pars += ",iname.set(\":" + nid(p,BARE) + "\")";

      // Add process constructor call
      str += "    kernel.add_process(new " + qid(p, rstack, id_type()) + "(" + constructor_pars + "),\"" + 
	get_long_name(p->declarative_region) + "\",\":" + nid(p,BARE) + "\",this);\n";

    } else if (s->first->is(IR_COMPONENT_INSTANTIATION_STATEMENT)) {
      // ***************************************************************
      // Add component 
      // ***************************************************************
      emit_component_instantiation((pIIR_ComponentInstantiationStatement)s->first, str, rstack, 4);

    } else if (s->first->is(IR_CONCURRENT_GENERATE_FOR_STATEMENT)) {
      // ***************************************************************
      // Add for generate statement
      // ***************************************************************
      pIIR_ConcurrentGenerateForStatement for_gen = pIIR_ConcurrentGenerateForStatement(s->first);

      // generate a internal variable for the loop variable, the
      // start value and the end value
      string loop_var_name = qid(for_gen->generate_parameter_specification, rstack, id_type (DEFAULT, NO_PREFIX));
      string loop_counter_name = loop_var_name + "_lc";
      string loop_step_name = loop_var_name + "_st";
      string loop_var_type = qid(get_declaration(for_gen->generate_parameter_specification->subtype), rstack, TYPE);

      // Print line and file info
      last_pos_info = emit_posinfo(for_gen->pos, str, last_pos_info, 0);

      // Get iteration range
      vector<RangeDescriptor> range_desc = 
	get_discrete_range (pIIR_ScalarSubtype(for_gen->generate_parameter_specification->subtype)->range, 
			    rstack, IR_NOT_STATIC);
      StaticRangeDescriptor<string, string> range = 
	range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));

      str += spaces(l) + "iname.set(\":" + convert_string(for_gen->declarator->text.to_chars(), tolower) + "\");\n";
      str += spaces(l) + "iname.push(\"\");\n";

      if (range_desc[0].is_explicit_range()) 
	{
	  str += spaces (l) + "for (" + loop_var_type + " " + loop_var_name + "=" + range.left + "," + loop_counter_name + "=" + 
	    string (range.dir == "to"? "up_range_to_length" : "down_range_to_length") + "<" + loop_var_type + ">(" +
	    range.left + "," + range.right + "); ";
	  str += loop_counter_name + "!=0; ";
	  str += loop_var_name + string (range.dir=="to"? "++" : "--") + "," + loop_counter_name + "--)";
	} 
      else 
	{
	  str += "for (" + loop_var_type + " " + loop_var_name + "=" + range.left + "," + loop_step_name + "=" + range.dir + "==to?+1:-1," + 
	    loop_counter_name + "=range_to_length<" + loop_var_type + ">(" + range.left + "," + range.dir + "," + range.right + ");";
	  str += loop_counter_name + "!=0" + "; ";
	  str += loop_var_name + "+=" + loop_step_name + "," + loop_counter_name + "--)";
	}
      str += "{\n";

      // Build parameter for constructor call
      string constructor_pars = "this";
      for (pIIR_DeclarationList dl = extended_interface_declarations(for_gen)->rest; dl; dl = dl->rest) {
	if (!dl->first->is(V2CC_INTERNAL_OBJECT_DECLARATION)) continue;
	pV2CC_InternalObjectDeclaration iobj = pV2CC_InternalObjectDeclaration(dl->first);
	constructor_pars += "," + string(iobj->declarator->text.to_chars());
      }
      constructor_pars += ",iname.set(" + loop_var_name + "),level";
      
      // Print line and file info
      last_pos_info = emit_posinfo(last_pos_info, str, last_pos_info, 0);

      // Emit constructor call
      str += spaces(l + 2) + "new " + qid(for_gen, rstack, id_type()) + "(" + constructor_pars + ");\n"; 

      str += spaces(l) + "}\n";
      str += spaces(l) + "iname.pop();\n";


    } else if (s->first->is(IR_CONCURRENT_GENERATE_IF_STATEMENT)) {
      // ***************************************************************
      // Add if generate statement
      // ***************************************************************
      pIIR_ConcurrentGenerateIfStatement if_gen = pIIR_ConcurrentGenerateIfStatement(s->first);

      // Print line and file info
      last_pos_info = emit_posinfo(last_pos_info, str, last_pos_info, 0);

      string constructor_pars = "this";
      for (pIIR_DeclarationList dl = extended_interface_declarations(if_gen)->rest; dl; dl = dl->rest) {
	if (!dl->first->is(V2CC_INTERNAL_OBJECT_DECLARATION)) continue;
	pV2CC_InternalObjectDeclaration iobj = pV2CC_InternalObjectDeclaration(dl->first);
	constructor_pars += "," + string(iobj->declarator->text.to_chars());
      }
      constructor_pars += ",iname,level";
      
      // Print line and file info
      last_pos_info = emit_posinfo(if_gen->condition->pos, str, last_pos_info, 0);

      str += spaces(l) + "if (";
      emit_expr(if_gen->condition, str, rstack, id_type(READER, DEREF));
      str += ") {\n";
      str += spaces(l + 2) + "iname.set(\":" + convert_string(if_gen->declarator->text.to_chars(), tolower) + "\");\n";

      // Print line and file info
      last_pos_info = emit_posinfo(last_pos_info, str, last_pos_info, 0);

      // Emit constructor call
      str += spaces(l + 2) + "new " + qid(if_gen, rstack, id_type()) + "(" + constructor_pars + ");\n"; 
      str += spaces(l) + "}\n";

    } else
      assert(false);
  }  
}


// emit architecture constructor code
void
emit_constructor(pIIR_ArchitectureDeclaration a, string &str, RegionStack &rstack)
{
  rstack.push(a->entity);
  rstack.push(a);
  pIIR_EntityDeclaration e = a->entity;

  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, 0);

  str += "/* Architecture Constructor */\n";	// handle func

  str += qid (a, rstack, id_type());
  str += "::\n";
  str += qid (a, rstack, id_type());
  str += "(name_stack &iname, map_list *mlist, void *father, int level) :\n  ";
  str += qid (e, rstack, id_type());
  str += "(iname, mlist, father) {\n";
  str += "    iname.push(\":";
  emit_noqual_id(a, str, rstack, BARE);
  str += "\");\n";
  str += "    iname.push(\"\");\n";
  int i=0;

  if (extended_declarations(a))
    // emit code to init object declared within the architecture
    emit_decls_init (extended_declarations(a), str, rstack, 4);

  // emit code to create all processes and components directly
  // instantiated within the architecture body
  if (a->architecture_statement_part != NULL)
    emit_concurrent_statement_constructors(a->architecture_statement_part, str, rstack, a, 4);
    
  // Print line and file info
  last_pos_info = emit_posinfo(last_pos_info, str, last_pos_info, 0);
  str += spaces(4) + string("iname.pop(); /* pop last declaration from name stack */ ") +
    string("iname.pop(); /* pop architecture from name stack */\n");
  // Print line and file info
  last_pos_info = emit_posinfo(last_pos_info, str, last_pos_info, 0);
  str += string("};\n");

  rstack.pop();
  rstack.pop();
}
  

// emit port signal constructor part
void
emit_sig_interfacecon (pIIR_SignalInterfaceDeclaration s, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(s->pos, str, last_pos_info, 5);

  pIIR_TypeDeclaration type_declaration = get_declaration(get_basic_type(s->subtype));

  // determine info instance
  string info_str = get_type_info_obj(s->subtype, rstack, true);

  // determine mode of the port signal
  string mode_str;
  if (s->mode == IR_IN_MODE)
    mode_str = "vIN";
  else if (s->mode == IR_OUT_MODE)
    mode_str = "vOUT";
  else if (s->mode == IR_INOUT_MODE)
    mode_str = "vINOUT";
  else if (s->mode == IR_BUFFER_MODE)
    mode_str = "vBUFFER";
 
  // If the current signal is declared within a package then the scope
  // reference pointer from the package is passed over to the sig_info
  // constructor. Otherwise, the pointer to the current architecture
  // (or other declarative region) is used.
  string sref = is_PackageDeclarativeRegion(s->declarative_region)? "sref" : "this";
  // Create a new sig_info instance
  str += spaces(l) + qid(s, rstack, id_type()) + string("=new sig_info<");
  str += qid(type_declaration, rstack, TYPE);
  str += ">(iname,";
  str += "\":" + nid(s,BARE) + "\",\"" + get_long_name(s->declarative_region) + "\",mlist," + info_str + "," + 
    mode_str + "," + sref + ");\n";

  if (s->initial_value) 
    {
      str += "    " + qid(s, rstack, id_type()) + "->init(" ;
      emit_expr (s->initial_value, str, rstack, DEFAULT);
      str += ");\n";
    }
}


// emit port signal constructor part
void
emit_generic_interfacecon (pIIR_ConstantInterfaceDeclaration g, string &str, RegionStack &rstack, int l)
{
  // determine info instance
  string info_str = get_type_info_obj(get_basic_type(g->subtype), rstack, true);

  // Print line and file info
  last_pos_info = emit_posinfo(g->pos, str, last_pos_info, 5);

  string default_value_p_str = "NULL";
  if (g->initial_value != NULL) {
    default_value_p_str = "const_pointer(";
    emit_expr (g->initial_value, default_value_p_str, rstack, id_type(READER, DEREF));
    default_value_p_str += ")";
  }

  str += spaces(l) + "kernel.init_generic(&" + qid(g, rstack, id_type()) + "," + info_str + ",";
  str += "iname,";
  str += "\":" + nid(g,BARE) + "\",\"" + get_long_name(g->declarative_region) + "\",mlist," + default_value_p_str + ",this);\n";
}


void
m_emit_impl (pIIR_ConcurrentStatementList s, string &str, RegionStack &rstack, int l)
{
  while (s)
    {
      str += spaces(l);
      emit_impl (s->first, str, rstack, l);
      s = s->rest;
    }
}


void
m_emit_impl (pIIR_ProcessStatement p, string &str, RegionStack &rstack, int l)
{
  rstack.push(p);
  ContextInfo &ctxt = *ActiveContext(rstack);

  // Create a list of declarative region pointers beginning from the
  // target region up to the root region
  list<pIIR_DeclarativeRegion> RegionList = create_region_list(p);
  RegionList.pop_front();

  // For each generate region as well as the enclosing architecture
  // region a corresponding pointer is declared and added as a
  // parameter to the constructor.
  string constructor_pars, separator;
  for (list<pIIR_DeclarativeRegion>::iterator iter = RegionList.begin(); 
       iter != RegionList.end(); iter++)
    if ((*iter)->is(IR_ARCHITECTURE_DECLARATION) || 
	(*iter)->is(IR_CONCURRENT_GENERATE_STATEMENT) ||
	(*iter)->is(IR_BLOCK_STATEMENT)) {
      constructor_pars += separator + qid(*iter, rstack, id_type()) + " *" + qid(*iter, rstack, id_type()) + "_AP_PAR";
      insert_internal_object_declaration(get_last_rest_address(&extended_interface_declarations(p)), 
					 p, p->pos, qid(*iter, rstack, id_type()) + "_AP", 
					 qid(*iter, rstack, id_type()) + "*", 
					 "=" + qid(*iter, rstack, id_type()) + "_AP_PAR", 
					 DECLARE_LOCALLY);
      separator = ",";
  }



  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  // ******************************************************************
  // append prolog
  // ******************************************************************
  str += "/* Implementation of process " + get_long_name(p) + " methods */\n" +
    qid(p, rstack, id_type()) + "::\n" + 
    qid(p, rstack, id_type()) + "(" + constructor_pars + ",name_stack &iname) : process_base(iname) {\n";

  // Emit code to initialize some interal process members
  if (extended_interface_declarations(p)!= NULL)
    emit_decls_init(extended_interface_declarations(p), str, rstack, 4);

  // ******************************************************************
  // map signals which are read within the process
  // ******************************************************************
  string reader_code_str, implicit_sig_reader_code_str;
  list<AccessDescriptor> sig_read = 
    filter_unique(ctxt.accessed_objects, READ, 
		  tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));
  for (list<AccessDescriptor>::iterator i = sig_read.begin(); i != sig_read.end(); i++)
    if ((*i).declaration->is(V2CC_IMPLICIT_SIGNAL_DECLARATION))
      implicit_sig_reader_code_str += "    " + qid((*i).declaration, rstack, READER) + "=&" + 
	qid((*i).declaration, rstack, id_type(SIGNAL, ARCHREF)) + "->reader();\n"; 
    else
      reader_code_str += "    " + qid((*i).declaration, rstack, READER) + "=&" + 
	qid((*i).declaration, rstack, id_type(SIGNAL, ARCHREF)) + "->reader();\n"; 

 
  // ******************************************************************
  // map sig_info pointer for signals which are prefix of a signal 
  // function kind attribute.
  // ******************************************************************
  string sig_info_code_str;
  list<AccessDescriptor> sig_attr = 
    filter_unique(ctxt.accessed_objects, SIGNAL_FUNCTION_ATTRIBUTE, 
		  tree_kind_list(IR_SIGNAL_DECLARATION,IR_SIGNAL_INTERFACE_DECLARATION));
  for (list<AccessDescriptor>::iterator i = sig_attr.begin(); i != sig_attr.end(); i++)
      sig_info_code_str += "    " + qid((*i).declaration, rstack, DEFAULT) + "=" + 
	qid((*i).declaration, rstack, id_type(SIGNAL, ARCHREF)) + ";\n"; 


  // ******************************************************************
  // create the driver for the signals that are written by the process.
  // ******************************************************************
  // First extract written signals from ctxt.accessed_objects list.
  list<AccessDescriptor> written_signals = 
    filter(ctxt.accessed_objects, WRITE, 
	   tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));

  string driver_code_str;
  while (written_signals.size()) {
    set<string> acls_for_signal;
    // get first signal in written_signal list and remove it from the
    // list
    AccessDescriptor current_signal = written_signals.front();
    written_signals.erase(written_signals.begin());

    while (true) {
      // get acl for the signal target expression and convert it into a
      // string. Append the string to the other acl strings for that
      // signal.
      list<pair<pIIR_Expression, pIIR_Root> > acl_list;
      if (current_signal.access_expr != NULL) {
	get_acl(current_signal.access_expr, acl_list, rstack, IR_GLOBALLY_STATIC, true);
	acls_for_signal.insert(sprint_acl(acl_list, "tmpacl->clear()", rstack, 
			       id_type(SIGNAL, ARCHREF)));
      } else
	acls_for_signal.insert("");
      // search for the next assignment to the same signal
      list<AccessDescriptor>::iterator iter = written_signals.begin();
      for (; iter != written_signals.end(); iter++)
	if ((*iter).declaration == current_signal.declaration) break;
      // exit loop if no more assignment to the same signal were
      // found. Otherwise, copy found signal to current_sig and remove
      // the corresponding entry from written_signals.
      if (iter == written_signals.end()) break;
      current_signal = (*iter);
      written_signals.erase(iter);
    }
    
    // acls_for_signal contains all different acl values which were
    // created from the signal target expressions (wihtin a process)
    // for a specific signal. Now, build the driver creation code.
    string start_str = "    " + qid(current_signal.declaration, rstack, DRIVER) + 
      string("=kernel.get_driver(this,") + 
      qid(current_signal.declaration, rstack, id_type(SIGNAL, ARCHREF));
    string next_start_str = "    " + string("kernel.get_driver(") + 
	qid(current_signal.declaration, rstack, DRIVER) + ",this";

    for (set<string>::iterator aiter = acls_for_signal.begin();
	 aiter != acls_for_signal.end(); aiter++) {
      driver_code_str += start_str;
      if ((*aiter) != "") // add acl
	driver_code_str += ",&(" + (*aiter) + ")";
      driver_code_str += string(");\n");
      start_str = next_start_str;
    }
  }

  // ******************************************************************
  // create the wait_info objects
  // ******************************************************************

  string wait_info_code_str;
  int windex = 0;

  for (list<pIIR_SequentialStatement>::iterator witer = ctxt.wait_statements.begin(); 
       witer != ctxt.wait_statements.end(); witer++)
    {
      if (! (*witer)->is (IR_WAIT_STATEMENT)) continue;
      pIIR_WaitStatement ws = pIIR_WaitStatement (*witer);
      // collect all signals the wait statement is sensitive on
      ContextInfo wctxt;
      get_context(ws, wctxt, rstack, false, 0);
      
      // Analyze each signal which was referenced in the corresponding
      // wait expression
      list<string> sal_add_arg_list;
      string codestr;
      int length = 0;
      for (access_list::iterator iter = wctxt.accessed_objects.begin(); 
	   iter != wctxt.accessed_objects.end(); iter++) {
	if (!((*iter).access_type & SENSITIVE)) continue;
	list<pair<pIIR_Expression, pIIR_Root> > acl_list;
	// convert each signal expression into an acl list
	get_acl((*iter).access_expr, acl_list, rstack, IR_GLOBALLY_STATIC, true);
	string sal_add_arg = qid((*iter).declaration, rstack, id_type(SIGNAL, ARCHREF));
	if (acl_list.size())
	  sal_add_arg += ",&(" + sprint_acl(acl_list, "tmpacl->clear()", rstack, id_type(SIGNAL, ARCHREF)) + ")";
	// if the current signal (including acl) already has been
	// added to the sal list then do nothing
	if (find(sal_add_arg_list.begin(), sal_add_arg_list.end(), sal_add_arg) != sal_add_arg_list.end())
	  continue;
	// add argument string (sal_add_arg) to list in order to
	// remove dublicate calls
	sal_add_arg_list.push_back(sal_add_arg);
	codestr += string("     sal.add(") + sal_add_arg + ");\n";

	length++;
      }
      
      // If the wait statment has an timeout clause then make it
      // sensitiv to a implicit signal associated with the current
      // process. This implicit signal is used to implement the wait
      // for condition.
      if (ws->timeout_clause != NULL) {
	// Determine declaration of implicit signal. Becuases there is
	// only a signle implicit signal for each process which uses a
	// timeout clause simply access the first element of the list
	// returned from filter_unique.
	pV2CC_ImplicitSignalDeclaration_WaitFor implicit_signal_decl = 
	  pV2CC_ImplicitSignalDeclaration_WaitFor(filter_unique(extended_declarations(p), 
								V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR).front());
	codestr += string("     sal.add(") + qid(implicit_signal_decl, rstack, id_type(SIGNAL, ARCHREF)) + ");\n";
	// Increment length as the implicit wait for signal is also
	// added to the sensitivity list!
	length++; 
      }

      // prolog
      wait_info_code_str += 
	string("    {\n") +
	string("     sigacl_list sal(") + to_string (length) + string(");\n");
      
      // add code 
      wait_info_code_str += codestr;

      // epilog
      wait_info_index(ws) = windex++;
      wait_info_code_str += string("     winfo[") + to_string (wait_info_index (ws)) + 
	string("]=kernel.setup_wait_info(sal,this);\n") + string("    }\n");
    }

  // Next, check out whether the process calls procedures that
  // contain at least one wait statement. First, get get all
  // procedure that are called from this process. For each
  bool calls_delayed_procedures = false;
  for (list<pIIR_SequentialStatement>::iterator witer = ctxt.wait_statements.begin(); 
       witer != ctxt.wait_statements.end(); witer++)
    {
      if (! (*witer)->is (IR_PROCEDURE_CALL_STATEMENT)) continue;
      pIIR_ProcedureCallStatement pc = pIIR_ProcedureCallStatement (*witer);
      wait_info_index(pc) = windex++;
      wait_info_code_str += string("    winfo[") + to_string (wait_info_index (pc)) + 
	string("]=(winfo_item*)NULL;\n");
      calls_delayed_procedures = true;
    }

  // If the procedure calls other procedures that contain wait
  // statements then create an internal pointer variable that will be
  // used to store pointers to the corresponding procedure class
  // instances.
  if (calls_delayed_procedures)
    insert_internal_object_declaration(get_last_rest_address(&extended_declarations(p)), 
				       p, p->pos, "pdelayed_procedure", 
				       "delayed_procedure_base*", "", DECLARE_LOCALLY);

  // ******************************************************************
  // append epilog code
  // ******************************************************************

  string code_str;

  // Print line and file info
  last_pos_info = emit_posinfo(p->pos, code_str, NULL, l);

  code_str += string("bool ") + qid(p, rstack, id_type()) + string("::execute() {\n");

  emit_process_body (p, code_str, rstack, l+2);			// SeqStatList

  // Print line and file info
  last_pos_info = emit_posinfo(p->pos, code_str, last_pos_info, l);

  code_str += "}\n\n";
  
  // Add code to setup singal info pointers and signal readers
  str += sig_info_code_str;
  str += reader_code_str;

  // *****************************************************************************
  // init variables and constants.  Note that the process code is
  // emitted first as due to the operations some internal variables
  // may be generated which must be initialized now!!!!
  // *****************************************************************************

  if (extended_declarations(p))
    // Emit declarations
    emit_decls_init(extended_declarations(p), str, rstack, 4);

  // Add code to setup implicit signal reader, driver and wait info objects.
  str += implicit_sig_reader_code_str;
  str += driver_code_str;
  str += wait_info_code_str;

  str += "}\n";


  // Now, append process code!
  str += code_str;

  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  // Remove context from context stack
  rstack.pop();
}



void
emit_process_body (pIIR_ProcessStatement p, string &str, RegionStack &rstack, int l)
{
  pIIR_SequentialStatementList sl = p->process_statement_part;

  ContextInfo &ctxt = *ActiveContext(rstack);

  if (ctxt.wait_statements.size() &&
      ! p->is(IR_SENSITIZED_PROCESS_STATEMENT) &&
      ! p->is(IR_IMPLICIT_PROCESS_STATEMENT)) {
    str += "  switch (jmp) {\n";					// create jump tbl
    for(unsigned int i=1 ; i <= ctxt.wait_statements.size(); i++)
      str += "      case " + to_string(i) + ": goto lab" + to_string(i) + ";\n";
    str += "  };\n\n  lab0:\n";
  }

  // emit sequential statements
  if (sl != NULL)
    emit_impl(sl, str, rstack, l);

  // the last statement of a process loops back to the beginning
  if (ctxt.wait_statements.size() &&
      ! p->is(IR_SENSITIZED_PROCESS_STATEMENT) &&
      ! p->is(IR_IMPLICIT_PROCESS_STATEMENT)) {
    // Print line and file info
    last_pos_info = emit_posinfo(p->pos, str, last_pos_info, l);
    str += spaces(l) + " goto lab0;\n";
  } else {
    // Else add return value to process code in order to prevent
    // warnings emitted by the c++ compiler.
    str += spaces(l) + "return true;\n";
  }
}


// Print subprogram implementation
void
emit_plain_subprogram_impl (pIIR_SubprogramDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  // emit_subprogram_prototype is defined in v2cc-decl.cc
  extern string emit_subprogram_prototype(pIIR_SubprogramDeclaration, RegionStack &k, bool, int);

  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  str += "/* Implementation of subprogram " + get_long_name(sbp) + " */\n";
  string return_type_str;
  string copy_back_code = spaces(4) + "rlabel:\n", parameter_setup_code;
  string separator = "";

  // Emit subprogram prototype
  str += emit_subprogram_prototype(sbp, rstack, true, 0);

  // Check whether sbp is a function or a procedure
  bool is_function = sbp->is(IR_FUNCTION_DECLARATION); 
  
  // ****************************************************************************
  // Analyze normal subprogram parameter
  // ****************************************************************************
  for (pIIR_DeclarationList il = extended_interface_declarations(sbp); il; il = il->rest) {
    if (!il->first->is(IR_INTERFACE_DECLARATION)) continue;
    pIIR_InterfaceDeclaration par = pIIR_InterfaceDeclaration(il->first);
    // Determine whether the parameter must be copied back
    bool copy_back = (is_scalar_type(par->subtype) ||
		      is_constrained_array_type (get_basic_type (par->subtype))) && 
      (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || 
       par->mode == IR_BUFFER_MODE);
    // Determine whether the parameter must be copied in
    bool copy_in = copy_back && 
      (par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE);
    // Determine whether the parameter can be used directly used or a
    // temporary must be created. It cannot be used directly if the
    // parameter value must be copied back or the parameter type is a
    // constrained array type.
    bool direct_use = il->first->is(IR_SIGNAL_INTERFACE_DECLARATION) 
      || !(copy_back || is_constrained_array_type(par->subtype));

    // If the paramter is not used directly create another variable
    // which is actually used within the subprogram body
    if (!direct_use) {
      // The current C++ source code is not associated with any real
      // VHDL source line
      last_pos_info = emit_posinfo(NO_SOURCE_LINE, parameter_setup_code, last_pos_info, l);

      string par_name = qid(par, rstack, DEFAULT) + "_PAR";
      // If the parameter is passed back by copy then add the
      // corresponding code
      if (copy_back)
	copy_back_code += spaces(4) + par_name + "=" + qid(par, rstack, DEFAULT) + ";\n";
      
      // Check type of parameter. If it is an implicit array subtype
      // then append code to setup the array_info instance of the
      // parameter
      if (is_implicit_array_subtype(par->subtype)) 
	{
	  string info_str = get_type_info_obj(par->subtype, rstack, false);
	  parameter_setup_code += spaces(4) + 
	    qid(get_declaration(par->subtype), rstack, id_type(TYPE | ALIAS, DEFAULT)) + " " + 
	    qid(par, rstack, DEFAULT) + "(" + info_str + "," + par_name + ".data)";
	  parameter_setup_code += ";\n";
	} 
      else if (is_constrained_array_type (par->subtype))
	{
	  string info_str = get_type_info_obj(par->subtype, rstack, false);
	  parameter_setup_code += spaces(4) + 
	    qid(get_declaration(par->subtype), rstack, id_type(TYPE, DEFAULT)) + " " + 
	    qid(par, rstack, DEFAULT) + "(" + info_str + ",(" + 
	    qid(par->subtype, rstack, id_type(TYPE)) + "::E_type*)" + par_name + ".data)";
	  parameter_setup_code += ";\n";
	}
      else
	{
	  parameter_setup_code += spaces(4) + 
	    qid(get_declaration(par->subtype), rstack, TYPE) + " " + qid(par, rstack, DEFAULT);
	  
	  // If the parameter is passed in by copy then add the
	  // corresponding code
	  if (copy_in)
	    parameter_setup_code += "=" + par_name + ";\n";
	  else
	    parameter_setup_code += ";\n";
	}
    }

    // Set separator for next parameter
    separator = ",";
  }

  // ********************************************************
  // The subprogram body starts here!
  // ********************************************************
  str += "\n{\n";

  // Add parameter setup code
  str += parameter_setup_code;

  // Emit any internal declarations required by the subprogram
  // parameters
  if (extended_interface_declarations(sbp) != NULL)
    emit_decls_init(extended_interface_declarations(sbp), str, rstack, 4);

  // emit sequential statements
  string body_code;
  emit_impl(sbp->subprogram_body, body_code, rstack, 4);

  if (extended_declarations(sbp) != NULL) {
    string decl_init_str, decl_str;
    // Emit initialization code of local declarations
    emit_decls_init(extended_declarations(sbp), decl_init_str, rstack, 4);
    // Emit local declarations of the subprogram 
    emit_decls(extended_declarations(sbp), decl_str, rstack, 4);
    str += decl_str + decl_init_str;
  }

  // Now, append subprogram body code. Note that the subprogram body
  // is emitted first before the declarations are printed.
  str += body_code;
  
  // If subprogram is not a function then add copy back code and
  // return subprogram. The copy back code is executed when the
  // subprogram returns.
  if (!is_function)
    str += copy_back_code;

  if (!is_function)
    str += spaces(4) + "return;\n";

  str += "}\n";

  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);
}


// Print subprogram implementation
void
emit_delayed_subprogram_impl (pIIR_ProcedureDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  // emit_subprogram_prototype is defined in v2cc-decl.cc
  string emit_delayed_procedure_constructor (pIIR_ProcedureDeclaration, RegionStack &, bool, int);

  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  const string separator = ",\n" + spaces(l + 2);
  str += "/* Class impl. for subprogram " + get_long_name(sbp) + " (contains waits) */\n";

  // Emit subprogram prototype
  string constructor_str, constructor_init_str, copy_back_code_str;
  constructor_str += "  /* Class constructor for subprogram " + get_long_name(sbp) + " */\n";
  constructor_str += qid(sbp, rstack, DEFAULT) + "::" + emit_delayed_procedure_constructor (sbp, rstack, true, 0)
    + " :\n" 
    + spaces (l + 2) + "delayed_procedure_base (process_PAR)";

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
    bool copy_back = (is_scalar_type(par->subtype) ||
		      is_constrained_array_type (par->subtype)) && 
      (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || 
       par->mode == IR_BUFFER_MODE);
    // Determine whether the parameter must be copied in
    bool copy_in = copy_back && 
      (par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE);
    // Determine whether the parameter can be used directly or an
    // temporary must be created. It cannot be used directly if the
    // parameter value must be copied back or the parameter type is a
    // constrained array type.
    bool direct_use = !(copy_back || is_constrained_array_type (get_basic_type (par->subtype)));

    if (par->is(IR_VARIABLE_INTERFACE_DECLARATION)) {
      constructor_str += separator + qid(par, rstack, DEFAULT)
	+ string (copy_back ? "_REF" : "")
	+ "(" + qid(par, rstack, DEFAULT) + "_PAR)";
      if (copy_back)
	{
	  // If the parameter is passed over via copy back, there are
	  // actually two local variables required. One variable which
	  // is used to store a reference to the original parameter
	  // (ends with _REF; it is used to copy back the value if
	  // the subprogram returns) and another variable which is
	  // used by the procedure body to read/write this parameter.
	  if (is_constrained_array_type (get_basic_type (par->subtype)))
	    {
	      string info_str = get_type_info_obj(par->subtype, rstack, false);
	      constructor_init_str += spaces(l + 2) + 
		qid(par, rstack, DEFAULT) + ".init(" + info_str + ",const_pointer(" + 
		qid(par, rstack, DEFAULT) + "_PAR))";
	      constructor_init_str += ";\n";
	    }
	  else
	    {
	      constructor_init_str += spaces (l + 2) + qid(par, rstack, DEFAULT)
		+ "=" + qid(par, rstack, DEFAULT) + "_PAR;\n";
	    }
	  copy_back_code_str += spaces (l + 2) + qid(par, rstack, DEFAULT) + "_REF"
	    + "=" + qid(par, rstack, DEFAULT) + ";\n";
	}

    } else if (par->is(IR_CONSTANT_INTERFACE_DECLARATION)) {
      constructor_str += separator + qid(par, rstack, DEFAULT) 
	+ "(" + qid(par, rstack, DEFAULT) + "_PAR)";

    } else if (par->is(IR_FILE_INTERFACE_DECLARATION)) {
      constructor_str += separator + qid(par, rstack, DEFAULT) 
	+ "(" + qid(par, rstack, DEFAULT) + "_PAR)";

    } else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION)) {
      // Signal values are NOT copied back! Instead, any operations
      // are directly applied on the corresponding reader/driver...
      copy_back = false;
      direct_use = true;
      // First, append sig_info pointer
      constructor_str += separator + qid(par, rstack, SIGNAL) 
	+ "(" + qid(par, rstack, SIGNAL) + "_PAR)";
      // Next, append reader if signal is of mode in or inout or buffer
      if (par->mode == IR_IN_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	constructor_str += separator + qid(par, rstack, READER) 
	  + "(" + qid(par, rstack, READER) + "_PAR)";
      }
      // Finally, append driver if mode is of out or inout or buffer
      if (par->mode == IR_OUT_MODE || par->mode == IR_INOUT_MODE || par->mode == IR_BUFFER_MODE) {
	constructor_str += separator + qid(par, rstack, DRIVER) 
	  + "(" + qid(par, rstack, DRIVER) + "_PAR)";
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
      constructor_str += separator + qid(par, rstack, DEFAULT)
	+ "(" + qid(par, rstack, DEFAULT) + "_PAR)";
 
    } else if (par->is(IR_SIGNAL_INTERFACE_DECLARATION) ||
	       par->is(IR_SIGNAL_DECLARATION)) {
      pIIR_ObjectDeclaration opar = pIIR_ObjectDeclaration(par);
      AccessFlags &aflags = (*iter).access_type;

      // Add sig_info pointer if a signal function kind attribute has
      // been applied on the parameter

      if ((aflags & SIGNAL_FUNCTION_ATTRIBUTE) ||
	  (aflags & SENSITIVE)) {
	constructor_str += separator + qid(par, rstack, SIGNAL) 
	  + "(" + qid(par, rstack, SIGNAL) + "_PAR)";
      }
      // Next, append reader if signal is read
      if (aflags & READ) {
	constructor_str += separator + qid(par, rstack, READER) 
	  + "(" + qid(par, rstack, READER) + "_PAR)";
      }
      // Finally, append driver if signal is written
      if (aflags & WRITE) {
	constructor_str += separator + qid(par, rstack, DRIVER)
	  + "(" + qid(par, rstack, DRIVER)+ "_PAR)";
      }

    } else if (par->is(IR_TYPE_DECLARATION) ||
	       par->is(IR_SUBTYPE_DECLARATION)) {
      // A type has been used and we need to pass over the type info
      // pointer of that type!
      constructor_str += separator + qid(par, rstack, INFO) 
	+ "_INFO(" + qid(par, rstack, INFO) + "_INFO_PAR)";
    }
  }
  

  // ******************************************************************
  // create the wait_info objects
  // ******************************************************************

  ContextInfo &ctxt = *ActiveContext(rstack);
  string wait_info_code_str;
  int windex = 0;

  for (list<pIIR_SequentialStatement>::iterator witer = ctxt.wait_statements.begin(); 
       witer != ctxt.wait_statements.end(); witer++)
    {
      if (! (*witer)->is (IR_WAIT_STATEMENT)) continue;
      pIIR_WaitStatement ws = pIIR_WaitStatement (*witer);
      // collect all signals the wait statement is sensitive on
      ContextInfo wctxt;
      get_context(ws, wctxt, rstack, false, 0);
      
      // Analyze each signal which was referenced in the corresponding
      // wait expression
      list<string> sal_add_arg_list;
      string codestr;
      int length = 0;
      for (access_list::iterator iter = wctxt.accessed_objects.begin(); 
	   iter != wctxt.accessed_objects.end(); iter++) {
	if (!((*iter).access_type & SENSITIVE)) continue;
	list<pair<pIIR_Expression, pIIR_Root> > acl_list;
	// convert each signal expression into an acl list
	get_acl((*iter).access_expr, acl_list, rstack, IR_GLOBALLY_STATIC, true);
	string sal_add_arg = qid((*iter).declaration, rstack, id_type(SIGNAL, ARCHREF));
	if (acl_list.size())
	  sal_add_arg += ",&(" + sprint_acl(acl_list, "tmpacl->clear()", rstack, id_type(SIGNAL, ARCHREF)) + ")";
	// if the current signal (including acl) already has been
	// added to the sal list then do nothing
	if (find(sal_add_arg_list.begin(), sal_add_arg_list.end(), sal_add_arg) != sal_add_arg_list.end())
	  continue;
	// add argument string (sal_add_arg) to list in order to
	// remove dublicate calls
	sal_add_arg_list.push_back(sal_add_arg);
	codestr += string("     sal.add(") + sal_add_arg + ");\n";

	length++;
      }
      
      // If the wait statment has an timeout clause then make it
      // sensitiv to a implicit signal associated with the current
      // process. This implicit signal is used to implement the wait
      // for condition.
      if (ws->timeout_clause != NULL) {
	// Determine declaration of implicit signal. Because there is
	// only a single implicit signal for each process which uses a
	// timeout clause, simply access the first element of the list
	// returned from filter_unique.
	list <AccessDescriptor> implicit_signal_access_list =
	  filter_unique(ctxt.extra_interface_objects, ACCESS, 
			V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR);
	assert (implicit_signal_access_list.size () >= 1);
	pV2CC_ImplicitSignalDeclaration_WaitFor implicit_signal_decl = 
	  pV2CC_ImplicitSignalDeclaration_WaitFor (implicit_signal_access_list.front ().declaration);
	assert (implicit_signal_decl != NULL);
	codestr += string("     sal.add(") + qid (implicit_signal_decl, rstack, id_type (SIGNAL, ARCHREF)) + ");\n";
	// Increment length as the implicit wait for signal is also
	// added to the sensitivity list!
	length++; 
      }

      // prolog
      wait_info_code_str += 
	string("    {\n") +
	string("     sigacl_list sal(") + to_string (length) + string(");\n");
      
      // add code 
      wait_info_code_str += codestr;

      // epilog
      wait_info_index(ws) = windex++;
      wait_info_code_str += string("     winfo[") + to_string (wait_info_index (ws)) + 
	string("]=kernel.setup_wait_info(sal,process);\n") + string("    }\n");
    }

  // Next, check out whether the process calls procedures that
  // contain at least one wait statement. First, get get all
  // procedure that are called from this process.
  bool calls_delayed_procedures = false;
  for (list<pIIR_SequentialStatement>::iterator witer = ctxt.wait_statements.begin(); 
       witer != ctxt.wait_statements.end(); witer++)
    {
      if (! (*witer)->is (IR_PROCEDURE_CALL_STATEMENT)) continue;
      pIIR_ProcedureCallStatement pc = pIIR_ProcedureCallStatement (*witer);
      wait_info_index(pc) = windex++;
      wait_info_code_str += string("    winfo[") + to_string (wait_info_index (pc)) + 
	string("]=(winfo_item*)NULL;\n");
      calls_delayed_procedures = true;
    }

  // If the procedure calls other procedures that contain wait
  // statements then create an internal pointer variable that will be
  // used to store pointers to the corresponding procedure class
  // instances.
  if (calls_delayed_procedures)
    insert_internal_object_declaration(get_last_rest_address(&extended_declarations(sbp)), 
				       sbp, sbp->pos, "pdelayed_procedure", 
				       "delayed_procedure_base*", "", DECLARE_LOCALLY);

  
  // ******************************************************************
  // Build constructor code
  // ******************************************************************

  constructor_str += 
    spaces (l) + string ("\n{\n")
    + spaces (l + 2) + "winfo=(winfo_item*)winfo_PAR;\n"
    + spaces (l + 2) + "if (winfo == NULL) {\n"
    + spaces (l + 2) + "  winfo=new winfo_item[" + to_string (windex) + "];\n"  
    + wait_info_code_str
    + spaces (l + 2) + "  winfo_PAR=winfo;\n"  
    + spaces (l + 2) + "}\n"
    + constructor_init_str 
    + spaces (l) + "}\n";

  str += constructor_str;
  
  str += "  /* Class destructor for subprogram " + get_long_name(sbp) + " */\n";
  str += spaces(l) + qid(sbp, rstack, DEFAULT) + "::~" + qid(sbp, rstack, DEFAULT) + "()\n"
    + spaces (l) + "{\n"
    + copy_back_code_str 
    + spaces (l) + "}\n";

  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  string code_str;
  code_str += "  /* Execute method for subprogram " + get_long_name(sbp) + " */\n";
  code_str += spaces(l) + "bool " + qid(sbp, rstack, DEFAULT) + "::execute()\n";
  code_str += spaces(l) + "{\n";
  code_str += spaces(l) + "  switch (jmp) {\n";
  for(unsigned int i = 1; i <= ctxt.wait_statements.size(); i++)
    code_str += "      case " + to_string(i) + ": goto lab" + to_string(i) + ";\n";
  code_str += spaces(l) + "  };\n\n  lab0:\n";
  
  // emit sequential statements
  pIIR_SequentialStatementList sl = sbp->subprogram_body;
  if (sl != NULL)
    emit_impl(sl, code_str, rstack, l + 2);

  // Print line and file info
  last_pos_info = emit_posinfo(sbp->pos, code_str, last_pos_info, l);
  code_str += spaces(l) + "  rlabel: return false;\n";

  code_str += spaces(l) + "}\n";

  str += code_str;
}


// Print subprogram implementation
void
m_emit_impl (pIIR_SubprogramDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  // If no subprogram body is defined then do nothing!
  if (sbp->subprogram_body == NULL)
    return;

  rstack.push(sbp);
  
  // Procedures that includes wait statements (or call procedure that
  // contain waits) must be handled different from plain subprograms.
  if (sbp->is (IR_PROCEDURE_DECLARATION) &&
      (has_wait (pIIR_ProcedureDeclaration (sbp)) ||
       has_wait_for (pIIR_ProcedureDeclaration (sbp))))
    {
      emit_delayed_subprogram_impl (pIIR_ProcedureDeclaration (sbp), str, rstack, l);
    } 
  else
    {
      emit_plain_subprogram_impl (sbp, str, rstack, l);
    }

  rstack.pop();
}





// Print subprogram implementation
void
m_emit_impl (pIIR_PredefinedFunctionDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  // Nothing to do.
}


// Print subprogram implementation
void
m_emit_impl (pIIR_PredefinedProcedureDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  // Nothing to do.
}


void                                                            // SeqStatList impl
m_emit_impl (pIIR_SequentialStatementList sl, string &str, RegionStack &rstack, int l)	
{
  while (sl)
    {
      pIIR_SequentialStatement s = sl->first;
      
      //if (s->label)
      //{
      //  emit_id (s->label->declarator, str, rstack);
      //  str += ": ";
      //}
      emit_impl (s, str, rstack, l);
      sl = sl->rest;
    }
}


void
m_emit_impl (pIIR_NullStatement, string &str, RegionStack &rstack, int l)
{
  str += "/* NullStat impl */;\n";
}


void
m_emit_impl (pIIR_ReturnStatement r, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(r->pos, str, last_pos_info, l);

  if (r->return_expression != NULL) {
    // Ok, this return statement belongs to a function
    pIIR_FunctionDeclaration func = pIIR_FunctionDeclaration(r->enclosing_subprogram);
    
    string return_expr;
    emit_expr (r->return_expression, return_expr, rstack, DEFAULT);

    if (is_array_type(func->return_type))
      // Return value is an array
      if (is_constrained_array_type(func->return_type)) {
	string alias_expr = "array_alias<" + 
	  qid(get_declaration(get_base_type(func->return_type)), rstack, id_type()) + " >(" + 
	  get_type_info_obj(func->return_type, rstack, false);
	return_expr = alias_expr + ",(" + return_expr + ").data)";

      } else {
	string alias_expr = "array_alias<" + 
	  qid(get_declaration(get_base_type(func->return_type)), rstack, id_type()) + " >(" + 
	  get_type_info_obj(func->return_type, rstack, false);
	return_expr = alias_expr + "," + return_expr + ")";

      }

    str += spaces(l) + "return " + return_expr + ";\n";

  } else
    // Ok, this return statement belongs to a procedure
    str += spaces(l) + "goto rlabel;\n";
}


void
m_emit_impl (pIIR_VariableAssignmentStatement a, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(a->pos, str, last_pos_info, l);
  
  str += spaces(l);
  emit_expr (a->target, str, rstack, id_type(READER, DEREF));
  str += "=";
  emit_expr (a->expression, str, rstack, id_type(READER, DEREF));
  str += ";\n";
}

void
m_emit_impl (pIIR_IfStatement is, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(is->pos, str, last_pos_info, l);

  str += spaces(l) + "if(";
  emit_expr (is->condition, str, rstack, DEFAULT);
  str += ") {\n";
  if (is->then_sequence != NULL)
    emit_impl (is->then_sequence, str, rstack, l+2);
  if (is->else_sequence != NULL)
    {
      str += spaces(l) + "} else {\n";
      emit_impl (is->else_sequence, str, rstack, l+2);
    }
  str += spaces(l) + "}\n";
}


// Emit code for a case statement where the selection expression is
// scalar
void
emit_impl_scalar_case_statement (pIIR_CaseStatement cs, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(cs->pos, str, last_pos_info, l);

  str += spaces(l) + "switch(";
  emit_expr (cs->expression, str, rstack, id_type(READER, DEREF));
  str += ") {\n";
  
  for (pIIR_CaseStatementAlternativeList al = cs->case_statement_alternatives; al; al = al->rest) {
    pIIR_CaseStatementAlternative a = al->first;
    
    string case_str = spaces(l);
    
    for (pIIR_ChoiceList cl = a->choices; cl; cl = cl->rest)
      
      if (cl->first->is(IR_CHOICE_BY_RANGE)) {
	//***************************************
	// Choice by range
	//***************************************
	
	pIIR_ChoiceByRange cbr = pIIR_ChoiceByRange(cl->first);
	
	// Get range.
	vector<RangeDescriptor> range_desc = get_discrete_range(cbr->range, rstack, IR_LOCALLY_STATIC);
	StaticRangeDescriptor<lint, IR_Direction> range = 
	  range_desc[0].rangedes_to_lint(rstack);
	if (range.left == range.right)
	  case_str += "case " + to_string(range.left) + ": ";
	else if (range.left < range.right && range.dir == IR_DIRECTION_UP)
	  case_str += "case " + to_string(range.left) + " ... " + to_string(range.right) + ": ";
	else if (range.left > range.right && range.dir != IR_DIRECTION_UP)
	  case_str += "case " + to_string(range.right) + " ... " + to_string(range.left) + ": ";
	
      } else if (cl->first->is(IR_CHOICE_BY_EXPRESSION)) {
	//***************************************
	// Choice by expression
	//***************************************
	
	pIIR_ChoiceByExpression cbe = pIIR_ChoiceByExpression(cl->first);
	int value = int(folded_value(cbe->value).long_value());
	case_str += "case " + to_string(value) + ": ";
	
      } else if (cl->first->is(IR_CHOICE_BY_OTHERS)) {
	//***************************************
	// Choice by others
	//***************************************
	case_str += "default: ";
      }
    
    str += case_str + "{\n";
    if (a->sequence_of_statements != NULL)
      // Analyze sequential statements associated with alternative
      emit_impl(a->sequence_of_statements, str, rstack, l + 2);
    str += spaces(l + 1) + "} break;\n";
  }
  
  str += spaces(l) + "}\n";
}



template <class T>
struct bitwise_and : public binary_function<T,T,T>
{
  bool operator()(const T& x, const T& y) const { return x & y; }
};
 
template <class T>
struct bitwise_or : public binary_function<T,T,T>
{
  bool operator()(const T& x, const T& y) const { return x | y; }
};
 

template <class T>
struct bitwise_xor : public binary_function<T,T,T>
{
  bool operator()(const T& x, const T& y) const { return x ^ y; }
};
 

inline unsigned int
rotate_left(unsigned int value, int count)
{
  return (value << count) | (value >> (sizeof(unsigned int) * 8 - count));
} 


// Count bit set in value. The algorithm is not very smart...
inline int
bit_count(unsigned int value)
{
  int result = 0;
  while (value) {
    if (value & 0x1) result++;
    value >>= 1;
  }
  return result;
}


// Find an bit shift width for pattern "bits" so that after shifting
// most of the bits set in "bits" are also set in free_bits.
int 
find_best_shift(unsigned int free_bits, int bits)
{
  const int max_shift = sizeof(int) * 8 - 1;
  int best_shift = -1, best_result = -1;

  for (int i = 0; i < max_shift; i++) {
    int result = bit_count(free_bits & rotate_left((unsigned int)bits, i));
    if (result > best_result) {
      best_result = result;
      best_shift = i;
    }
  }

  return best_shift;
}


// Emit code for a case statement where the selection expression is
// an one dimensional array
void
emit_impl_array_case_statement (pIIR_CaseStatement cs, string &str, RegionStack &rstack, int l)
{
  // We generate hash numbers from each selection expression to
  // speedup the slection process. A case statement like:
  
  // case var is
  // when "000" => ...
  // when "001" => ...
  // when  others => ...
  // end case;

  // is translated to (the hash numbers are chosen arbitrarily):

  // enumeration int1_lit[] = { 0, 0, 0 };
  // enumeration int2_lit[] = { 0, 0, 1 };
  // unsigned int int3_keys[] = { 12, 34 }; /* two hash numbers */
  // unsigned int int4_key_to_lit[] = { 0, 2 }; 
  // enumeration *int5_lit_tab[] = { int1_lit,  0, int2_lit,  0};
  // int          int6_action[] =  {        0, -1,       1 , -1};
  // memcpy(int7_selection, slection_expression.data, 3);
  // switch (do_case_select(3, 2, int7_selesction[0]^rot_left(int7_selection[1], 1), 
  //            int7_selection, int3_keys, int4_key_to_lit, int5_lit_tab, 
  //            int6_action)) {
  // case 0: ...
  // case 1: ...
  // default: ...
  // }

  // int1_lit and int2_lit are literal values translated into
  // enumeration array constant. int3_keys stores for each literal the
  // corresponding hash number while int4_key_to_lit is an index table
  // which points to the corresponding entry in int5_lit_tab. E.g., if
  // hash number 34 is calculated from the selection expression then
  // the *second* element of the key tables matches. Hence, we select
  // the *second* element of the int4_key_to_lit table which gives us
  // index number 1. This index is used to address the lit_tab table
  // which holds pointers to the corresponding array literal
  // constant(s). We need this constants to re-check whether the
  // selection expression really matches the array literal. Note that
  // more than one choice pattern my have the same hash value. Hence,
  // we compare all literal constants until the number 0 is reached in
  // the int5_lit_tab table. When we have a match (or a 0 is reached)
  // then the *corresponding* entry in the action table (int6_action)
  // is chosen as action number. This action number is finally used in
  // the case statement to select the appropriate alternative. Note
  // that do_case_select is an inlined function which performs most of
  // the described processing.
  
  // Note further that the hash number is generated by packing four
  // consecutive elements of the enumeration value into a int and then
  // processing the int values as shown below.
  
  // First, collect all pattern into a single list
  typedef vector<int> int_vec;
  vector<int_vec> all_pattern;
  int_vec alternative_number;
  int current_alternative_number = 0;
  for (pIIR_CaseStatementAlternativeList al = cs->case_statement_alternatives; 
       al; al = al->rest, current_alternative_number++) {
    pIIR_CaseStatementAlternative a = al->first;
    for (pIIR_ChoiceList cl = a->choices; cl; cl = cl->rest)
      if (cl->first->is(IR_CHOICE_BY_EXPRESSION)) {
	pIIR_ChoiceByExpression cbe = pIIR_ChoiceByExpression(cl->first);
	all_pattern.push_back(folded_value(cbe->value).array_literal_value());
	alternative_number.push_back(current_alternative_number);
      } 
  }

  // Next, determine pairwise difference of all pattern pairs and or
  // together these differences. This is done in order so detect
  // whether there are some bits that have the SAME value among all
  // choice pattern. After execution of the main loop diff_pattern
  // will consist of a sequence of integer values where each bit set
  // to 1 indicates that there are at least two pattern which are
  // having different bit values at the corresponding bit position
  // (the reason where are doing this here is: bits that are always
  // the same among all pattern are ingnored when generating the hash
  // values from the pattern).
  const int pattern_length = all_pattern.size() == 0? 0 : all_pattern[0].size();
  int_vec diff_pattern(pattern_length);
  fill(diff_pattern.begin(), diff_pattern.end(), 0);
  for (vector<int_vec>::iterator iter1 = all_pattern.begin(); iter1 != all_pattern.end(); iter1++) {
    vector<int_vec>::iterator iter1_next = iter1;
    for (vector<int_vec>::iterator iter2 = ++iter1_next; iter2 != all_pattern.end(); iter2++) {
      // First, xor pattern pair
      int_vec diff(pattern_length);
      transform((*iter1).begin(), (*iter1).end(), (*iter2).begin(), diff.begin(), bitwise_xor<int>());
      // Then, or result into diff_pattern
      transform(diff.begin(), diff.end(), diff_pattern.begin(), diff_pattern.begin(), bitwise_or<int>());
    }
  }
  
  const int sizeof_uint = sizeof(unsigned int);
  
  // Now find for each group of four (or less in case of the last
  // elements) elements of the difference vector a shift value so that
  // the set bits of all elements do not overlap. This is not possible
  // for the general case. Hence, try to minimize overlapping.
  int_vec shift_vector((pattern_length + sizeof_uint - 1)/sizeof_uint);
  fill(shift_vector.begin(), shift_vector.end(), 0);
  unsigned int free_bits = 0;
  for (int i = 0, word = 0; i < pattern_length; i += sizeof_uint, word++) {
    // If there are no more free bits to use then set all bits of
    // free_bits
    if (free_bits == 0)
      free_bits = (unsigned)0 - (unsigned)1;
    unsigned int diff_group = 0;
    for (int byte = i; (byte < pattern_length) && (byte < i + sizeof_uint); byte++) {
#ifndef WORDS_BIGENDIAN 
      // This is a little endian machine 
      diff_group |= (unsigned int)diff_pattern[byte] << (8 * (byte - i));
#else
      // This is a big endian machine
      diff_group |= (unsigned int)diff_pattern[byte] << (8 * (sizeof_uint - 1 - (byte - i)));
#endif
    } 
    // If all elements of all choice vectors are the same then we
    // simply store a -1 as shift value to indicate that this
    // particular group should not be used.
    if (diff_group == 0) {
      shift_vector[word] = -1;
      continue;
    }
    shift_vector[word] = find_best_shift(free_bits, diff_group);
    // Remove used bits from free_bits
    free_bits &= ~rotate_left(diff_group, shift_vector[word]);
  }

  // Calculate hash number for each pattern. The hash number is
  // stored in key_vector.
  vector<unsigned int> key_vector(all_pattern.size());
  for (unsigned int i = 0; i < all_pattern.size(); i++) {
    unsigned int key = 0;
    int_vec &pattern = all_pattern[i];
    for (int j = 0, word = 0; j < pattern_length; j += sizeof_uint, word++) {
      if (shift_vector[word] == -1)
	continue;
      unsigned int pattern_group = 0;
      for (int byte = j; (byte < pattern_length) && (byte < j + sizeof_uint); byte++) {
#ifndef WORDS_BIGENDIAN 
	// This is a little endian machine 
	pattern_group |= (unsigned int)pattern[byte] << (8 * (byte - j));
#else
	// This is a big endian machine
	pattern_group |= (unsigned int)pattern[byte] << (8 * (sizeof_uint - 1 - (byte - j)));
#endif
      } 
      key ^= rotate_left(pattern_group, shift_vector[word]);
    }
    key_vector[i] = key;
  }
  
  // Create internal array constants which store the literal
  // values. Note that this constants will be declared globally.
  pIIR_DeclarativeRegion root_region = RootDeclarativeRegion(rstack);
  vector<string> literal_names(all_pattern.size());
  for (unsigned int i = 0; i < all_pattern.size(); i++) {
    // Generate internal constant name
    literal_names[i] = get_new_internal_var_prefix() + "_lit";
    // The initial value of the constant is the concatenation of all
    // integer values separated by ","
    string init_str = "[]={" + concat_to_string(all_pattern[i].begin(), all_pattern[i].end(), ",") + "}";
    // Declare the internal variable as a global constant 
    insert_internal_object_declaration(NULL, root_region, NULL, literal_names[i],
				       "enumeration", init_str, DECLARE_GLOBALLY | DECLARE_AND_INIT);
  }

  // Calculate the various tables shown in the following example:
  // unsigned int int3_keys[] = { 12, 34 }; /* two hash numbers */
  // unsigned int int4_key_to_lit[] = { 0, 2 }; 
  // enumeration *int5_lit_tab[] = { int1_lit,  0, int2_lit,  0};
  // int          int6_action[] =  {        0, -1,       1 , -1};
  vector<bool> done(all_pattern.size());
  fill(done.begin(), done.end(), false);
  list<unsigned int> key_list, key_to_lit_list;
  list<int> action_list;
  list<string> lit_tab_list;
  int current_key_to_lit_index = 0;
  for (unsigned int i = 0; i < all_pattern.size(); i++ ) {
    if (done[i]) continue;
    done[i] = true;
    key_list.push_back(key_vector[i]);
    key_to_lit_list.push_back(current_key_to_lit_index);
    lit_tab_list.push_back(literal_names[i]);
    action_list.push_back(alternative_number[i]);
    for (unsigned int j = i + 1; j < all_pattern.size(); j++)
      if (key_vector[i] == key_vector[j]) {
	lit_tab_list.push_back(literal_names[j]);
	action_list.push_back(alternative_number[j]);
	done[j] = true;
      }
    lit_tab_list.push_back(string("0"));
    action_list.push_back(-1);
    current_key_to_lit_index = lit_tab_list.size();
  }


  // Create and init key constant array
  string key_list_name = get_new_internal_var_prefix() + "_keys";
  string init_str = "[]={" + concat_to_string(key_list.begin(), key_list.end(), ",") + "}";
  insert_internal_object_declaration(NULL, root_region, NULL, key_list_name,
				     "const unsigned int", init_str, DECLARE_GLOBALLY | DECLARE_AND_INIT);

  // Create and init key_to_lit constant array
  string key_to_lit_name = get_new_internal_var_prefix() + "_key_to_lit";
  init_str = "[]={" + concat_to_string(key_to_lit_list.begin(), key_to_lit_list.end(), ",") + "}";
  insert_internal_object_declaration(NULL, root_region, NULL, key_to_lit_name,
				     "const int", init_str, DECLARE_GLOBALLY | DECLARE_AND_INIT);

  // Create and init lit_tab constant array
  string lit_tab_name = get_new_internal_var_prefix() + "_lit_tab";
  init_str = "[]={" + concat_to_string(lit_tab_list.begin(), lit_tab_list.end(), ",") + "}";
  insert_internal_object_declaration(NULL, root_region, NULL, lit_tab_name,
				     "const enumeration *", init_str, DECLARE_GLOBALLY | DECLARE_AND_INIT);

  // Create and init action constant array
  string action_name = get_new_internal_var_prefix() + "_action";
  init_str = "[]={" + concat_to_string(action_list.begin(), action_list.end(), ",") + "}";
  insert_internal_object_declaration(NULL, root_region, NULL, action_name,
				     "const int", init_str, DECLARE_GLOBALLY | DECLARE_AND_INIT);

  // Create an global variable which stores the data part of the
  // selection array. Note that this variable does not have a real
  // initial value as it will be initialised each time the case
  // statement is executed.
  string selection_var_name = get_new_internal_var_prefix() + "_selection";
  insert_internal_object_declaration(NULL, root_region, NULL, selection_var_name,
				     "unsigned int", "[" + to_string((pattern_length + sizeof_uint - 1) / sizeof_uint) + "]", 
				     DECLARE_GLOBALLY | DECLARE_AND_INIT);

  // Generate the code which calculates the hash number from an
  // selection value
  list<string> hash_number_code_items;
  for (int i = 0, word = 0; i < pattern_length; i += sizeof_uint, word++)
    if (shift_vector[word] != -1) {
      unsigned int mask = (unsigned int)0 - (unsigned int)1;
#ifndef WORDS_BIGENDIAN 
      // This is a little endian machine 
      mask = (i + sizeof_uint - 1 < pattern_length)? 
	mask : (mask >> (sizeof_uint - i % sizeof_uint) * 8);
#else
      // This is a big endian machine
      mask = (i + sizeof_uint - 1 < pattern_length)? 
	mask : (mask >> ((i % sizeof_uint) * 8));
#endif
      // Create code which fetches the next four bytes of the
      // selection array. Note that usually four enumeration values
      // are fetched concurrently this way.
      string code_item = selection_var_name + "[" + to_string(word) + "]";
      if (~mask != 0)
	// If not all bits in mask are set then use mask to remove
	// unused bytes in the fetched word
	code_item = "(" + code_item + "&" + to_string(mask) + ")";
      // If the shift value for the current word is not equal to zero
      // than add code to perform the rotate operations.
      if (shift_vector[word] != 0)
	code_item = "rotate_left(" + code_item + "," + to_string(shift_vector[word]) + ")";
      // Finally, add code_item to list
      hash_number_code_items.push_back(code_item);
    }

  // Print line and file info
  last_pos_info = emit_posinfo(cs->pos, str, last_pos_info, l);
  str += spaces(l) + "memcpy(" + selection_var_name + ",";
  emit_expr (cs->expression, str, rstack, id_type(READER, DEREF));
  str += ".data," + to_string(pattern_length) + "*sizeof(enumeration)); ";
  // Add the code to calculate the selection expression for the
  // transformed case statement
  string hash_number_code = hash_number_code_items.size() != 0? 
    concat_to_string(hash_number_code_items.begin(), hash_number_code_items.end(), "^") : "0";
  str += "switch (do_case_select(" + 
    to_string(pattern_length) + "," + 
    to_string(key_list.size()) + "," + 
    hash_number_code + "," + 
    selection_var_name + "," + 
    key_list_name + "," + 
    key_to_lit_name + "," + 
    lit_tab_name + "," + 
    action_name + ")) {\n";

  // Now, add the code for the alternatives of the case statement
  int case_counter = 0;
  for (pIIR_CaseStatementAlternativeList al = cs->case_statement_alternatives; al; al = al->rest, case_counter++) {
    pIIR_CaseStatementAlternative a = al->first;
    
    str += spaces(l);
    
    if (a->choices->first->is(IR_CHOICE_BY_OTHERS))
	//***************************************
	// Choice by others
	//***************************************
      str += "default: ";
    else
      str += "case " + to_string(case_counter) + ":";

    str += "{\n";
    // Emit sequential statements associated with alternative
    if (a->sequence_of_statements != NULL)
      emit_impl(a->sequence_of_statements, str, rstack, l + 2);
    str += spaces(l + 1) + "} break;\n";
  }
  str += spaces(l) + "}\n";

}


void
m_emit_impl (pIIR_CaseStatement cs, string &str, RegionStack &rstack, int l)
{
  // A case statement. This is probably too complicated. We should
  // somehow unify ranges and subtypes
  
  if (is_scalar_type(cs->expression->subtype))
    //****************************************************
    // Expression is scalar
    //****************************************************
    emit_impl_scalar_case_statement(cs, str, rstack, l);
  else
    //****************************************************
    // Expression is an array 
    //****************************************************
    emit_impl_array_case_statement(cs, str, rstack, l);
}


void
m_emit_impl (pIIR_LoopStatement ls, string &str, RegionStack &rstack, int l)
{
  ContextInfo &ctxt = *ActiveContext(rstack);
  pIIR_DeclarativeRegion active_region = ActiveDeclarativeRegion(rstack);

  // Check whether a name has been associated with the loop statement
  if (ls->declarative_region->declarator == NULL) {
    // If the loop statement has no name then create a default name
    string loop_name = to_string(ls->declarative_region->seqno) + loop_default_postfix;
    ls->declarative_region->declarator = new IIR_TextLiteral(0, loop_name.c_str());
  }

  // Print line and file info
  last_pos_info = emit_posinfo(ls->pos, str, last_pos_info, l);

  if (ls->is(IR_WHILE_LOOP_STATEMENT))
    {
      str += spaces(l) + "while(";
      emit_expr (pIIR_WhileLoopStatement(ls)->condition, str, rstack, DEFAULT);
      str += ")";
    }
  else if (ls->is(IR_FOR_LOOP_STATEMENT))
    {
      pIIR_ForLoopStatement fl = pIIR_ForLoopStatement (ls);
      // generate a internal variable for the loop variable, and the
      // loop counter which stores the number of iterations.
      string loop_var_name = qid(fl->iterator, rstack, id_type());
      string loop_counter_name = loop_var_name + "_lc";
      string loop_step_name = loop_var_name + "_ls";
      string loop_var_type = qid(get_declaration(fl->iterator->subtype), rstack, TYPE);

      // Get iteration range
      vector<RangeDescriptor> range_desc = 
	get_discrete_range (pIIR_ScalarSubtype(fl->iterator->subtype)->range, rstack, IR_NOT_STATIC);
      StaticRangeDescriptor<string, string> range = 
	range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));

      // Create internal variables which will hold the iteration
      // bounds
      insert_internal_object_declaration(NULL, active_region, NULL, loop_var_name, loop_var_type, "", 0);
      insert_internal_object_declaration(NULL, active_region, NULL, loop_counter_name, loop_var_type, "", 0);
      if (!range_desc[0].is_explicit_range())
	insert_internal_object_declaration(NULL, active_region, NULL, loop_step_name, loop_var_type, "", 0);

      if (range_desc[0].is_explicit_range())
	{
	  str += spaces (l) + "for (" + loop_var_name + "=" + range.left + "," + loop_counter_name + "=" + 
	    string (range.dir == "to"? "up_range_to_length" : "down_range_to_length") + "<" + loop_var_type + ">(" +
	    range.left + "," + range.right + "); ";
	  str += loop_counter_name + "!=0; ";
	  str += loop_var_name + string(range.dir=="to"? "++" : "--") + "," + loop_counter_name + "--)";
	} 
      else 
	{
	  str +=  spaces (l) + "for (" + loop_var_name + "=" + range.left + "," + loop_step_name + "=" + range.dir + "==to?+1:-1," + 
	    loop_counter_name + "=range_to_length<" + loop_var_type + ">(" + range.left + "," + range.dir + "," + range.right + ");";
	  str += loop_counter_name + "!=0" + "; ";
	  str += loop_var_name + "+=" + loop_step_name + "," + loop_counter_name + "--)";
	}
    }
  else
    str += spaces(l) + "while(1)";

  str += " {\n";
  if (ls->sequence_of_statements != NULL)
    emit_impl (ls->sequence_of_statements, str, rstack, l+2);
  str += spaces(l);

  // If a next statement has been used for this loop then add an
  // appropriate label
  if (next_statement_used(ls))
    str += "next_" + to_string(loop_id(ls)) + ":; ";

  str += "}";

  // If a exit statement has been used for this loop then add an
  // appropriate label
  if (exit_statement_used(ls))
    str += " exit_" + to_string(loop_id(ls)) + ":; ";

  str += "\n";
}


void
m_emit_impl (pIIR_NextStatement ns, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(ns->pos, str, last_pos_info, l);

  string jump_code = "goto next_" + to_string(loop_id(ns->loop)) + ";\n";
  if (ns->condition) {
    str += spaces(l) + "if (";
    emit_expr (ns->condition, str, rstack, id_type(READER, DEREF));
    str += ") " + jump_code;
  } else
    str += spaces(l) + jump_code;
}


void
m_emit_impl (pIIR_ExitStatement es, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(es->pos, str, last_pos_info, l);

  string jump_code = "goto exit_" + to_string(loop_id(es->loop)) + ";\n";
  if (es->condition) {
    str += spaces(l) + "if (";
    emit_expr (es->condition, str, rstack, id_type(READER, DEREF));
    str += ") " + jump_code;
  } else
    str += spaces(l) + jump_code;
}


void
m_emit_impl (pIIR_ProcedureCallStatement pcs, string &str, RegionStack &rstack, int l)
{
  // A procedure call.

  // Print line and file info
  last_pos_info = emit_posinfo(pcs->pos, str, last_pos_info, l);

  pIIR_ProcedureDeclaration p = pcs->procedure;

  // Check whether the procedure contains wait statements
  if (has_wait (pIIR_ProcedureDeclaration (p)) ||
      has_wait_for (pIIR_ProcedureDeclaration (p)))
    {
      // This procedure contains wait statements. Hence, a
      // corresponding instance of the procedure object is
      // created and called.

      // If the caller is a process, then the this pointer is passed
      // over to the procedure class constructor. Otherwise (i.e., if
      // the caller is also a procedure), variable "process" must be
      // passed over. Note that this variable points to the
      // corresponding process this procedure is called from. The
      // constructor needs this information in order to idnetify the
      // "source" process.
      pIIR_DeclarativeRegion base_region = BaseDeclarativeRegion(rstack);
      string caller_str = base_region->is (IR_PROCESS_STATEMENT)? "this" : "process";

      int windex = wait_info_index (pcs);
      str += spaces (l) + "pdelayed_procedure=new " 
	+ qid (p, rstack, DEFAULT) + "(" + caller_str + ",winfo[" + to_string (windex) + "]";
      
      string assoc_str;
      emit_subprogram_associations (assoc_str, rstack, pcs->actual_parameter_part, 
				    p->interface_declarations,
				    context(p).extra_interface_objects);
      str += (assoc_str != ""? "," : "" ) + assoc_str;
      str += "); ";
      str += "jmp=" + to_string (windex + 1) + "; lab" + to_string (windex + 1) + ":" 
	+ " if (((" + qid (p, rstack, DEFAULT) + "*)pdelayed_procedure)->execute()) return true; "
	+ "delete (" +  qid (p, rstack, DEFAULT) + "*)pdelayed_procedure;\n";
    }
  else
    {
      // Ok, this is a plain procedure without wait statements
      str += spaces(l) + qid(p, rstack, DEFAULT);
      str += " (";
      emit_subprogram_associations (str, rstack, pcs->actual_parameter_part, 
				    p->interface_declarations,
				    context(p).extra_interface_objects);
      str += ");\n";
    }
}

void
m_emit_impl (pIIR_WaitStatement ws, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(ws->pos, str, last_pos_info, l);

  pIIR_DeclarativeRegion region = BaseDeclarativeRegion (rstack);
  if (region->is (IR_SENSITIZED_PROCESS_STATEMENT) ||
      region->is (IR_IMPLICIT_PROCESS_STATEMENT)) {
    /* If the wait is in an implicit process (concurrent signal
     * assignment) then any code to activate the wait statement can
     * be skipped, because only a single wait will be active all the
     * time. */
    return;

  } else if (ws->condition_clause == NULL &&
      ws->timeout_clause == NULL &&
      ws->sensitivity_list == NULL) {
    // If there is no condition clause and no timeout clause and no
    // sensitivity_list then this wait statements shall stop the
    // process for the rest of the simulation time.
    str += spaces(l) + "wait(PROCESS_STOP); return true;\n";

  } else {
    int windex = wait_info_index(ws);
    str += spaces(l) + "wait(winfo[" + to_string(windex) + "]); ";
    str += "jmp = " + to_string(windex + 1) + "; ";

    pV2CC_ImplicitSignalDeclaration_WaitFor implicit_signal_decl = NULL;
    if (ws->timeout_clause != NULL) {
      // Determine declaration of implicit signal. Because there is
      // only a single implicit signal for each process which uses a
      // timeout clause simply access the first element of the list
      // returned from filter_unique.
      list<pIIR_Declaration> l = 
	filter_unique(extended_declarations(BaseDeclarativeRegion(rstack)),
		      V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR);
      // Check whether an appropriate implicit signal could be
      // found. If not, then we are probably in a subprogram. In this
      // case, search the extra interface objects for an appropriate
      // signal. Note that in case of an "wait for" executed within a
      // subprogram, an appropriate implicit signal is declared within
      // the corresponding process and this signal is passed over to
      // the subprogram via its interface.
      if (l.size () == 0 &&
	  BaseDeclarativeRegion (rstack)->is (IR_SUBPROGRAM_DECLARATION))
	{
	  // Search extra interface objects for an appropriate
	  // implicit signal.
	  list < AccessDescriptor > al =
	    filter_unique(BaseContext (rstack)->extra_interface_objects,
			  ACCESS, 
			  V2CC_IMPLICIT_SIGNAL_DECLARATION_WAIT_FOR);
	  // Ok, if we found one, then extract the signal declaration
	  // and push it on the result list l.
	  if (al.size () > 0)
	    l.push_back (al.front ().declaration);
	}
      assert (l.size() > 0);
      implicit_signal_decl =
	pV2CC_ImplicitSignalDeclaration_WaitFor(l.front());

      // Generate a signal assignment to a special implicit signal
      // which activates the process in case of a timeout. The
      // assignment is a special signal assignment as it removes all
      // pending transactions from the driver and also immediately
      // sets the reader value to '0'.
      str += qid(implicit_signal_decl, rstack, id_type(DRIVER)) + "->reset_assign(0,1,";
      emit_expr(ws->timeout_clause, str, rstack, id_type(READER, DEREF));
      str += "); ";
    }
    str += "return true; ";
    str += "lab" + to_string(windex + 1) + ":; ";
      
    // Emit code to test condition 
    if (ws->condition_clause != NULL) {
      if (ws->timeout_clause != NULL)
	str += "if ((!" + qid(implicit_signal_decl, rstack, id_type(READER, DEREF)) + ")&&(";
      else 
	str += "if (!(";
      emit_expr(ws->condition_clause, str, rstack, id_type(READER, DEREF)); 
      str += ")) return false;";
    }
    str += "\n";
  }
}

void
m_emit_impl (pIIR_AssertionStatement as, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(as->pos, str, last_pos_info, l);

  str += spaces(l) + "if(!";
  emit_expr (as->assertion_condition, str, rstack, DEFAULT);
  str += ")\n";
  str += spaces(l + 2) + "report(";
  if (as->report_expression != NULL)
    {
      emit_expr (as->report_expression, str, rstack, DEFAULT);
      str += ",";
    }
  if (as->severity_expression != NULL)
    emit_expr (as->severity_expression, str, rstack, DEFAULT);
  else
    str += "0";
  str += ");\n";
}

void
m_emit_impl (pIIR_ReportStatement rs, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(rs->pos, str, last_pos_info, l);

  str += spaces(l) + "report(";
  if (rs->report_expression != NULL)
    {
      emit_expr (rs->report_expression, str, rstack, DEFAULT);
      str += ",";
    }
  if (rs->severity_expression != NULL)
    emit_expr (rs->severity_expression, str, rstack, DEFAULT);
  else
    str += "0";
  str += ");\n";
}


void
m_emit_impl (pIIR_SignalAssignmentStatement sa, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(sa->pos, str, last_pos_info, l);

  // determine the signals that are written!
  ContextInfo &ctxt = *ActiveContext(rstack);

  // Determine target signals.
  ContextInfo local_ctxt;
  get_context(sa->target, local_ctxt, rstack, true, 0);
  list<AccessDescriptor> sig_written = 
    filter(local_ctxt.accessed_objects, WRITE, 
	   tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));

  // bail out if more than one signal is written. Only simple signal
  // assignment targets are supported yet.
  if (sig_written.size() > 1)
    codegen_error.error("%:error: sorry, no resolved signals are supproted yet", sa);
    
  // Get decelration of target signal
  pIIR_SignalDeclaration target_sig_decl = (pIIR_SignalDeclaration)sig_written.front().declaration;

  // Determine the first part of the synthesized signal assignment statement
  string target_str, target_specifier;

  if (codegen_options.get_verbose ())
    codegen_error.info ("%:target %n", sa, target_sig_decl);

  if (is_scalar_type(target_sig_decl->subtype)) {
    //******************************************************************
    // if the target is a scalar signal then simply get the driver for
    // that signal
    //******************************************************************
    target_str = qid(target_sig_decl, rstack, id_type(DRIVER));

  } else if (is_scalar_type(sa->waveform->first->value->subtype)) {
    //******************************************************************
    // if the target is a *scalar* element of a composite signal then
    // get the scalar driver for that element
    //******************************************************************
    list<pair<pIIR_Expression, pIIR_Root> >acl_list;
    get_acl(sig_written.front().access_expr, acl_list, rstack, IR_NOT_STATIC, true);
    // generate a name for a new acl object
    string internal_var_name = create_internal_acl(get_acl_size(acl_list), rstack, false);
    // Create signal assignment code
    target_str = qid(target_sig_decl, rstack, id_type(DRIVER)) + 
      "->scalar_driver(&(" + sprint_acl(acl_list, internal_var_name + "->clear()", 
					rstack, id_type(DEFAULT, DEREF)) + "))";

  } else {
    //******************************************************************
    // Several elements of a composite signal are target of the
    // assignment operation. First, get acl for assignment target
    //******************************************************************
    list<pair<pIIR_Expression, pIIR_Root> > acl_list;
    get_acl(sig_written.front().access_expr, acl_list, rstack, IR_NOT_STATIC, true);

    // Check whether the entrire signal or a only a part of the signal
    // is target of the assignement
    if (acl_list.size()) {
      // Only a part of the signal is targeted. First, generate a name
      // for a new acl object
      string internal_var_name = create_internal_acl(get_acl_size(acl_list), rstack, false);
      // Create signal assignment code
      target_str = qid(target_sig_decl, rstack, id_type(DRIVER));
      target_specifier = ",&(" + sprint_acl(acl_list, internal_var_name + "->clear()", 
					    rstack, id_type(DEFAULT, DEREF)) + ")";
      
    } else {
      // the *entire* signal is assignement target
      target_str = qid(target_sig_decl, rstack, id_type(DRIVER));
      target_specifier = ",0";
    }
  }

  bool first = true;
  for (pIIR_WaveformList wl = sa->waveform; wl; wl = wl->rest)
    {
      if (!first)
        str += spaces(1);
      str += spaces(l) + target_str;
      if (sa->delay_mechanism==IR_INERTIAL_DELAY && first)
	str += "->inertial_assign(";
      else
	str += "->transport_assign(";

      pIIR_WaveformElement we = wl->first;
      string value_str;
      emit_expr (we->value, value_str, rstack, id_type(READER, DEREF));
      value_str += target_specifier;
      if (we->time) {
	value_str += ",vtime(";
	emit_expr (we->time, value_str, rstack, id_type(READER));     
      } else 
	value_str += ",vtime(0";

      str += value_str + "));\n";
      first = false;
    }
}


void
m_emit_impl (pIIR_SequentialStatement s, string &str, RegionStack &rstack, int l)
{
  str += string("/* emit statement ") + s->kind_name () + string(" */\n");
}


void
m_emit_impl (pIIR_ComponentInstantiationStatement ci, string &str, RegionStack &rstack, int l)
{
}

void
m_emit_impl (pIIR_BlockStatement bs, string &str, RegionStack &rstack, int l)
{
  // Print line and file info
  last_pos_info = emit_posinfo(bs->pos, str, last_pos_info, l);

  str += "block ";
  str += string("\n") + spaces(l) + string("{\n");
  emit_decls (extended_declarations(bs), str, rstack, l+2);
  if (extended_declarations(bs))
    str += "\n";
  //  emit (bs->block_statement_part, str, rstack, l+2);
  str += spaces(l) + string("}\n\n");
}

void
m_emit_impl (pIIR_ConcurrentGenerateStatement gs, string &str, RegionStack &rstack, int l)
{
  rstack.push(gs);

  // First, emit concurrent statement code
  emit_impl(gs->concurrent_statement_part, str, rstack, l);

  // Create a list of declarative region pointers beginning from the
  // target region up to the root region
  list<pIIR_DeclarativeRegion> RegionList = create_region_list(gs);
  RegionList.pop_front();

  // For each generate region as well as the enclosing architecture
  // region a corresponding pointer is declared and added as a
  // parameter to the constructor.
  string constructor_pars, separator;
  for (list<pIIR_DeclarativeRegion>::iterator iter = RegionList.begin(); 
       iter != RegionList.end(); iter++)
    if ((*iter)->is(IR_ARCHITECTURE_DECLARATION) || 
	(*iter)->is(IR_CONCURRENT_GENERATE_STATEMENT) ||
	(*iter)->is(IR_BLOCK_STATEMENT)) {
      constructor_pars += separator + qid(*iter, rstack, id_type()) + " *" + qid(*iter, rstack, id_type()) + "_AP_PAR";
      insert_internal_object_declaration(get_last_rest_address(&extended_interface_declarations(gs)), 
					 gs, gs->pos, qid(*iter, rstack, id_type()) + "_AP", 
					 qid(*iter, rstack, id_type()) + "*", 
					 "=" + qid(*iter, rstack, id_type()) + "_AP_PAR", 
					 DECLARE_LOCALLY);
      separator = ",";
  }

  // If this is a "for" generate statement then an additional class
  // member is created which stores the value of the iterator
  // variable. Note that this member is actually set only once during
  // elaboration. Note further that for each iteration a new instance
  // of this class is generated!
  if (gs->is(IR_CONCURRENT_GENERATE_FOR_STATEMENT)) {
    pIIR_ConcurrentGenerateForStatement for_gs = pIIR_ConcurrentGenerateForStatement(gs);
    // First, remove the iteration variable from the normal
    // decalaration list. 
    pIIR_DeclarationList *prev_rest_pointer = &extended_declarations(gs);
    for (pIIR_DeclarationList dl = *prev_rest_pointer; dl; prev_rest_pointer = &dl->rest, dl = dl->rest) 
      if (dl->first == for_gs->generate_parameter_specification) {
	// If iteration variable is found then remove it from the list
	*prev_rest_pointer = dl->rest;
	break;
      }
    // Next, add a corresponding parameter to the constructor
    constructor_pars += separator + qid(for_gs->generate_parameter_specification->subtype, rstack, TYPE) + " " + 
      qid(for_gs->generate_parameter_specification, rstack, id_type()) + "_AP_PAR";
    separator = ",";
    // Finally, add the iteration variable as an internal object.
    insert_internal_object_declaration(get_last_rest_address(&extended_interface_declarations(gs)), 
				       gs, gs->pos, qid(for_gs->generate_parameter_specification, rstack, id_type()), 
				       qid(for_gs->generate_parameter_specification->subtype, rstack, TYPE), 
				       "=" + qid(for_gs->generate_parameter_specification, rstack, id_type()) + "_AP_PAR", 
				       DECLARE_LOCALLY);
  }


  // ******************************************************************
  // Constructor
  // ******************************************************************
  str += "/* Implementation of generate class " + get_long_name(gs) + " methods */\n" +
    qid(gs, rstack, id_type()) + "::\n" + 
    qid(gs, rstack, id_type()) + "(" + constructor_pars + ",name_stack &iname,int level) {\n";
 
  // The current C++ source code is not associated with any real
  // VHDL source line
  last_pos_info = emit_posinfo(NO_SOURCE_LINE, str, last_pos_info, l);

  str += spaces(l + 4) + "iname.push(\"\");\n";

  // Emit code to initialize some interal process members
  if (extended_interface_declarations(gs)!= NULL)
    emit_decls_init(extended_interface_declarations(gs), str, rstack, 4);

  // Emit code to initialize remaining declarations
  if (extended_declarations(gs)!= NULL)
    emit_decls_init(extended_declarations(gs), str, rstack, 4);

  if (gs->concurrent_statement_part != NULL)
    emit_concurrent_statement_constructors(gs->concurrent_statement_part, str, rstack, gs, 4);

  str += spaces(l + 4) + "iname.pop();\n";

  str += "}\n";

  rstack.pop();
}


void
m_emit_impl (pIIR_ConcurrentStatement cs, string &str, RegionStack &rstack, int l)
{
  str += string("/* ") + string(cs->kind_name()) + string(" */\n");
}



