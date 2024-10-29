#include <stdio.h>

int main(){

}

int * criaVetorDeProdutosZerados(int * cod,int *estoque, int n, int * n_zerados){
    for(int i=0; i<n; i++){
        if((*estoque + i)==0){
            *n_zerados +=1;
        }
    }
    int * newvetor = (int *)malloc(sizeof(int)*(*n_zerados));

    int j = 0;
    for(int i =0; i< n; i++)
    {   
        if(*(estoque + i)==0){
            *(newvetor + j) = *(cod +  i);
            j++;
        }
    }
    return newvetor;

}

