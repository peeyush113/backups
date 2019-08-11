#define KERNEL
#include <iostream>
#include <freehdl/kernel-error.hh>
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-stack-trace.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <freehdl/kernel-fhdl-stream.hh>


void 
error(int errnum, const char *str) 
{
  static buffer_stream sbuffer;
  
  // Print stack trace
  trace_source(sbuffer, true, kernel.executable_name);
  kernel_error_stream << sbuffer.str();
  
  kernel_error_stream << "Runtime error " << errnum << ".\n";
  if (str != NULL && *str != '\0')
    kernel_error_stream << str << "\n";

  exit (1);
}

// Prints string on the screen and stops program execution
void 
error(int errnum, type_info_interface *info, void *valuep)
{
  static buffer_stream sbuffer;

  // Print stack trace
  trace_source(sbuffer, true, kernel.executable_name);
  kernel_error_stream << sbuffer.str();

  switch (errnum) {
  case ERROR_SCALAR_OUT_OF_BOUNDS:
    {
      buffer_stream s;
      s.clean();
      info->print(s, valuep, VHDL_PRINT_MODE); 
      kernel_error_stream << " scalar value " << s.str() << " out of bounds.";
      break;
    }
  default:
    kernel_error_stream << " unknown error.";
    break;
  }
  kernel_error_stream << "\n";
  exit(1);
}


void 
error(const char *str) {
  static buffer_stream sbuffer;

  // Print stack trace
  trace_source(sbuffer, true, kernel.executable_name);
  kernel_error_stream << sbuffer.str();
  kernel_error_stream << str << "\n";

  exit(1);
}


// Prints string on the screen and stops program execution
void 
error(const int errnum)
{
  const char *errstr;

  switch (errnum) {
  case ERROR_INTEGER_OVERFLOW:
    errstr = "Integer overflow";
    break;
  case ERROR_FLOATING_POINT_OVERFLOW:
    errstr = "Floating point overflow";
    break;
  case ERROR_ENUM_OVERFLOW:
    errstr = "Enumeration overflow";
    break;
  case ERROR_PHYSICAL_OVERFLOW:
    errstr = "Physical overflow";
    break;
  case ERROR_ARRAY_INDEX:
    errstr = "Illegal array index";
    break;
  case ERROR_INCOMPATIBLE_ARRAYS:
    errstr = "Incompatible arrays";
    break;
  case ERROR_UNKNOWN_COMPONENT:
    errstr = "Unkown component";
    break;
  case ERROR_DUBLICATE_INSTANCE_NAME:
    errstr = "Dublicate instance name";
    break;
  case ERROR_ARRAY_INDEX_OUT_OF_BOUNDS:
    errstr = "Array index out of bounds";
    break;
  case ERROR_SCALAR_OUT_OF_BOUNDS:
    errstr = "Scalar out of bounds";
    break;
  case ERROR_ARRAY_LENGTH_MISMATCH:
    errstr = "Array length mismatch";
    break;
  case ERROR_ARRAY_BOUNDS_MISMATCH:
    errstr = "Array bounds mismatch";
    break;
  case ERROR_FILE_IO:
    errstr = "File IO";
    break;
  case ERROR_TEXTIO:
    errstr = "TextIO";
    break;
  case ERROR_NO_SOCKETS:
    errstr = "Sorry, the system does not have sockets support";
    break;
  default:
    errstr = "Unkown runtime error";
    break;
  }

  // Output error string
  error(errstr);
}


void 
debug(const char *str, const char *file, const int line) {
  kernel_error_stream << "Debug info from " << file << " at line " << line << ": " << str << "\n";
}

#ifdef DEBUG
void 
void execute_assert(bool expr, string str, char *file, int line) {
{
  kernel_error_stream << "In file " << file << ":" << line << endl;
  if (expr) 
    error(str); 
}
#endif


