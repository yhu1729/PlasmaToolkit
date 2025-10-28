add_library(PT_Dependency INTERFACE)
add_library(PT::Dependency ALIAS PT_Dependency)

target_include_directories(
  PT_Dependency
  INTERFACE
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

if(PT_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(
    PT_Dependency
    INTERFACE
    -pedantic
    -Wall
    -Wextra
    -Werror
    -g
    -O0
    -fno-omit-frame-pointer
  )

  if(CMAKE_C_COMPILER_ID MATCHES Clang)
    target_compile_options(
      PT_Dependency
      INTERFACE
      -Wno-variadic-macro-arguments-omitted
      -fsanitize=address,undefined,leak
    )
    target_link_options(
      PT_Dependency
      INTERFACE
      -fsanitize=address,undefined,leak
    )
  elseif(CMAKE_C_COMPILER_ID MATCHES GNU)
    target_compile_options(
      PT_Dependency
      INTERFACE
      -Wno-error=address
    )
  else()
    message(FATAL_ERROR "${CMAKE_C_COMPILER_ID} C compiler is not supported.")
  endif()
endif()

find_package(PkgConfig REQUIRED)

# MPI
find_package(MPI 3.0 REQUIRED)

# OpenMP
find_package(OpenMP 4.0 COMPONENTS C REQUIRED)

# netCDF
pkg_check_modules(netCDF REQUIRED IMPORTED_TARGET netcdf>=4.0)

# NCCL
if(PT_USE_NCCL)
  find_package(NCCL 2.0 REQUIRED)
  target_link_libraries(PT_Dependency INTERFACE NCCL::NCCL_C)
endif()

target_link_libraries(PT_Dependency INTERFACE MPI::MPI_C)
target_link_libraries(PT_Dependency INTERFACE OpenMP::OpenMP_C)
target_link_libraries(PT_Dependency INTERFACE PkgConfig::netCDF)
