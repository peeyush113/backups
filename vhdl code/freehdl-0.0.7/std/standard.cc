#define KERNEL
#if HAVE_ALLOCA_H
#include <alloca.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <list>
#include <freehdl/std-standard.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <freehdl/kernel-register.hh>
#include <freehdl/kernel-util.hh>
#include <freehdl/kernel-stack-trace.hh>
#include <freehdl/kernel-fhdl-stream.hh>

// Map to store information about resolved types. Note that this
// global variable also must be defined here in order to force
// initialization.
map<type_info_interface *, resolver_descriptor> resolver_map;


const char *L3std_Q8standard_I9character::values[256] = {
	"nul", "soh", "stx", "etx", "eot", "enq", "ack", "bel", 
	"bs",  "ht",  "lf",  "vt",  "ff",  "cr",  "so",  "si", 
	"dle", "dc1", "dc2", "dc3", "dc4", "nak", "syn", "etb", 
	"can", "em",  "sub", "esc", "fsp", "gsp", "rsp", "usp", 

	"' '", "'!'", "'\"'", "'#'", "'$'", "'%'", "'&'", "'''", 
	"'('", "')'", "'*'", "'+'", "','", "'-'", "'.'", "'/'", 
	"'0'", "'1'", "'2'", "'3'", "'4'", "'5'", "'6'", "'7'", 
	"'8'", "'9'", "':'", "';'", "'<'", "'='", "'>'", "'?'", 

	"'@'", "'A'", "'B'", "'C'", "'D'", "'E'", "'F'", "'G'", 
	"'H'", "'I'", "'J'", "'K'", "'L'", "'M'", "'N'", "'O'", 
	"'P'", "'Q'", "'R'", "'S'", "'T'", "'U'", "'V'", "'W'", 
	"'X'", "'Y'", "'Z'", "'['", "'\\'", "']'", "'^'", "'_'", 

	"'`'", "'a'", "'b'", "'c'", "'d'", "'e'", "'f'", "'g'", 
	"'h'", "'i'", "'j'", "'k'", "'l'", "'m'", "'n'", "'o'", 
	"'p'", "'q'", "'r'", "'s'", "'t'", "'u'", "'v'", "'w'", 
	"'x'", "'y'", "'z'", "'{'", "'|'", "'}'", "'~'", "del",

	"c128", "c129", "c130", "c131", "c132", "c133", "c134", "c135",
	"c136", "c137", "c138", "c139", "c140", "c141", "c142", "c143",
	"c144", "c145", "c146", "c147", "c148", "c149", "c150", "c151",
	"c152", "c153", "c154", "c155", "c156", "c157", "c158", "c159",

	"' '", "'¡'", "'¢'", "'£'", "'¤'", "'¥'", "'¦'", "'§'",
	"'¨'", "'©'", "'ª'", "'«'", "'¬'", "'­'", "'®'", "'¯'",
	"'°'", "'±'", "'²'", "'³'", "'´'", "'µ'", "'¶'", "'·'",
	"'¸'", "'¹'", "'º'", "'»'", "'¼'", "'½'", "'¾'", "'¿'",

	"'À'", "'Á'", "'Â'", "'Ã'", "'Ä'", "'Å'", "'Æ'", "'Ç'",
	"'È'", "'É'", "'Ê'", "'Ë'", "'Ì'", "'Í'", "'Î'", "'Ï'",
	"'Ð'", "'Ñ'", "'Ò'", "'Ó'", "'Ô'", "'Õ'", "'Ö'", "'×'",
	"'Ø'", "'Ù'", "'Ú'", "'Û'", "'Ü'", "'Ý'", "'Þ'", "'ß'",

	"'à'", "'á'", "'â'", "'ã'", "'ä'", "'å'", "'æ'", "'ç'",
	"'è'", "'é'", "'ê'", "'ë'", "'ì'", "'í'", "'î'", "'ï'",
	"'ð'", "'ñ'", "'ò'", "'ó'", "'ô'", "'õ'", "'ö'", "'÷'",
	"'ø'", "'ù'", "'ú'", "'û'", "'ü'", "'ý'", "'þ'", "'ÿ'"
};
L3std_Q8standard_I9character L3std_Q8standard_I9character_INFO;


