#include "pt/algorithm/blas.h"
#include "pt/foundation/test.h"
#include <limits.h>

inline static void
test_step_1(void) {
  double x[4] = {1.0, 2.0, 3.0, 4.0};
  pt_invoke(pt_scal(4, 2.0, x, 1));
  pt_test_assert(x[0] == 2.0);
  pt_test_assert(x[1] == 4.0);
  pt_test_assert(x[2] == 6.0);
  pt_test_assert(x[3] == 8.0);
}

inline static void
test_step_2(void) {
  double x[4] = {1.0, 2.0, 3.0, 4.0};
  pt_invoke(pt_scal(2, 2.0, x, 2));
  pt_test_assert(x[0] == 2.0);
  pt_test_assert(x[1] == 2.0);
  pt_test_assert(x[2] == 6.0);
  pt_test_assert(x[3] == 4.0);
}

inline static void
test_step_10000(void) {
  size_t size = (size_t)INT_MAX + 10;
  double* x = calloc(size, sizeof(double));
  for (size_t index = 0; index < size; ++index) {
    x[index] = (double)index;
  }
  pt_invoke(pt_scal(size / 10000, 2.0, x, 10000));
  for (size_t index = 0; index < size / 10000 * 10000; index += 10000) {
    pt_test_assert(x[index] == 2.0 * (double)index);
  }
}

PT_TEST_LIST = {
  {test_step_1, "step size 1"},
  {test_step_2, "step size 2"},
  {test_step_10000, "step size 10000"},
  {NULL, NULL},
};

PT_TEST_MAIN
