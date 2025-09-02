include(FortranCInterface)

add_library(PT_Algorithm SHARED)
add_library(PT::Algorithm ALIAS PT_Algorithm)

target_compile_features(PT_Algorithm PUBLIC c_std_23)
target_compile_options(PT_Algorithm PUBLIC -pedantic -Wall -Wextra)

# range
target_sources(PT_Algorithm PRIVATE
  acquire_range.c
  acquire_range_iterator.c
  advance_range_iterator.c
  find_index.c
  release_range.c
  release_range_iterator.c
  reset_range_iterator.c
)

# blas
target_sources(PT_Algorithm PRIVATE
  dscal.c
  dscal.f90
)
FortranCInterface_HEADER(
  ${PROJECT_BINARY_DIR}/include/pt/algorithm/blas_f90.h
  SYMBOLS
  dscal
)

target_link_libraries(PT_Algorithm PT::Foundation)
target_link_libraries(PT_Algorithm PT::Container)

target_include_directories(PT_Algorithm PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(PT_Algorithm PUBLIC ${PROJECT_BINARY_DIR}/include)
