#pragma once

#define pt_min(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define pt_max(_a, _b) (((_a) < (_b)) ? (_b) : (_a))
#define pt_min3(_a, _b, _c) (pt_min(pt_min(_a, _b), _c))
#define pt_max3(_a, _b, _c) (pt_max(pt_max(_a, _b), _c))

float pt_sign_float(const float x);

double pt_sign_double(const double x);

#define pt_sign(_x) \
  _Generic((_x), float: pt_sign_float, double: pt_sign_double)((_x))
