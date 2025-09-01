#pragma once

#include "pt/foundation/error.h"
#include "pt/foundation/io.h"
#include <stdbool.h>
#include <stdlib.h>

inline static bool
_pt_test_assert(
  const bool result, const char* file, const int line, const char* expr) {
  const char* feedback;
  if (result) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (!result) {
    const char* message = "Invalid assertion";
    pt_log_error("%s: %s:%d  %s\n%s.\n", feedback, file, line, expr, message);
  } else {
    pt_log_debug("%s: %s:%d  %s\n", feedback, file, line, expr);
  }

  return result;
}

#define pt_test_assert(expr) \
  do { \
    if (!_pt_test_assert((expr), __FILE__, __LINE__, #expr)) { \
      abort(); \
    } \
  } while (0)

inline static bool
_pt_test_invoke(
  const pt_error result, const pt_error target, const char* file,
  const int line, const char* expr) {
  const char* feedback;
  if (result == target) {
    feedback = "PASS";
  } else {
    feedback = "FAIL";
  }

  if (result != target) {
    const char* message = pt_get_error_message(result);
    pt_log_error("%s: %s:%d  %s\n%s.\n", feedback, file, line, expr, message);
  } else {
    pt_log_debug("%s: %s:%d  %s\n", feedback, file, line, expr);
  }

  return (result == target);
}

#define pt_test_invoke(expr, r) \
  do { \
    if (!_pt_test_invoke((expr), (r), __FILE__, __LINE__, #expr)) { \
      abort(); \
    } \
  } while (0)

struct _pt_test_list_t {
  const char* name;
  void (*handle)(void);
};
extern const struct _pt_test_list_t pt_test_list[];
#define PT_TEST_LIST const struct _pt_test_list_t pt_test_list[]

#define PT_TEST_MAIN \
  int main(void) { \
    int list_size = 0; \
    for (list_size = 0;; ++list_size) { \
      if (!pt_test_list[list_size].name) { \
        break; \
      } \
    } \
    void (*handle)(void); \
    for (int index = 0; index < list_size; ++index) { \
      handle = pt_test_list[index].handle; \
      pt_log_info("TEST: %s\n", pt_test_list[index].name); \
      handle(); \
    } \
    return EXIT_SUCCESS; \
  }
