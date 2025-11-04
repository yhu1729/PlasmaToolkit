#include <mpi.h>
#include <stdarg.h>
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
  printf("%s [server] ", time_buf);

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

  MPI_Info info;
  MPI_Info_create(&info);
  MPI_Info_set(info, "ompi_global_scope", "true");
  char name[MPI_MAX_PORT_NAME];
  record("open port");
  MPI_Open_port(info, name);
  record("publish service");
  MPI_Publish_name("test", info, name);

  MPI_Comm client;
  int buffer[1];
  MPI_Status status;
  bool stop = false;
  while (!stop) {
    record("wait for connections");
    MPI_Comm_accept(name, info, 0, MPI_COMM_WORLD, &client);
    bool accept = true;
    while (accept) {
      record("wait for messages");
      MPI_Recv(
        buffer, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, client, &status);
      record("receive message: %d", buffer[0]);
      if (!status.MPI_TAG) {
        record("stop");
        MPI_Comm_disconnect(&client);
        MPI_Close_port(name);
        stop = true;
        accept = false;
      }
    }
  }

  record("unpublish service");
  MPI_Unpublish_name("test", info, name);
  record("finalize");
  MPI_Finalize();

  return EXIT_SUCCESS;
}
