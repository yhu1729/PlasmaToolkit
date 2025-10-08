#include "pt/core/log.h"
#include "pt/core/status.h"

pt_status
pt_invoke_impl(
  const pt_status target, pt_status_callback_t callback, void* context,
  const char* function, const char* file, const int line) {

  if (callback) {
    pt_emit_log_debug("Callback in \"%s\" at %s:%d", function, file, line);
    return callback(target.code, context);
  }

  return target;
}
