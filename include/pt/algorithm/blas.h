#pragma once

#include "pt/foundation/tag.h"
#include <stdlib.h>

// level 1: dscal
#define dscal(...) dscal_(__VA_ARGS__)
extern void dscal_(int* n, double* a, double* x, int* inc_x);
pt_error pt_dscal(int n, double a, double* x, int inc_x);

// level 3: dgemm
#define dgemm(...) dgemm_(__VA_ARGS__)
extern void dgemm_(
  char* transpose_A, char* transpose_B, int* m, int* n, int* k, double* alpha,
  double* A, int* ld_A, double* B, int* ld_B, double* beta, double* C,
  int* ld_C);
pt_error pt_dgemm(
  char* transpose_A, char* transpose_B, int m, int n, int k, double alpha,
  double* A, int ld_A, double* B, int ld_B, double beta, double* C, int ld_C);

// level 1: scal
#define pt_scal(_n, _a, _x, _inc_x) \
  _Generic((_a), double: pt_dscal)((_n), (_a), (_x), (_inc_x))

// level 3: gemm
#define pt_gemm( \
  _transpose_A, _transpose_B, _m, _n, _k, _alpha, _A, _ld_A, _B, _ld_B, \
  _beta, _C, _ld_C) \
  _Generic((_alpha), double: pt_dgemm)( \
    (_transpose_A), (_transpose_B), (_m), (_n), (_k), (_alpha), (_A), \
    (_ld_A), (_B), (_ld_B), (_beta), (_C), (_ld_C))
