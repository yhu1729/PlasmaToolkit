cmake_minimum_required(VERSION 4.0.0)

project(PlasmaToolkit
  VERSION 0.1.0
  LANGUAGES C CXX Fortran)

add_subdirectory(src)
add_subdirectory(example)

enable_testing()
add_subdirectory(test)
