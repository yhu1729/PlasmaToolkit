#pragma once

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

#define pt_acquire_vector(_target, _length) \
  ({ \
    pt_vector(typeof(**((*(_target))->tag))) _type; \
    pt_invoke(pt_malloc((void**)(_target), sizeof(_type))); \
    pt_invoke(pt_acquire_buffer( \
      &((*(_target))->buffer), \
      ((_length) * (sizeof(typeof(**((*(_target))->tag))))), 0)); \
    (*(_target))->length = _length; \
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
      (_target)->buffer, _index * sizeof(**((_target)->tag)), \
      (void**)(&(_element))))
