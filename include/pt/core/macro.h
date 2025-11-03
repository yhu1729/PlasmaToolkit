#pragma once

#include "pt/container/buffer.h"
#include "pt/core/context.h"
#include "pt/profile/timer.h"
#include "pt/profile/tracker.h"
#include <stddef.h>

#define pt_unreachable __builtin_unreachable

#define pt_container_of(_pointer, _type, _field) \
  ((_type*)((char*)(1 ? (_pointer) : &((_type*)0)->_field) - \
            offsetof(_type, _field)))

#define pt_as_pointer(_target, _tag, _member) \
  ((typeof(**((*(_target))._tag))*)((*(_target))._member))

#define pt_acquire(_target, ...) \
  _Generic( \
    (*(_target)), \
    pt_context: pt_acquire_context, \
    pt_context_local: pt_acquire_context_local, \
    pt_context_mpi: pt_acquire_context_mpi, \
    pt_timer: pt_acquire_timer, \
    pt_tracker: pt_acquire_tracker, \
    pt_buffer_h: pt_acquire_buffer_h, \
    pt_buffer_d: pt_acquire_buffer_d)((_target)__VA_OPT__(, ) __VA_ARGS__)

#define pt_release(_target, ...) \
  _Generic( \
    (_target), \
    pt_context: pt_release_context, \
    pt_context_local: pt_release_context_local, \
    pt_context_mpi: pt_release_context_mpi, \
    pt_timer: pt_release_timer, \
    pt_tracker: pt_release_tracker, \
    pt_buffer_h: pt_release_buffer_h, \
    pt_buffer_d: pt_release_buffer_d)((_target)__VA_OPT__(, ) __VA_ARGS__)

#define pt_initialize(_target, ...) \
  _Generic( \
    (_target), \
    pt_context: pt_initialize_context, \
    pt_context_interface: pt_initialize_context_interface, \
    pt_context_local: pt_initialize_context_local, \
    pt_context_mpi: pt_initialize_context_mpi)((_target)__VA_OPT__(, ) \
                                                 __VA_ARGS__)

#define pt_finalize(_target, ...) \
  _Generic( \
    (_target), \
    pt_context: pt_finalize_context, \
    pt_context_interface: pt_finalize_context_interface, \
    pt_context_local: pt_finalize_context_local, \
    pt_context_mpi: pt_finalize_context_mpi)((_target)__VA_OPT__(, ) \
                                               __VA_ARGS__)

#define pt_start(_target, ...) \
  _Generic( \
    (_target), pt_timer: pt_start_timer, pt_tracker: pt_start_tracker)( \
    (_target)__VA_OPT__(, ) __VA_ARGS__)

#define pt_stop(_target, ...) \
  _Generic((_target), pt_timer: pt_stop_timer, pt_tracker: pt_stop_tracker)( \
    (_target)__VA_OPT__(, ) __VA_ARGS__)
