pt_add_test(
  NAME print_backtrace
  MODULE core/backtrace
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
