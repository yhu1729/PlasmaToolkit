#include "pt/test/check.h"
#include <mpi.h>
#include <stdlib.h>

int
main(void) {
  MPI_Init(NULL, NULL);

  int mpi_rank;
  int mpi_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

  int stride = 32 / mpi_size;
  int result = 0;
  for (int index_local = 0; index_local < stride; ++index_local) {
    const int index_global = index_local + mpi_rank * stride;
    result += index_global;
  }

  MPI_Allreduce(MPI_IN_PLACE, &result, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

  pt_check_same(result, 496);

  MPI_Finalize();

  return EXIT_SUCCESS;
}
