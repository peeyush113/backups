/* memory management

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

#ifndef FREEHDL_VAUL_MEMPOOL_H
#define FREEHDL_VAUL_MEMPOOL_H

#include <stddef.h>

//	vaul_memregion hält beliebeigen Speicher zusammen, der
//	vom Destruktor freigegeben wird.
//
struct vaul_memregion {

	vaul_memregion();
	~vaul_memregion();

	bool contains(void *mem);
		// Ermittelt, ob 'mem' irgendwo innerhalb eines Blockes
		// liegt, der zu dieser 'vaul_memregion' gehört.

	struct block {
		block *link;
		size_t size;
		char  mem[0];
	} *blocks;
};

//	vaul_mempool kann Speicher besorgen, der automatisch mit dem
//	'vaul_mempool' zusammen freigegeben wird.
//
//
struct vaul_mempool : protected vaul_memregion {

	vaul_mempool();
	~vaul_mempool();
		// Gibt allen gemerkten Speicher frei.

	void *alloc(size_t size);
		// Besorgt 'size' Bytes Speicher und merkt ihn sich.

	void store(vaul_memregion *r);
	void store(vaul_memregion &r);
		// Transferiert allen gemerkten Speicher nach 'r' und 
		// vergisst ihn.

	bool contains(void *mem)
		{ return vaul_memregion::contains(mem); }

private:
	char *mem;
	size_t free;
};

inline void *operator new(size_t size, vaul_mempool *pool)
 { return pool->alloc(size); }

inline void *operator new(size_t size, vaul_mempool &pool)
 { return pool.alloc(size); }

//	vaul_stringpool besorgt Speicher für Strings und vermeidet
//	Duplikate
//
struct vaul_stringpool : private vaul_mempool {

	vaul_stringpool();
	~vaul_stringpool();

	char *add(char *str);
		// Fügt 'str' zum Pool hinzu, falls es noch nicht drin
		// ist. Strings mit gleichem Inhalt führen zu gleichen
		// Rückgabewerten.

	void store(vaul_memregion *m)	{ vaul_mempool::store(m); }
	void store(vaul_memregion &m)	{ vaul_mempool::store(m); }
};

#endif


