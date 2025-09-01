add_library(PT_Container SHARED)
add_library(PT::Container ALIAS PT_Container)

target_compile_features(PT_Container PUBLIC c_std_23)

target_sources(PT_Container PRIVATE
  acquire_buffer.c
  release_buffer.c)

target_include_directories(PT_Container PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(PT_Container PUBLIC ${PROJECT_BINARY_DIR}/include)
