#include "pt/algorithm/range.h"
#include "pt/foundation/error.h"
#include "pt/foundation/macro.h"
#include "pt/foundation/memory.h"

pt_error
pt_acquire_range_iterator(pt_range_iterator target[1], const pt_range range) {
  pt_invoke(pt_malloc(target, sizeof **target));

  pt_range_iterator pointer = *target;
  pointer->range = range;
  pointer->offset = 0;

  pt_invoke(pt_calloc(&(pointer->index), range->dimension, sizeof(long long)));
  for (int d = 0; d < range->dimension; ++d) {
    pointer->index[d] = 0;
  }

  return PT_TAG_SUCCESS;
}
