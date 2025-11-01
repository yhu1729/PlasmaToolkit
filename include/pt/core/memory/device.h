#pragma once

#include "pt/core/status.h"
#include <stdlib.h>

pt_status pt_free_d_impl(
  void* target, const char* function, const char* file, const int line);
pt_status pt_malloc_d_impl(
  void** target, const size_t size, const char* function, const char* file,
  const int line);
pt_status pt_calloc_d_impl(
  void** target, const size_t num, const size_t size, const char* function,
  const char* file, const int line);

#ifdef PT_USE_CUDA
#define pt_free_d(_target) \
  pt_free_d_impl((void*)(_target), __func__, __FILE__, __LINE__)
#define pt_malloc_d(_target, _size) \
  pt_malloc_d_impl((void**)(_target), (_size), __func__, __FILE__, __LINE__)
#define pt_calloc_d(_target, _num, _size) \
  pt_calloc_d_impl( \
    (void**)(_target), (_num), (_size), __func__, __FILE__, __LINE__)
#else
#define pt_free_d(...) pt_free_h(__VA_ARGS__)
#define pt_malloc_d(...) pt_malloc_h(__VA_ARGS__)
#define pt_calloc_d(...) pt_calloc_h(__VA_ARGS__)
#endif