const char *L3std_Q8standard_I3bit::values[2] = {"'0'", "'1'"};
L3std_Q8standard_I3bit L3std_Q8standard_I3bit_INFO;

const char *L3std_Q8standard_I7boolean::values[2] = {"'0'", "'1'"};
L3std_Q8standard_I7boolean L3std_Q8standard_I7boolean_INFO;

const char *L3std_Q8standard_I14severity_level::values[4] = {"NOTE", "WARNING", "ERROR", "FAILURE"};
L3std_Q8standard_I14severity_level L3std_Q8standard_I14severity_level_INFO;

L3std_Q8standard_I7integer L3std_Q8standard_I7integer_INFO;

L3std_Q8standard_I7natural L3std_Q8standard_I7natural_INFO;

L3std_Q8standard_I8positive L3std_Q8standard_I8positive_INFO;

L3std_Q8standard_I4real L3std_Q8standard_I4real_INFO;

const char *L3std_Q8standard_I4time::units[7] = {"fs", "ps", "ns", "us", "ms", "sec", "hr"};
const physical L3std_Q8standard_I4time::scale[7] = {1L, 1000LL, 1000000LL, 
						    1000000000LL, 1000000000000LL, 
						    1000000000000000LL, 3600000000000000000LL};
L3std_Q8standard_I4time L3std_Q8standard_I4time_INFO;

array_info L3std_Q8standard_I10bit_vector_INFO;

array_info L3std_Q8standard_I6string_INFO;


bool L3std_Q8standard_init_done = false;
// Function to init the basic type_info data structures for the
// predefined VHDL types.
int 
L3std_Q8standard_init() 
{
  if (L3std_Q8standard_init_done) return 1;
  L3std_Q8standard_init_done = true;

  // Savely initialize the 'mem_chunks' memory
  memset (mem_chunks, 0, sizeof(void*)*(MAX_INTERNAL_ALLOC_SIZE+1));

  Xinfo_data_descriptor_init ();
  L3std_Q8standard_I9character_INFO.register_type(":std:standard",":std:standard:character", ":character", NULL);
  L3std_Q8standard_I3bit_INFO.register_type(":std:standard", ":std:standard:bit", ":bit", NULL);
  L3std_Q8standard_I7boolean_INFO.register_type(":std:standard", ":std:standard:boolean", ":boolean", NULL);
  L3std_Q8standard_I14severity_level_INFO.register_type(":std:standard", ":std:standard:severity_level", 
							":severity_level", NULL);
  L3std_Q8standard_I7integer_INFO.register_type(":std:standard", ":std:standard:integer", ":integer", NULL);
  L3std_Q8standard_I7natural_INFO.register_type(":std:standard", ":std:standard:natural", ":natural", NULL);
  L3std_Q8standard_I8positive_INFO.register_type(":std:standard", ":std:standard:positive", ":positive", NULL);
  L3std_Q8standard_I4real_INFO.register_type(":std:standard", ":std:standard:real", ":real", NULL);
  L3std_Q8standard_I4time_INFO.register_type(":std:standard", ":std:standard:time", ":time", NULL);
  
  L3std_Q8standard_I10bit_vector_INFO.set(&L3std_Q8standard_I3bit_INFO, &L3std_Q8standard_I7natural_INFO, -1)
    .register_type(":std:standard", ":std:standard:bit_vector", ":bit_vector", NULL);
  L3std_Q8standard_I6string_INFO.set(&L3std_Q8standard_I9character_INFO, &L3std_Q8standard_I8positive_INFO, -1)
    .register_type(":std:standard", ":std:standard:string", ":string", NULL);

  return 1;
}

//int L3std_Q8standard_init_var = L3std_Q8standard_init();




// Min severity level of assert or report messages that will cause the
// simulator to stop execution. Initiliazed with ERROR.
severity_level exit_severity_level = 2;


