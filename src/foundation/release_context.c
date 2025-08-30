#include "pt/foundation/context.h"

pt_error
pt_release_context(pt_context target) {
  if (target->type == PT_TAG_LOCAL) {
    struct _pt_context_local_t* c =
      pt_container_of(target, struct _pt_context_local_t, interface.context);
    free(c);
  } else {
    return PT_TAG_INVALID_PARAMETER;
  }

  return PT_TAG_SUCCESS;
}
