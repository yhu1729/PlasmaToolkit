#include "pt/core/log.h"
#include "pt/profile/timer.h"

pt_status
pt_stop_timer(pt_timer target) {
  PT_STATUS(status);

  if (!(target->active)) {
    pt_emit_log_warning("Timer is not started");
  }

  gettimeofday(&(target->stop), NULL);
  target->active = false;

  return status;
}
