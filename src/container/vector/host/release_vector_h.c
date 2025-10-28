#include "pt/container/vector/host.h"
#include "pt/core/macro.h"
#include "pt/core/memory.h"

pt_status
pt_release_vector_h(pt_vector_h target) {
  PT_STATUS(status);

  pt_vector_h_impl handle =
    pt_container_of(target, struct pt_vector_h_impl_t, buffer);
  pt_safe_invoke(pt_release(*target));
  pt_safe_invoke(pt_free(handle));

  return status;
}
