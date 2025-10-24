#include "pt/profile/tracker.h"
#include <string.h>

pt_status
pt_get_tracker_port(pt_tracker port[1], pt_tracker target, const char* name) {
  PT_STATUS(status);

  for (int index = 0; index < target->port_size; ++index) {
    if (!strcmp(target->port[index]->name, name)) {
      *port = target->port[index];

      return status;
    }
  }

  status.code = PT_TAG_INVALID_PARAMETER;

  return status;
}
