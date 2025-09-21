#include "pt/algorithm/lapack.h"
#include "pt/algorithm/linear_solver.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"

pt_error
pt_prepare_linear_solver(
  pt_linear_solver target, const int n_eqn, const int n_rhs, double* A) {
  if ((n_eqn < 1) || (n_rhs < 1)) {
    return PT_TAG_INVALID_PARAMETER;
  }

  bool flag_grow_pivot = (n_eqn > target->info.n_eqn);
  target->info.n_eqn = n_eqn;
  target->info.n_rhs = n_rhs;

  if (target->type == PT_TAG_DIRECT) {
    if (!(target->info.pivot)) {
      pt_invoke(pt_calloc(&(target->info.pivot), n_eqn, sizeof(int)));
    } else {
      if (flag_grow_pivot) {
        pt_invoke(pt_realloc(&(target->info.pivot), n_eqn * sizeof(int)));
      }
    }

    if (A) {
      pt_invoke(pt_getrf(n_eqn, n_eqn, A, n_eqn, target->info.pivot));
      target->info.pivot_ready = true;
    } else {
      target->info.pivot_ready = false;
    }
  } else {
    return PT_TAG_INVALID_PARAMETER;
  }
  target->info.ready = true;

  return PT_TAG_SUCCESS;
}
