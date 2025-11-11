#include "pt/container/buffer/device.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void invoke_kernel_fill(pt_buffer_d target, const pt_u8 option);

void
test_small(void) {
  pt_buffer_d target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire_buffer_d(&target, 16));
  invoke_kernel_fill(target, 1);
  invoke_kernel_fill(target, 2);
  pt_release_buffer_d(target);

  pt_check_ok();
}

void
test_large(void) {
  pt_buffer_d target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire_buffer_d(&target, 131072));
  invoke_kernel_fill(target, 1);
  invoke_kernel_fill(target, 2);
  pt_release_buffer_d(target);

  pt_check_ok();
}

PT_TEST_LIST(
  {test_small, "Acquire a small buffer"},
  {test_large, "Acquire a large buffer"});

PT_TEST_UNIT_MAIN
