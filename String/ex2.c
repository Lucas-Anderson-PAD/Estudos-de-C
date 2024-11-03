/*
2. Implemente uma função que receba uma cadeia de caracteres (string) como parâmetro e altere nessa string as 
ocorrências de caracteres maiúsculos para minúsculos. Essa função deve obedecer ao protótipo:           
void minusculo (char* str); 
Implemente também um programa que teste essa função. 
*/

#include <stdio.h>
#include <string.h>

void minusculo (char* str); 

int main(void){
    char * str;
    printf("Digite : ");
    scanf("%[^\n]",str);

    minusculo (str);
    printf("So minuscula %s\n", str);
}

void minusculo (char* str){
    int n = strlen(str);
    for(int i= 0; i < n;i++){
        if(*(str + i)>='A' && *(str + i)<='Z'){
            *(str + i) = *(str + i) + 32;
        }
    }
}
