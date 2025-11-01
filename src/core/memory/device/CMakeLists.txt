if(PT_USE_CUDA)
  target_sources(PT_Core
    PRIVATE
    free_d_impl.c
  )
endif()
