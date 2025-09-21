#include "pt/foundation/test.h"
#include <stdlib.h>

bool
pt_test_assert_equal_impl_int(
  const int lhs, const int rhs, const int tolerance, const char* file,
  const int line) {
  bool result = (abs(lhs - rhs) <= tolerance);
  if (result) {
    pt_log_error(
      "PASS: %s:%d  abs(%d - %d) <= %d.\n", file, line, lhs, rhs, tolerance);
  } else {
    pt_log_error(
      "FAIL: %s:%d  abs(%d - %d) > %d.\n", file, line, lhs, rhs, tolerance);
  }

  return result;
}
