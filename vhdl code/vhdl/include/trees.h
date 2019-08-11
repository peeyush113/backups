
#ifndef TREES_H
#define TREES_H

/** \file
  
   This file contains the class definitions for the VHDL
   intermediate trees.

 */


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


enum { nd_bad_node,
       nd_const,
       nd_type,
       nd_sym
     };

/**
   Base class for the node type, which is the building block
   for the IR trees.

   This tree node is based on the trees developed by Peter Donovan and
   used in the Quickturn Verilog compiler.  They have proven to be
   fast and easy to manage, but they take some getting used to.

   The "kids" pointer points to the first child of the current node.
   The "sib" pointer points to the next "sibling" child.  For example,
   in the tree shown below, the kids pointer would point to "A".  Since
   "+" has no siblings in the tree shown, the "sib" node of "+" would
   be NULL.  The sibling node of "A" would point to "B".
<pre>
                                 +
                                / \
                               /   \
                              A     B
</pre>
<pre>

            +
           / \
          / kids
        NULL   \
                A
               /
             sib
             /  \
            B   NULL
</pre>

   A call like "foo( a, b + c, d, e)" would have the structure shown
   below (here the right pointer is the "kids" pointer and the left
   pointer is the "sib" pointer).
<pre>
             foo
             / \
           NULL a
               / \
              +
             / \
            d   b
           /   /
          e   c
</pre>

   This scheme for representing trees has several advantages: children
   can be easily added by simply inserting them into the sibling list;
   trees with more than two children can be easily represented and a
   field that reflects the number of children is not required.

<h4>
   Notes:
</h4>

<ul>
<li>
<p>
   kid_cnt
</p>
<p>
     kid_cnt is 32-bits to accomodate large statement lists.  For example,
     one of the children of a process would be a block, containing a
     statement list.  The kid_cnt of the block node will be the number
     of statements in the list.  In an HDL its possible for this to be
     very large, since automaticly generated VHDL may be encountered.
</p>
</li>
</ul>

 */
class node {
private:
    node *kids;
    node *sib;
    /** number of nodes down the "kids" chain */
    uint kid_cnt;         

    uint name      : 16,  // n_icon, n_plus, etc...
         td_rmark  :  1,  // tree dictionary: referenced flag
         td_rdonly :  1,  // tree dicitonary: VN reference copy
	 unused    : 14;

    SRC_REF sref;         // source reference information

public:
    node() 
    {
	kids = NULL;
	sib = NULL;
	name = n_bad_name;
	td_rmark = FALSE;
	td_rdonly = FALSE;
    }

    
    void *operator new( unsigned int num_bytes )
    {
	assert( FALSE );
	return NULL;
    }

    void *operator new( unsigned int num_bytes, pool *mem_pool )
    {
	return mem_pool->GetMem( num_bytes );
    }

    void set_name( node_name n )  { name = n; }
    node_name get_name(void)  { return name; }

    void set_kid( node *kid )  { kids = kid; }
    node *get_kid(void)        { return kids; }

    void set_sib( node *s )    { sib = s; };
    node *get_sib(void)        { return sib; }

    /* tree "macros" */
    uint is_leaf(void) { return kids == NULL; }
    uint is_nonleaf(void) { return kids != NULL; }

    node *first_kid(void)  { return kids; }
    node *second_kid(void) { return kids->get_sib(); }
    node *third_kid(void)  { return kids->get_sib()->get_sib(); }
    node *fourth_kid(void) { return kids->get_sib()->get_sib()->get_sib(); }
    node *fifth_kid(void)  { return kids->get_sib()->get_sib()->get_sib()->get_sib(); }
    
    // Virtual functions
    virtual uint get_kind(void) { return nd_bad_node; }

    //
    // node_const
    // 
    virtual void set_const( pConst c )
    {
	assert( FALSE );
    }
    virtual const pConst get_const(void)
    {
	return NULL;
    }
    //
    // node_type
    //
    virtual void set_type( pType t )
    {
	assert( FALSE );
    }
    virtual const pType get_type(void)
    {
	return NULL;
    }
    //
    // node_sym
    //
    virtual void set_sym( pSym s )
    {
	assert( FALSE );
    }
    virtual const pSym get_sym(void)
    {
	return NULL;
    }
}; // node


class node_const : public node {
private:
    pConst con;   // pointer to a constant object
public:
    node_const() : node {}
    uint get_kind(void) { return nd_const; }
    
    void set_const( pConst c )
    {
	con = c;
    }
    const pConst get_const(void)
    {
	return con;
    }

}; // node_const



class node_type : public node {
private:
    pType ty;     // pointer to a type object
public:
    uint get_kind(void) { return nd_type; }

    void set_type( pType t )
    {
	ty = t;
    }
    const pType get_type(void)
    {
	return ty;
    }
}; // node_const



class node_sym : public node {
private:
    pSym sy;     // pointer to a symbol
public:
    uint get_kind(void) { return nd_type; }

    void set_sym( pSym s )
    {
	sy = s;
    }
    const pSym get_sym(void)
    {
	return sy;
    }
}; // node_const


#endif
