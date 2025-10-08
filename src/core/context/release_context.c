#include "pt/core/context.h"
#include "pt/core/context/local.h"
#include "pt/core/context/mpi.h"
#include "pt/core/context/nccl.h"
#include "pt/core/memory.h"

pt_status
pt_release_context(pt_context target) {
  PT_STATUS(result);

  switch (target->type) {
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
  pt_safe_invoke(pt_free(target));

  return result;
}
