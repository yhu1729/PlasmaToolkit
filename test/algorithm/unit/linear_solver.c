#include "pt/algorithm/linear_solver.h"
#include "pt/foundation/context.h"
#include "pt/foundation/macro.h"
#include "pt/foundation/memory.h"
#include "pt/foundation/test.h"
#include <stdlib.h>

void
test_direct_4(void) {
  pt_context context;
  pt_test_invoke(PT_TAG_SUCCESS, pt_acquire(&context, PT_TAG_LOCAL));

  pt_linear_solver target;
  pt_test_invoke(PT_TAG_SUCCESS, pt_acquire(&target, context, PT_TAG_DIRECT));

  pt_test_invoke(PT_TAG_SUCCESS, pt_prepare(target, 4, 2, NULL));
  double* A;
  double* B;
  pt_test_invoke(PT_TAG_SUCCESS, pt_calloc(&A, 4 * 4, sizeof(double)));
  pt_test_invoke(PT_TAG_SUCCESS, pt_calloc(&B, 4 * 2, sizeof(double)));
  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 4; ++col) {
      int value = rand();
      A[row + col * 4] = ((double)(value) / (double)(RAND_MAX)) * 2.0 - 1.0;
    }
    for (int col = 0; col < 2; ++col) {
      int value = rand();
      B[row + col * 4] = ((double)(value) / (double)(RAND_MAX)) * 2.0 - 1.0;
    }
  }
  pt_test_invoke(PT_TAG_SUCCESS, pt_apply(target, A, B));

  pt_test_invoke(PT_TAG_SUCCESS, pt_free(A));
  pt_test_invoke(PT_TAG_SUCCESS, pt_free(B));
  pt_test_invoke(PT_TAG_SUCCESS, pt_release(target));
  pt_test_invoke(PT_TAG_SUCCESS, pt_release(context));
}

PT_TEST_LIST = {
  {test_direct_4, "direct; 4-by-4"},
  {NULL, NULL},
};

PT_TEST_MAIN
