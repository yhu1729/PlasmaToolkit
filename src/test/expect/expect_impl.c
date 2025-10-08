#include "pt/core/log.h"
#include "pt/core/status.h"
#include "pt/core/tag.h"
#include "pt/test/expect.h"

bool
pt_expect_impl(
  const pt_tag code, const pt_status status, const char* file, const int line,
  const char* expression) {
  const char* feedback;
  if (code == status.code) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (code == status.code) {
    pt_emit_log_debug("%s: %s:%d  %s", feedback, file, line, expression);
  } else {
    const char* name_code = pt_get_tag_name(code);
    const char* name_status = pt_get_status_name(status);
    pt_emit_log_debug(
      "%s: %s:%d  %s  (%s != %s)", feedback, file, line, expression, name_code,
      name_status);
  }

  return (code == status.code);
}
