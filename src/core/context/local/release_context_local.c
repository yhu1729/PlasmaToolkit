#include "pt/core/context.h"

pt_status
pt_release_context_local(pt_context_local target[1]) {
  PT_STATUS(status);

  target->active = false;

  return status;
}
