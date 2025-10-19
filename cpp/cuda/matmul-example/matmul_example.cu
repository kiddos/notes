#include <cuda.h>
#include <stdio.h>

#include "matmul_example.h"

void cuda_check(cudaError_t status, const char* action = NULL,
                const char* file = NULL, int32_t line = 0) {
  // check for cuda errors

  if (status != cudaSuccess) {
    printf("CUDA error occurred: %s\n", cudaGetErrorString(status));
    if (action != NULL)
      printf("While running %s   (file %s, line %d)\n", action, file, line);
    exit(1);
  }
}

#define CUDA_CHECK(action) cuda_check(action, #action, __FILE__, __LINE__)

__global__ void matrix_mul_kernel(const float* A, const float* B, float* C,
                                  int size) {
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  int row = col / size;
  col %= size;

  if (row < size && col < size) {
    float sum = 0.0f;
    for (int k = 0; k < size; ++k) {
      sum += A[row * size + k] * B[k * size + col];
    }
    C[row * size + col] = sum;
  }
}

void matmul(float* A, float* B, float* C, int size) {
  int m = size * size;
  float *d_A, *d_B, *d_C;
  CUDA_CHECK(cudaMalloc(&d_A, m * sizeof(float)));
  CUDA_CHECK(cudaMalloc(&d_B, m * sizeof(float)));
  CUDA_CHECK(cudaMalloc(&d_C, m * sizeof(float)));

  // Copy data from host to device
  CUDA_CHECK(cudaMemcpy(d_A, A, m * sizeof(float), cudaMemcpyHostToDevice));
  CUDA_CHECK(cudaMemcpy(d_B, B, m * sizeof(float), cudaMemcpyHostToDevice));

  // Define grid and block dimensions
  int blockSize = 256;
  int numBlocks = (m + blockSize - 1) / blockSize;
  // Launch the kernel
  matrix_mul_kernel<<<numBlocks, blockSize>>>(d_A, d_B, d_C, size);

  CUDA_CHECK(cudaMemcpy(C, d_C, m * sizeof(float), cudaMemcpyDeviceToHost));

  CUDA_CHECK(cudaFree(d_A));
  CUDA_CHECK(cudaFree(d_B));
  CUDA_CHECK(cudaFree(d_C));
}
