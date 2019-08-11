#if HAVE_ALLOCA_H
#include <alloca.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <math.h>
#include <limits.h>

#include "v2cc-util.h"


// ******************************************************************************************
// Some global variables
// ******************************************************************************************

// used to generate error messages
extern vaul_error_printer codegen_error;
int dbg=0;

// Counter to produce unique names for internal variables
int internal_counter = 0;
string internal_prefix_base = "itn";
string internal_prefix_start = "???";

// Prefix used to build a default name for a process
const string process_default_postfix = "pn";

// Prefix used to build a default name for loop statement
const string loop_default_postfix = "ln";

// Integer IIR_Range instance
pIIR_ExplicitRange iir_integer_range = NULL;

// Stores which type of checks shall be performed at runtime
CodeGeneratorCheckFlags do_runtime_checks = CG_CHECK_ALL;

// Holds list of unique pointers to external declarations which are
// used within the current design(s). The bool value stores whether an
// corresponding declaration has been already emitted.
decl_flag_list external_decls_list;

// Points to the last PosInfo instance printed to the C++ code
pIIR_PosInfo_TextFile last_pos_info = NULL;


v2cc_codegen_options::v2cc_codegen_options ()
{
  // Global variable to control register code generation. Register code
  // is used to collect information about VHDL objects (components,
  // processes, signals, variables, constants, ...) at simulation
  // startup.
  emit_register_code = false;

  // Flag to control whether debugging code/info shall be includes into
  // the generated code
  emit_debug_code = false;

  // Flag to control generation of CDFG (control data flow graph)
  // generation. Actually, no CDFG graph is created directly. Instead a
  // lisp module to generate the CDFG nodes is created from each
  // process.
  emit_cdfg_code = false;

  // If true, then code for procedure "main" is generated. "main" is
  // needed to build the simulator executable. It initializes
  // elaboration of the top level component.
  emit_main_cc_code = false;

  verbose = false;
  parser_flags = 0;
};

v2cc_codegen_options codegen_options;

// used to generate error messages
vaul_error_printer codegen_error;



// ******************************************************************************************


// Calculate power for integer parameters.
lint
calculate_pow(lint a, lint b)
{
  if (b < 0) return 0; 
  if (b == 0) return 1;
  lint value = a;
  while (--b) {
    value *= a;
    // In case of an overflow or underflow bail out
    if (value > INTEGER_MAX) 
      return lint(INTEGER_MAX) + 1;
    if (value < INTEGER_MIN) 
      return lint(INTEGER_MIN) - 1;
  }
  return value;
}


// Calculate power for double/integer parameters.
double
calculate_pow(double a, lint b)
{
  return pow(a,double(int(b)));
}


const char *
ppp(pIIR_Root n)
{
  return n->kind_name();
}



/* Print scalar value into a string */
string
to_string(pIIR_ScalarType type, const StaticDataType &value)
{
  string str;
  StaticDataType v = value;

  pIIR_ScalarType base_type = 
    pIIR_ScalarType (get_base_type (type));
  if (base_type->is (IR_ENUMERATION_TYPE))
    {
      pIIR_EnumerationLiteralList enum_list = 
	pIIR_EnumerationType (base_type)->enumeration_literals;
      str = pos_to_literal (enum_list, v.long_value ())->declarator->text.to_chars ();
    }
  else if (base_type->is (IR_INTEGER_TYPE))
    {
      str = to_string (v.long_value ());
    }
  else if (base_type->is (IR_FLOATING_TYPE))
    {
      str = to_string (v.double_value ());
    }

  return str;
}


// Converts a string item into an IR_TextLiteral
pIIR_TextLiteral
to_TextLiteral(const string &str)
{
  return new IIR_TextLiteral(NULL, IR_String(str.c_str()));
}


/* Get line number associated with a node */
int
get_line_number(pIIR_Root n)
{
  if (n->pos->is(IR_POS_INFO_TEXT_FILE))
    return pIIR_PosInfo_TextFile(n->pos)->line_number;
  else if (n->pos->is(IR_POS_INFO_SHEET))
    return pIIR_PosInfo_Sheet(n->pos)->x_coordinate;
  else
    assert(false);
}


/* Get library and unit name */
vector<string>
get_library_and_unit_name(pIIR_Declaration decl)
{
  vector<string> result;

  // Get long name of declaration. The long name is of the form
  // ":lib:unit:..."
  string lname = get_long_name(decl);
  // Extract library and unit name from path
  string str;
  unsigned int i = 1;
  while (i < lname.length() && lname[i] != ':') str += tolower(lname[i++]);
  result.push_back(str);
  i++; 
  str = "";
  while (i < lname.length() && lname[i] != ':') str += tolower(lname[i++]);
  result.push_back(str);

  return result;
}


/* Get source file name associated with a node */
const char *
get_source_file_name(pIIR_Root n)
{
  if (n->pos->is(IR_POS_INFO_TEXT_FILE))
    return pIIR_PosInfo_TextFile(n->pos)->file_name;
  else if (n->pos->is(IR_POS_INFO_SHEET))
    return pIIR_PosInfo_Sheet(n->pos)->sheet_name;
  else
    assert(false);
}


/* Select association elements from an association list which
 * corresponds with given formal */
list<pIIR_AssociationElement>
find_matching_actuals(pIIR_AssociationList assocs, pIIR_InterfaceDeclaration formal)
{
  list<pIIR_AssociationElement> result;
  for (pIIR_AssociationList al = assocs; al; al = al->rest)
    {
      pIIR_AssociationElement a = al->first;
      if (a->formal_declaration == formal) // add association element to list if it matches formal
	result.push_back(a);
    }

  return result;
}


/* Get id_type from region stack. Note that dependent on the region
 * stack some objects are either accessed directly or accessed via
 * architecture pointers */
id_type
get_default_id_type(RegionStack &rstack)
{
  pIIR_DeclarativeRegion dreg = rstack.back();
  id_type id;
  if (dreg->is(IR_CONCURRENT_STATEMENT) ||
      dreg->is(IR_SUBPROGRAM_DECLARATION))
    id = id_type(READER, DEREF);
  else
    id = id_type(READER, DEREF | ARCHREF);

  return id;
}


/* Creates an array info object for an array subtype */
string
create_array_info_obj(pIIR_Type base, pIIR_Range range, 
		      RegionStack &rstack, const bool static_object)
{
  string result = "new array_info(";
  
  pIIR_TypeDeclaration type_declaration = base->declaration;
  string array_base_str = get_type_info_obj(base, rstack, static_object);
  result += array_base_str + "->element_type," + array_base_str + "->index_type,";

  // Extract bounds and range direction from expression
  vector<RangeDescriptor> range_desc = get_discrete_range (range, rstack, IR_NOT_STATIC);
  StaticRangeDescriptor<string,string> static_range = 
    range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));
  result += static_range.left + "," + static_range.dir + "," + static_range.right;

  // If the array_info instance will be static, then set the last
  // argument to -1. Otherwise, append 0. Static array_info instances
  // are not removed even when no array instance is using it!
  if (static_object)
    result += ",-1)";
  else
    result += ",0)";

  return result;
}





/* Emit code to create an new object of a specific type */
string
create_default_instance(pIIR_Type type, RegionStack &rstack)
{
  string str;
  pIIR_Type im_base_type = get_immediate_base_type(type);
  pIIR_TypeDeclaration type_decl = get_declaration(type);
  
  // First, check whether the type is an array type
  if (im_base_type->is(IR_ARRAY_TYPE)) {
    // Bail out if the type is not constrained!
    assert(is_constrained_array_type(type));

    str += qid(type_decl, rstack, TYPE) + "(";
    str += get_type_info_obj(type, rstack, false);
    str += "," + create_default_instance(pIIR_ArrayType(im_base_type)->element_type, rstack) + ")";
    
  } else {
    // Emit simple constructor for the type
    str += qid(type_decl, rstack, TYPE) + "()";
  }

  return str;
}



/* Emit code to create an new object of a specific type using CDFG
   style */
string
cdfg_create_default_instance(pIIR_Type type, RegionStack &rstack)
{
  string str;
  pIIR_Type im_base_type = get_immediate_base_type(type);
  pIIR_TypeDeclaration type_decl = get_declaration(type);
  
  // Emit simple constructor for the type
  str += "(create-object " + get_escaped_string(get_long_name(type_decl)) + ")";

  return str;
}



