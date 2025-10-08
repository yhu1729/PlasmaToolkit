#pragma once

#include "pt/core/log.h"
#include <stdlib.h>

#define PT_TEST_UNIT_MAIN \
  int main(void) { \
    int list_size = 0; \
    for (list_size = 0;; ++list_size) { \
      if (!_pt_test_list[list_size].name) { \
        break; \
      } \
    } \
    void (*handle)(void); \
    for (int index = 0; index < list_size; ++index) { \
      handle = _pt_test_list[index].handle; \
      pt_emit_log_info("TEST: %s", _pt_test_list[index].name); \
      handle(); \
      pt_emit_log_info("PASS: %s", _pt_test_list[index].name); \
    } \
    return EXIT_SUCCESS; \
  }
