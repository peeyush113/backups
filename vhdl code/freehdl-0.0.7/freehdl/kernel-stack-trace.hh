#ifndef FREEHDL_KERNEL_STACK_TRACE_H
#define FREEHDL_KERNEL_STACK_TRACE_H

#include <freehdl/std-vhdl-types.hh>

// This function checks the current stack and print the source file name
// line number to 'str'. When vhdl_only is set true, only those files
// containing '.vhdl' or '.vhd' are printed.
void trace_source(buffer_stream &str, bool vhdl_only, const char * exefile);

#endif // #ifndef FREEHDL_KERNEL_STACK_TRACE_H
