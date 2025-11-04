#include "pt/core/log.h"
#include "pt/core/memory/host.h"
#include <string.h>

pt_status
pt_memcpy_h_impl(
  void* dst, void* src, const size_t size, const char* function,
  const char* file, const int line) {
  PT_STATUS(status);

  memcpy(dst, src, size);
  pt_emit_log_debug(
    "memcpy %p+%zu to %p in \"%s\" at %s:%d", src, size, dst, function, file,
    line);

  return status;
}
