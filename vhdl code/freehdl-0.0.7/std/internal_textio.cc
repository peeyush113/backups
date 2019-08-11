#if HAVE_ALLOCA_H
#include <alloca.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <sstream>
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/std-standard.hh>
#include <freehdl/kernel-name-stack.hh>
#include <freehdl/kernel-register.hh>

/* package :std:textio */

/* Definitions for access type :std:textio:line */
#define L3std_Q6textio_I4line access_info_base
extern access_info_base L3std_Q6textio_I4line_INFO;

/* Definitions for file type :std:textio:text */
#define L3std_Q6textio_I4text vhdlfile_info_base
extern vhdlfile_info_base L3std_Q6textio_I4text_INFO;

/* Definitions for enumeration type :std:textio:side */
class L3std_Q6textio_I4side:public enum_info_base{
   static const char *values[];
public:
   L3std_Q6textio_I4side():enum_info_base(0,1,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 1; }
   static int left() { return 0; }
   static int right() { return 1; }
};
extern L3std_Q6textio_I4side L3std_Q6textio_I4side_INFO;

/* Definitions for sutype :std:textio:width */
#define L3std_Q6textio_I5width L3std_Q8standard_I7natural
extern L3std_Q6textio_I5width L3std_Q6textio_I5width_INFO;

/* Prototype for predefined subprogram L3std_Q6textio_X10deallocate_i7 */
#define L3std_Q6textio_X10deallocate_i7(p,a) p=(p!=NULL?(a.designated_type_info->remove(p),(void*)NULL):(void*)NULL)

/* Prototype for predefined subprogram L3std_Q6textio_X9file_open_i11 */
#define L3std_Q6textio_X9file_open_i11(f,n,k) file_open(f,n,k)

/* Prototype for predefined subprogram L3std_Q6textio_X9file_open_i12 */
#define L3std_Q6textio_X9file_open_i12(s,f,n,k) file_open(s,f,n,k)

/* Prototype for predefined subprogram L3std_Q6textio_X10file_close_i13 */
#define L3std_Q6textio_X10file_close_i13(f) file_close(f)

/* Prototype for predefined subprogram L3std_Q6textio_X4read_i14 */
#define L3std_Q6textio_X4read_i14(f,v,l) file_read_array(f,&v,l)

/* Prototype for predefined subprogram L3std_Q6textio_X5write_i15 */
#define L3std_Q6textio_X5write_i15(f,v) file_write_array(f,const_pointer(v))

/* Prototype for predefined function L3std_Q6textio_Y7endfile_i16 */
#define L3std_Q6textio_Y7endfile_i16(f) file_eof(f)



// Temporary buffer for file read/write operations
#define TEXTIO_BUFFER_SIZE 1024
char textio_buf[TEXTIO_BUFFER_SIZE];

// White spaces
const char *whitespaces = " \t";

/* Implementation of subprogram :std:textio:readline */
void 
L3std_Q6textio_X8readline_i31(vhdlfile &file,vhdlaccess &line)
{
  // If line is pointing to a line then free line
  if (line != NULL) {
    L3std_Q6textio_I4line_INFO.remove(line);
    line = NULL;
  }
  // Test whether the file is open
  if (file.in_stream == NULL ||
      file.in_stream->bad ())
    error(ERROR_FILE_IO, "File not open or cannot read file!");

  // If end of file reached then return a NULL pointer
  if (file.in_stream->eof()) {
    line = NULL;
    return;
  }

  // Read in a line. Note that more than one read operation may be
  // required if the line is longer than TEXTIO_BUFFER_SIZE. The
  // resulting string is stored into str.
  string str;
  while (true) {
    file.in_stream->get(textio_buf, TEXTIO_BUFFER_SIZE, '\n');
    // If end of file reached then return a NULL pointer
    if (textio_buf [0] == '\0')
      {
	line = NULL;
	return;
      }

    str += textio_buf;
    char c;
    if (file.in_stream->eof() ||
	(file.in_stream->get(c) && c == '\n'))
      break;
  }

  // Check stream status
  if (file.in_stream->bad())
    error(ERROR_FILE_IO, "File input error");

  // Create a new line object and copy text into it.
  array_info *info = new array_info((&L3std_Q8standard_I6string_INFO)->element_type,
				    (&L3std_Q8standard_I6string_INFO)->index_type,
				    1,to,str.length(),0);
  array_base *new_line = (array_base*)info->create();
  if (str.length() != 0)
    memcpy(new_line->data, str.c_str(), str.length());
  
  // Finally, return new line.
  line = (vhdlaccess)new_line;
}


