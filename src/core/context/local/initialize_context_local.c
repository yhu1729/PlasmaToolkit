#include "pt/core/context/local.h"

pt_status
pt_initialize_context_local(pt_context_local target[1]) {
  PT_STATUS(status);

  target->active = true;

  return status;
}
