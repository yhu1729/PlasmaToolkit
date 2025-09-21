#pragma once

#include "pt/foundation/context.h"
#include "pt/foundation/tag.h"

struct _pt_linear_solver {
  pt_context context;
  pt_linear_solver_type type;

  struct {
    bool ready;
    int n_eqn;
    int n_rhs;
    int* pivot;
    bool pivot_ready;
  } info;
};
typedef struct _pt_linear_solver* pt_linear_solver;

pt_error pt_acquire_linear_solver(
  pt_linear_solver target[1], pt_context context,
  const pt_linear_solver_type type);
pt_error pt_release_linear_solver(pt_linear_solver target);
pt_error pt_prepare_linear_solver(
  pt_linear_solver target, const int n_eqn, const int n_rhs, double* A);
pt_error pt_apply_linear_solver(pt_linear_solver target, double* A, double* B);
