#include "pt/core/context.h"
#include "pt/core/macro.h"

pt_status
pt_finalize_context(pt_context target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_finalize(target->interface, target->type));
  target->active = false;

  return status;
}
