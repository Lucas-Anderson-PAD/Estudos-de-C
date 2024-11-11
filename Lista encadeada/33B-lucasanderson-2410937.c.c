#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno 
{ 
  int mat; 
  char nome[21]; 
  float nota;
  char sexo;
  struct aluno *prox; 
}; 
typedef struct aluno Aluno; 

Aluno *lst_cria(void);
Aluno  * lst_insere(Aluno * l, int mat,char nome[21], float nota, char sexo );
void exibe_lista(Aluno * l);
void lst_libera (Aluno* lst);
int conta_elementos(Aluno * l);
int conta_elementos_recursiva(Aluno * l);
int conta_sexo_recursiva(Aluno * l, char sexo);

Aluno * quebraAoMeio(Aluno * lista);
Aluno * fazCopia(Aluno * lista);
int maiorMatricula(Aluno * lista);
int maiorMatricula2(Aluno * lista);
Aluno * insereNaPosicao(Aluno * lista, int pos, Aluno * novo);


int main (void) 
{ 
    Aluno *lal, * lal_2, *lal_i; 
    lal = lst_cria(); 
    lal = lst_insere(lal, 33, "Caio", 3.3, 'M'); 
    lal = lst_insere(lal, 11, "Ana", 1.1, 'F'); 
    lal = lst_insere(lal, 44, "Edu", 4.4, 'M'); 
    lal = lst_insere(lal, 66, "Luiz", 6.6, 'M'); 
    lal = lst_insere(lal, 22, "Bia", 2.2, 'F');  
    lal = lst_insere(lal, 55, "Jane", 5.5, 'F'); 


    exibe_lista(lal);
    printf("\n...");
    lal_2 = fazCopia(lal);
    exibe_lista(lal_2);
    printf("\n...");
    lal_2 = quebraAoMeio(lal_2);
    exibe_lista(lal_2);
    printf("\n...");


    printf("%d", maiorMatricula(lal));

    lal_i= (Aluno*)malloc(sizeof(Aluno));

     if (lal_i == NULL) {
        printf("Erro de alocação de memória.\n");
        return -1;  // Retorna erro caso falhe a alocação
    }
    lal_i->mat = 99;
    strcpy(lal_i->nome, "Lucas");
    lal_i->nota = 8.2;
    lal_i->sexo = 'M';
    lal_i->prox = NULL;


    insereNaPosicao(lal,2,lal_i);
    lst_libera(lal); 
    lst_libera(lal_2); 

    return 0; 
}

Aluno *lst_cria(void){
    return NULL;
}


Aluno  * lst_insere(Aluno * l, int mat,char nome[21], float nota, char sexo ){
    Aluno  *novo;

    novo = (Aluno *)malloc(sizeof(Aluno));
    if(novo == NULL){
        printf("Erro ao alocar a memoria");
        exit(1);
    }

    novo ->mat=mat;
    strcpy(novo->nome,nome);// precisa certificar o \0?
    novo ->nota=nota;
    novo->sexo=sexo;

    novo ->prox=l;

    return novo;
};


void exibe_lista(Aluno * l){
    Aluno * temp;
    for(temp = l;temp!=NULL;temp=temp->prox){

        printf("\nMatricula %d \n",temp->mat);
        printf("nome %s \n", temp->nome);
        printf("nota %.2f \n", temp->nota);
        printf("sexo %c \n", temp->sexo);

        printf("---------------------------------------");
    }
}

void lst_libera (Aluno* lst) 
{ 
  Aluno *p = lst, *t; 
  while (p != NULL) 
  { 
    t = p->prox; /* guarda referência p/ próx. Aluno */ 
    free(p); /* libera a memória apontada por p */ 
    p = t; /* faz p apontar para o próximo */ 
  } 
} 


int conta_elementos(Aluno * l){
    int cont=0;
    Aluno * temp;
    for(temp= l;temp!=NULL;temp=temp->prox){
        cont ++;
    }
    return cont;
}

int conta_elementos_recursiva(Aluno * l){
    if(l==NULL){
        return 0;
    }
    return 1 + conta_elementos_recursiva(l->prox);
}

int conta_sexo_recursiva(Aluno * l, char sexo){
    if(l==NULL){
        return 0;
    }
    if(l->sexo==sexo){
    return 1 + conta_sexo_recursiva(l->prox,sexo);
    }
    else{
        return conta_sexo_recursiva(l->prox,sexo);
    }
}

Aluno* deleta_elemento(Aluno *l, int mat) {
    Aluno *anterior = NULL;
    Aluno *atual = l;

    // Percorre a lista até encontrar o elemento ou chegar ao final
    while (atual != NULL && atual->mat != mat) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o elemento não foi encontrado, retorna a lista inalterada
    if (atual == NULL) {
        printf("Elemento com matrícula %d não encontrado.\n", mat);
        return l;
    }

    // Se o elemento a ser removido é o primeiro da lista
    if (anterior == NULL) {
        l = atual->prox;  // Atualiza o início da lista
    } else {
        anterior->prox = atual->prox;  // Pula o nó a ser removido
    }

    free(atual);  // Libera a memória do nó removido
    printf("Elemento com matrícula %d removido com sucesso.\n", mat);

    return l;  // Retorna o ponteiro para o início da lista (pode ter mudado)
}

Aluno * quebraAoMeio(Aluno * lista){
    int n = conta_elementos_recursiva(lista);
    int metade = n/2;

    if (n<2){
        return NULL;
    }

    if(metade % 2!=0){
        metade ++;
    }

    Aluno * proxlista= lista->prox;

    int cont = 0;
    while(cont!=metade){
        cont ++;
        lista = lista->prox;
        proxlista= proxlista->prox;
    }

    lista->prox =NULL;
    return proxlista;
}


Aluno * fazCopia(Aluno * lista){
    Aluno * novalista = NULL;
    if(lista == NULL){
        return novalista;
    }
    novalista = (Aluno *)malloc(sizeof(Aluno));


    strcpy(novalista->nome,lista->nome);
    novalista->mat=lista->mat;
    novalista->nota=lista->nota;
    novalista->sexo=lista->sexo;
    novalista->prox=fazCopia(lista->prox);

    return novalista;
}

int maiorMatricula(Aluno * lista){
    if (lista ==NULL){
        return -1;
    }
    int atual = lista->mat;
    int prox = maiorMatricula(lista->prox);//para só fazer a recurção uma vez
    if(prox>atual){
         return prox;
    }
    return atual;
}

int maiorMatricula2(Aluno * lista){
    if (lista ==NULL){
        return -1;
    }
    int maiormat = lista->mat;

    while(lista != NULL){
        if(lista->mat>maiormat){
            maiormat= lista->mat;
        }
        lista = lista->prox;
    }
    return maiormat;
}

Aluno * insereNaPosicao(Aluno * lista, int pos, Aluno * novo){
    Aluno * primeiro = lista;
    if(lista == NULL|| novo ==NULL){
        return NULL;
    }
    
    if(pos==0){
        novo->prox= lista;
        return novo;
    }

    Aluno * anterior=NULL;
    if(lista!=NULL){
        for(int i =1; i< pos;i++){
            anterior = lista;
            lista = lista ->prox;
    }

    if(anterior != NULL){
            anterior->prox= novo;
    }
    novo->prox= lista;
    
    }

    return primeiro;
}