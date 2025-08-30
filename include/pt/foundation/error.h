#pragma once

#include "pt/config.h"
#include "pt/foundation/io.h"
#include "pt/foundation/tag.h"

const char* pt_get_error_message(const pt_error target);

pt_error pt_invoke_impl(
  const pt_error result, const char* file, const int line, const char* expr);

#ifdef PT_ABORT_ON_ERROR
#define pt_invoke(expr) \
  do { \
    if (pt_invoke_impl((expr), __FILE__, __LINE__, #expr)) { \
      abort(); \
    } \
  } while (0)
#else
#define pt_invoke(expr) (expr)
#endif
