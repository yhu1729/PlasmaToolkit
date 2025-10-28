#pragma once

#include "pt/container/vector/device.h"
#include "pt/container/vector/host.h"

typedef struct pt_vector_t* pt_vector;
struct pt_vector_t {
  pt_vector_h host;
  bool on_host;
  bool on_device;
};

pt_status pt_acquire_vector_impl(
  pt_vector target[1], const size_t stride, const size_t length,
  const bool on_host, const bool on_device);
pt_status pt_release_vector(pt_vector target);

#define pt_acquire_vector(_target, _type, _length, _on_host, _on_device) \
  pt_acquire_vector_impl( \
    (_target), sizeof(_type), (_length), (_on_host), (_on_device))
