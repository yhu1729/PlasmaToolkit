#include "pt/core/status.h"
#include <signal.h>

pt_status
pt_abort(const pt_tag code, void* context) {
  if (code != PT_TAG_SUCCESS) {
    raise(SIGTERM);
  }

  return pt_ignore(code, context);
}
