#pragma once

#include "pt/foundation/tag.h"

extern void
dgetrf(int* m, int* n, double* A, int* ld_A, int* pivot, int* info);

pt_error pt_dgetrf(int m, int n, double* A, int ld_A, int* pivot);

#define pt_getrf(_m, _n, _A, _ld_A, _pivot) \
  _Generic((*(_A)), double: pt_dgetrf)((_m), (_n), (_A), (_ld_A), (_pivot))
