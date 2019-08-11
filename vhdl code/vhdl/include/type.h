
#ifndef TYPE_H
#define TYPE_H

/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


#include "stdtypes.h"
#include "fifo_list.h"
#include "typedefs.h"
#include "str.h"
#include "pools.h"

enum { bad_type,
       ty_time,     // special 64 bit range for TIME variables (QT hack)
       ty_range,    // includes INTEGER, enumerations, CHAR, etc...
       ty_real,     // 32-bit floating point value
       ty_array,
       ty_record,
       ty_file };



/**
   Represent VHDL types.  VHDL types come in two forms: named
   and unnamed.  A named type has the form
<pre>
       type short_range is range 0..15;
</pre>
   Named types are entered into the symbol table like any other
   type.

   An unnamed type is created in a variable declartion.  For example,
<pre>
       variable short_val : array short_range of BIT;
</pre>
   A named type is simply a symbol that points to an unnamed type.
   Unnamed types are stored in an unnamed type pool.  Variables
   that share the same named type (e.g., INTEGER or NATURAL) will
   point to the same type in the type pool.  It should also be
   possible for two variables, declared with the same nunamed type
   to share the same type, but this is not done currently.  For
   example, the declarations for high_word and low_word could
   share the same type.
<pre>
      variable high_word : array (0 to 31) of BIT;
      variable low_word  : array (0 to 31) of BIT;
</pre>

<h4>
   Memory Allocation
</h4>

   New for symbols is only called from the symbol table.  New for
   types is only called from the type table.  If new compilers are
   not available, this localized code will have to be modified.

 */
class type {
private:
  /** if its an array, this width is the elem width */
    uint width;

public:
    type(void)
    {
	width = 0;
    }
    //
    // Overloaded new
    //

    void *operator new( unsigned int num_bytes )
    {
	assert( FALSE );
	return NULL;
    }

    void *operator new( unsigned int num_bytes, pool *mem_pool )
    {
	return mem_pool->GetMem( num_bytes );
    }

    // Memory is recovered by deleting the memory pool.  So delete
    // should do nothing.
    void operator delete( void *addr ) {/* do nothing */}

    const uint get_width(void) 
    { 
	return width; 
    } // get_width

    void set_width( uint w )   
    { 
	width = w; 
    } // set_width

    //
    // Virtual functions common to all classes
    //
    virtual const uint get_ty_kind(void)
    {
	return bad_type;
    }
    //
    // Virtual functions for derived classes
    //
    // -- type_time subclass
    //
    virtual void set_unit(uint unit )
    {
	assert( FALSE );
    }
    virtual uint get_unit(void)
    {
	assert( FALSE );
	return 0;
    }
    //
    // -- type_range subclass
    //
    virtual void set_lhs( int l )   
    { 
	assert( FALSE );
    }
    virtual const int get_lhs(void) 
    { 
	assert( FALSE );
	return 0; 
    }

    virtual void set_rhs( int r )   
    { 
	assert( FALSE );
    }
    const int get_rhs(void) 
    { 
	assert( FALSE );
	return 0; 
    }

    virtual void set_dir( uint dir ) 
    { 
	assert( FALSE );
    }
    virtual const uint get_dir(void) 
    { 
	assert( FALSE );
	return 0; 
    }

    virtual void set_range( int l, int r, uint dir )
    {
	assert( FALSE );
    }

    virtual void set_box(void)   
    { 
	assert( FALSE );
    }
    virtual void unset_box(void) 
    { 
	assert( FALSE );
    }
    virtual const Boolean is_box(void) 
    { 
	assert( FALSE );
	return FALSE; 
    }
    //
    // -- type_array subclass
    //
    virtual const uchar get_num_dims(void) 
    { 
	assert( FALSE );
	return 0; 
    }
    virtual void set_num_dims( uint ndim ) 
    { 
	assert( FALSE );
    }
    virtual const uint get_array_size(void) 
    {
	assert( FALSE );
	return 0;
    }
    virtual void set_array_size( uint s )
    {
	assert( FALSE );
    }
    virtual const pTypeRange get_array_range(void) 
    {
	assert( FALSE );
	return NULL;
    }
    virtual void set_array_range( pTypeRange r )
    {
	assert( FALSE );
    }
    virtual const pType get_array_base_type(void)
    {
	assert( FALSE );
	return NULL;
    }
    virtual void set_array_base_type( pType tBase )
    {
	assert( FALSE );
    }
    //
    // -- type_record subclass
    //
    virtual void dealloc()
    {
	assert( FALSE );
    }

    virtual const uint get_rec_size(void) 
    { 
	assert( FALSE );
	return 0;
    }
    virtual void put_rec_size( uint s ) 
    {
	assert( FALSE );
    }
    
    virtual pSym find_elem( STRING name ) 
    {
	assert( FALSE );
	return NULL;
    }
    virtual void add_elem( pSym sym )
    {
	assert( FALSE );
    }
    //
    // -- type_file subclass
    //
    virtual const pType get_file_base_type(void)
    {
	assert( FALSE );
	return NULL;
    } // get_base_type
    virtual void set_file_base_type( pType tBase )
    {
	assert( FALSE );
    } // set_base_type
}; // type



enum { time_bad_time,
       time_fs,
       time_ps,
       time_ns,
       time_us,
       time_ms,
       time_sec,
       time_min,
       time_hr 
     };
       

/**
   Special type for time.  Time is always 64-bits
   and, as a result, is outside of what can be 
   represented by a standard range.
 */
