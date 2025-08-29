#include <stdlib.h>
#include "pt/foundation/error.h"

const char*
pt_get_error_message(const pt_error target) {
#define _PT_EXPAND_TO_CASE(tag, message) \
  case tag: \
    return message;

  switch (target) {
    _PT_ERROR_LIST(_PT_EXPAND_TO_CASE)
  default:
    return "Unknown error";
  }

#undef _PT_EXPAND_TO_CASE

  return NULL;
}
