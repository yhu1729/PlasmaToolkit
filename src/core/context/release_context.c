#include "pt/core/context.h"
#include "pt/core/memory.h"

pt_status
pt_release_context(pt_context target) {
  PT_STATUS(status);

  switch (target->type) {
  case PT_TAG_LOCAL:
    pt_release(target->interface.local);
    break;
#ifdef PT_USE_MPI
  case PT_TAG_MPI:
    pt_release(target->interface.mpi);
    break;
#endif
  case PT_TAG_NCCL:
    break;
  case PT_TAG_MPI_NCCL:
    break;
  default:
    status.code = PT_TAG_INVALID_PARAMETER;
  }
  pt_safe_invoke(pt_free(target));

  return status;
}
