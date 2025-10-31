pt_add_test(
  NAME acquire_tracker
  MODULE profile/tracker
  LIB PT::Test PT::Profile
  USE_ASAN YES
  LABEL type:unit
)
