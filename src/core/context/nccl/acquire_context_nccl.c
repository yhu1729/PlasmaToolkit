#include "pt/core/context/nccl.h"
#include "pt/core/memory.h"

pt_status
pt_acquire_context_nccl(pt_context_nccl target[1]) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc(target, sizeof **target));
  pt_context_nccl handle = *target;
  handle->active = false;
  handle->rank = 0;
  handle->size = 0;
  handle->network = NULL;

  return status;
}
