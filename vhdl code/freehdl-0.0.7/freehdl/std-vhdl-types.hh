#ifndef FREEHDL_STD_VHDL_TYPES_H
#define FREEHDL_STD_VHDL_TYPES_H

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>
#include <string.h>

#include <freehdl/std-memory.hh>
#include <freehdl/kernel-error.hh>
#include <freehdl/kernel-acl.hh>

using namespace std;

typedef long long int lint;
const int BUFFER_STREAM_SIZE_INCREMENT = 1024;

// replaces ostrstream in order to speedup simulation. Furhter, this
// stream can also handle raw binary data, i.e., data which may
// contain 0 as an element!
class buffer_stream
{
public:
  char* buffer;
  char* end_of_buffer;
  char* pos_cursor;

  void resize()
    {
      int size = end_of_buffer - buffer; 
      int fill_count = pos_cursor - buffer;
      buffer = (char*)realloc(buffer, size + BUFFER_STREAM_SIZE_INCREMENT);
      end_of_buffer = buffer + size + BUFFER_STREAM_SIZE_INCREMENT;
      pos_cursor = buffer + fill_count;
    }

  //constructor
  buffer_stream(){
    buffer = end_of_buffer = pos_cursor = NULL;
    resize();
    buffer [0] = '\0';
  }

  //desconstructor
  ~buffer_stream()
  { 
    if (buffer != NULL) 
      free (buffer); 
  }

  // Write binary data to stream. Note that after writing binary data
  // to the stream the buffer usually is NOT ended with 0 !
  buffer_stream& binary_write(const void *src, const int len) {
    while (pos_cursor + len >= end_of_buffer)
      resize();
    memcpy(pos_cursor, src, len);
    pos_cursor += len;
    return *this;
  }

  // output operator
  buffer_stream& operator<<(const char* c)  { 
    const int len = strlen(c);
    if (pos_cursor + len >= end_of_buffer)
      resize();
    strcpy(pos_cursor, c);
    pos_cursor += len;
    return *this;
  }

  buffer_stream& operator<<(const char c) { 
    if (c != '\0') {
      if (pos_cursor + 2 >= end_of_buffer)
	resize();
      *(pos_cursor++) = c;
    }
    *pos_cursor = '\0';
    return *this;
  }

  buffer_stream& operator<<(const int i) { 
    // An int converted to decimal will never have more than 12
    // characters
    char ibuffer[13];
    char *cursor = ibuffer + 12;
    int l;
    *(cursor--) = '\0';
    if (i > 0) {
      l = i;
      while (l > 0) {
	int new_l = l / 10;
	int diff = l - (new_l << 3) - (new_l << 1);
	*(cursor--) = (char)diff + '0';
	l = new_l;
      } 
    } else if (i < 0) {
      l = -i;
      while (l > 0) {
	int new_l = l / 10;
	int diff = l - (new_l << 3) - (new_l << 1);
	*(cursor--) = (char)diff + '0';
	l = new_l;
      } 
      *(cursor--) = '-';
    } else
      *(cursor--) = '0';

    if (pos_cursor + 30 >= end_of_buffer)
      resize();
    strcpy(pos_cursor, cursor+1);
    pos_cursor += ibuffer + 12 - cursor - 1;

    return *this;
  }

  buffer_stream& operator<<(const lint i) {
    // An lint converted to decimal will never have more than 30
    // characters
    char ibuffer[31];
    char *cursor = ibuffer + 30;
    lint l;
    *(cursor--) = '\0';
    if (i > 0) {
      l = i;
      while (l > 0) {
	lint new_l = l / 10;
	lint diff = l - (new_l << 3) - (new_l << 1);
	*(cursor--) = (char)diff + '0';
	l = new_l;
      } 
    } else if (i < 0) {
      l = -i;
      while (l > 0) {
	lint new_l = l / 10;
	lint diff = l - (new_l << 3) - (new_l << 1);
	*(cursor--) = (char)diff + '0';
	l = new_l;
      } 
      *(cursor--) = '-';
    } else
      *(cursor--) = '0';

    if (pos_cursor + 30 >= end_of_buffer)
      resize();
    strcpy(pos_cursor, cursor+1);
    pos_cursor += ibuffer + 30 - cursor - 1;

    return *this;
  }

  buffer_stream& operator<<(string& s) {
    return *this << s.c_str();   
  }

  buffer_stream& operator<<(const double i) {
    char ibuffer[40];
    sprintf(ibuffer,"%e",i);
    return *this << ibuffer;
  }
  
  int str_len() {
    return (int)(pos_cursor - buffer);
  }

  void init(char* pos_cursor){ 
    if(pos_cursor == end_of_buffer) 
      buffer =(char*)realloc((void*)buffer, 1024);
  }

  //clean function
  void clean(){ pos_cursor = buffer; };
  void reinit() { 
    if (buffer != NULL)
      free (buffer); 
    end_of_buffer = buffer = pos_cursor = NULL;
    resize();
  }
  char *str() { return buffer; }
};



/* *************************************************************
 *  Type-Ids for the different VHDL type groups 
 * ************************************************************* */
typedef unsigned char type_id;
#define INTEGER 1
#define ENUM 2
#define FLOAT 3
#define PHYSICAL 4
#define RECORD 5
#define ARRAY 6
#define ACCESS 7
#define VHDLFILE 8

inline bool scalar(type_id id)
{
  switch (id) {
  case RECORD:
  case ARRAY:
    return false;
  default:
    return true;
  }
}

/* *************************************************************
 *  Typedefs
 * ************************************************************* */
typedef long long int lint;
typedef unsigned char uchar;


/* *************************************************************
 *  Logartihmus dualis of the sizes of VHDL types (in Bytes)
 * ************************************************************* */
#define INTEGER_SIZE sizeof(integer) 
#define ENUM_SIZE sizeof(enumeration)
#define FLOAT_SIZE sizeof(floatingpoint)
#define PHYSICAL_SIZE sizeof(physical)
/* HACK: see below */
#define RECORD_SIZE (2*sizeof(void*))
/* HACK: an array instance actually consists of two pointers (not
 * including memory for info and data instances). We cannot use
 * sizeof(array_base) here as array_base will be defined at the end of
 * this file while ARRAY_SIZE is used before! */
#define ARRAY_SIZE (2*sizeof(void*))  
#define ACCESS_SIZE sizeof(void*)
#define VHDLFILE_SIZE sizeof(iostream*)

#define INTEGER_SIZE_LD 32


/* *************************************************************
 *  All VHDL integer types are actually C ints
 * ************************************************************* */
typedef int integer;

/* Always returns the id of the type. The parameter is actually not
 * needed but used to select the appropriate function id. */
inline type_id id(integer *d) {  return INTEGER; }

/* Actually does nothing */
inline void cleanup(integer *d) { };

/* mod operator */
inline integer op_mod(const integer a, const integer b) { 
  register int tmp = a % b;
  return ((b^tmp) < 0)? tmp + b : tmp; 
}

/* power operator */
inline integer op_power(const integer a, const integer b) { 
  return (integer)pow((double)a, (double)b);
}

/* absolute operator */
inline integer op_abs (const integer a) { return abs (a); }

/* *************************************************************
 *  All VHDL access type are actually void pointer
 * ************************************************************* */
typedef void * vhdlaccess;

/* Always returns the id of the type. The parameter is actually not
 * needed but used to select the appropriate function id. */
inline type_id id(vhdlaccess *d) {  return ACCESS; }

/* Actually does nothing */
inline void cleanup(vhdlaccess *d) { };


/* *************************************************************
 *  All VHDL enumeration types are actually C chars
 * ************************************************************* */
typedef unsigned char enumeration;

/* Always returns the id of the type. The parameter is actually not
 * needed but used to select the appropriate function id. */
inline type_id id(enumeration *d) {  return ENUM; }

/* Actually does nothing */
inline void cleanup(enumeration *d) { };


/* *************************************************************
 *  All VHDL floating point types are actually C doubles
 * ************************************************************* */
typedef double floatingpoint;

