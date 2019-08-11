#include <mcuda.h>
#include <stdio.h>

#define USE_MCUDA_BARRIERS 1

#if USE_MCUDA_BARRIERS
#include "barrier.h"
#endif

//Global Variables and such
#define MAX_NUM_PTHREADS 32 
pthread_t __mcuda_pthreads[MAX_NUM_PTHREADS];
dim3 __kernel_grid_dim[2];
dim3 __kernel_block_dim[2];
__cuda_kernel_function __kernel_function[2];
#if USE_MCUDA_BARRIERS
pthread_barrier_mcuda __mcuda_pthread_barrier[2];
#else
pthread_barrier_t __mcuda_pthread_barrier[2];
#endif
int __num_mcuda_pthreads = 0;
int __current_barrier;
int __mcuda_pthread_terminate[2];
void* __kernel_argv[2];
int __tids[MAX_NUM_PTHREADS];
int assignment_type = DYNAMIC;

//These are for dynamic block assignment
int __next_block[2];
pthread_mutex_t __block_lock;

void __mcuda_pthread_pool(int num_threads)
{
  int i;
  for(i = 0; i < MAX_NUM_PTHREADS; i++)
    __tids[i] = i;

  if(__num_mcuda_pthreads != 0)
    __mcuda_pthread_destruct();

  num_threads = (num_threads > MAX_NUM_PTHREADS) ? MAX_NUM_PTHREADS : num_threads;

#if USE_MCUDA_BARRIERS
  pthread_barrier_init_mcuda(&__mcuda_pthread_barrier[0], num_threads+1);
  pthread_barrier_init_mcuda(&__mcuda_pthread_barrier[1], num_threads+1);
#else
  pthread_barrier_init(&__mcuda_pthread_barrier[0], NULL, num_threads+1);
  pthread_barrier_init(&__mcuda_pthread_barrier[1], NULL, num_threads+1);
#endif
  __current_barrier = 0;
  __mcuda_pthread_terminate[0] = 0;
  __mcuda_pthread_terminate[1] = 0;

  
  __num_mcuda_pthreads = num_threads;

  for(i = 0; i < num_threads; i++)
    pthread_create(&__mcuda_pthreads[i], NULL, 
		   __thread_pool_loop, (void*)&(__tids[i]));

  __kernel_function[0] = __kernel_function[1] = NULL;
  pthread_mutex_init(&__block_lock, NULL);
}

void __mcuda_pthread_init(int num_threads, int assignment)
{
  __mcuda_pthread_pool(num_threads);
  assignment_type = assignment;
}

void __mcuda_pthread_destruct()
{
  void* retval = NULL;
  int i;
  
 
  __kernel_function[__current_barrier] = NULL;
  __mcuda_pthread_terminate[__current_barrier] = 1;

#if USE_MCUDA_BARRIERS
  pthread_barrier_wait_mcuda(&__mcuda_pthread_barrier[__current_barrier]);
#else
  pthread_barrier_wait(&__mcuda_pthread_barrier[__current_barrier]);
#endif

  //Wait for all the threads to die before going on
  for(i = 0; i < __num_mcuda_pthreads; i++)
  {
    pthread_join(__mcuda_pthreads[i], &retval);
  }

  for(i = 0; i < 2; i++)
  {
    if(__kernel_argv[i] != NULL)
      free(__kernel_argv[i]);
    __kernel_argv[i] = NULL;
  }

}

//Launch the blocks evenly in a statically-assigned order
void 
launch_blocks_static_partition(__cuda_kernel_function function, 
                               int local_index, int current_barrier)
{
  int current_block;

  //Divide the total number of blocks evenly among the processors
  int total_blocks = __kernel_grid_dim[current_barrier].x *
                           __kernel_grid_dim[current_barrier].y;
  //Start with even chunks
  int start_block = local_index * (total_blocks / __num_mcuda_pthreads);
  //Adjust for the remainder
  start_block += (local_index > total_blocks % __num_mcuda_pthreads) ?
                   (total_blocks%__num_mcuda_pthreads) : local_index;
  int end_block = start_block + (total_blocks / __num_mcuda_pthreads);
  if(total_blocks % __num_mcuda_pthreads > local_index)
    end_block++;
  //Run the kernel function for each block
  for(current_block = start_block; current_block < end_block;
      current_block++)
  {
    dim3 blockIdx;
    blockIdx.x = current_block%__kernel_grid_dim[current_barrier].x;
    blockIdx.y = (current_block / __kernel_grid_dim[current_barrier].x) %
                         __kernel_grid_dim[current_barrier].y;
    blockIdx.z = 0;

    (*function)(__kernel_argv[current_barrier], blockIdx,
                     __kernel_block_dim[current_barrier],
                     __kernel_grid_dim[current_barrier]);
  }
}


