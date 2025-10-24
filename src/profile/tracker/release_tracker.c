#include "pt/core/macro.h"
#include "pt/core/memory.h"
#include "pt/profile/tracker.h"

pt_status
pt_release_tracker(pt_tracker target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_release(target->timer));

  for (int index = 0; index < target->port_size; ++index) {
    pt_safe_invoke(pt_release(target->port[index]));
  }

  pt_safe_invoke(pt_free(target));

  return status;
}
