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

#include <freehdl/vaul-mempool.h>
#include <freehdl/vaul-util.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static const size_t block_size = 1016;

vaul_memregion::vaul_memregion()
{
    blocks = NULL;
}

vaul_memregion::~vaul_memregion()
{
    block *b, *b2;
    int n = 0;
    for(b = blocks; b; b = b2) {
	b2 = b->link;
	// printf("freed block @ %p-%p\n", b, ((char *)b) + b->size);
	::free(b);
	n++;
    }
//  printf("freed %d bytes of mem\n", n * block_size);
}

bool vaul_memregion::contains(void *m)
{
    for(block *b = blocks; b; b = b->link)
	if(m >= (void *)(b->mem) && m < (void *)(b->mem + b->size))
	    return 1;
    return 0;
}

vaul_mempool::vaul_mempool()
{
    mem = NULL;
    free = 0;
}

vaul_mempool::~vaul_mempool()
{
}

void *vaul_mempool::alloc(size_t size)
{
    void *ptr;

    if(size > free) {
	size_t new_size = (size > block_size? size : block_size);
	block *b = (block *)vaul_xmalloc(sizeof(block) + new_size);
//	printf("new block @ %p\n", b);
	b->link = blocks;
	blocks = b;
	mem = b->mem;
	free = new_size;
	b->size = 0;
    }
    ptr = mem;
    mem += size;
    free -= size;
    blocks->size += size;
//  printf("allocated %d bytes @ %p.\n", size, ptr);
    return ptr;
}

void vaul_mempool::store(vaul_memregion *r)
{
    block **bp;
    for(bp = &blocks; *bp; bp = &(*bp)->link)
	;
    *bp = r->blocks;
    r->blocks = blocks;
    blocks = NULL;
    mem = 0;
    free = 0;
}

void vaul_mempool::store(vaul_memregion &r)
{
    store(&r);
}

vaul_stringpool::vaul_stringpool()
{
}

vaul_stringpool::~vaul_stringpool()
{
}

char *vaul_stringpool::add(char *str)
{
    for(block *b = blocks; b; b = b->link)
	for(char *cp = &b->mem[0]; cp < &b->mem[b->size]; cp += strlen(cp)+1)
	    if(!strcmp(cp, str))
		return cp;
    return strcpy((char *)alloc(strlen(str)+1), str);
}

