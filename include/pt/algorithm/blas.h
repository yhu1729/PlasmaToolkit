#pragma once

#include "pt/algorithm/blas.f90.h"
#include "pt/foundation/tag.h"
#include <stdlib.h>

extern void dscal(int* n, double* a, double* x, int* inc_x);

pt_error pt_dscal(size_t n, double a, double* x, int inc_x);

#define pt_scal(_n, _a, _x, _inc_x) \
  _Generic((_a), double: pt_dscal)((_n), (_a), (_x), (_inc_x))
