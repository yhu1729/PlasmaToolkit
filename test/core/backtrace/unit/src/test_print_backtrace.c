#include "pt/core/backtrace.h"
#include "pt/test/assert.h"
#include "pt/test/unit.h"

void
f(pt_backtrace* backtrace) {
  PT_BACKTRACE(target, backtrace);
  pt_print_backtrace(&target);

  pt_assert_ok();
}

void
test_print_local(void) {
  PT_BACKTRACE_TOP(target_0);
  pt_print_backtrace(&target_0);

  PT_BACKTRACE(target_1, &target_0);
  pt_print_backtrace(&target_1);

  pt_assert_ok();
}

void
test_print_remote(void) {
  PT_BACKTRACE_TOP(target);
  f(&target);

  pt_assert_ok();
}

PT_TEST_LIST(
  {test_print_local, "print local backtrace"},
  {test_print_remote, "print remote backtrace"});

PT_TEST_UNIT_MAIN
