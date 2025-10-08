#pragma once

#include "pt/core/tag.h"
#include <stdlib.h>

typedef struct _pt_status_t pt_status;
typedef pt_status (*pt_status_callback_t)(const pt_tag, void* context);

struct _pt_status_t {
  pt_tag code;
  pt_status_callback_t callback;
  void* context;
};

#define PT_STATUS(_handle) pt_status _handle = {PT_TAG_SUCCESS, NULL, NULL}

const char* pt_get_status_name(const pt_status target);
pt_status pt_ignore(const pt_tag code, void* context);
pt_status pt_abort(const pt_tag code, void* context);
pt_status pt_invoke_impl(
  const pt_status target, pt_status_callback_t callback, void* context,
  const char* function, const char* file, const int line);

#define pt_invoke(_expression, _callback, _context) \
  pt_invoke_impl( \
    (_expression), (_callback), (_context), __func__, __FILE__, __LINE__)

#define pt_safe_invoke(_expression) pt_invoke((_expression), pt_abort, NULL)
