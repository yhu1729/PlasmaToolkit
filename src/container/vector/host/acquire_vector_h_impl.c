#include "pt/container/vector/host.h"
#include "pt/core/memory.h"

pt_status
pt_acquire_vector_h_impl(
  pt_vector_h target[1], const size_t stride, const size_t length) {
  PT_STATUS(status);

  pt_vector_h_impl handle;
  pt_safe_invoke(pt_malloc_h(&handle, sizeof *handle));
  pt_safe_invoke(pt_acquire_buffer_h(&(handle->buffer), stride * length));
  handle->stride = stride;
  handle->length = length;

  *target = &(handle->buffer);

  return status;
}
