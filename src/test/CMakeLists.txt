add_library(PT_Test SHARED)
add_library(PT::Test ALIAS PT_Test)
target_link_libraries(PT_Test PUBLIC PT::Core)

target_link_libraries(PT_Test PUBLIC PT::Dependency)

add_subdirectory(check)
add_subdirectory(expect)
add_subdirectory(unit)
add_subdirectory(benchmark)
