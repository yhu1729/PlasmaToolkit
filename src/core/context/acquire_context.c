#include "pt/core/context.h"
#include "pt/core/memory.h"

pt_status
pt_acquire_context(pt_context target[1], const pt_tag type) {
  PT_STATUS(result);

  pt_safe_invoke(pt_malloc(target, sizeof **target));
  (*target)->type = type;
  switch ((*target)->type) {
  case PT_TAG_LOCAL:
    break;
  case PT_TAG_MPI:
    break;
  case PT_TAG_NCCL:
    break;
  case PT_TAG_MPI_NCCL:
    break;
  default:
    result.code = PT_TAG_INVALID_PARAMETER;
  }

  return result;
}
