
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
   Search for a symbol in the hash chain list, using its STRING field
   as a key.

   The strings should have been entered in the string table.
   As a result, an address compare can be used, since all strings
   are unique in the string table.

   Note that there must be a symbol table for each unique scope.

 */
sym *symtable::chain_elem::search_list( STRING item )
{
    LIST<sym *>::handle h;
    sym *list_sym, *sym;
    
    sym = NULL;
    for (h = list.first(); h != NULL; h = list.next(h)) {
	list_sym = list.get_item( h );
	if ( list_sym->get_name().GetText() == item.GetText() ) {
	    sym = list_sym;
	    break;
	}  // if
    } // for
    
    return sym;
} // search_list



/**
   Allocate a new symbol.  The STRING should have already
   been entered in the string table.  Note that as
   different derived symbol types are added to dsym.h this
   function must be changed as well.

 */
sym *symtable::new_sym( STRING str, uint kind )
{
    sym *pNewSym;

    assert( alloc_pool != NULL );

    switch ( kind ) {
    // IDENT: has scope
    case sy_ident:
	pNewSym = new( alloc_pool ) sym_ident( str );
	pNewSym->set_scope( get_owner() );
	break;
    // TYPE : no scope
    case sy_type:
	pNewSym = new( alloc_pool ) sym_type( str );
	break;
    // CONST: no scope
    case sy_const:
	pNewSym = new( alloc_pool ) sym_const( str );
	break;

    // SUBPROG: local symbol table
    case sy_subprog:
	pNewSym = new( alloc_pool ) sym_subprog( str );

	// the subprogram is in the scope of the owner of this symbol table
	pNewSym->set_scope( get_owner() );
	// A function or procedure will allocate memory from
	// from the same pool as its parent scope (which will be
	// either a component or the global scope, in the case of
	// a function in a package).
	//
	pNewSym->get_symtab()->set_pool( alloc_pool );
	// Set the allocation pool for the type table
	pNewSym->get_typtab()->set_pool( alloc_pool );	
	// The symbol table is owned by the subprogram
	pNewSym->get_symtab()->set_owner( pNewSym );
	break;

    // COMPONENT: local memory pool and local symbol table
    case sy_component:
	pNewSym = new( alloc_pool ) sym_component( str );

	// symbols in the component scope are owned by the component
	pNewSym->get_symtab()->set_owner( pNewSym  );
	break;

    // PROCESS: local symbol table
    case sy_process:
	pNewSym = new( alloc_pool ) sym_process( str );

	// the process is in the scope of its component
	pNewSym->set_scope( get_owner() );
	// set the memory pool to the pool of the parent
	pNewSym->get_symtab()->set_pool( alloc_pool );
	// Set the allocation pool for the type table
	pNewSym->get_typtab()->set_pool( alloc_pool );	
	// The symbol table is owned by the process
	pNewSym->get_symtab()->set_owner( pNewSym );
	break;
    case sy_package:   // its not currently clear what to do about packages
    case sy_block_label:
    case bad_symbol:
    default:
	// bad symbol kind
	assert( FALSE );
	break;
    } // switch

    assert( pNewSym != NULL );

    return pNewSym;
} // new_sym


/**
   Search for a symbol in the symbol table whose
   name is in the STRING object name.

 */
sym *symtable::find_sym( STRING name )
{
    STRING str;
    sym *retsym;
    
    retsym = NULL;
    if (name.GetText() != NULL) {
	// If the name is not entered into the string table then
	// its not in the symbol table.  Of course the name could
	// be in the string table and not in the symbol table, since
	// the string table is global and symbol could be out of scope.
	str = strtab.find_string( name, FALSE );
	if (str.GetText() != NULL) {
	    unsigned int ix, val;

	    val = hash_value( str.GetText() );
	    // table size should always be a power of 2, so
	    // table_size - 1 is likely to be a prime.
	    ix = val % (table_size - 1);
	    if (hash->probe( ix )) { 
		retsym =  (*hash)[ ix ].search_list( str );
	    }   
	}
    }

    return retsym;
} // find_sym



