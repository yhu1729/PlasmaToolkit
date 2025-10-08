add_executable(print_backtrace test_print_backtrace.c)
target_link_libraries(print_backtrace PT::Test PT::Core)
add_test(
  NAME Core/unit/print_backtrace
  COMMAND ./print_backtrace
)
set_tests_properties(Core/unit/print_backtrace
  PROPERTIES
  LABELS "type:unit;module:core/backtrace"
)
