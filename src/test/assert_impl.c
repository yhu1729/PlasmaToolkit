#include "pt/test/assert.h"
#include <stdio.h>

bool
pt_assert_impl(
  const bool result, const char* file, const int line, const char* expr) {
  const char* feedback;
  if (result) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (!result) {
    const char* message = "Invalid assertion";
    printf("%s: %s:%d  %s\n%s.\n", feedback, file, line, expr, message);
  } else {
    printf("%s: %s:%d  %s\n", feedback, file, line, expr);
  }

  return result;
}
