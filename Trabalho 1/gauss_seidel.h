/**
 *	Trabalho 1 -  Métodos Iterativos para  Sitemas Lineares
 *
 *		Cálculo Numérico	SME-0104
 *		Prof.: Murilo Francisco Tomé
 *
 *		Eduardo Brunaldi dos Santos             8642515
 *		Jorge Ashkar Ferreira Simondi           8517081
 *		Victor Luiz da Silva Mariano Pereira    8602444
 */

#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

/**
 * Função para imprimir de forma mais legível uma matriz quadrada
 * @param A Matriz a ser impressa
 * @param n dimensão da matriz
 */
void imprime_matriz(long double **A, int n);

/**
 * Função para imprimir um vetor de forma mais legível
 * @param v vetor a ser impresso
 * @param n tamanho do vetor
 */
void imprime_vetor(long double *v, int n);

/**
 * Função para retornar a norma infinita de um vetor obtido pela subtração
 * de dois vetores
 * @param  xk Vetor x(k+1)
 * @param  x  Vetor x(k)
 * @param  n  Dimensão dos vetores
 * @return    norma do vetor obtido pela subtração
 */
long double norma_infinita(long double *xk, long double *x, int n);

/**
 * Função para resolver o sistema linear usando o método de gauss-seidel
 * @param A     Matriz de funções do sistema linear
 * @param b     Resultados das equações do sistema linear
 * @param x     Vetor contendo os resultados iniciais
 * @param n     Dimensão do sistema linear
 * @param e     Precisão
 * @param itmax Número máximo de iterações
 */
long double *gauss_seidel(long double **A, long double *b, long double *x, int n, long double e, int itmax);

#endif