/* Returns an unqualified identifier name */
string
nid(pIIR_Declaration d, id_type obj_access)
{
  string id;
  char *decl;

  if (obj_access.object() & BARE) {  }
  else if (d->is(IR_PROCEDURE_DECLARATION)) id="X";
  else if (d->is(IR_FUNCTION_DECLARATION)) id="Y";
  else if (d->is(IR_ARCHITECTURE_DECLARATION)) id="A";
  else if (d->is(IR_ENTITY_DECLARATION))       id="E";
  else if (d->is(IR_OBJECT_DECLARATION) && pIIR_ObjectDeclaration(d)->alias_base != NULL) id="H";
  else if (d->is(IR_SIGNAL_DECLARATION) || d->is(IR_SIGNAL_INTERFACE_DECLARATION))
    {
      if (obj_access.object() & DRIVER)
	id = "D";
      else if (obj_access.object() & READER)
	id = "R";
      else if (obj_access.object() & SIGNAL)
	id = "S";
      else if (obj_access.object() & DEFAULT)
	id = "S";
    }
  else if (d->is(IR_TYPE_DECLARATION)) 
    {
      if (obj_access.object() & INFO)
	id = "I";
      else if (obj_access.object() & DEFAULT)
	id = "T";
      else if (obj_access.object() & TYPE)
	id = "T";
    }
  else if (d->is(IR_VARIABLE_DECLARATION)) id="V";
  else if (d->is(IR_VARIABLE_INTERFACE_DECLARATION)) id="V";
  else if (d->is(IR_FILE_DECLARATION)) id="V";
  else if (d->is(IR_FILE_INTERFACE_DECLARATION)) id="V";
  else if (d->is(IR_PACKAGE_DECLARATION)) id="Q";
  else if (d->is(IR_PACKAGE_BODY_DECLARATION)) id="W";
  else if (d->is(IR_CONSTANT_DECLARATION)) id="C";
  else if (d->is(IR_CONSTANT_INTERFACE_DECLARATION)) id="C";
  else if (d->is(IR_LIBRARY_DECLARATION)) id="L";
  else if (d->is(IR_CONCURRENT_STATEMENT)) id="P";
  else if (d->is(IR_COMPONENT_DECLARATION)) 
    id="!";
  else if (d->is(IR_LOOP_DECLARATIVE_REGION)) id="L";
  else if (d->is(IR_ELEMENT_DECLARATION)) id="M";
  else if (d->is(IR_ENUMERATION_LITERAL))
    return "enumeration(" + to_string(pIIR_EnumerationLiteral(d)->enum_pos) + ")";
  else { 
    cout << endl << "Can't find: " <<  d->kind_name() << endl ;
    id="?";
  }

  if (d->is(IR_FUNCTION_DECLARATION)) {
    pIIR_FunctionDeclaration fd = pIIR_FunctionDeclaration(d);
    // Check for operator function
    switch (get_operator_type(fd)) {
    case USER_OP:
    case BASIC_OP: 
      {
	// C++ names of user defined operator functions
	VHDLOperators &operators = *VHDLOperators::get_instance ();
	bool unary = fd->interface_declarations->rest == NULL; // Binary or unary operator?
	string op_name = unary? operators.get_unary_user_operator_name (string(fd->declarator->text.to_chars())) :
	  operators.get_binary_user_operator_name (string(fd->declarator->text.to_chars()));
	decl = (char*)op_name.c_str();
	break;
      }
    default:
      decl = d->declarator->text.to_chars();
      break;
    }

  } else if (obj_access.object() & LIBRARY) {
    id = "L";
    decl = pIIR_LibraryUnit(d)->library_name->text.to_chars();

  } else
    decl = d->declarator->text.to_chars();

  // Convert all uppercase letters to lowercase
  string str;
  if (!(obj_access.object() & BARE)) 
    str += id + to_string((int)strlen(decl));

  // Convert decl string to lower case and add result to str 
  str += convert_string(decl, tolower);

  // Append some kind of serial number in case of a subprogram. This
  // serial number is used to separate subprograms with the same
  // parameter profile but different return type (this is ok for VHDL
  // but illegal in C++).
  if (d->is(IR_SUBPROGRAM_DECLARATION)) {
    pIIR_SubprogramDeclaration sdecl = pIIR_SubprogramDeclaration(d);
    str += "_i" + to_string(sdecl->prototype != NULL? sdecl->prototype->seqno : sdecl->seqno);
  }

  return str;
}




// emit a plain identifier 
void
emit_noqual_id (pIIR_Declaration d, string &str, RegionStack &rstack, id_type obj_access)
{
  if (d->declarator) 
    {
      if (d->is(IR_ENUMERATION_LITERAL) && codegen_options.get_verbose ()) 
	{
	  emit_noqual_id (pIIR_EnumerationLiteral(d)->subtype->declaration, str, rstack);
	  str += "_";
	  if (d->declarator->is(IR_CHARACTER_LITERAL)) 
	    {
	      IR_Character ch = d->declarator->text[1];
	      if (isalnum(ch))
		str += ch;
	      else
		str += unsigned(ch);
	    }
	  else
	    str += nid(d, obj_access);
	}
      else
	{
	  str += nid(d, obj_access);

	  if (d->is(IR_SUBPROGRAM_DECLARATION) && codegen_options.get_verbose ()) 
	    {
	      for(pIIR_InterfaceList il =
		    pIIR_SubprogramDeclaration(d)->interface_declarations;
		  il; il = il->rest)
		{
		  str += "__";
		  str += qid (il->first->subtype->declaration, rstack, id_type());
		}
	      if(d->is(IR_FUNCTION_DECLARATION))
		{
		  str += "__";
		  str += qid (pIIR_FunctionDeclaration(d)->return_type->declaration, rstack, id_type());
		}
	    }
	}
    }
  else
    str += "<anonymous>";
}



/* Emit array literal value. Note that this will create a global
 * variable which takes the literal values. */
void
emit_folded_array_literal(StaticDataType &data, string &str, RegionStack &rstack, pIIR_Type subtype)
{
  // First, get range of array expression. The range (bounds and
  // directions) is stored into an vector of strings where the first
  // strings is the left bound, the second string denotes the range
  // direction and the third string is the right bound.
  vector<RangeDescriptor> range_desc = get_discrete_range (subtype, rstack, IR_NOT_STATIC);
  StaticRangeDescriptor<string, string> range = 
    range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));

  // Determine length of literal array
  int length = data.array_literal_value().size();

  // Determine range of resulting array. If the array subtype is
  // constrained then take bounds and direction from
  // subtype. Otherwise, take left bound of unconstrained array and
  // determine right bound based on direction and literal length.
  string range_str;
  if (is_constrained_array_type(subtype))
    // Concat all strings values separated by ","
    range_str = range.left + "," + range.dir + "," + range.right;
  else
    range_str = range.left + "," + range.dir + "," + 
      range.left + (range.dir == "to"?"+":"-") + to_string(length - 1);

  // Get type declaration of the array literal 
  pIIR_TypeDeclaration type = get_declaration(subtype);

  pIIR_EnumerationType etype = 
    pIIR_EnumerationType(get_base_type(pIIR_ArrayType(get_base_type(subtype))->element_type));
  pIIR_EnumerationLiteralList enum_items = etype->enumeration_literals; // Get list of enumeration items

  // Create name for an internal array constant to store the literal
  // values. This variable will be used to initialize the array instance
  string internal_var_name = get_new_internal_var_prefix() + "_lit";

  // Create call to array constructor. The second constructor argument
  // is a pointer to an array which stores the literal values. The
  // first argument is an array_info instance.
  str += "array_alias<" + qid(type, rstack, TYPE) + " >(new array_info(" + 
    get_type_info_obj(get_base_type(subtype), rstack, false) + "->element_type," + 
    get_type_info_obj(get_base_type(subtype), rstack, false) + "->index_type,"  + 
    range_str + ",0)," + internal_var_name + ")";

  // Now, convert each element of the literal into an corresponding
  // number and declare an internal constant which takes the literal
  // values. Note, this variable is declared globally.
  vector<int> &lit_values  = data.array_literal_value();
  string init_str = "[]={" + concat_to_string(lit_values.begin(), lit_values.end(), ",") + "}";
  
  // Declare the internal variable as a global constant
  pIIR_DeclarativeRegion root_region = RootDeclarativeRegion(rstack);
  //if (lookup_internal_object_declaration(root_region, internal_var_name) == NULL)
  insert_internal_object_declaration(NULL, root_region, NULL, internal_var_name, 
				     "enumeration", init_str, DECLARE_GLOBALLY | DECLARE_AND_INIT);
}


/* Emit folded value. Note that in case of an array literal value an
 * global internal variable will be created which stores the array
 * elements. */
void
emit_folded_value(StaticDataType &data, string &str, RegionStack &rstack, pIIR_Type subtype)
{
  pIIR_Type base_type = get_base_type(subtype);

  if (base_type->is(IR_ENUMERATION_TYPE))
    str += "enumeration(" + to_string(data.long_value()) + ")";
  else if (base_type->is(IR_FLOATING_TYPE))
    str += to_string(data.double_value());
  else if (base_type->is(IR_PHYSICAL_TYPE))
    str += to_string(data.long_value()) + "LL";
  else if (base_type->is(IR_ARRAY_TYPE)) 
    emit_folded_array_literal(data, str, rstack, subtype);
  else {
    lint val = data.long_value();
    str += to_string(val);
    // If value does not fit into an integer then add "LL" to define
    // an long long int constant (usually 64 bits).
    if (val > INTEGER_MAX || val < INTEGER_MIN)
      str += "LL";
  }
}





/* Emit folded value in CDFG style. Note that in case of an array
 * literal value an global internal variable will be created which
 * stores the array elements. */
void
cdfg_emit_folded_value(StaticDataType &data, string &str, RegionStack &rstack, pIIR_Type subtype)
{
  pIIR_Type base_type = get_base_type(subtype);

  if (base_type->is(IR_ENUMERATION_TYPE))
    str += to_string(data.long_value());
  else if (base_type->is(IR_FLOATING_TYPE)) {
    // Replace 'e' ein the floating point number by 'l' in order to
    // match the definition of doubles in lisp.
    string result = to_string(data.double_value());
    for (unsigned int i = 0; i < result.length(); i++)
      if (result[i] == 'e' ||
	  result[i] == 'E')
	result[i] = 'l';
    str += result;

  } else if (base_type->is(IR_PHYSICAL_TYPE))
    str += to_string(data.long_value());
  else if (base_type->is(IR_ARRAY_TYPE)) {
    // Now, convert each element of the literal into an corresponding
    // number 
    vector<int> &lit_values  = data.array_literal_value();
    str += "(list array " + concat_to_string(lit_values.begin(), lit_values.end(), " ") + ")";
  
  } else {
    lint val = data.long_value();
    str += to_string(val);
  } 
} 





