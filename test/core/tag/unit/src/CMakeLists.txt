add_executable(get_tag_name test_get_tag_name.c)
target_link_libraries(get_tag_name PT::Test PT::Core)
add_test(
  NAME core/unit/get_tag_name
  COMMAND ./get_tag_name
)
set_tests_properties(
  core/unit/get_tag_name
  PROPERTIES
  LABELS "type:unit;module:core/tag"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)
