find_package(CUDAToolkit 12.0 REQUIRED)

# NCCL
set(NCCL_LIB_NAME "nccl")
set(NCCL_ROOT $ENV{NVHPC_ROOT}/comm_libs/nccl)

list(APPEND CMAKE_PREFIX_PATH ${NCCL_ROOT})
find_path(NCCL_INC_DIR NAMES nccl.h)
find_library(NCCL_LIB NAMES ${NCCL_LIB_NAME} REQUIRED)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NCCL DEFAULT_MSG NCCL_INC_DIR NCCL_LIB)

add_library(NCCL INTERFACE IMPORTED)
target_include_directories(
  NCCL
  INTERFACE
  "${CUDAToolkit_INCLUDE_DIRS}"
  "${NCCL_INC_DIR}"
)
target_link_libraries(
  NCCL
  INTERFACE
  -lcudart
  -L${CUDAToolkit_LIBRARY_DIR}
  ${NCCL_LIB}
)
