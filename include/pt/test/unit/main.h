#pragma once

#include <stdlib.h>

#define PT_TEST_MAIN \
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
      handle(); \
    } \
    return EXIT_SUCCESS; \
  }
