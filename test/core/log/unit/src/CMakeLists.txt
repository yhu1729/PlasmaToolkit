pt_add_test(
  NAME emit_log
  MODULE core/log
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME get_verbosity_name
  MODULE core/log
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
