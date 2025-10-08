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
#ifdef PT_USE_MPI
  int active = 0;
  MPI_Initialized(&active);
  if (active) {
    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    fprintf(stderr, "[PT.%s:%d] ", name, rank);
  } else {
    fprintf(stderr, "[PT.%s] ", name);
  }
#else
  fprintf(stderr, "[PT.%s] ", name);
#endif

  va_list arg;
  va_start(arg, format);
  vfprintf(stderr, format, arg);
  va_end(arg);

  fprintf(stderr, "\n");
}
