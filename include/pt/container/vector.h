#pragma once

#include "pt/container/buffer.h"
#include "pt/foundation/tag.h"
#include <stdlib.h>

#define pt_vector(type) \
  typedef struct { \
    pt_buffer buffer; \
    type* tag[0]; \
  }*

#define pt_vector_as_pointer(target) ((typeof(**((*(target)).tag))*) ((*(target)).buffer->content))

#define pt_fetch_vector_element(target, index, element) \
  _Generic( \
    (element), \
    typeof(*((target)->tag)): pt_fetch_buffer_element( \
      (target)->buffer, index * sizeof(**((target)->tag)), \
      (void**)(&(element))))

#define pt_acquire_vector(target, size) \
  do { \
    pt_vector(typeof(**((*(target))->tag))) _type; \
    *(target) = malloc(sizeof(_type)); \
    pt_acquire_buffer(&((*(target))->buffer), (size), 0); \
  } while (0)

#define pt_release_vector(target) \
  do { \
    pt_release_buffer((target)->buffer); \
    free((target)); \
  } while (0)
