#include "pt/core/log.h"
#include "pt/core/memory/device.h"
#include <cuda.h>

pt_status
pt_calloc_d_impl(
  void** target, const size_t num, const size_t size, const char* function,
  const char* file, const int line) {
  PT_STATUS(status);

  cudaMalloc(target, num * size);
  if (!(*target)) {
    status.code = PT_TAG_OUT_OF_MEMORY;

    return status;
  }
  cudaMemset(*target, 0, num * size);
  pt_emit_log_debug(
    "calloc %p+%zu in \"%s\" at %s:%d", *target, num * size, function, file,
    line);

  return status;
}
