#include "pt/container/buffer.h"
#include "pt/core/tag.h"

pt_status
pt_send_buffer(
  pt_buffer dst, pt_feature dst_feature, pt_buffer src, pt_feature src_feature,
  MPI_Request* request) {
  PT_STATUS(status);

  if (
    (src_feature == PT_FEATURE_ON_HOST) &&
    (dst_feature == PT_FEATURE_ON_HOST)) {
    status = pt_send_buffer_h2h(dst, src, request);
  } else if (
    (src_feature == PT_FEATURE_ON_HOST) &&
    (dst_feature == PT_FEATURE_ON_DEVICE)) {
    status = pt_send_buffer_h2d(dst, src, request);
  } else if (
    (src_feature == PT_FEATURE_ON_DEVICE) &&
    (dst_feature == PT_FEATURE_ON_HOST)) {
    status = pt_send_buffer_d2h(dst, src, request);
  } else if (
    (src_feature == PT_FEATURE_ON_DEVICE) &&
    (dst_feature == PT_FEATURE_ON_DEVICE)) {
    status = pt_send_buffer_d2d(dst, src, request);
  } else {
    status.code = PT_TAG_INVALID_PARAMETER;
  }

  return status;
}
