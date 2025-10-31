#include "pt/test/check.h"
#include <cuda_runtime.h>
#include <stdlib.h>

int
main(void) {
  const int n = 32 * 1024;
  double* x = calloc(n, sizeof(double));
  double* y = calloc(n, sizeof(double));
  for (int index = 0; index < n; ++index) {
    y[index] = 0;
    x[index] = rand() / (double)RAND_MAX;
  }

  double* x_d;
  double* y_d;
  cudaMalloc((void**)&x_d, n * sizeof(double));
  cudaMalloc((void**)&y_d, n * sizeof(double));

  cudaMemcpy(x_d, x, n * sizeof(double), cudaMemcpyHostToDevice);
  cudaMemcpy(y_d, y, n * sizeof(double), cudaMemcpyHostToDevice);

  invoke_kernel_add(n, x_d, y_d);

  cudaMemcpy(y, y_d, n * sizeof(double), cudaMemcpyDeviceToHost);

  for (int index = 0; index < n; ++index) {
    pt_check_equal(y[index], x[index], PT_EPSILON_F64);
  }

  cudaFree(x_d);
  cudaFree(y_d);

  free(x);
  free(y);

  return EXIT_SUCCESS;
}
