#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxalunos 100

typedef struct aluno Aluno;
int comparar(char * el1,char * el2,int n);
int ler(Aluno ** vetor, int nmax);
void notamaior(Aluno ** vetor, int n, char cod[4]);


int main(){
    Aluno * vetorAlunos[maxalunos];
    int n_alunos = ler(vetorAlunos, maxalunos);
    char cod[4] = "INF";
    notamaior(vetorAlunos, n_alunos, cod);

    for(int i=0;i<n_alunos;i++){
        free(vetorAlunos[i]);
    }

}

struct aluno{
    int matricula;
    char codigo[8];
    float nota;
    char nome[31];
};


int ler(Aluno ** vetor, int nmax){
    int matricula;
    char codigo[8];
    float nota;
    char nome[31];

    int n;
    FILE * arq;
    arq = fopen("alunos.txt", "r");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    n =0;
    while(n<nmax && fscanf(arq, "%d;%[^;];%f;%[^\n]",&matricula,codigo,&nota,nome)==4){
        vetor[n] = (Aluno*)malloc(sizeof(Aluno));
        if(vetor[n]==NULL){
            printf("Erro alocacao");
            exit(2);

            vetor[n]->matricula=matricula;
            strcpy(vetor[n]->codigo,codigo);
            vetor[n]->nota=nota;
            strcpy(vetor[n]->nome,nome);
        }
    }
    fclose(arq);
    return n;
}

void notamaior(Aluno ** vetor, int n, char cod[4]){
    int corte = 7;
    for(int i =0;i<n;i++){
        if(comparar(vetor[i]->codigo, cod, 3) == 0){
            if(vetor[i]->nota>=corte){
                printf("Diciplina %s nome: %s",vetor[i]->codigo,vetor[i]->nome);
            }
        }
    }
}

int comparar(char * el1,char * el2,int n){
    for(int i =0; i< n;i++){
        if(el1[i]!=el2[i]){
            return 1;
        }
    }
    return 0;
}
