#include "pt/core/math.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void
test_f32(void) {
  pt_f32 target = pt_get_sign(+2.0f);
  pt_check_equal(target, +1.0f, PT_EPSILON_F32);

  pt_check_ok();
}

void
test_f64(void) {
  pt_f64 target = pt_get_sign(+2.0);
  pt_check_equal(target, +1.0, PT_EPSILON_F64);

  pt_check_ok();
}

PT_TEST_LIST(
  {test_f32, "32-bit floating-point numbers"},
  {test_f64, "64-bit floating-point numbers"});

PT_TEST_UNIT_MAIN
