add_executable(acquire_context_local test_acquire_context_local.c)
target_link_libraries(acquire_context_local PT::Test PT::Core)
add_test(
  NAME Core/unit/acquire_context_local
  COMMAND ./acquire_context_local
)
set_tests_properties(Core/unit/acquire_context_local
  PROPERTIES
  LABELS "type:unit;module:core/context"
)

add_executable(acquire_context_mpi test_acquire_context_mpi.c)
target_link_libraries(acquire_context_mpi PT::Test PT::Core)
add_test(
  NAME Core/unit/acquire_context_mpi
  COMMAND
    ${MPIEXEC_EXECUTABLE} ${MPIEXEC_PREFLAGS}
    ${MPIEXEC_NUMPROC_FLAG} 4
    ${MPIEXEC_POSTFLAGS}
    ./acquire_context_mpi
)
set_tests_properties(Core/unit/acquire_context_mpi
  PROPERTIES
  LABELS "type:unit;module:core/context"
)
