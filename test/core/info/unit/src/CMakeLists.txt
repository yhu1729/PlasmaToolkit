add_executable(print_info test_print_info.c)
target_link_libraries(print_info PT::Test PT::Core)
add_test(
  NAME Core/unit/print_info
  COMMAND ./print_info
)
set_tests_properties(Core/unit/print_info
  PROPERTIES LABELS
  "type:unit;module:core/info"
)
