pt_add_test(
  NAME print_version
  MODULE core/version
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
