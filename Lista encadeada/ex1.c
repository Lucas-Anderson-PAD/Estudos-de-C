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
Aluno  * lst_insere(Aluno * l, int mat,char nome[21], float nota, char * sexo );
void exibe_lista(Aluno * l);
void lst_libera (Aluno* lst);
int conta_elementos(Aluno * l);
int conta_elementos_recursiva(Aluno * l);
int conta_sexo_recursiva(Aluno * l, char sexo);


int main (void) 
{ 
    Aluno *lal; 
    lal = lst_cria(); 
    lal = lst_insere(lal, 33, "Caio", 3.3, 'M'); 
    lal = lst_insere(lal, 11, "Ana", 1.1, 'F'); 
    lal = lst_insere(lal, 44, "Edu", 4.4, 'M'); 
    lal = lst_insere(lal, 66, "Luiz", 6.6, 'M'); 
    lal = lst_insere(lal, 22, "Bia", 2.2, 'F');  
    lal = lst_insere(lal, 55, "Jane", 5.5, 'F'); 




    lst_libera(lal); 
    return 0; 
}

Aluno *lst_cria(void){
    return NULL;
}


Aluno  * lst_insere(Aluno * l, int mat,char nome[21], float nota, char * sexo ){
    Aluno  *novo;

    novo = (Aluno *)malloc(sizeof(Aluno));
    if(novo == NULL){
        printf("Erro ao alocar a memoria");
        exit(1);
    }

    novo ->mat=mat;
    strcpy(novo->nome,nome);// precisa certificar o \0?
    novo ->nota=nota;
    strcpy(novo->sexo,sexo);

    novo ->prox=l;

    return novo;
};


void exibe_lista(Aluno * l){
    Aluno * temp;
    for(temp = l;temp!=NULL;temp=temp->prox){

        printf("Matricula %d \n",temp->mat);
        printf("nome %s \n", temp->nome);
        printf("nota %f \n", temp->nota);
        printf("sexo %s \n", temp->sexo);

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
    if(strcmp(l->sexo,sexo)==0){
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

