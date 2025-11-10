#include "pt/core/context.h"

pt_status
pt_initialize_context_interface(
  pt_context_interface interface, const pt_tag type, pt_context leader) {
  PT_STATUS(status);

  switch (type) {
  case PT_TAG_NETWORK_LOCAL:
    pt_initialize_context_local(interface.local);
    break;
  case PT_TAG_NETWORK_MPI:
    pt_initialize_context_mpi(interface.mpi, leader);
    break;
#ifdef PT_USE_CUDA
  case PT_TAG_NETWORK_NCCL:
    pt_initialize_context_mpi(interface.mpi, leader);
    pt_initialize_context_nccl(interface.nccl, interface.mpi);
    break;
#endif
  default:
    status.code = PT_TAG_INVALID_PARAMETER;
  }

  return status;
}
