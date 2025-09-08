#pragma once

#include "pt/config.h"
#include "pt/container/buffer.h"
#include "pt/foundation/error.h"
#include "pt/foundation/tag.h"
#include <stdlib.h>

#define pt_vector(_type) \
  typedef struct { \
    pt_buffer buffer; \
    size_t length; \
    _type* tag[0]; \
  }*

pt_vector(pt_u8) pt_vector_u8;
pt_vector(pt_u16) pt_vector_u16;
pt_vector(pt_u32) pt_vector_u32;
pt_vector(pt_u64) pt_vector_u64;
pt_vector(pt_i8) pt_vector_i8;
pt_vector(pt_i16) pt_vector_i16;
pt_vector(pt_i32) pt_vector_i32;
pt_vector(pt_i64) pt_vector_i64;
pt_vector(pt_f32) pt_vector_f32;
pt_vector(pt_f64) pt_vector_f64;
pt_vector(pt_f128) pt_vector_f128;
#ifdef PT_USE_TYPE
typedef pt_vector_u8 vector_u8;
typedef pt_vector_u16 vector_u16;
typedef pt_vector_u32 vector_u32;
typedef pt_vector_u64 vector_u64;
typedef pt_vector_i8 vector_i8;
typedef pt_vector_i16 vector_i16;
typedef pt_vector_i32 vector_i32;
typedef pt_vector_i64 vector_i64;
typedef pt_vector_f32 vector_f32;
typedef pt_vector_f64 vector_f64;
typedef pt_vector_f128 vector_f128;
#endif

#define pt_acquire_vector(_target, _length) \
  ({ \
    typedef typeof(**((*(_target))->tag)) _datatype; \
    pt_vector(_datatype) _type; \
    pt_invoke(pt_malloc((void**)(_target), sizeof(_type))); \
    pt_invoke(pt_acquire_buffer( \
      &((*(_target))->buffer), ((_length) * (sizeof(_datatype))), 0)); \
    (*(_target))->length = (_length); \
    PT_TAG_SUCCESS; \
  })

#define pt_release_vector(_target) \
  ({ \
    pt_invoke(pt_release_buffer((_target)->buffer)); \
    pt_invoke(pt_free((_target))); \
    PT_TAG_SUCCESS; \
  })

#define pt_fetch_vector_element(_target, _index, _element) \
  _Generic( \
    (_element), \
    typeof(*((_target)->tag)): pt_fetch_buffer_element( \
      (_target)->buffer, (_index) * sizeof(**((_target)->tag)), \
      (void**)(&(_element))))
