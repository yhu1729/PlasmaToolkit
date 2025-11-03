#include "pt/container/buffer/device.h"
#include "pt/core/memory/device.h"

pt_status
pt_acquire_buffer_d(pt_buffer_d target[1], const size_t length) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc_d(target, sizeof **target));
  pt_buffer_d handle = *target;
  pt_safe_invoke(pt_malloc_d(&(handle->content), length));
  handle->length = length;

  return status;
}
