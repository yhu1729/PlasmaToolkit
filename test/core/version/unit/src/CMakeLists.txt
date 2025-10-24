add_executable(print_version test_print_version.c)
target_link_libraries(print_version PT::Test PT::Core)
add_test(
  NAME core/unit/print_version
  COMMAND ./print_version
)
set_tests_properties(
  core/unit/print_version
  PROPERTIES
  LABELS "type:unit;module:core/version"
)
