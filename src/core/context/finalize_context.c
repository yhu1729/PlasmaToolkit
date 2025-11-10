#include "pt/core/context.h"

pt_status
pt_finalize_context(pt_context target) {
  PT_STATUS(status);

  if (!(target->active)) {
    status.code = PT_TAG_INVALID_NETWORK;

    return status;
  }

  pt_safe_invoke(
    pt_finalize_context_interface(target->interface, target->type));
  target->active = false;

  return status;
}
