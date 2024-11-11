#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define linhas 100
#define tamtxt 127

// Declaração das funções auxiliares
void criarvetor(char *nomearq, char ***titulos, char ***autores, int *tamanho);
void ordenarvedetor(char **titulos, char **autores, int tamanho);
void escreverarq(char *nomenovoarq, char **titulos, char **autores, int tamanho);
void liberarmemoria(char **vetor, int tamanho);

int main(void) {
    char *nomearq = "ex1.txt";
    char *nomenovoarq = "ex1_n.txt";
    char **vetortitulos;
    char **vetorautores;
    int tamanho = 0;

    criarvetor(nomearq, &vetortitulos, &vetorautores, &tamanho);
    ordenarvedetor(vetortitulos, vetorautores, tamanho);
    escreverarq(nomenovoarq, vetortitulos, vetorautores, tamanho);
    liberarmemoria(vetortitulos, tamanho);
    liberarmemoria(vetorautores, tamanho);

    return 0;
}

// Função para ler o arquivo e criar os vetores de títulos e autores
void criarvetor(char *nomearq, char ***titulos, char ***autores, int *tamanho) {
    FILE *arq = fopen(nomearq, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }

    *titulos = (char**)malloc(sizeof(char*) * linhas);
    *autores = (char**)malloc(sizeof(char*) * linhas);

    if (*titulos == NULL || *autores == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(2);
    }

    char tempt[tamtxt];
    char tempa[tamtxt];
    int i = 0;
    while (fscanf(arq, " %[^/]/%[^\n]", tempt, tempa) == 2) {
        (*titulos)[i] = (char*)malloc(sizeof(char) * (strlen(tempt) + 1));
        (*autores)[i] = (char*)malloc(sizeof(char) * (strlen(tempa) + 1));

        if ((*titulos)[i] == NULL || (*autores)[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(2);
        }

        strcpy((*titulos)[i], tempt);
        strcpy((*autores)[i], tempa);
        i++;
    }
    *tamanho = i;
    fclose(arq);
}

// Função para ordenar os títulos em ordem alfabética, mantendo autores sincronizados
void ordenarvedetor(char **titulos, char **autores, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        char *chaveTitulo = titulos[i];
        char *chaveAutor = autores[i];
        int j = i - 1;

        while (j >= 0 && strcmp(titulos[j], chaveTitulo) > 0) {
            titulos[j + 1] = titulos[j];
            autores[j + 1] = autores[j];
            j--;
        }
        titulos[j + 1] = chaveTitulo;
        autores[j + 1] = chaveAutor;
    }
}

// Função para escrever o arquivo de saída no formato desejado
void escreverarq(char *nomenovoarq, char **titulos, char **autores, int tamanho) {
    FILE *arq = fopen(nomenovoarq, "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }

    char letraAtual = '\0';
    for (int i = 0; i < tamanho; i++) {
        char letra = titulos[i][0];
        if (letra != letraAtual) {
            if (letraAtual != '\0') {
                fprintf(arq, "\n");
            }
            fprintf(arq, "Titulos iniciados com %c:\n", letra);
            letraAtual = letra;
        }

        // Verifica se há mais de um autor
        if (strchr(autores[i], ';')) {
            fprintf(arq, "%s. Autores: %s\n", titulos[i], autores[i]);
        } else {
            fprintf(arq, "%s. Autor: %s\n", titulos[i], autores[i]);
        }
    }

    fclose(arq);
}

// Função para liberar memória alocada dinamicamente
void liberarmemoria(char **vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(vetor[i]);
    }
    free(vetor);
}
