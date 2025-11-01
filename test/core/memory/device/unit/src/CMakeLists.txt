pt_add_test(
  NAME free_d
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_CUDA YES
  USE_ASAN YES
  LABEL type:unit
)
