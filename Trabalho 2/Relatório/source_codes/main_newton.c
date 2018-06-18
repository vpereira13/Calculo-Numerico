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
#include <funcoes.h>
#include <newton.h>
#include <simpson.h>

int main (int argc, char *argv[]){
	long double x0;
	long double e;

	scanf("%Lf", &x0);
	scanf("%Lf", &e);

	printf("%.16Lf\n", newton(x0, e, simpson_composta, f_linha));

	return 0;
}
