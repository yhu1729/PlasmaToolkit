#include "pt/core/status.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void
skip(int signal) {}

void
test_bad(void) {
  signal(SIGTERM, skip);

  pt_status target = {PT_TAG_UNKNOWN, NULL, NULL};
  pt_status status = pt_invoke(target, pt_abort, NULL);

  pt_check(status.code == PT_TAG_SUCCESS);
  pt_check(!status.callback);
  pt_check(!status.context);

  pt_check_ok();
}

PT_TEST_LIST({test_bad, "Check bad path"});

PT_TEST_UNIT_MAIN