/* Test whether a type is a scalar */
bool
is_scalar_type(pIIR_Type t)
{
  return (t->is(IR_SCALAR_TYPE) || t->is(IR_SCALAR_SUBTYPE));
}


/* Test whether an type is an constrained array type */
bool
is_constrained_array_type(pIIR_Type t)
{
  if (t->is(VAUL_SUBARRAY_TYPE))
    return is_constrained_array_type(pVAUL_SubarrayType(t)->complete_type);
    
  else if (t->is(IR_ARRAY_SUBTYPE))
    if (pIIR_ArraySubtype(t)->constraint != NULL)
      return true;
    else
      return is_constrained_array_type(pIIR_ArraySubtype(t)->immediate_base);
    
  else if (t->is(IR_ARRAY_TYPE)) 
    return false;
    
  else
    return false;
}


/* Test whether a type denotes an array (sub)type */
bool 
is_array_type(pIIR_Type t)
{
  t = get_base_type(t);

  return t->is(IR_ARRAY_TYPE) || t->is(IR_ARRAY_SUBTYPE);
}


/* Calculate length from left bound, right bound and direction */
lint
range_to_length(lint left, IR_Direction dir, lint right)
{
  if (left <= right && 
      dir == IR_DIRECTION_UP)
    return  right - left + 1;
  else if (left >= right &&
	   dir == IR_DIRECTION_DOWN)
    return left - right + 1;
  else
    return 0;
}

bool
is_implicit_array_subtype(pIIR_Type t)
{
  if (!t->is(VAUL_SUBARRAY_TYPE) &&
      !t->is(IR_ARRAY_SUBTYPE) &&
      !t->is(IR_ARRAY_TYPE))
    return false;

  return  t->declaration == NULL;
}


// Not sure whether this works for all cases!!!
bool
is_implicit_subtype(pIIR_Type t)
{
  if (t->declaration != NULL)
    return false;

  if (t->is(IR_SUBTYPE)) {
    if (t->is(IR_ARRAY_SUBTYPE)) {
      pIIR_ArraySubtype subtype = pIIR_ArraySubtype(t);
      if (subtype->resolution_function != NULL ||
	  subtype->constraint != NULL)
	return true;
      else
	return is_implicit_subtype(subtype->immediate_base);

    } else if (t->is(IR_RECORD_SUBTYPE)) {
      pIIR_RecordSubtype subtype = pIIR_RecordSubtype(t);
      if (subtype->resolution_function != NULL)
	return true;
      else
	return is_implicit_subtype(subtype->immediate_base);
      
    } else if (t->is(IR_SCALAR_SUBTYPE)) {
      pIIR_ScalarSubtype subtype = pIIR_ScalarSubtype(t);
      if (subtype->resolution_function != NULL ||
	  subtype->range != NULL)
	return true;
      else
	return is_implicit_subtype(subtype->immediate_base);
      
    } else {
      pIIR_Subtype subtype = pIIR_Subtype(t);
      if (subtype->resolution_function != NULL)
	return true;
      else
	return is_implicit_subtype(subtype->immediate_base);

    }
  }

  return true;
//   if (t->declaration == NULL)
//     return true;

//   pIIR_Type type = t->declaration->type;
//   return get_basic_type(type) != t;
}


/* Convert character c into a decimal digit. Returns MAX_INTEGER if character is
   not within 0 to 9 or a to f! */
inline int
convert_digit(char c)
{
  c = tolower(c);
  if (c >= '0' && c <= '9')
    return c - '0';
  else if (c >= 'a' && c <= 'f')
    return 10 + c - 'a';
  else
    return INTEGER_MAX;
}


/* Convertes string to unsigned int. Stops conversion as soon as a
   character not included in base is found. However any character '_'
   is ignored. Returns a pointer to the first invalid character or to
   the end of the string. The function returns NULL if an overflow
   occured. */
const char *
string_to_ulint(lint &result, int base, const char *p)
{
  result = 0;
  while (*p != '\0') {
    if (*p == '_') { p++; continue; }
    // Convert digit and check whether digit is a valid digit with
    // respect to base
    int value = convert_digit(*p);
    if (value >= base) return p;
    lint result2 = (result * base) + value;
    // Check whether an overflow occured. Set ok flag to false in case
    // of an overflow.
    if (result2 < result) return NULL;
    result = result2;
    p++;
  }

  return p;
}


/* Convertes string to unsigned int. Stops conversion as soon as a
   character not included in 0 to 9 is found. However any character
   '_' is ignored. Returns a pointer to the first invalid character or
   to the end of the string. The function returns NULL if an overflow
   occured. */
const char *
string_to_ulint(lint &result, const char *p)
{
  result = 0;
  while (*p != '\0') {
    if (*p == '_') { p++; continue; }
    // Convert digit and check whether digit is a valid digit with
    // respect to base 10
    if (*p < '0' || *p > '9') return p;
    // equal to "result2 = result * 10 + ..."
    lint result2 = (result << 3) + (result << 1) + (*p - '0');
    // Check whether an overflow occured. Set ok flag to false in case
    // of an overflow.
    if (result2 < result) return NULL;
    result = result2;
    p++;
  }

  return p;
}


/* Convert an string value into a long integer. The number is returned
   as second element of the pair. The function returns false in first
   pair lement in case of an overflow. */
pair<bool, StaticLint>
string_to_lint(const string &str)
{
  lint result = 0;
  const char *p = str.c_str();
  bool negative = false, ok = true;

  // Read sign if present
  if (*p == '-') { p++; negative = true; }

  // Read first integer number
  p = string_to_ulint(result, p);
  if (p == NULL) return pair<bool, StaticLint> (false, StaticLint ());

  int base = 10;
  // Check whether a base has been specified
  if (*p == '#') {
    base = result;
    result = 0;
    if (base > 16) return pair<bool, StaticLint> (false, StaticLint ());
    p = string_to_ulint (result, base, ++p);
    if (p == NULL) return pair<bool, StaticLint> (false, StaticLint ());
    if (*p != '#')
      return pair<bool, StaticLint> (false, StaticLint ());
    p++;
  }

  // Skip underscores
  while (*p == '_') p++;

  // Check for exponent
  if (*p == 'e' || *p == 'E') {
    bool negative_exp = false;
    if (*(++p) == '-') { negative_exp = true; p++; }
    if (*p == '\0') return pair<bool, StaticLint> (false, StaticLint ());
    lint exp;
    p = string_to_ulint(exp, ++p);
    if (p == NULL) return pair<bool, StaticLint> (false, StaticLint ());
    // Calculate result
    if (negative_exp) 
      while ((exp--) && (result != 0))
	result /= base;
    else 
      while ((exp--) && (result != 0)) {
	lint result2 = result * base;
	// Check for overflow
	if (result2 < result) return pair<bool, StaticLint> (false, StaticLint ());
	result = result2;
      }
  }

  if (negative)
    result = -result;

  return pair<bool, StaticLint> (*p == '\0', StaticLint (result, str));
}


/* Convert an string value into a double. The number is returned in
   second element of the pair. The function returns false in first
   pair element in case of an overflow. */
pair<bool, StaticDouble>
string_to_double(const string &str)
{
  double result = 0.0;
  int number_of_digits = -1;
  char *cp = (char*)alloca(sizeof(char)*(str.length()+1));
  const char *p = str.c_str(), *copy = cp;

  // First, remove underscores and check whether a base is specified
  int i = 0;
  bool base_specified = false;
  while (p[i] != '\0') {
    if (p[i] == '#') base_specified = true;
    if (p[i] != '_') *(cp++) = p[i];
    i++;
  }
  *cp = '\0';

  if (base_specified) {
    // A base has been specified. First, determine base.
    bool negative = false;
    if (*copy == '-') { negative = true; copy++; }
    if (*copy == '\0') return pair<bool, StaticDouble> (false, StaticDouble ());
    lint base = 0;
    copy = string_to_ulint(base, copy);
    if (*(copy++) != '#' || base > 16) return pair<bool, StaticDouble> (false, StaticDouble ());
    // Get integer part
    lint integer = 0;
    copy = string_to_ulint(integer, base, copy);
    // Check for error and decimal point
    if (copy == NULL || *copy != '.') return pair<bool, StaticDouble> (false, StaticDouble ());
    copy++;
    // Get fraction 
    lint fraction = 0;
    const char *copy_new = string_to_ulint(fraction, base, copy); 
    if (copy_new == NULL || *copy_new != '#') return pair<bool, StaticDouble> (false, StaticDouble ());
    int fraction_digits = copy_new - copy;
    copy_new++;
    copy = copy_new;
    // Get exponent
    lint exponent = 0;
    if (*copy == 'e' || *copy == 'E') {
      bool negative_exp = false;
      if (*(++copy) == '-') { negative_exp = true; copy++; }
      if (*copy == '\0') return pair<bool, StaticDouble> (false, StaticDouble ());
      copy = string_to_ulint (exponent, ++copy);
      if (copy == NULL) return pair<bool, StaticDouble> (false, StaticDouble ());
      // Calculate result
      if (negative_exp) 
	exponent = -exponent;
    }
    // Finally, calculate result
    double fraction_value = (double)fraction;
    while (fraction_digits--) fraction_value /= (double)base;
    result = ((double)integer + fraction_value) * pow((double)base, (double)exponent);
    if (negative) result = -result;

    return pair<bool, StaticDouble> (*copy == '\0', StaticDouble (result));

  } else {
    // Base is 10. Hence, use library function strtod.
    char *endp;
    result = strtod(copy, &endp);

    string adopted_str = copy;
    adopted_str.erase (adopted_str.begin () + (endp - copy), adopted_str.end ());

    return pair<bool, StaticDouble> ((*endp == '\0') && 
				     (result > -HUGE_VAL) && 
				     (result < HUGE_VAL),
				     StaticDouble (result, adopted_str));
  }
}


