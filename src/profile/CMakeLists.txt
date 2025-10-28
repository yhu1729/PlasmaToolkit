add_library(PT_Profile SHARED)
add_library(PT::Profile ALIAS PT_Profile)
target_link_libraries(PT_Profile PUBLIC PT::Core)

target_link_libraries(PT_Profile PUBLIC PT::Dependency)

add_subdirectory(timer)
add_subdirectory(tracker)
