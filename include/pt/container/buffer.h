#pragma once

#include "pt/foundation/memory.h"
#include "pt/foundation/tag.h"

struct _pt_buffer_t {
  pt_memory_type type;
  size_t size;
  size_t alignment;
  void* content;
};
typedef struct _pt_buffer_t* pt_buffer;

pt_error pt_acquire_buffer(
  pt_buffer target[1], const size_t size, const size_t alignment);
pt_error pt_release_buffer(pt_buffer target);
pt_error pt_resize_buffer(pt_buffer target, const size_t size);
pt_error pt_copy_buffer(pt_buffer dst, const pt_buffer src);
pt_error pt_move_buffer(pt_buffer dst, pt_buffer src);
pt_error
pt_fetch_buffer_element(pt_buffer target, const size_t offset, void** element);