/* Always returns the id of the type. The parameter is actually not
 * needed but used to select the appropriate function id. */
inline type_id id(floatingpoint *d) {  return FLOAT; }

/* Actually does nothing */
inline void cleanup(floatingpoint *d) { };

/* power operator */
inline floatingpoint op_power(const floatingpoint a, const integer b) { 
  return pow(a, (double)b);
}

/* absolute operator */
inline floatingpoint op_abs (const floatingpoint a) { 
  return (floatingpoint)fabs (a); 
}

/* *************************************************************
 *  All VHDL physical types are actually long long ints (64 bit)
 * ************************************************************* */
typedef lint physical;

/* Always returns the id of the type. The parameter is actually not
 * needed but used to select the appropriate function id. */
inline type_id id(physical *d) {  return PHYSICAL; }

/* Actually does nothing */
inline void cleanup(physical *d) { };

/* absolute operator */
inline physical op_abs (const physical a) { 
  return (a >= 0)? a : -a; 
}


/* *************************************************************
 *  VHDL file types
 * ************************************************************* */
struct vhdlfile {
  bool do_close; // Is true if the stream must be closed manually
  istream *in_stream;
  ostream *out_stream;
  vhdlfile() { in_stream = NULL; out_stream = NULL; do_close = false; }
  ~vhdlfile() { 
    if (do_close) return;
    if (in_stream != NULL) delete in_stream; 
    if (out_stream != NULL) delete out_stream; 
    in_stream = NULL;
    out_stream = NULL;
  }
};

/* Always returns the id of the type. The parameter is actually not
 * needed but used to select the appropriate function id. */
inline type_id id(vhdlfile *d) {  return VHDLFILE; }

/* Actually does nothing */
inline void cleanup(vhdlfile *d) { };



/* *************************************************************
 *  Some functions for composite types
 * ************************************************************* */

/* Function to call the cleanup operator of the appropriate array
   instance */
template<class A>
void cleanup(A *p) { p->cleanup_instance(); }


/* *************************************************************
 *  Some operators
 * ************************************************************* */

/* not operator */
inline enumeration op_not(const enumeration a) { 
  return a ? 0 : 1; 
}

/* nand operator */
inline enumeration op_nand(const enumeration a, const enumeration b) {
  return op_not(a & b);
}

/* xor operator */
inline enumeration op_xor(const enumeration a, const enumeration b) {
  return a ^ b;
}

/* xnor operator */
inline enumeration op_xnor(const enumeration a, const enumeration b) {
  return op_not(op_xor(a, b));
}

/* nor operator */
inline enumeration op_nor(const enumeration a, const enumeration b) {
  return a | b ? 0 : 1;
}


/* *************************************************************
 *  Some functions of global interest
 * ************************************************************* */

/* Returns true if value is in between left and right */
template<class T>
inline bool check_bounds(const T &left, const T &right, const T &value) {
  if (left <= right) 
    return left <= value && value <= right;
  else 
    return left >= value && value >= right;
}

#if !(!defined __GNUC__ || __GNUC__ != 2)
template<class T>
inline T min(const T old_value, const T new_value) { 
  return new_value < old_value? new_value : old_value; 
}

template<class T>
inline T max(const T old_value, const T new_value) { 
  return new_value > old_value? new_value : old_value; 
}
#endif

/* Determine length of range */
template<class T>
inline T
range_to_length(T le, range_direction r, T ri)
{
  if (r == to)
    return le <= ri? (ri - le + (T)1) : (T)0;
  else
    return ri <= le? (le - ri + (T)1) : (T)0;
}


template<class T>
inline T
up_range_to_length(T le, T ri)
{
  return le <= ri? (ri - le + (T)1) : (T)0;
}


template<class T>
inline T
down_range_to_length(T le, T ri)
{
  return ri <= le? (le - ri + (T)1) : (T)0;
}


/* Rotate left value by count bits. Should be mapped to the
 * corresponding rotate left machine instruction by the C++ compiler! */
inline unsigned int
rotate_left(unsigned int value, int count)
{
  return (value << count) | (value >> (sizeof(unsigned int) * 8 - count));
} 


/* This function is used to select an appropriate alternative of an
 * VHDL case statement where the selection expression is an array of
 * characters */
inline int
do_case_select(const int size, const int key_count, const unsigned int key, 
	       const unsigned int* const sel, const unsigned int* const keys, 
	       const int* const key_to_lit, const enumeration** const lit_tab, 
	       const int* const actions) 
{
  // Try to find a key in the key table which matches the key value
  // calculated from the selection expression
  for (int i = 0; i < key_count; i++)
    if (key == keys[i]) {
      // If a key was found then we use the index number of the key to
      // access a table which stores for each key a list of pointer to
      // array literals. Note that all these array literals are
      // associated with the *same* key.
      i = key_to_lit[i];
      do {
	// Compare the current selection array litaral with all those
	// literals associated with the specific key (note that there
	// may be more than one literal). If a match is found then use
	// the index number to access an action table which stores the
	// corresponding action number. Return the action number.
	if (!memcmp(sel, lit_tab[i], size * sizeof(enumeration)))
	  return actions[i];
      } while (lit_tab[++i] != 0);
      break;
    }

  // If no match was found then return the default action number
  return -1;
}


/* Returns address of object passed over as a parameter */
template<class T>
inline const void *
const_pointer(const T &a) { return &a; }


/* Casts void pointer to type T and derefs it */
template<class T>
inline T
deref(void *p) { return *(T*)p; }


/* *************************************************************
 *  Definitions required for signal resolution
 * ************************************************************* */

// resolver_handler_p is a pointer type to a function which will be
// called by the kernel ro perform signal reolution. The first
// parameter points to a object which shall take the result of a
// resolving operation while the second parameter points to array
// containing the driver values to be resolved. The last parameter
// points to the unconstrained array_info.
class array_base;
class array_info;
class driver_info;
typedef void (*resolver_handler_p)(void*, driver_info*, array_base*, array_info*);



/* *************************************************************
 *  The type info interface class is te base class for all 
 *  derived type info classes 
 * ************************************************************* */
class type_info_interface {
public:
  const type_id id;
  const uchar size; /* size of an object that corresponds with the
		     * type_info_instance */
  bool resolved; /* set to true if the type is resolved. Note that the
		  * type_infos do NOT store any further information to
		  * support the resolving mechanism as these infos are
		  * used by the kernel only. Instead, the kernel
		  * collects and stores all necessary information. */

  type_info_interface(const type_id i, const uchar s) : 
    id(i), size(s), resolved(false) {};
  virtual ~type_info_interface() {};
  // Returns true if the current info instance describes a scalar type
  inline bool scalar();
  
  // Prints value of instance (src is pointing to) into a char
  // buffer and returns a pointer to the buffer. Note, the buffer
  // is static! Hence, each call to str uses the SAME buffer!
  char *str(const void *src);
  
  // Copy the content of src to dest. Note can be used
  // for scalar VHDL objects only!
  inline void *fast_copy(void *dest, const void *src);
  // Compare the content of src and dest. Note: can be used
  // for scalar VHDL objects only!
  inline bool fast_compare(const void *dest, const void *src);
  // Assigns the content of src and dest. Note: can be used
  // for scalar VHDL objects only! Returns true if the new
  // value differs from the old one.
  inline bool fast_assign(void *dest, const void *src);

  // Gets left and right bounds of an enumeration, integer or array
  // type and returns 0. Returns -1 if type is no enumeration, integer
  // or array type.
  int get_bounds(int &left, range_direction &range, int &right);

