
#ifndef SYM_H
#define SYM_H

/*
   include dependencies:

   stdlib.h     -- for NULL
   stdtypes.h
   string.h
   type.h
   str.h        -- definition for STRING

 */

#include "typedefs.h"
#include "list.h"
#include "const.h"


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


/** \file

  VHDL symbol class defintions

 */


/**
 */
class src_ref {
    ushort file_num;   // handle in the file name table
    ushort offset;     // char offset within the line
    uint line_num;     // line number within the file
}; // src_ref


enum { bad_symbol,
       sy_ident,
       sy_type,
       sy_const,          // an enumeration value, a defined constant
       sy_subprog,
       sy_component,      // an elaborated entity/architecture pair
       sy_package,        // both declaration parts and body
       sy_process,
       sy_block_label    // its not clear this is needed
    };

class symtable;
class typetable;

/**
   Memory Allocation

   New for symbols is only called from the symbol table.  New for
   types is only called from the type table.  If new compilers are
   not available, this localized code will have to be modified.

 */
class sym {
private:
    STRING name;       // Symbol name, entered into the string table
    src_ref  m_sr;     // source location for the declaration
    uint m_referenced : 1,  // symbol was referenced
	 m_unused     : 31;

public:
    sym(STRING n )
    {
	name = n;
        m_referenced = FALSE;
    } // sym constructor

    sym( )
    {
	name.SetText( NULL );
        m_referenced = FALSE;
    } // sym constructor


    void *operator new( unsigned int num_bytes )
    {
	assert( FALSE );
	return NULL;
    }

    //
    // Overloaded new
    //
    void *operator new( unsigned int num_bytes, pool *mem_pool )
    {
	return mem_pool->GetMem( num_bytes );
    }

    // Memory is recovered by deleting the memory pool.  So delete
    // should do nothing.
    void operator delete( void *addr ) {/* do nothing */}

    STRING get_name(void) { return name; }
    void set_name( const STRING str ) { name = str; }

    void set_referenced(void) { m_referenced = TRUE; }
    void unset_referenced(void) { m_referenced = FALSE; }
    const Boolean is_referenced(void) { return m_referenced; }
    
    //
    // Virtual functions common to all classes
    //
    virtual const uint get_sy_kind(void) { return bad_symbol; }

    //
    // Virtual functions for derived classes
    //
    // -- sym_scoped subclass
    //
    virtual void set_scope( pSym scope )
    {
	assert( FALSE );
    }
    //
    // get_scope default class
    //
    // Return null if there is no scope, since this
    // is one way to test this characteristic of
    // a symbol.
    virtual const pSym get_parent_scope(void) 
    {
	return NULL;
    }
    //
    // -- sym_const subclass
    //
    virtual void set_const( pConst c )
    {
	assert( FALSE );
    }
    virtual const pConst get_const(void)
    {
	assert( NULL );
	return NULL;
    }
    //
    // -- sym_type subclass
    //
    virtual void set_ty_type( pType t ) 
    { 
	assert( NULL );
    } // set_type
    virtual const pType get_ty_type(void) 
    { 
	assert( FALSE );
	return NULL; 
    } // get_type
    //
    // -- sym_ident subclass
    //
    virtual void set_alloc( uint alloc )
    {
	assert( FALSE );
    } // set_offset
    virtual const uint get_alloc(void)
    {
	assert( FALSE );
	return 0;
    }
    virtual void set_id_kind( uint kind )
    {
	assert( FALSE );
    }
    virtual const uint get_id_kind(void)
    {
	assert( FALSE );
	return 0;
    }
    virtual void set_id_type( pType t ) 
    { 
	assert( FALSE );
    } // set_id_type
    virtual const pType get_id_type(void) 
    { 
	assert( FALSE );
	return NULL; 
    }
    //
    // -- sym_scope subclass
    //
    virtual sym *LookupFromScope(STRING s)
    {
	assert( FALSE );
	return NULL;
    }
    virtual sym *LookupFromScope(const char *pChar )
    {
	assert( FALSE );
	return NULL;
    }
    virtual symtable *get_symtab(void)
    {
	assert( FALSE );
	return NULL;
    }

    virtual typetable *get_typtab(void)
    {
	assert( FALSE );
	return NULL;
    }
    virtual Boolean has_scope()
    {
	// return false for any symbol that is not of
	// the sym_scope sub-class
	return FALSE;
    }
    //
    // -- sym_subprog subclass
    //
    virtual void set_statement( NODE *s )
    {
	assert( FALSE );
    }
    virtual const NODE *get_statement(void)
    {
	assert( FALSE );
	return NULL;
    }

    virtual void set_func_type( pType t )
    {
	assert( FALSE );
    }
    virtual const pType get_func_type(void)
    {
	assert( FALSE );
	return NULL;
    }
    //
    // -- sym_component subclass
    //
    virtual void init(void)
    {
	// its ok to do nothing if there's nothing to initialize
    }
    virtual void dealloc(void)
    {
	// its ok to do nothing if there's nothing to deallocate
    }
    // Allocate memory from the pool that is local to the 
    // component.
    virtual void *GetMem( uint num_bytes )
    {
	assert( FALSE );
	return NULL;
    }

    virtual LIST<sym *> *get_proc_list(void)
    {
	assert( FALSE );
	return NULL;
    }
    virtual LIST<NODE *> *get_sigass_list(void)
    {
	assert( FALSE );
	return NULL;
    }
};  // class sym



/**
   This is a derived symbol class for named items that exist in
   a scope.  These include:
<ul>
<li>
      identifiers
</li>
<li>
      subprograms (procedures and functions)
</li>
<li>
      instances (e.g., u1 : foo port map (...); has the name u1)
</li>
</ul>

   These items can all be found in a symbol table in their local
   scope.

   Subprograms not only have scope, but they also have an associated
   synbol table.

   Exceptions (e.g., objects that are NOT sym_scoped, but have scope
               information)

<ul>
<li>
<p>
     Processes
</p>
<p>
       Although a process may have a name, its not clear that this
       name is useful for anything, except adding code reability.  A
       process is not looked up in the symbol table, so it is not a
       sym_scoped object (or even a sym derived object).  But a
       process _does_ have an associated symbol table.
</p>
</li>
<li>
<p>
     Packages
</p>
<p>
       A package has scope (e.g., local types, constants, etc).  But
       packages are in the global scope.  Its not clear that packages
       will survive after elaboration.
</p.
</li>
</ul>

 */
class sym_scoped : public sym {
private:
    pSym parent_scope;

public:
    sym_scoped(STRING n) : sym( n )
    { 
	parent_scope = NULL; 
    }

    sym_scoped()
    {
	parent_scope = NULL;
    }

    void set_scope( pSym scope )
    {
	parent_scope = scope;
    }
    const pSym get_parent_scope(void) 
    {
	return parent_scope;
    }
}; // sym_scoped


#endif
