#include <stdio.h>
#include <stdlib.h>

int *  intercalado(int * vetor1, int * vetor2, int n1,int n2);

int main(void){
    int vetor1[] = {1,2,3};
    int vetor2[] = {0,0,0};
    int n1 =3, n2=3, n3 = n1+n2;

    int * vetor3 = intercalado(vetor1, vetor2, n1,n2);

    for (int i=0;i<n3;i++){
        printf(" %d",*(vetor3 + i));
    }
}

int *  intercalado(int * vetor1, int * vetor2, int n1,int n2){
    int n3 = n1 +n2;
    int i=0,j=0,h=0;
    int * vetor3 = (int*) malloc (n3 * sizeof(int));

    while (i<n3){
        if(j<n1){
            *(vetor3 + i) =*(vetor1 + j);
            j++;
            i++;
        }

        if(h<n2){
            *(vetor3 + i) = *(vetor2 + h);
            h++;
            i++;
        }
    }
    return vetor3;
}

//se atentar na logica e no nome das variaveis