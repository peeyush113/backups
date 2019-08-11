#ifndef V2CC_HEADER
#define V2CC_HEADER

using namespace std;

#include <freehdl/vaul.h>
#include "mapping.h"

// ****************************************************************************
// * Definitons related to function qid and nid
// ****************************************************************************
// id_type is used to control the output of the qid and nid function.
#define DEFAULT 0x1
#define SIGNAL 0x2
#define READER 0x4
#define DRIVER 0x8
#define TYPE 0x10
#define INFO 0x20
#define BARE 0x40
#define LIBRARY 0x80
#define ALIAS 0x100

#define ARCHREF 0x2		// object access shall look like "arch->..."
#define DEREF 0x4		// object access shall look like "*..."
#define NO_PREFIX 0x8

struct id_type
{
  int obj;
  int acc;
    id_type (int o = DEFAULT, int a = DEFAULT)
  {
    obj = o;
    acc = a;
  }
  int object () const
  {
    return obj;
  }
  int access () const
  {
    return acc;
  }
};



// ****************************************************************************
// * Definition of template flag_array
// ****************************************************************************
// A template class to store an array of boolen values
template < int C > struct flag_array
{
  // The actual boolean values
  unsigned int data[(C + 31) / 32];
  const int asize;
  // Some constructors
    flag_array ():asize ((C + 31) / 32)
  {
    memset (data, 0, sizeof (unsigned int) * asize);
  }
  flag_array (const flag_array & a):asize ((C + 31) / 32)
  {
    memcpy (data, a.data, sizeof (unsigned int) * asize);
  }
  flag_array (const int i):asize ((C + 31) / 32)
  {
    memset (data, 0, sizeof (unsigned int) * asize);
    data[i / 32] = 1 << (i % 32);
  }
  flag_array & operator = (const flag_array & a)
  {
    memcpy (data, a.data, sizeof (unsigned int) * asize);
    return *this;
  }
  // Test whether a specific bit is set
  bool is_set (const int i)
  {
    return (data[i / 32] & (1 << (i % 32))) != 0;
  }
  // Set a bit of the vector. The bit is speicified by the bit
  // position number.
  flag_array operator | (const int i)
  {
    flag_array result (*this);
    result.data[i / 32] |= 1 << (i % 32);
    return result;
  }
  // Perform an logical or operation on two flag_arrays
  flag_array operator | (const flag_array & a)
  {
    flag_array result (*this);
    for (int i = 0; i < asize; i++)
      result.data[i] |= a.data[i];
    return result;
  }
  flag_array & operator |= (const flag_array & a)
  {
    for (int i = 0; i < asize; i++)
      data[i] |= a.data[i];
    return *this;
  }
  // Perform an logical and operation on two flag_arrays
  flag_array operator & (const flag_array & a)
  {
    flag_array result;
    for (int i = 0; i < asize; i++)
      result.data[i] = data[i] & a.data[i];
    return result;
  }
  // Perform an reduce or operation on the vector bits
  operator bool ()
  {
    unsigned int result = 0;
    for (int i = 0; i < asize; i++)
      result |= data[i];
    return result != 0;
  }
};



// ****************************************************************************
// * Definition of AccessFlags
// ****************************************************************************
// AccessFlags will store different types of operations performed on a
// VHDL object
typedef flag_array < 32 > AccessFlags;

// constants to mark how objects are accessed
#define READ       AccessFlags(0)
#define WRITE      AccessFlags(1)
#define SENSITIVE  AccessFlags(2)
#define FUNCTION_CALL AccessFlags(3)
#define TYPE_CHECK AccessFlags(4)	// Indicates that some type (range) checks has been made for a specific type
#define TYPE_USED AccessFlags(5)	// Indicates that a type has been used
#define SIGNAL_FUNCTION_ATTRIBUTE  AccessFlags(6)	// A signal function kind Attribute has been applied on a signal
#define ATTRIBUTE_DELAYED  AccessFlags(7)	// Signal kind attribute DELAYED
#define ATTRIBUTE_TRANSACTION  AccessFlags(8)	// Signal kind attribute TRANSACTION
#define ATTRIBUTE_STABLE  AccessFlags(9)	// Signal kind attribute STABLE
#define ATTRIBUTE_QUIET  AccessFlags(10)	// Signal kind attribute QUIET
#define PROCEDURE_CALL AccessFlags(11)

