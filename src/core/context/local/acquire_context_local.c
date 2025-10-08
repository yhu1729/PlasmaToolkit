#include "pt/core/context.h"

pt_status
pt_acquire_context_local(pt_context_local target[1]) {
  PT_STATUS(status);

  target->active = false;
  target->rank = 0;
  target->size = 1;

  return status;
}
