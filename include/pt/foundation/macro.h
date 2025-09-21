#pragma once

#include <stddef.h>

#define pt_unreachable __builtin_unreachable

#define pt_container_of(_pointer, _type, _field) \
  ((_type*)((char*)(1 ? (_pointer) : &((_type*)0)->_field) - \
            offsetof(_type, _field)))

#define pt_as_pointer(_target) \
  ((typeof(**((*(_target)).tag))*)((*(_target)).buffer->content))

#define pt_acquire(_target, ...) \
  _Generic( \
    (*(_target)), \
    pt_context: pt_acquire_context, \
    pt_linear_solver: pt_acquire_linear_solver)((_target)__VA_OPT__(, ) \
                                                  __VA_ARGS__)

#define pt_release(_target, ...) \
  _Generic( \
    (_target), \
    pt_context: pt_release_context, \
    pt_linear_solver: pt_release_linear_solver)((_target)__VA_OPT__(, ) \
                                                  __VA_ARGS__)
