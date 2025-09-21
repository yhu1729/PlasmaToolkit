add_library(PT_Foundation SHARED)
add_library(PT::Foundation ALIAS PT_Foundation)

target_compile_features(PT_Foundation PUBLIC c_std_23)
target_compile_options(PT_Foundation PUBLIC -pedantic -Wall -Wextra)

# error
target_sources(PT_Foundation PRIVATE
  invoke_impl.c
)

# context
target_sources(PT_Foundation PRIVATE
  acquire_context.c
  acquire_context_impl_local.c
  get_context_id.c
  get_context_size.c
  release_context.c
  set_context_id.c
)

# memory
target_sources(PT_Foundation PRIVATE
  aligned_alloc_impl.c
  calloc_impl.c
  free_impl.c
  get_error_message.c
  malloc_impl.c
)

# io
target_sources(PT_Foundation PRIVATE
  log.c
)

# math
target_sources(PT_Foundation PRIVATE
  sign_double.c
  sign_float.c
)

# test
target_sources(PT_Foundation PRIVATE
  test_assert_equal_impl_int.c
  test_assert_equal_impl_double.c
  test_assert_impl.c
  test_invoke_impl.c
)

target_include_directories(PT_Foundation PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(PT_Foundation PUBLIC ${PROJECT_BINARY_DIR}/include)
