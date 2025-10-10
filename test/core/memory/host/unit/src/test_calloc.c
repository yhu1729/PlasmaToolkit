#include "pt/core/memory.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_allocate_small(void) {
  char* target;
  pt_expect(PT_TAG_SUCCESS, pt_calloc(&target, 16, sizeof(char)));
  target[15] = 'a';
  pt_free(target);

  pt_check_ok();
}

void
test_allocate_large(void) {
  double* target;
  pt_expect(PT_TAG_SUCCESS, pt_calloc(&target, 1024, sizeof(double)));
  target[1023] = 1.0;
  pt_free(target);

  pt_check_ok();
}

PT_TEST_LIST(
  {test_allocate_small, "Allocate small chunks"},
  {test_allocate_large, "Allocate large chunks"});

PT_TEST_UNIT_MAIN
