/*
  Copyright (c) 2007 A. Arnold and J. A. van Meel, FOM institute
  AMOLF, Amsterdam; all rights reserved unless otherwise stated.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  In addition to the regulations of the GNU General Public License,
  publications and communications based in parts on this program or on
  parts of this program are required to cite the article
  "Harvesting graphics power for MD simulations"
  by J.A. van Meel, A. Arnold, D. Frenkel, S. F. Portegies Zwart and
  R. G. Belleman, Molecular Simulation, Vol. 34, p. 259 (2007).

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston,
  MA 02111-1307 USA
*/
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include "gpu.hpp"
#include "random.hpp"

int main(int argc, const char **argv)
{
  // a timer
  clock_t tS, tE;

  if (argc < 3) { 
    printf( "Usage: random <size in multiples of 6144> <loop>\nGenerates <loop> times <size> random numbers.\n" );
    return -1; 
  }
  // number of random numbers has to be a multiple of the number of threads for now
  const unsigned int size = atoi(argv[1]) * 6 * 1024;
  const unsigned int loop = atoi(argv[2]);

  printf( "Size: %d random numbers\n", size );
  printf( "Iterations: %d times\n", loop );

  int *tgt = new int[size];
  int *res = new int[size];

  /************************************************
   * system drand48
   ************************************************/

  tS = clock();

  srand48(123);
  for (unsigned int j = 0; j < loop; ++j) {
    for( unsigned int i = 0; i < size; ++i) {
      tgt[i] = lrand48();
    }
  }

  tE = clock();
  printf("GNU: %f ms\n", ((double)( tE - tS ) * 1000.0 / CLOCKS_PER_SEC) );

  /************************************************
   * GPU drand48
   ************************************************/


  GPU_init();

  RNG_rand48 r48(123);

  tS = clock();

  for (unsigned int j = 0; j < loop; ++j) {
    r48.generate(size);
  }

  tE = clock();
  printf("GPU: %f ms\n", ((double)( tE - tS ) * 1000.0 / CLOCKS_PER_SEC) );

  tS = clock();

  for (unsigned int j = 0; j < loop; ++j) {
    r48.get(res, size);
  }

  tE = clock();
  printf("Transfer: %f ms\n", ((double)( tE - tS ) * 1000.0 / CLOCKS_PER_SEC) );

  // test correctness
  for( unsigned int i = 0; i < size; ++i) {
    if (tgt[i] != res[i]) {
      printf( "ERROR: GPU lrand48 %d !!! %x != %x\n", (int)i, tgt[i], res[i]);
    }
  }

  delete tgt; delete res;
  return 0;
}
