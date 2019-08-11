

#ifndef STACK_H
#define STACK_H


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


/**
   A stack template.  This template is instantiated with
   the stack type and the stack size.  For example:
<pre>
      stack<my_type, 128> my_stack;
</pre>
   creates a stack that can hold up to 128 elements of my_type.

 */
template <class stack_type, unsigned int stack_max>
class stack {

private:
    stack_type stak[ stack_max ];
    unsigned int ix;

public:
    stack(void) { ix = stack_max; }

    bool empty(void) { return ix == stack_max; }

    void reset(void) { ix = stack_max; }

    void push( stack_type &val )
    {
	assert( ix > 0 );
	ix--;
	stak[ ix ] = val;
    }

    stack_type pop(void)
    {
	stack_type val;

	assert( ix < stack_max );
	val = stak[ix];
	ix++;
	return val;
    }
};  // stack


#endif
