#include "pt/core/status.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void
test_good(void) {
  pt_status target = {PT_TAG_SUCCESS, NULL, NULL};
  pt_status result = pt_invoke(target, pt_abort, NULL);

  pt_check(result.code == PT_TAG_SUCCESS);
  pt_check(!result.callback);
  pt_check(!result.context);

  pt_check_ok();
}

PT_TEST_LIST({test_good, "check good path"});

PT_TEST_UNIT_MAIN
