#pragma once

#include <stdlib.h>

typedef struct pt_test_info_t* pt_test_info;
struct pt_test_info_t {
  struct {
    double min;
    double max;
    double total;
  } time;
};

struct pt_test_list_item_t {
  void (*handle)(int, char**, pt_test_info info);
  const char* name;
  int n_max;
  void (*report)(pt_test_info info);
};

extern const struct pt_test_list_item_t pt_test_list[];

#define PT_TEST_LIST_IMPL const struct pt_test_list_item_t pt_test_list[]

#define PT_TEST_LIST(...) \
  PT_TEST_LIST_IMPL = {__VA_ARGS__ __VA_OPT__(, ){NULL, NULL, 0, NULL}}

#include "pt/test/benchmark/main.h"
