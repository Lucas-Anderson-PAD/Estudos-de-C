/*
As normas APA compõem um estilo de escrita e formatação para bibliografia em trabalhos acadêmicos. Estas 
normas surgiram com o manual de estilo da American Psychological Association (APA) e são amplamente utilizadas 
por diversos periódicos científicos e instituições acadêmicas. 
Para citar livros de um único autor, por exemplo, a norma APA usa o seguinte padrão: 
Sobrenome, Iniciais Separadas por ponto. (ano de publicação). Título. Editora. 
Exemplos: 
Alves, M.P. (2012). Metodologia cientifica. Escolar Editora. 
Hawking, S. (1988). Uma Breve Historia do Tempo. Intrinseca. 
Kundera, M. (1982). A insustentavel leveza do ser. Companhia das Letras. 
Crie uma função que recebe 4 cadeias de caracteres: nome do autor, ano de publicação, título do livro e editora. 
Esta função deve retornar uma nova string com a citação no formato APA acima descrito. Essa string deve ser 
alocada dinamicamente no tamanho exato. 
Repare que o nome do autor é dado em sua forma “normal”, de modo que é necessário fazer uma função auxiliar 
para converter o nome no formato “Sobrenome, iniciais separadas por ponto”. Por exemplo, esta função auxiliar 
receberia “Milan Kundera” e retornaria “Kundera, M.”, ou “Luis Fernando Verissimo” e retornaria “Verissimo, L.F.”.  
Para simplificar, desconsidere nomes com conectores “de”, “dos”, “da” e similares. Também desconsidere 
caracteres com acentos, ç, etc. 
Teste sua função com 5 livros diferentes. Você não pode usar a função strtok da biblioteca.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * normaAPA(char * nome, char * ano, char * titulo, char * editora);
char * abreviar(char * nome);
char * ultimonome(char * nome, int * pos);
int n_espacos(char * str);

#define tammax 100

int main(){
    char nome[tammax];
    char ano[tammax];
    char titulo[tammax];
    char editora[tammax];
    int n = 1;

    char * apa;

    for(int i = 0; i< n ; i++){
        printf("Digite o nome do autor\n");
        scanf(" %[^\n]",nome);

        printf("Digite o  ano de lancamento : \n");
        scanf( " %[^\n]", ano);

        printf("Digite o titulo da obra \n");
        scanf(" %[^\n]",titulo);

        printf("Digite a editora da obra \n");
        scanf(" %[^\n]",editora);

        apa = normaAPA(nome, ano, titulo, editora);
        if (apa != NULL) { 
            printf("%s\n", apa);
            free(apa); 
        }
        else {
            printf("Erro ao formatar a citação.\n");
        }
    }
                free(apa);
}

char * normaAPA(char * nome, char * ano, char * titulo, char * editora){
    char * nomeAbreviado;
    int tamnome;
    int tamano;
    int tamtitulo;
    int tameditora;

    char * apa;
    int tam;

    nomeAbreviado = abreviar(nome);
    tamnome = strlen(nomeAbreviado);
    tamano = strlen(ano);
    tamtitulo = strlen(titulo);
    tameditora = strlen(editora);

    tam = tamnome + 3 + tamano + 3 + tamtitulo + 2 +tameditora + 2;

    apa = (char*)malloc(sizeof(char)*tam);

    if(apa == NULL){
        printf("Erro ao alocar memoria.\n");
    }

    apa[0] = '\0';

    strcat(apa,nomeAbreviado);
    strcat(apa," ");
    strcat(apa,"(");
    strcat(apa,ano);
    strcat(apa,")");
    strcat(apa,".");
    strcat(apa," ");
    strcat(apa,titulo);
    strcat(apa,".");
    strcat(apa," ");
    strcat(apa,editora);
    strcat(apa,".");

    free(nomeAbreviado);
    return apa;
}

char * abreviar(char * nome){
    int pos;
    char *  ultimo=ultimonome(nome, &pos);
    int n_e =n_espacos(nome);
    char * newnome;
    int tam = 0;

    tam += strlen(ultimo) + 2 + n_e * 2 + 1;
    newnome = (char*)malloc(sizeof(char)*tam);

    if(newnome == NULL){
        printf("erro ao alocar a memoria");
        exit (1);
    }

    newnome[0] = '\0';

    strcat(newnome,ultimo);
    strcat(newnome,",");
    strcat(newnome," ");



    for(int i=0; i < pos;  i++){
        if(i==0|| (*(nome +(i- 1)) == ' ' && *(nome + i) != ' ')){
            char inicial[3] = {*(nome + i),'.','\0'};
            strcat(newnome,inicial);
        }
    }

    return newnome;
}


char * ultimonome(char * nome, int * pos){
    int n = strlen(nome);

    while(n >= 0 && *(nome + n) != ' '){
        n--;
    }


    *pos = n;
    return nome + n + 1;
}

int n_espacos(char * str){
    int cont=0;
    int n = strlen(str);
    for(int i = 0; i <n; i++)
    {
        if(*(str + i) == ' '){
            cont ++;
        }
    }
    return cont;
}

//se atentar ao tamanho das alocações