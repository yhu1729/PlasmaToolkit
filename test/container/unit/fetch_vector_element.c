#include "pt/container/vector.h"
#include "pt/foundation/test.h"

pt_vector(int) v_int_t;

inline static void
test_fetch_first(void) {
  v_int_t target;

  pt_acquire_vector(&target, 10);

  int* value_0;
  pt_fetch_buffer_element(target->buffer, 0, &value_0);
  *value_0 = 3;

  int* value_1;
  pt_fetch_vector_element(target, 0, value_1);
  pt_test_assert(*value_1 == 3);
  pt_test_assert(value_1 == value_0);

  pt_release_vector(target);
}

PT_TEST_LIST = {
  {test_fetch_first, "fetch first element"},
  {NULL, NULL},
};

PT_TEST_MAIN
