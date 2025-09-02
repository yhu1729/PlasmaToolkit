#include "pt/algorithm/blas.h"
#include "pt/foundation/test.h"

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

PT_TEST_LIST = {
  {test_step_1, "step size 1"},
  {test_step_2, "step size 2"},
  {NULL, NULL},
};

PT_TEST_MAIN
