#include <freehdl/std-memory.hh>


/* *************************************************************
 *  Memory management for dynamically sized objects 
 * ************************************************************* */

// This array stores all currently unused memory chunks. 
void *mem_chunks[MAX_INTERNAL_ALLOC_SIZE + 1];

// Free all memory stored in the internal list.
void
interal_dynamic_clean()
{
  for (int size = 0; size <= MAX_INTERNAL_ALLOC_SIZE; size++)
    while (mem_chunks[size] != NULL) {
      void *next_pointer = (void*)mem_chunks[size];
      free(mem_chunks[size]);
      mem_chunks[size] = next_pointer;
    }
}

