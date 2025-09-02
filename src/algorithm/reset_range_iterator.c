#include "pt/algorithm/range.h"

pt_error
pt_reset_range_iterator(pt_range_iterator target) {
  target->offset = 0;
  for (int d = 0; d < target->range->dimension; ++d) {
    target->index[d] = target->range->lower[d];
  }

  return PT_TAG_SUCCESS;
}
