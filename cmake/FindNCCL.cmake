set(_NCCL_INCLUDE_DIR $ENV{NCCL_INCLUDE_DIR} CACHE PATH "")
set(_NCCL_LIB_DIR $ENV{NCCL_LIB_DIR} CACHE PATH "")
set(_NCCL_VERSION $ENV{NCCL_VERSION} CACHE STRING "")
set(NCCL_LIB_NAME "nccl")

list(APPEND CMAKE_PREFIX_PATH ${NCCL_ROOT})
find_path(NCCL_INC_DIR NAMES nccl.h HINTS ${_NCCL_INCLUDE_DIR})

if(_NCCL_VERSION)
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".so.${_NCCL_VERSION}" ${CMAKE_FIND_LIBRARY_SUFFIXES})
endif()
find_library(NCCL_LIB NAMES ${NCCL_LIB_NAME} HINTS ${_NCCL_LIB_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NCCL DEFAULT_MSG NCCL_INC_DIR NCCL_LIB)

if(NCCL_FOUND)
  set(NCCL_HEADER_FILE "${NCCL_INC_DIR}/nccl.h")
  set(OLD_CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES})
  list(APPEND CMAKE_REQUIRED_INCLUDES ${NCCL_INC_DIR})

  include(CheckCXXSymbolExists)
  check_cxx_symbol_exists(NCCL_VERSION_CODE nccl.h NCCL_VERSION_DEFINED)
  if(NCCL_VERSION_DEFINED)
    set(file "${PROJECT_BINARY_DIR}/detect_nccl_version.cc")
    file(WRITE ${file} "
      #include <nccl.h>
      int main()
      {
        int vection;
        ncclGetVersion(&vection);
        return (x == NCCL_VERSION_CODE);
      }")
      try_run(NCCL_VERSION_MATCHED compile_result ${PROJECT_BINARY_DIR} ${file}
        RUN_OUTPUT_VARIABLE NCCL_VERSION_FROM_HEADER
        CMAKE_FLAGS  "-DINCLUDE_DIRECTORIES=${NCCL_INC_DIR}"
        LINK_LIBRARIES ${NCCL_LIB})
      message(STATUS "NCCL version: ${NCCL_VERSION_FROM_HEADER}")
  endif()

  set(CMAKE_REQUIRED_INCLUDES ${OLD_CMAKE_REQUIRED_INCLUDES})
  message(STATUS "Found NCCL (include: ${NCCL_INC_DIR}, library: ${NCCL_LIB})")
  mark_as_advanced(NCCL_ROOT_DIR NCCL_INC_DIR NCCL_LIB)

  add_library(NCCL::C INTERFACE IMPORTED)
  set_property(TARGET NCCL::C PROPERTY INTERFACE_COMPILE_OPTIONS -I${NCCL_INC_DIR})
  set_property(TARGET NCCL::C PROPERTY INTERFACE_LINK_LIBRARIES -L${NCCL_LIB}
endif()
