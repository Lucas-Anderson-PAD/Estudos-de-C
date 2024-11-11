/*
(1) função criaSenhas que recebe um vetor de n strings e retorna o vetor senhas totalmente 
dinâmico. Para teste, na main, defina char * s[] = {"an5a",NULL,"puc","9casa"}; 
(2) função imprime que exibe todas as senhas (e imprime a palavra NULL quando a senha é 
NULL);  
(3) função valida que recebe o vetor senhas, o seu tamanho e um específico usuário e retorna se 
a senha deste usuário é válida de acordo com o seguinte critério: uma senha é válida se tiver ao 
menos um dígito numérico. Por exemplo: "an5a" é válida e "puc" não. Considere que o usuário 
fornecido sempre tem uma senha não nula;  
(4) função elimina que recebe o vetor senhas e um usuário específico e elimina este usuário 
(liberando a memória ocupada pela senha e substituindo a senha pelo ponteiro NULL);  
(5) função eliminaTodos que libera todos os usuários, suas senhas e o vetor senhas 
completamente. 
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ** criaSenhas(char ** vetor, int tam);
int valida(char **vetor, int tam, int usuario);
void imprimeSenhas(char ** vetor, int tam);
void elimina(char ** vetor, int usuario);
void eliminaTodos(char ** vetor, int tam);

int main(){
    char *vetor[] = {"an5a","oi","puc","9casa"};
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    char **senhas = criaSenhas(vetor,tam);

    for(int i = 0 ; i< tam;i++){
        if(valida(senhas, tam, i)==0){
            elimina(senhas, i);
        }
    }

    imprimeSenhas(senhas,tam);


    eliminaTodos(senhas, tam);
}

char ** criaSenhas(char ** vetor, int tam){
    char ** senhas;
    senhas = (char**)malloc(sizeof(char*)*tam);

    if(senhas == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    for(int i = 0; i< tam;i++){

        if(vetor[i] == NULL){
            senhas[i]= NULL;
        }
        else{

        senhas[i] = (char*)malloc(sizeof(char)*strlen(vetor[i]) + 1);
        if(senhas[i] == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
        }
        strcpy(senhas[i],vetor[i]);
    }
    }
    return senhas;
}

int valida(char **vetor, int tam, int usuario) {
    if (usuario < 0 || usuario >= tam || vetor[usuario] == NULL) {
        return 0; 
    }

    for (int i = 0; i < strlen(vetor[usuario]); i++) {
        if (vetor[usuario][i] >= '0' && vetor[usuario][i] <= '9') {
            return 1;
    }
    }
    return 0;  
}


void imprimeSenhas(char ** vetor, int tam){
    for(int i = 0; i < tam; i++){
        if (vetor[i]!= NULL){
        printf("Senha %d : %s\n",(i+1),*(vetor + i));
        }
        else{
            printf("Senha %d : NULL\n",(i+1));
        }
    }
}

void elimina(char ** vetor, int usuario){
    free(vetor[usuario]);
    vetor[usuario] = NULL;
}

void eliminaTodos(char ** vetor, int tam){
        for(int i = 0 ; i< tam;i++){
        free(vetor[i]);
    }
    free(vetor);
}