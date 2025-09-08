#pragma once

#include "pt/application/pde.h"

struct _pt_advection_t {
  pt_pde equation;
};
typedef struct _pt_advection_t* pt_advection;

pt_error pt_acquire_advection(
  pt_advection target[1], const int variable, const int dimension);
pt_error pt_release_advection(pt_advection target);
