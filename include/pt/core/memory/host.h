#pragma once

#include "pt/core/status.h"
#include <stdlib.h>

pt_status pt_free_h_impl(
  void* target, const char* function, const char* file, const int line);
pt_status pt_malloc_h_impl(
  void** target, const size_t size, const char* function, const char* file,
  const int line);
pt_status pt_calloc_h_impl(
  void** target, const size_t num, const size_t size, const char* function,
  const char* file, const int line);
pt_status pt_memcpy_h_impl(
  void* dst, void* src, const size_t size, const char* function,
  const char* file, const int line);

#define pt_free_h(_target) \
  pt_free_h_impl((void*)(_target), __func__, __FILE__, __LINE__)
#define pt_malloc_h(_target, _size) \
  pt_malloc_h_impl((void**)(_target), (_size), __func__, __FILE__, __LINE__)
#define pt_calloc_h(_target, _num, _size) \
  pt_calloc_h_impl( \
    (void**)(_target), (_num), (_size), __func__, __FILE__, __LINE__)
#define pt_memcpy_h(_dst, _src, _size) \
  pt_memcpy_h_impl( \
    (void*)(_dst), (void*)(_src), (_size), __func__, __FILE__, __LINE__)
