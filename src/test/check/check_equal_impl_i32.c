#include "pt/core/log.h"
#include "pt/test/check.h"
#include <stdlib.h>

bool
pt_check_equal_impl_i32(
  const pt_i32 lhs, const pt_i32 rhs, const pt_i32 tolerance, const char* file,
  const int line) {
  bool result = (abs(lhs - rhs) <= tolerance);

  const char* feedback;
  if (result) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (result) {
    pt_emit_log_debug(
      "%s: %s:%d  abs(%d - %d) <= %d", feedback, file, line, lhs, rhs,
      tolerance);
  } else {
    pt_emit_log_debug(
      "%s: %s:%d  abs(%d - %d) > %d", feedback, file, line, lhs, rhs,
      tolerance);
  }

  return result;
}
