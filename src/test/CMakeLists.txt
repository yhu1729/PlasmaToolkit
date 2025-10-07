add_library(PT_Test SHARED)
add_library(PT::Test ALIAS PT_Test)
target_link_libraries(PT_Test PUBLIC PT::Core)

set_property(TARGET PT_Test PROPERTY C_STANDARD 23)
set_property(TARGET PT_Test PROPERTY C_STANDARD_REQUIRED ON)
target_compile_options(PT_Test PUBLIC
  -pedantic
  -Wall
  -Wextra
)
target_include_directories(PT_Test PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

add_subdirectory(assert)
add_subdirectory(invoke)
add_subdirectory(unit)
add_subdirectory(benchmark)
