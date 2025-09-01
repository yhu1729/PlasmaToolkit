add_executable(fetch_vector_element fetch_vector_element.c)
target_link_libraries(fetch_vector_element PT::Container)

add_test(NAME Container/unit/fetch_vector_element
  COMMAND ./fetch_vector_element)
