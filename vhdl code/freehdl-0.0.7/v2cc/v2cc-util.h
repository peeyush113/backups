
#ifndef V2CC_UTIL_H 
#define V2CC_UTIL_H

using namespace std;

#include <sstream>
#include <iomanip>
#include <freehdl/vaul.h>
#include "v2cc-chunk.h"

// ******************************************************************************************
// Some global variables
// ******************************************************************************************

// Counter to produce unique names for internal variables
extern int internal_counter;
extern string internal_prefix_start;

// Prefix used to build a default name for a process
extern const string process_default_postfix;

// Prefix used to build a default name for loop statement
extern const string loop_default_postfix;

// Stores which type of checks shall be performed at runtime
extern CodeGeneratorCheckFlags do_runtime_checks;

// Holds list of unique pointers to externl declarations which are
// used within the current design(s)
extern decl_flag_list external_decls_list;

// Points to the last PosInfo instance printed to the C++ code
extern pIIR_PosInfo_TextFile last_pos_info;


class v2cc_codegen_options {
  // Global variable to control register code generation. Register code
  // is used to collect information about VHDL objects (components,
  // processes, signals, variables, constants, ...) at simulation
  // startup.
  bool emit_register_code;
  
  // Flag to control whether debugging code/info shall be includes into
  // the generated code
  bool emit_debug_code;

  // Flag to control generation of CDFG (control data flow graph)
  // generation. Actually, no CDFG graph is created directly. Instead a
  // lisp module to generate the CDFG nodes is created from each
  // process.
  bool emit_cdfg_code;

  // If true, then code for procedure "main" is generated. "main" is
  // needed to build the simulator executable. It initializes
  // elaboration of the top level component.
  bool emit_main_cc_code;
  string main_cc_filename;

  bool verbose;
  int parser_flags;

 public:

  v2cc_codegen_options ();

  void set_emit_register_code (const bool v) { emit_register_code = v; }
  bool get_emit_register_code () const { return emit_register_code; }

  void set_emit_debug_code (const bool v) { emit_debug_code = v; }
  bool get_emit_debug_code () const { return emit_debug_code; }

  void set_emit_cdfg_code (const bool v) { emit_cdfg_code = v; }
  bool get_emit_cdfg_code () const { return emit_cdfg_code; }

  void set_verbose (const bool v) { verbose = v; }
  bool get_verbose () const { return verbose; }

  void set_emit_main_cc_code (const bool v) { emit_main_cc_code = v; }
  bool get_emit_main_cc_code () { return emit_main_cc_code; }
  void set_main_cc_filename (const string str) { main_cc_filename = str; }
  string get_main_cc_filename () const { return main_cc_filename; }
  
  void set_parser_flags (const bool v) { parser_flags = v; }
  int get_parser_flags () const { return parser_flags; }
};

extern v2cc_codegen_options codegen_options;

// used to generate error messages
extern vaul_error_printer codegen_error;



// ******************************************************************************************

// Calculate power for integer parameters.
lint
calculate_pow(lint a, lint b);

// Calculate power for double/integer parameters.
double
calculate_pow(double a, lint b);

// Calculate power for double/integer parameters.
inline double
calculate_pow(double a, double b)
{
  return calculate_pow(a, (lint) b);
}

// Calculate absolute value of long long int parameter. Will be
// replaced with library function llabs as soon as llabs funcion
// compiles with gcc.
inline lint
lint_abs (const lint a) 
{
  return a < 0 ? (-a) : a;
}


/* Get line number associated with a node */
int
get_line_number(pIIR_Root n);

/* Return a number which is unique within the current file. */
int
get_unique_int_id();

/* Get library and unit name */
vector<string>
get_library_and_unit_name(pIIR_Declaration decl);

/* Get source file name associated with a node */
const char *
get_source_file_name(pIIR_Root n);

/* Get id_type from region stack. Note that dependent on the region
 * stack some objects are either accessed directly or accessed via
 * architecture pointers */
id_type
get_default_id_type(RegionStack &rstack);

// Converts a string item into an IR_TextLiteral
pIIR_TextLiteral
to_TextLiteral(const string &str);

/* Return a string of L spaces, but at most 30. */
string 
spaces(int l);

