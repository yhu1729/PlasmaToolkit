#include "pt/core/log.h"
#include "pt/profile/timer.h"

pt_status
pt_start_timer(pt_timer target) {
  PT_STATUS(status);

  if (target->active) {
    pt_emit_log_warning("Timer restart");
  }

  gettimeofday(&(target->start), NULL);
  target->active = true;

  return status;
}
