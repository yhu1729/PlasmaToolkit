#include "pt/core/context/nccl.h"
#include "pt/core/memory.h"

pt_status
pt_release_context_nccl(pt_context_nccl target) {
  PT_STATUS(status);

  if (target->active) {
    pt_safe_invoke(pt_finalize_context_nccl(target));
  }
  pt_safe_invoke(pt_free(target));

  return status;
}
