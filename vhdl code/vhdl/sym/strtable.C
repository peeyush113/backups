
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "stdtypes.h"
#include "blockpool.h"
#include "pools.h"
#include "str.h"
#include "list.h"
#include "hash_serv.h"
#include "sparse.h"
#include "strtable.h"


/**
   Search for a string in a hash chain list.
 */
STRING *strtable::chain_elem::search_list( STRING item )
{
    LIST<STRING *>::handle h;
    STRING *list_str, *str;
    
    str = NULL;
    for (h = list.first(); h != NULL; h = list.next(h)) {
	list_str = list.get_item( h );
	if ( strcmp(list_str->GetText(), item.GetText()) == 0 ) {
	    str = list_str;
	    break;
	}  // if
    } // for
    
    return str;
} // search_list



/**
   Allocate a new STRING, plus the associated storage for the
   string.
 */
STRING *strtable::new_item( STRING str )
{
    STRING *pStr;
    char *pStrCopy;

    pStrCopy = NULL;
    pStr = (STRING *)alloc_pool->GetMem( sizeof(STRING) );

    if (str.GetText() != NULL) {
	uint len;

	len = strlen( str.GetText());
	pStrCopy = (char *)alloc_pool->GetMem( len + 1 /* char for '\0' */ );
	strcpy( pStrCopy, str.GetText() );
    }
    
    pStr->SetText( pStrCopy );
    return pStr;
} // new_item


/**
   Search for the string in the string table.
 */
STRING strtable::find_string( STRING item, Boolean insert /* = TRUE */)
{
    STRING * pVal;
    STRING RetStr;
    unsigned int ix, val;

    val = hash_value( item.GetText() );
    // table size should always be a power of 2, so
    // table_size - 1 is likely to be a prime.
    ix = val % (table_size - 1);
    if (! insert) {  // insert == FALSE

	if (! hash->probe( ix )) { 
	    pVal = NULL;
	}
	else {
	    pVal =  (*hash)[ ix ].search_list( item );
	}
    }
    else { // insert == TRUE
	if (! hash->probe( ix ) ) {

	    hash->insert( chain_elem(), ix );

	    pVal = new_item( item );
	    (*hash)[ix].list.add( pVal );
	}
	else {
	    pVal = (*hash)[ix].search_list( item );
	    if ( pVal == NULL) {
		pVal = new_item( item );
		(*hash)[ix].list.add( pVal );
	    }
	}
    }

    if (pVal == NULL) {
	RetStr.SetText( NULL );
    }
    else {
	RetStr = *pVal;
    }
    return RetStr;
} // find_item with a STRING argument


/**
   Print the contents of the string table.
 */
void strtable::pr(FILE *fp)
{
    uint i;

    for (i = 0; i < table_size; i++) {
	if (hash->probe( i )) {
	    LIST<STRING *>::handle h;
	    STRING * pVal;
	    
	    for (h = (*hash)[i].list.first(); h != NULL; h = (*hash)[i].list.next(h)) {
		// fprintf(fp, "hash_label::pr: i = %d, ", i );
		pVal = (*hash)[i].list.get_item( h );
		pVal->pr(fp);
		fprintf(fp, "\n");
	    } // for
	} // if
    } // for
} // pr



/**
   get_str is used to iterate through the string table.
   See strtable.h.
 */
STRING strtable::get_str(void)
{
    STRING local_str;
    STRING * pVal;

    local_str.SetText( NULL );
    pVal = &local_str;

    while (list_handle == NULL && hash_slot < table_size) {
	if (hash->probe( hash_slot )) {
	    list_handle = (*hash)[hash_slot].list.first();
	}
	if (list_handle == NULL) {
	    hash_slot++;
	}
    } // for

    if (list_handle != NULL && hash_slot < table_size) {

	pVal = (*hash)[hash_slot].list.get_item( list_handle );

	list_handle = (*hash)[hash_slot].list.next(list_handle);

	if (list_handle == NULL)
	    hash_slot++;	
    }

    return *pVal;
} // get_str

