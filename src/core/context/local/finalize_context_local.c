
#include "pt/core/context/local.h"

pt_status
pt_finalize_context_local(pt_context_local target[1]) {
  PT_STATUS(status);

  target->active = false;

  return status;
}
