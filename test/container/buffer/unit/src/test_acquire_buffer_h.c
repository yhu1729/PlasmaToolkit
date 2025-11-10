#include "pt/container/buffer/host.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_small(void) {
  pt_buffer_h target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire_buffer_h(&target, 16));
  pt_release_buffer_h(target);

  pt_check_ok();
}

void
test_large(void) {
  pt_buffer_h target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire_buffer_h(&target, 131072));
  pt_release_buffer_h(target);

  pt_check_ok();
}

PT_TEST_LIST(
  {test_small, "Acquire a small buffer"},
  {test_large, "Acquire a large buffer"});

PT_TEST_UNIT_MAIN
