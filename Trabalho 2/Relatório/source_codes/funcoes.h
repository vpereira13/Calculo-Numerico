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

#ifndef FUNCOES_H
#define FUNCOES_H

/**
 * Definindo ponteiros para funções, serivrá para poder chamar a função
 * desejada por parâmetro
 */
typedef long double (*Funcao_Derivada)(long double);
typedef long double (*Funcao)(long double, long double, int, Funcao_Derivada);

/**
 * Função que calcula o valor de f'(x) dada por:
 *
 *		f'(x) = (1/sqrt(2*π))*e^((-x^2)/2)
 *
 * @param  x ponto x onde será calculada f'(x)
 * @return   valor da função f'(x) calculada no ponto x
 */
long double f_linha (long double x);

#endif
