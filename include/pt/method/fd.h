#pragma once

#include "pt/algorithm/range.h"
#include "pt/container/matrix.h"
#include "pt/foundation/context.h"

struct _pt_fd_mesh_t {
  pt_context context;
  int variable;
  int dimension;

  pt_range range;
  pt_matrix(double) content;
};
typedef struct _pt_fd_mesh_t* pt_fd_mesh;

pt_error acquire_fd_mesh(
  pt_fd_mesh target[1], const pt_context context, int variable, int dimension,
  size_t* resolution, size_t* halo);
pt_error release_fd_mesh(pt_fd_mesh);

typedef pt_error (*_pt_fd_operator_central_t)(
  pt_context context, double* result, size_t size, const double* f,
  double* work);
typedef pt_error (*_pt_fd_operator_forward_t)(
  pt_context context, double* result, size_t size, const double* f,
  double* work);
typedef pt_error (*_pt_fd_operator_backward_t)(
  pt_context context, double* result, size_t size, const double* f,
  double* work);

struct _pt_fd_operator_t {
  struct {
    size_t addition;
    size_t multiplication;
    size_t copy;
  } count;

  _pt_fd_operator_central_t central_1_2;
  _pt_fd_operator_central_t central_1_4;
  _pt_fd_operator_central_t central_2_2;
  _pt_fd_operator_central_t central_2_4;
  _pt_fd_operator_forward_t forward_1_1;
  _pt_fd_operator_forward_t forward_1_2;
  _pt_fd_operator_forward_t forward_1_3;
  _pt_fd_operator_forward_t forward_1_4;
  _pt_fd_operator_forward_t forward_2_1;
  _pt_fd_operator_forward_t forward_2_2;
  _pt_fd_operator_forward_t forward_2_3;
  _pt_fd_operator_forward_t forward_2_4;
  _pt_fd_operator_backward_t backward_1_1;
  _pt_fd_operator_backward_t backward_1_2;
  _pt_fd_operator_backward_t backward_1_3;
  _pt_fd_operator_backward_t backward_1_4;
  _pt_fd_operator_backward_t backward_2_1;
  _pt_fd_operator_backward_t backward_2_2;
  _pt_fd_operator_backward_t backward_2_3;
  _pt_fd_operator_backward_t backward_2_4;
};
typedef struct _pt_fd_operator_t* pt_fd_operator;

pt_error acquire_fd_operator(pt_fd_operator target[1]);
pt_error release_fd_operator(pt_fd_operator target);
