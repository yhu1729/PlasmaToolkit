#pragma once

#include "pt/core/type.h"

#define pt_min(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define pt_max(_a, _b) (((_a) < (_b)) ? (_b) : (_a))
#define pt_min3(_a, _b, _c) (pt_min(pt_min(_a, _b), _c))
#define pt_max3(_a, _b, _c) (pt_max(pt_max(_a, _b), _c))

pt_f32 pt_get_sign_impl_f32(const pt_f32 x);

pt_f64 pt_get_sign_impl_f64(const pt_f64 x);

#define pt_get_sign_impl(_x) \
  _Generic((_x), pt_f32: pt_get_sign_impl_f32, pt_f64: pt_get_sign_impl_f64)( \
    (_x))

#define pt_get_sign(...) pt_get_sign_impl(__VA_ARGS__)
