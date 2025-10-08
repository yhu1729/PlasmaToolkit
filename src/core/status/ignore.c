#include "pt/core/status.h"
#include <stdlib.h>

pt_status
pt_ignore(const pt_tag code, void* context) {
  pt_status result = {PT_TAG_SUCCESS, NULL, context};

  return result;
}
