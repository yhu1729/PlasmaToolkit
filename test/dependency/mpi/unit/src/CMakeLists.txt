pt_add_test(
  NAME reduce
  MODULE dependency/mpi
  LIB PT::Test PT::Core
  USE_MPI YES
  N_MPI_TASK 4
  USE_ASAN YES
  LABEL type:unit feature:mpi
)
