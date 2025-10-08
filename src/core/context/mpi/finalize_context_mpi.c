#include "pt/core/context/mpi.h"

pt_status
pt_finalize_context_mpi(pt_context_mpi target) {
  PT_STATUS(status);

  if (!(target->active)) {
    status.code = PT_TAG_INVALID_PARAMETER;

    return status;
  }

  target->active = false;
  target->rank = 0;
  target->size = 0;
  target->network = NULL;

  return status;
}
