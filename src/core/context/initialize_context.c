#include "pt/core/context.h"
#include "pt/core/macro.h"

pt_status
pt_initialize_context(pt_context target, pt_context leader) {
  PT_STATUS(status);

  if (target->active) {
    status.code = PT_TAG_INVALID_NETWORK;

    return status;
  }

  pt_safe_invoke(pt_initialize(target->interface, target->type, leader));
  target->active = true;

  return status;
}
