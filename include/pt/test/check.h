#pragma once

#include "pt/config.h"

bool pt_check_impl(
  const bool result, const char* file, const int line, const char* expr);

#define pt_check(_expr) \
  do { \
    if (!pt_check_impl((_expr), __FILE__, __LINE__, #_expr)) { \
      abort(); \
    } \
  } while (0)

#define pt_check_ok(...) pt_check(true);

bool pt_check_equal_impl_int(
  const int lhs, const int rhs, const int tolerance, const char* file,
  const int line);

bool pt_check_equal_impl_double(
  const double lhs, const double rhs, const double tolerance, const char* file,
  const int line);

#define pt_check_equal_impl(_lhs, _rhs, _tolerance) \
  _Generic( \
    (_lhs), \
    int: pt_check_equal_impl_int, \
    double: pt_check_equal_impl_double)( \
    (_lhs), (_rhs), (_tolerance), __FILE__, __LINE__)

#define pt_check_equal(_lhs, _rhs, _tolerance) \
  do { \
    if (!pt_check_equal_impl((_lhs), (_rhs), (_tolerance))) { \
      abort(); \
    } \
  } while (0)
