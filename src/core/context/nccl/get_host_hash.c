#include "pt/core/context/nccl.h"
#include "pt/core/math.h"
#include <stdio.h>
#include <string.h>

pt_status
pt_get_host_hash(pt_u64 result[1], const char* host_name) {
  PT_STATUS(status);

  char hash[128];
  strncpy(hash, host_name, sizeof(hash));
  int offset = strlen(hash);

  FILE* file_id = fopen("/proc/sys/kernel/random/boot_id", "r");
  if (file_id) {
    char* buffer;
    if (fscanf(file_id, "%ms", &buffer) == 1) {
      strncpy(hash + offset, buffer, sizeof(hash) - offset - 1);
      free(buffer);
    }
  }
  fclose(file_id);

  hash[sizeof(hash) - 1] = '\0';

  pt_safe_invoke(pt_get_hash(result, hash, strlen(hash)));

  return status;
}
