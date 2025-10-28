#pragma once

#include "pt/container/buffer/host.h"
#include "pt/core/status.h"

typedef pt_buffer_h* pt_vector_h;

typedef struct pt_vector_h_impl_t* pt_vector_h_impl;
struct pt_vector_h_impl_t {
  pt_buffer_h buffer;
  size_t stride;
  size_t length;
};

pt_status pt_acquire_vector_h_impl(
  pt_vector_h target[1], const size_t stride, const size_t length);
pt_status pt_release_vector_h(pt_vector_h target);

#define pt_acquire_vector_h(_target, _type, _length) \
  pt_acquire_vector_h_impl((_target), sizeof(_type), (_length))
