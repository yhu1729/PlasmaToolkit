#include "pt/core/version.h"
#include "pt/test/assert.h"
#include "pt/test/unit.h"

void
test_print_full(void) {
  pt_print_version(true);

  pt_assert_ok();
}

PT_TEST_LIST({test_print_full, "print full version"});

PT_TEST_UNIT_MAIN
