#include "pt/core/backtrace.h"
#include "pt/core/log.h"

void
pt_print_backtrace(pt_backtrace* target) {
  if (!target) {
    return;
  }

  pt_emit_log_error(
    "Backtrace #%d in \"%s\" at %s:%d", target->depth, target->function,
    target->file, target->line);

  pt_print_backtrace(target->parent);
}