/* Return a string of L spaces, but at most 30.  */
string 
spaces(int l)
{
  if(l > 30)
    l = 30;
  if(l < 0)
    l = 0;
  return string("                              " + (30-l));
}


// Create a list of declarative region pointers beginning from the
// end_region up to the root region
list<pIIR_DeclarativeRegion> 
create_region_list(pIIR_DeclarativeRegion end_region)
{
  list<pIIR_DeclarativeRegion> RegionList;
  pIIR_DeclarativeRegion reg = end_region;
  while (reg != NULL) {
    RegionList.push_back(reg);
    if (reg->is (IR_ARCHITECTURE_DECLARATION))
      reg = pIIR_ArchitectureDeclaration (reg)->entity;
    else
      reg = reg->declarative_region;
  }
  
  return RegionList;
}


/* Emit a declaration name */
void
emit_id (pIIR_Declaration d, string &str, RegionStack &rstack)
{
  emit_noqual_id (d, str, rstack);
}


/* Emit a type name */
void
emit_id (pIIR_Type t, string &str, RegionStack &rstack)
{
  if (t->declaration)
    emit_id (t->declaration, str, rstack);
  else
    str += "<anonymous" + string(t->kind_name()) + ">";
}


/* Emit an UglyIdentifier as a beautiful_identifier.  */
void 
emit_id(pIIR_TextLiteral idnode, string &str, RegionStack &rstack)
{
  char *id = idnode->text.to_chars();
  if (*id == '\\' || *id == '\'')
    str += id;
  else 
    {
      bool break_on_caps = false;
      while (*id) 
	{
	  if (isupper(*id) && break_on_caps)
	    str += '_';
	  break_on_caps = islower(*id);
	  str += tolower(*id++);
	}
    }
}


// return long name of declaration (similar to the path_name defined
// in VHDL). E.g., returns ":std:standard:bit" when called for
// standard type bit.
string
get_long_name (pIIR_Declaration d)
{
  string id;

  // Convert declarator string to lower and add result to id 
  id += convert_string(d->declarator->text.to_chars(), tolower);

  if (d->is(IR_ARCHITECTURE_DECLARATION))
    id = get_long_name (pIIR_ArchitectureDeclaration(d)->entity) + "(" + id + ")";
  else if (d->is (IR_LIBRARY_UNIT))
    id = string(":") + pIIR_LibraryUnit(d)->library_name->text.to_chars() + ":" + id;
  else if (d->declarative_region)
    id = get_long_name (d->declarative_region) + ":" + id;

  return id;
}



// prepend special characters like " with \ and return string.
string
get_escaped_string (const string str, const string escape_chars)
{
  string id, result;

  // Convert declarator string to lower and add result to id 
  for (unsigned int i = 0; i < str.size(); i++) {
    for (unsigned int j = 0; j < escape_chars.length(); j++)
      if (escape_chars[j] == str[i]) {
	result += string("\\");
	break;
      }
    result += str[i];
  }

  return result;
}



/* Return the prefix for the name of a new internal variable */
string
get_new_internal_var_prefix()
{
  return internal_prefix_start + to_string(internal_counter++);
}


/* Return a number which is unique within the current file. */
int
get_unique_int_id()
{
  return internal_counter++;
}


/* Set prefix for internal variables */
void
set_internal_prefix_start(pIIR_DeclarativeRegion r, RegionStack &rstack)
{
  internal_prefix_start = qid(r, rstack, id_type()) + "_" + internal_prefix_base;
}


/* Returns a pointer to the current active context info instance */
ContextInfo *
ActiveContext(RegionStack &rstack)
{
  pIIR_DeclarativeRegion r = ActiveDeclarativeRegion(rstack);

  return r != NULL? &context(r) : NULL;
}

pIIR_DeclarativeRegion
ActiveDeclarativeRegion(RegionStack &rstack)
{
  return rstack.back();
}


/* Returns the next process, subprogram, concurrent assignement,
   package declaration, package body declaration, architecture or
   entity declarative region */
ContextInfo *
BaseContext(RegionStack &rstack)
{
  pIIR_DeclarativeRegion r = BaseDeclarativeRegion(rstack);

  return r != NULL? &context(r) : NULL;
}

pIIR_DeclarativeRegion
BaseDeclarativeRegion(RegionStack &rstack)
{
  if (rstack.size() == 0) return NULL;

  RegionStack::reverse_iterator iter = rstack.rbegin();
  while (true) {
    // Search in reverse order until either a concurrent statement
    // region is found or the very first item on the list has been
    // visited
    if ((*iter)->is(IR_CONCURRENT_STATEMENT) ||
	(*iter)->is(IR_PACKAGE_DECLARATION) ||
	(*iter)->is(IR_PACKAGE_BODY_DECLARATION) ||
	(*iter)->is(IR_SUBPROGRAM_DECLARATION) ||
	(*iter)->is(IR_ARCHITECTURE_DECLARATION) ||
	(*iter)->is(IR_ENTITY_DECLARATION))
      return *iter;
    if (iter == rstack.rend()) break;
    iter--;
  }
  return NULL;
}


/* Returns the top level region which is either an architecture
   region, an entity region, a package body region or package declaration
   region */
ContextInfo *
TopContext(RegionStack &rstack) 
{
  pIIR_DeclarativeRegion r = TopDeclarativeRegion(rstack);

  return r != NULL? &context(r) : NULL;
}

pIIR_DeclarativeRegion
TopDeclarativeRegion(RegionStack &rstack)
{
  if (rstack.size() == 0) return NULL;

  pIIR_DeclarativeRegion found = NULL;

  for (RegionStack::iterator iter = rstack.begin(); iter != rstack.end(); iter++)
    if ((*iter)->is(IR_PACKAGE_BODY_DECLARATION) ||
	(*iter)->is(IR_PACKAGE_DECLARATION) ||
	(*iter)->is(IR_ARCHITECTURE_DECLARATION) ||
	(*iter)->is(IR_ENTITY_DECLARATION))
      found = *iter;
  
  return found;
}


pIIR_DeclarativeRegion
TopDeclarativeRegion(pIIR_DeclarativeRegion region)
{
  if (region->declarative_region != NULL)
    return TopDeclarativeRegion(region->declarative_region);
  else
    return region;
}

/* Returns the upper most declarative region which has been added to
   store all the global code items */
pIIR_DeclarativeRegion
RootDeclarativeRegion(RegionStack &rstack)
{
  return (*rstack.begin());
}

ContextInfo *
RootContext(RegionStack &rstack)
{
  pIIR_DeclarativeRegion r = RootDeclarativeRegion(rstack);
  
  return r != NULL? &context(r) : NULL;
}


pIIR_DeclarativeRegion
get_combined_static_region(list<pIIR_DeclarativeRegion> &rlist, RegionStack &rstack)
{
  pIIR_DeclarativeRegion region = ActiveDeclarativeRegion (rstack);

  do 
    {
      for (list<pIIR_DeclarativeRegion>::iterator i = rlist.begin(); i != rlist.end(); i++) {
	if ((*i) == NULL)
	  return ActiveDeclarativeRegion (rstack);
	if ((*i) == region)
	  return region;
      }
      
      region = get_parent_declarative_region (region, rstack);
    } while (region != NULL);
  
  return RootDeclarativeRegion(rstack);
}


pIIR_DeclarativeRegion
get_combined_static_region(pIIR_DeclarativeRegion r1, pIIR_DeclarativeRegion r2, RegionStack &rstack)
{
  RegionStack::iterator iter = rstack.end();

  if (r1 == NULL || r2 == NULL)
    return NULL;

  do {
    iter--;
    if ((*iter) == r1 || (*iter == r2))
	return (*iter);
  } while (iter != rstack.begin());
  
  return RootDeclarativeRegion(rstack);
}


/* for debugging */
int
plot_rstack(RegionStack &rstack)
{
  for (RegionStack::iterator iter = rstack.begin(); iter != rstack.end(); iter++) {
    cout << hex << "0x" << (long)*iter << dec <<" = ";
    if ((*iter)->is(IR_PACKAGE_BODY_DECLARATION))
      cout << "IR_PACKAGE_BODY_DECLARATION" << endl;
    else if ((*iter)->is(IR_PACKAGE_DECLARATION))
      cout << "IR_PACKAGE_DECLARATION" << endl;
    else if  ((*iter)->is(IR_ARCHITECTURE_DECLARATION))
      cout << "IR_ARCHITECTURE_DECLARATION" << endl;
    else if ((*iter)->is(IR_ENTITY_DECLARATION))
      cout << "IR_ENTITY_DECLARATION" << endl;
    else if ((*iter)->is(IR_CONCURRENT_STATEMENT))
      cout << "IR_CONCURRENT_STATEMENT" << endl;
    else if ((*iter)->is(IR_SUBPROGRAM_DECLARATION))
      cout << "IR_SUBPROGRAM_DECLARATION" << endl;
    else
      cout << "???" << endl;
  }
  return 0;
}


/* for debugging */
void
plot(string &str) { cout << str; }



// Get the type declaration
pIIR_TypeDeclaration
get_declaration(pIIR_Type type)
{
  if ((type->declaration == NULL) &&
      (type->is(IR_SUBTYPE) && (implicit_subtype_declaration(pIIR_Subtype(type)) == NULL))) {
    if (type->is(IR_ARRAY_SUBTYPE)) {
      pIIR_ArraySubtype ast = pIIR_ArraySubtype(type);
      if (ast->immediate_base->declaration != NULL)
	return ast->immediate_base->declaration;
      else if (ast->immediate_base == ast)
	return get_declaration(ast->base);
      else
	return get_declaration(ast->immediate_base);

    } else if (type->is(IR_SCALAR_SUBTYPE)) {
      pIIR_ScalarSubtype sst = pIIR_ScalarSubtype(type);
      return get_declaration(sst->immediate_base);
    }
  }

  return type->declaration != NULL? 
    type->declaration : implicit_subtype_declaration(pIIR_Subtype(type));
}


