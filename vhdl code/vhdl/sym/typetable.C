
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "stdtypes.h"
#include "blockpool.h"
#include "pools.h"
#include "str.h"
#include "list.h"
#include "fifo_list.h"
#include "hash_serv.h"
#include "sparse.h"
#include "strtable.h"
#include "sym.h"
#include "type.h"
#include "typetable.h"



type *typetable::find_time(const uint time_scale )
{
    type_time *pT;
    type_time *time_elem;
    LIST<type_time *>::handle h;
    
    pT = NULL;

    if (time_scale != time_bad_time) {
	for (h = time_list.first(); h != NULL; h = time_list.next( h )) {
	    time_elem = time_list.get_item( h );
	    if (time_elem->get_unit() == time_scale) {
		pT = time_elem;
		break;
	    }
	}

	// If pT is NULL then a type with that time scale is not in the
	// type list.  Allocate the type from the global memory pool.
	if (pT == NULL) {
	    pT = new( &global_mem ) type_time( time_scale );
	    time_list.add( pT );
	}
    }

    return pT;
} // find_time


/**
   The new_type class function returns a type based on its "kind"
   argument.  The time_scale argument is only needed in the case that
   kind == ty_time.

   There are a very large number of possible range types and an
   infinite number of possible array, record and file types.  However,
   this is only one REAL type.

   The time type is also special.  There are a limited number of time
   types reflecting the various resolutions.  These types are stored
   in a list that is shared by all instances of the typetable class.
   When the component is processed it can he quickly determined what
   the smallest time resolution is by searching this list.  Of course
   the time resolution must be done across components as well.

 */
type *typetable::new_type( uint kind, uint time_scale /* = time_bad_time */ )
{
    pType pT;

    assert( alloc_pool != NULL );

    pT = NULL;

    switch (kind) {
    case ty_time:
	pT = find_time( time_scale );
	break;
    case ty_range:
	pT = new( alloc_pool ) type_range( );
	break;
    case ty_real:
	pT = &REAL;  // there is only one real type
	break;
    case ty_array:
	pT = new( alloc_pool ) type_array( );
	break;
    case ty_record:
	pT = new( alloc_pool ) type_record( );
	break;
    case ty_file:
	pT = new( alloc_pool ) type_file( );
	break;
    default:
	assert( FALSE );
	break;
    } // switch

    return pT;
} // new_type


/**
   Debug print for the type table

 */
void typetable::pr(void)
{
    // To Be Done
} // pr

