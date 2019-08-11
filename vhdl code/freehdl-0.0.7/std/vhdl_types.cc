#define KERNEL
#if HAVE_ALLOCA_H
#include <alloca.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <stdlib.h>
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-dump.hh>
#include <freehdl/kernel-register.hh>



/* *************************************************************
 *  Some global functions
 * ************************************************************* */

// Returns whether info is or includes array types which are not
// constrained. Returns true if no such type or element type was
// found.
bool
is_constrained(type_info_interface *info)
{
  switch (info->id) {
  case ARRAY: {
    array_info &ainfo = *(array_info*)info;
    // If length of array is set ot -1 then this is an unconstrained
    // array type.
    if (ainfo.length == -1) return true;
    // Next, analyze element type of the array.
    return is_constrained(ainfo.element_type);
    break;
  }
  case VHDLFILE:
  case RECORD:
    return true;
    break;

  default:
    // All other types are contrained
    return true;
    break;
  }
}


// Create a type instance based on a reference info rinfo and an acl
// a. The acl stores all information which are not included within the
// reference info. E.g., if the reference info is an unconstrained
// array then the acl stores the actual bounds of the array. Note that
// information which can be derived from the reference info is NOT
// stored in the acl!
type_info_interface *
setup_type_info_interface(type_info_interface *rinfo, pacl a)
{
  // If the reference info is constrained then return it as we do not
  // have to modify it.
  if (is_constrained(rinfo)) 
    return rinfo;

  switch (rinfo->id) {
  case ARRAY: {
    array_info *rainfo = (array_info*)rinfo;
    // First, convert elementy type if necessary
    type_info_interface *elem_type = rainfo->element_type;
    if (!is_constrained(elem_type))
      elem_type = setup_type_info_interface(elem_type, a + 1);
    // Next, create a new array info instance. The first step is to
    // determine actual array range.
    int left, right;
    range_direction dir;
    if (rainfo->length == -1) {
      // If the array range is not defined by the reference array info
      // (i.e., if the reference array is unconstrained) then read it
      // from the acl.
      if ((a++)->get() != ACL_RANGE)
	error("Internal runtime error!");
      left = (a++)->get();
      dir = (a++)->get() == 0? to : downto;
      right = (a++)->get();

    } else {
      // If the reference array has a fixed range then use it.
      left = rainfo->left_bound;
      dir = rainfo->index_direction;
      right = rainfo->right_bound;

    }
    // Now, create a new array info instance and return it
    array_info *new_ainfo = new array_info(elem_type, rainfo->index_type, left, dir, right, 0);

    return new_ainfo;
  }
  break;

  case RECORD:
  default:
    // This should never happen!
    error("Internal runtime error!");
  }
  
  return NULL;
}



// Conversion table to convert a nibble into a binary string
const char *nibble_translation_table[] = { 
  "0000", "0001", "0010", "0011",
  "0100", "0101", "0110", "0111",
  "1000", "1001", "1010", "1011",
  "1100", "1101", "1110", "1111",
};


/* Converts an unsigned integer into an string */
inline char *
uint_to_binary(char *buffer, const int buffer_size, unsigned int value)
{
  // Set end of string
  buffer[buffer_size - 1] = '\0';
  // buffer_pointer points to "end of string"
  char *buffer_pointer = &buffer[buffer_size - 1];
  
  if (value != 0) {
    // Convert integer in chunks of 4 bits
    while (value != 0) {
      buffer_pointer -= 4;
#if SIZEOF_INT == 4
      *(int*)buffer_pointer = *(int*)nibble_translation_table[value & 0xf];
#else
      memcpy(buffer_pointer, nibble_translation_table[value & 0xf], sizeof(int));
#endif
      value >>= 4;
    }
    // Skip leading '0's
    while (*buffer_pointer != '1')
      buffer_pointer++;

  } else {
    // Print a single '0'
    buffer_pointer -= 1;
    buffer[buffer_size] = '0';
  }

  return buffer_pointer;
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
    return L3std_Q8standard_I7integer_INFO.high_bound;
}


/* Convertes string to unsigned int. Stops conversion as soon as a
   character not included in base is found. However any character '_'
   is ignored. Returns a pointer to the first invalid character or to
   the end of the string. The function returns NULL if an overflow
   occured. */
const char *
string_to_ulint(lint result, int base, const char *p)
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
   in result. Further, in case of an error the function returns a
   pointer to the character which caused the failure or NULL
   otherwise. */
const char *
string_to_li(lint &result, const char *p)
{
  result = 0;
  bool negative = false, ok = true;

  // Read sign if present
  if (*p == '-') { p++; negative = true; }

  // Read first integer number
  const char *p_old = p;
  p = string_to_ulint(result, p);
  if (p == NULL) return p_old;

  int base = 10;
  // Check whether a base has been specified
  if (*p == '#') {
    base = result;
    if (base > 16) return p;
    p = string_to_ulint(result = 0, base, p_old = ++p);
    if (p == NULL) return p_old;
  }

  // Skip underscores
  while (*p == '_') p++;

  // Check for exponent
  if (*p == 'e' || *p == 'E') {
    bool negative_exp = false;
    if (*(++p) == '-') { negative_exp = true; p++; }
    if (*p == '\0') return p-1;
    lint exp;
    p = string_to_ulint(exp, p_old = ++p);
    if (p == NULL) return p_old;
    // Calculate result
    if (negative_exp) 
      while ((exp--) && (result != 0))
	result /= base;
    else 
      while ((exp--) && (result != 0)) {
	lint result2 = result * base;
	// Check for overflow
	if (result2 < result) return p_old;
	result = result2;
      }
  }

  if (negative)
    result = -result;

  return *p == '\0'? NULL : p;
}


/* Convert an string value into a double. Further, in case of an error
   the function returns a pointer to the character which caused the
   failure or NULL otherwise. */
const char *
string_to_d(double &result, const char *p)
{
  result = 0.0;
#ifdef HAVE_ALLOCA
  char *last_copy, *cp = (char*)alloca (sizeof(char)*(strlen(p)+1));
#else
  int mem_size;
  char *last_copy, *cp = (char*)internal_dynamic_alloc (mem_size = sizeof(char)*(strlen(p)+1));
#endif
  char **o_addr = (char**)alloca(sizeof(char*)*(strlen(p)+1));
  const char *copy = cp, *copy_start = cp;
  const char * const *org_addr = o_addr;

  // First, remove underscores and check whether a base is specified
  int i = 0;
  bool base_specified = false;
  while (p[i] != '\0') {
    if (p[i] == '#') base_specified = true;
    if (p[i] != '_') {
      *(o_addr++) = (char*)&p[i];
      *(cp++) = p[i];
    }
    i++;
  }
  *cp = '\0';

  if (base_specified) {
    // A base has been specified. First, determine base.
    bool negative = false;
    if (*copy == '-') { negative = true; copy++; }
    if (*copy == '\0') 
      {
#ifndef HAVE_ALLOCA
	internal_dynamic_remove (cp, mem_size);
#endif
	return org_addr[copy - copy_start - 1];
      }
    lint base = 0;
    copy = string_to_ulint(base, copy);
    if (*(copy++) != '#' || base > 16) 
      {
#ifndef HAVE_ALLOCA
	internal_dynamic_remove (cp, mem_size);
#endif
	return org_addr[copy - copy_start - 1];
      }
    // Get integer part
    lint integer = 0;
    last_copy = (char*)copy;
    copy = string_to_ulint(integer, base, copy);
    // Check for error and decimal point
    if (copy == NULL || *copy != '.') 
      {
#ifndef HAVE_ALLOCA
	internal_dynamic_remove (cp, mem_size);
#endif
	return org_addr[last_copy - copy_start];
      }
    copy++;
    // Get fraction 
    lint fraction = 0;
    const char *copy_new = string_to_ulint(fraction, base, copy); 
    if (copy_new == NULL) 
      {
#ifndef HAVE_ALLOCA
	internal_dynamic_remove (cp, mem_size);
#endif
	return org_addr[copy - copy_start];
      }
    int fraction_digits = copy_new - copy;
    copy = copy_new;
    // Get exponent
    lint exponent = 0;
    if (*copy == 'e' || *copy == 'E') {
      bool negative_exp = false;
      if (*(++copy) == '-') { negative_exp = true; copy++; }
      if (*copy == '\0') 
	{
#ifndef HAVE_ALLOCA
	  internal_dynamic_remove (cp, mem_size);
#endif
	  return org_addr[copy - copy_start];
	}
      const char * old_copy = copy;
      copy = string_to_ulint(exponent, ++copy);
      if (copy == NULL) 
	{
#ifndef HAVE_ALLOCA
	  internal_dynamic_remove (cp, mem_size);
#endif
	  return org_addr[old_copy - copy_start];
	}
      // Calculate result
      if (negative_exp) 
	exponent = -exponent;
    }
    // Finally, calculate result
    double fraction_value = (double)fraction;
    while (fraction_digits--) fraction_value /= (double)base;
    result = ((double)integer + fraction_value) * pow((double)base, (double)exponent);
    if (negative) result = -result;

#ifndef HAVE_ALLOCA
    internal_dynamic_remove (cp, mem_size);
#endif
    return *copy == '\0'? NULL : org_addr[copy - copy_start];

  } else {
    // Base is 10. Hence, use library function strtod.
    char *endp;
    result = strtod(copy, &endp);

#ifndef HAVE_ALLOCA
    internal_dynamic_remove (cp, mem_size);
#endif
    return (*endp == '\0') && (result > -HUGE_VAL) && (result < HUGE_VAL)? NULL : endp;
  }
}




