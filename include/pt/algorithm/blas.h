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
