cmake_minimum_required(VERSION 3.31.6)

project(PlasmaToolkit
  VERSION 0.1.0
  LANGUAGES C Fortran)

configure_file(include/pt/config.h.in include/pt/config.h @ONLY)

set(CMAKE_MESSAGE_CONTEXT_SHOW ON)

option(PT_BUILD_TYPE "Build type" "Release")
list(APPEND _pt_build_option "PT_BUILD_TYPE")

option(PT_PROCESSOR_HOST "Host processor vendor" "None")
option(PT_COMPILER_HOST "Host compiler vendor" "None")
list(APPEND _pt_build_option "PT_PROCESSOR_HOST" "PT_COMPILER_HOST")

option(PT_PROCESSOR_DEVICE "Device processor vendor" "None")
option(PT_COMPILER_DEVICE "Device compiler vendor" "None")
list(APPEND _pt_build_option "PT_PROCESSOR_DEVICE" "PT_COMPILER_DEVICE")

option(PT_CANARY "Canary level" 0)
option(PT_VERBOSITY "Verbosity level" 0)
list(APPEND _pt_build_option "PT_CANARY" "PT_VERBOSITY")

option(PT_USE_MPI "Use MPI features" ON)
option(PT_USE_NCCL "Use NCCL features" ON)
list(APPEND _pt_build_option "PT_USE_MPI" "PT_USE_NCCL")

# display build options
list(APPEND CMAKE_MESSAGE_CONTEXT "PlasmaToolkit")
message(STATUS "Build options:")
list(APPEND CMAKE_MESSAGE_INDENT "  ")
foreach(target ${_pt_build_option})
  message(STATUS "${target}=${${target}}")
endforeach()
list(POP_BACK CMAKE_MESSAGE_INDENT)
list(POP_BACK CMAKE_MESSAGE_CONTEXT)

add_subdirectory(src)

add_library(PT INTERFACE)
target_link_libraries(PT
  INTERFACE
  PT::Core
  PT::Test
  PT::Profile
  PT::Container
  PT::IO
  PT::Algorithm
  PT::Method
  PT::Application
)

add_subdirectory(example)

enable_testing()
add_subdirectory(test)
