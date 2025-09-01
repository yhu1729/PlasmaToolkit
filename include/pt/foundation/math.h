#pragma once

#define pt_min(a, b) (((a) < (b)) ? (a) : (b))
#define pt_max(a, b) (((a) < (b)) ? (b) : (a))
#define pt_min3(a, b, c) (pt_min(pt_min(a, b), c))
#define pt_max3(a, b, c) (pt_max(pt_max(a, b), c))

inline static float
_pt_sign_float(const float x) {
  return (x >= 0.0f) ? 1.0f : -1.0f;
}

inline static double
_pt_sign_double(const double x) {
  return (x >= 0.0) ? 1.0 : -1.0;
}

#define pt_sign(x) \
  _Generic((x), float: _pt_sign_float, double: _pt_sign_double)((x))