  // Create a new object. Memory is allocated by malloc
  virtual void *create() = 0;
  // Clone a object. Memory is allocated by malloc
  virtual void *clone(const void *src) = 0;
  // Copy the content of src to dest
  virtual void *copy(void *dest, const void *src) = 0;
  // Initiliazes an instance
  virtual void init(void *src) = 0;
  // Frees additional memory occupied by an object.
  virtual void clear(void *src) {};
  // Compare src1 with src2. Returns true if they are equal
  virtual bool compare(const void *src1, const void *src2) = 0;
  // Copy the content of src to dest. Returns true if the new
  // value differs from the old one
  virtual bool assign(void *dest, const void *src) = 0;
  // Removes an object (frees memory)
  virtual void remove(void *src) = 0;
  // This method does nothing for scalar types. For non-scalar types
  // it assumes that src points to allocated memory that contains
  // garbage. Hence, the method does *not* try to read the conent
  // stored in *src.
  void reset (void *src);
  // Returns the address of an appropriate subelement of the current
  // object. acl is the "path" to the subelement. Note that element
  // returns the address of the left element in case of a "range"
  // (slice) is applied onto an array.
  virtual void *element(void *src, acl *a) { return src; }
  // Returns the address of an appropriate subelement of
  // the current object. i is the index number of the subelment.
  void *element(void *src, int i);
  // Convert acl to index start and end. Returns start value
  int acl_to_index(acl *a, int &start, int &end) const;
  // Convert acl to index start
  int acl_to_index(acl *a) const;
  // Get info instance of scalar element with index i
  type_info_interface *get_info(int i) const;
  // Return info instance of element determined by acl a. src is an
  // optional pointer to an object.
  type_info_interface *get_info(void *src, acl *a) const;
  // Returns the number of scalar elements of the current object
  virtual int element_count() { return 1; }
  // Prints the content of src into an string stream
  virtual void print(buffer_stream &str, const void *src, int mode) = 0;
  // Reads a value from a string and stores it into *dest. Further, in
  // case of an error the function returns a pointer to the character
  // which caused the failure or NULL otherwise.
  virtual const char *read(void *dest, const char *str) = 0;
  // Prints the content of src into an string stream in VCD format
  virtual void vcd_print(buffer_stream &str, const void *src,char* translation_table, bool pure) = 0;
  // Prints value into binary stream. Note that only the raw data but
  // no type info objects are written! The method returns the number
  // of bytes written to the stream.
  int binary_print(buffer_stream &str, const void *src);
  // Reads value from memory (str) and puts the values into dest. The
  // sequence of the data values must be the same as generated by
  // binary_print. Note that only the raw data but no type info objects
  // are read! Hence, the dest pointer must point to valid object of the
  // appropriate size! Returns the number of bytes read or -1 if the
  // read operation was not successfull.
  int binary_read(void *dest, void *src);
  // Usualy increments/decrements reference counter of type_info
  // instances. However, as these instances are static for all
  // but composite types both function actually do noting. Note
  // that the corresponding methods are overloaded by the array_info
  // and record_info classes. 
  virtual void add_ref() { };
  virtual void remove_ref() { };
  // Add a resolver handler (required by the kernel to perform signal
  // resolution) to a type. Returns a reference to the current info
  // instance. handler points to a function which is used by the
  // kernel to perform the resolution mechanism. ainfo points to a
  // corresponding array_info instance describing the driver
  // array. The last parameter stated whether the resolver function
  // must not be called for a single source (ideal = true).
  type_info_interface &add_resolver(resolver_handler_p handler, type_info_interface *ainfo, bool ideal);
  // Register a type
  void register_type(const char *sln, const char *ln, const char *n, void *sr);
};


/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL // This is only required when the kernel is compiled

// Constants to control printing of values via the
// type_info_interface::print method
#define VHDL_PRINT_MODE 0
#define CDFG_PRINT_MODE 1

// Copy the content of src to dest. Note, this method can be used for
// scalar VHDL objects only!
inline void *
type_info_interface::fast_copy(void *dest, const void *src) 
{
  switch (id) {
  case ENUM:
    *(enumeration*)dest = *(enumeration*)src;
    break;
  case INTEGER:
    *(integer*)dest = *(integer*)src;
    break;
  case FLOAT:
  case PHYSICAL:
    *(physical*)dest = *(physical*)src;
    break;
  }
  return dest;
}

// Compare the content of src and dest. Note: can be used
// for scalar VHDL objects only!
inline bool 
type_info_interface::fast_compare(const void *dest, const void *src) 
{
  switch (id) {
  case ENUM:
    return *(enumeration*)dest == *(enumeration*)src;
    break;
  case INTEGER:
    return *(integer*)dest == *(integer*)src;
    break;
  case FLOAT:
  case PHYSICAL:
    return *(physical*)dest == *(physical*)src;
    break;
  }
  return false;
}


// Assigns the content of src and dest. Note: can be used
// for scalar VHDL objects only! Returns true if the new
// value differs from the old one
inline bool 
type_info_interface::fast_assign(void *dest, const void *src) 
{
  switch (id) {
  case ENUM:
    {
      enumeration src_val = *(enumeration*)src, dest_val = *(enumeration*)dest;
      if (src_val != dest_val) {
	*(enumeration*)dest = src_val;
	return true;
      } else return false;
    }
  case INTEGER:
    {
      integer src_val = *(integer*)src, dest_val = *(integer*)dest;
      if (src_val != dest_val) {
	*(integer*)dest = src_val;
	return true;
      } else return false;
    }
  case FLOAT:
  case PHYSICAL: 
    {
      physical src_val = *(physical*)src, dest_val = *(physical*)dest;
      if (src_val != dest_val) {
	*(physical*)dest = src_val;
	return true;
      } else return false;
    }
  }
  return false;
}


inline bool
type_info_interface::scalar()
{
  switch (id) {
  case RECORD:
  case ARRAY:
    return false;
  default:
    return true;
  }
}


// Returns whether info is or includes array types which are not
// constrained. Returns true if no such type or element type was
// found.
bool
is_constrained(type_info_interface *info);

// Create a type instance based on a reference info rinfo and an acl
// a. The acl stores all information which are not included within the
// reference info. E.g., if the reference info is an unconstrained
// array then the acl stores the actual bounds of the array. Note that
// information which can be derived from the reference info is NOT
// stored in the acl!
type_info_interface *
setup_type_info_interface(type_info_interface *rinfo, pacl a);


/******************************************************
 * End of internal kernel definitions    
 ******************************************************/
#endif


/* *************************************************************
 *  Integer info base class
 * ************************************************************* */
class integer_info_base : public type_info_interface {
public:
  integer left_bound, right_bound, low_bound, high_bound;

  integer_info_base();

  integer_info_base(const integer le, const integer ri, 
		    const integer lo, const integer hi);

  integer_info_base &set(integer_info_base *src);
  integer_info_base &set(const integer le, const integer ri, 
			 const integer lo, const integer hi);
  void *create();
  void *clone(const void *src);
  void *copy(void *dest, const void *src);
  void init(void *src);
  bool compare(const void *src1, const void *src2);
  bool assign(void *dest, const void *src);
  void remove(void *src);
  void print(buffer_stream &str, const void *src, int mode);
  void vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure);
  const char *read(void *dest, const char *str);

  integer check(integer value) {
    if (value >= low_bound && value <= high_bound)
      return value;
    else
      error(ERROR_SCALAR_OUT_OF_BOUNDS, this, &value);
    return 0;
  }
};




/* *************************************************************
 *  Access info base class
 * ************************************************************* */
class access_info_base : public type_info_interface {
public:
  type_info_interface *designated_type_info;

  access_info_base();

  access_info_base(type_info_interface *d_info);

  access_info_base &set(type_info_interface *d_info);

  void *create();
  void *clone(const void *src);
  void *copy(void *dest, const void *src);
  void init(void *src);
  bool compare(const void *src1, const void *src2);
  bool assign(void *dest, const void *src);
  void remove(void *src);
  void print(buffer_stream &str, const void *src, int mode);
  void vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure) {};
  const char *read(void *dest, const char *str);
};




/* *************************************************************
 *  File info base class
 * ************************************************************* */
class vhdlfile_info_base : public type_info_interface {
public:
  type_info_interface *type_info;

  vhdlfile_info_base();

  vhdlfile_info_base(type_info_interface *f_info);

  vhdlfile_info_base &set(type_info_interface *f_info);

