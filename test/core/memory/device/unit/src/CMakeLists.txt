pt_add_test(
  NAME free_d
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_CUDA YES
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME malloc_d
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_CUDA YES
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME calloc_d
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_CUDA YES
  USE_ASAN YES
  LABEL type:unit
)
