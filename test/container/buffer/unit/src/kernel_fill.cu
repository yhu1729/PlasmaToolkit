#include "pt/container/buffer/device.h"
#include <cuda.h>

__global__ void
kernel_fill(const size_t n, char* buffer) {
  for (int index = 0; index < n; ++index) {
    buffer[index] = 0;
  }
}

extern "C" void
invoke_kernel_fill(pt_buffer_d target) {
  // method 1: invoke device kernel
  kernel_fill<<<1, 1>>>(target->length, target->content);
  // method 2: use CUDA Driver API
  cuMemsetD8((CUdeviceptr)(target->content), 0, target->length);
}
