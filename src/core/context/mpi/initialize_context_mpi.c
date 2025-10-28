#include "pt/core/context/mpi.h"
#include "pt/core/log.h"

pt_status
pt_initialize_context_mpi(pt_context_mpi target, pt_context leader) {
  PT_STATUS(status);

  if (target->active) {
    status.code = PT_TAG_INVALID_NETWORK;

    return status;
  }

  target->active = true;

  if (leader) {
    pt_emit_log_error("TODO");
    status.code = PT_TAG_INVALID_PARAMETER;

    return status;
  } else {
    target->network = MPI_COMM_WORLD;
  }
  int buffer[1];
  MPI_Comm_rank(target->network, buffer);
  target->rank = buffer[0];
  MPI_Comm_size(target->network, buffer);
  target->size = buffer[0];

  return status;
}
