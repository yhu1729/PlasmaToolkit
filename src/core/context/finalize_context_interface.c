#include "pt/core/context.h"

pt_status
pt_finalize_context_interface(
  pt_context_interface interface, const pt_tag type) {
  PT_STATUS(status);

  switch (type) {
  case PT_TAG_NETWORK_LOCAL:
    pt_finalize_context_local(interface.local);
    break;
  case PT_TAG_NETWORK_MPI:
    pt_finalize_context_mpi(interface.mpi);
    break;
#ifdef PT_USE_CUDA
  case PT_TAG_NETWORK_NCCL:
    pt_finalize_context_nccl(interface.nccl);
    pt_finalize_context_mpi(interface.mpi);
    break;
#endif
  default:
    status.code = PT_TAG_INVALID_PARAMETER;
  }

  return status;
}