// Get the immediate_base type
pIIR_Type
get_immediate_base_type(pIIR_Type type)
{
  if (type->declaration == NULL) {
    if (type->is(IR_ARRAY_SUBTYPE))
      type = ((pIIR_ArraySubtype)(type))->immediate_base;
    else if (type->is(IR_SCALAR_SUBTYPE))
      type = ((pIIR_ScalarSubtype)(type))->immediate_base;
  }

  return type;
}


// Get base type or subtype the current type is derived from. I.e.,
// any subtype declarations which only add a resolution function are
// skipped.
pIIR_Type
get_basic_type(pIIR_Type type)
{
  if (type->is(IR_SCALAR_SUBTYPE)) 
    {
      pIIR_ScalarSubtype sst = pIIR_ScalarSubtype(type);
      if (sst->range != NULL)
	return type;
      else
	return get_basic_type(sst->immediate_base);
      
    } 
  else if (type->is(IR_ARRAY_SUBTYPE)) 
    {
      pIIR_ArraySubtype ast = pIIR_ArraySubtype(type);
      if (ast->constraint != NULL)
	return type;
      else 
	return get_basic_type(ast->immediate_base);
    } 
  else if (type->is(IR_RECORD_SUBTYPE)) 
    {
      pIIR_RecordSubtype rst = pIIR_RecordSubtype (type);
      return get_basic_type (rst->immediate_base);
    }
  else
    return type;
}

// Get base type of a type
pIIR_Type
get_base_type(pIIR_Type type)
{
  if (type != type->base)
    return get_base_type(type->base);
  else
    return type;
}


// Convert locally static expression to int value. Returns false if
// the expression is not locally static.
bool
expr_to_int(pIIR_Expression e, int &value, RegionStack &rstack)
{
  // Return false if expression is not locally static
  if (e->static_level != IR_LOCALLY_STATIC)
    return false;

  pIIR_Type base = get_base_type(e->subtype);
  pIIR_AbstractLiteralExpression ae = pIIR_AbstractLiteralExpression(e);
  if (base->is(IR_INTEGER_TYPE)) {
    string val_str;
    if (!emit_expr(e, val_str, rstack, DEFAULT))
      return false;
    value = atoi(val_str.c_str());
  } else if (base->is(IR_ENUMERATION_TYPE)) {
    string literal_str = pIIR_EnumerationLiteral(ae->value)->declarator->text.to_chars();
    value = literal_to_pos(pIIR_EnumerationType(base)->enumeration_literals, literal_str);
  } else
    // Return false if type is not an enumeration type or integer type 
    return false;

  return true;
}


// Get enumeration pos of enumeration item
int 
literal_to_pos(pIIR_EnumerationLiteralList enum_items, const string &literal_str)
{
  for (pIIR_EnumerationLiteralList lit_list = enum_items; lit_list; lit_list = lit_list->rest) {
    if (lit_list->first->declarator->is(IR_IDENTIFIER)) { 
      // Identifier enumeration item
      if (!strcmp(literal_str.c_str(), lit_list->first->declarator->text.to_chars()))
	return lit_list->first->enum_pos;

    } else if (lit_list->first->declarator->text.to_chars()[1] == literal_str.c_str()[1])
      // Character enumeration item
      return lit_list->first->enum_pos;
  }
  return -1;
}


// Get enumeration literal associated with pos
pIIR_EnumerationLiteral
pos_to_literal(pIIR_EnumerationLiteralList enum_items, int literal_pos)
{
  for (pIIR_EnumerationLiteralList lit_list = enum_items; lit_list; lit_list = lit_list->rest)
    if (lit_list->first->enum_pos == literal_pos)
      return lit_list->first;

  return NULL;
}


// Create an internal acl object which is used to store acl values at
// simulation time. Return the name of the internal acl
// object. private_acl determines whether the object will be used
// privately or may be shared by several expressions.
string
create_internal_acl (const int size, RegionStack &rstack, bool private_acl)
{
  pIIR_DeclarativeRegion active_region = ActiveDeclarativeRegion(rstack);

  // generate a name for a new acl object. If the internal object is
  // private then the name is generated by adding a serial number to
  // the standard prefix name. Otherwise, an additional string "_acl"
  // is appended to the prefix and the number determines the max
  // length of the acl instance.
  string internal_var_name = internal_prefix_start + 
    (private_acl? to_string(internal_counter++) : "_acl" + to_string(size));
  
  if (lookup_internal_object_declaration(active_region, internal_var_name) == NULL)
    insert_internal_object_declaration(NULL, active_region, NULL, internal_var_name, "pacl", 
				       "=new(" + to_string(size) + ") acl", 
				       DECLARE_LOCALLY);

  return internal_var_name;
}



// Lookup an internal object declaration with name "name" defined in
// the declarative region "region"
pV2CC_InternalObjectDeclaration
lookup_internal_object_declaration(pIIR_DeclarativeRegion region, const string &name)
{
  for (pIIR_DeclarationList decls = extended_declarations(region); decls; decls = decls->rest) {
    pIIR_Declaration obj = decls->first;
    if (obj->is(V2CC_INTERNAL_OBJECT_DECLARATION) &&
	!strcmp(name.c_str(), obj->declarator->text.to_chars()))
      return pV2CC_InternalObjectDeclaration(obj);
  }

  return NULL;
}


// Return C++ type string of an internal object
string
get_internal_object_type_string(pV2CC_InternalObjectDeclaration decl, RegionStack &rstack)
{
  // Test whether cpp_type_string contains a valid string value
  if (decl->cpp_type_string != "")
    return decl->cpp_type_string;
  else
    return qid(decl, rstack, TYPE);
}

// Return inital value string of an internal object
string
get_internal_object_initial_string(pV2CC_InternalObjectDeclaration decl, RegionStack &rstack)
{
  // Test whether cpp_inital_string contains an valid type string
  if (decl->cpp_initial_string != "")
    return decl->cpp_initial_string;
  else {
    string str = "";
    if (decl->initial_value)
      emit_expr (decl->initial_value, str, rstack, DEFAULT);
    
    return str;
  }
}


// Merge two static levels. The resulting level will be equal to the
// smallest level of both.
IR_StaticLevel
merge_level(IR_StaticLevel sl1, IR_StaticLevel sl2)
{
  if (IR_LOCALLY_STATIC == sl1 && IR_LOCALLY_STATIC == sl2)
    return IR_LOCALLY_STATIC;
  if (level_match(sl1, IR_GLOBALLY_STATIC) &&
      level_match(sl2, IR_GLOBALLY_STATIC)) 
    return IR_GLOBALLY_STATIC;
  return IR_NOT_STATIC;
}


// Get folded value from IIR_Root node
StaticDataType &
get_folded_value(pIIR_Root n) 
{
  if (n->is(IR_EXPRESSION))
    return folded_value(pIIR_Expression(n));
  else if (n->is(IR_ENUMERATION_LITERAL))
    return folded_value(pIIR_EnumerationLiteral(n));
  else if (n->is(IR_LITERAL))
    return folded_value(pIIR_Literal(n));
  else
    assert(false);
}

// Returns whether a valid folded value has been calculated from node
// n
bool
valid_folded_value(pIIR_Root n) 
{
  if (n->is(IR_EXPRESSION))
    return valid_folded_value(pIIR_Expression(n));
  else if (n->is(IR_ENUMERATION_LITERAL))
    return valid_folded_value(pIIR_EnumerationLiteral(n));
  else if (n->is(IR_LITERAL))
    return valid_folded_value(pIIR_Literal(n));
  else
    assert(false);
}

int 
get_scalar_count(pIIR_Type type, bool &success)
{
  if (type->is(IR_ARRAY_TYPE)) {
    
    return get_scalar_count(pIIR_ArrayType(type)->element_type, success);

  } else if (type->is(IR_ARRAY_SUBTYPE)) {

  } else if (type->is(IR_RECORD_TYPE)) {

    // Sorry, but records are not supported yet
    assert(false);

  } else {
    success = true;
    return 1;
  }
}


static decl_flag_list::iterator
find_decl_in_list (decl_flag_list &l, pIIR_Declaration d)
{
  for (decl_flag_list::iterator i = l.begin(); i != l.end (); i++)
    if ((*i).first == d)
      return i;
  return l.end ();
}

void
merge (decl_flag_list &pm, pIIR_Type type, RegionStack &rstack)
{
  if (type->is(IR_SUBTYPE)) {
    // First, explore immediate base type. This is necessary in order
    // to gather all required info about the type. Note false is
    // passed over as last parameter here because we actually do not
    // need the list of accessed objects as determined by
    // explore_and_check.
    explore_and_check(pIIR_Subtype(type)->immediate_base, rstack, false);
    // Next, merge subtype into map
    merge(pm, pIIR_Subtype(type)->immediate_base, rstack);
  }

  if (type->declaration == NULL)
    return;

  pIIR_Declaration decl = type->declaration;
  // Try to find corresponding entry in list
  decl_flag_list::iterator iter = find_decl_in_list (pm, decl);
  // Insert new entry if pointer is not on the list. The boolean value
  // is set to false.  If it is already on the list, simply return.
  // This avoids endless recursion in case access types form cycles.
  if (iter != pm.end())
    return;

  // First recurse to merge referenced types that need to be defined
  // prior to this type.

  if (type->is(IR_ARRAY_TYPE)) {
    // For array types merge index types as well element type 
    for (pIIR_TypeList tl = pIIR_ArrayType(type)->index_types; tl; tl = tl->rest)
      merge(pm, tl->first, rstack);
    merge(pm, pIIR_ArrayType(type)->element_type, rstack);

  } else if (type->is(IR_RECORD_TYPE)) {
    // For record types merge element types
    pIIR_RecordType rt = pIIR_RecordType (type);
    for (pIIR_ElementDeclarationList edl = rt->element_declarations;
	 edl; edl = edl->rest)
      merge (pm, edl->first->subtype, rstack);

  } else if (type->is(IR_ACCESS_TYPE)) {
    // For access types merge desiganted type.
    merge(pm, pIIR_AccessType(type)->designated_type, rstack);
  }

  // Now append this type.
  pm.push_back (decl_flag_list::value_type (decl,false));
}