void
launch_blocks_dynamic_assignment(__cuda_kernel_function function,
                               int local_index, int current_barrier)
{
  int current_block;
  int total_blocks = __kernel_grid_dim[current_barrier].x *
                         __kernel_grid_dim[current_barrier].y;

  while(1)
  {
    pthread_mutex_lock(&__block_lock);
    current_block = __next_block[current_barrier];
    if(__next_block[current_barrier] < total_blocks)
      __next_block[current_barrier]++;
    pthread_mutex_unlock(&__block_lock);

    if(current_block < total_blocks)
    {
      dim3 blockIdx;
      blockIdx.x = current_block%__kernel_grid_dim[current_barrier].x;
      blockIdx.y = (current_block / __kernel_grid_dim[current_barrier].x) %
                           __kernel_grid_dim[current_barrier].y;
      blockIdx.z = 0;

      (*function)(__kernel_argv[current_barrier], blockIdx,
                       __kernel_block_dim[current_barrier],
                       __kernel_grid_dim[current_barrier]);
    }
    else
      break;
  }
}

void* __thread_pool_loop(void* index)
{
  //The first thing we're going to do is toggle the current barrier
  int current_barrier = 1;
  int local_index = *((int*)index);
  dim3 blockIdx;
#if 0
  int current_block;
#endif  
  __cuda_kernel_function next_function = NULL;
  
  do{
      //Using the other barrier now
      current_barrier ^= 1;
#if USE_MCUDA_BARRIERS
      pthread_barrier_wait_mcuda(&__mcuda_pthread_barrier[current_barrier]);
#else
      pthread_barrier_wait(&__mcuda_pthread_barrier[current_barrier]);
#endif
      //Get the next function.  If it's NULL, it's either a kernel sync or
      //  environment destruct command
      next_function = __kernel_function[current_barrier];
      if(next_function != NULL)
      {
        int current_block;

  	//Divide the total number of blocks evenly among the processors
  	int total_blocks = __kernel_grid_dim[current_barrier].x *
                             __kernel_grid_dim[current_barrier].y;
#if 0
	for(current_block = 0; current_block < total_blocks; current_block++)
      	{
	  blockIdx.x = current_block%__kernel_grid_dim[current_barrier].x;
	  blockIdx.y = (current_block / __kernel_grid_dim[current_barrier].x) %
                         __kernel_grid_dim[current_barrier].y;
	  blockIdx.z = 0;
  	  (*next_function)(__kernel_argv[current_barrier], blockIdx,
                       __kernel_block_dim[current_barrier],
                       __kernel_grid_dim[current_barrier]);
	}

	

        if(assignment_type == STATIC)
#endif
	  launch_blocks_static_partition(next_function, local_index, current_barrier);
#if 0
	else // assignment == DYNAMIC
          launch_blocks_dynamic_assignment(next_function, local_index, current_barrier);
#endif
      }
  
      //Terminate when we get the destruct command
  }while(__mcuda_pthread_terminate[current_barrier] == 0);


  return NULL;
}
      


//This function launches a kernel to be executed by a 
// pool of threads.  This function assumes ownership 
// of the provided parameter pointer.  
void 
__mcuda_kernel_launch(__cuda_kernel_function kernel_function, 
		     dim3 grid, dim3 block, void** params)
{
  //Check to make sure that we actually have a thread pool
  if(__num_mcuda_pthreads == 0)
    __mcuda_pthread_init(MAX_NUM_PTHREADS, DYNAMIC);

  //Sanity check the number of threads
  if(block.x * block.y * block.z > 512)
  {
    fprintf(stderr, "Error, too many threads in kernel launch\n");
    return;
  }

  //Set up the basic kernel parameters
  __kernel_function[__current_barrier] = kernel_function;
  __kernel_grid_dim[__current_barrier] = grid;
  __kernel_block_dim[__current_barrier] = block;
  
  //Free the old kernel parameters, if there were any
  if(__kernel_argv[__current_barrier] != NULL)
    free(__kernel_argv[__current_barrier]);
  
  //Set the new kernel parameters
  if(params == NULL)
  //This seems pretty unlikely.  Probably should put a warning message here.
    __kernel_argv[__current_barrier] = params;
  else
  {
    __kernel_argv[__current_barrier] = *params;
    *params = NULL;
  }

  //Initialize the block ID to start at 0
  __next_block[__current_barrier] = 0;
  
  //Launch the kernel
#if USE_MCUDA_BARRIERS
  pthread_barrier_wait_mcuda(&__mcuda_pthread_barrier[__current_barrier]);
#else
  pthread_barrier_wait(&__mcuda_pthread_barrier[__current_barrier]);
#endif
  __current_barrier ^= 1;

  //If set, always launch synchronously
  __mcuda_kernel_sync();
}
 
void
__mcuda_kernel_sync()
{
  //Synchronization is achieved through a "kernel launch" with a 
  //  NULL function pointer.
  
  __kernel_function[__current_barrier] = NULL;
  //Dimensions really don't matter here
  
  //It doesn't take much time, so let's go ahead and free the 
  //  old arguments, if they're there.
  if(__kernel_argv[__current_barrier] == NULL)
    free(__kernel_argv[__current_barrier]);
  __kernel_argv[__current_barrier] = NULL;

  //Barrier sync with the thread pool
#if USE_MCUDA_BARRIERS
  pthread_barrier_wait_mcuda(&__mcuda_pthread_barrier[__current_barrier]);
#else
  pthread_barrier_wait(&__mcuda_pthread_barrier[__current_barrier]);
#endif
  __current_barrier ^= 1;
}