/* Emit a declaration name */
void 
emit_id (pIIR_Declaration d, string &str, RegionStack &rstack);

/* Emit a type name */
void
emit_id (pIIR_Type t, string &str, RegionStack &rstack);

/* Emit an UglyIdentifier as a beautiful_identifier. */
void 
emit_id(pIIR_TextLiteral idnode, string &str, RegionStack &rstack);

/* emit a plain identifier */
void
emit_noqual_id (pIIR_Declaration d, string &str, RegionStack &rstack, id_type typ=id_type());


/* Emit folded value. Note that in case of an array literal value an
 * global internal variable will be created which stores the array
 * elements. */
void
emit_folded_value(StaticDataType &data, string &str, RegionStack &rstack, pIIR_Type subtype);

/* Emit folded value in CDFG style. */
void
cdfg_emit_folded_value(StaticDataType &data, string &str, RegionStack &rstack, pIIR_Type subtype);


//string
//qid (pIIR_Declaration d, RegionStack &rstack, id_type typ=id_type());

// get an unqualified id
string
nid(pIIR_Declaration d, id_type obj_access=id_type());

/* return long name of declaration (similar to the path_name defined
 * in VHDL). E.g., returns ":std:standard:bit" when called for
 * standard type bit. */
string
get_long_name(pIIR_Declaration d);

/* prepend special characters like " with \ and return string. */
string 
get_escaped_string (const string str, const string escape_chars = "\"\\");

/* Select association element from an association list which
 * corresponds with given formal */
list<pIIR_AssociationElement>
find_matching_actuals(pIIR_AssociationList assocs, pIIR_InterfaceDeclaration formal);

/* Test whether a type is a scalar */
bool
is_scalar_type(pIIR_Type t);

/* Test whether a type denotes an array type */
bool 
is_array_type(pIIR_Type t);

/* Test whether an type is an constrained array type */
bool
is_constrained_array_type(pIIR_Type t);

/* Test whether an type is an implicit defined array
 * subtype. E.g. when a variable "varaible var : bit_vector(0 to 7)"
 * is declared then an implicit subtype "bit_vector(0 to 7)" is
 * defined. */
bool 
is_implicit_array_subtype(pIIR_Type t);

/* Test whether an type is an implicit defined
 * subtype. */
bool
is_implicit_subtype(pIIR_Type t);

/* Calculate length from left bound, right bound and direction */
lint
range_to_length(lint left, IR_Direction dir, lint right);

/* Applies a function "int (*f)(int)" on a copy of the paramter string
 * and returns it. E.g., calling "convert_string(str, tolower)" will
 * convert all characters in str to lower case. */
inline string
convert_string(const string &str, int (*f)(int)) 
{
  string result = str;
  for (unsigned int i = 0; i < result.length(); i++)
    result[i] = (*f)(result[i]);

  return result;
}

/* Convert an integer value into a string */
template <class T>
inline string
to_string(T i)
{
  stringstream lstr;
  lstr << i;
  return lstr.str();
}

inline string
to_string(double i)
{
  stringstream lstr;
#if !defined __GNUC__ || __GNUC__ != 2
  lstr << showpoint << setprecision(20) << i;
  return lstr.str();
#else
  lstr << setprecision(20) << i;
  string str = lstr.str ();
  if (str.find ('.') < str.size ())
    return str;
  else
    return str + ".0";
#endif
}

/* Print scalar value into a string */
string
to_string(pIIR_ScalarType type, const StaticDataType &value);


/* Convert a string value into a string (dummy function) */
inline string
to_string(string &str) { return str; }


/* Template class used to build binary function objects that take two
 * function object classes as parameter: ArgF is a unary function
 * class that is used to process both arguments, which are then passed
 * over to binary function class CompF. E.g.,
 * binary_function_compose<less<int>, select1st<pair<int,int> > > ()
 * creates a function object that takes two pair<int,int> as
 * parameter, select the first element of the pairs and compares them
 * using less<int>. */
template <class CompF, class ArgF>
struct binary_function_compose : 
  public binary_function <typename ArgF::argument_type, 
			  typename ArgF::argument_type,
			  typename CompF::result_type>
{
  CompF CF;
  ArgF AF;
  binary_function_compose () {};
  typename CompF::result_type
  operator ()(const typename ArgF::argument_type &arg1, 
	      const typename ArgF::argument_type &arg2) const
  {
    return CF (AF (arg1), AF(arg2));
  }
};

