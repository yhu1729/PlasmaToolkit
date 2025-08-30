#pragma once

// clang-format off

#define _PT_ERROR_LIST(entry) \
  entry(PT_TAG_SUCCESS, "Success") \
  entry(PT_TAG_INVALID_PARAMETER, "Invalid parameter") \
  entry(PT_TAG_NULL_POINTER, "Null pointer") \
  entry(PT_TAG_OUT_OF_MEMORY, "Out of memory") \
  entry(PT_TAG_OUT_OF_RANGE, "Out of range") \
  entry(PT_TAG_UNREACHABLE, "Unreachable branch")

// clang-format on

enum _pt_error_t {
#define _PT_EXPAND_TO_ENUM(tag, message) tag,

  _PT_ERROR_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_error_t pt_error;

const char* pt_get_error_message(const pt_error target);
