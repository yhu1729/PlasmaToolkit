find_package(CUDAToolkit REQUIRED)

set(NCCL_LIB_NAME "nccl")
set(NCCL_ROOT $ENV{NVHPC_ROOT}/comm_libs/nccl)

find_path(NCCL_INC_DIR NAMES nccl.h)
find_library(NCCL_LIB NAMES ${NCCL_LIB_NAME})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NCCL DEFAULT_MSG NCCL_INC_DIR NCCL_LIB)

if(NCCL_FOUND)
  set(NCCL_HEADER_FILE "${NCCL_INC_DIR}/nccl.h")
  set(OLD_CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES})
  list(APPEND CMAKE_REQUIRED_INCLUDES ${NCCL_INC_DIR})

  include(CheckCXXSymbolExists)
  check_cxx_symbol_exists(NCCL_VERSION_CODE nccl.h NCCL_VERSION_DEFINED)
  if(NCCL_VERSION_DEFINED)
    set(_file "${PROJECT_BINARY_DIR}/check_NCCL.cpp")
    file(WRITE ${file} "
      #include <nccl.h>
      int main()
      {
        int vection;
        ncclGetVersion(&vection);
        return (x == NCCL_VERSION_CODE);
      }")
      try_run(
        _run_result _compile_result
        ${PROJECT_BINARY_DIR} ${_file}
        RUN_OUTPUT_VARIABLE NCCL_VERSION
        CMAKE_FLAGS  "-DINCLUDE_DIRECTORIES=${NCCL_INC_DIR}"
        LINK_LIBRARIES ${NCCL_LIB})
      message(STATUS "NCCL version: ${NCCL_VERSION}")
  endif()

  set(CMAKE_REQUIRED_INCLUDES ${OLD_CMAKE_REQUIRED_INCLUDES})

  add_library(NCCL INTERFACE)
  set_property(TARGET NCCL PROPERTY INTERFACE_COMPILE_OPTIONS -I${NCCL_INC_DIR} -I${CUDAToolkit_INCLUDE_DIRS})
  set_property(TARGET NCCL PROPERTY INTERFACE_LINK_LIBRARIES -L${NCCL_LIB} -L${CUDAToolkit_LIBRARY_DIR})
endif()
