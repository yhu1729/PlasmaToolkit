#include "pt/container/vector.h"
#include "pt/foundation/macro.h"
#include "pt/foundation/test.h"

void
test_fetch_first(void) {
  pt_vector_i32 target;

  pt_test_invoke(PT_TAG_SUCCESS, pt_acquire_vector(&target, 10));

  int* content = pt_as_pointer(target);
  content[0] = 3;

  int* value_1;
  pt_test_invoke(PT_TAG_SUCCESS, pt_fetch_vector_element(target, 0, value_1));
  pt_test_assert(*value_1 == 3);
  pt_test_assert(value_1 == (content + 0));

  pt_test_invoke(PT_TAG_SUCCESS, pt_release_vector(target));
}

PT_TEST_LIST = {
  {test_fetch_first, "fetch first element"},
  {NULL, NULL},
};

PT_TEST_MAIN
