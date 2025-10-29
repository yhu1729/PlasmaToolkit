#include "pt/core/type.h"
#include <mpi.h>
#include <netcdf.h>
#include <stdio.h>
#include <stdlib.h>

struct c_t {
  pt_u64 x;
  pt_u64 y;
};

int
main(int argc, char** argv) {
  MPI_Init(&argc, &argv);

  int mpi_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);

  pt_u64 data[4][16];
  struct c_t data_compound[4][16];
  for (pt_u64 x = 0; x < 4; ++x) {
    for (pt_u64 y = 0; y < 16; ++y) {
      data[x][y] = x * 4 + y;
      data_compound[x][y].x = x;
      data_compound[x][y].y = y;
    }
  }

  int id_file;
  char filename[32];
  sprintf(filename, "test.%d.nc", mpi_rank);
  nc_create(filename, NC_NETCDF4 | NC_CLOBBER, &id_file);

  int id_dim[2];
  nc_def_dim(id_file, "x", 4, &(id_dim[0]));
  nc_def_dim(id_file, "y", 12, &(id_dim[1]));

  int id_group[2];
  nc_def_grp(id_file, "group_1", &(id_group[0]));
  nc_def_grp(id_file, "group_2", &(id_group[1]));

  int id_variable[2];
  nc_def_var(id_group[0], "data", NC_UINT64, 2, id_dim, &(id_variable[0]));
  int id_compound;

  nc_def_compound(
    id_group[1], sizeof(struct c_t), "compound_data", &id_compound);
  nc_insert_compound(
    id_group[1], id_compound, "x", offsetof(struct c_t, x), NC_INT);
  nc_insert_compound(
    id_group[1], id_compound, "y", offsetof(struct c_t, y), NC_INT);
  nc_def_var(id_group[1], "data", id_compound, 2, id_dim, &(id_variable[1]));

  nc_put_var(id_group[0], id_variable[0], &(data[0][0]));
  nc_put_var(id_group[1], id_variable[1], &(data_compound[0][0]));

  nc_close(id_file);

  MPI_Finalize();

  return EXIT_SUCCESS;
}
