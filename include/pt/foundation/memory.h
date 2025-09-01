#pragma once

#include "pt/foundation/tag.h"
#include <stdlib.h>

pt_error pt_free_impl(
  void* target, const char* file, const int line, const char* function);
#define pt_free(target) pt_free_impl((target), __FILE__, __LINE__, __func__)

pt_error pt_malloc_impl(
  void** target, const size_t size, const char* file, const int line,
  const char* function);
#define pt_malloc(target, size) \
  pt_malloc_impl((target), (size), __FILE__, __LINE__, __func__)

pt_error pt_calloc_impl(
  void** target, const size_t n, const size_t size, const char* file,
  const int line, const char* function);
#define pt_calloc(target, n, size) \
  pt_calloc_impl((target), (n), (size), __FILE__, __LINE__, __func__)

pt_error pt_realloc_impl(
  void** target, const size_t size, const char* file, const int line,
  const char* function);
#define pt_realloc(target, size) \
  pt_realloc_impl((target), (size), __FILE__, __LINE__, __func__)

pt_error pt_aligned_alloc_impl(
  void** target, const size_t alignment, const size_t size, const char* file,
  const int line, const char* function);
#define pt_aligned_alloc(target, alignment, size) \
  pt_aligned_alloc_impl( \
    (target), (alignment), (size), __FILE__, __LINE__, __func__)

pt_error pt_aligned_realloc_impl(
  void** target, void* input, const size_t alignment, const size_t size,
  const size_t size_prev, const char* file, const int line,
  const char* function);
#define pt_aligned_realloc(target, input, alignment, size, size_prev) \
  pt_aligned_realloc_impl( \
    (target), (input), (alignment), (size), (size_prev), __FILE__, __LINE__, \
    __func__)

const char* pt_get_memory_type_name(const pt_memory_type target);
