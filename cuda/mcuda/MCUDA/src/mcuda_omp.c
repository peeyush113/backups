#include "mcuda.h"
#include <stdio.h>
#include <omp.h>

//This function launches a kernel to be executed by a
// pool of threads.  This function assumes ownership
// of the provided parameter pointer.
void
__mcuda_kernel_launch(__cuda_kernel_function kernel_function,
                     dim3 grid, dim3 block, void** params)
{
  int current_block;
  dim3 blockIdx;
  //Divide the total number of blocks evenly among the processors
  int total_blocks = grid.x * grid.y;
  void* temp_params;

  //Sanity check the number of threads
  if(block.x * block.y * block.z > 512)
  {
    fprintf(stderr, "Error, too many threads in kernel launch\n");
    return;
  }

  if(params == NULL)
  //This seems pretty unlikely.  Probably should put a warning message here.
    temp_params = params;
  else
  {
    temp_params = *params;
    *params = NULL;
  }

  //Run the kernel function for each block
#pragma omp parallel for shared(total_blocks, kernel_function) private(current_block, blockIdx)
  for(current_block = 0; current_block < total_blocks;
      current_block++)
  {
    blockIdx.x = current_block%grid.x;
    blockIdx.y = (current_block / grid.x) % grid.y;
    blockIdx.z = 0;

    (*kernel_function)(temp_params, blockIdx, block, grid);
  }
}

