add_executable(openmp_reduce test_openmp_reduce.c)
target_link_libraries(openmp_reduce PT::Test PT::Core)
add_test(
  NAME openmp/unit/reduce
  COMMAND ./openmp_reduce
)
set_tests_properties(
  openmp/unit/reduce
  PROPERTIES
  LABELS "type:unit;feature:openmp"
  ENVIRONMENT_MODIFICATION "ASAN_OPTIONS=set:detect_leaks=1"
)
