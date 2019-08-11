
/** \file

   This file contains the class functions for the big_block_alloc memory
   allocation class.  This class allocates and deallocates large blocks
   of memory.  On a Win32 system (e.g., Windows NT), these blocks are
   allocated and deallocated via calls to VirtualAlloc and VirtualFree.

   This code is compatible with SunOS, AIX on RS 6000 and HP-UX 10.0.  This
   code is NOT compatible with HP-UX 9.0, which does not support the
   getpagesize() function.

  */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdtypes.h"
#include "blockpool.h"

/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


#ifdef _WIN32

#include <windows.h>  // for VirtualAlloc and GetSysInfo

#else

#define _UNIX_
extern "C" int getpagesize(void);

#endif



void big_block_alloc::alloc_error(void)
{
  printf("big_block_alloc: memory allocation error\n");
  exit( 1 );
} /* big_block_alloc::alloc_error */



/**
   Allocate memory from the virtual memory pool.  This block
   should be an integral number of pages and should be greater
   than or equal to the allocation granularity.
*/
void *big_block_alloc::MemoryAlloc( unsigned int num_bytes )
{
  void *mem;

  assert( num_bytes >= alloc_gran );  
  assert( num_bytes % page_size == 0 );  // should be an integral number of pages

#ifdef _UNIX_
/////
///// UNIX
/////
  mem = (void *)malloc( num_bytes );
  if (mem != NULL) { // zero out the memory
    memset(mem, 0, num_bytes);
  }

#else
/////
///// Win32
/////

  // Call the Win32 virtual memory allocater.  Virtual blocks are always
  // zeroed out (see Microsoft documentation on VirtualAlloc).
  mem = VirtualAlloc(NULL, num_bytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE );
#endif

  if (mem == NULL)
    alloc_error();

  return mem;
} // big_block_alloc::MemoryAlloc



/**
   Free large memory blocks
*/
void big_block_alloc::MemoryFree( void *address )
{

#ifdef _UNIX_
/////
///// UNIX
/////

  free( address );

#else
/////
///// Win32
/////

  if (! VirtualFree(address, 0, MEM_RELEASE))
    alloc_error();

#endif

} // big_block_alloc::MemoryFree



/**
   This is a system dependent function that returns the system
   virtual memory page size and the allocation granularity.
   The Allocation granularity is the smallest allocatable
   block of virtual memory.  On UNIX systems this tends to
   be the same as the value returned by getpagesize().  On
   Win32 systems the allocation granularity is usually larger
   than the page size.
*/
void big_block_alloc::GetSysInfo(void)
{

#ifdef _UNIX_
/////
///// UNIX
/////
  const int page_multiple = 4;

  page_size = getpagesize();
  // on HP-UX 9.0 use page_size = (unsigned int)sysconf( _SC_PAGE_SIZE );
  alloc_gran = page_size * page_multiple;

#else
/////
///// Win32
/////
  
  SYSTEM_INFO sys_info;  // system info structure, defined in windows.h

  GetSystemInfo( &sys_info );
  page_size = sys_info.dwPageSize;
  alloc_gran = sys_info.dwAllocationGranularity;

#endif
  assert( page_size != 0 );
  assert( alloc_gran != 0 );
} // big_block_alloc::GetSysInfo

