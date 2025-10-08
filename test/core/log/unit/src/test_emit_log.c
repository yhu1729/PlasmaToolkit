#include "pt/core/log.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void
test_emit_one(void) {
  pt_emit_log_error("error");

  pt_check_ok();
}

void
test_emit_all(void) {
  pt_emit_log_error("error");
  pt_emit_log_warning("warning");
  pt_emit_log_info("info");
  pt_emit_log_debug("debug");

  pt_check_ok();
}

PT_TEST_LIST(
  {test_emit_one, "emit one log message"},
  {test_emit_all, "emit all log messages"});

PT_TEST_UNIT_MAIN
