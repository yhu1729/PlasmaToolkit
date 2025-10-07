#include "pt/core/backtrace.h"
#include <stdio.h>

void
pt_print_backtrace(pt_backtrace* target) {
  if (!target) {
    return;
  }

  printf(
    "Backtrace #%d in \"%s\" at %s:%d\n", target->depth, target->function,
    target->file, target->line);

  pt_print_backtrace(target->parent);
}
