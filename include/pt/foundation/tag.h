#pragma once

enum _pt_tag_t {
  PT_TAG_LEFT,
  PT_TAG_RIGHT,
  PT_TAG_LOCAL,
  PT_TAG_MPI,
  PT_TAG_NCCL,
};
typedef enum _pt_tag_t pt_tag;

// clang-format off

#define _PT_ERROR_LIST(entry) \
  entry(PT_TAG_SUCCESS, "Success") \
  entry(PT_TAG_INVALID_PARAMETER, "Invalid parameter") \
  entry(PT_TAG_INVALID_OPERATION, "Invalid operation") \
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

#define _PT_MEMORY_TYPE_LIST(entry) \
  entry(PT_TAG_CPU, "CPU") \
  entry(PT_TAG_GPU_NVIDIA, "GPU/NVIDIA") \
  entry(PT_TAG_GPU_AMD, "GPU/AMD")

#define _PT_PDE_TYPE_LIST(entry) \
  entry(PT_TAG_ADVECTION, "Advection equation") \
  entry(PT_TAG_EULER, "Euler equation")

// clang-format on

enum _pt_error_t {
#define _PT_EXPAND_TO_ENUM(_tag, _message) _tag,

  _PT_ERROR_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_error_t pt_error;

enum _pt_verbosity_t {
#define _PT_EXPAND_TO_ENUM(_tag, _value, _name) _tag = _value,

  _PT_VERBOSITY_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_verbosity_t pt_verbosity;

enum _pt_memory_type_t {
#define _PT_EXPAND_TO_ENUM(_tag, _name) _tag,

  _PT_MEMORY_TYPE_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_memory_type_t pt_memory_type;

enum _pt_pde_type_t {
#define _PT_EXPAND_TO_ENUM(_tag, _name) _tag,

  _PT_PDE_TYPE_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_pde_type_t pt_pde_type;
