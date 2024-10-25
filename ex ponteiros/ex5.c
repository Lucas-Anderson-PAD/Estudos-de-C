#include <stdio.h>

float calculaMedia(int * vetor, int n);
int busca1(int *vetor, int n, int x);
int busca2(int *vetor, int n, int x);
int verificaOrd(int * vetor, int n);
int Inverte(int *vetor, int *invetor,int n);


int main (void){
    int max, min,temp = 0;

     printf("digite um valor inteiro");
    scanf("%d",&temp); 

    max = temp;
    min = temp;

    for(int i = 0; i<10-1;i++){
        printf("digite um valor inteiro");
        scanf("%d",&temp);

        if(temp>max){
            max= temp;
        }
        if(temp<min){
            min = temp;
        }
    }
    printf("O menor valor lido foi %d\nO maior valor lido foi%d\n",min,max);

    //teste funçoes
    int n = 5;
    int vetor[]= {1,2,3,4,5};
    int invetor[5];
    int x;

    printf("A media e %.1f\n\n",calculaMedia(vetor, n));

    printf("Digite um valor\n");
    scanf("%d",&x);

    if(busca1(vetor,n,x)==1){
        printf("O numero foi encontrado\n");
        printf("A posicao do numero e %d\n",busca2(vetor,n,x)+1);
    }
    else{
        printf("O numero nao foi encontrado\n");
    }

    if(verificaOrd(vetor, n)==1){
        printf("O vetor esta ordenado em ordem crecente\n");
    }
    else{
        printf("O vetor nao esta ordenado em ordem crecente\n");
    }
    

    Inverte(vetor, invetor,n);
    printf("{");
    for(int i = 0; i<n;i++){
        printf("%d ,",invetor[i]);
    }
    printf("}");
}

float calculaMedia(int * vetor, int n){
    int soma = 0;
    for(int i=0;i<n;i++){
        soma += vetor[i];
    }

    float media;
    media = (float)soma/n;
    return media;
}

int busca1(int *vetor, int n, int x){
    for(int i = 0; i<n;i++){
        if(vetor[i]==x){
            return 1;
        }
    }
    return 0;
}

int busca2(int *vetor, int n, int x){
    for(int i = 0; i<n;i++){
        if(vetor[i]==x){
            return i;
        }
    }
    return -1;
}

int verificaOrd(int * vetor, int n){
    int verificador = 0;
    for(int i = 0; i<n-1;i++){
        if(vetor[i]<vetor[i+1]){
            verificador = 1;
        }
        else {
            return verificador;
        }
    }
    return verificador;
}

int Inverte(int *vetor, int *invetor,int n){
    for(int i = 0; i<n;i++){
        invetor[i] = vetor[n-i-1];
    }
}