  void *create();
  void *clone(const void *src);
  void *copy(void *dest, const void *src);
  void init(void *src);
  bool compare(const void *src1, const void *src2);
  bool assign(void *dest, const void *src);
  void remove(void *src);
  void print(buffer_stream &str, const void *src, int mode) {};
  void vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure) {};
  const char *read(void *dest, const char *str);
};




/* *************************************************************
 *  Float  info base class
 * ************************************************************* */
class float_info_base : public type_info_interface {
public:
  floatingpoint left_bound, right_bound, low_bound, high_bound;

  float_info_base();

  float_info_base(const floatingpoint le, const floatingpoint ri, 
		  const floatingpoint lo, const floatingpoint hi);

  float_info_base &set(const floatingpoint le, const floatingpoint ri, 
		       const floatingpoint lo, const floatingpoint hi);
  float_info_base &set(float_info_base *src);
  void *create();
  void *clone(const void *src);
  void *copy(void *dest, const void *src);
  void init(void *src);
  bool compare(const void *src1, const void *src2);
  bool assign(void *dest, const void *src);
  void remove(void *src);
  void print(buffer_stream &str, const void *src, int mode);
  void vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure);
  const char *read(void *dest, const char *str);

  floatingpoint check(floatingpoint value) {
    if (value >= low_bound && value <= high_bound)
      return value;
    else
      error(ERROR_SCALAR_OUT_OF_BOUNDS, this, &value);
    return 0;
  }
};


/* *************************************************************
 *  Enum info base class
 * ************************************************************* */
class enum_info_base : public type_info_interface {
public:
  int left_bound, right_bound, length;
  const char **values;

  enum_info_base();

  enum_info_base(const int le, const int ri, const char **val);

  enum_info_base &set(const int le, const int ri, const char **val);
  enum_info_base &set(enum_info_base *src);
  void *create();
  void *clone(const void *src);
  void *copy(void *dest, const void *src);
  void init(void *src);
  bool compare(const void *src1, const void *src2);
  bool assign(void *dest, const void *src);
  void remove(void *src);
  void print(buffer_stream &str, const void *src, int mode);
  void vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure);
  const char *read(void *dest, const char *str);

  enumeration check(integer value) {
    if (value >= left_bound && value <= right_bound)
      return value;
    else
      error(ERROR_SCALAR_OUT_OF_BOUNDS, this, &value);
    return 0;
  }
};

/* *************************************************************
 *  Physical info base class
 * ************************************************************* */
class physical_info_base : public type_info_interface {
public:
  physical left_bound, right_bound, low_bound, high_bound;
  const char **units;
  const physical *scale;
  int unit_count;
  
  physical_info_base();
  
  physical_info_base(const physical le, const physical ri, 
		     const physical lo, const physical hi,
		     const char **un, const physical *sc, int uc);
  
  physical_info_base &set(const physical le, const physical ri, 
			  const physical lo, const physical hi,
			  const char **un, const physical *sc, int uc);
  physical_info_base &set(physical_info_base *src);
  void *create();
  void *clone(const void *src);
  void *copy(void *dest, const void *src);
  void init(void *src);
  bool compare(const void *src1, const void *src2);
  bool assign(void *dest, const void *src);
  void remove(void *src);
  void print(buffer_stream &str, const void *src, int mode);
  void vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure) ;
  const char *read(void *dest, const char *str);
   
  physical check(physical value) {
    if (value >= low_bound && value <= high_bound)
      return value;
    else
      error(ERROR_SCALAR_OUT_OF_BOUNDS, this, &value);
    return 0;
  }
};


/* *************************************************************
 *  Record info base class
 * ************************************************************* */
class record_info : public type_info_interface {
public:
  int record_size;
  int data_size;
  type_info_interface **element_types;
  void *(*element_addr) (void*, int);
  const char **element_names;

  /* Counts the number of instances which are currently using this
   * record_info object. Hence, several record instances may
   * share a single record_info instance! */
  int ref_counter;

  /* Memory management for record_info instances. */
  void *operator new(size_t s) {  
    return (record_info*)internal_dynamic_alloc(sizeof(record_info));
  }

  void operator delete(void *a) {
    internal_dynamic_remove(a, sizeof(record_info));
  }

  record_info () : type_info_interface(RECORD, RECORD_SIZE) { 
    record_size = -1; data_size = -1; element_types = NULL; element_addr = NULL; element_names = NULL; 
  }
  record_info (int rs, int ds, const char **en, void *(*ea)(void*, int), int rc);
  record_info &set(int rs, int ds, const char **en, void *(*ea)(void*, int), int rc) {
    record_size = rs;
    data_size = ds;
    element_names = en;
    element_addr = ea;
    element_types = (type_info_interface**)internal_dynamic_alloc(record_size * sizeof(type_info_interface*));
    memset(element_types, 0, record_size * sizeof(type_info_interface*));
    ref_counter = rc;

    return *this;
  }

  /* Initialize record info from other record info */
  record_info &set (record_info *info, int rc)
  {
    record_size = info->record_size;
    data_size = info->data_size;
    element_types = info->element_types;
    element_addr = info->element_addr;
    element_names = info->element_names;
    ref_counter = rc;

    return *this;
  }
 
  /* Set info pointer of index "index" to eti */
  record_info &set(int index, type_info_interface *eti) {
    element_types[index] = eti;
    eti->add_ref();
    return *this;
  }

  ~record_info () {

    /* Do not destruct permanent structs at all.  Global objects can
       not be handled reliably since their destructors will be run in
       no particular order and the type_info_interface structs
       referenced by element_types could have been destroyed before
       running this destructor, for example. */

    if (ref_counter < 0)
      return;

    if (element_types)
      {
	for (int i = 0; i < record_size; i++)
	  if (element_types[i] != NULL)
	    element_types[i]->remove_ref();
	
	internal_dynamic_remove (element_types,
				 record_size * sizeof(type_info_interface*));
      }
  }

  /* Returns the number of scalar elements of the current type */
  int element_count() { 
    int count = 0;
    for (int i = 0; i < record_size; i++)
      count += element_types[i]->element_count();
    return count;
  }
  /* Returns the address of an appropriate element of the current
   * object. acl is the "path" to the element */
  void *element(void *src, acl *a);

  /* This method must be called by each array instance which references
   * the current info instance */
  void add_ref() { 
    if (ref_counter >= 0) ref_counter++;
  }
  /* If rec_counter == 0 then no object uses this info instance and
   * it is removed. Note, there are also static info instances which
   * are not removed even when they are not in use. To create a
   * static info instance, array_info is called with parameter -1. */
  void remove_ref() {
    if (ref_counter > 0) {
      ref_counter--;
      if (ref_counter == 0) 
	delete this;
    }
  }

  void *create();
  void *clone(const void *src);
  void *copy(void *dest, const void *src);
  void init(void *src);
  void clear(void *src);
  bool compare(const void *src1, const void *src2) { return false; };
  bool assign(void *dest, const void *src) { return false; };
  void remove(void *src);
  void print(buffer_stream &str, const void *src, int mode);
  void vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure) ;
  const char *read(void *dest, const char *str);
};




/* *************************************************************
 *  Array info class
 * ************************************************************* */

class array_info : public type_info_interface {
public:
  /* Dimension info */
  range_direction index_direction; /* = "to" if index is of enumeration type */
  int left_bound, right_bound;
  int length; /* = -1 if bounds are actually not set (unconstrained array) */

  /* Index type info */
  type_info_interface *index_type;
  
  /* Element info */
  type_info_interface *element_type;

  /* Counts the number of array instances which are currently using  
   * this array_info_base object to define their bounds. Hence, several 
   * array instances may share a single array_info_base instance! */
  int ref_counter;
  
  /* Methods */

  /* Memory management for array_info instances. */
  void *operator new(size_t s) {  
    return (array_info*)internal_dynamic_alloc(sizeof(array_info));
  }

  void operator delete(void *a) {
    internal_dynamic_remove(a, sizeof(array_info));
  }

