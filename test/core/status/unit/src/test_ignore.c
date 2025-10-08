#include "pt/core/status.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void
test_good(void) {
  pt_status target = {PT_TAG_SUCCESS, NULL, NULL};
  pt_status result = pt_invoke(target, pt_ignore, NULL);

  pt_check(result.code == PT_TAG_SUCCESS);
  pt_check(!result.callback);
  pt_check(!result.context);

  pt_check_ok();
}

void
test_bad(void) {
  pt_status target = {PT_TAG_UNKNOWN, NULL, NULL};
  pt_status result = pt_invoke(target, pt_ignore, NULL);

  pt_check(result.code == PT_TAG_SUCCESS);
  pt_check(!result.callback);
  pt_check(!result.context);

  pt_check_ok();
}

PT_TEST_LIST({test_good, "check good path"}, {test_bad, "check bad path"});

PT_TEST_UNIT_MAIN
