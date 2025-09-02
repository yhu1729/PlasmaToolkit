#include "pt/algorithm/range.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"

pt_error
pt_release_range_iterator(pt_range_iterator target) {
  pt_invoke(pt_free(target->index));

  return PT_TAG_SUCCESS;
}