void
merge (decl_flag_list &pm, pIIR_Declaration decl, RegionStack &rstack)
{
  // Try to find corresponding entry in list and simply return when it
  // is found.
  decl_flag_list::iterator iter = find_decl_in_list (pm, decl);
  if (iter != pm.end())
    return;

  // First merge all declarations referenced by this one

  if (decl->is(IR_TYPE_DECLARATION)) {
    // If decl is a type decalration then use the special merge
    // function.
    merge(pm, pIIR_TypeDeclaration(decl)->type, rstack);
    return;

  } else if (decl->is(IR_SUBPROGRAM_DECLARATION)) {
    // If decl is a subprogram then the type of the subprogram
    // parameters must be merged.
    pIIR_SubprogramDeclaration subprog = pIIR_SubprogramDeclaration(decl);
    for (pIIR_InterfaceList il = subprog->interface_declarations; il; il = il->rest)
      merge(pm, get_basic_type(il->first->subtype), rstack);
    // If decl is a function then merge the return type of the
    // function as well.
    if (decl->is(IR_FUNCTION_DECLARATION))
      merge(pm, pIIR_FunctionDeclaration(decl)->return_type, rstack);	

  } else if (decl->is(IR_OBJECT_DECLARATION)) {
    // If decl is a object declaration, its subtype must be merged.
    merge (pm, pIIR_ObjectDeclaration (decl)->subtype, rstack);

  }

  // XXX - there are probably more cases to consider here.  The whole
  // external_decls business needs to be rethought, I'm afraid.  We
  // should just `merge' while we `explore_and_check'.  Also,
  // decl_pointer_bool_map needs to be an ordered collection.

  // Now append this declaration
  pm.push_back (decl_flag_list::value_type (decl,false));
}

void
merge (decl_flag_list &pm, pIIR_DeclarationList decls, RegionStack &rstack)
{
  for (pIIR_DeclarationList dl = decls; dl; dl = dl->rest)
    merge (pm, dl->first, rstack);
}


/* Check whether a scalar integer, enumeration or physical value e is
 * within the bound sepcified by the target type. print_error controls
 * whether an error message is printed whenever the bounds check fails
 * or just the number of errors are returnd. Node n is used to
 * determine the line number and source file name if an error message
 * should be printed. runtime_checks returns the checks that must be
 * performed at runtime. error_prefix_str will be prepended to the
 * error message in case of an error. */
int
check_scalar_against_bounds(pIIR_Root n, lint e, pIIR_Type target_type, RegionStack &rstack, 
			    RuntimeCheckFlags &runtime_checks, bool print_error,
			    string error_prefix_str) 
{ 
  int error_count = 0; 
  pIIR_Type target_base_type = get_base_type(target_type);

  // Determine range of target type
  vector<RangeDescriptor> range_des_vec = get_discrete_range(target_type, rstack, IR_NOT_STATIC);
  error_count += range_des_vec[0].constant_fold_rangedes(rstack);
  if (error_count != 0) return error_count;
  
  StaticRangeDescriptor<lint, IR_Direction> range = 
    range_des_vec[0].rangedes_to_lint(rstack);

  string left_str = to_string(range.left);
  string right_str = to_string(range.right);
  if (!range.valid[1]) {
    // If the range is not static then do not perform any furhter
    // checks. All checks will be done at runtime.
    runtime_checks |= RT_CHECK_DIRECTION | RT_CHECK_LEFT_BOUND | RT_CHECK_RIGHT_BOUND;
    return error_count;
  }
  if (!range.valid[0]) {
    // If bound is not static then store that the value must be
    // checked against this bound at runtime. 
    range.left = range.dir == IR_DIRECTION_UP? PHYSICAL_MIN : PHYSICAL_MAX;
    left_str = "?";
    runtime_checks |= RT_CHECK_LEFT_BOUND;
  }
  if (!range.valid[2]) {
    // If bound is not static then store that the value must be
    // checked against this bound at runtime. 
    range.right = range.dir == IR_DIRECTION_UP? PHYSICAL_MAX : PHYSICAL_MIN;
    right_str = "?";
    runtime_checks |= RT_CHECK_RIGHT_BOUND;
  }
  
  if (target_base_type->is(IR_ENUMERATION_TYPE)) {
    // *****************************************************
    // Enumeration type
    // *****************************************************
    if (range.left != PHYSICAL_MIN)
      left_str = pos_to_literal(pIIR_EnumerationType(target_base_type)->enumeration_literals, (int)range.left)
	->declarator->text.to_chars();
    if (range.right != PHYSICAL_MAX)
      right_str = pos_to_literal(pIIR_EnumerationType(target_base_type)->enumeration_literals, (int)range.right)
	->declarator->text.to_chars();
    if (e < range.left || e > range.right) {
      if (print_error) 
	if (is_implicit_subtype(target_type)) 
	  // If the traget type is an implicit type then do not print
	  // any range information as this is automatically done by
	  // the error method!
	  codegen_error.error("%:error:%s enumeration value is not within bounds of type %n.",
			      n, error_prefix_str.c_str(), target_type);
	else
	  codegen_error.error("%:error:%s enumeration value is not within bounds of type %n. "
			      "Range of type %n is %s to %s.", 
			      n, error_prefix_str.c_str(), target_type, target_type, left_str.c_str(), 
			      right_str.c_str());
      error_count++;
    }
    
  } else if (target_base_type->is(IR_INTEGER_TYPE)) {
    // *****************************************************
    // Integer type
    // *****************************************************
    if ((range.dir == IR_DIRECTION_DOWN && (e < range.right || e > range.left)) ||
	(range.dir != IR_DIRECTION_DOWN && (e > range.right || e < range.left))) {
      if (print_error)
	if (is_implicit_subtype(target_type)) 
	  // If the traget type is an implicit type then do not print
	  // any range information as this is automatically done by
	  // the error method!
	  codegen_error.error("%:error:%s integer value %i is not within bounds of type %n.",
			      n, error_prefix_str.c_str(), (int)e, target_type);
	else
	  codegen_error.error("%:error:%s integer value %i is not within bounds of type %n. "
			      "Range of type %n is %s %s %s.", 
			      n, error_prefix_str.c_str(), (int)e, target_type, target_type, 
			      left_str.c_str(), (range.dir == IR_DIRECTION_DOWN? "downto":"to"), 
			      right_str.c_str());
      error_count++;
    }

  } else if (target_base_type->is(IR_PHYSICAL_TYPE)) {
    // *****************************************************
    // Physical type
    // *****************************************************
    string value_str = to_string(e);
    if ((range.dir == IR_DIRECTION_DOWN && (e < range.right || e > range.left)) ||
	(range.dir != IR_DIRECTION_DOWN && (e > range.right || e < range.left))) {
      if (print_error)
	if (is_implicit_subtype(target_type)) 
	  // If the traget type is an implicit type then do not print
	  // any range information as this is automatically done by
	  // the error method!
	  codegen_error.error("%:error:%s pyhsical value %s is not within bounds of type %n.",
			      n, error_prefix_str.c_str(), value_str.c_str(), target_type);
	else
	  codegen_error.error("%:error:%s pyhsical value %s is not within bounds of type %n. "
			      "Range of type %n is %s %s %s.", 
			      n, error_prefix_str.c_str(), value_str.c_str(), target_type, 
			      target_type, left_str.c_str(), (range.dir == IR_DIRECTION_DOWN? "downto":"to"), 
			      right_str.c_str());
      error_count++;
    }


  } else {
    assert(false);
  }

  return error_count;
}



/* Check whether a scalar floating point value e is within the bound
 * sepcified by the target type. print_error controls whether an error
 * message is printed whenever the bounds check fails or just the
 * number of errors are returnd. Node n is used to determine the line
 * number and source file name if an error message should be
 * printed. runtime_checks returns the checks that must be performed
 * at runtime. error_prefix_str will be prepended to the error message
 * in case of an error. */
