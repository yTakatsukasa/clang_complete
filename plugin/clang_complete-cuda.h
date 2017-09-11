#pragma once
#if !defined(CLANG_COMPLETE_CUDA_H__)
#define CLANG_COMPLETE_CUDA_H__

#error "called"

//Block loading cuda_runtime.h and cuda_runtime_api.h inside genuine CUDA SDK
//#define __CUDA_RUNTIME_H__
//#define __CUDA_RUNTIME_API_H__
//#define __DRIVER_TYPES_H__
#include <stddef.h>
//#if !defined(__CUDA__)

#define __constant__ __attribute__((constant))
#define __device__ __attribute__((device))
#define __global__ __attribute__((global))
#define __host__ __attribute__((host))
#define __shared__ __attribute__((shared))
#define __launch_bounds__(...) __attribute__((launch_bounds(__VA_ARGS__)))

/*
struct dim3 {
  unsigned x, y, z;
  __host__ __device__ dim3(unsigned x, unsigned y = 1, unsigned z = 1) : x(x), y(y), z(z) {}
};

typedef struct cudaStream *cudaStream_t;
*/

int cudaConfigureCall(dim3 gridSize, dim3 blockSize, size_t sharedSize = 0, cudaStream_t stream = 0);

extern dim3 threadIdx, blockDim, blockIdx, gridDim;
//#endif

#endif //CLANG_COMPLETE_CUDA_H__
