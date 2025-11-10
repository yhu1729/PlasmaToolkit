#include "pt/profile/tracker.h"

pt_status
pt_stop_tracker(pt_tracker target) {
  return pt_stop_timer(target->timer);
}
