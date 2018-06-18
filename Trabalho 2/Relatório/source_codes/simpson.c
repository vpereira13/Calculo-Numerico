/**
 *	Trabalho 2 - Método de Integração Numérica Simpson 1/3 Composta
 *
 *		Cálculo Numérico	SME-0104
 *		Prof.: Murilo Francisco Tomé
 *
 *		Eduardo Brunaldi dos Santos             8642515
 *		Jorge Ashkar Ferreira Simondi           8517081
 *		Victor Luiz da Silva Mariano Pereira    8602444
 */

#include <funcoes.h>
#include <simpson.h>

/**
 * Função para calcular a integração de uma certa função f usando o método de
 * Simpson 1/3 Composta, dada por:
 *
 * I^N_S = (h/3) * (f(x0) + f(xN) + 4*SUM(f(x_impares)) + 2*SUM(f(x_pares)))
 *
 * Utilizando um intervalo, a quantidade de divisões do intervalo e a função a
 * ser integrada.
 *
 * @param  x0 valor inicial do intervalo
 * @param  xN valor final do intervalo
 * @param  n  quantas vezes será dividido o intervalo
 * @param  f  função a ser integrada
 * @return    valor aproximado da integral da função f
 */
long double simpson_composta(long double x0, long double xN, int n, Funcao_Derivada f){
	// Variáveis auxiliares
	long double x;
	long double h;
	long double resposta;
	long double pares;
	long double impares;

	// Iterador
	int i;

	// Verifica se o n de entrada é par, caso ímpar adiciona 1
	if (n % 2 != 0)
		n += 1;

	// Cálculo de h
	h = (xN - x0)/n;

	// Inicializa valores dos somatórios
	pares = 0;
	impares = 0;

	// atualiza o valor de x
	x = x0 + h;

	// Inicia a resposta com a f(0) e f(x_n)
	resposta = f(x0) + f(xN);

	// Cálculo dos somatórios de pares e ímpares
	for (i = 1; i < n; i++){
		// Caso par
		if (i % 2 == 0)
			pares += f(x);
		// Caso ímpar
		else
			impares += f(x);
		// Atualiza o x
		x += h;
	}

	// Adiciona 4*somatório dos ímpares + 2*somatório dos pares na resposta
	resposta += 4 * impares + 2 * pares;
	// Multiplica o valor achado pelas somas por h/3
	resposta *= h/3;

	// Retorna o valor aproximado da integral utilizando o método de
	// Simpson 1/3 composto
	return resposta;
}
