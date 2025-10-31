#include "pt/core/context.h"
#include "pt/core/macro.h"
#include "pt/core/memory.h"

pt_status
pt_release_context_local(pt_context_local target) {
  PT_STATUS(status);

  if (target->active) {
    pt_safe_invoke(pt_finalize(target));
  }
  pt_safe_invoke(pt_free_h(target));

  return status;
}