/* *************************************************************
 *  Memory management for scalar VHDL objects
 * ************************************************************* */

long long int *free_items = NULL;

inline void 
internal_remove(void *src)
{
  *(long*)src = (long)free_items;
  free_items = (long long int*)src;
}


inline void *
internal_alloc()
{
  if (free_items) {
    void *result = free_items;
    free_items = (long long int*)*(long*)free_items;
    return result;
  } else
    return malloc(sizeof(long long int));
}



/* *************************************************************
 *  type_info_interface
 * ************************************************************* */

char buffer[1000];

// Not clean!
char *
type_info_interface::str(const void *src)
{
  dump_buffer.clean();
  print(dump_buffer, src, VHDL_PRINT_MODE);
  strcpy(buffer, dump_buffer.str());
  return buffer;
}


// Register a type
void
type_info_interface::register_type(const char *sln, const char *ln, const char *n, void *sr)
{
  ::register_type((void*)this, sln, ln, n, sr);
}


void *
type_info_interface::element(void *src, int i)
{
  switch (id) {
  case ARRAY: 
    {
      // the current object is actually an array_info instance
      array_info &ainfo = *(array_info*)this;
      array_base &abase = *(array_base*)src;
      int subelement_count = ainfo.element_type->element_count();
      int element_index = i / subelement_count;
      if (subelement_count == 1)
	// if the element of the array is a scalar type then
	return &abase.data[element_index * ainfo.element_type->size];
      else
	// the element type is a composite type
	return ainfo.element_type->element(&abase.data[element_index * ainfo.element_type->size], 
					   i - element_index * subelement_count);
      break;
    }

  case RECORD:
    {
      record_info &rinfo = *(record_info*)this;
      record_base &rbase = *(record_base*)src;
      // Find the appropriate type info pointer of the record element
      // the scalar element i belongs to
      int j = 0;
      type_info_interface **element_info_p = rinfo.element_types;
      int element_count;
      while (i - (element_count = rinfo.element_types[j]->element_count()) >= 0) {
	i -= element_count;
	j++;
      }
      
      if (rinfo.element_types[j]->scalar()) 
	// If we already found element i then return its address
	return (*rinfo.element_addr) (rbase.data, j);
      else
	// Otherwise, call method "element" again
	return rinfo.element_types[j]->element((*rinfo.element_addr) (rbase.data, j), i);
      break;
    }

  default: 
    return src;
    break;
  }
}



int 
type_info_interface::acl_to_index(acl *a, int &start, int &end) const
{
  switch (id) {
  case ARRAY: 
    {
      // the current object is actually an array_info instance
      array_info &ainfo = *(array_info*)this;
      int subelement_count = ainfo.element_type->element_count();
      if (a->end()) {
	// If acl ends then return all elements
	end = start + ainfo.length * subelement_count - 1;
	return start;

      } else if (a->get() == ACL_RANGE) {
	// Acl determines a range 
	int sindex, eindex;
	if (ainfo.index_direction == to) {
	  sindex = a->get(1) - ainfo.left_bound;
	  eindex = a->get(3) - ainfo.left_bound;
	} else {
	  sindex = ainfo.left_bound - a->get(1);
	  eindex = ainfo.left_bound - a->get(3);
	}
	end = start + (eindex + 1) * subelement_count - 1;
	start += sindex * subelement_count;
	return start;

      } else {
	// A single element is referenced by the acl
	int index = ainfo.index_direction==to? 
	  (a->get() - ainfo.left_bound) : (ainfo.left_bound - a->get());
	if (subelement_count == 1) {
	  // if an element of the array is a scalar type then
	  start += index;
	  end = start;
	  return start;
	} else {
	  start += index * subelement_count;
	  // the element type is a composite type
	  return ainfo.element_type->acl_to_index(++a, start, end);
	}
      }

      break;
    }

  case RECORD:
    {
      // The current info instance is an record_info
      record_info &rinfo = *(record_info*)this;
      if (a->end()) {
	// If the end of the acl has been reached then return the
	// entire record index range
	end = start + rinfo.element_count() - 1;
	return start;
      } else {
	// Otherwise, the next acl number determines the record
	// element (0 = first record element, 1 = second record
	// element, ...)
	const int end_element_index = a->get();
	for (int i = 0; i < end_element_index; i++)
	  start += rinfo.element_types[i]->element_count();
	return rinfo.element_types[end_element_index]->acl_to_index(++a, start, end);
      }
      break;
    }

  default:
    end = start;
    return start;
    break;
  }
}


int 
type_info_interface::acl_to_index(acl *a) const
{
  switch (id) {
  case ARRAY: 
    {
      // the current object is actually an array_info instance
      array_info &ainfo = *(array_info*)this;
      int subelement_count = ainfo.element_type->element_count();

      if (a->end())
	return 0;
      else if (a->get() == ACL_RANGE) {
	const int left = a->get(1);
	// Acl determines a range 
	int sindex;
	if (ainfo.index_direction == to)
	  sindex = left - ainfo.left_bound;
	else 
	  sindex = ainfo.left_bound - left;
	
	return sindex * subelement_count;

      } else {
	// A single element is referenced by the acl
	int index = ainfo.index_direction==to? 
	  (a->get() - ainfo.left_bound) : (ainfo.left_bound - a->get());

	if (subelement_count == 1)
	  // if an element of the array is a scalar type then return
	  return index;
	else
	  // the element type is a composite type
	  return index * subelement_count + ainfo.element_type->acl_to_index(++a);
      }

      break;
    }

  case RECORD:
    {
      // the current object is an record_info instance
      record_info &rinfo = *(record_info*)this;
      
      if (a->end())
	return 0;
      else {
	// The next acl number determines the record element (0 =
	// first record element, 1 = second record element, ...)
	int index = 0;
	const int end_element_index = a->get();
	for (int i = 0; i < end_element_index; i++)
	  index += rinfo.element_types[i]->element_count();

	return index + rinfo.element_types[end_element_index]->acl_to_index(++a);
      }
	
      return 0;
      break;
    }

  default:
    return 0;
    break;
  }
}


