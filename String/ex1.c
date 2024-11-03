/*
1. Escreva a função contaLetras (usando obrigatoriamente aritmética de ponteiros) que: - recebe uma cadeia (ou seja, um ponteiro para uma cadeia), e o endereço de duas variáveis onde devem devolvidas 
as respostas - devolve nas variáveis cujos endereço foram recebidos dois valores: o número de maiúsculas e o número de 
minúsculas. 
Implemente um programa que teste essa função.
*/

#include <stdio.h>
#include <string.h>

void contaLetras(char * palavra, int * maiusculas, int * minusculas);

int main(void){
    char * cadeia;
    int maiusculas = 0;
    int minusculas = 0;
    printf("Digite uma cadeia de caracteres");
    scanf("%[^\n]",cadeia);

    contaLetras(cadeia, &maiusculas, &minusculas);

    printf("A cadeia digitada foi %s",cadeia);
    printf("O numero de letras maiusculas foi %d\n",maiusculas);
    printf("O numero de letras minusculas foi %d\n",minusculas);

}

void contaLetras(char * palavra, int * maiusculas, int * minusculas){
    int n = strlen(palavra);
    for (int i =0; i < n ;i++){
        if(*(palavra + i) <= 'z' && *(palavra + i) >= 'a'){
            *minusculas += 1;
        }
        else if(*(palavra + i) <= 'Z' && *(palavra + i) >= 'A'){
            *maiusculas+=1;
        }
    }
}