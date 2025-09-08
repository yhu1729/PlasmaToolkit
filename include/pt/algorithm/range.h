#pragma once

#include "pt/config.h"
#include "pt/foundation/tag.h"
#include <stdlib.h>

pt_error pt_find_index(
  pt_i64* target, size_t offset, const int dimension, const size_t* stride);

struct _pt_range_t {
  pt_tag style;
  int dimension;
  pt_i64* lower;
  pt_i64* upper;
  size_t* extent;
  size_t* stride;
  size_t volume;
};
typedef struct _pt_range_t* pt_range;

struct _pt_range_iterator_t {
  pt_range range;
  size_t offset;
  pt_i64* index;
};
typedef struct _pt_range_iterator_t* pt_range_iterator;

pt_error pt_acquire_range(
  pt_range target[1], const pt_tag style, const int dimension,
  const pt_i64* lower, const pt_i64* upper);
pt_error pt_release_range(pt_range target);

pt_error
pt_acquire_range_iterator(pt_range_iterator target[1], const pt_range range);
pt_error pt_release_range_iterator(pt_range_iterator target);
pt_error pt_reset_range_iterator(pt_range_iterator target);
pt_error
pt_advance_range_iterator(pt_range_iterator target, const size_t step);
