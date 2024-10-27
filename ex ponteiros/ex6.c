#include <stdio.h>
#define n_reis_rainhas 10

void numero_de_alunos(int * n);
void cod_reis(int n, int * vetor);
int busca_posicao(int * vetor, int e, int n);
void votacao(int * candidatorei,int * candidatarainha, int n, int * votosrei, int *votosrainha, int n_r);
void listadevotos(int * candidatos,int *votos, int n_r, char * tipo);
int voto(int tempcand, int *vetor, int n, char * tipo);
void min_max(int *votos,int n, int *posmax,int *posmin);
void imprimeresultado(int * candidatorei, int posmaxrei, int posminrei, int *votosrei ,int * candidatarainha,  int posmaxrainha, int posminrainha, int * votosrainha, int n);

int main(){
    int n;
    int  candidatarainha [n_reis_rainhas] = {1,2,3,4,5,6,7,8,9,10};
    int candidatorei[n_reis_rainhas];
    int votosrei[n_reis_rainhas] = {0};
    int votosrainha[n_reis_rainhas] = {0};
    int posmaxrei, posminrei, posmaxrainha, posminrainha;

    numero_de_alunos(&n);
    
    cod_reis(n_reis_rainhas, candidatorei);

    votacao(candidatorei,candidatarainha, n, votosrei, votosrainha,n_reis_rainhas);
    min_max(votosrei, n_reis_rainhas, &posmaxrei, &posminrei);
    min_max(votosrainha, n_reis_rainhas, &posmaxrainha, &posminrainha);
    imprimeresultado(candidatorei,posmaxrei, posminrei, votosrei,candidatarainha,posmaxrainha, posminrainha, votosrainha, n);
}

void numero_de_alunos(int * n){
    printf("Digite o numero de alunos da escola");
    scanf("%d", n);
}

void cod_reis(int n, int * vetor){
    for(int i = 0; i < n;i++){
        printf("Digite o codigo de cada candidato a rei %d ", i+ 1);
        scanf("%d", &vetor[i]);
    }
}

int busca_posicao(int * vetor, int e, int n){
    for(int i = 0;i<n;i++){
        if(*(vetor + i)==e){
            return i;
        }
    }
    return -1;
}

void votacao(int * candidatorei,int * candidatarainha, int n, int * votosrei, int *votosrainha, int n_r){
    char * rei = "rei";
    char * rainha = "rainha";
        for (int i = 0; i < n;i++){
            listadevotos(candidatorei,votosrei, n_r, rei);
            listadevotos(candidatarainha,votosrainha, n_r, rainha);
        }
}


void listadevotos(int * candidatos,int *votos, int n_r, char * tipo){
    int tempcad=0;
    int temppos=0;
    int cont;
    temppos = voto(tempcad, candidatos, n_r, tipo);

    if(temppos != -1){
        *(votos + temppos) +=1; 
    }
    else{
        printf("candidato não encontrado");
        printf("Deseja votar novamente? Digite 1 se sim e -1 se não");
        scanf("%d", &cont);
        if (cont ==1){     
            temppos = voto(tempcad, candidatos, n_r, tipo);
            if(temppos != -1){
            *(votos + temppos) +=1; 
            }
        }
        
        else if (cont ==-1){
            printf("Seu voto foi anulado");
        }
        else{
            printf("Resposta invalida seu voto foi anulado");
        }
            
    }
}


int voto(int tempcand, int *vetor, int n, char * tipo){
    int temppos;

    printf("Digite o voto do candidato a %s", tipo);
    scanf("%d",&tempcand);

    temppos = busca_posicao(vetor, tempcand, n);
    return temppos;
}

void min_max(int *votos,int n, int *posmax,int *posmin){
    int min = 11, max =0;

    for(int i=0; i < n;i++){
        if (*(votos + i)< min){
            *posmin = i;
            min = *(votos + i);
        }
        if(*(votos+i) > max){
            *posmax = i;
            max = *(votos + i);
        }
    }
}

void imprimeresultado(int * candidatorei, int posmaxrei, int posminrei, int *votosrei ,int * candidatarainha,  int posmaxrainha, int posminrainha, int * votosrainha, int n){
    float porcentagem;
    

    printf("O CANDIDATO  A REI VENCEDOR e...\n");

    printf("O candidato %d\n", *(candidatorei + posmaxrei));

    porcentagem = ((float)(*(votosrei + posmaxrei))/n)*100;
    printf("Sua contagem devotos foi %d que euqivale a %.1f", *(votosrainha + posmaxrainha), porcentagem);

    printf("E agora a vencedora como rainha e...\n A candidata %d\n", *(candidatarainha + posmaxrainha ) );

    porcentagem = ((float)(*(votosrainha + posmaxrainha))/n)*100;
    printf("Sua contagem devotos foi %d que euqivale a %.1f", *(votosrainha + posmaxrainha), porcentagem);

    printf("E os lanterninhas a rei e rainha sao respequitivamente os candidatos %d e %d\n", *(candidatorei + posminrei),  *(candidatarainha + posminrainha ));

}