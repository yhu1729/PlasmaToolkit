#pragma once

#include "pt/container/buffer.h"
#include "pt/foundation/error.h"

struct pt_pool_t {
  pt_u64 size_block;
  pt_u64 block_total;
  pt_u64 block_free;
  void* head;
  void* next;
};
typedef struct pt_pool_t* pt_pool;

pt_error pt_acquire_pool(
  pt_pool target[1], const pt_u64 size_block, const pt_u64 block_total);
pt_error pt_release_pool(pt_pool target);
pt_error pt_pool_allocate_impl(pt_pool target, void** result, const pt_u64 n);
pt_error
pt_pool_deallocate_impl(pt_pool target, void* pointer, const pt_u64 n);

#define pt_pool_allocate(_target, _result, _n) \
  pt_pool_allocate_impl((_target), (void**)(_result), (_n))
#define pt_pool_deallocate(_target, _pointer, _n) \
  pt_pool_deallocate_impl((_target), (void*)(_pointer), (_n))