int
check_scalar_against_bounds(pIIR_Root n, double e, pIIR_Type target_type, RegionStack &rstack, 
			    RuntimeCheckFlags &runtime_checks, bool print_error,
			    string error_prefix_str) 
{ 
  int error_count = 0; 
  pIIR_Type target_base_type = get_base_type(target_type);
  // Bail out if target type is not an floating point type 
  assert(target_base_type->is(IR_FLOATING_TYPE));

  // Determine range of target type
  vector<RangeDescriptor> range_des_vec = get_discrete_range(target_type, rstack, IR_NOT_STATIC);
  error_count += range_des_vec[0].constant_fold_rangedes(rstack);
  if (error_count != 0) return error_count;

  StaticRangeDescriptor<double, IR_Direction> range = 
    range_des_vec[0].rangedes_to_double(rstack);

  string left_str = to_string(range.left);
  string right_str = to_string(range.right);
  if (!range.valid[1]) {
    // If the range is not static then do not perform any furhter
    // checks. All checks will be done at runtime.
    runtime_checks |= RT_CHECK_DIRECTION | RT_CHECK_LEFT_BOUND | RT_CHECK_RIGHT_BOUND;
    return error_count;
  }
  if (!range.valid[0]) {
    // If bound is not static then store that the value must be
    // checked against this bound at runtime. 
    range.left = range.dir == IR_DIRECTION_UP? -HUGE_VAL : HUGE_VAL;
    left_str = "?";
    runtime_checks |= RT_CHECK_LEFT_BOUND;
  }
  if (!range.valid[2]) {
    // If bound is not static then store that the value must be
    // checked against this bound at runtime. 
    range.right = range.dir == IR_DIRECTION_UP? HUGE_VAL : -HUGE_VAL;
    right_str = "?";
    runtime_checks |= RT_CHECK_RIGHT_BOUND;
  }
  
  if ((range.dir == IR_DIRECTION_DOWN && (e < range.right || e > range.left)) ||
      (range.dir != IR_DIRECTION_DOWN && (e > range.right || e < range.left))) {
    if (print_error)
      if (is_implicit_subtype(target_type)) 
	// If the traget type is an implicit type then do not print
	// any range information as this is automatically done by
	// the error method!
	codegen_error.error("%:error:%s floating point value %f is not within bounds of type %n.",
			    n, error_prefix_str.c_str(), e, target_type);
      else
	codegen_error.error("%:error:%s floating point value %f is not within bounds of type %n. "
			    "Range of type %n is %f %s %f.", 
			    n, error_prefix_str.c_str(),e, target_type, target_type, range.left, 
			    (range.dir == IR_DIRECTION_DOWN? "downto":"to"), range.right);
    error_count++;
  }
  
  return error_count;
}



/* Check whether a folded value value is within the bound sepcified by
 * the target type. print_error controls whether an error message is
 * printed whenever the bounds check fails or just the number of
 * errors are returned. Node n is used to determine the line number
 * and source file name if an error message should be
 * printed. runtime_checks returns the checks that must be performed
 * at runtime. error_prefix_str will be prepended to the error message
 * in case of an error. */
int
check_scalar_against_bounds(pIIR_Root n, StaticDataType &value, pIIR_Type target_type, RegionStack &rstack, 
			    RuntimeCheckFlags &runtime_checks, bool print_error,
			    string error_prefix_str) 
{
  if (get_base_type(target_type)->is(IR_FLOATING_TYPE))
    return check_scalar_against_bounds(n, value.double_value(), target_type, rstack, runtime_checks, 
				       print_error, error_prefix_str);
  else
    return check_scalar_against_bounds(n, value.long_value(), target_type, rstack, runtime_checks, 
				       print_error, error_prefix_str);
}


/* Check whether the source matches target type */
int
check_for_target_type(pIIR_Root n, pIIR_Type target_type, pIIR_Expression source,
		      RegionStack &rstack, RuntimeCheckFlags &runtime_checks, 
		      bool print_error, string error_prefix_str) 
{
  int error_count = 0;

  if (is_scalar_type(target_type)) {
    // If target_type is scalar then source must be scalar as
    // well. This should have been already checked by the parser.
    assert(is_scalar_type(source->subtype));
    // If the source value could be folded then check whether it is in
    // bounds of the target_type
    if (valid_folded_value(source))
      return check_scalar_against_bounds(n, folded_value(source), target_type, rstack, 
					 runtime_checks, print_error, error_prefix_str);
    else
      runtime_checks |= RT_CHECK_LEFT_BOUND | RT_CHECK_RIGHT_BOUND;

  } else if (is_array_type(target_type)) {
    // If target_type is an array then source must be an array as well.
    assert(is_array_type(source->subtype));
    
    if (!is_constrained_array_type(target_type)) {
      // If target_type array is unconstrained then we cannot check
      // the assignemnt at compile time. Further, the array aggregate
      // must not contain an others clause!
      if (source->is(IR_ARRAY_AGGREGATE)) {
	for (pIIR_IndexedAssociationList a = pIIR_ArrayAggregate(source)->indexed_association_list; a; a = a->rest) 
	  if (a->first->is(IR_OTHERS_INDEXED_ASSOCIATION)) {
	    if (print_error)
	      codegen_error.error("%:error:%s others must not be used in array aggregate if target type is unconstrained.",
				  n, error_prefix_str.c_str());
	    error_count++;
	  }
      }
      runtime_checks |= RT_CHECK_LEFT_ARRAY_BOUND | RT_CHECK_RIGHT_ARRAY_BOUND;

    } else if (!is_constrained_array_type(source->subtype)) {
      // If source array is unconstrained then we cannot check the
      // assignemnt at compile time.
      runtime_checks |= RT_CHECK_LEFT_ARRAY_BOUND | RT_CHECK_RIGHT_ARRAY_BOUND;

    } else {

      // Get bounds of target_type and source arrays
      vector<RangeDescriptor> range_desc_target = 
	get_discrete_range(target_type, rstack, IR_NOT_STATIC);
      vector<RangeDescriptor> range_desc_source = 
	get_discrete_range(source->subtype, rstack, IR_NOT_STATIC);
      
      // Check each dimension
      const int dim_count = range_desc_target.size();
      for (int dim = 0; dim < dim_count; dim++) {
	// Try to determine bounds now!
	StaticRangeDescriptor<lint, IR_Direction> 
	  target_range = range_desc_target[dim].rangedes_to_lint(rstack);
	StaticRangeDescriptor<lint, IR_Direction> source_range = 
	  range_desc_source[dim].rangedes_to_lint(rstack);
	lint target_length, source_length;
	// If we could determine bounds and direction at compile time
	// then check wether the array length matches.
	if (and_reduce(target_range.valid) && 
	    (and_reduce(source_range.valid) || valid_folded_value(source))) {
	  target_length = 
	    range_to_length(target_range.left, target_range.dir, target_range.right);
	  source_length = 
	    valid_folded_value(source)? folded_value(source).array_literal_value().size() : 
	    range_to_length(source_range.left, source_range.dir, source_range.right);
	  // Report an error if array length do not match
	  if (source_length != target_length) {
	    if (print_error) {
	      // If we have more than a single dimension then also
	      // output the dimension number
	      string dim_str = dim_count == 1? "" : "(dimension " + to_string(dim + 1) + ")";
	      codegen_error.error("%:error:%s array length mismatch%s. "
				  "Target array type has length %i while source array has length %i.",
				  n, error_prefix_str.c_str(), dim_str.c_str(), 
				  (int)target_length, (int)source_length);
	    }
	    error_count++;
	  }
	  
	} else
	  // Ok, we could not determine the array bounds at compile
	  // time. Hence, range checking must be done at runtime.
	  runtime_checks |= RT_CHECK_LEFT_ARRAY_BOUND | RT_CHECK_RIGHT_ARRAY_BOUND;
      }
    }

  } else if (get_base_type(target_type)->is(IR_RECORD_TYPE)) {
    // XXX - perform checking of record elements.
    return error_count;

  } else if (get_base_type(target_type)->is(IR_ACCESS_TYPE)) {
    return error_count;

  } else
    assert(false);

  return error_count;
}



// ******************************************************************************************
// Name: insert_internal_object_declaration, set of functions
//
// Description: Creates an internal object declaration and inserts it
// into the corresponding declaration list. The new item is inserted
// right before *listp. region points to the declarative region the
// new item belongs to. type_str is the C++ type of the item while
// initial_str stores its initial value. Alternatively, the type may
// be specified by a pIIR_Type pointer and the intial value may be
// defined by a pIIR_Expression.
// 
// Return value: returns pointer to new internal object declaration
//
// ******************************************************************************************

pV2CC_InternalObjectDeclaration
insert_internal_object_declaration(pIIR_DeclarationList *listp, pIIR_DeclarativeRegion region, pIIR_PosInfo pos,
				   const string &name, const string &type_str, const string &initial_str, 
				   int flags)
{
  // If listp is not specified then append the new item to the end of
  // the list
  if (listp == NULL)
    listp = get_last_rest_address(&extended_declarations(region));

  pV2CC_InternalObjectDeclaration obj =
    new V2CC_InternalObjectDeclaration(pos /* pIIR_PosInfo */, 
				       to_TextLiteral(name) /* declarator name */, 
				       region /* declaration region */, 
				       NULL /* attribute value list */, 
				       0 /* seqno */ , 
				       NULL /* type */ , 
				       NULL /* initial value expression */, 
				       NULL /* aliased object declaration */, 
				       (string)type_str /* type string */, 
				       (string)initial_str /* initial value string */, 
				       flags /* some flags */);
  *listp = new IIR_DeclarationList(obj->pos, obj, *listp);

  return obj;
}

pV2CC_InternalObjectDeclaration
insert_internal_object_declaration(pIIR_DeclarationList *listp, pIIR_DeclarativeRegion region,  
				   pIIR_PosInfo pos, const string &name, pIIR_Type type, 
				   const string &initial_str, int flags)
{
  // If listp is not specified then append the new item to the end of
  // the list
  if (listp == NULL)
    listp = get_last_rest_address(&extended_declarations(region));

  pV2CC_InternalObjectDeclaration obj =
    new V2CC_InternalObjectDeclaration(pos /* pIIR_PosInfo */, 
				       to_TextLiteral(name) /* declarator name */, 
				       region /* declaration region */, 
				       NULL /* attribute value list */, 
				       0 /* seqno */ , 
				       type /* type */ , 
				       NULL /* initial value expression */, 
				       NULL /* aliased object declaration */, 
				       "" /* type string */, 
				       (string)initial_str /* initial value string */, 
				       flags /* some flags */);
  *listp = new IIR_DeclarationList(obj->pos, obj, *listp);

  return obj;
}


