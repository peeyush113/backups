#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <mcutil.h>


#define NUM_TIMERS 20

struct timeval timer_start[NUM_TIMERS];
int elapsed_time[NUM_TIMERS];
int timer_in_use[NUM_TIMERS];
int current_timer = 0;

void cutCreateTimer(unsigned int* timer)
{
  if(current_timer != NUM_TIMERS)
  {
    *timer = current_timer++;
    elapsed_time[*timer] = 0;
  }
  else
  {
    fprintf(stderr, "Error: maximum number of mcutil timers exceeded\n");
    exit(1);
  }
}

void cutStartTimer(unsigned int timer)
{
  gettimeofday(( &timer_start[timer] ), (struct timeval*)0 );
}

void cutStopTimer(unsigned int timer)
{
  struct timeval end;

  gettimeofday(&end, (struct timeval*)0);

  elapsed_time[timer] += 
    ((float)(end.tv_sec - timer_start[timer].tv_sec)*1000) +
    ((float)(end.tv_usec - timer_start[timer].tv_usec))/1000.0;

}

float cutGetTimerValue(unsigned int timer)
{
  return elapsed_time[timer];
}

void cutDeleteTimer(unsigned int timer)
{
  //Really should do something here eventually
}

void cudaMemcpy(void* dest, void* src, size_t size, int type)
{
  memcpy(dest, src, size);
}

void cudaMalloc(void** dest, size_t size)
{
  if(dest != NULL)
    *dest = malloc(size);
}

void cudaFree(void* ptr)
{
  free(ptr);
}

void cudaMemset(void* ptr, int i, size_t size)
{
  memset(ptr, i, size);
}

void cudaThreadSynchronize()
{
  return;
}


void cudaMemcpyToSymbol(void* dst, void* src, size_t size, int type)
{
  memcpy(dst, src, size);
}

__inline__ int __umul24(int x, int y)
{
  return x * y;
}
