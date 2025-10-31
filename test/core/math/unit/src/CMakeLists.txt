pt_add_test(
  NAME get_sign
  MODULE core/math
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
