add_executable(PT_Example_hello)

target_sources(PT_Example_hello PRIVATE main.c)

target_link_libraries(PT_Example_hello PT::Foundation)