pV2CC_InternalObjectDeclaration
insert_internal_object_declaration(pIIR_DeclarationList *listp, pIIR_DeclarativeRegion region, 
				   pIIR_PosInfo pos, const string &name, const string &type_str, 
				   pIIR_Expression initial, int flags)
{
  // If listp is not specified then append the new item to the end of
  // the list
  if (listp == NULL)
    listp = get_last_rest_address(&extended_declarations(region));

  pV2CC_InternalObjectDeclaration obj =
    new V2CC_InternalObjectDeclaration(pos /* pIIR_PosInfo */, 
				       to_TextLiteral(name) /* declarator name */, 
				       region /* declaration region */, 
				       NULL /* attribute value list */, 
				       0 /* seqno */ , 
				       NULL /* type */ , 
				       initial /* initial value expression */, 
				       NULL /* aliased object declaration */, 
				       (string)type_str /* type string */, 
				       "" /* initial value string */, 
				       flags /* some flags */);
  *listp = new IIR_DeclarationList(obj->pos, obj, *listp);

  return obj;
}


pV2CC_InternalObjectDeclaration
insert_internal_object_declaration(pIIR_DeclarationList *listp, pIIR_DeclarativeRegion region,
				   pIIR_PosInfo pos, const string &name, pIIR_Type type, 
				   pIIR_Expression initial, int flags)
{
  // If listp is not specified then append the new item to the end of
  // the list
  if (listp == NULL)
    listp = get_last_rest_address(&extended_declarations(region));

  pV2CC_InternalObjectDeclaration obj =
    new V2CC_InternalObjectDeclaration(pos /* pIIR_PosInfo */, 
				       to_TextLiteral(name) /* declarator name */, 
				       region /* declaration region */, 
				       NULL /* attribute value list */, 
				       0 /* seqno */ , 
				       type /* type */ , 
				       initial /* initial value expression */, 
				       NULL /* aliased object declaration */, 
				       "" /* type string */, 
				       "" /* initial value string */, 
				       flags /* some flags */);
  *listp = new IIR_DeclarationList(obj->pos, obj, *listp);

  return obj;
}


// ******************************************************************************************
// Name: insert_internal_code, function
//
// Description: Creates an internal object which contains code to be
// included into the generated C++ code. hdr contains header code to
// be prepended to the C++ code while impl stores the actual
// implementation code. Usually, this object is used to store the code
// generated from VHDL subporogram declarations. In this case, hdr
// contains the C++ interface definition of the subprogram while impl
// stores its implementation code.
// 
// Return value: returns pointer to new internal object declaration
//
// ******************************************************************************************

pV2CC_InternalCode
insert_internal_code(pIIR_DeclarationList *listp, pIIR_DeclarativeRegion region,
		     const string &name, const string &hdr, const string &impl,
		     int flags)
{
  // If listp is not specified then append the new item to the end of
  // the list
  if (listp == NULL)
    listp = get_last_rest_address(&extended_declarations(region));

  pV2CC_InternalCode obj =
    new V2CC_InternalCode(NULL /* pIIR_PosInfo */, 
			  to_TextLiteral(name) /* declarator name */, 
			  region /* declaration region */, 
			  NULL /* attribute value list */, 
			  0 /* seqno */ , 
			  NULL /* type */ , 
			  NULL /* initial value expression */, 
			  NULL /* aliased object declaration */, 
			  (string)hdr /* header string */, 
			  (string)impl /* initial value string */,
			  flags /* some flags */ );
  *listp = new IIR_DeclarationList(obj->pos, obj, *listp);

  return obj;
}


// ******************************************************************************************
// Name: m_get_object_declaration , generic function
//
// Description: Returns the object declaration a reference expression
// is based on. E.g. an expression "sig(3 downto 1)" will return the
// object declaration pointer associated with "sig". Note that if the
// prefix is a signal kind attribute then this signal attribute object
// is returned!
// 
// Return value: returns object declaration
//
// ******************************************************************************************


pIIR_ObjectDeclaration
m_get_object_declaration(pIIR_ObjectReference mor)
{
  return NULL;
}


pIIR_ObjectDeclaration
m_get_object_declaration(pIIR_SimpleReference sr)
{
  return sr->object;
}


pIIR_ObjectDeclaration
m_get_object_declaration(pIIR_SliceReference slr)
{
  return get_object_declaration(slr->array);
}


pIIR_ObjectDeclaration
m_get_object_declaration(pIIR_SignalAttr asr)
{
  codegen_error.error("%:error: sorry, currently no signal kind attributes are supported", asr);
  return NULL;
}


pIIR_ObjectDeclaration
m_get_object_declaration(pIIR_ArrayReference ar)
{
  return get_object_declaration(ar->array);
}


pIIR_ObjectDeclaration
m_get_object_declaration(pIIR_RecordReference rr)
{
  return get_object_declaration(rr->record);
}


// ******************************************************************************************
// Name: m_get_discrete_range , generic function
//
// Description: Returns an array of RangeDescriptors derived from the
// first parameter. Note that usually this function is called to
// determine the bounds on an scalar type or the index bounds on an
// array. In most cases it will return an array containing only a
// single element. However, when called to extract the index ranges
// from an array several RangeDescriptors may be returned where each
// one covers another index range.
// 
// Return value: RangeDescriptor (see v2cc.h)
//
// ******************************************************************************************

vector<RangeDescriptor>
m_get_discrete_range(pIIR_EnumerationType et, RegionStack &rstack, IR_StaticLevel slevel)
{
  vector<RangeDescriptor> bounds;

  pIIR_EnumerationLiteral left, right;
  
  left = et->enumeration_literals->first;
  for (pIIR_EnumerationLiteralList el = et->enumeration_literals; el; el = el->rest)
    if (el->rest == NULL)
      // Store right bound
      right = el->first;
      
  bounds.push_back(RangeDescriptor(left, IR_DIRECTION_UP, right, IR_LOCALLY_STATIC));

  return bounds;
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_IntegerType it, RegionStack &rstack, IR_StaticLevel slevel)
{
  return get_discrete_range(pIIR_ScalarSubtype(it->declaration->type)->range, rstack, slevel);
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_PhysicalType pt, RegionStack &rstack, IR_StaticLevel slevel)
{
  return get_discrete_range(pIIR_ScalarSubtype(pt->declaration->type)->range, rstack, slevel);
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_FloatingType ft, RegionStack &rstack, IR_StaticLevel slevel)
{
  return get_discrete_range(pIIR_ScalarSubtype(ft->declaration->type)->range, rstack, slevel);
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_ScalarSubtype st, RegionStack &rstack, IR_StaticLevel slevel)
{
  if (st->range == NULL) {
    // If no discrete array range is defined then try to get the range
    // from the base type of the current type
    return  get_discrete_range(st->immediate_base, rstack, slevel);

  } else {
    // Get the range of the type
    vector<RangeDescriptor> bounds = get_discrete_range(st->range, rstack, slevel);
    // Test static level of the exracted range(s). If no bound with
    // the required static range could be extracted then try to
    // extract an appropriate range from the base type of the current
    // type. Otherwise return bounds.
    if (bounds.size() == 0)
      return get_discrete_range(st->immediate_base, rstack, slevel);
    else
      return bounds;
  }
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_ExplicitRange r, RegionStack &rstack, IR_StaticLevel slevel)
{
  vector<RangeDescriptor> bounds;

  // If both bounds matche the required static level then create a
  // corresponding RangeDescriptor from the range. Otherwise return an
  // empty RangeDescriptor vector.
  if (level_match(r->left->static_level, slevel) &&
      level_match(r->right->static_level, slevel)) {
    IR_StaticLevel new_level = merge_level(r->left->static_level, r->right->static_level);
    bounds.push_back(RangeDescriptor(r->left, r->direction, r->right, new_level));
  }

  return bounds;
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_ArraySubtype ast, RegionStack &rstack, IR_StaticLevel slevel)
{
  vector<RangeDescriptor> bounds;

  if (ast->constraint == NULL)
    return get_discrete_range(ast->immediate_base, rstack, slevel);

  for (pIIR_TypeList tl = ast->constraint; tl; tl = tl->rest) {
    vector<RangeDescriptor> new_bound = get_discrete_range(tl->first, rstack, slevel);
    assert (new_bound.size() <= 1);
    bounds.push_back(new_bound[0]);
  }

  return bounds;
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_ArrayType at, RegionStack &rstack, IR_StaticLevel slevel)
{
  vector<RangeDescriptor> bounds;

  for (pIIR_TypeList tl = at->index_types; tl; tl = tl->rest) {
    vector<RangeDescriptor> new_bound = get_discrete_range(tl->first, rstack, slevel);
    assert (new_bound.size() <= 1);
    bounds.push_back(new_bound[0]);
  }

  return bounds;
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_Attr_ArrayRANGE atr, RegionStack &rstack, IR_StaticLevel slevel)
{
  vector<RangeDescriptor> bounds;
  bounds.push_back(RangeDescriptor(atr));

  return bounds;
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_Attr_ArrayREVERSE_RANGE atr, RegionStack &rstack, IR_StaticLevel slevel)
{
  vector<RangeDescriptor> bounds;
  bounds.push_back(RangeDescriptor(atr));

  return bounds;
}


vector<RangeDescriptor>
m_get_discrete_range(pIIR_SliceReference sr, RegionStack &rstack, IR_StaticLevel slevel)
{
  return get_discrete_range(sr->range, rstack, slevel);
}

