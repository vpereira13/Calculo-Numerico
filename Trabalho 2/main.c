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
#include <simpson_e_newton.h>

int main (int argc, char *argv[]){
	long double x0;
	long double xN;
	long double n;

	scanf("%Lf", &x0);
	scanf("%Lf", &xN);
	scanf("%Lf", &n);

	printf("Valor da integral, utilizando Simpson 1/3 Composta: %.16Lf\n", simpson_composta(x0, xN, n, f_linha));
	printf("Valor da raiz pelo metodo de Newton: %.16Lf\n", newton(0.5, 0.0000000001, simpson_composta, f_linha));
	return 0;
}
