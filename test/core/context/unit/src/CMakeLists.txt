pt_add_test(
  NAME acquire_context_local
  MODULE core/unit
  LIB PT::Test PT::Core
  ENV_MOD ASAN_OPTIONS=set:detect_leaks=1
  LABEL type:unit module:core/context network:local
)
pt_add_test(
  NAME acquire_context_mpi
  MODULE core/unit
  LIB PT::Test PT::Core
  ENV_MOD ASAN_OPTIONS=set:detect_leaks=1
  LABEL type:unit module:core/context network:mpi
  USE_MPI YES
  N_MPI_TASK 4
)
pt_add_test(
  NAME acquire_context_nccl
  MODULE core/unit
  LIB PT::Test PT::Core
  ENV_MOD ASAN_OPTIONS=set:detect_leaks=1
  LABEL type:unit module:core/context network:nccl
  USE_MPI YES
  N_MPI_TASK 4
  USE_CUDA YES
)
pt_add_test(
  NAME acquire_context
  MODULE core/unit
  LIB PT::Test PT::Core
  ENV_MOD ASAN_OPTIONS=set:detect_leaks=1
  LABEL type:unit module:core/context network:local network:mpi network:nccl
  USE_MPI YES
  N_MPI_TASK 4
  USE_CUDA YES
)
