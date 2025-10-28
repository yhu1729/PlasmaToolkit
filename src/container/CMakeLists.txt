add_library(PT_Container SHARED)
add_library(PT::Container ALIAS PT_Container)

target_link_libraries(PT_Container PUBLIC PT::Dependency)

add_subdirectory(buffer)
add_subdirectory(vector)
add_subdirectory(matrix)
add_subdirectory(pool)
add_subdirectory(tree)
add_subdirectory(grid)
