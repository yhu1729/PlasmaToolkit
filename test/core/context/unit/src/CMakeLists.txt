add_executable(acquire_context_local test_acquire_context_local.c)
target_link_libraries(acquire_context_local PT::Test PT::Core)
add_test(
  NAME core/unit/acquire_context_local
  COMMAND ./acquire_context_local
)
set_tests_properties(
  core/unit/acquire_context_local
  PROPERTIES
  LABELS "type:unit;module:core/context;network:local"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)

add_executable(acquire_context_mpi test_acquire_context_mpi.c)
target_link_libraries(acquire_context_mpi PT::Test PT::Core)
add_test(
  NAME core/unit/acquire_context_mpi
  COMMAND
    ${MPIEXEC_EXECUTABLE}
    ${MPIEXEC_PREFLAGS}
    ${MPIEXEC_NUMPROC_FLAG} 4
    ${MPIEXEC_POSTFLAGS}
    ./acquire_context_mpi
)
set_tests_properties(
  core/unit/acquire_context_mpi
  PROPERTIES
  LABELS "type:unit;module:core/context;network:mpi"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)

if(PT_USE_CUDA)
  add_executable(acquire_context_nccl test_acquire_context_nccl.c)
  target_link_libraries(acquire_context_nccl PT::Test PT::Core)
  add_test(
    NAME core/unit/acquire_context_nccl
    COMMAND
      ${MPIEXEC_EXECUTABLE} ${MPIEXEC_PREFLAGS}
      ${MPIEXEC_NUMPROC_FLAG} 4
      ${MPIEXEC_POSTFLAGS}
      ./acquire_context_nccl
  )
  set_tests_properties(
    core/unit/acquire_context_nccl
    PROPERTIES
    LABELS "type:unit;module:core/context;network:nccl"
    ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
  )
endif()

add_executable(acquire_context test_acquire_context.c)
target_link_libraries(acquire_context PT::Test)
add_test(
  NAME core/unit/acquire_context
  COMMAND
    ${MPIEXEC_EXECUTABLE} ${MPIEXEC_PREFLAGS}
    ${MPIEXEC_NUMPROC_FLAG} 4
    ${MPIEXEC_POSTFLAGS}
    ./acquire_context
)
set_tests_properties(
  core/unit/acquire_context
  PROPERTIES
  LABELS "type:unit;module:core/context"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)
