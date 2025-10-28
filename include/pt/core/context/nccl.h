#pragma once

#include "pt/config.h"
#include "pt/core/status.h"
#include "pt/core/type.h"

typedef struct _pt_context_mpi_t* pt_context_mpi;

typedef struct _pt_context_nccl_t* pt_context_nccl;
struct _pt_context_nccl_t {
  bool active;
  pt_index rank;
  pt_index size;
  ncclComm_t network;
};

pt_status pt_acquire_context_nccl(pt_context_nccl target[1]);
pt_status pt_release_context_nccl(pt_context_nccl target);
pt_status
pt_initialize_context_nccl(pt_context_nccl target, pt_context_mpi host);
pt_status pt_finalize_context_nccl(pt_context_nccl target);