/**
   Enter a symbol in the symbol table.  If "name" is not entered
   in the string table, enter it as well.

 */
sym *symtable::enter_sym( STRING name, uint kind )
{
    unsigned int ix, val;
    sym *retsym;
    STRING str;

    retsym = NULL;

    if (kind == sy_process) {
	// Processes are special cases.  They are allocated by the
	// symbol table class, since they are derived from the
	// symbol type.  But they are not entered into the symbol
	// table, since in VHDL a process name can't be referenced.
	// Allocation of processes by the symbol table allows uniform
	// allocation of all symbol derived objects.
	retsym = new_sym( name, kind);
    }
    else {

	assert( name.GetText() != NULL );

	val = hash_value( name.GetText() );
	str = strtab.find_string( name, TRUE );  // insert into table if its not there.
	// table size should always be a power of 2, so
	// table_size - 1 is likely to be a prime.
	ix = val % (table_size - 1);
	if (! hash->probe( ix ) ) {

	    hash->insert( chain_elem(), ix );
	    
	    retsym = new_sym( str, kind );
	    (*hash)[ix].list.add( retsym );
	}
	else {
	    retsym = (*hash)[ix].search_list( str );
	    if ( retsym == NULL) {
		retsym = new_sym( str, kind );
		(*hash)[ix].list.add( retsym );
	    }
	}
    }

    return retsym;
} // enter_sym


/**
   Traverse the symbol table and find any symbol that has scope (e.g.,
   its own symbol table).  Recursively call dealloc_sub_tables for
   each of these symbols and then call dealloc to recover sparse array
   and list memory.

 */
void symtable::dealloc_sub_tables(void)
{
    uint i;

    for (i = 0; i < table_size; i++) {
	if (hash->probe( i )) {
	    LIST<sym *>::handle h;
	    sym * pListSym;
	    
	    for (h = (*hash)[i].list.first(); h != NULL; h = (*hash)[i].list.next(h)) {
		pListSym = (*hash)[i].list.get_item( h );
		if (pListSym->has_scope()) {
		    pListSym->get_symtab()->dealloc_sub_tables();
		    pListSym->dealloc();
		}
	    } // for
	} // if
    } // for
} // dealloc_sub_tables

/**
   Print the contents of the string table.
 */
void symtable::pr(FILE *fp)
{
    uint i;

    for (i = 0; i < table_size; i++) {
	if (hash->probe( i )) {
	    LIST<sym *>::handle h;
	    sym * pListSym;
	    
	    for (h = (*hash)[i].list.first(); h != NULL; h = (*hash)[i].list.next(h)) {
		// fprintf(fp, "hash_label::pr: i = %d, ", i );
		pListSym = (*hash)[i].list.get_item( h );
		pListSym->get_name().pr(fp);
		fprintf(fp, "\n");
	    } // for
	} // if
    } // for
} // pr



/**
   get_str is used to iterate through the string table.
   See symtable.h.
 */
sym *symtable::get_sym(void)
{
    sym * pHashSym;

    pHashSym = NULL;

    while (list_handle == NULL && hash_slot < table_size) {
	if (hash->probe( hash_slot )) {
	    list_handle = (*hash)[hash_slot].list.first();
	}
	if (list_handle == NULL) {
	    hash_slot++;
	}
    } // while

    if (list_handle != NULL && hash_slot < table_size) {

	pHashSym = (*hash)[hash_slot].list.get_item( list_handle );

	list_handle = (*hash)[hash_slot].list.next(list_handle);

	// if we've hit the end of the list, increment the
	// slot so we're not stuck in the same place
	if (list_handle == NULL)
	    hash_slot++;	
    }

    return pHashSym;
} // get_str

