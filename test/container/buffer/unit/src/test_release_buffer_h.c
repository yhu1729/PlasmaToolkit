#include "pt/container/buffer/host.h"
#include "pt/core/macro.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_small(void) {
  pt_buffer_h target;
  pt_acquire(&target, 16);
  pt_expect(PT_TAG_SUCCESS, pt_release(target));

  pt_check_ok();
}

void
test_large(void) {
  pt_buffer_h target;
  pt_acquire(&target, 131072);
  pt_expect(PT_TAG_SUCCESS, pt_release(target));

  pt_check_ok();
}

PT_TEST_LIST(
  {test_small, "Release a small buffer"},
  {test_large, "Release a large buffer"});

PT_TEST_UNIT_MAIN
