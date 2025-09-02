#include "pt/container/buffer.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"

pt_error
pt_release_buffer(pt_buffer target) {
  pt_invoke(pt_free(target->content));
  pt_invoke(pt_free(target));

  return PT_TAG_SUCCESS;
}
