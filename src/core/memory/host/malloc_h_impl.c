#include "pt/core/log.h"
#include "pt/core/memory/host.h"

pt_status
pt_malloc_h_impl(
  void** target, const size_t size, const char* function, const char* file,
  const int line) {
  PT_STATUS(result);

  *target = malloc(size);
  if (!(*target)) {
    result.code = PT_TAG_OUT_OF_MEMORY;

    return result;
  }
  pt_emit_log_debug(
    "malloc %p+%zu in \"%s\" at %s:%d", *target, size, function, file, line);

  return result;
}
