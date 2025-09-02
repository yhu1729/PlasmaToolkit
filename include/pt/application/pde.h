#pragma once

#include "pt/foundation/context.h"

struct _pt_pde_t {
  pt_context context;
  int variable;
  int dimension;
};
typedef struct _pt_pde_t* pt_pde;
