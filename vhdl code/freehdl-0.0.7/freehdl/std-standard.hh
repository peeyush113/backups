#ifndef FREEHDL_STD_STANDARD_H
#define FREEHDL_STD_STANDARD_H

#include <float.h>
#include <limits.h>
#include <freehdl/std-vhdl-types.hh>

/* ***************************************************************
 * Predefined VHDL types
 * *************************************************************** */

/** Enum info class of predefined VHDL type CHARACTER */
class L3std_Q8standard_I9character : public enum_info_base {
  static const char *values[256]; //={"'0'", "'1'"};
public:
  L3std_Q8standard_I9character() : enum_info_base(0, 255, values) {};
  static const char **get_values() { return values; }
  static int low() { return 0; }
  static int high() { return 255; }
  static int left() { return 0; }
  static int right() { return 255; }
};

extern L3std_Q8standard_I9character L3std_Q8standard_I9character_INFO;
#define character enumeration


/** Enum info class of predefined VHDL type BIT */
class L3std_Q8standard_I3bit : public enum_info_base {
  static const char *values[2]; //={"'0'", "'1'"};
public:
  L3std_Q8standard_I3bit() : enum_info_base(0, 1, values) {};
  static const char **get_values() { return values; }
  static int low() { return 0; }
  static int high() { return 1; }
  static int left() { return 0; }
  static int right() { return 1; }
};

extern L3std_Q8standard_I3bit L3std_Q8standard_I3bit_INFO;
#define bit enumeration




/** Enum info class of predefined VHDL type BOOLEAN */
class L3std_Q8standard_I7boolean : public enum_info_base {
  static const char *values[2]; //={"'0'", "'1'"};
public:
  L3std_Q8standard_I7boolean() : enum_info_base(0, 1, values) {};
  static const char **get_values() { return values; }
  static int low() { return 0; }
  static int high() { return 1; }
  static int left() { return 0; }
  static int right() { return 1; }
};


extern L3std_Q8standard_I7boolean L3std_Q8standard_I7boolean_INFO;
#define L3std_Q8standard_T7boolean boolean_enum_type
#define boolean enumeration


/** Enum info class of predefined VHDL type severity_level */
class L3std_Q8standard_I14severity_level : public enum_info_base {
  static const char *values[4];
public:
  L3std_Q8standard_I14severity_level() : enum_info_base(0, 3, values) {};
  static const char **get_values() { return values; }
  static int low() { return 0; }
  static int high() { return 3; }
  static int left() { return 0; }
  static int right() { return 3; }
};

extern L3std_Q8standard_I14severity_level L3std_Q8standard_I14severity_level_INFO;
#define severity_level enumeration



/** Integer info class of predefined VHDL INTEGER type */
class L3std_Q8standard_I7integer : public integer_info_base {
public:
  static integer low() { return INT_MIN+1; };
  static integer high() { return INT_MAX; }
  static integer left() { return INT_MIN+1; }
  static integer right() { return INT_MAX; }
  L3std_Q8standard_I7integer() : 
    integer_info_base(left(), right(), low(), high()) {};
};


extern L3std_Q8standard_I7integer L3std_Q8standard_I7integer_INFO;


/** Integer info class of predefined VHDL NATURAL type */
class L3std_Q8standard_I7natural : public integer_info_base {
public:
  static integer low() { return 0; };
  static integer high() { return INT_MAX; }
  static integer left() { return 0; }
  static integer right() { return INT_MAX; }
  L3std_Q8standard_I7natural() : 
    integer_info_base(left(), right(), low(), high()) {};
};

extern L3std_Q8standard_I7natural L3std_Q8standard_I7natural_INFO;
#define natural integer


/** Integer info class of predefined VHDL POSITIVE type */
class L3std_Q8standard_I8positive : public integer_info_base {
public:
  static integer low() { return 1; };
  static integer high() { return INT_MAX; }
  static integer left() { return 1; }
  static integer right() { return INT_MAX; }
  L3std_Q8standard_I8positive() : 
    integer_info_base(left(), right(), low(), high()) {};
};

extern L3std_Q8standard_I8positive L3std_Q8standard_I8positive_INFO;
#define positive integer


/** Floatig point info class of predefined VHDL REAL type */
class L3std_Q8standard_I4real : public float_info_base {
public:
  static floatingpoint low() { return -DBL_MAX; };
  static floatingpoint high() { return DBL_MAX; }
  static floatingpoint left() { return -DBL_MAX; }
  static floatingpoint right() { return DBL_MAX; }
  L3std_Q8standard_I4real() : 
    float_info_base(left(), right(), low(), high()) {};
};

extern L3std_Q8standard_I4real L3std_Q8standard_I4real_INFO;
#define real floatingpoint

#ifndef __LONG_LONG_MAX__
#define __LONG_LONG_MAX__ 9223372036854775807LL
#endif
#ifndef LONG_LONG_MIN
#define LONG_LONG_MIN (-__LONG_LONG_MAX__-1)
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX __LONG_LONG_MAX__
#endif

/** Physical point info class of predefined VHDL TIME type */
class L3std_Q8standard_I4time : public physical_info_base {
public:
  const static long unit_count = 7;
  const static char *units[7];
  const static physical scale[7];
  static physical low() { return LONG_LONG_MIN; };
  static physical high() { return LONG_LONG_MAX; }
  static physical left() { return LONG_LONG_MIN; }
  static physical right() { return LONG_LONG_MAX; }
  L3std_Q8standard_I4time() : 
    physical_info_base(left(), right(), low(), high(), units, scale, unit_count) {};
};


extern L3std_Q8standard_I4time L3std_Q8standard_I4time_INFO;
#define L3std_Q8standard_T4time physical_type<L3std_Q8standard_I4time>
// Just to save some typing
#define vtime physical


/** Predefined array type bit_vector */
extern array_info L3std_Q8standard_I10bit_vector_INFO;
#define L3std_Q8standard_T10bit_vector array_type<bit>
// Just to save some typing
#define vbit_vector L3std_Q8standard_T10bit_vector


/** Predefined array type string */
extern array_info L3std_Q8standard_I6string_INFO;
#define L3std_Q8standard_T6string array_type<character>
// Just to save some typing
#define vstring L3std_Q8standard_T6string


extern void report (const vstring&, severity_level);
extern void report (severity_level);
extern lint attribute_value (type_info_interface *, const vstring &);
extern vstring attribute_image (type_info_interface *, const void *);

// Predefined function "now"
extern vtime L3std_Q8standard_Y3now_i303();

/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

// Min severity level of assert or report messages that will cause the
// simulator to stop execution
extern severity_level exit_severity_level;



// Convert simulation time to string
inline string time_to_string (const physical t)
{
  lint tval = t < 0? -t : t;
  int i = 0;
  
  if (tval != 0) {
    for (i=1; i < L3std_Q8standard_I4time::unit_count; i++)
      if (tval % L3std_Q8standard_I4time::scale[i] != 0) { i--; break; }
    tval = tval / L3std_Q8standard_I4time::scale[i];
  }

  return to_string (lint (t < 0? -1 : 1) * tval) + " " + L3std_Q8standard_I4time::units[i];
}

#endif
/******************************************************
 * End of kernel only definitions
 ******************************************************/

#endif
