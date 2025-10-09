#pragma once

#include "pt/core/log.h"
#include <stdlib.h>

#define PT_TEST_UNIT_MAIN \
  int main(void) { \
    int size = 0; \
    for (size = 0;; ++size) { \
      if (!pt_test_list[size].handle) { \
        break; \
      } \
    } \
    void (*handle)(void); \
    for (int index = 0; index < size; ++index) { \
      handle = pt_test_list[index].handle; \
      pt_emit_log_info("TEST: %s", pt_test_list[index].name); \
      handle(); \
      pt_emit_log_info("PASS: %s", pt_test_list[index].name); \
    } \
    return EXIT_SUCCESS; \
  }