class type_time : public type {
private:
    uint time_unit;  // time_fs .. time_hr

public:
    type_time(uint unit = time_bad_time ) : type()
    {
	time_unit = unit;
    }
    
    void set_unit(uint unit )
    {
	time_unit = unit;
    }
    uint get_unit(void)
    {
	return time_unit;
    }

    const uint get_ty_kind(void)
    {
	return ty_time;
    }
}; // type_time



enum { bad_range_dir,
       range_to,
       range_downto };

/**
   Range types are limited to a complete range that can fit in
   32-bits.  (e.g., 0..(2^32)-1 or -(2^31) .. (02^31)-1.  This cannot
   represent ranges like TIME (defined in the standard library).
   The TIME range requires 64 bits (e.g., the range of time is 0..2^60).
   A special type is provided for this range (we'll see if this 
   special type was a bad idea or not).

 */
class type_range : public type {
private:
  /** left hand side of the range */
    int lhs;
  /** right hand side of range */
    int rhs;                
    uint direction : 2,     // to/downto
	 unconstrained : 1, // array bounds are <>, sometimes called a "box"
	 unused : 29;

public:
    type_range() : type()
    {
	lhs = 0;
	rhs = 0;
	direction = bad_range_dir;
	unconstrained = FALSE;
    }
    void set_lhs( int l )   
    { 
	lhs = l; 
    }
    const int get_lhs(void) 
    { 
	return lhs; 
    }

    void set_rhs( int r )   
    { 
	rhs = r; 
    }
    const int get_rhs(void) 
    { 
	return rhs; 
    }

    void set_dir( uint dir ) 
    { 
	direction = dir; 
    }
    const uint get_dir(void) 
    { 
	return direction; 
    }

    void set_range( int l, int r, uint dir )
    {
	set_lhs( l );
	set_rhs( r );
	set_dir( dir );
    }

    void set_box(void)   
    { 
	unconstrained = TRUE; 
    }
    void unset_box(void) 
    { 
	unconstrained = FALSE; 
    }
    const Boolean is_box(void) 
    { 
	return unconstrained; 
    }

    const uint get_ty_kind(void)
    {
	return ty_range;
    }
};  // type_range




class type_real : public type {
public:
    type_real() : type() {}
    const uint get_ty_kind(void)
    {
	return ty_real;
    }
}; // type_real


/**
   VHDL uses the concept of "array of type".  A multi-dimensional
   array is an "array of array".  As a result, a multi-dimensional
   array is a recursive data structure.  The current "top" represents
   the current highest dimension.

   A note on array indexes:

   If array A has three dimension, it will be index by A(k, j, i).
   Incrementing "i" will reference sequential array elements.  So,
   assuming that all bounds start at zero, the index expression will 
   be
<pre>
      index = i + ((j  + (k * size_dim2)) * size_dim2)
</pre>

   ?? Should the "delta" from zero also be included here, to aid
      in generating code for index expressions. ??

 */
class type_array : public type {
private:
    uchar num_dims;        // number of array dimensions, at this point (no more than 255)
    uint size;             // total size of array, in 32-bit words, at this point
    pTypeRange range;      // range for this dimension
    pType base_type;       // pointer to the array base type

public:
    type_array() : type()
    {
	num_dims = 0;
	size = 0;
	range = NULL;
	base_type = NULL;
    } // type_array constructor

    const uchar get_num_dims(void) 
    { 
	return num_dims; 
    }
    void set_num_dims( uint ndim ) 
    { 
	num_dims = (uchar)ndim; 
    }

    const uint get_array_size(void) 
    {
	return size;
    }
    void set_array__ize( uint s )
    {
	size = s;
    }

    const pTypeRange get_array_range(void) 
    {
	return range;
    }
    void set_array_range( pTypeRange r )
    {
	range = r;
    }

    const pType get_array_base_type(void)
    {
	return base_type;
    }
    void set_array_base_type( pType tBase )
    {
	base_type = tBase;
    }

    const uint get_ty_kind(void)
    {
	return ty_array;
    }
};  // type_array



/**
   Record elements are ordered the way they appear in the
   record.  Note that this means that when the type is
   created, the elements must be added in correct order.

   The record elements are represented by symbol objects.
   Note, however, that these objects are _not_ entered
   in the symbol table.  A record element can only be 
   accessed via its base base, so these names exist
   only in the scope of the base name.

 */
class type_record : public type {

private:
    uint size;        // size in 32-bit words
    FIFO_LIST<pSym> elem_list;

public:
    type_record() : type()
    {
	size = 0;
    } // type_record constructor

    // deallocate the element list
    void dealloc()
    {
	// deallocate the list
	elem_list.dealloc();
    }

    const uint get_rec_size(void) 
    { 
	return size; 
    }
    void put_rec_size( uint s ) 
    {
	size = s;
    }
    
    pSym find_elem( STRING name );

    // elements must be added in the correct order.
    void add_elem( pSym sym )
    {
	elem_list.add( sym );
    }

    const uint get_ty_kind(void)
    {
	return ty_record;
    }
}; // type_record



class type_file : public type {
private:
    pType base_type;
    
    // other file status information goes here
    
public:
    type_file() : type()
    {
	base_type = NULL;
    }  // type_file

    const pType get_file_base_type(void)
    {
	return base_type;
    } // get_base_type
    void set_file_base_type( pType tBase )
    {
	base_type = tBase;
    } // set_base_type

    const uint get_ty_kind(void)
    {
	return ty_file;
    }
};  // type_file


#endif
