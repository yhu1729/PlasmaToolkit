#include "pt/container/buffer/host.h"
#include "pt/core/memory.h"

pt_status
pt_acquire_buffer_h(pt_buffer_h target[1], const size_t length) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc(target, sizeof **target));
  pt_buffer_h handle = *target;
  handle->content = malloc(length);
  handle->length = length;

  return status;
}
