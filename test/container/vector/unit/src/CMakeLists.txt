add_executable(acquire_vector_h test_acquire_vector_h.c)
target_link_libraries(acquire_vector_h PT::Test PT::Container)
add_test(
  NAME container/unit/acquire_vector_h
  COMMAND ./acquire_vector_h
)
set_tests_properties(
  container/unit/acquire_vector_h
  PROPERTIES
  LABELS "type:unit;module:container/vector"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)

add_executable(release_vector_h test_release_vector_h.c)
target_link_libraries(release_vector_h PT::Test PT::Container)
add_test(
  NAME container/unit/release_vector_h
  COMMAND ./release_vector_h
)
set_tests_properties(
  container/unit/release_vector_h
  PROPERTIES
  LABELS "type:unit;module:container/vector"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)
