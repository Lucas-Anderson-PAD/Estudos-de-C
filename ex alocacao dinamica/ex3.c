#include <stdio.h>
#include <stdlib.h>


int contaMelhoresMotoristas(int * inscricao, int *multas, int n);
int * obtemMelhoresMotoristas(int * inscricao, int *multas, int n,int * sem_multas);

int main(){
    int inscricao[50]={11,22,33,44,55,66,77,100};
    int multas[50]={0,0,0,0,2,5,4,6};
    int n = 8;
    int n_sem_multas;
    int * vetor_sem_multas;

    vetor_sem_multas = obtemMelhoresMotoristas(inscricao, multas, n, &n_sem_multas);
    printf("{");
    for(int i =0;i<n_sem_multas;i++){
        printf(" %d ", *(vetor_sem_multas + i));
    }
    printf("}\n");

    printf("%d", n_sem_multas);


}

int contaMelhoresMotoristas(int * inscricao, int *multas, int n){
    int sem_multas = 0;
    printf("Motoristas sem multa :\n");
    for(int i =0; i<n; i++){
        if(*(multas + i) == 0){
            sem_multas += 1;
            printf("%d\n",*(inscricao + i));
        }
    }

    return sem_multas;
}

int * obtemMelhoresMotoristas(int * inscricao, int *multas, int n,int * sem_multas){
    *sem_multas = contaMelhoresMotoristas(inscricao, multas, n);
    int* vetor = (int *)malloc(*sem_multas* sizeof(int));
    int j = 0;
    for(int i = 0; i<n; i++){

        if(*(multas+i)==0){
            *(vetor +j) = *(inscricao + i);
            j++;
        }
    }
    return vetor;
}