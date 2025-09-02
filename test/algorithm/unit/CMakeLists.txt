add_executable(scal scal.c)
target_link_libraries(scal PT::Algorithm)

add_test(NAME Algorithm/unit/scal
  COMMAND ./scal)
set_tests_properties(Algorithm/unit/scal
  PROPERTIES LABELS
  "type:unit;module:algorithm/blas;need:memory"
)
