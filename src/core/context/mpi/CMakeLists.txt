if(PT_USE_MPI)
target_sources(PT_Core PRIVATE
  acquire_context_mpi.c
  release_context_mpi.c
  initialize_context_mpi.c
  finalize_context_mpi.c
)
endif()
