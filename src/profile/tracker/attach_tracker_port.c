#include "pt/core/memory.h"
#include "pt/profile/tracker.h"

pt_status
pt_attach_tracker_port(
  pt_tracker target, const char* port_name, const int port_capacity) {
  PT_STATUS(status);

  if (target->port_capacity) {
    if (target->port_size == target->port_capacity) {
      target->port_capacity += 4;
      pt_tracker* buffer_port;
      pt_safe_invoke(
        pt_calloc_h(&buffer_port, target->port_capacity, sizeof(pt_tracker)));

      for (int index = 0; index < target->port_capacity; ++index) {
        buffer_port[index] = target->port[index];
      }

      pt_safe_invoke(pt_free_h(target->port));
      target->port = buffer_port;

      status = pt_attach_tracker_port(target, port_name, port_capacity);
    } else {
      pt_tracker port;
      pt_safe_invoke(pt_acquire_tracker(&port, port_name, port_capacity));
      target->port[target->port_size] = port;
      target->port_size += 1;
    }
  } else {
    target->port_capacity = 4;
    target->port_size = 0;
    pt_safe_invoke(
      pt_calloc_h(&(target->port), target->port_capacity, sizeof(pt_tracker)));

    status = pt_attach_tracker_port(target, port_name, port_capacity);
  }

  return status;
}
