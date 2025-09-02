#pragma once

#include "pt/foundation/tag.h"
#include <stdlib.h>

pt_error pt_free_impl(
  void* target, const char* file, const int line, const char* function);
#define pt_free(_target) \
  pt_free_impl((void*)(_target), __FILE__, __LINE__, __func__)

pt_error pt_malloc_impl(
  void** target, const size_t size, const char* file, const int line,
  const char* function);
#define pt_malloc(_target, _size) \
  pt_malloc_impl((void**)(_target), (_size), __FILE__, __LINE__, __func__)

pt_error pt_calloc_impl(
  void** target, const size_t n, const size_t size, const char* file,
  const int line, const char* function);
#define pt_calloc(_target, _n, _size) \
  pt_calloc_impl( \
    (void**)(_target), (_n), (_size), __FILE__, __LINE__, __func__)

pt_error pt_realloc_impl(
  void** target, const size_t size, const char* file, const int line,
  const char* function);
#define pt_realloc(_target, _size) \
  pt_realloc_impl((void**)(_target), (_size), __FILE__, __LINE__, __func__)

pt_error pt_aligned_alloc_impl(
  void** target, const size_t alignment, const size_t size, const char* file,
  const int line, const char* function);
#define pt_aligned_alloc(_target, _alignment, _size) \
  pt_aligned_alloc_impl( \
    (void**)(_target), (_alignment), (_size), __FILE__, __LINE__, __func__)

pt_error pt_aligned_realloc_impl(
  void** target, void* input, const size_t alignment, const size_t size,
  const size_t size_prev, const char* file, const int line,
  const char* function);
#define pt_aligned_realloc(_target, _input, _alignment, _size, _size_prev) \
  pt_aligned_realloc_impl( \
    (void**)(_target), (void*)(_input), (_alignment), (_size), (_size_prev), \
    __FILE__, __LINE__, __func__)

const char* pt_get_memory_type_name(const pt_memory_type target);
