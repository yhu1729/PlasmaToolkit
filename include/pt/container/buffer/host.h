#pragma once

#include "pt/core/memory/host.h"
#include "pt/core/status.h"

struct pt_buffer_h_t {
  char* content;
  size_t length;
};
typedef struct pt_buffer_h_t* pt_buffer_h;

pt_status pt_acquire_buffer_h(pt_buffer_h target[1], const size_t length);
pt_status pt_release_buffer_h(pt_buffer_h target);
