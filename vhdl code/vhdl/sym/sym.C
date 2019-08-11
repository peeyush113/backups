
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
#include "const.h"
#include "symtable.h"
#include "typetable.h"
#include "dsym.h"


/**
   Recursively search the symbol scope for the symbol
   with the name str.
 */
sym *sym_scope::find_in_scope( sym *pSym, STRING sym_name )
{
    sym *retsym = NULL;

    if (pSym != NULL && pSym->has_scope() ) {
	retsym = ((sym_scope *)pSym)->symtab.find_sym( sym_name );
	if (retsym == NULL && pSym->get_parent_scope() != NULL) {
	    // the symbol was not found in the local scope, so go up one
	    // scope level.
	    retsym = find_in_scope( pSym->get_parent_scope(), sym_name );
	}
    }

    return retsym;
} // find_in_scope


/**
   Start in the local scope and search upward toward the component
   scope.
 */
sym *sym_scope::LookupFromScope( STRING str )
{
    sym *retsym = NULL;

    if (str.GetText() != NULL) {
	STRING local_str;

	// if its not in the string table, its not in the symbol table
	local_str = strtab.find_string( str, FALSE ); // don't enter
	if (local_str.GetText() != NULL) {
	    retsym = find_in_scope( this, local_str );
	}
    }
    
    return retsym;
} // LookupFromScope



/**
   Deallocate the process list symbol tables.
 */
void sym_component::proc_list_dealloc(void)
{
    LIST<sym *>::handle h;
    sym *pListSym;

    for (h = proc_list.first(); h != NULL; h = proc_list.next( h ) ) {
	pListSym = proc_list.get_item( h );
	if (pListSym != NULL && pListSym->has_scope()) {
	    pListSym->get_symtab()->dealloc_sub_tables();
	    pListSym->get_symtab()->dealloc();
	}
    } // for
    proc_list.dealloc();
} // proc_list_dealloc
