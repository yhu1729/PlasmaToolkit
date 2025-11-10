#include "pt/core/memory.h"
#include "pt/profile/tracker.h"

pt_status
pt_release_tracker(pt_tracker target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_release_timer(target->timer));

  for (int index = 0; index < target->port_size; ++index) {
    pt_safe_invoke(pt_release_tracker(target->port[index]));
  }
  pt_safe_invoke(pt_free_h(target->port));

  pt_safe_invoke(pt_free_h(target));

  return status;
}
