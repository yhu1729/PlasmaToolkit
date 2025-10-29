#include "pt/config.h"
#include "pt/core/context.h"
#include "pt/core/macro.h"
#include "pt/core/memory.h"

pt_status
pt_acquire_context(pt_context target[1], const pt_tag type) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc(target, sizeof **target));
  pt_context handle = *target;
  handle->type = type;
  handle->active = false;
  switch (handle->type) {
  case PT_TAG_NETWORK_LOCAL:
    pt_acquire(&(handle->interface.local));
    break;
  case PT_TAG_NETWORK_MPI:
    pt_acquire(&(handle->interface.mpi));
    break;
#ifdef PT_USE_CUDA
  case PT_TAG_NETWORK_NCCL:
    pt_acquire(&(handle->interface.mpi));
    pt_acquire_context_nccl(&(handle->interface.nccl));
    break;
#endif
  default:
    status.code = PT_TAG_INVALID_PARAMETER;
  }

  return status;
}