/* Convert an string value into a long integer. The number is returned
   as second element of the pair. The function returns false in first
   pair lement in case of an overflow. */
pair<bool, StaticLint> string_to_lint(const string &str);

/* Convert an string value into a double. The number is returned in
   second element of the pair. The function returns false in first
   pair element in case of an overflow. */
pair<bool, StaticDouble> string_to_double(const string &str);

// Get folded value from IIR_Root node
StaticDataType &
get_folded_value(pIIR_Root n);

// Returns whether a valid folded value has been calculated from node
// n
bool
valid_folded_value(pIIR_Root n);

/* Concatenate lists or items into a string */
template<class Titer>
string
concat_to_string(const Titer b, const Titer e, const string sep)
{
  if (b == e) return "";
  
  Titer iter = b;
  string result = to_string(*iter);
  while (++iter != e)
    result += sep + to_string(*iter);

  return result;
}


/* Return the prefix for the name of a new internal variable */
string
get_new_internal_var_prefix();

/* Set prefix for internal variables */
void
set_internal_prefix_start(pIIR_DeclarativeRegion r, RegionStack &rstack);


// Return number of items on a list
template<class T>
int
list_size(T *l)
{
  int items = 0;
  while (l != NULL) {
    items++;
    l = l->rest;
  }
  return items;
}


// Return n-th element (first element is the 0-th element!)
template<class T>
T *
get_nth_element(T *l, const int n)
{
  for (int i = 0; i < n; i++)
    l = l->rest;

  return l;
}

// Return address of the last member from the last item on the
// list. If the list is empty then return listp. Note that listp is
// the ADDRESS of an pointer which points to the next item on the list
// (or to NULL).
template<class T> 
T *get_last_rest_address(T *listp)
{
  while (*listp)
    listp = &(*listp)->rest;

  return listp;
}


// Creates a copy of a list and returns a pointer to the new
// list. Note that the source list type and the destination type may
// differ. source_T is the source list type while target_T is the
// destination list type.
template<class source_T, class target_T>
target_T* clone_list(source_T* list)
{
  target_T *new_list = NULL;
  target_T **last_rest_address = &new_list;
  for (; list; list = list->rest) {
    *last_rest_address = new target_T(list->pos, list->first, NULL);
    last_rest_address = &(*last_rest_address)->rest;
  }

  return new_list;
}



// Creates a copy of a list and returns a pointer to the new
// list. Note that the source list type and the destination type may
// differ. source_T is the source list type while target_T is the
// destination list type. However, only list items for which the unary
// function class F returns true are copied!
template<class source_T, class target_T, class F>
target_T* filter_list(source_T* list)
{
  target_T *new_list = NULL;
  target_T **last_rest_address = &new_list;
  for (; list; list = list->rest) {
    // If node kind of the list itme matches one of the kind stored in
    // the filter vector then skip this declaration!
    if (! bool(F(list->first))) 
	continue;
    *last_rest_address = new target_T(list->pos, list->first, NULL);
    last_rest_address = &(*last_rest_address)->rest;
  }

  return new_list;
}



/* Print line number and source file name */
#define NO_SOURCE_LINE NULL

inline pIIR_PosInfo_TextFile
emit_posinfo(pIIR_PosInfo pi, string &str, pIIR_PosInfo_TextFile last_pos, int l = 0) {

  if (pi == NO_SOURCE_LINE) {
    // Print the source line of the generated code if the
    // corresponding C++ line is not associated with any real line
    // number of the VHDL source code!
    if (last_pos == NULL) return NULL;
    str += "#line 1000000 __FILE__\n";
    return NULL;
  }

  if (!codegen_options.get_emit_debug_code () ||
      !pi->is(IR_POS_INFO_TEXT_FILE)) return last_pos;

  pIIR_PosInfo_TextFile pit = pIIR_PosInfo_TextFile(pi);
  // Emit line number and file name
  str += "#line " + to_string(pit->line_number);
  if (last_pos == NO_SOURCE_LINE)
    str += " \"" + to_string(pit->file_name) + "\"\n";
  else
    str += "\n";
  
  return pit;
}


