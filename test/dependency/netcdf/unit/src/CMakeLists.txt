pt_add_test(
  NAME get_version
  MODULE dependency/netcdf
  LIB PT::Test PT::Core
  USE_MPI YES
  N_MPI_TASK 4
  USE_ASAN YES
  LABEL type:unit feature:netcdf
)
pt_add_test(
  NAME write
  MODULE dependency/netcdf
  LIB PT::Test PT::Core
  USE_MPI YES
  N_MPI_TASK 4
  USE_ASAN YES
  LABEL type:unit feature:netcdf
)
