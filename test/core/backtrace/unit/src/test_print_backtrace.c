#include "pt/core/backtrace.h"
#include "pt/test/assert.h"
#include "pt/test/unit.h"

void
test_print_all(void) {
  PT_BACKTRACE_TOP(target_0);
  pt_print_backtrace(&target_0);

  PT_BACKTRACE(target_1, &target_0);
  pt_print_backtrace(&target_1);

  pt_assert_ok();
}

PT_TEST_LIST({test_print_all, "print all"})

PT_TEST_MAIN
