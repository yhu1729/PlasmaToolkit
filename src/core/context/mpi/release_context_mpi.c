#include "pt/core/context/mpi.h"
#include "pt/core/macro.h"
#include "pt/core/memory.h"

pt_status
pt_release_context_mpi(pt_context_mpi target) {
  PT_STATUS(status);

  if (target->active) {
    pt_safe_invoke(pt_finalize(target));
  }
  pt_safe_invoke(pt_free_h(target));

  return status;
}
