#pragma once

#include <stddef.h>

#define pt_unreachable __builtin_unreachable

#define pt_container_of(pointer, type, field) \
  ((type*)((char*)(1 ? (pointer) : &((type*)0)->field) - \
           offsetof(type, field)))
