#include "pt/foundation/test.h"
#include <math.h>

bool
pt_test_assert_equal_impl_double(
  const double lhs, const double rhs, const double tolerance, const char* file,
  const int line) {
  bool result = (fabs(lhs - rhs) <= tolerance);
  if (!result) {
    pt_log_error(
      "FAIL: %s:%d  abs(%.6E - %.6E) <= %f.\n", file, line, lhs, rhs,
      tolerance);
  } else {
    pt_log_error(
      "PASS: %s:%d  abs(%.6E - %.6E) > %f.\n", file, line, lhs, rhs,
      tolerance);
  }

  return result;
}
