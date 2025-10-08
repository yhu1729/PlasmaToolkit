#include "pt/core/memory.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void test_free_small(void) {
  char* target;
  pt_malloc(&target,16);
  pt_safe_invoke(pt_free(target));

  pt_check_ok();
}

void test_free_large(void) {
  char* target;
  pt_malloc(&target,1024);
  pt_safe_invoke(pt_free(target));

  pt_check_ok();
}

PT_TEST_LIST(
    {test_free_small,"free small chunks"},
    {test_free_large,"free large chunks"});

PT_TEST_UNIT_MAIN
