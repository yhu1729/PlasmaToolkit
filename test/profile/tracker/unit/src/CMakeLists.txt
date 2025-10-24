add_executable(acquire_tracker test_acquire_tracker.c)
target_link_libraries(acquire_tracker PT::Test PT::Profile)
add_test(
  NAME profile/unit/acquire_tracker
  COMMAND ./acquire_tracker
)
set_tests_properties(
  profile/unit/acquire_tracker
  PROPERTIES
  LABELS "type:unit;module:profile/tracker"
)
