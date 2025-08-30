#pragma once

enum _pt_tag_t {
  PT_TAG_LEFT,
  PT_TAG_RIGHT,
};
typedef enum _pt_tag_t pt_tag;

// clang-format off

#define _PT_ERROR_LIST(entry) \
  entry(PT_TAG_SUCCESS, "Success") \
  entry(PT_TAG_INVALID_PARAMETER, "Invalid parameter") \
  entry(PT_TAG_NULL_POINTER, "Null pointer") \
  entry(PT_TAG_OUT_OF_MEMORY, "Out of memory") \
  entry(PT_TAG_OUT_OF_RANGE, "Out of range") \
  entry(PT_TAG_UNREACHABLE, "Unreachable branch")

#define _PT_VERBOSITY_LIST(entry) \
  entry(PT_TAG_VERBOSITY_NONE, 0, "None") \
  entry(PT_TAG_VERBOSITY_ERROR, 1, "Error") \
  entry(PT_TAG_VERBOSITY_WARNING, 2, "Warning") \
  entry(PT_TAG_VERBOSITY_INFO, 3, "Info") \
  entry(PT_TAG_VERBOSITY_DEBUG, 4, "Debug")

// clang-format on

enum _pt_error_t {
#define _PT_EXPAND_TO_ENUM(tag, message) tag,

  _PT_ERROR_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_error_t pt_error;

enum _pt_verbosity_t {
#define _PT_EXPAND_TO_ENUM(tag, value, name) tag = value,

  _PT_VERBOSITY_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_verbosity_t pt_verbosity;
