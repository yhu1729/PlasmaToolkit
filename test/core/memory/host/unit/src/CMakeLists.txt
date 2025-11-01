pt_add_test(
  NAME free_h
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME malloc_h
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME calloc_h
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
