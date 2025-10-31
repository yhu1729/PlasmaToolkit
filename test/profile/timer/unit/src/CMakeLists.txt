pt_add_test(
  NAME acquire_timer
  MODULE profile/timer
  LIB PT::Test PT::Profile
  USE_ASAN YES
  LABEL type:unit
)
