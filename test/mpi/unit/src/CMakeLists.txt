add_executable(mpi_reduce test_mpi_reduce.c)
target_link_libraries(mpi_reduce PT::Test PT::Core)
add_test(
  NAME mpi/unit/reduce
  COMMAND
    ${MPIEXEC_EXECUTABLE} ${MPIEXEC_PREFLAGS}
    ${MPIEXEC_NUMPROC_FLAG} 4
    ${MPIEXEC_POSTFLAGS}
    ./mpi_reduce
)
set_tests_properties(
  mpi/unit/reduce
  PROPERTIES
  LABELS "type:unit;feature:mpi"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=0"
)