#define SIGNAL_KIND_ATTRIBUTE (ATTRIBUTE_DELAYED | ATTRIBUTE_TRANSACTION | ATTRIBUTE_STABLE | ATTRIBUTE_QUIET)
#define ACCESS     (READ | WRITE | SENSITIVE | SIGNAL_FUNCTION_ATTRIBUTE | SIGNAL_KIND_ATTRIBUTE | \
                    FUNCTION_CALL | PROCEDURE_CALL)


// ****************************************************************************
// * Definition of RuntimeCheckFlags
// ****************************************************************************
// RuntimeCheckFlags store the type of check operations that must be perfomed
// at runtime
typedef flag_array < 32 > RuntimeCheckFlags;

// Constants for check operations
#define RT_CHECK_LEFT_BOUND RuntimeCheckFlags(0)
#define RT_CHECK_RIGHT_BOUND RuntimeCheckFlags(1)
#define RT_CHECK_DIRECTION RuntimeCheckFlags(2)
#define RT_CHECK_LEFT_ARRAY_BOUND RuntimeCheckFlags(3)
#define RT_CHECK_RIGHT_ARRAY_BOUND RuntimeCheckFlags(4)
#define RT_CHECK_ARRAY_DIRECTION RuntimeCheckFlags(5)


// ****************************************************************************
// * Definition of CodeGeneratorFlags
// ****************************************************************************
// Flags to control the behaviour of the code generator. E.g., to
// control whether code to check for type bounds are put into the
// generated code.
typedef flag_array < 32 > CodeGeneratorCheckFlags;

#define CG_CHECK_SCALAR_TYPE_RANGE CodeGeneratorCheckFlags(0)
#define CG_CHECK_COMPOSITE_TYPE_RANGE CodeGeneratorCheckFlags(1)
#define CG_CHECK_OBJECT_RANGE CodeGeneratorCheckFlags(2)
#define CG_CHECK_SIGNAL_RANGE CodeGeneratorCheckFlags(3)
#define CG_CHECK_ARRAY_INDEX CodeGeneratorCheckFlags(4)

#define CG_CHECK_ALL (\
 CG_CHECK_SCALAR_TYPE_RANGE|\
 CG_CHECK_COMPOSITE_TYPE_RANGE|\
 CG_CHECK_OBJECT_RANGE|\
 CG_CHECK_SIGNAL_RANGE|\
 CG_CHECK_ARRAY_INDEX\
)


// ****************************************************************************
// * Definition of processing steps that were performed on a node
// ****************************************************************************
// Optimization/compilation stages
#define CONST_FOLD 0x1
#define EXPLORED 0x2


// ****************************************************************************
// * Max and min values
// ****************************************************************************
// Max and min integer values
#define INTEGER_MIN (INT_MIN + 1)
#define INTEGER_MAX (INT_MAX)

// Max and min physical type values
#define PHYSICAL_MAX (9223372036854775807LL - 1LL)
#define PHYSICAL_MIN (-9223372036854775807LL + 1LL)


// ****************************************************************************
// * Some definitions and functions
// ****************************************************************************
typedef long long int lint;	// To save some typing

inline int
min (const int a, const int b)
{
  return a < b ? a : b;
}

inline int
max (const int a, const int b)
{
  return a > b ? a : b;
}

inline lint
min (const lint a, const lint b)
{
  return a < b ? a : b;
}

inline lint
max (const lint a, const lint b)
{
  return a > b ? a : b;
}

inline bool
and_reduce (const vector < bool > &vec)
{
  for (unsigned int i = 0; i < vec.size (); i++)
    if (!vec[i])
      return false;

  return true;
}

inline bool
or_reduce (const vector < bool > &vec)
{
  for (unsigned int i = 0; i < vec.size (); i++)
    if (vec[i])
      return true;

  return false;
}


// Ordered list of declaration/bool mappings.
typedef list < pair < pIIR_Declaration, bool > > decl_flag_list;


