add_library(PT_Container SHARED)
add_library(PT::Container ALIAS PT_Container)

target_compile_features(PT_Container PUBLIC c_std_23)
target_compile_options(PT_Container PUBLIC -pedantic -Wall -Wextra)
target_compile_options(PT_Container PUBLIC
  -Wno-gnu-statement-expression-from-macro-expansion
  -Wno-zero-length-array
)

# buffer
target_sources(PT_Container PRIVATE
  acquire_buffer.c
  fetch_buffer_element_impl.c
  release_buffer.c
)

target_link_libraries(PT_Container PT::Foundation)

target_include_directories(PT_Container PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(PT_Container PUBLIC ${PROJECT_BINARY_DIR}/include)
