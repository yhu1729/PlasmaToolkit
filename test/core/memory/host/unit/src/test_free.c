#include "pt/core/memory.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_free_small(void) {
  char* target;
  pt_malloc(&target, 16);
  pt_expect(PT_TAG_SUCCESS, pt_free(target));

  pt_check_ok();
}

void
test_free_large(void) {
  char* target;
  pt_malloc(&target, 1024);
  pt_expect(PT_TAG_SUCCESS, pt_free(target));

  pt_check_ok();
}

PT_TEST_LIST(
  {test_free_small, "Free small chunks"},
  {test_free_large, "Free large chunks"});

PT_TEST_UNIT_MAIN
