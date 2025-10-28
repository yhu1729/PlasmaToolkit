add_library(PT_Container SHARED)
add_library(PT::Container ALIAS PT_Container)

set_property(TARGET PT_Container PROPERTY C_STANDARD 23)
set_property(TARGET PT_Container PROPERTY C_STANDARD_REQUIRED ON)
target_compile_options(
  PT_Container
  PUBLIC
  -pedantic
  -Werror
  -Wall
  -Wextra
  -Wno-c23-extensions
  -Wno-variadic-macro-arguments-omitted
)
target_include_directories(
  PT_Container
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

if(PT_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(
    PT_Container
    PUBLIC
    -g
    -O0
    -fsanitize=address,undefined,leak
    -fno-omit-frame-pointer
  )
  target_link_options(
    PT_Container
    PUBLIC
    -fsanitize=address,undefined,leak
  )
endif()

target_link_libraries(PT_Container PUBLIC PT::Dependency)

add_subdirectory(buffer)
add_subdirectory(vector)
add_subdirectory(matrix)
add_subdirectory(pool)
add_subdirectory(tree)
add_subdirectory(grid)