// Virtual base class for static values
struct StaticDataBase {
  virtual ~StaticDataBase() {};
  virtual lint &long_value () { assert (false); };
  virtual double &double_value () { assert (false); };
  virtual vector<int> &array_literal_value () { assert (false); };
  virtual StaticDataBase *clone () const = 0;
  virtual string original_string () const { assert (false); };
  virtual bool is_double_value () const { return false; }
  virtual bool is_long_value () const { return false; }
  virtual bool is_array_literal_value () const { return false; }
};

// Stores a double value
struct StaticDouble : public StaticDataBase {
  string orig_string;
  double value;
  virtual double & double_value () { return value; }
  StaticDouble (const double v) { value = v; }
  StaticDouble (const double v, const string &s) { value = v; orig_string = s; }
  StaticDouble () { value = 0; }
  virtual StaticDataBase *clone () const { return new StaticDouble (value, orig_string); }
  virtual string original_string () const { return orig_string; }
  virtual bool is_double_value () const { return true; }
};

// Stores a long long int value
struct StaticLint : public StaticDataBase {
  string orig_string;
  lint value;
  virtual lint & long_value () { return value; }
  StaticLint (const lint v) { value = v; }
  StaticLint (const lint v, const string &s) { value = v; orig_string = s; }
  StaticLint () { value = 0; }
  virtual StaticDataBase *clone () const { return new StaticLint (value, orig_string); }
  virtual string original_string () const { return orig_string; }
  virtual bool is_long_value () const { return true; }
};

// Stores a array literal value
struct StaticArrayLiteral : public StaticDataBase {
  vector<int> value;
  virtual vector<int> & array_literal_value () { return value; }
  StaticArrayLiteral (const vector<int> v) { value = v; }
  StaticArrayLiteral () { }
  StaticDataBase *clone () const { return new StaticArrayLiteral (value); }
  virtual bool is_array_literal_value () const { return true; }
};

// Union which either stores an integer, an double value or an array literal
struct StaticDataType
{
  StaticDataBase *value_p;

  // Contructor. Default is NO array literal value.
  StaticDataType () { value_p = NULL; }
  StaticDataType (const lint v) { value_p = new StaticLint (v); }
  StaticDataType (const double v) { value_p = new StaticDouble (v); }

  StaticDataType (const StaticDataType &v) 
  {
    if (v.value_p == NULL)
      value_p = NULL;
    else
      value_p = v.value_p->clone ();
  }

  StaticDataType &operator = (const StaticLint &v) 
  {
    if (value_p != NULL)
      delete value_p;
    value_p = v.clone ();

    return *this;
  }

  StaticDataType &operator = (const StaticDouble &v) 
  {
    if (value_p != NULL)
      delete value_p;
    value_p = v.clone ();

    return *this;
  }

  // Cleanup instance. 
  ~StaticDataType ()
  {
    if (value_p != NULL)
      delete value_p;
    value_p = NULL;
  }

  lint &long_value () 
  {
    if (value_p == NULL) value_p = new StaticLint;
    return value_p->long_value (); 
  }
  double &double_value () 
  { 
    if (value_p == NULL) value_p = new StaticDouble;
    return value_p->double_value (); 
  }
  // If an array literal is requested then check whether the array
  // literal pointer is valid. If not then allocate stroage to hold an
  // array literal.
  vector<int> &array_literal_value ()
  {
    if (value_p == NULL) value_p = new StaticArrayLiteral;
    return value_p->array_literal_value ();
  }

  string original_string () const { assert (value_p != NULL); return value_p->original_string (); }

  bool is_long_value () const { return value_p == NULL? false : value_p->is_long_value (); }
  bool is_double_value () const { return value_p == NULL? false : value_p->is_double_value (); }
  bool is_array_literal_value () const { return value_p == NULL? false : value_p->is_array_literal_value (); }
};

struct mypool:vaul_pool
{
  mypool ();
  vaul_design_unit *get (char *library, char *name);
  v2cc_mapper *mapper;
  FILE *dependencies_file;
};


// Some constants to control handling of internal variables generated
// by the code generator
#define DECLARE_LOCALLY 0	// Declare locally
#define DECLARE_AND_INIT 1	// The object shall be declared and directly initialized
#define DECLARE_GLOBALLY 2	// The items should be declared as a global object
#define INIT_ONLY 4		// Do not declare but initialize object

