#include "pt/container/buffer/host.h"
#include "pt/core/memory/host.h"

pt_status
pt_acquire_buffer_h(pt_buffer_h target[1], const size_t length) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc_h(target, sizeof **target));
  pt_buffer_h handle = *target;
  pt_safe_invoke(pt_malloc_h(&(handle->content), length));
  handle->length = length;

  return status;
}