// Search for the next character not equal one of the characters
// included in parameter ignore. Returns true if end of string has
// been reached.
bool
skip_chars(char *&p, char *end, const char *ignore)
{
  while (p < end) {
    const char *test_char = ignore;

    while (*test_char != '\0')
      if (*test_char == *p) 
	break;
      else
	test_char++;

    if (*test_char == '\0') 
      return p == end;
    p++;
  }
  return true;
}


// Accept chars from char string p and return lowercase converted
// string. However, only characters included in accept are accepted.
string
accept_chars(char *&p, char *end, const char *accept)
{
  string result;
  while (p < end) {
    const char *test_char = accept;
    while (*test_char != '\0')
      if (*test_char == *p)
	break;
      else
	test_char++;
    if (*test_char == '\0')
      return result;
    result += tolower(*p);
    p++;
  }
  return result;
}


vhdlaccess
create_line(const char *p, const char *end)
{
  // Create a new line object and copy text into it.
  const int new_length = (int)(end - p);
  array_info *info = new array_info((&L3std_Q8standard_I6string_INFO)->element_type,
				    (&L3std_Q8standard_I6string_INFO)->index_type,
				    1,to,new_length,0);
  array_base *new_array = (array_base*)info->create();
  if (new_length != 0)
    memcpy(new_array->data, p, new_length);

  return new_array;
}


/* ***************************************************************** */
/* Prototype for subprogram :std:textio:read for type BIT  */
/* ***************************************************************** */
void 
L3std_Q6textio_X4read_i35(vhdlaccess &line, enumeration &value, enumeration &good)
{
  good = 0; // Assume that operation failes
  if (line == NULL) return;
  array_base &array = *(array_base*)line;
  int length = array.info->length;
  if (length == 0) return;

  char *p = array.data, *end = &array.data[length];
  // Skip leading spaces
  if (skip_chars(p, end, whitespaces)) return;

  string str = accept_chars(p, end, "01");

  if (str == "0")
    value = 0;
  else if (str == "1")
    value = 1;
  else
    return;
  
  // Create new line
  vhdlaccess new_line = create_line(p, end);
  // Remove old line
  L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Operation succeeded
  good = 1;
  
  line = new_line;
}


/* Prototype for subprogram :std:textio:read for type BIT */
void 
L3std_Q6textio_X4read_i38(vhdlaccess &line, enumeration &value)
{
  enumeration good;
  L3std_Q6textio_X4read_i35(line, value, good);
  if (good == 0)
    error(ERROR_TEXTIO, "read operation for type BIT failed");
}


/* ***************************************************************** */
/* Implementation of subprogram :std:textio:read for type BIT_VECTOR */
/* ***************************************************************** */
void 
L3std_Q6textio_X4read_i42(vhdlaccess &line, L3std_Q8standard_T10bit_vector &value, enumeration &good)
{
  good = 0; // Assume that operation failes
  if (line == NULL) return;
  array_base &array = *(array_base*)line;
  int length = array.info->length;
  if (length == 0) return;

  char *p = array.data, *end = &array.data[length];
  // Skip leading spaces
  if (skip_chars(p, end, whitespaces))
    return;

  int vector_length = value.info->length;
  // Does the remaining string contain enough characters?
  if ((int)(end - p) < vector_length)
    return;
    
#ifdef HAVE_ALLOCA
  enumeration *new_value = (enumeration*)alloca (sizeof(enumeration) * vector_length);
#else
  int mem_size;
  enumeration *new_value = (enumeration*)internal_dynamic_alloc (mem_size = sizeof(enumeration) * vector_length);
#endif
  for (int i = 0; i < vector_length; i++, p++)
    if (*p == '0')
      new_value[i] = 0;
    else if (*p == '1') 
      new_value[i] = 1;
    else 
      return;

  // Operation succeeded
  memcpy(value.data, new_value, vector_length); 
  
  vhdlaccess new_line = create_line(p, end);
  // Operation succeeded
  // Remove old line
  L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Create new line
  good = 1;

  line = new_line;

#ifndef HAVE_ALLOCA
  internal_dynamic_remove (new_value, mem_size);
#endif
}