type_info_interface *
type_info_interface::get_info(void *src, acl *a) const {
  switch (id) {
  case RECORD:
    {
      record_info *rinfo = (src != NULL)? ((record_base*)src)->info : (record_info*)this;
      if (a->end())
	return rinfo;
      else {
	// Get next integer values stored in a. It determined which
	// record element shall be addressed here (first record
	// element = 0, second record element = 1, ...)
	int index = a->get();
	char *next_src = NULL;
	if (src != NULL)
	  next_src = (char*)(*rinfo->element_addr) (((record_base*)src)->data, index);
	return rinfo->element_types[index]->get_info(next_src, ++a);
      }
      break;
    }

  case ARRAY: 
    {
      // the current object is actually an array_info instance
      array_info *ainfo = (src != NULL)? ((array_base*)src)->info : (array_info*)this;
      if (a->end()) 
	return ainfo;
      else {
	char *next_src = NULL;
	if (src != NULL) {
	  int index = (ainfo->index_direction == to)?
	    a->get() - ainfo->left_bound : ainfo->left_bound - a->get();
	  next_src = &((array_base*)src)->data[index * ainfo->element_type->size];
	}
	return ainfo->element_type->get_info(next_src, ++a);
      }
      break;
    }

  default:
    return (type_info_interface*)this;
    break;
  }
}


type_info_interface *
type_info_interface::get_info(int i) const 
{
  switch (id) {
  case ARRAY: 
    {
      array_info &ainfo = *(array_info*)this;
      if (ainfo.element_type->scalar()) return ainfo.element_type;
      i = i % ainfo.element_type->element_count();
      return ainfo.element_type->get_info(i);
      break;
    }

  case RECORD:
    {
      record_info &rinfo = *(record_info*)this;
      int j = 0, elem_count;
      while (i - (elem_count = rinfo.element_types[j]->element_count()) >= 0) {
	i -= elem_count;
	j++;
      }
      return rinfo.element_types[j]->get_info(i);
      break;
    }

  default:
    return (type_info_interface*)this;
    break;
  }
}



int
type_info_interface::get_bounds(int &left, range_direction &range, int &right)
{
  switch (id) {
  case ARRAY: {
    array_info &ainfo = *(array_info*)this;
    left = ainfo.left_bound;
    range = ainfo.index_direction;
    right = ainfo.right_bound;
    return 0;
  }
  case INTEGER: {
    integer_info_base &iinfo = *(integer_info_base*)this;
    left = iinfo.left_bound;
    right = iinfo.right_bound;
    range = left < right? to : downto;
    return 0;
  }
  case ENUM: {
    enum_info_base &einfo = *(enum_info_base*)this;
    left = einfo.left_bound;
    right = einfo.right_bound;
    range = left < right? to : downto;
    return 0;
  }
  default:
    return -1;
  }
}


/* This method does nothing for scalar types. For non-scalar types it
   assumes that src points to allocated memory that contains
   garbage. Hence, the method does *not* try to read the conent stored
   in *src. */
void
type_info_interface::reset(void *src)
{
  switch (id) {
  case ARRAY: 
    {
      array_base &a_src = *(array_base*)src;
      a_src.info = NULL;
      a_src.data = NULL;
      break;
    } 
  case RECORD: 
    { 
      record_base &r_src = *(record_base*)src; 
      r_src.info = NULL; 
      r_src.data = NULL; 
      break; 
    } 
  }
}


// Prints value into binary stream. Note that only the raw data but
// no type info objects are written! The method returns the number
// of bytes written to the stream.
int 
type_info_interface::binary_print(buffer_stream &str, const void *src)
{
  switch (id) {
  case ARRAY: 
    {
      array_base &array = *(array_base*)src;
      array_info &ainfo = *array.info;
      // Return if there is nothing to write
      if (ainfo.length <= 0)
	return 0; 
      // Now loop over the data elements of the array
      int bytes_written = 0;
      const int elem_size = ainfo.element_type->size;
      const int end_of_data = elem_size * ainfo.length;
      type_info_interface *const elem_info = ainfo.element_type;
      for (int index = 0; index < end_of_data; index += elem_size)
	bytes_written += elem_info->binary_print(str, &array.data[index]);
      
      return bytes_written;
    } 

  case RECORD:
    {
      record_base &record = *(record_base*)src;
      record_info &rinfo = *(record_info*)record.info;
      
      int bytes_written = 0;
      for (int i = 0; i < rinfo.record_size; i++)
	bytes_written += 
	  rinfo.element_types[i]->binary_print (str, (*rinfo.element_addr) (record.data, i));

      return bytes_written;
    }

  case ENUM:
  case INTEGER:
  case PHYSICAL:
  case FLOAT:
    str.binary_write(src, size);
    return size;
    break;

  default:
    error("Internal error in type_info_interface::binary_print!");
  }
}


// Reads value from memory (str) and puts the values into dest. The
// sequence of the data values must be the same as generated by
// binary_print. Note that only the raw data but no type info objects
// are read! Hence, the dest pointer must point to valid object of the
// appropriate size! Returns the number of bytes read or -1 if the
// read operation was not successfull.
int
type_info_interface::binary_read(void *dest, void *src)
{
  void *src_start = src;
  
  switch (id) {
  case ARRAY: 
    {
      array_base &array = *(array_base*)dest;
      array_info &ainfo = *array.info;
      // Return if there is nothing to read
      if (ainfo.length <= 0)
	return 0; 
      // Now loop over the data elements of the array
      const int elem_size = ainfo.element_type->size;
      const int end_of_data = elem_size * ainfo.length;
      type_info_interface *const elem_info = ainfo.element_type;
      for (int index = 0; index < end_of_data; index += elem_size) {
	int bytes_read = elem_info->binary_read(&array.data[index], src);
	if (bytes_read < 0) 
	  return -1;
	src = (char*)src + bytes_read;
      }	
      return (int)((long)src - (long)src_start);
    } 

  case RECORD: 
    {
      record_base &record = *(record_base*)dest;
      record_info &rinfo = *(record_info*)record.info;
      
      int bytes_read = 0;
      for (int i = 0; i < rinfo.record_size; i++) {
	int bytes = rinfo.element_types[i]->binary_read((*rinfo.element_addr) (record.data, i), src);
	if (bytes < 0)
	  return -1;
	src = (char*)src + bytes;
	bytes_read += bytes;
      }

      return bytes_read;
    }

  default:
    fast_copy(dest, src);
    return size;
  }
}


// Add a resolver handler (required by the kernel to perform signal
// resolution) to a type. Returns a reference to the current info
// instance. handler points to a function which is used by the
// kernel to perform the resolution mechanism.
type_info_interface &
type_info_interface::add_resolver(resolver_handler_p handler, type_info_interface *ainfo, bool ideal)
{
  // Associate resolver with type
  ::add_resolver(this, handler, ainfo, ideal);
  // Further, mark the current type_info instance so that the kernel
  // can easily find out whether the type is resolved or not.
  resolved = true;

  return *this;
}



/* *************************************************************
 *  Integer info base class
 * ************************************************************* */

integer_info_base::
integer_info_base() : type_info_interface(INTEGER, INTEGER_SIZE) {
}


integer_info_base::
integer_info_base(const int le, const int ri, 
		  const int lo, const int hi) : 
  type_info_interface(INTEGER, INTEGER_SIZE) {
    left_bound = le; 
    right_bound = ri;
    low_bound = lo;
    high_bound = hi;
}


integer_info_base &
integer_info_base::set(const int le, const int ri, const int lo, const int hi)
{
    left_bound = le; 
    right_bound = ri;
    low_bound = lo;
    high_bound = hi;
    return *this;
}


