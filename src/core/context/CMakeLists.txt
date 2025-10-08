target_sources(PT_Core PRIVATE
  acquire_context.c
  release_context.c
)

add_subdirectory(local)
add_subdirectory(mpi)
add_subdirectory(nccl)
