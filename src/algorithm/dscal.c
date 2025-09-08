#include "pt/algorithm/blas.h"
#include <limits.h>

pt_error
pt_dscal(size_t n, double a, double* x, int inc_x) {
  int tmp_n;
  if (n < (size_t)INT_MAX) {
    tmp_n = n;
    dscal(&tmp_n, &a, x, &inc_x);
  } else {
    size_t n_block = n / INT_MAX;
    size_t n_extra = n % INT_MAX;
    for (size_t block = 0; block <= n_block; ++block) {
      tmp_n = (block == n_block) ? n_extra : INT_MAX;
      double* tmp_x = x + (block * (size_t)INT_MAX * inc_x);
      dscal(&tmp_n, &a, tmp_x, &inc_x);
    }
  }

  return PT_TAG_SUCCESS;
}
