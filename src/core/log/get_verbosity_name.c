#include "pt/core/log.h"

const char*
pt_get_verbosity_name(const pt_tag target) {
  switch (target) {
  case (PT_TAG_VERBOSITY_NONE):
  case (PT_TAG_VERBOSITY_ERROR):
  case (PT_TAG_VERBOSITY_WARNING):
  case (PT_TAG_VERBOSITY_INFO):
  case (PT_TAG_VERBOSITY_DEBUG):
    return pt_get_tag_name(target);
  default:
    return pt_get_tag_name(PT_TAG_UNKNOWN);
  }
}
