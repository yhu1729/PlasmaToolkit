#pragma once

#include <stdlib.h>

struct _pt_test_list_item_t {
  void (*handle)(void);
  const char* name;
};
extern const struct _pt_test_list_item_t pt_test_list[];
#define PT_TEST_LIST_IMPL const struct _pt_test_list_item_t _pt_test_list[]
#define PT_TEST_LIST(...) \
  PT_TEST_LIST_IMPL = {__VA_ARGS__ __VA_OPT__(, ){NULL, NULL}};

#include "pt/test/unit/main.h"
