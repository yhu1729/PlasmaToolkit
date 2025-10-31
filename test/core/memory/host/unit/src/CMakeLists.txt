pt_add_test(
  NAME free
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME malloc
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME calloc
  MODULE core/memory
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
