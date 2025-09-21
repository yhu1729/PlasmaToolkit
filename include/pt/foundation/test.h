#pragma once

#include "pt/foundation/error.h"
#include "pt/foundation/io.h"
#include <stdbool.h>
#include <stdlib.h>

#define PT_TEST_EPSILON_FLOAT 1e-4
#define PT_TEST_EPSILON_DOUBLE 1e-13

bool pt_test_assert_impl(
  const bool result, const char* file, const int line, const char* expr);

#define pt_test_assert(_expr) \
  do { \
    if (!pt_test_assert_impl((_expr), __FILE__, __LINE__, #_expr)) { \
      abort(); \
    } \
  } while (0)

bool pt_test_assert_equal_impl_int(
  const int lhs, const int rhs, const int tolerance, const char* file,
  const int line);

bool pt_test_assert_equal_impl_double(
  const double lhs, const double rhs, const double tolerance, const char* file,
  const int line);

#define pt_test_assert_equal_impl(_lhs, _rhs, _tolerance) \
  _Generic( \
    (_lhs), \
    int: pt_test_assert_equal_impl_int, \
    double: pt_test_assert_equal_impl_double)( \
    (_lhs), (_rhs), (_tolerance), __FILE__, __LINE__)

#define pt_test_assert_equal(_lhs, _rhs, _tolerance) \
  do { \
    if (!pt_test_assert_equal_impl((_lhs), (_rhs), (_tolerance))) { \
      abort(); \
    } \
  } while (0)

bool pt_test_invoke_impl(
  const pt_error result, const pt_error target, const char* file,
  const int line, const char* expr);

#define pt_test_invoke(_result, _expr) \
  do { \
    if (!pt_test_invoke_impl( \
          (_expr), (_result), __FILE__, __LINE__, #_expr)) { \
      abort(); \
    } \
  } while (0)

struct _pt_test_list_item_t {
  void (*handle)(void);
  const char* name;
};
extern const struct _pt_test_list_item_t pt_test_list[];
#define PT_TEST_LIST const struct _pt_test_list_item_t pt_test_list[]

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
