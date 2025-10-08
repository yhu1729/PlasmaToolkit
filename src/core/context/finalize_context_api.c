#include "pt/core/context.h"

pt_status
pt_finalize_context_api(pt_context_api api, const pt_tag type) {
  PT_STATUS(status);

  switch (type) {
  case PT_TAG_LOCAL:
    pt_finalize_context_local(&(api.local));
    break;
  case PT_TAG_MPI:
    break;
  case PT_TAG_NCCL:
    break;
  case PT_TAG_MPI_NCCL:
    break;
  default:
    status.code = PT_TAG_INVALID_PARAMETER;
  }

  return status;
}
