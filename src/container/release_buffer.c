#include "pt/container/buffer.h"

pt_error
pt_release_buffer(pt_buffer target) {
  free(target->content);
  free(target);

  return PT_TAG_SUCCESS;
}
