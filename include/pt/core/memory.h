#pragma once

#include "pt/config.h"
#include "pt/core/memory/device.h"
#include "pt/core/memory/host.h"

#ifndef __CUDA_ARCH__
#define pt_free(...) pt_free_h(__VA_ARGS__)
#define pt_malloc(...) pt_malloc_h(__VA_ARGS__)
#define pt_calloc(...) pt_calloc_h(__VA_ARGS__)
#else
#define pt_free(...) pt_free_d(__VA_ARGS__)
#define pt_malloc(...) pt_malloc_d(__VA_ARGS__)
#define pt_calloc(...) pt_calloc_d(__VA_ARGS__)
#endif
