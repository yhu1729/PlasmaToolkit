#pragma once

#include "pt/foundation/tag.h"

const char* pt_get_verbosity_name(const pt_verbosity target);

void pt_log(const pt_verbosity level, const char* format, ...);

#define pt_log_error(...) pt_log(PT_TAG_VERBOSITY_ERROR, __VA_ARGS__)
#define pt_log_warning(...) pt_log(PT_TAG_VERBOSITY_WARNING, __VA_ARGS__)
#define pt_log_info(...) pt_log(PT_TAG_VERBOSITY_INFO, __VA_ARGS__)
#define pt_log_debug(...) pt_log(PT_TAG_VERBOSITY_DEBUG, __VA_ARGS__)
