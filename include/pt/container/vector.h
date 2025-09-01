#pragma once

#include "pt/container/buffer.h"
#include "pt/foundation/error.h"
#include "pt/foundation/tag.h"
#include <stdlib.h>

#define pt_vector(type) \
  typedef struct { \
    pt_buffer buffer; \
    type* tag[0]; \
  }*

#define pt_fetch_vector_element(target, index, element) \
  _Generic( \
    (element), \
    typeof(*((target)->tag)): pt_fetch_buffer_element( \
      (target)->buffer, index * sizeof(**((target)->tag)), \
      (void**)(&(element))))

#define pt_acquire_vector(target, size) \
  ({ \
    pt_vector(typeof(**((*(target))->tag))) _type; \
    pt_invoke(pt_malloc((void**)(target), sizeof(_type))); \
    pt_invoke(pt_acquire_buffer(&((*(target))->buffer), (size), 0)); \
    PT_TAG_SUCCESS; \
  })

#define pt_release_vector(target) \
  ({ \
    pt_invoke(pt_release_buffer((target)->buffer)); \
    pt_invoke(pt_free((target))); \
    PT_TAG_SUCCESS; \
  })
