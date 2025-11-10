#include "pt/core/context.h"

pt_status
pt_initialize_context(pt_context target, pt_context leader) {
  PT_STATUS(status);

  if (target->active) {
    status.code = PT_TAG_INVALID_NETWORK;

    return status;
  }

  pt_safe_invoke(
    pt_initialize_context_interface(target->interface, target->type, leader));
  target->active = true;

  return status;
}
