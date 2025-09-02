#pragma once

typedef pt_error (*_pt_rk_operator_erk_t)(
  pt_context context, double* result, size_t size, const double* rhs,
  double* work);

struct _pt_rk_operator_t {
  _pt_rk_operator_erk_t erk_1;
  _pt_rk_operator_erk_t erk_2;
  _pt_rk_operator_erk_t erk_3;
  _pt_rk_operator_erk_t erk_4;
};
typedef struct _pt_rk_operator_erk_1_t* pt_rk_operator;

pt_error acquire_rk_operator(pt_rk_operator target[1]);
pt_error release_rk_operator(pt_rk_operator);
