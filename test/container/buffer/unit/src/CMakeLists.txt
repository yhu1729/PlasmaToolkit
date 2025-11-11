pt_add_test(
  NAME acquire_buffer_h
  MODULE container/buffer
  LIB PT::Test PT::Container
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME release_buffer_h
  MODULE container/buffer
  LIB PT::Test PT::Container
  USE_ASAN YES
  LABEL type:unit
)
pt_add_test(
  NAME acquire_buffer_d
  MODULE container/buffer
  LIB PT::Test PT::Container
  USE_CUDA YES
  CUDA_KERNEL fill
  USE_ASAN YES
  LABEL type:unit
)