integer_info_base & 
integer_info_base::set(integer_info_base *src)
{
  left_bound = src->left_bound;
  right_bound = src->right_bound;
  low_bound = src->low_bound;
  high_bound = src->high_bound;

  return *this;
}


void *
integer_info_base::create() {
  integer *p = (integer*)internal_alloc();
  *p = left_bound;
  return p;
}


void *
integer_info_base::clone(const void *src) {
  integer *p = (integer*)internal_alloc();
  *p = *((integer*)src);
  return p;
}


void 
integer_info_base::init(void *src) {
  *((integer*)src) = left_bound;
}


void *
integer_info_base::copy(void *dest, const void *src) {
  *((integer*)dest) = *((integer*)src);
  return dest;
}


bool
integer_info_base::compare(const void *src1, const void *src2) {
  return *((integer*)src1) == *((integer*)src2);
}


bool 
integer_info_base::assign(void *dest, const void *src) {
  int new_value = *((integer*)src);
  bool event = new_value != *((integer*)dest);
  *((integer*)dest) = new_value;
  return event;
}


void
integer_info_base::remove(void *src)
{
  internal_remove(src);
}


void
integer_info_base::print(buffer_stream  &str, const void *src, int mode) {
  str << *((integer*)src);
}

void
integer_info_base::vcd_print(buffer_stream  &str, const void *src,char* translation_table,  bool pure) 
{
 integer op =*((integer*)src);
 static char result[INTEGER_SIZE_LD + 1];
 int i;

 if (op == 0)
   str << "b0";
 else {
   char *cp = uint_to_binary(result, INTEGER_SIZE_LD + 1, (unsigned int)op);
   str << "b" << cp;
 }
}


const char *
integer_info_base::read(void *dest, const char *str)
{
  lint li_value;
  const char *result = string_to_li(li_value, str);
  integer value = (integer)li_value;
  if (result == NULL)
    fast_copy(dest, &value);
  return result;
}


/* *************************************************************
 *  Access info base class
 * ************************************************************* */

access_info_base::
access_info_base() : type_info_interface(ACCESS, ACCESS_SIZE) {
}


access_info_base::
access_info_base(type_info_interface *d_info) :
  type_info_interface(ACCESS, ACCESS_SIZE) 
{
  designated_type_info = d_info;
}


access_info_base &
access_info_base::set(type_info_interface *d_info)
{
  designated_type_info = d_info;
  return *this;
}


void *
access_info_base::create() {
  vhdlaccess *p = (vhdlaccess*)internal_alloc();
  *p = NULL;
  return p;
}


void *
access_info_base::clone(const void *src) {
  vhdlaccess *p = (vhdlaccess*)internal_alloc();
  *p = *((vhdlaccess*)src);
  return p;
}


void 
access_info_base::init(void *src) {
  *((vhdlaccess*)src) = NULL;
}


void *
access_info_base::copy(void *dest, const void *src) {
  *((vhdlaccess*)dest) = *((vhdlaccess*)src);
  return dest;
}


bool
access_info_base::compare(const void *src1, const void *src2) {
  return *((vhdlaccess*)src1) == *((vhdlaccess*)src2);
}


bool 
access_info_base::assign(void *dest, const void *src) {
  vhdlaccess new_value = *((vhdlaccess*)src);
  bool event = new_value != *((vhdlaccess*)dest);
  *((vhdlaccess*)dest) = new_value;
  return event;
}


void
access_info_base::remove(void *src)
{
  internal_remove(src);
}


void
access_info_base::print(buffer_stream  &str, const void *src, int mode) {
  str << (int)((long)*((vhdlaccess*)src));
}


const char *
access_info_base::read(void *dest, const char *str)
{
  error("Sorry, access_info_base::read is currently not implemented!");
}



/* *************************************************************
 *  VHDL file info base class
 * ************************************************************* */

vhdlfile_info_base::
vhdlfile_info_base() : type_info_interface(VHDLFILE, VHDLFILE_SIZE) {
}


vhdlfile_info_base::
vhdlfile_info_base(type_info_interface *f_info) :
  type_info_interface(VHDLFILE, VHDLFILE_SIZE) 
{
  type_info = f_info;
}


vhdlfile_info_base &
vhdlfile_info_base::set(type_info_interface *f_info)
{
  type_info = f_info;
  return *this;
}


void *
vhdlfile_info_base::create() {
  return NULL;
}


void *
vhdlfile_info_base::clone(const void *src) {
  return NULL;
}


void 
vhdlfile_info_base::init(void *src) {
}


void *
vhdlfile_info_base::copy(void *dest, const void *src) {
  return NULL;
}


bool
vhdlfile_info_base::compare(const void *src1, const void *src2) {
  return false;
}


bool 
vhdlfile_info_base::assign(void *dest, const void *src) {
  return false;
}


void
vhdlfile_info_base::remove(void *src)
{
}


const char *
vhdlfile_info_base::read(void *dest, const char *str)
{
  error("Sorry, vhdlfile_info_base::read is not available!");
}



/* *************************************************************
 *  Float  info base class
 * ************************************************************* */


float_info_base::
float_info_base() : type_info_interface(FLOAT, FLOAT_SIZE) {
}


float_info_base::
float_info_base(const double le, const double ri, 
		const double lo, const double hi) : 
  type_info_interface(FLOAT, FLOAT_SIZE) {
    left_bound = le;
    right_bound = ri;
    low_bound = lo;
    high_bound = hi;
}


float_info_base &
float_info_base::set(const double le, const double ri, 
		     const double lo, const double hi)
{
    left_bound = le;
    right_bound = ri;
    low_bound = lo;
    high_bound = hi;
    return *this;
}


float_info_base & 
float_info_base::set(float_info_base *src)
{
  left_bound = src->left_bound;
  right_bound = src->right_bound;
  low_bound = src->low_bound;
  high_bound = src->high_bound;

  return *this;
}


void *
float_info_base::create() {
  floatingpoint *p = (floatingpoint*)internal_alloc();
  *p = left_bound;
  return p;
}


void *
float_info_base::clone(const void *src) {
  floatingpoint *p = (floatingpoint*)internal_alloc();
  *p = *((floatingpoint*)src);
  return p;
}


void *
float_info_base::copy(void *dest, const void *src) {
  *((floatingpoint*)dest) = *((floatingpoint*)src);
  return dest;
}


void 
float_info_base::init(void *src) {
  *((floatingpoint*)src) = left_bound;
}


bool
float_info_base::compare(const void *src1, const void *src2) {
  return *((floatingpoint*)src1) == *((floatingpoint*)src2);
}


bool 
float_info_base::assign(void *dest, const void *src) {
  double new_value = *((floatingpoint*)src);
  bool event = new_value != *((floatingpoint*)dest);
  *((floatingpoint*)dest) = new_value;
  return event;
}


void
float_info_base::remove(void *src)
{
  internal_remove(src);
}


void
float_info_base::print(buffer_stream &str, const void *src, int mode) {
  str << *((floatingpoint*)src);
}

void
float_info_base::vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure) {
  // should be definitly enough characters to hold a string
  // representation of a double
  static char rbuffer[8*sizeof(double)]; 
  sprintf(rbuffer, "%.16g", *((floatingpoint*)src));
  str << 'r' << rbuffer;
}


const char * 
float_info_base::read(void *dest, const char *str)
{
  floatingpoint value;
  const char *result = string_to_d(value, str);
  if (result == NULL)
    fast_copy(dest, &value);
  return result;
}


/* *************************************************************
 *  Enum info base class
 * ************************************************************* */

enum_info_base::
enum_info_base() : type_info_interface(ENUM, ENUM_SIZE) {
}

enum_info_base::
enum_info_base(const int le, const int ri, const char **val) :
  type_info_interface(ENUM, ENUM_SIZE) {
    left_bound = le;
    right_bound = ri;
    length = ri - le + 1;
    values = val;
}


