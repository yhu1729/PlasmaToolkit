#include "pt/algorithm/linear_solver.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"

pt_error
pt_release_linear_solver(pt_linear_solver target) {
  if (target->info.pivot) {
    pt_invoke(pt_free(target->info.pivot));
  }
  pt_invoke(pt_free(target));

  return PT_TAG_SUCCESS;
}
