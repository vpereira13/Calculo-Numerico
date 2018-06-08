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

#include <stdio.h>
#include <math.h>
#include <simpson_e_newton.h>

/**
 * Função que calcula o valor de f(x), sendo f(x) dada por:
 *
 *		f(x) = (1/sqrt(2*π))*e^((-x^2)/2)
 *
 * @param  x ponto x onde será calculada f(x)
 * @return   valor da função f(x) calculada no ponto x
 */
long double f_linha (long double x){
	return (1.0/(sqrt(2*M_PI)*1.0))*exp((- pow(x, 2.0))/2.0);
}

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

/**
 * Função que calcula a raiz de uma função utilizando o método de Newton
 * @param  x0      Valor do chute inicial
 * @param  e       Precisão esperada
 * @param  f       Função que será analisada
 * @param  f_linha Derivada da função que será analisada
 * @return         Aproximação da raiz da função dada, com uma certa precisão
 */
long double newton(long double x0, long double e, Funcao f, Funcao_Derivada f_linha){
	// Variáveis auxiliares
	long double x_atual;
	long double x_anterior;
	int iteracoes = 0;

	// Atualiza o valor de x_n+1
	x_atual = x0;

	do{
		// Atualiza valor de x_n
		x_anterior = x_atual;
		// Calcula novo valor de x_n+1
		x_atual = x_anterior - ((f(0, x_anterior, 200, f_linha)-0.45)/f_linha(x_anterior));
		// Atualiza contador de iterações
		iteracoes += 1;
	}while(fabs(x_atual - x_anterior) > e); // Verifica condição da precisão

	// Se não quiser imprimir o número de iterações do método de Newton, basta
	// comentar a próxima linha
	printf("Numero de iteracoes do metodo de Newton: %d\n", iteracoes);

	// Retorna a raiz calculada
	return x_atual;
}
