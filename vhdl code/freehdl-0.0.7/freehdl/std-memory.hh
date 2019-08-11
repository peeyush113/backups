#ifndef FREEHDL_STD_MEMORY_H
#define FREEHDL_STD_MEMORY_H

#include <stdlib.h>



/* *************************************************************
 *  Memory management for dynamically sized objects 
 * ************************************************************* */

// Max memory allocation size handled by this routine
#define MAX_INTERNAL_ALLOC_SIZE 1024 

// This array stores all currently unused memory chunks. 
extern void *mem_chunks[MAX_INTERNAL_ALLOC_SIZE + 1];

// Allocates new memory of size "size". To speedup memory allocation a
// list of unused memory chunks is stored in an array which is
// addressed by size. However, memory chunks of size greater than
// MAX_INTERNAL_ALLOC_SIZE are allocated and freed as usual.
inline void *
internal_dynamic_alloc(unsigned int size)
{
  void *result = NULL;
  // Memory chunks of size greater than MAX_INTERNAL_ALLOC_SIZE are
  // handled as usual
  if (size > MAX_INTERNAL_ALLOC_SIZE)
    result = malloc(size);
  
  else if (mem_chunks[size] != NULL) {
    // If there is a memory chunk of appropriate size then return it.
    result = mem_chunks[size];
    mem_chunks[size] = *(void**)mem_chunks[size];

  } else
    // If no unused memory chunk could be found then allocate new
    // memory
    result = malloc(size >= sizeof(void*)? size : sizeof(void*));

  return result;
}


// Free memory. However, memory of size less than or equal to
// MAX_INTENAL_ALLOCA_SIZE is stored into the internal list of unused
// chunks
inline void
internal_dynamic_remove(void *pointer, int size)
{
  if (pointer == NULL)
    return;
  if (size > MAX_INTERNAL_ALLOC_SIZE)
    free(pointer);
  else {
    *(void**)pointer = mem_chunks[size];
    mem_chunks[size] = pointer;
  }
}

// Free all memory stored in the internal list.
void
internal_dynamic_clean();


#endif
