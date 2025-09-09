#include "pt/foundation/math.h"

float
pt_sign_float(const float x) {
  return (x >= 0.0f) ? 1.0f : -1.0f;
}
