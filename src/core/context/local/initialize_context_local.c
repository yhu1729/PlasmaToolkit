#include "pt/core/context/local.h"

pt_status
pt_initialize_context_local(pt_context_local target) {
  PT_STATUS(status);

  if (target->active) {
    status.code = PT_TAG_INVALID_NETWORK;

    return status;
  }

  target->active = true;
  target->rank = 0;
  target->size = 1;

  return status;
}
