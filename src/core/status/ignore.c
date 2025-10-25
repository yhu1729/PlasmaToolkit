#include "pt/core/status.h"
#include <stdlib.h>

pt_status
pt_ignore(const pt_tag, void* context) {
  pt_status status = {PT_TAG_SUCCESS, NULL, context};

  return status;
}
