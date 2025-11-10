add_executable(example_mpi_server mpi_server.c)
add_executable(example_mpi_client mpi_client.c)
target_link_libraries(example_mpi_server PT::Core)
target_link_libraries(example_mpi_client PT::Core)