/* Returns a pointer to the current active context info instance */
ContextInfo *
ActiveContext(RegionStack &rstack);

pIIR_DeclarativeRegion
ActiveDeclarativeRegion(RegionStack &rstack);

/* Returns the next process, subprogram, concurrent assignment,
   package declaration, package body declaration, architecture or
   entity declarative region */
extern ContextInfo *
BaseContext(RegionStack &rstack);

pIIR_DeclarativeRegion
BaseDeclarativeRegion(RegionStack &rstack);

/* Returns the top level region which is either an architecture
   region, an entity region, a package body region or package declaration
   region */
ContextInfo *
TopContext(RegionStack &rstack);

pIIR_DeclarativeRegion
TopDeclarativeRegion(RegionStack &rstack);

pIIR_DeclarativeRegion
TopDeclarativeRegion(pIIR_DeclarativeRegion region);

/* Returns the upper most declarative region which has been added to
   store all the global code items */
pIIR_DeclarativeRegion
RootDeclarativeRegion(RegionStack &rstack);

ContextInfo *
RootContext(RegionStack &rstack);


inline bool
is_PackageDeclarativeRegion(pIIR_DeclarativeRegion region) 
{
  if (region->is(IR_PACKAGE_BODY_DECLARATION) ||
      region->is(IR_PACKAGE_DECLARATION)) {
    return true;
  } else
    return false;
}

/* for debugging */
extern int
plot_rstack(RegionStack &rstack);

/* for debugging */
extern void
plot(string &str);

// Create a list of declarative region pointers beginning from
// end_region up to the root region
list<pIIR_DeclarativeRegion> 
create_region_list(pIIR_DeclarativeRegion end_region);

inline pIIR_DeclarativeRegion
get_parent_declarative_region(pIIR_DeclarativeRegion region, RegionStack &rstack)
{
  if (region->is (IR_ARCHITECTURE_DECLARATION))
    return pIIR_ArchitectureDeclaration (region)->entity;
  else if (region->is (IR_PACKAGE_BODY_DECLARATION))
    return pIIR_PackageBodyDeclaration (region)->package;
  else if (region->is (IR_ENTITY_DECLARATION) ||
	   region->is (IR_PACKAGE_DECLARATION) || 
	   region->is (IR_CONFIGURATION_DECLARATION) || 
	   region->is (VAUL_TOP_SCOPE))
    return RootDeclarativeRegion (rstack);
  else if (region == RootDeclarativeRegion (rstack))
    return NULL;
  else
    return region->declarative_region;
}

// Get the type declaration
pIIR_TypeDeclaration
get_declaration(pIIR_Type type);

// Get the immediate_base type
pIIR_Type
get_immediate_base_type(pIIR_Type type);

// Get base type of a type
pIIR_Type
get_base_type(pIIR_Type type);

// Get base type or subtype the current type is derived from. I.e.,
// any subtype declarations which only add a resolution function are
// skipped.
pIIR_Type
get_basic_type(pIIR_Type type);

/* Emit code to create an new object of a specific type */
string
create_default_instance(pIIR_Type type, RegionStack &rstack);

/* Emit code to create an new object of a specific type using CDFG
   style */
string
cdfg_create_default_instance(pIIR_Type type, RegionStack &rstack);

/* Creates an array info object for an array subtype */
string
create_array_info_obj(pIIR_Type base, pIIR_Range range, RegionStack &rstack, const bool static_object);

// Convert locally static expression to int value. Returns false if
// the expression is not locally static.
bool
expr_to_int(pIIR_Expression e, int &value, RegionStack &rstack);

// Get enumeration pos of enumeration item
int 
literal_to_pos(pIIR_EnumerationLiteralList enum_items, const string &literal_str);

// Get enumeration literal associated with pos
pIIR_EnumerationLiteral
pos_to_literal(pIIR_EnumerationLiteralList enum_items, int literal_pos);

// Create an internal acl object which is used to store acl values at
// simulation time. Return the name of the internal acl
// object. private_acl determines whether the object will be used
// privately or may be shared by several expressions.
string
create_internal_acl (const int size, RegionStack &rstack, bool private_acl);

