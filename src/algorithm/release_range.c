#include "pt/algorithm/range.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"

pt_error
pt_release_range(pt_range target) {
  pt_invoke(pt_free(target->lower));
  pt_invoke(pt_free(target->upper));
  pt_invoke(pt_free(target->extent));
  pt_invoke(pt_free(target->stride));
  pt_invoke(pt_free(target));

  return PT_TAG_SUCCESS;
}
