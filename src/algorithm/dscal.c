#include "pt/algorithm/blas.h"
#include <limits.h>

pt_error
pt_dscal(size_t n, double a, double* x, size_t inc_x) {
  if (x == NULL) {
    return PT_TAG_NULL_POINTER;
  }
  if ((n == 0) || (inc_x == 0)) {
    return PT_TAG_INVALID_PARAMETER;
  }
  if (a == 1.0) {
    return PT_TAG_SUCCESS;
  }

  int tmp_n;
  int tmp_inc_x;
  if (n < (size_t)INT_MAX) {
    tmp_n = n;
    tmp_inc_x = inc_x;
    dscal(&tmp_n, &a, x, &tmp_inc_x);
  } else {
    tmp_inc_x = inc_x;
    size_t n_block = n / INT_MAX;
    size_t n_extra = n % INT_MAX;
    for (size_t block = 0; block <= n_block; ++block) {
      tmp_n = (block == n_block) ? n_extra : INT_MAX;
      double* tmp_x = x + (block * (size_t)INT_MAX * inc_x);
      dscal(&tmp_n, &a, tmp_x, &tmp_inc_x);
    }
  }

  return PT_TAG_SUCCESS;
}
