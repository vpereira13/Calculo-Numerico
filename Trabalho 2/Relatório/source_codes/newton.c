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

#include <newton.h>
#include <stdio.h>
#include <math.h>
#include <funcoes.h>
#include <simpson.h>

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
