#include "pt/container/vector/host.h"
#include "pt/core/macro.h"

pt_status
pt_release_vector_h(pt_vector_h target) {
  PT_STATUS(status);

  pt_vector_h_impl tmp =
    pt_container_of(target, struct pt_vector_h_impl_t, head);
  free(*target);
  free(tmp);

  return status;
}
