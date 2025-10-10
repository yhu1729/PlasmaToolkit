#include "pt/core/log.h"
#include "pt/test/check.h"
#include <string.h>

bool
pt_check_same_impl_char_pointer(
  const char* lhs, const char* rhs, const char* file, const int line) {
  bool result = !strcmp(lhs, rhs);

  const char* feedback;
  if (result) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (result) {
    pt_emit_log_debug("%s: %s:%d  %s == %s", feedback, file, line, lhs, rhs);
  } else {
    pt_emit_log_debug("%s: %s:%d  %s != %s", feedback, file, line, lhs, rhs);
  }

  return result;
}
