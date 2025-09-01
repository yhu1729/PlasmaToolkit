add_library(PT_Foundation SHARED)
add_library(PT::Foundation ALIAS PT_Foundation)

target_compile_features(PT_Foundation PUBLIC c_std_11)

target_sources(PT_Foundation PRIVATE
  acquire_context.c
  acquire_context_impl_local.c
  get_context_id.c
  get_context_size.c
  get_error_message.c
  invoke_impl.c
  log.c
  release_context.c
  set_context_id.c)

target_include_directories(PT_Foundation PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(PT_Foundation PUBLIC ${PROJECT_BINARY_DIR}/include)
