#include "pt/algorithm/blas.h"

pt_error
pt_dscal(int n, double a, double* x, int inc_x) {
  if (!x) {
    return PT_TAG_NULL_POINTER;
  }
  if ((n < 1) || (inc_x < 1)) {
    return PT_TAG_INVALID_PARAMETER;
  }
  if (a == 1.0) {
    return PT_TAG_SUCCESS;
  }

  dscal(&n, &a, x, &inc_x);

  return PT_TAG_SUCCESS;
}
