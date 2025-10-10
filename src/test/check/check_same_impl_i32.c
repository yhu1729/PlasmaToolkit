#include "pt/core/log.h"
#include "pt/test/check.h"

bool
pt_check_same_impl_i32(
  const pt_i32 lhs, const pt_i32 rhs, const char* file, const int line) {
  bool result = (lhs == rhs);

  const char* feedback;
  if (result) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (result) {
    pt_emit_log_debug("%s: %s:%d  %d == %d", feedback, file, line, lhs, rhs);
  } else {
    pt_emit_log_debug("%s: %s:%d  %d != %d", feedback, file, line, lhs, rhs);
  }

  return result;
}
