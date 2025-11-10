#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char** argv) {
  MPI_Init(&argc, &argv);

  int mpi_size;
  int mpi_rank;
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);

  const int mpi_rank_right = (mpi_rank + 1) % mpi_size;

  double buffer[8];
  for (int index = 0; index < 8; ++index) {
    buffer[index] = (double)(mpi_rank * 8 + index);
  }
  MPI_Win mpi_window;
  MPI_Win_create(
    buffer, 8 * sizeof(double), sizeof(double), MPI_INFO_NULL, MPI_COMM_WORLD,
    &mpi_window);
  MPI_Win_fence(0, mpi_window);

  MPI_Get(
    &(buffer[7]), 1, MPI_DOUBLE, mpi_rank_right, 1, 1, MPI_DOUBLE, mpi_window);
  MPI_Put(
    &(buffer[6]), 1, MPI_DOUBLE, mpi_rank_right, 0, 1, MPI_DOUBLE, mpi_window);
  MPI_Win_fence(0, mpi_window);

  if (mpi_rank == 0) {
    printf("rank %d: ", mpi_rank);
    for (int index = 0; index < 8; ++index) {
      printf("%4.1f, ", buffer[index]);
    }
    puts("");
    int flag = 0;
    MPI_Send(&flag, 1, MPI_INT, mpi_rank_right, 0, MPI_COMM_WORLD);
  } else {
    const int mpi_rank_left = (mpi_rank + mpi_size - 1) % mpi_size;
    int flag;
    MPI_Recv(
      &flag, 1, MPI_INT, mpi_rank_left, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("rank %d: ", mpi_rank);
    for (int index = 0; index < 8; ++index) {
      printf("%4.1f, ", buffer[index]);
    }
    puts("");
    if (mpi_rank != (mpi_size - 1)) {
      MPI_Send(&flag, 1, MPI_INT, mpi_rank_right, 0, MPI_COMM_WORLD);
    }
  }
  MPI_Barrier(MPI_COMM_WORLD);

  MPI_Win_free(&mpi_window);

  MPI_Finalize();

  return EXIT_SUCCESS;
}
