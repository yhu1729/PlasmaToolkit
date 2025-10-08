#pragma once

#include "pt/core/status.h"
#include "pt/core/type.h"
#include <signal.h>

bool pt_expect_impl(
  const pt_tag code, const pt_status status, const char* file, const int line,
  const char* expr);

#define pt_expect(_result, _expr) \
  do { \
    if (!pt_expect_impl((_result), (_expr), __FILE__, __LINE__, #_expr)) { \
      raise(SIGTERM); \
    } \
  } while (0)
