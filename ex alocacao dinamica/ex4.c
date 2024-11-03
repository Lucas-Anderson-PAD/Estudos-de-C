#include <stdio.h>
#include <stdlib.h>
#define nn 8

int busca(float* vetor,int n, float x);
int contagem(float *vetor, int n);
int busca2(float* vetor,int n, float x);
float * vetordiferente(float *vetor, int n,int * nd);

int main(void){
    float vetor[nn]= {-1.7, 3.0, 0.0, 1.5, 0.0, -1.7,2.3,-1.7} ;
    int nx = 0;
    int n = nn;
    int nd =0;
    
    float * newvetor = vetordiferente(vetor, n, &nd);

    printf("Foram encontrado %d elementos distindtos\n\n",nd);
    for(int i = 0; i< nd; i++){
        nx = busca( vetor, n, *(newvetor +i));
        printf("%.1f ocorre %d vezes\n", *(newvetor +i), nx);
    }
}

int busca(float* vetor,int n, float x){
    int nx=0;
    for(int i=0;i<n;i++){
        if(*(vetor + i)==x){
            nx+=1;

        }
    }
    return nx;
}

int busca2(float* vetor,int n, float x){
    for(int i=0;i<n;i++){
        if(*(vetor + i)==x){
            return 1;

        }
    }
    return -1;
}

int contagem(float *vetor, int n){
    int cont = 0;
    for(int i = 0 ; i < n ; i++){
        int unico =1;
        for(int j =0; j<i;j++){
            if(*(vetor+ i)==(*(vetor+j))){
                unico =0;
                break;
            }
        }
        if(unico){
            cont++;
        }
    }
    return cont;
}

float * vetordiferente(float *vetor, int n, int *nd){
    *nd = contagem(vetor, n);
    int ndn=0;
    float * newvetor;

    newvetor = (float*)malloc(sizeof(float)*(*nd));

    for(int i=0;i<n;i++){
        if(busca2(newvetor,*nd,*(vetor + i))==-1){
            *(newvetor + ndn) = *(vetor + i);
            ndn++;
        }
    }
    return newvetor;
}