  /* Default constructor */
  array_info() : type_info_interface(ARRAY, ARRAY_SIZE) 
  { 
    length = -1; 
    element_type = index_type = NULL; 
    ref_counter = 0; 
  }
  /* Destructor */
  ~array_info() {
    /* See ~record_info for additional general comments about
       destructors of global objects. */
    if (ref_counter < 0)
      return;
    if (element_type)
      element_type->remove_ref();
    if (index_type)
      index_type->remove_ref(); 
  }

  /* Constructor. If rc is set to -1 then the array_info instance 
   * will not be removed */
  array_info &set(type_info_interface *et, type_info_interface *it, int rc);
  array_info(type_info_interface *et, type_info_interface *it, int rc);
  /* Constructor to create an info instance for an array subtype */
  /* Set the element info object and the range of the array */
  array_info &set(type_info_interface *et, type_info_interface *it, int le, range_direction r, int ri, int rc = 1) { 
    index_direction = r;
    left_bound = le; 
    right_bound = ri;
    length = (ri - le) * (r == to? 1 : -1);
    length = length < 0? 0 : length + 1;
    ref_counter = rc;
    index_type = it;
    index_type->add_ref();
    element_type = et;
    element_type->add_ref();
    return *this;
  }
  array_info(type_info_interface *et, type_info_interface *it, int le, range_direction r, int ri, int rc);
  /* Constructor to create an info instance where the left bound is
   * determined by base and the right bound is derived from len */
  array_info &set(type_info_interface *et, type_info_interface *it, int len, int rc);
  array_info(type_info_interface *et, type_info_interface *it, int len, int rc);

  /* Set the element info object */
  void set(type_info_interface *et) { element_type = et; element_type->add_ref(); }
  /* This method must be called by each array instance which references
   * the current info instance */
  void add_ref() { 
    if (ref_counter >= 0) ref_counter++;
  }
  /* If rec_counter == 0 then no object uses this info instance and
   * it is removed. Note, there are also static info instances which
   * are not removed even when they are not in use. To create a
   * static info instance, array_info is called with parameter -1. */
  void remove_ref() {
    if (ref_counter > 0) {
      ref_counter--;
      if (ref_counter == 0) 
	delete this;
    }
  }

  // Check an array index value
  int check(int value) {
    if (index_direction == to) {
      if (value >= left_bound && value <= right_bound)
	return value;
    } else
      if (value <= left_bound && value >= right_bound)
	return value;
    error(ERROR_ARRAY_INDEX, this, &value);
  }

  /* The methods named "???_match" are used to test the bounds of the
   * current array_info instance. All methods return a pointer to the
   * current array_info instance. */

  /* Methods to test whether an array_info instances has bounds and
   * direction as defined by a reference array_info instance */
  array_info *exact_match(type_info_interface *test_info);
  /* Methods to test whether an array_info instances has bounds le and
   * ri and direction r */
  array_info *exact_match(int le, range_direction r, int ri);
  /* Methods to test whether an array_info instances has length
   * len */
  array_info *length_match(int len);

  /* Returns the number of scalar elements of the current type */
  int element_count() { return length * element_type->element_count(); }
  /* Returns the address of an appropriate subelement of
   * the current object. acl is the "path" to the subelement */
  void *element(void *src, acl *a);

  void *create();
  void *clone(const void *src);
  void *copy(void *dest, const void *src);
  void init(void *src);
  void clear(void *src);
  bool compare(const void *src1, const void *src2) { return false; };
  bool assign(void *dest, const void *src) { return false; };
  void remove(void *src);
  void print(buffer_stream &str, const void *src, int mode);
  void vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure);
  const char *read(void *dest, const char *str);
};


// Function to cast an type_info_interface pointer to an array_info
// pointer
inline array_info *parray_info(type_info_interface *t) { return (array_info*)t; }



/* *************************************************************
 * The type classes
 * ************************************************************* */


/* *************************************************************
 * Record type class
 * ************************************************************* */

/* Record base class */
class record_base {
public:
  record_info *info; /* Points to the object which stores information
		      * about the current record */
  char *data; /* Pointer to the actual data of the record */

  record_base() { };
  record_base(const record_base &a);
  record_base(record_info *i) { info = i; i->add_ref(); }
  void set_info(record_info *i) {
    if (info != NULL) info->remove_ref();
    info = i;
    i->add_ref();
  }
  static int size() { return RECORD_SIZE; }
};

/* Always returns the id of the type. The parameter is actually not
 * needed but used to select the appropriate function id. */
inline type_id id(record_base *d) {  return RECORD; }


/* E is a structure containing the actual record data */
template<class E> 
class record_type : public record_base {
 public:
  typedef E E_type; /* declare a local type name which is equivalent
		     * to the actual record type */
  /* Method to access record value */
  E &value() { return *(E*)data; }
  /* Method to access record value */
  const E &value() const { return *(E*)data; }
  
  inline void cleanup_instance();
  record_type() {};
  /* init initiliazes an record. The record elements are set to their
   * corresponding default values. */
  record_type &init(type_info_interface *rinfo) { 
    info = (record_info*)rinfo;
    info->add_ref();
    data = (char*)internal_dynamic_alloc(sizeof(E));
    this->value().init(rinfo); 
    return *this;
  }
  /* "p" points to an record instance. The record elements are copied
   * from "p". */
  record_type &init(type_info_interface *rinfo, const void *p) {
    info = (record_info*)rinfo;
    info->add_ref();
    data = (char*)internal_dynamic_alloc(sizeof(E));
    this->value().init(rinfo, p);
    return *this;
  }
  record_type(const record_type &r) : record_base() { init(r.info, (void*)&r); }
  inline ~record_type() { cleanup_instance(); }

  /* Methods used to build record aggregats */
  inline record_type &aggregate_set(int index, const void *element_value);
  inline record_type &aggregate_copy(int index, int copy_index);

  record_type &operator=(const record_type &record) { 
    this->value() = record.value();
    return *this;
  }

  // Note that only the relational operators == is directly defined in
  // the class as it is valid for all array classes (!= is defined by
  // combining ! and ==).
  bool operator==(const record_type &record) { return record.value() == this->value(); }
};


/* Method to cleanup a record instance, i.e. memory allocated by the
 * instance is freed */
template<class E>
inline void record_type<E>::cleanup_instance()
{
  if (info != NULL)
    {
      record_info &rinfo = *info;
      for (int i = 0; i < rinfo.record_size; i++) {
	rinfo.element_types[i]->clear ( (*rinfo.element_addr) (data, i));
	rinfo.element_types[i]->remove_ref();
      }
  
      rinfo.remove_ref();
      internal_dynamic_remove(data, rinfo.data_size);
    }
}


template<class E>
inline record_type<E> &record_type<E>::aggregate_set(int index, const void *element_value)
{
  record_info &rinfo = *info;
  rinfo.element_types[index]->copy( (*rinfo.element_addr) (data, index), element_value);
  return *this;
}


template<class E>
inline record_type<E> &record_type<E>::aggregate_copy(int index, int copy_index)
{
  record_info &rinfo = *info;
  rinfo.element_types[index]->copy( (*rinfo.element_addr) (data, index), 
				    (*rinfo.element_addr) (data, copy_index));
  return *this;
}



/* *************************************************************
 * Array type class
 * ************************************************************* */
class array_base {
public:
  array_info *info; /* Points to the object which stores information
		     * about the current array */
  char *data; /* Pointer to the actual data of the array */

  array_base() { };
  array_base(const array_base &a);
  array_base(array_info *i) { info = i; i->add_ref(); }
  void set_info(array_info *i) {
    if (info != NULL) info->remove_ref();
    info = i;
    i->add_ref();
  }
  array_base &operator=(const array_base &a);
  static int size() { return ARRAY_SIZE; }
};


/* Always returns the id of the type. The parameter is actually not
 * needed but used to select the appropriate function id. */
inline type_id id(array_base *d) {  return ARRAY; }


/* E is the array element type of the _unconstrained_ array range
 * type. */
