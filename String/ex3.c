/*
3. Escreva, em C, a função ultimoNome que recebe uma cadeia com um nome completo de uma pessoa e retorna o seu 
sobrenome (isto é, o seu último nome). Considere que há apenas um único espaço em branco entre nomes e que após o 
último nome não há espaços em branco. Não crie novas cadeias (estáticas ou dinâmicas).  
Exemplos:  
com “STEVEN PAUL JOBS”, a função retorna “JOBS”  
com “SILVA”, a função retorna “SILVA”  
com “”, a função retorna “” 
Implemente um programa que teste essa função. 
*/

#include <stdio.h>
#include <string.h>

char * ultimoNome (char * str);
#define tam 100

int main(void){

    char nome[tam];

    printf("Digite o seu nome completa\n");
    scanf("%[^\n]", nome);

    printf(" O seu ultimo nome e : %s",ultimoNome (nome));

}

char * ultimoNome (char * str){
    int n = strlen(str);
    
    while(*(str + n) != ' '){
        n-=1;
    }
    return str + n + 1;
}