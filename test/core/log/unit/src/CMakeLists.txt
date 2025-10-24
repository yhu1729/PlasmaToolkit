add_executable(emit_log test_emit_log.c)
target_link_libraries(emit_log PT::Test PT::Core)
add_test(
  NAME core/unit/emit_log
  COMMAND ./emit_log
)
set_tests_properties(
  core/unit/emit_log
  PROPERTIES
  LABELS "type:unit;module:core/log"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)

add_executable(get_verbosity_name test_get_verbosity_name.c)
target_link_libraries(get_verbosity_name PT::Test PT::Core)
add_test(
  NAME core/unit/get_verbosity_name
  COMMAND ./get_verbosity_name
)
set_tests_properties(
  core/unit/get_verbosity_name
  PROPERTIES
  LABELS "type:unit;module:core/log"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)