inline void
internal_report (const char *s, severity_level l)
{
  static buffer_stream sbuffer;
  sbuffer.clean(); // added by zhang
  sbuffer << '\0';
  
  // Print stack trace 
  trace_source(sbuffer, true, kernel.executable_name);
  model_output_stream << sbuffer.str();

  // Print simulation time
  model_output_stream << time_to_string (kernel.get_sim_time ()) << " + " << kernel.get_delta () << "d: ";

  model_output_stream << L3std_Q8standard_I14severity_level_INFO.get_values()[l] << ": ";

  // Finally, print string
  model_output_stream << s << "\n";

  if (l >= exit_severity_level) {
    kernel_output_stream << "Simulation stopped!" << "\n";
    // Set end simulation time to current simulation time. This will
    // stop the main simulation loop.
    kernel.set_end_sim_time(kernel.get_sim_time());
  }
}

 
void 
report(const vstring &s, severity_level l)
{
  // Get length of string and create a 0 terminated copy of the string
  int len = s.info->length; 
#ifdef HAVE_ALLOCA
  char *str = (char*)alloca(sizeof(char)*(len + 1));
#else
  int mem_size;
  char *str = (char*)internal_dynamic_alloc (mem_size = sizeof(char)*(len + 1));
#endif
  strncpy(str, s.data, len);
  str[len] = '\0';
  internal_report (str, l);
#ifndef HAVE_ALLOCA
  internal_dynamic_remove (str, mem_size);
#endif
}


void 
report(severity_level l)
{
  const char *str = "";
  internal_report (str, l);
}



// Function used to implement VHDL attribute 'value. 
lint 
attribute_value (type_info_interface *info, const vstring &str)
{
  lint result = 0;

#ifdef HAVE_ALLOCA
  char *char_str = (char*)alloca (sizeof (char) * (str.info->length + 1));
#else
  int mem_size;
  char *char_str = (char*)internal_dynamic_alloc (mem_size = sizeof (char) * (str.info->length + 1));
#endif
  memcpy (char_str, str.data, str.info->length);
  char_str [str.info->length] = '\0';

  bool error_flag = false;
  switch (info->id) {
  case ENUM:
    {
      enumeration value;
      enum_info_base *e_info = (enum_info_base*)info;
      error_flag = e_info->read (&value, char_str) != NULL;
      if (!error_flag) e_info->check (value);
      result = (lint)value;
      break;
    }
  case INTEGER:
    {
      integer value;
      integer_info_base *i_info = (integer_info_base*)info;
      error_flag = i_info->read (&value, char_str) != NULL;
      if (!error_flag) i_info->check (value);
      result = (lint)value;
      break;
    }
  case PHYSICAL:
    {
      physical value;
      physical_info_base *p_info = (physical_info_base*)info;
      error_flag = p_info->read (&value, char_str) != NULL;
      if (!error_flag) p_info->check (value);
      result = (lint)value;
      break;
    }
  case FLOAT:
    {
      floatingpoint value;
      float_info_base *f_info = (float_info_base*)info;
      error_flag = f_info->read (&value, char_str) != NULL;
      if (!error_flag) f_info->check (value);
      result = (lint)value;
      break;
    }
  default:
    {
#ifndef HAVE_ALLOCA
      internal_dynamic_remove (char_str, mem_size);
#endif
      error("Internal error in attribute_value!");
    }
  }

  if (error_flag)
    {
      string error_str = "Error: conversion error while processing attribute VALUE: string '" +
	string (char_str) + "' does not match target type!";
#ifndef HAVE_ALLOCA
      internal_dynamic_remove (char_str, mem_size);
#endif
      error (error_str.c_str ());
    }
  
#ifndef HAVE_ALLOCA
  internal_dynamic_remove (char_str, mem_size);
#endif

  return result;
}


// Function used to implement VHDL attribute 'image. 
vstring 
attribute_image (type_info_interface *info, const void *value)
{
  buffer_stream buf;
  info->print (buf, value, VHDL_PRINT_MODE);
  return vstring (new array_info (L3std_Q8standard_I6string_INFO.element_type,
				  L3std_Q8standard_I6string_INFO.index_type,
				  buf.str_len (),
				  0),
		  (const enumeration*)buf.str ()); 
}


// Predefined function "std:stanard:now". Returns current simulation
// time.
vtime 
L3std_Q8standard_Y3now_i303()
{
  return kernel.get_sim_time();
}
