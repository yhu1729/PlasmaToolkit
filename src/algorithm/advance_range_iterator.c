#include "pt/algorithm/range.h"
#include "pt/foundation/error.h"
#include "pt/foundation/macro.h"

pt_error
pt_advance_range_iterator(pt_range_iterator target, const size_t step) {
  if (!step) {
    return PT_TAG_SUCCESS;
  }

  target->offset += step;
  pt_invoke(pt_find_index(
    target->index, target->offset, target->range->dimension,
    target->range->stride));
  for (int d = 0; d < target->range->dimension; ++d) {
    target->index[d] += target->range->lower[d];
  }

  return PT_TAG_SUCCESS;
}
