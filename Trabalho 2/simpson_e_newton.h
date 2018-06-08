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

#ifndef SIMPSON_E_NEWTON_H
#define SIMPSON_E_NEWTON_H

/**
 * Definindo ponteiros para funções, servirá para poder chamar a função
 * desejada por parâmetro
 */
typedef long double (*Funcao_Derivada)(long double);
typedef long double (*Funcao)(long double, long double, int, Funcao_Derivada);

/**
 * Função que calcula o valor de f(x), sendo f(x) dada por:
 *
 *		f(x) = (1/sqrt(2*π))*e^((-x^2)/2)
 *
 * @param  x ponto x onde será calculada f(x)
 * @return   valor da função f(x) calculada no ponto x
 */
long double f_linha (long double x);

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
long double simpson_composta(long double x0, long double xN, int n, Funcao_Derivada f);

/**
 * Função que calcula a raiz de uma função utilizando o método de Newton
 * @param  x0      Valor do chute inicial
 * @param  e       Precisão esperada
 * @param  f       Função que será analisada
 * @param  f_linha Derivada da função que será analisada
 * @return         Aproximação da raiz da função dada, com uma certa precisão
 */
long double newton(long double x0, long double e, Funcao f, Funcao_Derivada f_linha);

#endif
