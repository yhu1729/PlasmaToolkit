#include "pt/core/context.h"
#include "pt/core/memory.h"

pt_status
pt_acquire_context_local(pt_context_local target[1]) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc(target, sizeof **target));
  pt_context_local handle = *target;
  handle->active = false;
  handle->rank = 0;
  handle->size = 0;

  return status;
}
