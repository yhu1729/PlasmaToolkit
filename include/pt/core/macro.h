#pragma once

#include <stddef.h>

#define pt_unreachable __builtin_unreachable

#define pt_container_of(_pointer, _type, _field) \
  ((_type*)((char*)(1 ? (_pointer) : &((_type*)0)->_field) - \
            offsetof(_type, _field)))

#define pt_as_pointer(_target, _tag, _member) \
  ((typeof(**((*(_target))._tag))*)((*(_target))._member))