enum_info_base & 
enum_info_base::set(const int le, const int ri, const char **val)
{
  left_bound = le;
  right_bound = ri;
  length = ri - le + 1;
  values = val;
  return *this;
}


enum_info_base & 
enum_info_base::set(enum_info_base *src)
{
  left_bound = src->left_bound;
  right_bound = src->right_bound;
  length = src->length;
  values = src->values;

  return *this;
}


void *
enum_info_base::create() {
  enumeration *p = (enumeration*)internal_alloc();
  *p = left_bound;
  return p;
}


void *
enum_info_base::clone(const void *src) {
  enumeration *p = (enumeration*)internal_alloc();
  *p = *((enumeration*)src);
  return p;
}


bool
enum_info_base::compare(const void *src1, const void *src2) {
  return *((enumeration*)src1) == *((enumeration*)src2);
}


void *
enum_info_base::copy(void *dest, const void *src) {
  *((enumeration*)dest) = *((enumeration*)src);
  return dest;
}


void 
enum_info_base::init(void *src) {
  *((enumeration*)src) = left_bound;
}


bool 
enum_info_base::assign(void *dest, const void *src) {
  enumeration new_value = *((enumeration*)src);
  bool event = new_value != *((enumeration*)dest);
  *((enumeration*)dest) = new_value;
  return event;
}


void
enum_info_base::remove(void *src)
{
  internal_remove(src);
}


void
enum_info_base::print(buffer_stream &str, const void *src, int mode) {
  switch (mode) {
  case VHDL_PRINT_MODE:
    str << values[*((enumeration*)src)];
    break;
  case CDFG_PRINT_MODE:
    str << (int)*((enumeration*)src);
    break;
  }
}


void
enum_info_base::vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure) 
{
  if (translation_table != NULL) {
    const char output = translation_table[*((enumeration*)src)];
    str << output;
  } else {
    static char result[INTEGER_SIZE_LD + 1];
    char *cp = uint_to_binary(result, INTEGER_SIZE_LD + 1, (unsigned int)*((enumeration*)src));
    if (!pure)
      str << "b";
    str << cp;
  }
}


const char *
enum_info_base::read(void *dest, const char *str)
{
  enumeration value;
  for (int i = 0; i < length; i++)
    if (!strcmp(values[i], str)) {
      fast_copy(dest, &(value = i));
      return NULL;
    }

  return str;
}


/* *************************************************************
 *  Physical info base class
 * ************************************************************* */

physical_info_base::
physical_info_base() : type_info_interface(PHYSICAL, PHYSICAL_SIZE) 
{
}

physical_info_base::
physical_info_base(const long long int le, const long long int ri, 
		   const long long int lo, const long long int hi,
		   const char **un, const long long int *sc, 
		   int uc) : 
  type_info_interface(PHYSICAL, PHYSICAL_SIZE) 
{
  left_bound = le;
  right_bound = ri;
  low_bound = lo;
  high_bound = hi;
  units = un;
  scale = sc;
  unit_count = uc;
}


physical_info_base &
physical_info_base::set(const long long int le, const long long int ri, 
			const long long int lo, const long long int hi,
			const char **un, const long long int *sc, 
			int uc)
{
  left_bound = le;
  right_bound = ri;
  low_bound = lo;
  high_bound = hi;
  units = un;
  scale = sc;
  unit_count = uc;
  return *this;
}


physical_info_base & 
physical_info_base::set(physical_info_base *src)
{
  left_bound = src->left_bound;
  right_bound = src->right_bound;
  low_bound = src->low_bound;
  high_bound = src->high_bound;
  units = src->units;
  scale = src->scale;
  unit_count = src->unit_count;

  return *this;
}


void *
physical_info_base::create() {
  physical *p = (physical*)internal_alloc();
  *p = left_bound;
  return p;
}


void *
physical_info_base::clone(const void *src) {
  physical *p = (physical*)internal_alloc();
  *p = *((physical*)src);
  return p;
}


void *
physical_info_base::copy(void *dest, const void *src) {
  *((physical*)dest) = *((physical*)src);
  return dest;
}


void 
physical_info_base::init(void *src) {
  *((physical*)src) = left_bound;
}


bool
physical_info_base::compare(const void *src1, const void *src2) {
  return *((physical*)src1) == *((physical*)src2);
}


bool 
physical_info_base::assign(void *dest, const void *src) {
  long new_value = *((physical*)src);
  bool event = new_value != *((physical*)dest);
  *((physical*)dest) = new_value;
  return event;
}


void
physical_info_base::remove(void *src)
{
  internal_remove(src);
}


void
physical_info_base::print(buffer_stream &str, const void *src, int mode) {
  switch (mode) {
  case VHDL_PRINT_MODE:
    str << *((physical*)src) << " " << units[0];
    break;
  case CDFG_PRINT_MODE:
    str << *((physical*)src);
    break;
  }
}

void
physical_info_base::vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure) {
  str << *((physical*)src) << " " << units[0];
}


const char *
physical_info_base::read(void *dest, const char *str)
{
  physical int_value = 1, result;
  floatingpoint real_value = 1.0;
  bool is_integer_value = true;
  
  // Create a copy of the original string
#ifdef HAVE_ALLOCA
  char *copy = (char*)alloca(sizeof(char) * (strlen(str) + 1));
#else
  int mem_size;
  char *copy = (char*)internal_dynamic_alloc (mem_size = sizeof(char) * (strlen(str) + 1));
#endif
  char *cp = copy;
  char *unit_start; // Start of time unit value

  strcpy(copy, str);
  
  // Test whether a value is given or just an time unit has been
  // specified.
  const char *accept = "0123456789#_.-+ABCDEFabcdef";
  while (*accept != '\0')
    if (*accept == *cp)
      break;
    else
      accept++;
  if (*accept == '\0')
    unit_start = cp;
  else {
    // Search for whitespaces between value and time unit. Further,
    // search for a '.' within the value string in order to determine
    // whether value is given as a integer or a floating point.
    while (*cp != ' ' && *cp != '\t' && *cp != '\0') {
      if (*cp == '.')
	is_integer_value = false;
      cp++;
    }
    if (*cp == '\0') 
      {
#ifndef HAVE_ALLOCA
	internal_dynamic_remove (copy, mem_size);
#endif
	return str;
      }
    *(cp++) = '\0';
    while ((*cp == ' ' || *cp == '\t') && *cp != '\0') cp++;
    if (*cp == '\0') 
      {
#ifndef HAVE_ALLOCA
	internal_dynamic_remove (copy, mem_size);
#endif
	return str;
      }
    unit_start = cp; // Start of time unit value
    // Now, convert value and test whether the conversion succeeded.
    bool failed;
    if (is_integer_value)
      failed = string_to_li(int_value, copy) != NULL;
    else
      failed = string_to_d(real_value, copy) != NULL;
    if (failed)
      {
#ifndef HAVE_ALLOCA
	internal_dynamic_remove (copy, mem_size);
#endif
	return str;
      }
  }

  // Next, convert unit value
  int i;
  for (i = 0; i < unit_count; i++)
    if (!strcasecmp(units[i], unit_start))
      break;
  if (i == unit_count)
    {
#ifndef HAVE_ALLOCA
      internal_dynamic_remove (copy, mem_size);
#endif
      return &str[unit_start - copy];
    }
  
  // Finally, calculate resulting value
  if (is_integer_value)
    result = int_value * scale[i];
  else
    result = (physical)(real_value * scale[i]);
  
  // Copy back result into destination variable
  fast_copy(dest, &result);
  
#ifndef HAVE_ALLOCA
  internal_dynamic_remove (copy, mem_size);
#endif

  return NULL;
}


/* *************************************************************
 *  Array info class
 * ************************************************************* */

