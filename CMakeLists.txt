cmake_minimum_required(VERSION 4.0.0)

project(PlasmaToolkit
  VERSION 0.1.0
  LANGUAGES C CXX Fortran)

configure_file(include/pt/config.h.in include/pt/config.h @ONLY)

add_subdirectory(src)

add_library(PT INTERFACE)
target_link_libraries(PT INTERFACE
  PT::Foundation
  PT::Container
  PT::Algorithm
)

add_subdirectory(example)

enable_testing()
add_subdirectory(test)