/* Implementation of subprogram :std:textio:read for type BIT_VECTOR */
void 
L3std_Q6textio_X4read_i45(vhdlaccess &line, L3std_Q8standard_T10bit_vector &value)
{
  enumeration good;
  L3std_Q6textio_X4read_i42(line, value, good);
  if (good == 0)
    error(ERROR_TEXTIO, "read operation for type BIT_VECTOR failed");
}


/* ***************************************************************** */
/* Implementation of subprogram std:textio:read for VHDL type BOOLEAN */
/* ***************************************************************** */
void 
L3std_Q6textio_X4read_i49(vhdlaccess &line, enumeration &value, enumeration &good)
{
  good = 0; // Assume that operation failes
  if (line == NULL) return;
  array_base &array = *(array_base*)line;
  int length = array.info->length;
  if (length == 0) return;

  char *p = array.data, *end = &array.data[length];
  // Skip leading spaces
  if (skip_chars(p, end, whitespaces)) return;

  string str = accept_chars(p, end, "falsetrueFALSETRUE");

  if (str == "false")
    value = 0;
  else if (str == "true")
    value = 1;
  else
    return;
  
  // Create new line
  vhdlaccess new_line = create_line(p, end);
  // Remove old line
  L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Operation succeeded
  good = 1;

  line = new_line;
}

/* Implementation of subprogram std:textio:read for type BOOLEAN */
void 
L3std_Q6textio_X4read_i52(vhdlaccess &line, enumeration &value) 
{
  enumeration good;
  L3std_Q6textio_X4read_i49(line, value, good);
  if (good == 0)
    error(ERROR_TEXTIO, "read operation for type BOOLEAN failed");
}

/* ***************************************************************** */
/* Implementation of subprogram :std:textio:read for type CHARACTER */
/* ***************************************************************** */
void 
L3std_Q6textio_X4read_i56(vhdlaccess &line, enumeration &value, enumeration &good)
{
  good = 0; // Assume that operation failes
  if (line == NULL) return;
  array_base &array = *(array_base*)line;
  int length = array.info->length;
  if (length == 0) return;

  char *p = array.data, *end = &array.data[length];

  value = *p;
  p++;
  
  // Create new line
  vhdlaccess new_line = create_line(p, end);
  // Remove old line
  L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Operation succeeded
  good = 1;

  line = new_line;
}

/* Implementation of subprogram :std:textio:read for type CHARACTER */
void 
L3std_Q6textio_X4read_i59(vhdlaccess &line, enumeration &value)
{
  enumeration good;
  L3std_Q6textio_X4read_i56(line, value, good);
  if (good == 0)
    error(ERROR_TEXTIO, "read operation for type CHARACTER failed");
}


/* ***************************************************************** */
/* Implementation of subprogram :std:textio:read for type INTEGER */
/* ***************************************************************** */


void 
L3std_Q6textio_X4read_i63(vhdlaccess &line, integer &value, enumeration &good)
{
  good = 0; // Assume that operation failes
  if (line == NULL) return;
  array_base &array = *(array_base*)line;
  int length = array.info->length;
  if (length == 0) return;

  char *p = array.data, *end = &array.data[length];
  // Skip leading spaces
  if (skip_chars(p, end, whitespaces)) return;

  string str = accept_chars(p, end, "-0123456789abcdefABCDEF_#");

  // Convert string to integer and check result
  integer result;
  if (L3std_Q8standard_I7integer_INFO.read(&result, str.c_str()) != NULL)
    return;
  value = result;
  L3std_Q8standard_I7integer_INFO.check(value);
  
  // Create new line
  vhdlaccess new_line = create_line(p, end);
  // Remove old line
  L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Operation succeeded
  good = 1;  

  line = new_line;
}

/* Implementation of subprogram :std:textio:read */
void 
L3std_Q6textio_X4read_i66(vhdlaccess &line, integer &value)
{
  enumeration good;
  L3std_Q6textio_X4read_i63(line, value, good);
  if (good == 0)
    error(ERROR_TEXTIO, "read operation for type INTEGER failed");
}


/* ***************************************************************** */
/* Implementation of subprogram :std:textio:read for type REAL */
/* ***************************************************************** */

