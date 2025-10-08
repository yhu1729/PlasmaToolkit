#include "pt/core/status.h"

const char*
pt_get_status_name(const pt_status target) {
  if (target.code == PT_TAG_SUCCESS) {
  } else if (
    (target.code > PT_TAG_ERROR_MIN) && (target.code < PT_TAG_ERROR_MAX)) {
  } else {
    return pt_get_tag_name(PT_TAG_UNKNOWN);
  }

  return pt_get_tag_name(target.code);
}
