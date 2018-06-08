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

#ifndef SIMPSON_COMPOSTA_H
#define SIMPSON_COMPOSTA_H

/**
 * Definindo um ponteiro para uma função para poder chamar a função desejada
 * por parâmetro
 */
typedef long double (*Funcao)(long double);

/**
 * Função que calcula o valor de f(x), sendo f(x) dada por:
 *
 *		f(x) = (1/sqrt(2*π))*e^((-x^2)/2)
 *
 * @param  x ponto x onde será calculada f(x)
 * @return   valor da função f(x) calculada no ponto x
 */
long double funcao_f (long double x);

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
long double simpson_composta(long double x0, long double xN, int n, Funcao f);

#endif