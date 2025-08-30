#pragma once

#include "pt/config.h"
#include "pt/foundation/macro.h"
#include "pt/foundation/tag.h"
#include <stdlib.h>

struct _pt_context_t {
  pt_tag type;
  size_t id;
};
typedef struct _pt_context_t* pt_context;

typedef pt_error (*_pt_context_set_id_t)(pt_context context, const size_t id);

struct _pt_context_interface_t {
  struct _pt_context_t context;
  _pt_context_set_id_t set_id;
};
typedef struct _pt_context_interface_t* pt_context_interface;

#define _PT_GET_CONTEXT_INTERFACE(c) \
  (pt_container_of((c), struct _pt_context_interface_t, context))

struct _pt_context_local_t {
  struct _pt_context_interface_t interface;
};

struct _pt_context_mpi_t {
  struct _pt_context_interface_t interface;
#ifdef PT_USE_MPI
  MPI_Comm communicator;
#endif
};

struct _pt_context_nccl_t {
  struct _pt_context_interface_t interface;
#ifdef PT_USE_NCCL
  ncclComm_t communicator;
#endif
};

pt_context pt_acquire_context_impl_local(void);
pt_error pt_acquire_context(pt_context target[1], pt_tag type);
pt_error pt_release_context(pt_context target);
pt_error pt_set_context_id(pt_context target, const size_t id);
