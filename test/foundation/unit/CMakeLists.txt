add_executable(get_error_message get_error_message.c)
target_link_libraries(get_error_message PT::Foundation)

add_test(NAME Foundation/unit/get_error_message
  COMMAND ./get_error_message)
