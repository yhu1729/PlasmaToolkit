#include "pt/algorithm/blas.h"

pt_error
pt_dgemm(
  char* transpose_A, char* transpose_B, int m, int n, int k, double alpha,
  double* A, int ld_A, double* B, int ld_B, double beta, double* C, int ld_C) {
  if ((!A) || (!B) || (!C)) {
    return PT_TAG_NULL_POINTER;
  }
  if (
    (m < 1) || (n < 1) || (k < 1) || (ld_A < 1) || (ld_B < 1) || (ld_C < 1)) {
    return PT_TAG_INVALID_PARAMETER;
  }

  dgemm(
    transpose_A, transpose_B, &m, &n, &k, &alpha, A, &ld_A, B, &ld_B, &beta, C,
    &ld_C);

  return PT_TAG_SUCCESS;
}
