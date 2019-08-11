#include <mcuda.h>
#include <stdio.h>
#include <stdlib.h>

//This function launches a kernel to be executed by a 
// pool of threads.  This function assumes ownership 
// of the provided parameter pointer.  
void 
__mcuda_kernel_launch(__cuda_kernel_function kernel_function, 
		     dim3 grid, dim3 block, void** params)
{
  int current_block;
  dim3 blockIdx;
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
 
  for(blockIdx.y = 0; blockIdx.y < grid.y; blockIdx.y++)
    for(blockIdx.x = 0; blockIdx.x < grid.x; blockIdx.x++) 
  {
    blockIdx.z = 0;
    (*kernel_function)(temp_params, blockIdx, block, grid);
  }
  if(temp_params != NULL);
    free(temp_params);
}

//Single thread means implicit synchronization
void
__mcuda_kernel_sync()
{
  return;
}

