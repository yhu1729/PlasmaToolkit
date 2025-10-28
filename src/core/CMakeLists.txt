add_library(PT_Core SHARED)
add_library(PT::Core ALIAS PT_Core)

target_link_libraries(PT_Core PUBLIC PT::Dependency)

add_subdirectory(version)
add_subdirectory(tag)
add_subdirectory(log)
add_subdirectory(backtrace)
add_subdirectory(status)
add_subdirectory(memory)
add_subdirectory(context)
add_subdirectory(math)
