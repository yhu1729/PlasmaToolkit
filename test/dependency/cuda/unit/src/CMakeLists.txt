pt_add_test(
  NAME cuda_add
  MODULE dependency/cuda
  LIB PT::Test PT::Dependency
  USE_CUDA YES
  CUDA_KERNEL add.cu
  USE_ASAN YES
  LABEL type:unit feature:cuda
)
