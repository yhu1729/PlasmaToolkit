#include "pt/foundation/error.h"
#include "pt/foundation/test.h"
#include <string.h>

void
test_all(void) {
#define _PT_EXPAND_TO_TEST(tag, message) \
  do { \
    const char* result = pt_get_error_message(tag); \
    pt_test_assert(!strcmp(result, message)); \
  } while (0);

  _PT_ERROR_LIST(_PT_EXPAND_TO_TEST)

#undef _PT_EXPAND_TO_TEST
}

PT_TEST_LIST = {
  {test_all, "all"},
  {NULL, NULL},
};

PT_TEST_MAIN
