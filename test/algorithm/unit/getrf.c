#include "pt/algorithm/lapack.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"
#include "pt/foundation/test.h"
#include <stdlib.h>

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
  pt_test_assert_equal(A[0], 2.0, PT_TEST_EPSILON_DOUBLE);

  pt_invoke(pt_free(A));
  pt_invoke(pt_free(pivot));
}

void
test_4(void) {
  const int n = 4;
  double* A;
  double* A_copy;
  pt_invoke(pt_calloc(&A, n * n, sizeof(double)));
  pt_invoke(pt_calloc(&A_copy, n * n, sizeof(double)));
  const int ld_A = n;
  int* pivot;
  int* pivot_copy;
  pt_invoke(pt_calloc(&pivot, n, sizeof(int)));
  pt_invoke(pt_calloc(&pivot_copy, n, sizeof(int)));

  for (int col = 0; col < n; ++col) {
    for (int row = 0; row < n; ++row) {
      int value = rand();
      A[row + col * n] = ((double)(value) / (double)(RAND_MAX)) * 2.0 - 1.0;
      A_copy[row + col * n] = A[row + col * n];
    }
  }
  pt_test_invoke(PT_TAG_SUCCESS, pt_getrf(n, n, A, ld_A, pivot));

  double* B;
  pt_invoke(pt_calloc(&B, n, sizeof(double)));
  const int ld_B = n;
  pt_test_invoke(
    PT_TAG_SUCCESS, pt_gesv(n, 1, A_copy, ld_A, pivot_copy, B, ld_B));
  for (int index = 0; index < n * n; ++index) {
    pt_test_assert_equal(A[index], A_copy[index], PT_TEST_EPSILON_DOUBLE);
  }
  for (int index = 0; index < n; ++index) {
    pt_test_assert_equal(pivot[n], pivot_copy[n], 0);
  }
  pt_invoke(pt_free(B));

  pt_invoke(pt_free(A));
  pt_invoke(pt_free(A_copy));
  pt_invoke(pt_free(pivot));
  pt_invoke(pt_free(pivot_copy));
}

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
