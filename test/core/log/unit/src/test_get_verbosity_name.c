#include "pt/core/log.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"
#include <string.h>

void
test_all(void) {
  for (int target = PT_TAG_VERBOSITY_NONE; target <= PT_TAG_VERBOSITY_DEBUG;
       ++target) {
    pt_check_same(
      pt_get_verbosity_name((pt_tag)target), pt_get_tag_name((pt_tag)target));
  }

  pt_check_ok();
}

PT_TEST_LIST({test_all, "Check all verbosity names"});

PT_TEST_UNIT_MAIN
