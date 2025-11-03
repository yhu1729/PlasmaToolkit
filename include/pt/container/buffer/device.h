#pragma once

#include "pt/core/status.h"

typedef struct pt_buffer_d_t* pt_buffer_d;
struct pt_buffer_d_t {
  char* content;
  size_t length;
};

pt_status pt_acquire_buffer_d(pt_buffer_d target[1], const size_t length);
pt_status pt_release_buffer_d(pt_buffer_d target);
