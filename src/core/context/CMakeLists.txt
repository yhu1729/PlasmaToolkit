target_sources(PT_Core PRIVATE
  acquire_context.c
  release_context.c
  initialize_context.c
  finalize_context.c
  initialize_context_api.c
  finalize_context_api.c
)

add_subdirectory(local)
add_subdirectory(mpi)
add_subdirectory(nccl)
