#include <nccl.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
  int version;
  ncclGetVersion(&version);
  printf("NCCL v%d\n", version);

  return EXIT_SUCCESS;
}
