#pragma once

#include "pt/core/tag.h"

const char* pt_get_verbosity_name(const pt_tag level);

void pt_emit_log(const pt_tag level, const char* format, ...);

#define pt_emit_log_error(...) pt_emit_log(PT_TAG_VERBOSITY_ERROR, __VA_ARGS__)
#define pt_emit_log_warning(...) \
  pt_emit_log(PT_TAG_VERBOSITY_WARNING, __VA_ARGS__)
#define pt_emit_log_info(...) pt_emit_log(PT_TAG_VERBOSITY_INFO, __VA_ARGS__)
#define pt_emit_log_debug(...) pt_emit_log(PT_TAG_VERBOSITY_DEBUG, __VA_ARGS__)
