pt_add_test(
  NAME cuda_get_version
  MODULE dependency/cuda
  LIB PT::Test PT::Dependency
  USE_CUDA YES
  USE_ASAN YES
  LABEL type:unit feature:cuda
)
