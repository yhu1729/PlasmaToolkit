add_library(PT_Profile SHARED)
add_library(PT::Profile ALIAS PT_Profile)
target_link_libraries(PT_Profile PUBLIC PT::Core)

set_property(TARGET PT_Profile PROPERTY C_STANDARD 23)
set_property(TARGET PT_Profile PROPERTY C_STANDARD_REQUIRED ON)
target_compile_options(PT_Profile PUBLIC
  -pedantic
  -Wall
  -Wextra
)
target_include_directories(PT_Profile PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

if(PT_USE_MPI)
  find_package(MPI REQUIRED)
  target_link_libraries(PT_Profile PUBLIC MPI::MPI_C)
endif()

add_subdirectory(timer)
add_subdirectory(tracker)
