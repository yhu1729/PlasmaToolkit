#pragma once

enum _pt_tag_t {
  PT_TAG_LEFT,
  PT_TAG_RIGHT,
};
typedef enum _pt_tag_t pt_tag;

// clang-format off

#define _PT_ERROR_LIST(_entry) \
  _entry(PT_TAG_SUCCESS, "Success") \
  _entry(PT_TAG_INVALID_PARAMETER, "Invalid parameter") \
  _entry(PT_TAG_INVALID_OPERATION, "Invalid operation") \
  _entry(PT_TAG_NULL_POINTER, "Null pointer") \
  _entry(PT_TAG_OUT_OF_MEMORY, "Out of memory") \
  _entry(PT_TAG_OUT_OF_RANGE, "Out of range") \
  _entry(PT_TAG_UNREACHABLE, "Unreachable branch") \
  _entry(PT_TAG_INVALID_OUTPUT, "Invalid output") \
  _entry(PT_TAG_SINGULAR_MATRIX, "Singular matrix")

#define _PT_VERBOSITY_LIST(_entry) \
  _entry(PT_TAG_VERBOSITY_NONE, 0, "None") \
  _entry(PT_TAG_VERBOSITY_ERROR, 1, "Error") \
  _entry(PT_TAG_VERBOSITY_WARNING, 2, "Warning") \
  _entry(PT_TAG_VERBOSITY_INFO, 3, "Info") \
  _entry(PT_TAG_VERBOSITY_DEBUG, 4, "Debug")

#define _PT_CONTEXT_TYPE_LIST(_entry) \
  _entry(PT_TAG_LOCAL, "Local") \
  _entry(PT_TAG_MPI, "MPI") \
  _entry(PT_TAG_NCCL, "NCCL")

#define _PT_MEMORY_TYPE_LIST(_entry) \
  _entry(PT_TAG_CPU, "CPU") \
  _entry(PT_TAG_GPU_NVIDIA, "GPU/NVIDIA") \
  _entry(PT_TAG_GPU_AMD, "GPU/AMD")

#define _PT_LINEAR_SOLVER_TYPE_LIST(_entry) \
  _entry(PT_TAG_DIRECT, "Direct linear algebra solver") \
  _entry(PT_TAG_ITERATIVE, "Iterative linear algebra solver")

#define _PT_PDE_TYPE_LIST(_entry) \
  _entry(PT_TAG_ADVECTION, "Advection equation") \
  _entry(PT_TAG_EULER, "Euler equation")

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

enum _pt_context_type_t {
#define _PT_EXPAND_TO_ENUM(_tag, _name) _tag,

  _PT_CONTEXT_TYPE_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_context_type_t pt_context_type;

enum _pt_memory_type_t {
#define _PT_EXPAND_TO_ENUM(_tag, _name) _tag,

  _PT_MEMORY_TYPE_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_memory_type_t pt_memory_type;

enum _pt_linear_solver_type_t {
#define _PT_EXPAND_TO_ENUM(_tag, _name) _tag,

  _PT_LINEAR_SOLVER_TYPE_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_linear_solver_type_t pt_linear_solver_type;

enum _pt_pde_type_t {
#define _PT_EXPAND_TO_ENUM(_tag, _name) _tag,

  _PT_PDE_TYPE_LIST(_PT_EXPAND_TO_ENUM)

#undef _PT_EXPAND_TO_ENUM
};
typedef enum _pt_pde_type_t pt_pde_type;
