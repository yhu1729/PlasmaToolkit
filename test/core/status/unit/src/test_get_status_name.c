#include "pt/core/status.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"
#include <string.h>

void
test_all(void) {
  pt_status target = {PT_TAG_SUCCESS, NULL, NULL};
  pt_check_same(pt_get_status_name(target), pt_get_tag_name(target.code));
  for (int code = PT_TAG_ERROR_MIN + 1; code < PT_TAG_ERROR_MAX; ++code) {
    target.code = code;
    pt_check_same(pt_get_status_name(target), pt_get_tag_name(code));
  }

  pt_check_ok();
}

PT_TEST_LIST({test_all, "Check all status names"});

PT_TEST_UNIT_MAIN
