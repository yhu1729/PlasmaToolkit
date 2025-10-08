#include "pt/config.h"
#include "pt/core/log.h"
#include <stdarg.h>
#include <stdio.h>

void
pt_emit_log(const pt_tag level, const char* format, ...) {
  if ((int)level <= (int)PT_TAG_VERBOSITY_NONE) {
    return;
  }
  if ((int)level > (int)PT_TAG_VERBOSITY_DEBUG) {
    return;
  }
  if (((int)level - (int)PT_TAG_VERBOSITY_NONE) > PT_VERBOSITY) {
    return;
  }

  const char* name = pt_get_verbosity_name(level);
  fprintf(stderr, "[PT.%s] ", name);

  va_list arg;
  va_start(arg, format);
  vfprintf(stderr, format, arg);
  va_end(arg);

  fprintf(stderr, "\n");
}
