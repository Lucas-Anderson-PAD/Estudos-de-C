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

Aluno * deletarelemento(Aluno * lista, int mat){
    Aluno * anterior = NULL; 
    Aluno * atual = lista;


    while(atual != NULL && atual->mat != mat){
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL){
        return lista;
    }

    if(anterior==NULL){
        lista = lista->prox;
    }
    else{
        anterior->prox=atual->prox;
    }
    
    
    free(atual);
    return lista;
}