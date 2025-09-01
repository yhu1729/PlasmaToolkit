#include "pt/container/vector.h"
#include "pt/foundation/error.h"
#include "pt/foundation/test.h"

pt_vector(int) v_int_t;

inline static void
test_fetch_first(void) {
  v_int_t target;

  pt_invoke(pt_acquire_vector(&target, 10));

  int* content = pt_vec2ptr(target);
  content[0] = 3;

  int* value_1;
  pt_invoke(pt_fetch_vector_element(target, 0, value_1));
  pt_test_assert(*value_1 == 3);
  pt_test_assert(value_1 == (content + 0));

  pt_invoke(pt_release_vector(target));
}

PT_TEST_LIST = {
  {test_fetch_first, "fetch first element"},
  {NULL, NULL},
};

PT_TEST_MAIN
