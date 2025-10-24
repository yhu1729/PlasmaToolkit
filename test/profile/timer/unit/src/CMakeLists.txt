add_executable(acquire_timer test_acquire_timer.c)
target_link_libraries(acquire_timer PT::Test PT::Profile)
add_test(
  NAME profile/unit/acquire_timer
  COMMAND ./acquire_timer
)
set_tests_properties(
  profile/unit/acquire_timer
  PROPERTIES
  LABELS "type:unit;module:profile/timer"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)
