/**
 *	Trabalho 1 -  Métodos Iterativos para  Sitemas Lineares
 *
 *		Cálculo Numérico	SME-0104
 *		Prof.: Murilo Francisco Tomé
 *
 *		Eduardo Brunaldi dos Santos				8642515
 *		Jorge Ashkar Ferreira Simondi			8517081
 *		Victor Luiz da Silva Mariano Pereira	8602444
 */

#include <stdio.h>
#include <stdlib.h>
#include <gauss_seidel.h>

int main (int argc, char *argv[]){
	// Variáveis de entrada
	int n;				// Quantidade de equações do sistema linear
	int itmax;			// Número máximo de iterações
	long double **A;	// Matriz de sistemas lineares
	long double *b;		// Vetor resultado das equações
	long double *x;		// Vetor inicial
	long double e;		// Erro permitido, precisão

	// Iteradores
	int i;
	int j;

	// Dimensão da matriz (número de equações do sistema linear)
	scanf("%d", &n);

	// Alocação da matriz
	A = malloc(sizeof(long double *) * n);
	for (i = 0; i < n; i++)
		A[i] = malloc(sizeof(long double) * n);

	// Pegando valores de A
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%Lf", &(A[i][j]));

	// Alocação do vetor resultado
	b = malloc(sizeof(long double) * n);

	// Pegando os valores de b
	for(i = 0; i < n; i++)
		scanf("%Lf", &b[i]);

	// Alocação do vetor chute
	x = malloc(sizeof(long double) * n);

	// Pegando os valores do x(0), o vetor inicial
	for(i = 0; i < n; i++)
		scanf("%Lf", &x[i]);

	// Pegando o valor da precisão (erro permitido)
	scanf("%Lf", &e);

	// Pegando a quantidade máxima de iterações
	scanf("%d", &itmax);

	x = gauss_seidel(A, b, x, n, e, itmax);

	imprime_vetor(x, n);

	// Liberando a memória
	free(x);
	free(b);
	for (i = 0; i < n; i++)
		free(A[i]);
	free(A);

	return 0;
}
