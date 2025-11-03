#include "pt/container/buffer/device.h"
#include "pt/core/macro.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void invoke_kernel_fill(pt_buffer_d target);

void
test_small(void) {
  pt_buffer_d target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire(&target, 16));
  invoke_kernel_fill(target);
  pt_release(target);

  pt_check_ok();
}

void
test_large(void) {
  pt_buffer_d target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire(&target, 131072));
  invoke_kernel_fill(target);
  pt_release(target);

  pt_check_ok();
}

PT_TEST_LIST(
  {test_small, "Acquire a small buffer"},
  {test_large, "Acquire a large buffer"});

PT_TEST_UNIT_MAIN
