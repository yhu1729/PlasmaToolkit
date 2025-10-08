#include "pt/core/log.h"
#include "pt/core/memory/host.h"

pt_status
pt_free_h_impl(
  void* target, const char* function, const char* file, const int line) {
  PT_STATUS(status);

  free(target);
  pt_emit_log_debug(
    "free %p in \"%s\" at %s:%d", target, function, file, line);

  return status;
}
