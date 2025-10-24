#include "pt/core/macro.h"
#include "pt/profile/tracker.h"

pt_status
pt_stop_tracker(pt_tracker target) {
  return pt_stop(target->timer);
}
