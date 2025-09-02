#include "pt/algorithm/range.h"
#include "pt/foundation/error.h"
#include "pt/foundation/macro.h"
#include "pt/foundation/memory.h"

pt_error
pt_acquire_range(
  pt_range target[1], const pt_tag style, const int dimension,
  const long long* lower, const long long* upper) {
  pt_invoke(pt_malloc(target, sizeof **target));

  pt_range pointer = *target;
  pointer->style = style;
  pointer->dimension = dimension;

  pt_invoke(pt_calloc(&(pointer->lower), dimension, sizeof(long long)));
  pt_invoke(pt_calloc(&(pointer->upper), dimension, sizeof(long long)));
  pt_invoke(pt_calloc(&(pointer->extent), dimension, sizeof(long long)));
  pt_invoke(pt_calloc(&(pointer->stride), dimension, sizeof(long long)));
  for (int d = 0; d < dimension; ++d) {
    pointer->lower[d] = lower[d];
    pointer->upper[d] = upper[d];
    pointer->extent[d] = upper[d] - lower[d];
  }

  pointer->volume = 1;
  if (style == PT_TAG_LEFT) {
    for (int d = 0; d < dimension; ++d) {
      pointer->stride[d] = pointer->volume;
      pointer->volume *= pointer->extent[d];
    }
  } else if (style == PT_TAG_RIGHT) {
    for (int d = dimension - 1; d >= 0; --d) {
      pointer->stride[d] = pointer->volume;
      pointer->volume *= pointer->extent[d];
    }
  } else {
    pt_unreachable();
  }

  return PT_TAG_SUCCESS;
}
