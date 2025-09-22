#include "pt/algorithm/linear_solver.h"
#include "pt/foundation/context.h"
#include "pt/foundation/macro.h"
#include "pt/foundation/memory.h"
#include "pt/foundation/test.h"
#include <stdlib.h>

void
generate_data(
  const int n_eqn, const int n_rhs, double* A, double* B, double* A_original,
  double* B_original) {
  for (int row = 0; row < n_eqn; ++row) {
    for (int col = 0; col < n_eqn; ++col) {
      const int index = row + col * n_eqn;
      int value = rand();
      A[index] = ((double)(value) / (double)(RAND_MAX)) * 2.0 - 1.0;
      A_original[index] = A[index];
    }
    for (int col = 0; col < n_rhs; ++col) {
      const int index = row + col * n_eqn;
      int value = rand();
      B[index] = ((double)(value) / (double)(RAND_MAX)) * 2.0 - 1.0;
      B_original[index] = B[index];
    }
  }
}

void
test_direct_4(void) {
  const int n_eqn = 4;
  const int n_rhs = 2;

  pt_context context;
  pt_test_invoke(PT_TAG_SUCCESS, pt_acquire(&context, PT_TAG_LOCAL));

  pt_linear_solver target;
  pt_test_invoke(PT_TAG_SUCCESS, pt_acquire(&target, context, PT_TAG_DIRECT));

  double* A;
  double* B;
  double* A_original;
  double* B_original;
  pt_test_invoke(PT_TAG_SUCCESS, pt_calloc(&A, n_eqn * n_eqn, sizeof(double)));
  pt_test_invoke(PT_TAG_SUCCESS, pt_calloc(&B, n_eqn * n_rhs, sizeof(double)));
  pt_test_invoke(
    PT_TAG_SUCCESS, pt_calloc(&A_original, n_eqn * n_eqn, sizeof(double)));
  pt_test_invoke(
    PT_TAG_SUCCESS, pt_calloc(&B_original, n_eqn * n_rhs, sizeof(double)));

  // solve
  pt_test_invoke(PT_TAG_SUCCESS, pt_prepare(target, n_eqn, n_rhs, NULL));
  generate_data(n_eqn, n_rhs, A, B, A_original, B_original);
  pt_test_invoke(PT_TAG_SUCCESS, pt_apply(target, A, B));

  // factor, solve
  generate_data(n_eqn, n_rhs, A, B, A_original, B_original);
  pt_test_invoke(PT_TAG_SUCCESS, pt_prepare(target, n_eqn, n_rhs, A));
  pt_test_invoke(PT_TAG_SUCCESS, pt_apply(target, A, B));

  pt_test_invoke(PT_TAG_SUCCESS, pt_free(A));
  pt_test_invoke(PT_TAG_SUCCESS, pt_free(B));
  pt_test_invoke(PT_TAG_SUCCESS, pt_free(A_original));
  pt_test_invoke(PT_TAG_SUCCESS, pt_free(B_original));
  pt_test_invoke(PT_TAG_SUCCESS, pt_release(target));
  pt_test_invoke(PT_TAG_SUCCESS, pt_release(context));
}

PT_TEST_LIST = {
  {test_direct_4, "direct; 4-by-4"},
  {NULL, NULL},
};

PT_TEST_MAIN
