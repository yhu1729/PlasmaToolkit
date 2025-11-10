#include <mpi.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
record(const char* format, ...) {
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  char time_buf[100];
  size_t rc = strftime(time_buf, sizeof time_buf, "%D %T", gmtime(&ts.tv_sec));
  snprintf(
    time_buf + rc, sizeof time_buf - rc, ".%06ld UTC", ts.tv_nsec / 1000);
  printf("%s [client] ", time_buf);

  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  puts("");
  va_end(arg);
}

int
main(int argc, char** argv) {
  record("initialize");
  MPI_Init(&argc, &argv);

  MPI_Comm server;
  char name[MPI_MAX_PORT_NAME];
  int buffer[1];

  record("lookup service");
  MPI_Lookup_name("test", MPI_INFO_NULL, name);
  record("connect");
  MPI_Comm_connect(name, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &server);

  int repeat = 4;
  int tag = 1;
  while (repeat--) {
    buffer[0] = repeat;
    record("send message: %d", buffer[0]);
    MPI_Send(buffer, 1, MPI_INT, 0, tag, server);
  }
  tag = 0;
  record("send stop");
  MPI_Send(buffer, 0, MPI_INT, 0, tag, server);
  record("disconnect");
  MPI_Comm_disconnect(&server);
  record("finalize");
  MPI_Finalize();

  return EXIT_SUCCESS;
}
