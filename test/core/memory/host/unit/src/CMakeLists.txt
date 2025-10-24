add_executable(free test_free.c)
target_link_libraries(free PT::Test PT::Core)
add_test(
  NAME core/unit/free
  COMMAND ./free
)
set_tests_properties(
  core/unit/free
  PROPERTIES
  LABELS "type:unit;module:core/memory"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)

add_executable(malloc test_malloc.c)
target_link_libraries(malloc PT::Test PT::Core)
add_test(
  NAME core/unit/malloc
  COMMAND ./malloc
)
set_tests_properties(
  core/unit/malloc
  PROPERTIES
  LABELS "type:unit;module:core/memory"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)

add_executable(calloc test_calloc.c)
target_link_libraries(calloc PT::Test PT::Core)
add_test(
  NAME core/unit/calloc
  COMMAND ./calloc
)
set_tests_properties(
  core/unit/calloc
  PROPERTIES
  LABELS "type:unit;module:core/memory"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)