// Size of various VHDL data types in bytes
#define ENUM_SIZE 1

// Main parser node
extern mypool vaul;


// ****************************************************************************
// * Definition of AccessDescriptor
// ****************************************************************************
// An AccessDescriptor instance stores information about the objects,
// functions and types that are accessed within the VHDL source.
struct AccessDescriptor
{
  // points to the declaration (object, function or type declaration) 
  pIIR_Declaration declaration;
  // stores what kind of operations/usage has been performed on a
  // specific object. E.g, read, written, sensed...
  AccessFlags access_type;
  // level the object is located at. The entire statement is assigned
  // level 0. The level is increased each time an object is included
  // in an argument to a subroutine or an index value of an array
  // reference.
  int level;
  // points to the part of the expression which references the
  // object/function
  pIIR_Expression access_expr;

  // Test whether the declaration matches a specific tree_kind
  bool is (const tree_kind a)
  {
    return declaration->is (a);
  }

  AccessDescriptor ()
  {
    declaration = NULL;
    access_expr = NULL;
    access_type = AccessFlags ();
    level = 0;
  }

  AccessDescriptor (pIIR_ObjectDeclaration decl, pIIR_Expression ae,
		    AccessFlags at = READ, int l = 0)
  {
    declaration = decl;
    access_expr = ae;
    access_type = at;
    level = l;
  };

  AccessDescriptor (pIIR_FunctionDeclaration fdecl, pIIR_Expression ae,
		    AccessFlags at = FUNCTION_CALL, int l = 0)
  {
    declaration = fdecl;
    access_expr = ae;
    access_type = at;
    level = l;
  };

  AccessDescriptor (pIIR_ProcedureDeclaration pdecl, 
		    AccessFlags at = PROCEDURE_CALL, int l = 0)
  {
    declaration = pdecl;
    access_expr = NULL;
    access_type = at;
    level = l;
  };

  AccessDescriptor (pIIR_TypeDeclaration tdecl, AccessFlags at = TYPE_USED)
  {
    declaration = tdecl;
    access_expr = NULL;
    access_type = at;
    level = 0;
  };

  AccessDescriptor (const AccessDescriptor & sacs)
  {
    declaration = sacs.declaration;
    access_expr = sacs.access_expr;
    access_type = sacs.access_type;
    level = sacs.level;
  };

  AccessDescriptor & operator = (const AccessDescriptor & sacs)
  {
    declaration = sacs.declaration;
    access_expr = sacs.access_expr;
    access_type = sacs.access_type;
    level = sacs.level;
    return *this;
  };
};


typedef list < AccessDescriptor > access_list;
typedef AccessDescriptor *pAccessDescriptor;


// Stores a list of tree_kind values
class tree_kind_list:public vector < tree_kind >
{
public:
  tree_kind_list ()
  {
  };
  tree_kind_list (const tree_kind a)
  {
    push_back (a);
  }
  tree_kind_list (const tree_kind a, const tree_kind b)
  {
    push_back (a);
    push_back (b);
  }
  tree_kind_list (const tree_kind a, const tree_kind b, const tree_kind c)
  {
    push_back (a);
    push_back (b);
    push_back (c);
  }
  tree_kind_list & operator << (const tree_kind a)
  {
    push_back (a);
    return *this;
  }
  bool matches (const pIIR_Declaration decl) const
  {
    for (const_iterator iter = begin (); iter != end (); iter++)
      if (decl->is (*iter))
	return true;
    return false;
  }
};


// function generates a new list from an access_list which only
// includes items that matche the access_type and the
// object_kind. Example: filter(lst, WRITE, IR_SIGNAL_DECLARATION)
// will create a new list from lst where only written signals are
// inlcuded.
inline list < AccessDescriptor >
filter (list < AccessDescriptor > &lst, const AccessFlags access_type,
	const tree_kind_list & object_kind)
{
  list < AccessDescriptor > result;

  for (list < AccessDescriptor >::iterator it = lst.begin ();
       it != lst.end (); it++)
    if (((*it).access_type & access_type)
	&& object_kind.matches ((*it).declaration))
      result.push_back (*it);

  return result;
}


