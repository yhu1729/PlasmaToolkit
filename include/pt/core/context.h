#pragma once

#include "pt/core/context/local.h"
#include "pt/core/context/mpi.h"
#include "pt/core/context/nccl.h"
#include "pt/core/status.h"
#include "pt/core/tag.h"

typedef union _pt_context_api_t pt_context_api;
union _pt_context_api_t {
  pt_context_local local;
} __attribute__((transparent_union));

typedef struct _pt_context_t* pt_context;
struct _pt_context_t {
  pt_tag type;
  bool active;
  pt_context_api api;
};

pt_status pt_acquire_context(pt_context target[1], const pt_tag type);
pt_status pt_release_context(pt_context target);
pt_status pt_initialize_context(pt_context target);
pt_status pt_finalize_context(pt_context target);
pt_status pt_initialize_context_api(pt_context_api api, const pt_tag type);
pt_status pt_finalize_context_api(pt_context_api api, const pt_tag type);
