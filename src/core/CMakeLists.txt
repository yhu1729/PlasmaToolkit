add_library(PT_Core SHARED)
add_library(PT::Core ALIAS PT_Core)

set_property(TARGET PT_Core PROPERTY C_STANDARD 23)
set_property(TARGET PT_Core PROPERTY C_STANDARD_REQUIRED ON)
target_compile_options(
  PT_Core
  PUBLIC
  -pedantic
  -Werror
  -Wall
  -Wextra
  -Wno-c23-extensions
  -Wno-variadic-macro-arguments-omitted
)
target_include_directories(PT_Core PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

if(PT_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(
    PT_Core
    PUBLIC
    -g
    -O0
    -fsanitize=address,undefined,leak
    -fno-omit-frame-pointer
  )
  target_link_options(
    PT_Core
    PUBLIC
    -fsanitize=address,undefined,leak
  )
endif()

find_package(OpenMP 5.0 COMPONENTS C Fortran REQUIRED)
target_link_libraries(PT_Core PUBLIC OpenMP::OpenMP_C)

find_package(MPI REQUIRED)
target_link_libraries(PT_Core PUBLIC MPI::MPI_C)

add_subdirectory(version)
add_subdirectory(tag)
add_subdirectory(log)
add_subdirectory(backtrace)
add_subdirectory(status)
add_subdirectory(memory)
add_subdirectory(context)
add_subdirectory(math)
