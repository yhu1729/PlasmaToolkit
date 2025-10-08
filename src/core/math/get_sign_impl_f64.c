#include "pt/core/math.h"

pt_f64
pt_get_sign_impl_f64(const pt_f64 x) {
  return (x >= 0.0) ? 1.0 : -1.0;
}
