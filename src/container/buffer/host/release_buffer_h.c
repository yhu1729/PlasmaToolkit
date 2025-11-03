#include "pt/container/buffer/host.h"
#include "pt/core/memory/host.h"

pt_status
pt_release_buffer_h(pt_buffer_h target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_free_h(target->content));
  pt_safe_invoke(pt_free_h(target));

  return status;
}
