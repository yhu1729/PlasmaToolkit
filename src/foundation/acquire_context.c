#include "pt/foundation/context.h"
#include "pt/foundation/error.h"

pt_error
pt_acquire_context(pt_context target[1], const pt_context_type type) {
  if (type == PT_TAG_LOCAL) {
    pt_invoke(pt_acquire_context_impl_local(target));
  } else {
    return PT_TAG_INVALID_PARAMETER;
  }

  return PT_TAG_SUCCESS;
}
