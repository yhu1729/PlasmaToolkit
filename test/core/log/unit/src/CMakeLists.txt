add_executable(emit_log test_emit_log.c)
target_link_libraries(emit_log PT::Test PT::Core)
add_test(
  NAME Core/unit/emit_log
  COMMAND ./emit_log
)
set_tests_properties(Core/unit/emit_log
  PROPERTIES LABELS
  "type:unit;module:core/log"
)

add_executable(get_verbosity_name test_get_verbosity_name.c)
target_link_libraries(get_verbosity_name PT::Test PT::Core)
add_test(
  NAME Core/unit/get_verbosity_name
  COMMAND ./get_verbosity_name
)
set_tests_properties(Core/unit/get_verbosity_name
  PROPERTIES LABELS
  "type:unit;module:core/log"
)