void L3std_Q6textio_X4read_i70(vhdlaccess &line, floatingpoint &value, enumeration &good)
{
  good = 0; // Assume that operation failes
  if (line == NULL) return;
  array_base &array = *(array_base*)line;
  int length = array.info->length;
  if (length == 0) return;

  char *p = array.data, *end = &array.data[length];
  // Skip leading spaces
  if (skip_chars(p, end, whitespaces)) return;

  string str = accept_chars(p, end, "-0123456789abcdefABCDEF_#.");

  // Convert string to floating point and check result
  floatingpoint result;
  if (L3std_Q8standard_I4real_INFO.read(&result, str.c_str()) != NULL)
    return;
  value = result;
  L3std_Q8standard_I4real_INFO.check(value);
  
  // Create new line
  vhdlaccess new_line = create_line(p, end);
  // Remove old line
  L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Operation succeeded
  good = 1;  

  line = new_line;
}

/* Implementation of subprogram :std:textio:read for type REAL */
void L3std_Q6textio_X4read_i73(vhdlaccess &line, floatingpoint &value)
{
  enumeration good;
  L3std_Q6textio_X4read_i70(line, value, good);
  if (good == 0)
    error(ERROR_TEXTIO, "read operation for type REAL failed");
}

/* ***************************************************************** */
/* Implementation of subprogram :std:textio:read for type STRING */
/* ***************************************************************** */
void L3std_Q6textio_X4read_i77(vhdlaccess &line, L3std_Q8standard_T6string &value, enumeration &good)
{
  good = 0; // Assume that operation failes
  if (line == NULL) return;
  array_base &array = *(array_base*)line;
  int length = array.info->length;
  if (length == 0) return;

  char *p = array.data, *end = &array.data[length];

  int vector_length = value.info->length;
  // Does the remaining string contain enough characters?
  if ((int)(end - p) < vector_length)
    return;
    
  // Copy string
  memcpy(value.data, p, vector_length); 
  
  // Create new line
  vhdlaccess new_line = create_line(p, end);
  // Remove old line
  L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Operation succeeded
  good = 1;

  line = new_line;
}

/* Implementation of subprogram :std:textio:read for type STRING */
void L3std_Q6textio_X4read_i80(vhdlaccess &line, L3std_Q8standard_T6string &value)
{
  enumeration good;
  L3std_Q6textio_X4read_i77(line, value, good);
  if (good == 0)
    error(ERROR_TEXTIO, "read operation for type STRING failed");
}


/* ***************************************************************** */
/* Implementation of subprogram :std:textio:read for type TIME */
/* ***************************************************************** */
void L3std_Q6textio_X4read_i84(vhdlaccess &line, physical &value, enumeration &good)
{
  good = 0; // Assume that operation failes
  if (line == NULL) return;
  array_base &array = *(array_base*)line;
  int length = array.info->length;
  if (length == 0) return;

  char *p = array.data, *end = &array.data[length];
  // Skip leading spaces
  if (skip_chars(p, end, whitespaces)) return;
  string str = accept_chars(p, end, "0123456789abcdefABCDEF_#.");
  // Test whether value and unit are separated by a space
  if (*p != ' '  && *p != '\t')
    return;
  // Skip leading spaces
  if (skip_chars(p, end, whitespaces)) return;
  str += " " + accept_chars(p, end, "0123456789abcdefABCDEF_#spnumch");

  // Convert string to floating point and check result
  physical result;
  if (L3std_Q8standard_I4time_INFO.read(&result, str.c_str()) != NULL)
    return;
  value = result;
  L3std_Q8standard_I4time_INFO.check(value);
  
  // Create new line
  vhdlaccess new_line = create_line(p, end);
  // Remove old line
  L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Operation succeeded
  good = 1;  

  line = new_line;
}

/* Implementation of subprogram :std:textio:read for type TIME */
void L3std_Q6textio_X4read_i87(vhdlaccess &line, physical &value)
{
  enumeration good;
  L3std_Q6textio_X4read_i84(line, value, good);
  if (good == 0)
    error(ERROR_TEXTIO, "read operation for type TIME failed");
}




/* ***************************************************************** */
/* Implementation of subprogram :std:textio:writeline */
/* ***************************************************************** */
void 
L3std_Q6textio_X9writeline_i90(vhdlfile &file, vhdlaccess &line)
{
  // Test whether the file is open
  if (file.out_stream == NULL)
    error(ERROR_FILE_IO, "File not open!");

  // Write line to file and add newline to the end of the line
  if (line != NULL) {
    array_base &str_array = *(array_base*)line;
    if (str_array.info->length > 0)
      file.out_stream->write(str_array.data, str_array.info->length);
  }
  file.out_stream->put('\n');

  // Check stream status
  if (file.out_stream->bad())
    error(ERROR_FILE_IO, "File output error");

  // Remove old line
  if (line != NULL)
    L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);
  // Create new line which is pointing to a NULL string
  line = create_line(NULL, NULL);
}


