#include "pt/algorithm/lapack.h"

pt_error
pt_dgetrs(
  char transpose, int n, int n_rhs, double* A, int ld_A, int* pivot, double* B,
  int ld_B) {
  if ((!A) || (!pivot) || (!B)) {
    return PT_TAG_NULL_POINTER;
  }
  if ((n < 1) || (n_rhs < 1) || (ld_A < 1) || (ld_B < 1)) {
    return PT_TAG_INVALID_PARAMETER;
  }

  int info;
  dgetrs(transpose, &n, &n_rhs, A, &ld_A, pivot, B, &ld_B, &info);
  if (info < 0) {
    return PT_TAG_INVALID_OUTPUT;
  }

  return PT_TAG_SUCCESS;
}
