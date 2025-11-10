#include "pt/container/buffer.h"
#include "pt/core/memory.h"
#include "pt/core/tag.h"

pt_status
pt_acquire_buffer(
  pt_buffer target[1], pt_context context, pt_feature feature,
  const size_t length) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc_h(target, sizeof **target));
  pt_buffer handle = *target;
  handle->context = context;
  handle->feature = feature;

  if (handle->feature & PT_FEATURE_ON_HOST) {
    pt_safe_invoke(pt_acquire_buffer_h(&(handle->host), length));
  }
  if (handle->feature & PT_FEATURE_ON_DEVICE) {
    pt_safe_invoke(pt_acquire_buffer_d(&(handle->device), length));
  }

  return status;
}
