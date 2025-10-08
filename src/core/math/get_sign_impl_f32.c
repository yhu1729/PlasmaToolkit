#include "pt/core/math.h"

pt_f32
pt_get_sign_impl_f32(const pt_f32 x) {
  return (x >= 0.0f) ? 1.0f : -1.0f;
}
