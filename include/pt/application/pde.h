#pragma once

#include "pt/foundation/context.h"
#include "pt/foundation/tag.h"

typedef pt_error (*_pt_pde_get_variable_t)(pt_pde target, int variable[1]);
typedef pt_error (*_pt_pde_get_dimension_t)(pt_pde target, int dimension[1]);

struct _pt_pde_t {
  pt_context context;
  int variable;
  int dimension;

  _pt_pde_get_variable_t get_variable;
  _pt_pde_get_dimension_t get_dimension;
};
typedef struct _pt_pde_t* pt_pde;

pt_error pt_acquire_pde(
  pt_pde target[1], const pt_pde_type type, int variable, int dimension);
pt_error pt_release_pde(pt_pde target);
pt_error pt_get_pde_variable(pt_pde target, int variable[1]);
pt_error pt_get_pde_dimension(pt_pde target, int dimension[1]);
