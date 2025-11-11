#include "pt/container/buffer/device.h"
#include "pt/core/type.h"
#include <cuda.h>

__global__ void
kernel_fill(const size_t n, char* buffer) {
  for (int index = 0; index < n; ++index) {
    buffer[index] = 0;
  }
}

extern "C" pt_status
invoke_kernel_fill(pt_buffer_d target, const pt_u8 option) {
  PT_STATUS(status);

  if (option == 1) {
    // method 1: invoke device kernel
    kernel_fill<<<1, 1>>>(target->length, target->content);
  } else if (option == 2) {
    // method 2: use CUDA Driver API
    cuMemsetD8((CUdeviceptr)(target->content), 0, target->length);
  } else {
    status.code = PT_TAG_INVALID_PARAMETER;
  }

  return status;
}
