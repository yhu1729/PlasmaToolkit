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
  case PT_TAG_LOCAL:
    pt_acquire(&(handle->interface.local));
    break;
  case PT_TAG_MPI:
    pt_acquire(&(handle->interface.mpi));
    break;
  case PT_TAG_NCCL:
    break;
  case PT_TAG_MPI_NCCL:
    break;
  default:
    status.code = PT_TAG_INVALID_PARAMETER;
  }

  return status;
}
