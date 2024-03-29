/* a dynamic array as a template

   Copyright (C) 1994-1997 University of Dortmund
   Department of Electrical Engineering, AG SIV

   VAUL is free software; you can redistribute it and/or modify it
   under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   VAUL is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General
   Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with VAUL; see the file COPYING.LIB.  If not, write
   to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA.

*/

#ifndef FREEHDL_VAUL_MY_DYNARRAY
#define FREEHDL_VAUL_MY_DYNARRAY

template<class T> struct my_dynarray {

    my_dynarray(int sz = 10)
    {
	elts = new T[sz];
	max_elts = sz;
	n_elts = 0;
    }

    ~my_dynarray()
    {
	delete[] elts;
    }

    T& operator[] (int i)    // unchecked, does not expand array
    {
	return elts[i];
    }

    void add(T e)            // add to end, expand array
    {
	if(max_elts <= n_elts) {
	    max_elts += 20;
	    T *new_elts = new T[max_elts];
	    for(int i = 0; i < n_elts; i++)
		new_elts[i] = elts[i];
	    delete[] elts;
	    elts = new_elts;
	}
	elts[n_elts++] = e;
    }

    void add_uniq(T e)
    {
	if(!contains(e))
	    add(e);
    }

    int size()
    {
	return n_elts;
    }

    bool contains(T e)
    {
	for(int i = 0; i < n_elts; i++)
	    if(elts[i] == e)
		return true;
	return false;
    }

private:
    T *elts;
    int n_elts, max_elts;
};

template<class T> struct my_dynparray : my_dynarray<void *> {

    my_dynparray(int sz = 10) : my_dynarray<void*>(sz)
    {
    }

    T*& operator [] (int i)
    {
	return (T*&) my_dynarray<void*>::operator[](i);
    }

    void add(T *e)
    {
	my_dynarray<void *>::add((void *)e);
    }

    void add_uniq(T *e)
    {
	my_dynarray<void *>::add_uniq((void *)e);
    }
};

#endif
