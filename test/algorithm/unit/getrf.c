#include "pt/algorithm/lapack.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"
#include "pt/foundation/test.h"

void
test_1(void) {
  const int n = 1;
  double* A;
  pt_invoke(pt_calloc(&A, n * n, sizeof(double)));
  const int ld_A = n;
  int* pivot;
  pt_invoke(pt_calloc(&pivot, n, sizeof(int)));

  A[0] = 2.0;
  pt_test_invoke(PT_TAG_SUCCESS, pt_getrf(n, n, A, ld_A, pivot));
  pt_test_assert_equal(A[0], 2.0, 1.0E-14);

  pt_invoke(pt_free(A));
  pt_invoke(pt_free(pivot));
}

void
test_4(void) {}

void
test_32(void) {}

void
test_64(void) {}

void
test_128(void) {}

void
test_256(void) {}

PT_TEST_LIST = {
  {test_1, "1-by-1 matrix"},
  {test_4, "4-by-4 matrix"},
  {test_32, "32-by-32 matrix"},
  {test_64, "64-by-64 matrix"},
  {test_128, "128-by-128 matrix"},
  {test_256, "256-by-256 matrix"},
  {NULL, NULL},
};

PT_TEST_MAIN
