#include "pt/test/check.h"
#include <stdlib.h>

void invoke_kernel_add(const int n, const double* x, double* y);

int
main(void) {
  const int n = 32 * 1024;
  double* x = calloc(n, sizeof(double));
  double* y = calloc(n, sizeof(double));
  for (int index = 0; index < n; ++index) {
    x[index] = rand() / (double)RAND_MAX;
    y[index] = 0;
  }

  invoke_kernel_add(n, x, y);

  for (int index = 0; index < n; ++index) {
    pt_check_equal(y[index], x[index], PT_EPSILON_F64);
  }

  free(x);
  free(y);

  return EXIT_SUCCESS;
}
