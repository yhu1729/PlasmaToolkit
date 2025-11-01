#include "pt/core/memory/host.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_small(void) {
  char* target;
  pt_malloc_h(&target, 16);
  pt_expect(PT_TAG_SUCCESS, pt_free_h(target));

  pt_check_ok();
}

void
test_large(void) {
  char* target;
  pt_malloc_h(&target, 1024);
  pt_expect(PT_TAG_SUCCESS, pt_free_h(target));

  pt_check_ok();
}

PT_TEST_LIST(
  {test_small, "Free small chunks"},
  {test_large, "Free large chunks"});

PT_TEST_UNIT_MAIN
