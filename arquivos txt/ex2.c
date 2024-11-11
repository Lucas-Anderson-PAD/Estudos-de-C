#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** criarvetor(FILE * arq, int * tam);
char * gerar_str(FILE * arq);
int maior_str(char ** str,int tam);
void imprime_maior_str(char ** str, int i);


int main(void){
    FILE * arq;
    arq = fopen("ex2.txt","r");

    int tam;

    char **str =criarvetor(arq, &tam);
    imprime_maior_str(str,maior_str(str,tam));

    for (int i = 0; i < tam; i++) {
        free(str[i]);
    }
    free(str);
    
}


char ** criarvetor(FILE * arq, int * tam){
    char ** vetor;
    int n;
    *tam =0;
    if(fscanf(arq,"%d",&n)!=1){
        printf("Erro no conteudo do arquivo");
        return NULL;
    }

    vetor = (char**)malloc(sizeof(char*)*n);

    if(vetor == NULL){
        printf("Erro ao alocar memoria");
        exit(2);
    }


    int i=0;
    char * buffer;
    while( (buffer=gerar_str(arq)) != NULL){
        vetor[i]=(char*)malloc(sizeof(char)*(strlen(buffer)+1));
        if (vetor[i]==NULL){
            printf("Erro ao alocar memoria");
            exit(2);
        }

        strcpy(vetor[i],buffer);
        free(buffer);
        i++;
    }

    *tam = i;
    fclose(arq);
    return vetor;
}


char * gerar_str(FILE * arq){
    char proficao[50];
    char  nome[50];
    char *espaco = " ";


    if(fscanf(arq," %[^:]:%[^\n]",nome,proficao)!=2){
        return NULL;
    }

    char * resultado = (char*)malloc(sizeof(char)*(strlen(proficao)+strlen(nome)+2));

    if (resultado==NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }
    
    strcpy(resultado,proficao);
    strcat(resultado, espaco);
    strcat(resultado,nome);

    return resultado;
};


int maior_str(char ** str,int tam){
    int maior_tam = 0;
    int indice = 0;

    for(int i =0; i < tam;i++){
            if(strlen(str[i])>maior_tam){
                maior_tam = strlen(str[i]);
                indice = i;
        }
    }
    return indice;
}


void imprime_maior_str(char ** str, int i){
    printf("%s",str[i]);
}
