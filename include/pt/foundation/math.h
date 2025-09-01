#pragma once

#define pt_min(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define pt_max(_a, _b) (((_a) < (_b)) ? (_b) : (_a))
#define pt_min3(_a, _b, _c) (pt_min(pt_min(_a, _b), _c))
#define pt_max3(_a, _b, _c) (pt_max(pt_max(_a, _b), _c))

inline static float
_pt_sign_float(const float x) {
  return (x >= 0.0f) ? 1.0f : -1.0f;
}

inline static double
_pt_sign_double(const double x) {
  return (x >= 0.0) ? 1.0 : -1.0;
}

#define pt_sign(_x) \
  _Generic((_x), float: _pt_sign_float, double: _pt_sign_double)((_x))
