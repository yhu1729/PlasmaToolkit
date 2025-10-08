#pragma once

#include "pt/core/status.h"
#include "pt/core/type.h"
#include <stdbool.h>

typedef struct _pt_context_local_t pt_context_local;
struct _pt_context_local_t {
  bool active;
  pt_index rank;
  pt_index size;
};

pt_status pt_acquire_context_local(pt_context_local target[1]);
pt_status pt_release_context_local(pt_context_local target[1]);
pt_status pt_initialize_context_local(pt_context_local target[1]);
pt_status pt_finalize_context_local(pt_context_local target[1]);
