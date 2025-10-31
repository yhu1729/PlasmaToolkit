pt_add_test(
  NAME get_status_name
  MODULE core/status
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME ignore
  MODULE core/status
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME abort
  MODULE core/status
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME abort_skip
  MODULE core/status
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