/* ***************************************************************** */
/* Implementation of subprogram :std:textio:write for type BIT */
/* ***************************************************************** */

class v_strstream : public stringstream {
public:
  void side(enumeration s) {
    switch (s) {
    case 0: setf(ios::right, ios::adjustfield); break;
    case 1: setf(ios::left, ios::adjustfield); break;
    }  
  }
};

vhdlaccess
append_to_line(vhdlaccess line, const char *p)
{
  const int old_length = line == NULL? 0 : ((array_base*)line)->info->length;
  // Create a new line object and copy text into it.
  const int new_length = strlen(p) + old_length;
  array_info *info = new array_info((&L3std_Q8standard_I6string_INFO)->element_type,
				    (&L3std_Q8standard_I6string_INFO)->index_type,
				    1,to,new_length,0);
  array_base *new_array = (array_base*)info->create();
  if (old_length != 0)
    memcpy(new_array->data, ((array_base*)line)->data, old_length);
  if (new_length != 0)
    memcpy(&new_array->data[old_length], p, new_length - old_length);

  // Remove old line
  if (line != NULL)
    L3std_Q6textio_I4line_INFO.designated_type_info->remove(line);

  return new_array;
}

void 
L3std_Q6textio_X5write_i95(vhdlaccess &line, const enumeration value, const enumeration side, const integer width)
{
  v_strstream lstr;
  lstr.width(width);
  lstr.side(side);

  lstr << (int)value;
  
  line = append_to_line(line, lstr.str ().c_str ());
}

/* ***************************************************************** */
/* Implementation of subprogram :std:textio:write for type BIT_VECTOR */
/* ***************************************************************** */
void 
L3std_Q6textio_X5write_i100(vhdlaccess &line, const L3std_Q8standard_T10bit_vector &value, 
			    const enumeration side, const integer width)
{
#ifdef HAVE_ALLOCA
  char *str = (char*)alloca (sizeof(char) * (value.info->length + 1));
#else
  int mem_size;
  char *str = (char*)internal_dynamic_alloc (mem_size = sizeof(char) * (value.info->length + 1));
#endif
  int i;
  for (i = 0; i < value.info->length; i++)
    str[i] = '0' + value.data[i];
  str[i] = '\0';

  v_strstream lstr;
  lstr.width(width);
  lstr.side(side);
  lstr << str;
  
  line = append_to_line(line, lstr.str ().c_str ());
#ifndef HAVE_ALLOCA
  internal_dynamic_remove (str, mem_size);
#endif
}

/* ***************************************************************** */
/* Implemenation of subprogram :std:textio:write BOOLEAN */
/* ***************************************************************** */
void 
L3std_Q6textio_X5write_i105(vhdlaccess &line, const enumeration value, const enumeration side, const integer width)
{
  v_strstream lstr;
  lstr.width(width);
  lstr.side(side);
  if (value == 0)
    lstr << "false";
  else
    lstr << "true";
  
  line = append_to_line(line, lstr.str ().c_str ());
}

/* ***************************************************************** */
/* Implementation of subprogram :std:textio:write for type CHARACTER */
/* ***************************************************************** */
void 
L3std_Q6textio_X5write_i110(vhdlaccess &line, const enumeration value, const enumeration side, const integer width)
{
  v_strstream lstr;
  lstr.width(width);
  lstr.side(side);
  lstr << (char)value;

  line = append_to_line(line, lstr.str ().c_str ());
}

/* ***************************************************************** */
/* Implementation of subprogram :std:textio:write for type INTEGER */
/* ***************************************************************** */
void 
L3std_Q6textio_X5write_i115(vhdlaccess &line, const integer value, const enumeration side, const integer width)
{
  v_strstream lstr;
  lstr.width(width);
  lstr.side(side);
  lstr << value;

  line = append_to_line(line, lstr.str ().c_str ());
}

/* ***************************************************************** */
/* Implementation of subprogram :std:textio:write for type REAL */
/* ***************************************************************** */
void 
L3std_Q6textio_X5write_i121(vhdlaccess &line, const floatingpoint value, const enumeration side, 
			    const integer width, const integer digits)
{
  v_strstream lstr;
  lstr.width(width);
  lstr.side(side);
  if (digits == 0) {
    lstr.setf(ios::scientific, ios::floatfield);
    lstr.precision(6);
  } else {
    lstr.setf(ios::fixed, ios::floatfield);
    lstr.precision(digits);
  }
  lstr << value;

  line = append_to_line(line, lstr.str ().c_str ());
}

