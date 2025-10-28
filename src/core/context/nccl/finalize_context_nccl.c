#include "pt/core/context/nccl.h"

pt_status
pt_finalize_context_nccl(pt_context_nccl target) {
  PT_STATUS(status);

  if (!(target->active)) {
    status.code = PT_TAG_INVALID_NETWORK;

    return status;
  }

  target->active = false;
  target->rank = 0;
  target->size = 0;

  ncclCommDestroy(target->network);
  target->network = NULL;

  return status;
}
