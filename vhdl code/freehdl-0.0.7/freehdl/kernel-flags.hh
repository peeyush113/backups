#ifndef FREEHDL_KERNEL_FLAGS_H
#define FREEHDL_KERNEL_FLAGS_H

// This header file contains several flags of general use

// If defined enables collection of statistical information
//#define STATISTICS(a)
#define STATISTICS(a) a

// If defined plots some statistical informations about reader_info
// instances.
//#define READER_INFO_STATISTICS

// Enables some debug actions (usually some debug messages) during simulation
//#define REPORT(a) a
#define REPORT(a) 

// Enables some performance monitoring on ULTRA sparc machines
//#define PERFMON_STATISTICS

#endif
