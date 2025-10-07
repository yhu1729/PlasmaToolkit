#include "pt/core/info.h"
#include <stdio.h>

void
pt_print_info(pt_info* target) {
  if (!target) {
    return;
  }

  printf(
    "Backtrace #%d in \"%s\" at %s:%d\n", target->depth, target->function,
    target->file, target->line);

  pt_print_info(target->parent);
}
