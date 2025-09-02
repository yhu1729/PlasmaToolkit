#include "pt/algorithm/blas.h"

pt_error
pt_dscal(int n, double a, double* x, int inc_x) {
  dscal(n, a, x, inc_x);

  return PT_TAG_SUCCESS;
}
