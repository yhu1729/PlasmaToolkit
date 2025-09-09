#include "pt/algorithm/lapack.h"
#include <stdlib.h>

pt_error
pt_dgetrf(int m, int n, double* A, int ld_A, int* pivot) {
  if ((A == NULL) || (pivot == NULL)) {
    return PT_TAG_NULL_POINTER;
  }
  if ((m == 0) || (n == 0) || (ld_A == 0)) {
    return PT_TAG_INVALID_PARAMETER;
  }

  int info;
  dgetrf(&m, &n, A, &ld_A, pivot, &info);
  if (info < 0) {
    return PT_TAG_INVALID_OUTPUT;
  } else if (info > 0) {
    return PT_TAG_SINGULAR_MATRIX;
  }

  return PT_TAG_SUCCESS;
}
