#include "pt/core/macro.h"
#include "pt/profile/tracker.h"

pt_status
pt_start_tracker(pt_tracker target) {
  return pt_start(target->timer);
}
