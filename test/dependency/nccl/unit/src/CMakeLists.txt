pt_add_test(
  NAME nccl_get_version
  MODULE dependency/nccl
  LIB PT::Test PT::Dependency
  USE_CUDA YES
  USE_ASAN YES
  LABEL type:unit feature:nccl
)
