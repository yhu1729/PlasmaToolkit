#include "pt/core/log.h"
#include "pt/test/check.h"

bool
pt_check_impl(
  const bool result, const char* file, const int line, const char* expr) {
  const char* feedback;
  if (result) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (!result) {
    const char* message = "Invalid result";
    pt_emit_log_debug(
      "%s: %s:%d  %s  \"%s\"", feedback, file, line, expr, message);
  } else {
    pt_emit_log_debug("%s: %s:%d  %s", feedback, file, line, expr);
  }

  return result;
}
