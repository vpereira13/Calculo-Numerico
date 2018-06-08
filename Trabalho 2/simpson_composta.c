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
#include <stdlib.h>
#include <math.h>
#include <simpson_composta.h>

/**
 * Função que calcula o valor de f(x), sendo f(x) dada por:
 *
 *		f(x) = (1/sqrt(2*π))*e^((-x^2)/2)
 *
 * @param  x ponto x onde será calculada f(x)
 * @return   valor da função f(x) calculada no ponto x
 */
long double funcao_f (long double x){
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
long double simpson_composta(long double x0, long double xN, int n, Funcao f){
	long double x;
	long double h;
	long double resposta;
	long double pares;
	long double impares;

	int i;

	if (n % 2 != 0)
		n += 1;
	h = (xN - x0)/n;

	pares = 0;
	impares = 0;
	x = x0 + h;

	resposta = f(x0) + f(xN);

	for (i = 1; i < n; i++){
		if (i % 2 == 0)
			pares += f(x);
		else
			impares += f(x);

		x += h;
	}

	resposta += 4 * impares + 2 * pares;
	resposta *= h/3;

	return resposta;
}