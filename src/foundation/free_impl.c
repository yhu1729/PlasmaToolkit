#include "pt/foundation/io.h"
#include "pt/foundation/memory.h"
#include <stdlib.h>

pt_error
pt_free_impl(
  void* target, const char* file, const int line, const char* function) {
  pt_log_debug("free: %s:%d  %s  %p\n", file, line, function, target);
  free(target);

  return PT_TAG_SUCCESS;
}
