# scal
add_executable(scal scal.c)
target_link_libraries(scal PT::Algorithm)
add_test(NAME Algorithm/unit/scal
  COMMAND ./scal)
set_tests_properties(Algorithm/unit/scal
  PROPERTIES LABELS
  "type:unit;module:algorithm/blas"
)

# getrf
add_executable(getrf getrf.c)
target_link_libraries(getrf PT::Algorithm)
add_test(NAME Algorithm/unit/getrf
  COMMAND ./getrf)
set_tests_properties(Algorithm/unit/getrf
  PROPERTIES LABELS
  "type:unit;module:algorithm/lapack"
)

# linear_solver
add_executable(linear_solver linear_solver.c)
target_link_libraries(linear_solver PT::Algorithm)
add_test(NAME Algorithm/unit/linear_solver
  COMMAND ./linear_solver)
set_tests_properties(Algorithm/unit/linear_solver
  PROPERTIES LABELS
  "type:unit;module:algorithm/linear_solver"
)