array_info &
array_info::set(type_info_interface *et, type_info_interface *it, int rc) 
{
  index_type = it;
  index_type->add_ref();
  element_type = et;
  element_type->add_ref();
  length = -1; /* indicate unconstrained array */
  it->get_bounds(left_bound, index_direction, right_bound); /* Preload bounds */
  ref_counter = rc;

  return *this;
}


array_info::array_info(type_info_interface *et, type_info_interface *it, int rc) :
  type_info_interface(ARRAY, array_base::size())
{
  set(et, it, rc);
}


array_info::array_info(type_info_interface *et, type_info_interface *it, 
		       int le, range_direction r, int ri, int rc) :
  type_info_interface(ARRAY, array_base::size())
{
  set(et, it, le, r, ri, rc);
}


array_info &
array_info::set(type_info_interface *et, type_info_interface *it, int len, int rc)
{
  ref_counter = rc;
  int right;
  range_direction range;
  int le = it->get_bounds(left_bound, range, right);
  if (left_bound < right) {
    right_bound = left_bound + len - 1;
    index_direction = to;
    if (right_bound > right) error(ERROR_ARRAY_INDEX_OUT_OF_BOUNDS);
  } else {
    right_bound = left_bound - len + 1;
    index_direction = downto;
    if (right_bound < right) error(ERROR_ARRAY_INDEX_OUT_OF_BOUNDS);
  }
  length = len;
  index_type = it;
  index_type->add_ref();
  element_type = et;
  element_type->add_ref();

  return *this;
}


/* Constructor to create an info instance where the left bound is
 * determined by base and the right bound is derived from len */
array_info::array_info(type_info_interface *et, type_info_interface *it, int len, int rc) :
  type_info_interface(ARRAY, array_base::size())
{
  set(et, it, len, rc);
}


void array_info::print(buffer_stream &str, const void *src, int mode)
{
  int length = ((array_base*)src)->info->length;
  type_info_interface *einfo = ((array_base*)src)->info->element_type;
  char *data = ((array_base*)src)->data;

  str << "(";
  if (mode == CDFG_PRINT_MODE)
    str << "list ";
  for (int i = 0; i < length; i++) {
    if (i) 
      if (mode == VHDL_PRINT_MODE)
	str << ",";
      else
	str << " ";
    einfo->print(str, &data[i * einfo->size], mode);
  }
  str << ")";
}

// Temporary VCD_Print function
void array_info::vcd_print(buffer_stream  &str, const void *src,char* translation_table, bool pure)
{
  //str.clean();
  int length = ((array_base*)src)->info->length;
  type_info_interface *einfo = ((array_base*)src)->info->element_type;
  char *data = ((array_base*)src)->data;

  switch (einfo->id) {

  case ENUM:
    {
      char result; 
      str << "b";
      int k = 0;
      for (; k < length; k++)
	if (translation_table [(enumeration) data[k * einfo->size]] != '0')
	  break;
      if (k >= length) 
	k = length - 1;
      
      for (int j = k; j < length; j++)   
	einfo->vcd_print(str, &data [j * einfo->size], translation_table, true);
      
      break;
    }
  case INTEGER: 
  case PHYSICAL:
  case FLOAT:
  case RECORD:
  case ARRAY:
    for (int j = 0; j < length; j++)   
      einfo->vcd_print(str, &data [j * einfo->size], translation_table, false);
    break;
  }
}
// end of Temporary VCD_Print

void *
array_info::element(void *src, acl *a)
{
  if (a == NULL || a->end()) return src;
  array_info &ainfo = *(array_info*)this;
  array_base &abase = *(array_base*)src;

  const int first_value = a->get();
  
  if (first_value != ACL_RANGE) {
    const int org_index = first_value;
    const int index = ainfo.index_direction == to? 
      org_index - ainfo.left_bound : ainfo.left_bound - org_index;
    return ainfo.element_type->element(&abase.data[index * ainfo.element_type->size], 
				       a->next());
  } else {
    // If a is a index range then return the address of the left
    // element of the range! Note that we do not check for null range
    // here!
    const int org_index = a->next()->get();
    const int index = ainfo.index_direction == to? 
      org_index - ainfo.left_bound : ainfo.left_bound - org_index;
    return (void*)&abase.data[index * ainfo.element_type->size];
  }
    
}


void 
array_info::init(void *src)
{
  array_base &abase = *(array_base*)src;
  abase.set_info(this);

  const int size = length * element_type->size;
  const int step = element_type->size;

  /* Do not allocate any data memory if the array info instance is
   * unconstrained */
  if (length < 0) {
    abase.data = NULL;
    return;
  }

  /* Allocate memory for the data */
  abase.data = (char*)internal_dynamic_alloc(size);
  /* Init memory for non scalar element types because (init for these
   * types will try to read the content otherwise; this is not a
   * problem for scalars) */
  if (!element_type->scalar())
    memset(abase.data, 0, size);
  
  /* Initialize each element of the array */
  for (int i = 0; i < size; i+=step)
    element_type->init(&abase.data[i]);
}


void *
array_info::create()
{
  /* Get memory for array object */
  array_base &abase = *(array_base*)internal_dynamic_alloc(sizeof(array_base));
  abase.info = NULL;
  abase.data = NULL;
  /* Initialize object */
  init(&abase);

  return (void*)&abase;
}



void 
array_info::clear(void *src)
{
  array_base &abase = *(array_base*)src;
  array_info &ainfo = *abase.info;
  
  /* Clear each element of the array if they are not scalar! */
  int size = ainfo.length * ainfo.element_type->size;
  if (!element_type->scalar()) {
    int step = ainfo.element_type->size;
    for (int i = 0; i < size; i+=step)
      element_type->clear(&abase.data[i]);
  }

  /* Remove array memory */
  if (abase.data != NULL)
    internal_dynamic_remove(abase.data, size);

  /* The current array info intance is not referenced by this
   * object any more. Hence, decrement its reference counter */
  ainfo.remove_ref();
}


void 
array_info::remove(void *src) 
{
  /* Clear/Remove data structures of the array instance */
  clear(src);
  internal_dynamic_remove(src, sizeof(array_base));
}


void *
array_info::copy(void *dest, const void *src)
{
  array_base &adest = *(array_base*)dest;
  array_base &asrc = *(array_base*)src;
  
  /* Check whether array bounds are compatible */
  if (adest.info != asrc.info)
    if (adest.info->length == -1) {
      /* If the bounds of the destination array are not set then
       * create a new array_info instance. The bounds are derived from
       * the source array */
      array_info *new_info =  
	new array_info(adest.info->element_type, adest.info->index_type, asrc.info->left_bound, 
		       asrc.info->index_direction, asrc.info->right_bound, 1);
      /* remove the old array_info instance */
      adest.info->remove_ref();
      adest.info = new_info;

      /* Allocate memory for the data */
      const int data_size = adest.info->length * adest.info->element_type->size;
      adest.data = (char*)internal_dynamic_alloc(data_size);
      memset(adest.data, 0, data_size);

    } else if (adest.info->length != asrc.info->length)
      error(ERROR_INCOMPATIBLE_ARRAYS);

  /* Copy the data part of the arrays */
  int element_size = adest.info->element_type->size;
  int length = adest.info->length; 
  char *ps = asrc.data, *pd = adest.data; 
  for (int i = 0; i < length; i++) {
    adest.info->element_type->copy(pd, ps);
    ps += element_size;
    pd += element_size;
  }

  return dest;
}


