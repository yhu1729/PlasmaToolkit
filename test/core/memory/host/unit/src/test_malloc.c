#include "pt/core/memory.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void test_allocate_small(void) {
  char* target;
  pt_safe_invoke(pt_malloc(&target,16));
  pt_free(target);

  pt_check_ok();
}

void test_allocate_large(void) {
  char* target;
  pt_safe_invoke(pt_malloc(&target,1024));
  pt_free(target);

  pt_check_ok();
}

PT_TEST_LIST(
    {test_allocate_small,"allocate small chunks"},
    {test_allocate_large,"allocate large chunks"});

PT_TEST_UNIT_MAIN
