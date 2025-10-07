#pragma once

#include "pt/config.h"

bool pt_assert_impl(
  const bool result, const char* file, const int line, const char* expr);

#define pt_assert(_expr) \
  do { \
    if (!pt_assert_impl((_expr), __FILE__, __LINE__, #_expr)) { \
      abort(); \
    } \
  } while (0)

#define pt_assert_ok(...) pt_assert(true);

bool pt_assert_equal_impl_int(
  const int lhs, const int rhs, const int tolerance, const char* file,
  const int line);

bool pt_assert_equal_impl_double(
  const double lhs, const double rhs, const double tolerance, const char* file,
  const int line);

#define pt_assert_equal_impl(_lhs, _rhs, _tolerance) \
  _Generic( \
    (_lhs), \
    int: pt_assert_equal_impl_int, \
    double: pt_assert_equal_impl_double)( \
    (_lhs), (_rhs), (_tolerance), __FILE__, __LINE__)

#define pt_assert_equal(_lhs, _rhs, _tolerance) \
  do { \
    if (!pt_assert_equal_impl((_lhs), (_rhs), (_tolerance))) { \
      abort(); \
    } \
  } while (0)
