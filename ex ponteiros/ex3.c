#include <stdio.h>
#define MAX 100

void leitura(int *end);
int classe(int clas,int * max, int * min);



int main(void){
    int clas, cod;
    
    for(int i=0; i<MAX;i++){
        int max=0, min=0;
        printf("Digite o codigo da peca\n");
        leitura(&cod);
        printf("Digite a classificação da peca:\n");
        leitura(&clas);

        if (classe(clas,&max,&min)!= -1){
        printf("O produto com godigo %d possui estoque:\n Maximo %d\n Minimo %d\n",cod,max, min);

        }
        
    }
}

void leitura(int *end){
    scanf("%d",end);
}

int classe(int clas,int * max, int * min){
    switch (clas)
    {
    case 1:
        *max = 120;
        *min = 100;
        break;
    case 2:
        *max = 180;
        *min = 150;
        break;
    case 3:
        *max = 250;
        *min = 200;
        break;
    case 4:
        *max = 300;
        *min = 250;
        break;
    default:
        printf("classe invalida\n");
        return -1;
    }
}