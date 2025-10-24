#include "pt/test/check.h"
#include <omp.h>
#include <stdlib.h>

int
main(void) {
  int result = 0;

#pragma omp parallel
  {
    int index;

#pragma omp for reduction(+ : result)
    for (index = 0; index < 32; ++index) {
      result += index;
    }
  }

  pt_check_same(result, 496);

  return EXIT_SUCCESS;
}
