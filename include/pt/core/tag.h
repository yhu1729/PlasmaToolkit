#pragma once

#include "pt/config.h"

// clang-format off

#define _PT_TAG_LIST(_entry) \
  _entry(PT_TAG_UNKNOWN,           "Unknown",              -1) \
  _entry(PT_TAG_SUCCESS,           "Success",               0) \
  _entry(PT_TAG_ERROR_MIN,         "Min error code",      999) \
  _entry(PT_TAG_INVALID_PARAMETER, "Invalid parameter",  1000) \
  _entry(PT_TAG_INVALID_OPERATION, "Invalid operation",  1001) \
  _entry(PT_TAG_INVALID_NETWORK,   "Invalid network",    1002) \
  _entry(PT_TAG_NULL_POINTER,      "Null pointer",       1003) \
  _entry(PT_TAG_OUT_OF_MEMORY,     "Out of memory",      1004) \
  _entry(PT_TAG_OUT_OF_RANGE,      "Out of range",       1005) \
  _entry(PT_TAG_UNREACHABLE,       "Unreachable branch", 1006) \
  _entry(PT_TAG_INVALID_OUTPUT,    "Invalid output",     1007) \
  _entry(PT_TAG_SINGULAR_MATRIX,   "Singular matrix",    1008) \
  _entry(PT_TAG_ERROR_MAX,         "Max error code",     1999) \
  _entry(PT_TAG_VERBOSITY_NONE,    "None",               2000) \
  _entry(PT_TAG_VERBOSITY_ERROR,   "Error",              2001) \
  _entry(PT_TAG_VERBOSITY_WARNING, "Warning",            2002) \
  _entry(PT_TAG_VERBOSITY_INFO,    "Info",               2003) \
  _entry(PT_TAG_VERBOSITY_DEBUG,   "Debug",              2004) \
  _entry(PT_TAG_NONE,              "None",               3000) \
  _entry(PT_TAG_LEFT,              "Left",               3001) \
  _entry(PT_TAG_RIGHT,             "Right",              3002) \
  _entry(PT_TAG_UPPER,             "Upper",              3003) \
  _entry(PT_TAG_LOWER,             "Lower",              3004) \
  _entry(PT_TAG_NETWORK_LOCAL,     "Local",              4000) \
  _entry(PT_TAG_NETWORK_MPI,       "MPI",                4001) \
  _entry(PT_TAG_NETWORK_NCCL,      "NCCL",               4002) \
  _entry(PT_TAG_CPU,               "CPU",                4003) \
  _entry(PT_TAG_GPU_NVIDIA,        "GPU/NVIDIA",         4004) \
  _entry(PT_TAG_GPU_AMD,           "GPU/AMD",            4005)

// clang-format on

enum _pt_tag_t {

#define _PT_EXPAND(_tag, _message, _value) _tag = _value,

  _PT_TAG_LIST(_PT_EXPAND)

#undef _PT_EXPAND

};
typedef enum _pt_tag_t pt_tag;

const char* pt_get_tag_name(const pt_tag);

#define PT_FEATURE_ON_HOST (1)
#define PT_FEATURE_ON_DEVICE (1 << 1)
