add_library(PT_Foundation SHARED)
add_library(PT::Foundation ALIAS PT_Foundation)

target_compile_features(PT_Foundation PUBLIC c_std_11)

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
  free_impl.c
  get_error_message.c
  malloc_impl.c
)

# io
target_sources(PT_Foundation PRIVATE
  log.c
)

target_include_directories(PT_Foundation PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(PT_Foundation PUBLIC ${PROJECT_BINARY_DIR}/include)
