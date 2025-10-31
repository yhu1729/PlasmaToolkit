#include "pt/core/memory.h"
#include "pt/profile/timer.h"

pt_status
pt_release_timer(pt_timer target) {
  PT_STATUS(status);

  pt_safe_invoke(pt_free_h(target));

  return status;
}
