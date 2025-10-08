#pragma once

#include "pt/config.h"
#include "pt/core/type.h"
#include <signal.h>

bool pt_check_impl(
  const bool result, const char* file, const int line, const char* expression);

#define pt_check(_expression) \
  do { \
    if (!pt_check_impl((_expression), __FILE__, __LINE__, #_expression)) { \
      raise(SIGTERM); \
    } \
  } while (0)

#define pt_check_ok(...) pt_check(true);

bool pt_check_equal_impl_i32(
  const pt_i32 lhs, const pt_i32 rhs, const pt_i32 tolerance, const char* file,
  const int line);

bool pt_check_equal_impl_f32(
  const pt_f32 lhs, const pt_f32 rhs, const pt_f32 tolerance, const char* file,
  const int line);

bool pt_check_equal_impl_f64(
  const pt_f64 lhs, const pt_f64 rhs, const pt_f64 tolerance, const char* file,
  const int line);

#define pt_check_equal_impl(_lhs, _rhs, _tolerance) \
  _Generic( \
    (_lhs), \
    pt_i32: pt_check_equal_impl_i32, \
    pt_f32: pt_check_equal_impl_f32, \
    pt_f64: pt_check_equal_impl_f64)( \
    (_lhs), (_rhs), (_tolerance), __FILE__, __LINE__)

#define pt_check_equal(_lhs, _rhs, _tolerance) \
  do { \
    if (!pt_check_equal_impl((_lhs), (_rhs), (_tolerance))) { \
      raise(SIGTERM); \
    } \
  } while (0)