// same as filter besides that no items with the same member
// "declaration" will appear more than once on the list
inline list < AccessDescriptor >
filter_unique (list < AccessDescriptor > &lst, const AccessFlags access_type,
	       const tree_kind_list & object_kind)
{
  list < AccessDescriptor > result;
  set < pIIR_Declaration, less < void *> > obj_set;

  for (list < AccessDescriptor >::iterator it = lst.begin ();
       it != lst.end (); it++)
    if (((*it).access_type & access_type)
	&& object_kind.matches ((*it).declaration)
	&& obj_set.find ((*it).declaration) == obj_set.end ())
      {
	result.push_back (*it);
	obj_set.insert ((*it).declaration);
      }

  return result;
}


// function generates a new list from an pIIR_DeclarationList where
// only elements which matches the object node kinds stored in
// object_kind are selected.
inline list < pIIR_Declaration >
filter_unique (pIIR_DeclarationList lst_begin,
	       const tree_kind_list & object_kind)
{
  list < pIIR_Declaration > result;
  set < pIIR_Declaration, less < void *> > obj_set;

  for (pIIR_DeclarationList lst = lst_begin; lst; lst = lst->rest)
    if (object_kind.matches (lst->first) &&
	obj_set.find (lst->first) == obj_set.end ())
      {
	result.push_back (lst->first);
	obj_set.insert (lst->first);
      }

  return result;
}



// ****************************************************************************
// * Definition of struct ConetxtInfo
// ****************************************************************************
// A "ContextInfo" object is used to store data required by the code
// generator
struct ContextInfo
{
  list < AccessDescriptor > accessed_objects;	// accessed objects
  list < pIIR_SequentialStatement > wait_statements;	// wait statements
  list < pIIR_SignalAssignmentStatement > signal_assignment_statements;	// signal assignements
  list < AccessDescriptor > extra_interface_objects;	// additional interface parameter
  void clear ()
  {
    accessed_objects.clear ();
    wait_statements.clear ();
    signal_assignment_statements.clear ();
    extra_interface_objects.clear ();
  }
};

typedef ContextInfo *pContextInfo;


struct RegionStack:public deque < pIIR_DeclarativeRegion >
{
  void push (pIIR_DeclarativeRegion r)
  {
    push_back (r);
  }
  void pop ()
  {
    pop_back ();
  }
};


inline char *
to_chars (const AccessDescriptor & a)
{
  return a.declaration->declarator->text.to_chars ();
}


// ****************************************************************************
// * Definition of struct StaticRangeDescriptor
// ****************************************************************************
// class to store static range information. 
template<class T, class R>
struct StaticRangeDescriptor
{
  // left bound, right bound and range direction
  T left, right; R dir;
  // Contains three elementes, whether the first element is true of
  // left is valid, the second element is true if dir is static and
  // the right element is true if right is static.
  vector<bool> valid;
  StaticRangeDescriptor () 
  {
    valid.resize (3);
    fill (valid.begin (), valid.end (), true);
  };
  StaticRangeDescriptor (const T l, const R d, const T r) :
    left (l), right (r), dir (d)
  {
    valid.resize (3);
    fill (valid.begin (), valid.end (), true);
  };
  StaticRangeDescriptor (const StaticRangeDescriptor &a) :
    left (a.left), right (a.right), dir (a.dir), valid (a.valid) {};
  StaticRangeDescriptor &operator = (const StaticRangeDescriptor &a) 
  {
    left = a.left;
    dir = a.dir;
    right = a.right;
    valid = a.valid;
    return *this;
  };
  bool operator == (const StaticRangeDescriptor &a)  const
  {
    if (!and_reduce(valid) || !and_reduce(a.valid)) return false;
    return (left == a.left) && (dir == a.dir) && (right == a.right);
  }
};


