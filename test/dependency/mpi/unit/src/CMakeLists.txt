pt_add_test(
  NAME reduce
  MODULE dependency/mpi/unit
  LIB PT::Test PT::Core
  ENV_MOD ASAN_OPTIONS=set:detect_leaks=1
  LABEL type:unit feature:mpi
  USE_MPI YES
  N_MPI_TASK 4
)
