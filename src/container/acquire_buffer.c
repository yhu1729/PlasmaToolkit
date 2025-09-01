#include "pt/container/buffer.h"

pt_error
pt_acquire_buffer(
  pt_buffer target[1], const size_t size, const size_t alignment) {
  *target = malloc(sizeof **target);
  pt_buffer buffer = *target;
  buffer->size = size;
  buffer->alignment = alignment;
  if (alignment) {
    pt_aligned_alloc(&(buffer->content), alignment, size);
  } else {
    pt_malloc(&(buffer->content), size);
  }

  return PT_TAG_SUCCESS;
}