struct StaticRangeDescriptor_lint_Less : 
  public binary_function <StaticRangeDescriptor<lint, IR_Direction>,
			  StaticRangeDescriptor<lint, IR_Direction>,
			  bool>
{
  bool operator () (const StaticRangeDescriptor<lint, IR_Direction> &a,
		    const StaticRangeDescriptor<lint, IR_Direction> &b)
    {
      // If not both ranges are static then return false
      if (! and_reduce (a.valid) ||
	  ! and_reduce (b.valid))
	return false;
      // Next, check out whether some of the ranges are null ranges
      const bool null_range = a.dir == IR_DIRECTION_UP? 
	a.left > a.right : a.left < a.right;
      const bool a_null_range = b.dir == IR_DIRECTION_UP? 
	b.left > b.right : b.left < b.right;
      if (null_range || a_null_range)
	return null_range;
      // Finally, compare ranges
      const lint min_a = min (a.left, a.right);
      const lint min_b = min (b.left, b.right);
      return min_a != min_b ? min_a < min_b : 
	max (a.left, a.right) < max (b.left, b.right);
    }
};


// Compare function required to build maps where
// StaticRangeDescriptor<lint, IR_Direction> is a key! Note that the
// ranges are not really compared. The function just defines some kind
// of order among a set of StaticRangeDescriptor<lint, IR_Direction>
// elements.
inline bool 
operator < (const StaticRangeDescriptor<lint, IR_Direction> &a,
	    const StaticRangeDescriptor<lint, IR_Direction> &b)
{
  if (a.left < b.left) 
    return true;
  else if (a.left == b.left)
    if (a.dir == IR_DIRECTION_DOWN && 
	b.dir != IR_DIRECTION_UP)
      return true;
    else if (a.dir == b.dir &&
	     a.right < b.right)
      return true;
    return false;
}


// ****************************************************************************
// * Definition of struct RangeDescriptor
// ****************************************************************************
// class to store range information. Range information is either given
// as an "explicit" range by specifying left border, right border and
// direction or derived from an array instance via the attributes
// RANGE or REVERSE_RANGE.
class RangeDescriptor
{
public:
  // Members used to store "explicit" ranges
  pIIR_Root left, right;
  IR_Direction direction;
  // Member stores an array attribtute range expression. If this
  // pointer is not equal to NULL then an range attribute expression
  // is stored by the current range descriptor.
  pIIR_ArrayRange range_attribute;
  // Static level of the instance
  IR_StaticLevel static_level;

    RangeDescriptor ()
  {
    left = right = NULL;
    direction = IR_DIRECTION_UP;
    range_attribute = NULL;
    static_level = IR_NOT_STATIC;
  }
  // Create range descriptor from "explitit" range
  RangeDescriptor (pIIR_Root l, IR_Direction d, pIIR_Root r,
		   IR_StaticLevel slevel)
  {
    left = l;
    right = r;
    direction = d;
    static_level = slevel;
    range_attribute = NULL;	// Flag explicit range
  }
  // Create range descriptor from array attribute RANGE or
  // REVERSE_RANGE
  RangeDescriptor (pIIR_ArrayRange ar)
  {
    left = right = NULL;
    direction = IR_DIRECTION_UP;
    range_attribute = ar;	// Store RANGE attribute node
    static_level = IR_NOT_STATIC;
  }
  // Copy constructor
  RangeDescriptor (const RangeDescriptor & r)
  {
    left = r.left;
    right = r.right;
    direction = r.direction;
    static_level = r.static_level;
    range_attribute = r.range_attribute;
  }
  // Destructor. Nothing to do.
  ~RangeDescriptor ()
  {
  };
  // Returns true if range r and the current instance cover the same
  // range
  bool is_equal_to (const RangeDescriptor & r);
  // Returns true if range is "explicit"
  bool is_explicit_range ()
  {
    return left != NULL && right != NULL;
  }
  // Convert a RangeDescriptor into corresponding integer values and
  // the direction. A boolean vector is returned where each item stores
  // whether the corresponding bound could be statically determined
  // (true).
  StaticRangeDescriptor<lint, IR_Direction> 
    rangedes_to_lint (RegionStack & rstack);
  // Convert a RangeDescriptor into corresponding double values and
  // the direction. A boolean vector is returned where each item stores
  // whether the corresponding bound could be statically determined
  // (true).
  StaticRangeDescriptor<double, IR_Direction> 
    rangedes_to_double (RegionStack & rstack);
  // Convert a RangeDescriptor into corresponding integer value
  // strings and the direction strings. If a bound is not locally
  // static then appropriate code is emitted to extract the
  // corresponding values from the object. A boolean vector is
  // returned where each item stores whether the corresponding bound
  // could be statically determined (true).
  StaticRangeDescriptor<string, string> 
    rangedes_to_string (RegionStack & rstack, id_type t);
  // Same as previos method. However, string are generated according
  // to CDFG rules.
  StaticRangeDescriptor<string, string> 
    cdfg_rangedes_to_string (RegionStack & rstack, id_type t);
  // Returns Attribute node
  pIIR_ArrayRange get_attribute_range ()
  {
    return range_attribute;
  };
  // Constant fold
  int constant_fold_rangedes (RegionStack & rstack);
};


