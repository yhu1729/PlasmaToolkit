#include "pt/foundation/test.h"

bool
pt_test_invoke_impl(
  const pt_error result, const pt_error target, const char* file,
  const int line, const char* expr) {
  const char* feedback;
  if (result == target) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (result != target) {
    const char* message = pt_get_error_message(result);
    pt_log_error("%s: %s:%d  %s\n%s.\n", feedback, file, line, expr, message);
  } else {
    pt_log_debug("%s: %s:%d  %s\n", feedback, file, line, expr);
  }

  return (result == target);
}
