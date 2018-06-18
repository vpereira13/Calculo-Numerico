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

#ifndef NEWTON_H
#define NEWTON_H

/**
 * Definindo ponteiros para funções, serivrá para poder chamar a função
 * desejada por parâmetro
 */
typedef long double (*Funcao_Derivada)(long double);
typedef long double (*Funcao)(long double, long double, int, Funcao_Derivada);

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
