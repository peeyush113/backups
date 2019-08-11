#ifndef KERNEL_PERSISTENT_CDFG_DUMP_HH
#define KERNEL_PERSISTENT_CDFG_DUMP_HH
#define KERNEL 
#include <iostream>
#include <list>
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-register.hh>
#include <freehdl/kernel-error.hh>
#include <freehdl/kernel-Xinfo-data-descriptor.hh>

//**********************************************************************************************
// Write CDFG design information into file using a lisp style syntax
//**********************************************************************************************
void 
write_cdfg_info_file(list<Xinfo_data_descriptor*> &xinfo_desc, ostream &os);


#endif
