#include "pt/core/log.h"
#include "pt/test/check.h"
#include <math.h>

bool
pt_check_equal_impl_f32(
  const pt_f32 lhs, const pt_f32 rhs, const pt_f32 tolerance, const char* file,
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
      "%s: %s:%d  abs(%.6E - %.6E) <= %.6E", feedback, file, line, lhs, rhs,
      tolerance);
  } else {
    pt_emit_log_debug(
      "%s: %s:%d  abs(%.6E - %.6E) > %.6E", feedback, file, line, lhs, rhs,
      tolerance);
  }

  return result;
}
