#include "pt/algorithm/lapack.h"
#include "pt/algorithm/linear_solver.h"
#include "pt/foundation/error.h"

pt_error
pt_apply_linear_solver(pt_linear_solver target, double* A, double* B) {
  if ((!A) || (!B)) {
    return PT_TAG_INVALID_PARAMETER;
  }
  if (!(target->info.ready)) {
    return PT_TAG_INVALID_PARAMETER;
  }

  if (target->info.pivot_ready) {
    pt_invoke(pt_getrs(
      'N', target->info.n_eqn, target->info.n_rhs, A, target->info.n_eqn,
      target->info.pivot, B, target->info.n_eqn));
  } else {
    pt_invoke(pt_gesv(
      target->info.n_eqn, target->info.n_rhs, A, target->info.n_eqn,
      target->info.pivot, B, target->info.n_eqn));
  }

  return PT_TAG_SUCCESS;
}
