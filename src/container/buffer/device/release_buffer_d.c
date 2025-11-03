#include "pt/container/buffer/device.h"
#include "pt/core/memory/device.h"

pt_status
pt_release_buffer_d(pt_buffer_d target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_free_d(target->content));
  pt_safe_invoke(pt_free_d(target));

  return status;
}
