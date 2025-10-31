pt_add_test(
  NAME acquire_context_local
  MODULE core/context
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit network:local
)
pt_add_test(
  NAME acquire_context_mpi
  MODULE core/context
  LIB PT::Test PT::Core
  USE_MPI YES
  N_MPI_TASK 4
  USE_ASAN YES
  LABEL type:unit network:mpi
)
pt_add_test(
  NAME acquire_context_nccl
  MODULE core/context
  LIB PT::Test PT::Core
  USE_MPI YES
  N_MPI_TASK 4
  USE_CUDA YES
  USE_ASAN YES
  LABEL type:unit network:nccl
)
pt_add_test(
  NAME acquire_context
  MODULE core/context
  LIB PT::Test PT::Core
  USE_MPI YES
  N_MPI_TASK 4
  USE_CUDA YES
  USE_ASAN YES
  LABEL type:unit network:local network:mpi network:nccl
)
