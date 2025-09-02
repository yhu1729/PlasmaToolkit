#pragma once

#include "pt/foundation/context.h"
#include "pt/foundation/tag.h"

struct _pt_pde_t {
  pt_context context;
  int variable;
  int dimension;
};
typedef struct _pt_pde_t* pt_pde;

pt_error pt_acquire_pde(
  pt_pde target[1], const pt_pde_type type, int variable, int dimension);
pt_error pt_release_pde(pt_pde target);
