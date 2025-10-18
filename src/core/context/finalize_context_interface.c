#include "pt/core/context.h"
#include "pt/core/macro.h"

pt_status
pt_finalize_context_interface(
  pt_context_interface interface, const pt_tag type) {
  PT_STATUS(status);

  switch (type) {
  case PT_TAG_LOCAL:
    pt_finalize(interface.local);
    break;
#ifdef PT_USE_MPI
  case PT_TAG_MPI:
    pt_finalize(interface.mpi);
    break;
#endif
  case PT_TAG_NCCL:
    break;
  case PT_TAG_MPI_NCCL:
    break;
  default:
    status.code = PT_TAG_INVALID_PARAMETER;
  }

  return status;
}
