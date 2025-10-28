#pragma once

#include "pt/config.h"
#include "pt/core/status.h"
#include "pt/core/type.h"

typedef struct _pt_context_t* pt_context;

typedef struct _pt_context_mpi_t* pt_context_mpi;
struct _pt_context_mpi_t {
  bool active;
  pt_index rank;
  pt_index size;
  MPI_Comm network;
};

pt_status pt_acquire_context_mpi(pt_context_mpi target[1]);
pt_status pt_release_context_mpi(pt_context_mpi target);
pt_status pt_initialize_context_mpi(pt_context_mpi target, pt_context leader);
pt_status pt_finalize_context_mpi(pt_context_mpi target);
