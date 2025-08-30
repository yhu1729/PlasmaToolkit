add_library(PT_Foundation SHARED)
add_library(PT::Foundation ALIAS PT_Foundation)

target_compile_features(PT_Foundation PUBLIC c_std_11)

target_sources(PT_Foundation PRIVATE get_error_message.c invoke_impl.c log.c)

target_include_directories(PT_Foundation PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(PT_Foundation PUBLIC ${PROJECT_BINARY_DIR}/include)
