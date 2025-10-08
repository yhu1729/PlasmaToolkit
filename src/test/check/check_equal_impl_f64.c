#include "pt/core/log.h"
#include "pt/test/check.h"
#include <math.h>

bool
pt_check_equal_impl_f64(
  const pt_f64 lhs, const pt_f64 rhs, const pt_f64 tolerance, const char* file,
  const int line) {
  bool result = (fabs(lhs - rhs) <= tolerance);

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
