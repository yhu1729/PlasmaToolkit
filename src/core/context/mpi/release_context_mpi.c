#include "pt/core/context/mpi.h"
#include "pt/core/memory.h"

pt_status
pt_release_context_mpi(pt_context_mpi target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_free(target));

  return status;
}
