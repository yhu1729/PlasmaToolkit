#include "pt/container/buffer.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"

pt_error
pt_acquire_buffer(
  pt_buffer target[1], const size_t size, const size_t alignment) {
  pt_invoke(pt_malloc(target, sizeof **target));
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
