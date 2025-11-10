#include "pt/container/buffer.h"
#include "pt/core/memory.h"
#include "pt/core/tag.h"

pt_status
pt_release_buffer(pt_buffer target) {
  PT_STATUS(status);

  if ((target->feature & PT_FEATURE_ON_HOST) && target->host) {
    pt_safe_invoke(pt_release_buffer_h(target->host));
    target->host = NULL;
  }
  if ((target->feature & PT_FEATURE_ON_DEVICE) && target->device) {
    pt_safe_invoke(pt_release_buffer_d(target->device));
    target->device = NULL;
  }

  pt_safe_invoke(pt_free_h(target));

  return status;
}
