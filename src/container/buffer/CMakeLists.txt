add_subdirectory(host)
add_subdirectory(device)

target_sources(
  PT_Container
  PRIVATE
  acquire_buffer.c
  release_buffer.c
  send_buffer.c
  send_buffer_h2h.c
  send_buffer_h2d.c
  send_buffer_d2h.c
  send_buffer_d2d.c
)
