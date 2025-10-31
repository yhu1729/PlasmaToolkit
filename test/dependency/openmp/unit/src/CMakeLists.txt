pt_add_test(
  NAME openmp_reduce
  MODULE dependency/openmp
  LIB PT::Test PT::Dependency
  USE_ASAN YES
  LABEL type:unit feature:openmp
)
