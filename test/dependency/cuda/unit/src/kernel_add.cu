#include <cuda_runtime.h>

__global__ void
kernel_add(const int n, const double* x, double* y) {
  int index = blockDim.x * blockIdx.x + threadIdx.x;
  if (index < n) {
    y[n] = y[n] + x[n];
  }
}

void
invoke_kernel_add(const int n, const double* x_d, const double* y_d) {
  const int n_thread_per_block = 256;
  const int n_block_per_grid =
    (n + n_thread_per_block - 1) / n_thread_per_block;
  kernel_add<<<n_block_per_grid, n_thread_per_block>>>(n, x_d, y_d);
}
