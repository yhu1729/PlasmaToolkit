add_library(PT_Core SHARED)
add_library(PT::Core ALIAS PT_Core)

set_property(TARGET PT_Core PROPERTY C_STANDARD 23)
set_property(TARGET PT_Core PROPERTY C_STANDARD_REQUIRED ON)
target_compile_options(PT_Core PUBLIC
  -pedantic
  -Wall
  -Wextra
)
target_include_directories(PT_Core PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include
)

add_subdirectory(version)
add_subdirectory(tag)
add_subdirectory(log)
add_subdirectory(backtrace)
add_subdirectory(status)
add_subdirectory(memory)
add_subdirectory(context)
add_subdirectory(math)
