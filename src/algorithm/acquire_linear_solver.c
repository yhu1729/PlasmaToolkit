#include "pt/algorithm/linear_solver.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"

pt_error
pt_acquire_linear_solver(
  pt_linear_solver target[1], pt_context context,
  const pt_linear_solver_type type) {
  pt_invoke(pt_malloc(target, sizeof **target));

  pt_linear_solver pointer = *target;
  pointer->context = context;
  pointer->type = type;

  pointer->info.ready = false;
  pointer->info.n_eqn = 0;
  pointer->info.n_rhs = 0;
  pointer->info.pivot = NULL;
  pointer->info.pivot_ready = false;

  return PT_TAG_SUCCESS;
}