void *
array_info::clone(const void *src)
{
  array_base &asrc = *(array_base*)src;  
  array_base *result = (array_base*)internal_dynamic_alloc(sizeof(array_base));

  result->info = NULL;
  result->data = NULL;
  result->set_info(asrc.info);
 
  if (asrc.info->length == -1) {
    /* If the bounds of the source array are not set then do not
     * allocate data memory */
    result->data = NULL;

  } else {
    /* Copy the data part of the arrays */
    const int element_size = asrc.info->element_type->size;
    const int length = asrc.info->length; 
    const int data_size = element_size * length;
    result->data = (char*)internal_dynamic_alloc(data_size);
    memset(result->data, 0, data_size);
    type_info_interface *element_type = asrc.info->element_type;
    
    char *ps = asrc.data, *pd = result->data; 
    for (int i = 0; i < length; i++) {
      element_type->init(pd);
      element_type->copy(pd, ps);
      ps += element_size;
      pd += element_size;
    }
  }

  return result;
}


/* The methods named "???_match" are used to test the bounds of the
 * current array_info instance. All methods return a pointer to the
 * current array_info instance. */

/* Methods to test whether an array_info instances has bounds and
 * direction as given by a reference array_info instance */
array_info *
array_info::exact_match(type_info_interface *test_info)
{
  int test_left_bound, test_right_bound;
  range_direction test_index_direction;
  test_info->get_bounds(test_left_bound, test_index_direction, test_right_bound);
  if (test_index_direction != index_direction ||
      test_left_bound != left_bound ||
      test_right_bound != right_bound)
    error(ERROR_ARRAY_BOUNDS_MISMATCH);
  
  return this;
}

/* Methods to test whether an array_info instances has bounds le and
 * ri and direction r */
array_info *
array_info::exact_match(int le, range_direction r, int ri)
{
  if (r != index_direction ||
      le != left_bound ||
      ri != right_bound)
    error(ERROR_ARRAY_BOUNDS_MISMATCH);

  return this;
}


/* Methods to test whether an array_info instances has length
 * len */
array_info *
array_info::length_match(int len)
{
  if (len != length)
    error(ERROR_ARRAY_LENGTH_MISMATCH);

  return this;
}



const char *
array_info::read(void *dest, const char *str)
{
  error("Sorry, array_info_base::read is currently not implemented!");
}



/* *************************************************************
 *  Record info class
 * ************************************************************* */

record_info::record_info(int rs, int ds, const char **en,void *(*ea)(void*, int), int rc) :
  type_info_interface(RECORD, record_base::size())
{
  set(rs, ds, en, ea, rc);
}


void 
record_info::print(buffer_stream &str, const void *src, int mode)
{
  record_base &rbase = *(record_base*)src;
  record_info &rinfo = *rbase.info;

  str << "(";
  if (mode == CDFG_PRINT_MODE)
    str << "list ";

  for (int i = 0; i < record_size; i++) {
    type_info_interface &einfo = *rinfo.element_types[i];
    if (i) 
      if (mode == VHDL_PRINT_MODE)
	str << ",";
      else
	str << " ";
    einfo.print(str, (*rinfo.element_addr) (rbase.data, i), mode);
  }

  str << ")";
}


// Temporary VCD_Print function
void record_info::vcd_print(buffer_stream  &str, const void *src, char* translation_table, bool pure)
{
  record_base &record = *(record_base*)src;
  record_info &rinfo = *record.info;
  
  for (int i = 0; i < rinfo.record_size; i++)
    rinfo.element_types [i]->vcd_print(str, (*rinfo.element_addr) (record.data, i), 
				       translation_table, false);
}
// end of Temporary VCD_Print

void *
record_info::element(void *src, acl *a)
{
  if (a->end()) return src;
  record_info &rinfo = *(record_info*)this;
  record_base &rbase = *(record_base*)src;

  // The next number stored in the acl determines the element to be
  // addressed. 0 is asociated with the first element of the record, 1
  // with the second element, ...
  const int i = a->get();
  
  return rinfo.element_types[i]->element ((*rinfo.element_addr) (rbase.data, i), a->next());
}


void 
record_info::init(void *src)
{
  record_base &rbase = *(record_base*)src;
  rbase.set_info(this);

  /* Allocate memory for the data and init it to 0 */
  rbase.data = (char*)internal_dynamic_alloc(data_size);
  memset(rbase.data, 0, data_size);
  
  /* Finally, initialize each element of the record */
  for (int i = 0; i < record_size; i++)
    element_types[i]->init ((*element_addr) (rbase.data, i));
}


void *
record_info::create()
{
  /* Get memory for record object */
  record_base &rbase = *(record_base*)internal_dynamic_alloc(sizeof(record_base));
  rbase.info = NULL;
  rbase.data = NULL;
  /* Initialize object */
  init(&rbase);

  return (void*)&rbase;
}



void 
record_info::clear(void *src)
{
  record_base &rbase = *(record_base*)src;
  record_info &rinfo = *rbase.info;
  
  /* Clear each element of the record if they are not scalar! */
  if (rbase.data != NULL) { 
    int rsize = rinfo.record_size;
    int size = 0;
    for (int i = 0; i < rsize; i++) {
      size += rinfo.element_types[i]->size;
      if (!rinfo.element_types[i]->scalar())
	rinfo.element_types[i]->clear ((*rinfo.element_addr) (rbase.data, i));
    }

    /* Remove record memory */
    internal_dynamic_remove(rbase.data, size);
  }

  /* The current record info intance is not referenced by this object
   * any more. Hence, decrement its reference counter */
  rinfo.remove_ref();
}


void 
record_info::remove(void *src) 
{
  /* Clear/Remove data structures of the record instance */
  clear(src);
  internal_dynamic_remove(src, sizeof(record_base));
}


void *
record_info::copy(void *dest, const void *src)
{
  record_base &rdest = *(record_base*)dest;
  record_base &rsrc = *(record_base*)src;
  record_info &rinfo = *rdest.info;
  
  for (int i = 0; i < rinfo.record_size; i++) 
    {
      rinfo.element_types[i]->copy ((*rinfo.element_addr) (rdest.data, i),
				    (*rinfo.element_addr) (rsrc.data, i));
    }
  
  return dest;
}


void *
record_info::clone(const void *src)
{
  record_base &rsrc = *(record_base*)src;  
  record_base &result = *(record_base*)internal_dynamic_alloc(sizeof(record_base));

  result.info = rsrc.info;
  record_info &rinfo = *result.info;
  result.info->add_ref();
  result.data = (char*)internal_dynamic_alloc(rinfo.data_size);
  memset(result.data, 0, rinfo.data_size);
  
  for (int i = 0; i < rinfo.record_size; i++)
    {
      type_info_interface &etype = *rinfo.element_types [i];
      if (etype.scalar ())
	{
	  etype.fast_copy ((*rinfo.element_addr) (result.data, i),
			   (*rinfo.element_addr) (rsrc.data, i));
	}
      else 
	{
	  etype.init ((*rinfo.element_addr) (result.data, i));
	  etype.copy ((*rinfo.element_addr) (result.data, i),
		      (*rinfo.element_addr) (rsrc.data, i));
	}
    }

  return (void*)&result;
}


const char *
record_info::read(void *dest, const char *str)
{
  error("Sorry, record_info::read is currently not implemented!");
}



/* *************************************************************
 *  Function to implement VHDL file IO operations
 * ************************************************************* */

enumeration 
file_eof(vhdlfile &file) 
{
  // Return true if file is open for writing!
  if (file.out_stream != NULL)
    return 1;  
  // Testing for end of file is a little bit more complex here as
  // eof() returns true not before the read operations fails. Hence,
  // try to read in a character form the stream. If eof() then returns
  // true the end of the file has been reached. Otherwise, put back
  // the character so that it can be read out again from the
  // corresponding file read operations.
  char c;
  file.in_stream->get(c);
  if (file.in_stream->eof())
    return 1;
  else {
    file.in_stream->putback(c);
    return 0;
  }
}


