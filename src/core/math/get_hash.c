#include "pt/core/math.h"

pt_status
pt_get_hash(pt_u64 result[1], const char* buffer, size_t length) {
  PT_STATUS(status);

  *result = 5381;
  for (size_t index = 0; index < length; ++index) {
    *result = ((*result << 5) + *result) ^ buffer[index];
  }

  return status;
}
