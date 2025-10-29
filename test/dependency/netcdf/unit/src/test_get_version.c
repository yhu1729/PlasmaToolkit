#include <mpi.h>
#include <netcdf_meta.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char** argv) {
  MPI_Init(&argc, &argv);

  const char* version = NC_VERSION;
  puts(version);

  MPI_Finalize();

  return EXIT_SUCCESS;
}
