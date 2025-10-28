#pragma once

#include "pt/core/status.h"
#include "pt/core/type.h"
#include "pt/profile/timer.h"

typedef struct pt_tracker_t* pt_tracker;
struct pt_tracker_t {
  const char* name;
  bool active;
  pt_timer timer;
  pt_tracker* port;
  pt_i32 port_capacity;
  pt_i32 port_size;
};

pt_status pt_acquire_tracker(
  pt_tracker target[1], const char* name, const int port_capacity);
pt_status pt_release_tracker(pt_tracker target);
pt_status pt_start_tracker(pt_tracker target);
pt_status pt_stop_tracker(pt_tracker target);
pt_status pt_attach_tracker_port(
  pt_tracker target, const char* port_name, const int port_capacity);
pt_status
pt_get_tracker_port(pt_tracker port[1], pt_tracker target, const char* name);
