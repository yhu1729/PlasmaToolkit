#include "pt/core/tag.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void
test_all(void) {

#define _PT_EXPAND(_tag, _message, _value) \
  do { \
    int r = strcmp(pt_get_tag_name((_tag)), (_message)); \
    pt_check(!r); \
  } while (0);

#undef _PT_EXPAND

  pt_check_ok();
}

PT_TEST_LIST({test_all, "check all tag names"});

PT_TEST_UNIT_MAIN
