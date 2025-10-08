#include "pt/core/context.h"

pt_status
pt_initialize_context(pt_context target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_initialize_context_api(target->api, target->type));
  target->active = true;

  return status;
}
