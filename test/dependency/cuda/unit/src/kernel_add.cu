#include <cuda_runtime.h>

__global__ void
kernel_add(const int n, const double* x, double* y) {
  int index = blockDim.x * blockIdx.x + threadIdx.x;
  if (index < n) {
    y[index] += x[index];
  }
}

extern "C" {
void
invoke_kernel_add(const int n, const double* x, double* y) {
  double* x_d;
  double* y_d;
  cudaMalloc((void**)&x_d, n * sizeof(double));
  cudaMalloc((void**)&y_d, n * sizeof(double));

  cudaMemcpy(x_d, x, n * sizeof(double), cudaMemcpyHostToDevice);
  cudaMemcpy(y_d, y, n * sizeof(double), cudaMemcpyHostToDevice);

  const int n_thread_per_block = 256;
  const int n_block_per_grid =
    (n + n_thread_per_block - 1) / n_thread_per_block;
  kernel_add<<<n_block_per_grid, n_thread_per_block>>>(n, x_d, y_d);

  cudaMemcpy(y, y_d, n * sizeof(double), cudaMemcpyDeviceToHost);

  cudaFree(x_d);
  cudaFree(y_d);
}
}
