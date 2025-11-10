#pragma once

#include "pt/container/buffer/device.h"
#include "pt/container/buffer/host.h"
#include "pt/core/context.h"
#include "pt/core/status.h"
#include "pt/core/type.h"

typedef struct pt_buffer_t* pt_buffer;
struct pt_buffer_t {
  pt_context context;
  pt_feature feature;
  pt_buffer_h host;
  pt_buffer_d device;
};

pt_status pt_acquire_buffer(
  pt_buffer target[1], pt_context context, pt_feature feature,
  const size_t length);
pt_status pt_release_buffer(pt_buffer target);
pt_status pt_send_buffer(
  pt_buffer dst, pt_feature dst_feature, pt_buffer src, pt_feature src_feature,
  MPI_Request* request);
pt_status
pt_send_buffer_h2h(pt_buffer dst, pt_buffer src, MPI_Request* request);
pt_status
pt_send_buffer_h2d(pt_buffer dst, pt_buffer src, MPI_Request* request);
pt_status
pt_send_buffer_d2h(pt_buffer dst, pt_buffer src, MPI_Request* request);
pt_status
pt_send_buffer_d2d(pt_buffer dst, pt_buffer src, MPI_Request* request);
