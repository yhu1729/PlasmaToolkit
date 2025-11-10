#include "pt/core/memory.h"
#include "pt/profile/tracker.h"

pt_status
pt_acquire_tracker(
  pt_tracker target[1], const char* name, const int port_capacity) {
  PT_STATUS(status);

  pt_safe_invoke(pt_malloc_h(target, sizeof **target));
  pt_tracker handle = *target;
  handle->name = name;
  handle->active = false;
  pt_safe_invoke(pt_acquire_timer(&(handle->timer), name));

  pt_safe_invoke(
    pt_calloc_h(&(handle->port), port_capacity, sizeof(pt_tracker)));
  handle->port_capacity = port_capacity;
  handle->port_size = 0;

  for (int index = 0; index < handle->port_capacity; ++index) {
    handle->port[index] = NULL;
  }

  return status;
}
