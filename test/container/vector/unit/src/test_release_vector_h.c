#include "pt/container/vector/host.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_short(void) {
  pt_vector_h target;
  pt_acquire_vector_h(&target, double, 16);
  pt_expect(PT_TAG_SUCCESS, pt_release_vector_h(target));
}

void
test_long(void) {
  pt_vector_h target;
  pt_acquire_vector_h(&target, double, 1024);
  pt_expect(PT_TAG_SUCCESS, pt_release_vector_h(target));
}

PT_TEST_LIST(
  {test_short, "Release a short vector"},
  {test_long, "Release a long vector"});

PT_TEST_UNIT_MAIN