template<class E> 
class array_type : public array_base {
 public:
  typedef E E_type; /* declare a local type name which is
		     * equivalent to the element type */
  inline void cleanup_instance();
  array_type() {};
  /* init initiliazes an array. The array elements are set to their
   * corresponding default values. */
  array_type &init(type_info_interface *ainfo);
  /* All elements of the array are initialized to "elem_init_value" */
  array_type &init(type_info_interface *ainfo, const E &elem_init_value);
  /* "p" points to an array instance. The array elements are copied
   * from "p". */
  array_type &init(type_info_interface *ainfo, const void *p);
  array_type &init(const void *p) { init(((array_base*)p)->info, p); return *this; }
  array_type(const array_type &a) : array_base() { init(a.info, (void*)&a); }
  array_type(array_info *ainfo, const E *iarray);
  array_type(array_info *ainfo, const E &val);
  inline ~array_type() { cleanup_instance(); }

  /* Methods used to build array aggregats */
  inline array_type &aggregate_set(int left, range_direction direction, int right, const E &value);
  inline array_type &aggregate_copy(int left, range_direction direction, int right, int copy_index);

  E &operator[](const int i) {
    int index = (info->index_direction == to? i - info->left_bound : info->left_bound - i);
    if (index < 0 || index >= info->length)
      error(ERROR_ARRAY_INDEX);
    return ((E*)data)[index];
  }

  const E &operator[](const int i) const {
    int index = (info->index_direction == to? i - info->left_bound : info->left_bound - i);
    if (index < 0 || index >= info->length)
      error(ERROR_ARRAY_INDEX);
    return ((E*)data)[index];
  }

  E &operator()(const int i) { return ((E*)data)[i];  }
  const E &operator()(const int i) const { return ((E*)data)[i];  }

  array_type &operator=(const array_type &array);

  // Note that only the relational operators == is directly defined in
  // the class as it is valid for all array classes (!= is defined by
  // combining ! and ==).
  bool operator==(const array_type &array) const;
};


/* Method to cleanup an array instance, i.e. memory allocated by the
   instance is freed */
template<class E>
void array_type<E>::cleanup_instance()
{
  if (data != NULL)
    {
      /* Note, scalar(...) can be evaluated at compile time. */
      if (!scalar(id((E*)NULL)))
	/* If the element type is not scalar then execute
	 * cleanup() for each element in the array */
	for (int i = 0; i < info->length; i++)
	  cleanup(&((E*)data)[i]);
      
      if (data != NULL)
	internal_dynamic_remove(data, sizeof(E) * info->length); /* Remove data memory */
    }

  if (info != NULL)
    info->remove_ref(); /* Unlink from the info instance */
}




/* The concat operator */
template<class A, class E>
A concat(array_info *ainfo, const A &a1, const A &a2)
{
  int length = ainfo->length;
  // If both arrays are null arrays then return the result is the
  // right operand
  if (ainfo->length == 0)
    return A(a2);

  // Create new array
  A new_array;
  new_array.info = ainfo;
  new_array.info->add_ref();

  /* Allocate memory for the data */
  const int mem_size = length * ainfo->element_type->size();
  new_array.data = (char*)internal_dynamic_alloc(mem_size);

  /* Note, scalar(...) can be evaluated at compile time. */
  type_info_interface *etype = ainfo->element_type;
  if (!scalar(id((E*)NULL))) {
    /* If the element type is not scalar then init the memory and
     * execute init(...) for each element in the array */
    memset(new_array.data, 0, mem_size);
    for (int i = 0; i < length; i++)
      etype->init(&((E*)new_array.data)[i]);
  }

  /* Copy data */
  int length1 = a1.info->length1;
  int length2 = a2.info->length2;
  int i;
  for (i = 0; i < length1; i++)
    ((E*)new_array.data)[i] = ((E*)a1.data)[i];
  for (; i < length; i++)
    ((E*)new_array.data)[i] = ((E*)a2.data)[i];
  
  return new_array;
}


/* Another version of the concat operator */
template<class A, class E>
A concat(const A &a1, const A &a2)
{
  int length = a1.info->length + a2.info->length;
  // If both arrays are null arrays then return the result is the
  // right operand
  if (length == 0)
    return A(a2);

  // Create new array
  A new_array;
  array_info &ref_ainfo = a1.info->length != 0? *a1.info : *a2.info;

  new_array.info = new array_info(ref_ainfo.element_type, ref_ainfo.index_type, 0);
  array_info &new_info = *new_array.info;
  new_array.info->add_ref();
  int right;
  ref_ainfo.index_type->get_bounds(new_info.left_bound, new_info.index_direction, right);
  if (new_info.index_direction == to) {
    new_info.right_bound = new_info.left_bound + length - 1;
    if (new_info.right_bound > right) error(ERROR_ARRAY_INDEX_OUT_OF_BOUNDS);
  } else {
    new_info.right_bound = new_info.left_bound - length + 1;
    if (new_info.right_bound < right) error(ERROR_ARRAY_INDEX_OUT_OF_BOUNDS);
  }
  new_info.length = length;

  /* Allocate memory for the data */
  const int mem_size = length * sizeof(E);
  new_array.data = (char*)internal_dynamic_alloc(mem_size);

  /* Note, scalar(...) can be evaluated at compile time. */
  type_info_interface *etype = new_array.info->element_type;
  if (!scalar(id((E*)NULL))) {
    /* If the element type is not scalar then execute init(...) for
     * each element in the array after setting the memory to 0 */
    memset(new_array.data, 0, mem_size);
    for (int i = 0; i < length; i++)
      etype->init(&((E*)new_array.data)[i]);
  }

  /* Copy data */
  int length1 = a1.info->length;
  int i;
  for (i = 0; i < length1; i++)
    ((E*)new_array.data)[i] = ((E*)a1.data)[i];
  for (int j = 0; i < length; i++, j++)
    ((E*)new_array.data)[i] = ((E*)a2.data)[j];
  
  return new_array;
}



template<class E>
array_type<E>::array_type (array_info *ainfo, const E *iarray)
{
  /* Create a new array_info instance */
  info = ainfo;
  info->add_ref();

  /* Allocate memory for the data */
  int length = info->length;
  const int mem_size = length * sizeof(E);
  data = (char*)internal_dynamic_alloc(mem_size);

  /* Note, scalar(...) can be evaluated at compile time. */
  type_info_interface *etype = info->element_type;
  if (!scalar(id((E*)NULL))) {
    /* If the element type is not scalar then execute init(...) for
     * each element in the array after initialing the memory to 0 */
    memset(data, 0, mem_size);
    for (int i = 0; i < length; i++)
      etype->init(&((E*)data)[i]);
  }

  /* Copy data */
  for (int i = 0; i < length; i++)
    ((E*)data)[i] = iarray[i];
}


template<class E>
array_type<E>::array_type (array_info *ainfo, const E &val)
{
  /* Create a new array_info instance */
  info = ainfo;
  info->add_ref();
  int length = info->length;

  /* Allocate memory for the data */
  const int mem_size = length * sizeof(E);
  data = (char*)internal_dynamic_alloc(mem_size);

  /* Note, scalar(...) can be evaluated at compile time. */
  type_info_interface *etype = info->element_type;
  if (!scalar(id((E*)NULL))) {
    /* If the element type is not scalar then execute init(...) for
     * each element in the array after initialing the memory to 0 */
    memset(data, 0, mem_size);
    for (int i = 0; i < length; i++) {
      etype->init(&((E*)data)[i]);
      ((E*)data)[i] = val;
    }

  } else {
    /* Each element of the array is set to val */
    const E val_copy = val; // Important for speed optimization
    for (int i = 0; i < length; i++)
      ((E*)data)[i] = val_copy;
  }
}


template<class E>
array_type<E> &array_type<E>::operator=(const array_type<E> &array)
{
  int length = info->length;

  /* Check whether array bounds are compatible */
  if (info != array.info && length != array.info->length)
    error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Copy the data part of the arrays */
  if (scalar(id((E*)NULL))) {
    /* If the element type is not scalar then execute init(...) for
     * each element in the array after initialing the memory to 0 */
    const int mem_size = length * sizeof(E);
    memcpy(data, array.data, mem_size);
  } else
    for (int i = 0; i < length; i++)
      ((E*)data)[i] = ((E*)array.data)[i];

  return *this;
}


