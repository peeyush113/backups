
/** \file

  This file contains the class functions for a "pool" based memory allocator.
  These functions manage the block chain that makes up the memory pool and
  allocates memory from the individual blocks.  The entire pool is freed at
  once.  This object is independent of the actual memory allocation and
  deallocation functions, which are virutal functons.

 */

/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/
 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stdtypes.h"
#include "blockpool.h"


block_pool::block_pool(void)
{
  
  page_size = 0;
  alloc_gran = 0;
  current_block = NULL;
  block_list_start = NULL;
} // block_pool constructor


/*
   This function is automatically called to initialize the block_pool
   object when the "current_block" pointer is NULL.
*/
void block_pool::init_pool( void )
{

  block_chain *new_link;

  getinfo(page_size, alloc_gran);

  new_link = new_block( alloc_gran );
  block_list_start = new_link;
  current_block = new_link;
} /* init_pool */



/**
   Walk through the block chain and deallocate the blocks.
   Note that the block chain structures and the allocatible
   memory is contained within a single allocated block.
   The block_chain structure is at the start of this block
   so passing its address to the memory deallocation function
   deallocates both the block chain structure and the allocatible
   memory
*/
void block_pool::free_pool(void)
{
  block_chain *tmp;

  while (block_list_start != NULL) {
    tmp = block_list_start;
    block_list_start = Chain_next(block_list_start);
    MemFree( (void *)tmp );
  }
}


/**
   The new_block function is the "root" memory allocator for the
   block_pool object.  The amount of memory allocated is rounded up
   to the next "block_size" boundary.  Both the block_chain structure
   and the allocatible memory are allocated from a single block
   that is a multiple of the page size.  This should avoid fragmentation in
   the system memory allocator.
*/
block_pool::blk_chain *block_pool::new_block( unsigned int block_size )
{
  const unsigned int max_block_size = max_block_multiple * page_size;
  block_chain *new_link = NULL;
  unsigned int alloc_amt, total_alloc;

  // add in the memory needed for the block_chain structure
  total_alloc = block_size + sizeof(block_chain);
  if (total_alloc < alloc_gran)
      alloc_amt = alloc_gran;
  else { 
      // its larger than the allocation granularity, so round
      // up the the nearest page.
      alloc_amt = ((total_alloc + (page_size-1))/page_size) * page_size;
  }

  if (alloc_amt <= max_block_size) {

    /* allocate memory for both the block_chain structure and the memory block */
    new_link = (block_chain *)MemAlloc( alloc_amt );

    // The new memory block starts after the block_chain structure
    Chain_block(new_link) = (void *)(((unsigned int)new_link) + sizeof(block_chain));

    assert( alloc_amt >= block_size );

    Chain_bytes_used(new_link) = 0;
    Chain_block_size(new_link) = alloc_amt - sizeof(block_chain);
    Chain_next(new_link) = NULL;
  }
  else {
    printf("block_pool::new_block: allocation request too large\n");
  }

  return new_link;
} // block_chain::new_block



/**
   Add a new memory block to the memory pool.  This function is called when the 
   amount of memory requested by pool_alloc will not fit in the current block.  
*/
void *block_pool::add_block( unsigned int block_size )
{
  block_chain *block = NULL;
  block_chain *last_block;

  last_block = current_block;
  block = new_block( block_size );
  Chain_next(current_block) = block;
  current_block = block;

  return (void *)block;
} // block_chain::add_block




/**
   This function is called to allocate memory from the  memory pool.  If there 
   is enough free memory in the current block to satisify the memory request, 
   memory is allocated from the current block and the amount of free memory 
   is updated.  If the current block does not have enough memory, add_block 
   is called to allocate a new memory block which will be large enough.
*/
void *block_pool::pool_alloc( unsigned int num_bytes )
{
  const unsigned int align = sizeof( int );
  void *addr = NULL;
  unsigned int amt_free;

  /* the number of bytes allocated must be a multiple of the align
     size */
  num_bytes = ((num_bytes + (align-1))/align) * align;

  if (current_block == NULL) {
    init_pool();
  }

  amt_free = Chain_block_size(current_block) - Chain_bytes_used(current_block);
  
  if (num_bytes > amt_free) {
    if (add_block( num_bytes ) != NULL) {
      amt_free = Chain_block_size(current_block);
    }
  }

  if (amt_free >= num_bytes) {
    addr = (void *)((unsigned int)Chain_block(current_block) + Chain_bytes_used(current_block));
    Chain_bytes_used(current_block) += num_bytes;
  }
  else {
    printf("block_pool::block_alloc: allocation error\n");
    exit(1);
  }
  return addr;
} // block_pool::pool_alloc



/**
   Print information about the block pool
*/
void block_pool::print_block_pool_info( FILE *fp /*= stdout */)
{
  int total_allocated = 0;
  int total_unused = 0;
  block_chain *ptr = block_list_start;

  fprintf(fp, "[block size, bytes_used]\n");
  while (ptr != NULL) {
    fprintf(fp, "[%4d, %4d]", Chain_block_size(ptr), Chain_bytes_used(ptr));
    total_allocated += Chain_bytes_used(ptr);
    total_unused += (Chain_block_size(ptr) - Chain_bytes_used(ptr));
    if (Chain_next(ptr) != NULL) {
      fprintf(fp, ", ");
    }
    else {
      fprintf(fp, "\n");
    }
    ptr = Chain_next(ptr);
  } // while
  fprintf(fp, "Total allocated = %5d, total unused = %3d\n", total_allocated,
	 total_unused );
}

