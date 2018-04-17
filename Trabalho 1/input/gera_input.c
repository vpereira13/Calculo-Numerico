#include <stdio.h>
#include <stdlib.h>

/**
 * Programa feito para gerar parte do input utilizado no trabalho
 * com ele é possível gerar a matriz A solicitada, o vetor b (que
 * dependendo da letra do enunciado é diferente), o vetor x com o
 * chute inicial 0, número máximo de iterações e a tolerância de erro.
 * O programa sempre imprimirá mensagem de como usar se caso não for
 * usado corretamente.
 * Se usado corretamente, ele sempre imprimirá na sequência:
 * 			n
 * 			A (um elemento por linha)
 * 			b (um elemento por linha)
 *			x (um elemento por linha)
 *			e (precisão)
 *			itmax (número máximo de iterações)
 *
 * para facilitar, recomendo que use da seguinte forma:
 *
 * 			./gera_input n exercicio
 *
 * sendo que n é a dimensão da matriz, dos vetores x e do vetor b. Já a
 * variável exercicio pode assumiros seguintes valores:
 *						 0 -> para gerar exemplo para o item b) do trabalho
 * 					   e 1 -> para gerar exemplo para o item c) do trabalho
 *
 */

/**
 * Função que gera uma matriz pentadiagonal como a descrita no enunciado
 * do trabalho
 * @param  n Dimensão da matriz
 * @return   Matriz alocada e com valores setados
 */
int **gera_matriz_A(int n){
	int i;
	int j;

	int **A;

	// Alocando memória
	A = malloc(sizeof(int *) * n);
	for(i = 0; i < n; i++)
		A[i] = malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			// Caso da diagonal principal
			if(i == j)
				A[i][j] = 4;
			// Caso das diagonais especiais
			else if(j == i+1 || i == j+1 || j == i+3 || i == j+3)
				A[i][j] = -1;
			// Caso do resto
			else
				A[i][j] = 0;
		}

	return A;
}

/**
 * Função que gera o vetor b de acordo com a letra b) do enunciado do
 * trabalho
 * @param  A Matriz base para a criação do vetor b
 * @param  n Tamanho do vetor
 * @return   Vetor b com os valores solicitados
 */
int *gera_vetor_b_b(int **A, int n){
	int i;
	int j;
	int *b;

	b = calloc(sizeof(int), n);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			b[i] += A[i][j];

	return b;
}

/**
 * Função que gera o vetor b de acordo com a letra c) do enunciado do
 * trabalho
 * @param  n Tamanho do vetor
 * @return   Vetor b com os valores solicitados
 */
long double *gera_vetor_b_c(int n){
	int i;
	long double *b;

	b = malloc(sizeof(int)* n);

	for(i = 0; i < n; i++)
		b[i] = 1.0/((i+1)*1.0);

	return b;
}

/**
 * Função para imprimir um vetor de inteiros, com um elemento por linha
 * @param v Vetor a ser impresso
 * @param n Dimensão do vetor
 */
void imprime_vetor(int *v, int n){
	int i;

	for(i = 0; i < n; i++)
		printf("%d\n", v[i]);
}

/**
 * Função para imprimir uma matriz para usar como input de outro programa
 * @param A Matriz a ser impressa
 * @param n dimensão da matriz
 */
void imprime_matriz(int **A, int n){
	int i;
	int j;

	for (i = 0; i < n; i++)
		imprime_vetor(A[i], n);
}

/**
 * Função para imprimir um vetor para usar como input de outro programa
 * no caso o vetor é da forma do item c) do trabalho
 * @param b vetor a ser impresso
 * @param n dimensão do vetor
 */
void imprime_vetor_c(long double *b, int n){
	int i;

	for(i = 0; i < n; i++)
		printf("%.16Lf\n", b[i]);
}

int main(int argc, char *argv[]){
	// Variáveis
	int *x;
	int *bb;
	int **A;
	long double *bc;
	int ex;
	int n;

	// Iteradores
	int i;

	if(argc != 3){
		printf("Usage: ./programa valor_de_n exercicio, sendo que o exercicio pode ter valores\n\t0 -> b\n\t1 -> c\n");
		return -1;
	}

	n = atol(argv[1]);
	ex = atol(argv[2]);

	if(ex > 1 && ex < 0 || n < 1){
		printf("Usage: ./programa valor_de_n exercicio, sendo que o exercicio pode ter valores\n\t0 -> b\n\t1 -> c\n");
		return -1;
	}

	A = gera_matriz_A(n);
	printf("%d\n", n);
	imprime_matriz(A, n);

	// Como o chute inicial é sempre o vetor nulo, podemos alocar com zeros
	x = calloc(sizeof(int), n);

	if(ex == 0){
		bb = gera_vetor_b_b(A, n);
		imprime_vetor(bb, n);

		imprime_vetor(x, n);

		printf("0.00001\n");
		printf("10000000\n");

		// Liberando memória
		free(bb);
	} else if(ex == 1){
		bc = gera_vetor_b_c(n);
		imprime_vetor_c(bc, n);

		imprime_vetor(x, n);

		printf("0.0000000001\n");
		printf("10000000\n");

		// Liberando memória
		free(bc);
	} else{
		// Liberando memória
		for(i = 0; i < n; i++)
			free(A[i]);
		free(A);
		free(x);
		return -1;
	}

	// Liberando memória
	for(i = 0; i < n; i++)
		free(A[i]);
	free(A);
	free(x);

	return 0;
}
