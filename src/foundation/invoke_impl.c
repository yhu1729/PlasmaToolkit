#include "pt/foundation/error.h"

pt_error
pt_invoke_impl(
  const pt_error result, const char* file, const int line, const char* expr) {
  if (result) {
    const char* message = pt_get_error_message(result);
    pt_log_error(
      "Location: %s:%d\nLine: %s\nMessage: %s.\n", file, line, expr, message);
  }

  return result;
}
