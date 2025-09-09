#pragma once

#include "pt/foundation/context.h"
#include "pt/foundation/tag.h"

struct _pt_linear_solver {
  pt_linear_solver_type type;
  pt_context context;
};
typedef struct _pt_linear_solver* pt_linear_solver;

pt_error pt_acquire_linear_solver(
  pt_linear_solver target[1], const pt_linear_solver_type type,
  pt_context context);
pt_error pr_release_linear_solver(pt_linear_solver target);
