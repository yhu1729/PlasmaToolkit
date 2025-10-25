#pragma once

#include <stdlib.h>

#define PT_TEST_BENCHMARK_MAIN \
  int main(int argc, char** argv) { \
    struct pt_test_info_t info = { \
      .time = \
        { \
          .min = 0.0, \
          .max = 0.0, \
          .total = 0.0, \
        }, \
    }; \
    int list_size = 0; \
    for (list_size = 0;; ++list_size) { \
      if (!_pt_test_list[list_size].handle) { \
        break; \
      } \
    } \
    void (*handle)(int, char**, pt_test_info); \
    void (*report)(pt_test_info info); \
    for (int index = 0; index < size; ++index) { \
      handle = pt_test_list[index].handle; \
      report = pt_test_list[index].report; \
      pt_emit_log_info("BENCHMARK: %s", pt_test_list[index].name); \
      int n_max = pt_test_list[index].n_max; \
      for (int n = 0; n < n_max; ++n) { \
        handle(argc, argv, &info); \
      } \
      if (report) { \
        report(&info); \
      } \
      pt_emit_log_info("DONE: %s", pt_test_list[index].name); \
    } \
    void* _tmp = malloc(0); \
    free(_tmp); \
    return EXIT_SUCCESS; \
  }
