
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stdtypes.h"
#include "blockpool.h"
#include "pools.h"
#include "str.h"
#include "list.h"
#include "strtable.h"
#include "sym.h"
#include "type.h"
#include "symtable.h"
#include "typetable.h"


/*
   Global Objects

   Note that the ordering in this file reflects object constructor
   order.  This ordering assures, for example, that object that use
   global memory in their constructors are initialized after
   the global memory object has been initialized.

 */



/*  ----- Stand alone objects that don't use block pool memory ---- */

STRING NULLSTR;  // a NULL string

// global list of times (e.g., fs, ps, ns, ...)
LIST<type_time *>   typetable::time_list;


type_real REAL;


/* ----- Block pool memory and objects that use block pool memory ---- */


/*
 * memory_pools
 *
 * There are MAX_POOLS memory pools that allocate memory
 * using the big_block_pool memory pool object.
 */
mem_pool<big_block_pool, MAX_POOLS>  memory_pools;

/*
 * global memory pool
 *
  
   Note: don't allocate memory from the global memory pool
         from a global constructor, since this class is
	 initialized at the global level and may not 
	 exist (be initialized itself) at the point you reference it.

 */
pool global_mem;


/* String table */
strtable strtab( SQRT_STRTAB, &global_mem );


/* Global symbol table */
symtable glob_symtab( SQRT_SYMTAB * 2, &global_mem );

typetable glob_typtab( &global_mem );

