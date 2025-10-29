#include "pt/core/context.h"
#include "pt/core/macro.h"
#include "pt/core/memory.h"

pt_status
pt_release_context(pt_context target) {
  PT_STATUS(status);

  switch (target->type) {
  case PT_TAG_NETWORK_LOCAL:
    pt_release(target->interface.local);
    break;
  case PT_TAG_NETWORK_MPI:
    pt_release(target->interface.mpi);
    break;
#ifdef PT_USE_NCCL
  case PT_TAG_NETWORK_NCCL:
    pt_release_context_nccl(target->interface.nccl);
    pt_release(target->interface.mpi);
    break;
#endif
  default:
    status.code = PT_TAG_INVALID_PARAMETER;
  }
  pt_safe_invoke(pt_free(target));

  return status;
}
