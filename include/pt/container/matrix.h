#pragma once

#include "pt/container/buffer.h"
#include "pt/foundation/error.h"
#include "pt/foundation/tag.h"
#include <stdlib.h>

#define pt_matrix(_type) \
  typedef struct { \
    pt_buffer buffer; \
    size_t row; \
    size_t column; \
    _type* tag[0]; \
  }*

#define pt_acquire_matrix(_target, _row, _column) \
  ({ \
    typedef typeof(**((*(_target))->tag)) _datatype; \
    pt_matrix(_datatype) _type; \
    pt_invoke(pt_malloc((void**)(_target), sizeof(_type))); \
    pt_invoke(pt_acquire_buffer( \
      &((*(_target))->buffer), ((_row) * (_column) * (sizeof(_datatype))), \
      0)); \
    (*(_target))->row = _row; \
    (*(_target))->column = _column; \
    PT_TAG_SUCCESS; \
  })

#define pt_release_matrix(_target) \
  ({ \
    pt_invoke(pt_release_buffer((_target)->buffer)); \
    pt_invoke(pt_free((_target))); \
    PT_TAG_SUCCESS; \
  })

#define pt_fetch_matrix_element(_target, _index, _row, _column) \
  _Generic( \
    (_element), \
    typeof(*((_target)->tag)): pt_fetch_buffer_element( \
      (_target)->buffer, \
      ((_row) + (_target)->row * (_column)) * sizeof(**((_target)->tag)), \
      (void**)(&(_element))))