template<class E>
bool array_type<E>::operator==(const array_type<E> &array) const
{
  const int length = info->length;
  
  if (length != array.info->length) return false;
  /* Compare the data part of the arrays */
  for (int i = 0; i < length; i++)
    if ((((E*)data)[i] != ((E*)array.data)[i])) return false;

  return true;
}


template<class E>
array_type<E> &array_type<E>::init(type_info_interface *ainfo, const void *p)
{
  info = (array_info*)ainfo;
  info->add_ref();
  int length = info->length;
  type_info_interface *etype = info->element_type;

  /* Allocate memory for the data */
  const int mem_size = length * sizeof(E);
  data = (char*)internal_dynamic_alloc(mem_size);

  E *src_data = (E*)((array_base*)p)->data;
  /* Next, analyze element type of array */
  switch (id((E*)NULL)) {
  case ARRAY:
    {
      /* If the element type is not scalar then init memory to 0 */
      memset(data, 0, mem_size);
      /* Copy each element of the array */
      for (int i = 0; i < length; i++) {
	array_base &dest = (array_base&)((E*)data)[i];
	((array_info*)etype)->init (&dest);
	etype->copy(&dest, &src_data[i]);
      }
      break;
    }
  case RECORD:
    {
      /* If the element type is not scalar then init memory to 0 */
      memset(data, 0, mem_size);
      /* Copy each element of the array */
      for (int i = 0; i < length; i++) {
	record_base &dest = (record_base&)((E*)data)[i];
	((record_info*)etype)->init (&dest);
	etype->copy(&dest, &src_data[i]);
      }
      break;
    }
  default:
    {
      /* The element is a scalar simply copy the entire data region */
      memcpy(data, src_data, mem_size);
      break;
    }
  }

  return *this;
}


template<class E>
array_type<E> &array_type<E>::init(type_info_interface *ainfo)
{
  info = (array_info*)ainfo;
  info->add_ref();
  int length = info->length;
  type_info_interface *etype = info->element_type;

  /* Allocate memory for the data */
  const int mem_size = length * sizeof(E);
  data = (char*)internal_dynamic_alloc(mem_size);

  if (scalar(id((E*)NULL))) {
    /* If the element type is scalar then create a single copy of the
     * element and use this copy to initialize the other array
     * elements */
    E elem_init_val;
    etype->init(&elem_init_val);
    for (int i = 0; i < length; i++)
      ((E*)data)[i] = elem_init_val;

  } else {
    /* If the element type is not scalar then init memory to 0 */
    memset(data, 0, mem_size);
    /* Initialize each element of the array */
    for (int i = 0; i < length; i++)
      etype->init(&((E*)data)[i]);
  }

  return *this;
}


template<class E>
array_type<E> &array_type<E>::init(type_info_interface *ainfo, const E &elem_init_value)
{
  info = (array_info*)ainfo;
  info->add_ref();
  int length = info->length;

  /* Allocate memory for the data */
  const int mem_size = length * sizeof(E);
  data = (char*)internal_dynamic_alloc(mem_size);

  /* Init data part */
  if (scalar(id((E*)NULL))) {
    // Create a local copy of the element value (important for speed
    // optimizations)
    const E elem_init_value_copy = elem_init_value;
    for (int i = 0; i < length; i++)
      ((E*)data)[i] = elem_init_value_copy;

  } else { 
    /* If the element type is not scalar then init memory to 0 */
    memset(data, 0, mem_size);
    type_info_interface *etype = info->element_type;
    for (int i = 0; i < length; i++) {
      etype->init(&((E*)data)[i]);
      ((E*)data)[i] = elem_init_value;
    }
  }

  return *this;
}


/* Method to set array elements left to/downto right to value */
template<class E>
inline array_type<E> &array_type<E>::aggregate_set(int left, range_direction direction, int right, const E &value)
{
  if (direction == downto) {
    int tmp = left;
    left = right;
    right = tmp;
  }
  for (int i = left; i <= right; i++)
    (*this)[i] = value;

  return *this;
}


/* Method to copys array element with index copy_index to array
 * elements left to/downto right to value */
template<class E>
inline array_type<E> &array_type<E>::aggregate_copy(int left, range_direction direction, int right, int copy_index)
{
  if (direction == downto) {
    int tmp = left;
    left = right;
    right = tmp;
  }
  E &value = ((E*)data)[copy_index];
  for (int i = left; i <= right; i++)
    (*this)[i] = value;

  return *this;
}


/* ************************************************************* 
 * The relational operators <,<=, >, >= are not defined for each array
 * type. Hence, a separate set of template functions are defined here
 * which define operator < (op_array_lt) and operator <=
 * (op_array_le). The remaining relational operators are defined by
 * combining < and <= with operator ! (this is done online when the 
 * C++ code is generated by the VHDL compiler).
 * ************************************************************* */
template<class A, class B>
bool op_array_lt(const A &a1, const B &a2)
{
  const int length1 = a1.info->length;
  const int length2 = a2.info->length;
  const int min_length = min(length1, length2);

  /* Compare the data part of the arrays */
  for (int i = 0; i < min_length; i++)
    if (a1(i) != a2(i)) return a1(i) < a2(i);

  return length1 < length2;
}


template<class A, class B>
bool op_array_le(const A &a1, const B &a2)
{
  const int length1 = a1.info->length;
  const int length2 = a2.info->length;
  const int min_length = min(length1, length2);

  /* Compare the data part of the arrays */
  for (int i = 0; i < min_length; i++)
    if (a1(i) != a2(i)) return a1(i) < a2(i);

  return length1 <= length2;
}


/* ************************************************************* 
 * The logical operators not, and, or, nor, xor, xnor are not defined
 * for each array type. Hence, a separate set of template functions
 * are defined.
 * ************************************************************* */
template<class A>
A op_array_not (const A &a)
{
  A result(a);
  const int length = a.info->length;

  /* Compare the data part of the arrays */
  for (int i = 0; i < length; i++)
    result(i) = op_not(a(i));

  return result;
}

template<class A, class B>
A op_array_and (const A &a1, const B &a2)
{
  A result(a1);
  const int length = a1.info->length;

  /* Check whether array bounds are compatible */
  if (a1.info != a2.info && length != a2.info->length)
    error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Handle data part of the arrays */
  for (int i = 0; i < length; i++)
    result(i) = a1(i) & a2(i);

  return result;
}


template<class A, class B>
A op_array_or (const A &a1, const B &a2)
{
  A result(a1);
  const int length = a1.info->length;

  /* Check whether array bounds are compatible */
  if (a1.info != a2.info && length != a2.info->length)
    error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Handle data part of the arrays */
  for (int i = 0; i < length; i++)
    result(i) = a1(i) | a2(i);

  return result;
}


template<class A, class B>
A op_array_nand (const A &a1, const B &a2)
{
  A result(a1);
  const int length = a1.info->length;

  /* Check whether array bounds are compatible */
  if (a1.info != a2.info && length != a2.info->length)
    error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Handle data part of the arrays */
  for (int i = 0; i < length; i++)
    result(i) = op_nand(a1(i), a2(i));

  return result;
}


template<class A, class B>
A op_array_nor (const A &a1, const B &a2)
{
  A result(a1);
  const int length = a1.info->length;

  /* Check whether array bounds are compatible */
  if (a1.info != a2.info && length != a2.info->length)
    error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Handle the data part of the arrays */
  for (int i = 0; i < length; i++)
    result(i) = op_nor(a1(i), a2(i));

  return result;
}


template<class A, class B>
A op_array_xor (const A &a1, const B &a2)
{
  A result(a1);
  const int length = a1.info->length;

  /* Check whether array bounds are compatible */
  if (a1.info != a2.info && length != a2.info->length)
    error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Handle data part of the arrays */
  for (int i = 0; i < length; i++)
    result(i) = op_xor(a1(i), a2(i));

  return result;
}