// Lookup an internal object declaration with name "name" defined in
// the declarative region "region"
pV2CC_InternalObjectDeclaration
lookup_internal_object_declaration(pIIR_DeclarativeRegion region, const string &name);


// Return C++ type string of an internal object
string
get_internal_object_type_string(pV2CC_InternalObjectDeclaration decl, RegionStack &rstack);

// Return inital value string of an internal object
string
get_internal_object_initial_string(pV2CC_InternalObjectDeclaration decl, RegionStack &rstack);


// Test whether static level level matches the required static level
// test. The function returns true if the static level "level" is
// greater or equal compared to level test.
inline bool 
level_match(IR_StaticLevel test, IR_StaticLevel level) {
  switch (level) {
  case IR_LOCALLY_STATIC:
    if (test == IR_GLOBALLY_STATIC) return false;
  case IR_GLOBALLY_STATIC:
    if (test == IR_NOT_STATIC) return false;
  case IR_NOT_STATIC:
    break;
  };
  return true;
}


// Merge two static levels. The resulting level will be equal to the
// smallest level of both.
IR_StaticLevel
merge_level(IR_StaticLevel sl1, IR_StaticLevel sl2);

// Merge pointers of the declaration decls list into the pointer set
// pm
void
merge (decl_flag_list &pm, pIIR_DeclarationList decls, RegionStack &rstack);

pIIR_DeclarativeRegion
get_combined_static_region(list<pIIR_DeclarativeRegion> &rlist, RegionStack &rstack);

pIIR_DeclarativeRegion
get_combined_static_region(pIIR_DeclarativeRegion r1, pIIR_DeclarativeRegion r2, RegionStack &rstack);


/* Check whether a folded value value is within the bound sepcified by
 * the target type. print_error controls whether an error message is
 * printed whenever the bounds check fails or just the number of
 * errors are returnd. Node n is used to determine the line number and
 * source file name if an error message should be
 * printed. runtime_checks returns the checks that must be performed
 * at runtime. error_prefix_str will be prepended to the error message
 * in case of an error. */
int
check_scalar_against_bounds(pIIR_Root n, StaticDataType &value, pIIR_Type target_type, RegionStack &rstack, 
			    RuntimeCheckFlags &runtime_checks, bool print_error = true,
			    string error_prefix_str = "");

/* Check whether a scalar integer, enumeration or physical value e is
 * within the bound sepcified by the target type. print_error controls
 * whether an error message is printed whenever the bounds check fails
 * or just the number of errors are returnd. Node n is used to
 * determine the line number and source file name if an error message
 * should be printed. runtime_checks returns the checks that must be
 * performed at runtime. error_prefix_str will be prepended to the
 * error message in case of an error.  */
int
check_scalar_against_bounds(pIIR_Root n, lint e, pIIR_Type target_type, RegionStack &rstack, 
			    RuntimeCheckFlags &runtime_checks, bool print_error = true,
			    string error_prefix_str = "");


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
			    RuntimeCheckFlags &runtime_checks, bool print_error = true,
			    string error_prefix_str = "");


/* Check whether the source matches target type is ok */
int
check_for_target_type(pIIR_Root n, pIIR_Type target_type, pIIR_Expression source,
		      RegionStack &rstack, RuntimeCheckFlags &runtime_checks, 
		      bool print_error = true, string error_prefix_str = "");



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
				   int flags);
pV2CC_InternalObjectDeclaration
insert_internal_object_declaration(pIIR_DeclarationList *listp, pIIR_DeclarativeRegion region, pIIR_PosInfo pos,
				   const string &name, pIIR_Type type, const string &initial_str, 
				   int flags);
pV2CC_InternalObjectDeclaration
insert_internal_object_declaration(pIIR_DeclarationList *listp, pIIR_DeclarativeRegion region, pIIR_PosInfo pos,
				   const string &name, const string &type_str, pIIR_Expression initial, 
				   int flags);
pV2CC_InternalObjectDeclaration
insert_internal_object_declaration(pIIR_DeclarationList *listp, pIIR_DeclarativeRegion region, pIIR_PosInfo pos,
				   const string &name, pIIR_Type type, pIIR_Expression initial, int flags);


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
		     int flags);

#endif
