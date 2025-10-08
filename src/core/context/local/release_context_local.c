#include "pt/core/context.h"
#include "pt/core/memory.h"

pt_status
pt_release_context_local(pt_context_local target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_free(target));

  return status;
}
