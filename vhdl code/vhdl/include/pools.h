
#ifndef POOLS_H
#define POOLS_H


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


#include "output.h"
#include "blockpool.h"

typedef enum { min_handle = 0};


/**
  This is a template class that implements arrays of memory pools.
  This allows the user to request a new memory pool (get_new_pool),
  allocate memory from this pool (GetMem) and delete the pool
  (release_pool).

  The mem_pool class should be instantiated with a memory pool
  allocation object.  For example:
<pre>
    mem_pool<big_block_pool, 128>  big_pool;
</pre>

  The constant argument (e.g., 128, in the above example), defines
  the maximum number of pools that can be active at once.  Each pool
  has its own block chain and can be allocated and deallocated independently
  of the other pools.

  The class functions are in-lined because some C++ compilers (notably
  Sun's) only support templates with in-lined class functions.
  
 */
template <class pool_type, int max_handle>
class mem_pool {

private:
    pool_type *pools[ max_handle ];

public:
    typedef unsigned int pool_handle;

public:
    void pool_init(void)
    {
	int i;
	
	for (i = min_handle; i < max_handle; i++) {
	    pools[ i ] = NULL;
	}
    }  // pool_init 

  /** Find the first free pool slot and allocate a pool */
    pool_handle get_new_pool(void)
    {
	pool_handle handle;

	for (handle = min_handle; handle < max_handle; handle++) {
	    if (pools[handle] == NULL) {
		pools[handle] = new pool_type;
		break;
	    }
	}
	if (handle > max_handle) {
	    Fatal("big_pool::get_new_pool: no memory pools available");
	}

	return handle;
    } // get_new_pool

    void release_pool( pool_handle handle )
    {
	if (handle < max_handle && pools[ handle ] != NULL) {
	    delete pools[ handle ];
	    pools[ handle ] = NULL;
	}
	else {
	    Fatal("big_pool::release_pool: bad pool handle");
	}
    } // release_pool

    void *GetMem( pool_handle handle, unsigned int num_bytes )
    {
	void *mem;

	mem = NULL;
	if (handle < max_handle && pools[ handle ] != NULL) {
	    // mem = pools[ handle ]->MemAlloc( num_bytes );
	    mem = pools[ handle ]->pool_alloc( num_bytes );
	}
	else {
	    Fatal("big_pool::GetMem: bad pool handle");
	}
	return mem;
    } // GetMem

    void pr( FILE *fp, pool_handle handle )
    {
	if (handle < max_handle && pools[ handle ] != NULL) {
	    pools[ handle ]->print_block_pool_info();
	}
	else {
	    fprintf(fp, "big_pool::pr: bad pool handle");
	}
    } // pr
}; // mem_pool


/** 
   MAX_POOLS is the maximum number of memory pools that can be allocated
*/
#define MAX_POOLS 128

extern mem_pool<big_block_pool, MAX_POOLS>  memory_pools;

/**
   This object is used to allocate a single memory pool.
   The pool is allocated in the constructor and deallocated
   in the destructor.  This class references the global
   object memory_pools.

  */
class pool {
private:
    mem_pool<big_block_pool, MAX_POOLS>::pool_handle pool_handle;

  /** The copy constructor for this class should never be called,
      so declare private */
    pool( const pool &p) {}

  /** if a pool object is dymamically allocated from a pool
       its memory will be initialized to zero.  So allocated
       will be FALSE;
  */
    Boolean allocated;

public:
    pool(void) 
    {
	new_pool();
    }
    ~pool(void)
    {
	delete_pool();
    }
    void new_pool(void)
    {
	allocated = TRUE;
	pool_handle = memory_pools.get_new_pool();
    }
    void delete_pool(void)
    {
	allocated = FALSE;
	memory_pools.release_pool( pool_handle );
    }
    void *GetMem( unsigned int num_bytes )
    {
	assert( allocated == TRUE );

	return memory_pools.GetMem( pool_handle, num_bytes );
    }
    void pr( FILE *fp = stdout )
    {
	memory_pools.pr(fp,  pool_handle );
    }
};

extern pool global_mem;

#endif
