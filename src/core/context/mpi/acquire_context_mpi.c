#include "pt/core/context/mpi.h"
#include "pt/core/memory.h"

pt_status
pt_acquire_context_mpi(pt_context_mpi target[1]) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc_h(target, sizeof **target));
  pt_context_mpi handle = *target;
  handle->active = false;
  handle->rank = 0;
  handle->size = 0;
  handle->network = 0;

  return status;
}
