/*
4. Escreva a função criaNome que gera automaticamente e retorna o nome completo de um bebê, a partir do primeiro 
nome dado ao bebê, do nome completo de solteira da mãe e do nome completo do pai. O nome do bebê é composto 
pelo seu primeiro nome + último nome da mãe + último nome do pai, separados por espaços. 
Função criaNome: - recebe uma cadeia com o primeiro nome do bebê, uma cadeia com o nome completo da mãe e uma cadeia com o 
nome completo do pai; - cria e retorna uma nova cadeia contendo o nome completo do bebê, gerado de acordo com o critério descrito. 
Utilizar alocação dinâmica de memória do tamanho exato necessário. Retorna NULL quando não for possível alocar 
dinamicamente. Essa função deve usar, adequadamente, a função ultimoNome, mesmo que você não a tenha feito.  
Exemplo: a seguinte chamada da função com os argumentos: 
criaNome("Pedro", "Ana Luiza Resende", "Rui Alberto Medeiros") 
retornaria (um ponteiro para) uma nova cadeia contendo o nome "Pedro Resende Medeiros" 
Implemente um programa que teste essa função.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 100


char * criaNome (char * primeiro_n, char * nome_m, char * nome_p);
char * ultimonome(char * nome);

int main(){
    char primeiro_n[tam];
    char nome_m[tam];
    char nome_p[tam];
    char * nome_bebe;

    printf("Digite o primeiro nome escolhido para o bebe\n");
    scanf(" %[^\n]",primeiro_n); //deve se usar o espaço antes do % para que possa ler outro scanf em seguida

    printf("Digete o nome completo do pai :");
    scanf(" %[^\n]", nome_p);

    printf("Digite o nome completo da mae :");
    scanf(" %[^\n]",nome_m);

    nome_bebe = criaNome (primeiro_n, nome_m, nome_p);

    printf("O nome do bebe e %s \n",nome_bebe);
    free(nome_bebe);
    return 0;
}

char * criaNome (char * primeiro_n, char * nome_m, char * nome_p){
    char * ult_pai;
    char * ult_mae;
    int tam_p;
    int tam_m;
    int tam_primeiro_n;
    char * nome_bebe;
    int tam_nome_bebe;
    char branco[] = " ";

    ult_pai = ultimonome(nome_p);
    tam_p = strlen(ult_pai);
    ult_mae = ultimonome(nome_m);
    tam_m = strlen(ult_mae);
    tam_primeiro_n =strlen(primeiro_n);

    tam_nome_bebe = tam_primeiro_n + tam_m + tam_p;

    nome_bebe = (char*)malloc(sizeof(char)*(tam_nome_bebe + 3));

    if(nome_bebe == NULL){
        printf("erro ao alocar memoria");
        exit(1);
    }

    nome_bebe[0] = '\0';  // Inicializa a string vazia


    strcat(nome_bebe, primeiro_n);
    strcat(nome_bebe, branco);
    strcat(nome_bebe, ult_mae);
    strcat(nome_bebe, branco);
    strcat(nome_bebe, ult_pai);

    return nome_bebe;
}

char * ultimonome(char * nome){
    int n = strlen(nome);
    while (*(nome + n) != ' '){
        n --;
    }
    return nome + n + 1;
}

/*
Dicas Gerais
Sempre inicialize ponteiros.
Verifique o retorno de malloc.
Inicialize strings antes de usar strcat.
Use " %[^\n]" para scanf múltiplos.
Calcule corretamente o tamanho para alocação.
Verifique limites em loops de strings.
Libere memória após o uso.
*/