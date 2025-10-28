#include "pt/container/vector/host.h"

pt_status
pt_acquire_vector_h_impl(
  pt_vector_h target[1], const size_t stride, const size_t length) {
  PT_STATUS(status);

  pt_vector_h_impl tmp = malloc(sizeof(*tmp));
  tmp->head = malloc(stride * length);
  tmp->stride = stride;
  tmp->length = length;
  *target = (char**)&(tmp->head);

  return status;
}
