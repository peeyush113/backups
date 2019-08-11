#ifndef FREEHDL_KERNEL_ERROR_H
#define FREEHDL_KERNEL_ERROR_H

// FreeHDL error handler interface.

#include <string>

#define ERROR_INTEGER_OVERFLOW 100
#define ERROR_FLOATING_POINT_OVERFLOW 101
#define ERROR_ENUM_OVERFLOW 102
#define ERROR_PHYSICAL_OVERFLOW 103
#define ERROR_ARRAY_INDEX 104
#define ERROR_INCOMPATIBLE_ARRAYS 105
#define ERROR_UNKNOWN_COMPONENT 106
#define ERROR_DUBLICATE_INSTANCE_NAME 107
#define ERROR_ARRAY_INDEX_OUT_OF_BOUNDS 108
#define ERROR_SCALAR_OUT_OF_BOUNDS 109
#define ERROR_ARRAY_LENGTH_MISMATCH 110
#define ERROR_ARRAY_BOUNDS_MISMATCH 111
#define ERROR_FILE_IO 112
#define ERROR_TEXTIO 113
#define ERROR_NO_SOCKETS 114

//Event handler internal errors
#define ERROR_EVENT_GENERAL_ERROR 200

#define ERROR_NOT_SUPPORTED 1000


// Prints an error message on the screen and stops program execution
void error(const int errnum, const char *str);

// Prints string on the screen and stops program execution
void error(const char *str);

// Prints string on the screen and stops program execution
void error(const int errnum);

struct type_info_interface;
// Prints string on the screen and stops program execution
void error(int errnum, type_info_interface *info, void *valuep);

// Prints string on the screen
void debug(const char *str, const char *file, const int line);


#ifdef DEBUG
void execute_assert(bool expr, string str);
#define v_assert(a,b) execute_assert(a,b,__FILE__,__LINE__)
#else
#define v_assert(a,b)
#endif

#endif
