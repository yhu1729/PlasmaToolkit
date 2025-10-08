add_executable(get_status_name test_get_status_name.c)
target_link_libraries(get_status_name PT::Test PT::Core)
add_test(
  NAME Core/unit/get_status_name
  COMMAND ./get_status_name
)
set_tests_properties(Core/unit/get_status_name
  PROPERTIES
  LABELS "type:unit;module:core/status"
)

add_executable(ignore test_ignore.c)
target_link_libraries(ignore PT::Test PT::Core)
add_test(
  NAME Core/unit/ignore
  COMMAND ./ignore
)
set_tests_properties(Core/unit/ignore
  PROPERTIES
  LABELS "type:unit;module:core/status"
)

add_executable(abort test_abort.c)
target_link_libraries(abort PT::Test PT::Core)
add_test(
  NAME Core/unit/abort
  COMMAND ./abort
)
set_tests_properties(Core/unit/abort
  PROPERTIES
  LABELS "type:unit;module:core/status"
)

add_executable(abort_skip test_abort_skip.c)
target_link_libraries(abort_skip PT::Test PT::Core)
add_test(
  NAME Core/unit/abort_skip
  COMMAND ./abort_skip
)
set_tests_properties(Core/unit/abort_skip
  PROPERTIES
  LABELS "type:unit;module:core/status"
)
