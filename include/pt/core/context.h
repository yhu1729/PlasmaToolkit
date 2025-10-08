#pragma once

#include "pt/core/context/local.h"
#include "pt/core/context/mpi.h"
#include "pt/core/context/nccl.h"
#include "pt/core/status.h"
#include "pt/core/tag.h"

typedef struct _pt_context_t* pt_context;
struct _pt_context_t {
  pt_tag type;
};

pt_status pt_acquire_context(pt_context target[1], const pt_tag type);
pt_status pt_release_context(pt_context target);
