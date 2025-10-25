add_library(PT_Profile SHARED)
add_library(PT::Profile ALIAS PT_Profile)
target_link_libraries(PT_Profile PUBLIC PT::Core)

set_property(TARGET PT_Profile PROPERTY C_STANDARD 23)
set_property(TARGET PT_Profile PROPERTY C_STANDARD_REQUIRED ON)
target_compile_options(
  PT_Profile
  PUBLIC
  -pedantic
  -Werror
  -Wall
  -Wextra
  -Wno-c23-extensions
  -Wno-variadic-macro-arguments-omitted
)
target_include_directories(PT_Profile PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

if(PT_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(
    PT_Profile
    PUBLIC
    -g
    -O0
    -fsanitize=address,undefined,leak
    -fno-omit-frame-pointer
  )
  target_link_options(
    PT_Profile
    PUBLIC
    -fsanitize=address,undefined,leak
  )
endif()

if(PT_USE_MPI)
  find_package(MPI REQUIRED)
  target_link_libraries(PT_Profile PUBLIC MPI::MPI_C)
endif()

add_subdirectory(timer)
add_subdirectory(tracker)
