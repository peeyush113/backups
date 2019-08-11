
#ifndef SYMTABLE_H
#define SYMTABLE_H


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


/*
   include dependencies:

   <string.h>     -- strlen(), strcmp(), etc...
   <stdio.h>      -- for printf and FILE (needed by str.h)
   stdtypes.h
   blockpool.h
   pools.h
   str.h
   list.h
   hash_serv.h
   sparse.h
   strtable.h
   sym.h
   type.h
   dsym.h


 */

#include "list.h"
#include "sparse.h"
#include "hash_serv.h"

/** for a populated sparse array of 256K hash lists */
const uint SQRT_SYMTAB = 512;

/**
  This class implements a symbol table for the VHDL compiler.  The
  symbol table consists of symbols with unique names (contained in
  the STRING class, entered in the string table).

  This class was originally a generic template (HASH) for building
  hash tables.  However, this template uses other templates (e.g., the
  sparse_array and LIST templates).  C++ compilers (especially the HP C++
  compiler) tend to have trouble with nested templates.  So this class 
  has been changed to be a specific class, instead of a template.

*/
class symtable : public hash_services 
{
private:

  /** class for the hash collision chains */
    class chain_elem {
    public:
	LIST<sym *> list;
    private:
	chain_elem(const chain_elem &) {}
    public:
	chain_elem(void)  { list = LIST<sym *>(); }
	~chain_elem(void) { list.dealloc(); }
        
	sym *search_list( STRING item );

	unsigned int list_len(void)
	{
	    LIST<sym *>::handle h;
	    int len = 0;;
	    
	    for (h = list.first(); h != NULL; h = list.next(h)) {
		len++;
	    } // for
	    return len;
	} // list_len

    }; // class chain_elem

    unsigned int table_size;
    unsigned int hash_slot;  // used in iterating through the hash table
    LIST<sym *>::handle list_handle;

    sparse_array<chain_elem> *hash;
    pool *alloc_pool;
    // the symbol that contains "owns" this symbol table.
    sym *owner;

private:
    // allocate a new symbol
    sym *new_sym( STRING str, uint kind );

private:
    // outlaw the copy constructor, since we don't want to call
    // the destructor which will deallocate the sparse array
    symtable( const symtable &st ) { assert( FALSE ); }

public:
    void init(uint size = SQRT_SYMTAB)
    {
	hash = new sparse_array<chain_elem>( (const unsigned int)size );
	table_size = hash->get_total_size();
    }

    symtable( unsigned int size = SQRT_SYMTAB, pool *p = NULL )
    {

	owner = NULL;
	alloc_pool = p;
	init( size );
    }
    void dealloc()
    {
	hash->dealloc();

	delete hash;
    }
    ~symtable()
    {
	dealloc_sub_tables();  // Deallocate all the "child" symbol tables.
	dealloc();             // Deallocate the sparse array and list memory for
	                       // this symbol table.
    }

    void set_pool( pool *p )
    {
	alloc_pool = p;
    }

    void set_owner( sym *parent ) { owner = parent; }

    // The global scope is the only scope without an owner.
    // Only components (and, perhaps, processes) are entered in the
    // global scope.  The get_owner function should not be called
    // for these.  So owner should never be NULL.
    sym *get_owner(void)          
    { 
	assert( owner != NULL );
	return owner; 
    }


    // enter_sym: enter a symbol into the symbol table.
    // This function will allocate the space for the
    // symbol in the memory pool associated with the
    // symbol table.  The enter_sym function will also
    // enter the STRING in the string table if necessary.
    sym *enter_sym( STRING str, uint kind );

    sym *enter_sym( const char *pChar, uint kind )
    {
	STRING str;

	str.SetText( pChar );
	return enter_sym( str, kind );
    }  // enter_sym

    // find_sym: search for a symbol.  Returns the symbol if found,
    // NULL otherwise.
    sym *find_sym( STRING name );

    sym *find_sym( const char *pChar )
    {
	STRING str;

	str.SetText( pChar );
	return find_sym( str );

    } // find_sym with a char * argument

    // note that hash can never be NULL, since it is initialized in the constructor
    unsigned int get_percent_alloced(void) { return hash->get_percent_alloced(); }

    unsigned int get_max_list(void)
    {
	uint i;
	uint max, len;

	max = 0;
	for (i = 0; i < table_size; i++) {
	    if (hash->probe( i )) {
		len = (*hash)[i].list_len();
		if (len > max) {
		    max = len;
		}
	    }
	}
	return max;
    } // get_max_list

    void pr(FILE *fp = stdout);

  /**
       Traverse the symbol table and find sub-symbols
       that have scope (e.g., symbol tables).  For each
       of these, call dealloc_sub_tables, and then dealloc.
  */
    void dealloc_sub_tables();

  /**
       The functions first and get_item are used to iterate through the
       string table.  Note that the strings will be returned in hash order,
       which is pseudorandom.  An example is shown below:
<pre>
         sym *pSym;
      
         for (pSym = symtab.first(); pSym != NULL; pSym = symtab.get_str()) {
             printf("%s\n", sym->get_name().GetText() );
         }
</pre>  
  */
    sym *first(void)
    {
	hash_slot = 0;
	list_handle = NULL;
	return get_sym();
    }

    sym *get_sym(void);

}; // class symtable


extern symtable glob_symtab;

#endif
