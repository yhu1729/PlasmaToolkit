add_library(PT_Dependency INTERFACE)
add_library(PT::Dependency ALIAS PT_Dependency)

find_package(PkgConfig REQUIRED)

# MPI
find_package(
  MPI 3.0
  REQUIRED
)

# OpenMP
find_package(
  OpenMP 4.0
  COMPONENTS C Fortran
  REQUIRED
)

# netCDF
pkg_check_modules(
  netCDF
  REQUIRED
  IMPORTED_TARGET
  netcdf>=4.0
)

target_link_libraries(
  PT_Dependency
  INTERFACE
  MPI::MPI_C
  OpenMP::OpenMP_C
  PkgConfig::netCDF
)
