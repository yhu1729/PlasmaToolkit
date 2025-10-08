add_executable(free test_free.c)
target_link_libraries(free PT::Test PT::Core)
add_test(
  NAME Core/unit/free
  COMMAND ./free
)
set_tests_properties(Core/unit/free
  PROPERTIES
  LABELS "type:unit;module:core/memory"
)

add_executable(malloc test_malloc.c)
target_link_libraries(malloc PT::Test PT::Core)
add_test(
  NAME Core/unit/malloc
  COMMAND ./malloc
)
set_tests_properties(Core/unit/malloc
  PROPERTIES
  LABELS "type:unit;module:core/memory"
)
