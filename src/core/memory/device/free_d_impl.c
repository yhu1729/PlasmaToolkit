#include "pt/core/log.h"
#include "pt/core/memory/device.h"
#include <cuda_runtime.h>

pt_status
pt_free_d_impl(
  void* target, const char* function, const char* file, const int line) {
  PT_STATUS(status);

  pt_emit_log_debug(
    "free %p in \"%s\" at %s:%d", target, function, file, line);
  cudaFree(target);

  return status;
}
