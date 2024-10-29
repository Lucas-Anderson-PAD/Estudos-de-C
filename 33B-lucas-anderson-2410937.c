#include <stdio.h>

char * proficaonome(FILE * arq);




int main(){
    char ** vetor;
    FILE * arq;
    arq = fopen("arquivo.txt", "rb+");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        return NULL;
    }

    fclose(arq);
}
char * proficaonome(FILE * arq){
    char ** vetor;
    char *linha;
    while ((linha = fgetc(arq)) != EOF){

    }
}