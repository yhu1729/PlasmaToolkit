pt_add_test(
  NAME get_version
  MODULE dependency/netcdf/unit
  LIB PT::Test PT::Core
  ENV_MOD ASAN_OPTIONS=set:detect_leaks=1
  LABEL type:unit feature:netcdf
  USE_MPI YES
  N_MPI_TASK 4
)
pt_add_test(
  NAME write
  MODULE dependency/netcdf/unit
  LIB PT::Test PT::Core
  ENV_MOD ASAN_OPTIONS=set:detect_leaks=1
  LABEL type:unit feature:netcdf
  USE_MPI YES
  N_MPI_TASK 4
)
