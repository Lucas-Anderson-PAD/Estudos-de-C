#include <stdio.h>
#include <stdlib.h>

struct avaliacao
{
    float	valorVendidoNoMes;
    int	numeroDeFaltas;
};
typedef  struct avaliacao  Avaliacao;

struct vendedor
{
    int	 	inscricao;
    char  		nome[51];
    float		salario_base;
    Avaliacao	aval;
};
typedef struct  vendedor Vendedor;


float calculaExtra(Avaliacao aval);
float calculaValorTotalDaFolha(int qnt_ven, Vendedor *vend);
Vendedor ** obtemRelacaoDemitidos(int qnt_vend, Vendedor *vend, int* numDemitidos);
char* obtemMelhorVendedor(int qnt_vend, Vendedor vend[]);

int main(void)
{
    Vendedor vVendedor[10] = { 
    {1, "Ana Silva", 1000,{3000,1}},
    {2, "Pedro Duarte",2000,{3010,3}},
    {3, "Joao Filho", 1000,{3020,4}},
    {4, "Maria Gomes", 3000,{3030,15}},
    {5, "Silvio Lins", 1000,{6000,15}},
    {6, "Marcia Morais",2000,{6010,3}},
    {7, "Bruno Rodrigues",3000,{6020,4}},
    {8, "Thais Silva", 4000,{6030,7}},
    {9, "Ricardo Costa", 5000,{3040,7}},
    {10, "Julia Neves", 10000,{1000,0}} };
    //Continue a implementação do programa!

    float totalFolha = calculaValorTotalDaFolha(10, vVendedor);
    printf("total da folha = R$%.2f\n", totalFolha);

    int numDemitidos = 0;
    int* demitidos = obtemRelacaoDemitidos(10, vVendedor, &numDemitidos);
    if (!demitidos) {
        if (numDemitidos == 0) {
            printf("Nenhum vendedor demitido esse mes");
        }
        else {
            printf("Erro alocacao\n");
        }
    }

    else {
        printf("Vendedores demitidos\n");
        for (int i = 0; i < numDemitidos; i++) {
            printf("%d oi\n",demitidos[i]);
        }
    }

    char* melhorVendedor = obtemMelhorVendedor(10, vVendedor);
    printf("%s ganhou destaque como melhor\n", melhorVendedor);

    return 0;
}

float calculaExtra(Avaliacao avali) {
    if (avali.numeroDeFaltas < 2) {
        if (avali.valorVendidoNoMes > 2000) {
            return 180.0;
        }
    }

    else if (avali.numeroDeFaltas < 4) {
        if (avali.valorVendidoNoMes > 2000) {
            return 150.0;
        }
    }

    else if (avali.numeroDeFaltas < 6) {
        if (avali.valorVendidoNoMes > 5000) {
            return 120.0;
        }
    }

    return 0.0;
}

float calculaValorTotalDaFolha(int qnt_ven, Vendedor *vend) {
    float totalMes = 0;
    int i;

    for (i = 0; i < qnt_ven; i++) {
        totalMes += calculaExtra(vend[i].aval) + vend[i].salario_base;
    }
    return totalMes;
}

Vendedor ** obtemRelacaoDemitidos(int qnt_vend, Vendedor *vend, int* numDemitidos) {
    int i, demitidos, index;
    index = 0;
    demitidos = 0;

    for (i = 0; i < qnt_vend; i++) {
        if (vend[i].aval.numeroDeFaltas >= 10) {
            demitidos++;
        }
    }
    *numDemitidos = demitidos;
    if (demitidos == 0) {
        return NULL;
    }

    Vendedor** newVet = (Vendedor*)malloc(demitidos * sizeof(Vendedor));
    if (!newVet) {
        return NULL;
    }

    for (i = 0; i < qnt_vend; i++) {
        if (vend[i].aval.numeroDeFaltas >= 10) {
            newVet[index++] = &vend[i];
        }
    }

    return newVet;
}

char* obtemMelhorVendedor(int qnt_vend, Vendedor vend[]) {
    int i, mIndex = 0;

    for (i = 1; i < qnt_vend +1; i++) {
        if (vend[i].aval.valorVendidoNoMes > vend[mIndex].aval.valorVendidoNoMes) {
            mIndex = i;
        }
    }
    return vend[mIndex].nome;
}
