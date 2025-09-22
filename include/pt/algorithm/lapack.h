#pragma once

#include "pt/foundation/tag.h"

// driver: dgesv
#define dgesv(...) dgesv_(__VA_ARGS__)
extern void dgesv_(
  int* n, int* n_rhs, double* A, int* ld_A, int* pivot, double* B, int* ld_B,
  int* info);
pt_error pt_dgesv(
  int n, int n_rhs, double* A, int ld_A, int* pivot, double* B, int ld_B);

// computation: dgetrf
#define dgetrf(...) dgetrf_(__VA_ARGS__)
extern void
dgetrf_(int* m, int* n, double* A, int* ld_A, int* pivot, int* info);
pt_error pt_dgetrf(int m, int n, double* A, int ld_A, int* pivot);

// computation: dgetrs
#define dgetrs(...) dgetrs_(__VA_ARGS__)
extern void dgetrs_(
  char* transpose, int* n, int* n_rhs, double* A, int* ld_A, int* pivot,
  double* B, int* ld_B, int* info);
pt_error pt_dgetrs(
  char* transpose, int n, int n_rhs, double* A, int ld_A, int* pivot,
  double* B, int ld_B);

// driver: gesv
#define pt_gesv(_n, _n_rhs, _A, _ld_A, _pivot, _B, _ld_B) \
  _Generic((*(_A)), double: pt_dgesv)( \
    (_n), (_n_rhs), (_A), (_ld_A), (_pivot), (_B), (_ld_B))

// driver: getrf
#define pt_getrf(_m, _n, _A, _ld_A, _pivot) \
  _Generic((*(_A)), double: pt_dgetrf)((_m), (_n), (_A), (_ld_A), (_pivot))

// driver: getrs
#define pt_getrs(_transpose, _n, _n_rhs, _A, _ld_A, _pivot, _B, _ld_B) \
  _Generic((*(_A)), double: pt_dgetrs)( \
    (_transpose), (_n), (_n_rhs), (_A), (_ld_A), (_pivot), (_B), (_ld_B))
