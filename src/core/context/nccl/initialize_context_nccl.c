#include "pt/core/context/nccl.h"
#include "pt/core/type.h"
#include <unistd.h>

pt_status
pt_initialize_context_nccl(pt_context_nccl target, pt_context_mpi host) {
  PT_STATUS(status);

  if (target->active) {
    status.code = PT_TAG_INVALID_NETWORK;

    return status;
  }

  if (!(host->active)) {
    status.code = PT_TAG_INVALID_NETWORK;

    return status;
  }

  target->active = true;

  char host_name[32];
  gethostname(host_name, 32);
  for (int index = 0; index < 32; ++index) {
    if (host_name[index] == '.') {
      host_name[index] = '\0';
      break;
    }
  }

  pt_u64 host_hash[host->size];
  pt_safe_invoke(pt_get_host_hash(&(host_hash[host->rank]), host_name));
  MPI_Allgather(
    MPI_IN_PLACE, 0, MPI_DATATYPE_NULL, host_hash, sizeof(pt_u64), MPI_BYTE,
    host->network);

  target->rank = 0;
  for (int index = 0; index < host->size; ++index) {
    if (index == host->rank) {
      break;
    }
    if (host_hash[index] == host_hash[host->rank]) {
      target->rank += 1;
    }
  }

  ncclUniqueId id;
  if (host->rank == 0) {
    ncclGetUniqueId(&id);
  }
  MPI_Bcast(&id, sizeof(id), MPI_BYTE, 0, host->network);
  cudaSetDevice(target->rank);
  ncclCommInitRank(&(target->network), host->size, id, host->rank);

  return status;
}