void
file_close(vhdlfile &file)
{
  if (!file.do_close)
    return;
  if (file.in_stream != NULL)
    delete file.in_stream;
  file.in_stream = NULL;
  if (file.out_stream != NULL)
    delete file.out_stream;
  file.out_stream = NULL;
}


void
do_file_open(vhdlfile &file, const array_type<enumeration> &name, enumeration kind)
{
  // Determine file name
  string fname;
  fname.assign(name.data, name.info->length);
  // Open file
  switch (kind) {
  case 0: file.in_stream = new ifstream(fname.c_str(), ios::in); break; // File read
  case 1: file.out_stream = new ofstream(fname.c_str(), ios::out); break; // File write 
  case 2: file.out_stream = new ofstream(fname.c_str(), ios::app); break; // File append
  }
  file.do_close = true;
}

void 
file_open(vhdlfile &file, const array_type<enumeration> &name, enumeration kind)
{
  // Print an error if the file instance is already associated with a
  // file
  if (file.in_stream != NULL || 
      file.out_stream != NULL) 
    error(ERROR_FILE_IO, "File object is alread associated with a file!");
  // Open file
  do_file_open(file, name, kind);
  // Test whether open operation succeeded and print error message in
  // case of a problem.
  if ((file.in_stream != NULL && file.in_stream->bad()) ||
      (file.out_stream != NULL && file.out_stream->bad())) {
    string fname;
    fname.assign(name.data, name.info->length);
    string error_msg = "Could not open file '" + fname + "' for ";
    switch (kind) {
    case 0: error_msg += "reading!"; break;
    case 1: error_msg += "writing!"; break;
    case 2: error_msg += "appending!"; break;
    }
    error(ERROR_FILE_IO, error_msg.c_str());
  }
}

void file_open(enumeration &status, vhdlfile &file, array_type<enumeration> &name, enumeration kind)
{
  status = 0; // OPEN_OK
  // Return an error if file instance is already associated with a
  // file
  if (file.in_stream != NULL || 
      file.out_stream != NULL) {
    status = 1; // STATUS_ERROR
    return;
  }
  // Open file
  do_file_open(file, name, kind);
  // Test whether open operation succeeded. Note that we do not test
  // for MODE_ERROR. If the file could not be opened NAME_ERROR is
  // returned!
  if ((file.in_stream != NULL && file.in_stream->bad()) ||
      (file.out_stream != NULL && file.out_stream->bad())) {
    status = 2; // NAME_ERROR
    return;
  }
}


// Read value from file
void 
file_read_scalar(vhdlfile &file, void *value_p, int size)
{
  // Test whether the file is open
  if (file.in_stream == NULL)
    error(ERROR_FILE_IO, "File not open!");
  // Read value from file
  file.in_stream->read((char *)value_p, size);
}

// Read value from file
void 
file_read_record(vhdlfile &file, void *value_p)
{
  // Test whether the file is open
  if (file.in_stream == NULL)
    error(ERROR_FILE_IO, "File not open!");
}

// Read value from file
void 
file_read_array(vhdlfile &file, void *value_p)
{
  // Test whether the file is open
  if (file.in_stream == NULL)
    error(ERROR_FILE_IO, "File not open!");
  buffer_stream file_buffer_stream;
  array_base &array = *(array_base*)value_p;
  // First, determine number of array elements and buffer size
  // required to read in array data
  int element_count, no_of_bytes;
  file.in_stream->read((char *)&element_count, sizeof(int));
  file.in_stream->read((char *)&no_of_bytes, sizeof(int));
  if (array.info->length != element_count)
    error(ERROR_FILE_IO, "Length of array in file does not match length of array object");
  // Next, read array data into temporary buffer
#ifdef HAVE_ALLOCA
  char *read_buffer = (char*)alloca(no_of_bytes);
#else
  char *read_buffer = (char*)internal_dynamic_alloc (no_of_bytes);
#endif
  file.in_stream->read(read_buffer, no_of_bytes);
  // Finally, write data into array instance
  if (array.info->binary_read(value_p, read_buffer) != no_of_bytes)
    {
#ifndef HAVE_ALLOCA
      internal_dynamic_remove (read_buffer, no_of_bytes);
#endif
      error(ERROR_FILE_IO, "File format error");
    }

#ifndef HAVE_ALLOCA
  internal_dynamic_remove (read_buffer, no_of_bytes);
#endif
}


// Read unconstrained array value from file 
void 
file_read_array(vhdlfile &file, void *value_p, integer &length)
{
  // Test whether the file is open
  if (file.in_stream == NULL)
    error(ERROR_FILE_IO, "File not open!");
  buffer_stream file_buffer_stream;
  array_base &array = *(array_base*)value_p;
  // First, determine number of array elements and buffer size
  // required to read in array data
  int element_count, no_of_bytes;
  file.in_stream->read((char *)&element_count, sizeof(int));
  file.in_stream->read((char *)&no_of_bytes, sizeof(int));
  // Next, read array data into temporary buffer
#ifdef HAVE_ALLOCA
  char *read_buffer = (char*)alloca(no_of_bytes);
#else
  char *read_buffer = (char*)internal_dynamic_alloc (no_of_bytes);
#endif
  file.in_stream->read(read_buffer, no_of_bytes);
  // Create a new array which has the right size to hold the array
  // data read from the file
  array_info *new_info = new array_info(array.info->element_type, array.info->index_type, element_count, 0);
  array_base *new_array = (array_base*)new_info->create();
  // Read file data into new array
  if (new_info->binary_read(value_p, read_buffer) != no_of_bytes)
    {
#ifndef HAVE_ALLOCA
      internal_dynamic_remove (read_buffer, no_of_bytes);
#endif
      error(ERROR_FILE_IO, "File format error");
    }
  // Determine number of array elements which are written back to the
  // array instance and copy only those elements!
  int element_size = array.info->element_type->size;
  int elements_to_write = min(element_count, array.info->length);
  type_info_interface *element_info = array.info->element_type;
  char *pd = array.data, *ps = new_array->data;
  for (int i = 0; i < elements_to_write; i++, pd += element_size, ps += element_size)
    array.info->element_type->copy(pd, ps);
  // Return number of elements written back to the array instance
  length = elements_to_write;
  // Remove temporary array
  new_info->remove(new_array);
#ifndef HAVE_ALLOCA
  internal_dynamic_remove (read_buffer, no_of_bytes);
#endif
}



// Write value to a file
void 
file_write_scalar(vhdlfile &file, const void *value_p, int size)
{
  // Test whether the file is open
  if (file.out_stream == NULL)
    error(ERROR_FILE_IO, "File not open!");
  // Write value to file
  file.out_stream->write((char *)value_p, size);
  // Check stream status
  if (file.out_stream->bad())
    error(ERROR_FILE_IO, "File format error");
}


// Write value to a file
void 
file_write_array(vhdlfile &file, const void *value_p)
{
  // Test whether the file is open
  if (file.out_stream == NULL)
    error(ERROR_FILE_IO, "File not open!");
  buffer_stream file_buffer_stream;
  array_base &array = *(array_base*)value_p;
  // Print content of array to stream
  int num_of_bytes = array.info->binary_print(file_buffer_stream, &array);
  // Write length of array, number of bytes and then buffer content to file
  file.out_stream->write((char *)&array.info->length, sizeof(int));
  file.out_stream->write((char *)&num_of_bytes, sizeof(int));
  file.out_stream->write(file_buffer_stream.str(), file_buffer_stream.str_len());
  // Check stream status
  if (file.out_stream->bad())
    error(ERROR_FILE_IO, "File format error");
}


// Write value to a file
void 
file_write_record(vhdlfile &file, const void *value_p)
{
  // Test whether the file is open
  if (file.out_stream == NULL)
    error(ERROR_FILE_IO, "File not open!");
  // Check stream status
  if (file.out_stream->bad())
    error(ERROR_FILE_IO, "File format error");
}


