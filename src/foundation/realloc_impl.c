#include "pt/foundation/io.h"
#include "pt/foundation/memory.h"
#include <stdlib.h>

pt_error
pt_realloc_impl(
  void** target, const size_t size, const char* file, const int line,
  const char* function) {
  *target = realloc(*target, size);
  pt_log_debug(
    "realloc: %s:%d  %s  %p+%zu\n", file, line, function, *target, size);

  return PT_TAG_SUCCESS;
}
