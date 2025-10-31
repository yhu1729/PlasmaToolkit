#include "pt/core/memory/device.h"
#include <cuda.h>

extern "C" pt_status
pt_free_d_impl(
  void* target, const char* function, const char* file, const int line) {
  PT_STATUS(status);

  return status;
}
