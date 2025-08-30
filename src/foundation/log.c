#include "pt/config.h"
#include "pt/foundation/io.h"
#include <stdarg.h>
#include <stdio.h>

void
pt_log(const pt_verbosity level, const char* format, ...) {
  if ((int)level > PT_VERBOSITY) {
    return;
  }

  va_list arg;
  va_start(arg, format);
  vfprintf(stderr, format, arg);
  va_end(arg);
}
