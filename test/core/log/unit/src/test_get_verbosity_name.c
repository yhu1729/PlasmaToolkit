#include "pt/core/log.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"
#include <string.h>

void
test_all(void) {
  pt_check(!strcmp(
    pt_get_verbosity_name(PT_TAG_VERBOSITY_NONE),
    pt_get_tag_name(PT_TAG_VERBOSITY_NONE)));
  pt_check(!strcmp(
    pt_get_verbosity_name(PT_TAG_VERBOSITY_ERROR),
    pt_get_tag_name(PT_TAG_VERBOSITY_ERROR)));
  pt_check(!strcmp(
    pt_get_verbosity_name(PT_TAG_VERBOSITY_WARNING),
    pt_get_tag_name(PT_TAG_VERBOSITY_WARNING)));
  pt_check(!strcmp(
    pt_get_verbosity_name(PT_TAG_VERBOSITY_INFO),
    pt_get_tag_name(PT_TAG_VERBOSITY_INFO)));
  pt_check(!strcmp(
    pt_get_verbosity_name(PT_TAG_VERBOSITY_DEBUG),
    pt_get_tag_name(PT_TAG_VERBOSITY_DEBUG)));

  pt_check_ok();
}

PT_TEST_LIST({test_all, "check all verbosity names"});

PT_TEST_UNIT_MAIN
