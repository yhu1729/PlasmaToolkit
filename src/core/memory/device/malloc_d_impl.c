#include "pt/core/log.h"
#include "pt/core/memory/device.h"
#include <cuda.h>

pt_status
pt_malloc_d_impl(
  void** target, const size_t size, const char* function, const char* file,
  const int line) {
  PT_STATUS(status);

  cudaMalloc(target, size);
  if (!(*target)) {
    status.code = PT_TAG_OUT_OF_MEMORY;

    return status;
  }
  pt_emit_log_debug(
    "malloc %p+%zu in \"%s\" at %s:%d", *target, size, function, file, line);

  return status;
}