template<class A, class B>
A op_array_xnor (const A &a1, const B &a2)
{
  A result(a1);
  const int length = a1.info->length;

  /* Check whether array bounds are compatible */
  if (a1.info != a2.info && length != a2.info->length)
    error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Handle data part of the arrays */
  for (int i = 0; i < length; i++)
    result(i) = op_xnor(a1(i), a2(i));

  return result;
}


template<class A>
A op_array_sll (const A &a, integer j)
{
  typedef typename A::E_type E;
  const int length = a.info->length;
  if (length <= 0) return a;
  const int shift = abs (j) % length;

  /* Create result vector. Note that result is initialized with all
   * elements set to element_type'left */
  A result;
  result.init (a.info);

  if (shift == 0) return a;
  else if (j > 0)
    /* Handle data part of the arrays */
    for (int i = 0; i < length - shift; i++)
      ((E*)result.data) [i] = ((E*)a.data) [i + shift];
  else 
    for (int i = length - 1; i >= shift; i--)
      ((E*)result.data) [i] = ((E*)a.data) [i - shift];

  return result;
}


template<class A>
A op_array_srl (const A &a, integer j)
{
  return op_array_sll<A> (a, -j);
}


template<class A>
A op_array_sla (const A &a, integer j)
{
  typedef typename A::E_type E;
  const int length = a.info->length;
  if (length <= 0) return a;
  const int shift = abs (j) % length;

  /* Create result vector. Note that result is initialized with all
   * elements set to a[a'right] */
  A result;
  result.init (a.info, ((E*)a.data) [j > 0? length - 1 : 0]);
  
  if (shift == 0) return a;
  else if (j > 0)
    /* Handle data part of the arrays */
    for (int i = 0; i < length - shift; i++)
      ((E*)result.data) [i] = ((E*)a.data) [i + shift];
  else 
    for (int i = length - 1; i >= shift; i--)
      ((E*)result.data) [i] = ((E*)a.data) [i - shift];

  return result;
}


template<class A>
A op_array_sra(const A &a, integer j)
{
  return op_array_sla (a, -j);
}


template<class A>
A op_array_rol (const A &a, integer j)
{
  typedef typename A::E_type E;
  const int length = a.info->length;
  if (length <= 0) return a;
  const int shift = abs (j) % length;

  /* Create result vector */
  A result;
  result.init(a.info);
  
  if (shift == 0) return a;
  else if (j > 0)
    /* Handle data part of the arrays */
    for (int i = 0; i < length; i++)
      ((E*)result.data) [i] = 
	((E*)a.data) [i + shift - (i + shift >= length? length : 0)];
  else 
    for (int i = 0; i < length; i++)
      ((E*)result.data) [i] =  
	((E*)a.data) [i - shift + (i - shift < 0? length : 0)];

  return result;
}


template<class A>
A op_array_ror (const A &a, integer j)
{
  return op_array_rol<A> (a, -j);
}


/* *************************************************************
 * Array alias type class
 * ************************************************************* */

/* array_alias class is a array class derived from an array_type class
 * (T). This special class is used to build array alias instances of
 * an array object. Basically, the alias class adds some new
 * constructors and a destructor. The constructors do not create a new
 * data array but reuse an existing array. Hence, the destructor does
 * not deallocate the data part of the array!
 * 
 * Note that T must be an array_type class! */
template<class T> 
class array_alias : public T {
public:
  array_alias(): T () {
    array_base &array = *(array_base*)this;
    array.info = NULL;
    array.data = NULL;
  }
  array_alias(type_info_interface *et, type_info_interface *it, 
	      int le, range_direction dir, int ri, int rc, void *iarray) : T () {
    array_base &array = *(array_base*)this;
    /* Create a new array_info instance */
    array.info = new array_info(et, it, le, dir, ri, rc);
    array.data = (char*)iarray;
  }
  /* Note that here the bounds of the alias are taken from the
   * source array and NOT  from the array base! */
  array_alias(array_info *base, const array_base &abase) : T () {
    array_base &array = *(array_base*)this;
    const array_info &ainfo = *abase.info;
    array.info = new array_info(base->element_type, base->index_type, ainfo.left_bound, 
				ainfo.index_direction, ainfo.right_bound, 1);
    array.data = abase.data;
  }
  array_alias(array_info *ainfo, const void *iarray) : T () { 
    array_base &array = *(array_base*)this;
    array.info = ainfo; 
    array.info->add_ref(); 
    array.data = (char*)iarray; 
  }
  array_alias &set(array_info *ainfo, void *iarray) {
    array_base &array = *(array_base*)this;
    if (array.info != NULL)
      array.info->remove_ref();
    array.info = ainfo;
    array.info->add_ref();
    array.data = (char*)iarray;
    return *this;
  }
  ~array_alias() { 
    /* Note that the data array is NOT deallocated as the memory has
     * been allocated by another array_type instance */
    array_base &array = *(array_base*)this;
    array.data = NULL; /* Set pointer to NULL so that the destructor of
			* class T will NOT remove the memory! */
  }
  array_alias &operator=(const T &a);
  array_alias &operator=(const array_alias &a) { *this = (T&)a; return *this; }
};


template<class T>
array_alias<T> &array_alias<T>::operator=(const T &a) 
{
  array_base &array = *(array_base*)this;
  int length = array.info->length;
  typedef typename T::E_type E;

  /* Check whether array bounds are compatible */
  if (array.info != a.info && length != a.info->length)
    error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Check whether the arrays overlap */
  const int mem_size = length * sizeof(E);
  
  if (abs((long)a.data - (long)array.data) >= mem_size) {
    /* Ok, arrays do NOT overlap! */
    /* Copy the data part of the arrays */
    if (scalar(id((E*)NULL)))
      /* If the element type is not scalar then execute init(...) for
       * each element in the array after initialing the memory to 0 */
      memcpy(array.data, a.data, mem_size);
    else
      for (int i = 0; i < length; i++)
	((E*)array.data)[i] = ((E*)a.data)[i];
    
  } else {
    /* Attention: arrays overlap! */
    /* Copy the data part of the arrays */
    if (scalar(id((E*)NULL)))
      /* If the element type is not scalar then execute init(...) for
       * each element in the array after initialing the memory to
       * 0. Note that twe are using memmove instead of memcpy here
       * because the memory ranges of source and destination
       * overlap. */
      memmove(array.data, a.data, mem_size);

    else {
      /* Check out whether the lower border of the source array is
       * located within the destination array as this affects the
       * iteration direction. */
      if (a.data >= array.data) 
	for (int i = 0; i < length; i++)
	  ((E*)array.data)[i] = ((E*)a.data)[i];
      else 
	for (int i = length - 1; i >= 0; i--)
	  ((E*)array.data)[i] = ((E*)a.data)[i];
    }
  }

  return *this; 
}



/* *************************************************************
 *  Functions to implement VHDL file IO
 * ************************************************************* */

enumeration file_eof(vhdlfile &file);

void file_close(vhdlfile &file);

void file_open(vhdlfile &file, const array_type<enumeration> &name, enumeration kind);
void file_open(enumeration &status, const vhdlfile &file, array_type<enumeration> &name, enumeration kind);

void file_read_scalar(vhdlfile &file, void *value_p, int size);
void file_read_array(vhdlfile &file, void *value_p);
void file_read_record(vhdlfile &file, void *value_p);
void file_read_array(vhdlfile &file, void *value_p, integer &length);
void file_write_scalar(vhdlfile &file, const void *value_p, int size);
void file_write_array(vhdlfile &file, const void *value_p);
void file_write_record(vhdlfile &file, const void *value_p);

/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL // This is only required when the kernel is compiled

#include <freehdl/kernel-db.hh>

// Create a database key type for type_info_interface so that entries
// can be associated to it.
define_db_key_type (type_info_interface*, type_info_interface_p);

#endif
#endif

