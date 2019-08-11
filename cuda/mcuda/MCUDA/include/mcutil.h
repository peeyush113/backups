/*
 * (c) 2008 The Board of Trustees of the University of Illinois.
 */

#ifndef MCUDA_UTILS
#define MCUDA_UTILS

#define CUT_SAFE_CALL(x) (x)
#define CUDA_SAFE_CALL(x) (x)
#define CUT_CHECK_ERROR(x) 

#if defined(__cplusplus)
extern "C" {
#endif

void cutCreateTimer(unsigned int* timer);

void cutStartTimer(unsigned int timer);

void cutStopTimer(unsigned int timer);

float cutGetTimerValue(unsigned int timer);

void cutDeleteTimer(unsigned int timer);

void cudaMemcpy(void* dest, void* src, size_t size, int type);
void cudaMalloc(void** dest, size_t size);
void cudaFree(void* ptr);
void cudaMemcpyToSymbol(void* dst, void* src, size_t size, int type);
void cudaMemset(void* ptr, int i, size_t size);
void cudaThreadSynchronize();
//__inline__ int __umul24(int x, int y);

#if defined(__cplusplus)
}
#endif


#endif
