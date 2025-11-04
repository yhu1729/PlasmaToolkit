add_executable(mpi_server mpi_server.c)
add_executable(mpi_client mpi_client.c)
target_link_libraries(mpi_server PT::Core)
target_link_libraries(mpi_client PT::Core)
