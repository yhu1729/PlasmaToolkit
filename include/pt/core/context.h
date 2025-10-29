#pragma once

#include "pt/config.h"
#include "pt/core/context/local.h"
#include "pt/core/context/mpi.h"
#include "pt/core/status.h"
#include "pt/core/tag.h"

#ifdef PT_USE_CUDA
#include "pt/core/context/nccl.h"
#endif

typedef struct _pt_context_interface_t pt_context_interface;
struct _pt_context_interface_t {
  pt_context_local local;
  pt_context_mpi mpi;

#ifdef PT_USE_CUDA
  pt_context_nccl nccl;
#endif
};

typedef struct _pt_context_t* pt_context;
struct _pt_context_t {
  pt_tag type;
  bool active;
  pt_context_interface interface;
};

pt_status pt_acquire_context(pt_context target[1], const pt_tag type);
pt_status pt_release_context(pt_context target);
pt_status pt_initialize_context(pt_context target, pt_context leader);
pt_status pt_finalize_context(pt_context target);
pt_status pt_initialize_context_interface(
  pt_context_interface interface, const pt_tag type, pt_context leader);
pt_status pt_finalize_context_interface(
  pt_context_interface interface, const pt_tag type);
