#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

void imprime_matriz(long double **A, int n);
void imprime_vetor(long double *v, int n);
long double norma_infinita(long double *xk, long double *x, int n);
long double *gauss_seidel(long double **A, long double *b, long double *x, int n, long double e, int itmax);

#endif
