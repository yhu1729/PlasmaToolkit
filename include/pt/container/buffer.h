#pragma once

#include "pt/foundation/tag.h"
#include "pt/foundation/memory.h"

struct _pt_buffer_t {
  pt_memory_type type;
  size_t size;
  size_t alignment;
  char* content;
};
typedef struct _pt_buffer_t* pt_buffer;

pt_error pt_acquire_buffer(
  pt_buffer buffer[1], const size_t size, const size_t alignment);
pt_error pt_release_buffer(pt_buffer buffer);
pt_error pt_resize_buffer(pt_buffer buffer, const size_t size);
pt_error pt_copy_buffer(pt_buffer dst, const pt_buffer src);
pt_error pt_move_buffer(pt_buffer dst, pt_buffer src);
