#include "pt/algorithm/range.h"

pt_error
pt_find_index(
  pt_i64* target, size_t offset, const int dimension, const size_t* stride) {
  if (stride[0] < stride[dimension - 1]) {
    for (int d = 0; d < dimension; ++d) {
      target[d] =
        (offset % (((d + 1) < dimension) ? stride[d + 1] : (offset + 1))) /
        stride[d];
      offset -= target[d] * stride[d];
    }
  } else {
    for (int d = dimension - 1; d >= 0; --d) {
      target[d] =
        (offset % ((d > 0) ? stride[d - 1] : (offset + 1))) / stride[d];
      offset -= target[d] * stride[d];
    }
  }

  return PT_TAG_SUCCESS;
}
