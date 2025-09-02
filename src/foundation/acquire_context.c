#include "pt/foundation/context.h"

pt_error
pt_acquire_context(pt_context target[1], const pt_tag type) {
  if (type == PT_TAG_LOCAL) {
    *target = pt_acquire_context_impl_local();
  } else {
    return PT_TAG_INVALID_PARAMETER;
  }

  return PT_TAG_SUCCESS;
}
