add_executable(get_sign test_get_sign.c)
target_link_libraries(get_sign PT::Test PT::Core)
add_test(
  NAME Core/unit/get_sign
  COMMAND ./get_sign
)
set_tests_properties(Core/unit/get_sign
  PROPERTIES
  LABELS "type:unit;module:core/math"
)
