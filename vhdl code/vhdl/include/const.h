
#ifndef CONST_H
#define CONST_H


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


#include <assert.h>

#include "type.h"


#ifndef NULL
#define NULL 0
#endif

/** Note that string constants are just array constants. */
enum { bad_constant,
       cn_sign,          // a signed scalar constant
       cn_unsign,        // an unsigned scalar constant
       cn_real,          // a real constant
       cn_aggregate      // an "aggragate" constant for either
                         // an array or a record. 
     };


/** 
   Base class for VHDL constants.  Like types in VHDL, constants come
   in two flavors: named and anonymous.

   Named constants are created by:
<ul>
<li>
     enumeration values
</li>
<li>
     declared constant 
</li>
</ul>

   The value of a declared constant may be deferred until
   the design is elaborated.  However, after elaboration
   the values of all named constants must be known.

   The classes in this file define anonymous constants.  If
   the object is a named constant, an anonymous constant will
   be allocated and it will be used to initialize a sym_const
   object.

   There are five kinds of constant:

<ul>
<li>
      range constants (e.g, NATURAL, INTEGER, etc..)
</li>
<li>
      real constants
</li>
<li>
      array constants
</li>
<li>
      record constants
</li>
</ul>

   Note that an enumeration value is a named constant.  So
   it will have a symbol and an associated const_range
   object giving the enumeration value.
   
   Ranges are limited to bounds that can be represented in
   32-bits.  Note that "x" and "z" are not scalar values.
   In VHDL "x" and "z" are enumeration values defined as
   part of packages like std_logic.

   Array and record constants are aggragates, whose type is
   defined by their context.  Depending on where they are used
   (e.g., in a process or in a function) an aggragate will be
   implemented by static initialized data or via generated 
   code.  The choice also depends on the aggragate itself.
   Even in cases where an aggragate could be created in 
   static initialized data, it may be more efficient to
   generate code for it.

   The choice of what to do with an aggragate is made after
   the QT trees have been constructed.  So initially all
   aggragate constants have a pointer to a QT tree that
   represents the aggragate.  This also allows aggragates
   to be composed of sub-aggragates.  Later these can all
   be "flattened".

 */
class vhdl_const {
public:
    vhdl_const(void) { }

  /** Disallow the default new operator */
  void *operator new( unsigned int num_bytes )
  {
    assert( FALSE );
    return NULL;
  }

  /**
     Overloaded new
  */
  void *operator new( unsigned int num_bytes, pool *mem_pool )
  {
    return mem_pool->GetMem( num_bytes );
  }

  /** shared virtual functions */
  virtual const uint get_cn_kind( void ) { return bad_constant; }

    // virtual functions specific to a class
    /**
       const_range_signed
    */
    virtual void set_val( int i )
    {
	assert( FALSE );
    }
    virtual const int get_val(void)
    {
	assert( FALSE );
	return 0;
    }
  /** const_range_unsigned
   */
    virtual void set_uval( uint u )
    {
	assert( FALSE );
    }
    virtual const uint get_uval(void)
    {
	assert( FALSE );
	return 0;
    }
  /** const_real
   */
    virtual void set_real( float f )
    {
	assert( FALSE );
    }
    virtual const float get_real(void)
    {
	assert( FALSE );
	return (float)0.0;
    }
    //
    //
    //
    virtual void set_agg_ty( pType ty ) 
    {
	assert( FALSE );
    }    
    virtual const pType get_agg_ty(void)
    {
	return NULL;
    }
    //
    // const_agg 
    //
    virtual void set_tree( NODE *tree ) 
    {
	assert( FALSE );
    }
    virtual const NODE *get_tree(void)
    {
	return NULL;
    }
};  // vhdl_const




/**
 */
class const_range_signed : public vhdl_const {
private:
    int val;
public:
    const_range_signed(void) { val = 0; }
    const_range_signed(int i) { val = i; }
    void set_val( int i )
    {
	val = i;
    }
    const int get_val(void)
    {
	return val;
    }

    const uint get_cn_kind( void ) { return cn_sign; }
}; // const_range_signed



/*
 * const_range_unsigned
 *
 */
class const_range_unsigned : public vhdl_const {
private:
    uint val;
public:
    const_range_unsigned() { val = 0; }
    const_range_unsigned( uint u ) { val = u; }
    void set_uval( uint u )
    {
	val = u;
    }
    const uint get_uval(void)
    {
	return val;
    }
    const uint get_cn_kind( void ) { return cn_unsign; }
}; // const_range_unsigned


/**
 */
class const_real : public vhdl_const {
private:
    float real_val;

public:
    const_real(void) { real_val = 0.0; }
    void set_real( float f )
    {
	real_val = f;
    }
    const float get_real(void)
    {
	return real_val;
    }
    const uint get_cn_kind( void ) { return cn_real; }
}; // const_real



/**
   An aggragate constant.  The type (e.g, array or record)
   is determined by checking the aggragate type.

   The aggragate is represented as a tree.  If a decision has
   been made to allocate the aggragate in static data, the
   tree pointer will be NULL and the data pointer will have
   an address.

 */
class const_agg : public vhdl_const {
private:
    pType ty_aggragate;
    NODE *agg_tree;
public:
    const_agg(void) 
    { 
	ty_aggragate = NULL;
	agg_tree = NULL;
    }
    
    void set_agg_ty( pType ty ) 
    {
	ty_aggragate = ty;
    }    
    const pType get_agg_ty(void)
    {
	return ty_aggragate;
    }

    void set_tree( NODE *tree ) 
    {
	assert( tree != NULL );
	agg_tree = tree;
    }
    const NODE *get_tree(void)
    {
	return agg_tree;
    }
    const uint get_cn_kind( void ) { return cn_aggregate; }
}; // const_agg


#endif