/* ***************************************************************** */
/* Implementation of subprogram :std:textio:write for type STRING */
/* ***************************************************************** */
void 
L3std_Q6textio_X5write_i126(vhdlaccess &line, const L3std_Q8standard_T6string &value, 
			    const enumeration side, const integer width)
{
  v_strstream lstr;
  lstr.width(width);
  lstr.side(side);
#ifdef HAVE_ALLOCA
  char *str = (char*)alloca (sizeof(char) * (value.info->length + 1));
#else
  int memsize;
  char *str = (char*)internal_dynamic_alloc (mem_size = sizeof(char) * (value.info->length + 1));
#endif
  memcpy(str, value.data, value.info->length);
  str[value.info->length] = '\0';
  lstr << str;

  line = append_to_line(line, lstr.str ().c_str ());
#ifndef HAVE_ALLOCA
  internal_dynamic_remove (str, mem_size);
#endif
}

/* ***************************************************************** */
/* Implementation of subprogram :std:textio:write for type TIME */
/* ***************************************************************** */
void 
L3std_Q6textio_X5write_i132(vhdlaccess &line, const physical value, const enumeration side, 
			    const integer width, const physical unit)
{
  v_strstream tmp_lstr;

  // Print time value
  if (unit * (value / unit) == value) {
    // value / unit does not have an fractional part
    physical result = value / unit;
    tmp_lstr << result << " ";
  } else {
    floatingpoint result = (double)value / (double)unit;
    tmp_lstr << result << " ";
  }

  // Print time unit
  int i;
  for (i = 0; i < L3std_Q8standard_I4time_INFO.unit_count; i++)
    if (L3std_Q8standard_I4time_INFO.scale[i] == unit)
      break;
  if (i == L3std_Q8standard_I4time_INFO.unit_count)
    error(ERROR_TEXTIO, "write called with an illegal time unit value");
  tmp_lstr << L3std_Q8standard_I4time_INFO.units[i] << '\0';

  v_strstream lstr;
  lstr.width(width);
  lstr.side(side);
  lstr << tmp_lstr.str();

  line = append_to_line(line, lstr.str ().c_str ());
}


/* Terminal IO streams */
vhdlfile L3std_Q6textio_V5input, L3std_Q6textio_V6output;


L3std_Q6textio_I4line L3std_Q6textio_I4line_INFO;
L3std_Q6textio_I4text L3std_Q6textio_I4text_INFO;

/* Implementation of enumeration type :std:textio:side */
const char *L3std_Q6textio_I4side::values[]={"RIGHT","LEFT"};
L3std_Q6textio_I4side L3std_Q6textio_I4side_INFO;
L3std_Q6textio_I5width L3std_Q6textio_I5width_INFO;

/* Initialization function for body :std:textio */
bool L3std_Q6textio_init_done = false;
int L3std_Q6textio_init(){
  extern int L3std_Q8standard_init();
  if (L3std_Q6textio_init_done) return 1;
  L3std_Q6textio_init_done=true;
  L3std_Q8standard_init();
  name_stack iname;
  iname.push("");
  void *sref=register_package(":std",":textio");
  L3std_Q6textio_I4line_INFO.set((&L3std_Q8standard_I6string_INFO)).register_type(":std:textio",":std:textio:line","LINE",NULL);
  L3std_Q6textio_I4text_INFO.set((&L3std_Q8standard_I6string_INFO)).register_type(":std:textio",":std:textio:text","TEXT",NULL);
  L3std_Q6textio_I4side_INFO.register_type(":std:textio",":std:textio:side","SIDE",NULL);
  L3std_Q6textio_I5width_INFO.set((&L3std_Q8standard_I7natural_INFO)).register_type(":std:textio",":std:textio:width","WIDTH",NULL);
  // Init terminal IO streams
  L3std_Q6textio_V5input.in_stream = &cin;
  L3std_Q6textio_V5input.do_close = true;
  L3std_Q6textio_V6output.out_stream = &cout;
  L3std_Q6textio_V6output.do_close = true;

  iname.pop();
  return 1;
}

//int L3std_Q6textio_init_var=L3std_Q6textio_init();

/* end of package :std:textio */
