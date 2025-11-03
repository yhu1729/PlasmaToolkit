#include "pt/container/buffer/device.h"
#include <cuda.h>

__global__ void
kernel_fill(const size_t n, char* buffer) {
  cuMemsetD8(buffer, 0, n);
}

extern "C" void
invoke_kernel_fill(pt_buffer_d target) {
  kernel_fill(target->length, target->content);
}
