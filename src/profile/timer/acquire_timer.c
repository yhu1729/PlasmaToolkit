#include "pt/core/memory.h"
#include "pt/profile/timer.h"

pt_status
pt_acquire_timer(pt_timer target[1], const char* name) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc_h(target, sizeof **target));
  pt_timer handle = *target;
  handle->name = name;
  handle->active = false;

  return status;
}
