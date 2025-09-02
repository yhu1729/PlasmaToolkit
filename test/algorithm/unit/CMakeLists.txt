add_executable(scal scal.c)
target_link_libraries(scal PT::Algorithm)

add_test(NAME Algorithm/unit/scal
  COMMAND ./scal)
