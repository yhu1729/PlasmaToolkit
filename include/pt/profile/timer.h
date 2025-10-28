#pragma once

#include "pt/core/status.h"
#include "pt/core/type.h"
#include <sys/time.h>

typedef struct pt_timer_t* pt_timer;
struct pt_timer_t {
  const char* name;
  bool active;
  struct timeval start;
  struct timeval stop;
};

pt_status pt_acquire_timer(pt_timer target[1], const char* name);
pt_status pt_release_timer(pt_timer target);
pt_status pt_start_timer(pt_timer target);
pt_status pt_stop_timer(pt_timer target);