// ****************************************************************************
// * Definition of VHDLOperators (singleton class)
// ****************************************************************************
// Is used to convert VHDL operator calls to C++ code
class VHDLOperators
{
 public: 
  static VHDLOperators *get_instance ();
  
 protected:
  VHDLOperators ();

 private:
  static VHDLOperators *single_instance;
  
  typedef map < string, string, less < string > >MapString2;

  // Stores macros to generate code for predefined unary and binary
  // operators. The variables are associative arrays indexed by the VHDL
  // operator name. Example: "unary_operator_macro[string("\"and\"")]"
  // will return the string "(%s&&%s)". The returned string may be used as
  // a format string for a "sprintf" function.
  MapString2 unary_operator_macro;
  MapString2 binary_operator_macro;

  // C++ operator function names for arrays
  MapString2 unary_array_operator_macro;
  MapString2 binary_array_operator_macro;
  
  // C++ names of user defined operator functions
  MapString2 unary_user_operator_name;
  MapString2 binary_user_operator_name;

  void init_operator_macros();
  void init_array_operator_macros();
  void init_user_operator_names();

 public:
  /* Generate string for a call to a binary operator */
  string get_operator_call_string(pIIR_FunctionDeclaration fd, const string arg1, const string arg2);
  /* Generate string for a call to a unary operator */
  string get_operator_call_string(pIIR_FunctionDeclaration fd, const string arg1);
  // Generated code to concat two arrays
  string get_concat_operator_call_string(pIIR_FunctionCall fc, string &arg1, string &arg2, RegionStack &rstack);
  /* Get unary operator name string */
  string get_unary_user_operator_name (const string &str);
  /* Get unary operator name string */
  string get_binary_user_operator_name (const string &str);
  /* Test whether operator name denotes contat operator */
  bool is_concat_operator (const string &str);
};




// ****************************************************************************
// * Globally defined functions
// ****************************************************************************
extern int constant_fold (RangeDescriptor & r, RegionStack & rstack);
void emit_sig_interfacecon (pIIR_SignalInterfaceDeclaration s,
			    string & str, RegionStack & rstack, int l);
void emit_generic_interfacecon (pIIR_ConstantInterfaceDeclaration s,
				string & str, RegionStack & rstack, int l);
void emit_handle (pIIR_ArchitectureDeclaration a, string & str);
string sprint_acl (list < pair < pIIR_Expression, pIIR_Root > >&acl_expr_list,
		   const string acl_object, RegionStack & rstack,
		   id_type t = id_type ());
string sprint_object_reference(pIIR_ObjectDeclaration obj, 
			       vector<StaticRangeDescriptor<lint, IR_Direction> > &static_range_vec,
			       RegionStack &rstack);
int get_acl_size (list < pair < pIIR_Expression, pIIR_Root > > &acl_expr_list);
vector < pair < pIIR_Type, pIIR_Type > > get_types 
  (list < pair < pIIR_Expression, pIIR_Root > > &acl_expr_list, const pIIR_Type type);
void emit_constructor (pIIR_ArchitectureDeclaration a, string & str,
		       RegionStack & rstack);
void emit_decls (pIIR_DeclarationList decl_list, string & str,
		 RegionStack & rstack, int l);
void emit_process_body (pIIR_ProcessStatement p, string & str,
			RegionStack & rstack, int l);
bool emit_associations (string & str, RegionStack & rstack,
			pIIR_AssociationList assocs,
			pIIR_InterfaceList formals);

#endif
