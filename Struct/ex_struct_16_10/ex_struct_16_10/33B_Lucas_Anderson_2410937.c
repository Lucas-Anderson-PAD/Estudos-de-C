#include <stdio.h>
#include <stdlib.h>

typedef  struct avaliacao  Avaliacao;
typedef struct  vendedor Vendedor;



int main() {

}

struct avaliacao
{
	float valorVendidoNoMes;
	int	numeroDeFaltas;
};

struct vendedor
{
	int	 	inscricao;
	char  		nome[51];
	float		salario_base;
	Avaliacao	aval;
};

float calculaExtra(Avaliacao av) {

	if (av.valorVendidoNoMes > 2000) {
		if (av.numeroDeFaltas < 2) {
			return 180;
		}

		else if (av.numeroDeFaltas < 4) {
			return 150;
		}

	}
	if (av.valorVendidoNoMes > 5000) {
		if (av.numeroDeFaltas < 6) {
			return 120;
		}
	}
	else {
		return 0;
	}
}

float calculaValorTotalDaFolha(int n, Vendedor* ved) {
	float soma;
	for (int i = 0; i < n; i++) {
		soma = ved[i].salario_base + calculaExtra(ved[i].aval);
	}

	return soma;
}

int* obtemRelacaoDemitidos() {

}