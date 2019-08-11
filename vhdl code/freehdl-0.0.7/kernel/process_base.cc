#define KERNEL

#include <freehdl/kernel-name-stack.hh>
#include <freehdl/kernel-process-base.hh>
#include <freehdl/kernel-kernel-class.hh>


process_base::process_base(name_stack &in) 
{
  jmp = 0;
  next_process = NULL; // The process is not on the execution list
}


// Constructor for "internal" processes
process_base::process_base()
{
  jmp = 0;
  next_process = NULL; // The process is not on the execution list
}
