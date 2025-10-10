#include "pt/core/log.h"
#include "pt/core/memory/host.h"

pt_status
pt_calloc_h_impl(
  void** target, const size_t num, const size_t size, const char* function,
  const char* file, const int line) {
  PT_STATUS(status);

  *target = calloc(num, size);
  if (!(*target)) {
    status.code = PT_TAG_OUT_OF_MEMORY;

    return status;
  }
  pt_emit_log_debug(
    "calloc %p+%zu in \"%s\" at %s:%d", *target, num * size, function, file,
    line);

  return status;
}
