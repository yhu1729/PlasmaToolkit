add_library(PT_Test SHARED)
add_library(PT::Test ALIAS PT_Test)
target_link_libraries(PT_Test PUBLIC PT::Core)

set_property(TARGET PT_Test PROPERTY C_STANDARD 23)
set_property(TARGET PT_Test PROPERTY C_STANDARD_REQUIRED ON)
target_compile_options(
  PT_Test
  PUBLIC
  -pedantic
  -Wall
  -Wextra
)
target_include_directories(PT_Test PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

if(PT_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(
    PT_Test
    PUBLIC
    -g
    -O0
    -fsanitize=address,undefined,leak
    -fno-omit-frame-pointer
  )
  target_link_options(
    PT_Test
    PUBLIC
    -fsanitize=address,undefined,leak
  )
endif()

add_subdirectory(check)
add_subdirectory(expect)
add_subdirectory(unit)
add_subdirectory(benchmark)
