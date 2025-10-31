pt_add_test(
  NAME acquire_vector_h
  MODULE container/vector
  LIB PT::Test PT::Container
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME release_vector_h
  MODULE container/vector
  LIB PT::Test PT::Container
  USE_ASAN YES
  LABEL type:unit
)
