#pragma once

#include "pt/foundation/context.h"

struct _pt_pde_t {
  pt_context context;
  int variable;
};
typedef struct _pt_pde_t* pt_pde;
