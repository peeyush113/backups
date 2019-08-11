
#ifndef STRTABLE_H
#define STRTABLE_H


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

 */

#include <stdio.h>

#include "stdtypes.h"
#include "blockpool.h"
#include "pools.h"
#include "str.h"
#include "list.h"
#include "hash_serv.h"
#include "sparse.h"

/**
  This class implements a string table.  The string table consists of
  unique strings, which are null terminated.  The strings that are
  managed by the string table are contained in the STRING class.

  This class was originally a generic template (HASH) for building
  hash tables.  However, this template uses other templates (e.g., the
  sparse_array and LIST templates).  C++ compilers (especially the HP C++
  compiler) tend to have trouble with nested templates.  So this class 
  has been changed to be a specific class, instead of a template.
*/
class strtable : public hash_services 
{
private:

    // class for the hash collision chains
    class chain_elem {
    public:
	LIST<STRING *> list;
    private:
	chain_elem(const chain_elem &) {}
    public:
	chain_elem(void)  { list = LIST<STRING *>(); }
	~chain_elem(void) { list.dealloc(); }
        
	STRING *search_list( STRING item );

	unsigned int list_len(void)
	{
	    LIST<STRING *>::handle h;
	    int len = 0;;
	    
	    for (h = list.first(); h != NULL; h = list.next(h)) {
		len++;
	    } // for
	    return len;
	} // list_len

    }; // class chain_elem

    unsigned int table_size;
    unsigned int hash_slot;  // used in iterating through the hash table
    LIST<STRING *>::handle list_handle;

    sparse_array<chain_elem> *hash;
    pool *alloc_pool;
private:

    STRING *new_item( STRING str );

public:
    strtable( unsigned int size, pool *p )
    {

	assert( p != NULL );
        alloc_pool = p;
	hash = new sparse_array<chain_elem>( (const unsigned int)size );
	table_size = hash->get_total_size();
    }
    void dealloc()
    {
	hash->dealloc();

	delete hash;
    }
    ~strtable()
    {
	dealloc();
    }

    STRING find_string( STRING item, Boolean insert = TRUE);

    STRING find_string( const char *str, Boolean insert = TRUE )
    {
	STRING local_str;
	
	local_str.SetText( str );
	return find_string( local_str, insert );
    } // find_item with a char * argument

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
       The functions first and get_item are used to iterate through the
       string table.  Note that the strings will be returned in hash order,
       which is pseudorandom.  An example is shown below:
<pre>      
      STRING str;
      
      for (str = strtab.first(); str.GetText() != NULL; str = strtab.get_str()) {
         printf("%s\n", str.GetText() );
      }
</pre>
  */    
    STRING first(void)
    {
	hash_slot = 0;
	list_handle = NULL;
	return get_str();
    }

    STRING get_str(void);

}; // class strtable


//
// square root of the string table size
//
const uint SQRT_STRTAB = 1024;

extern strtable strtab;

#endif
