#include "pt/container/buffer.h"

pt_error
pt_fetch_buffer_element_impl(
  pt_buffer target, const size_t offset, void** element) {
  *((char**)element) = (char*)(target->content) + offset;

  return PT_TAG_SUCCESS;
}
