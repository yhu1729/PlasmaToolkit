#include "pt/container/buffer.h"
#include "pt/core/memory.h"
#include "pt/core/tag.h"

pt_status
pt_send_buffer_h2h(pt_buffer dst, pt_buffer src, MPI_Request* request) {
  PT_STATUS(status);

  if (!((src->feature & PT_FEATURE_ON_HOST) &&
        (dst->feature & PT_FEATURE_ON_HOST))) {
    status.code = PT_TAG_INVALID_PARAMETER;

    return status;
  }

  if (!(src->host->length == dst->host->length)) {
    status.code = PT_TAG_INVALID_PARAMETER;

    return status;
  }

  if (
    (src->context->interface.local->active) &&
    (dst->context->interface.local->active)) {
    return pt_memcpy_h(
      dst->host->content, src->host->content, src->host->length);
  }

  if (!((src->context->interface.mpi->active) &&
        (dst->context->interface.mpi->active))) {
    status.code = PT_TAG_INVALID_PARAMETER;

    return status;
  }

  if (src->context->interface.mpi->rank == dst->context->interface.mpi->rank) {
    return pt_memcpy_h(
      dst->host->content, src->host->content, src->host->length);
  }

  if (!(src->context->interface.mpi->network ==
        dst->context->interface.mpi->network)) {
    status.code = PT_TAG_INVALID_PARAMETER;

    return status;
  }

  int mpi_rank;
  MPI_Comm network = src->context->interface.mpi->network;
  MPI_Comm_rank(network, &mpi_rank);
  if (mpi_rank == src->context->interface.mpi->rank) {
    MPI_Isend(
      src->host->content, src->host->length, MPI_CHAR,
      dst->context->interface.mpi->rank, 0, network, request);
  } else {
    MPI_Irecv(
      dst->host->content, dst->host->length, MPI_CHAR,
      src->context->interface.mpi->rank, MPI_ANY_TAG, network, request);
  }

  return status;
}
