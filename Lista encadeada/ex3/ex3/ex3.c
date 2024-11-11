#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define n_linhas 100

struct aluno {
	char nome[51];
	int idade;
	int matricula;

	struct aluno* proximo;
};

typedef struct aluno Aluno;

Aluno* criarlistaencadeada();
Aluno* criar_lista(void);
Aluno* insere_lista(Aluno* e, char nome[41], int idade, int matricula);
void salvararqbin(Aluno* e);
void imprimelista(Aluno* e);
void saida();


int main() {
	saida();
}


Aluno * criarlistaencadeada() {
	FILE* arq;
	arq = fopen("entrada.txt", "r");

	if (arq == NULL) {
		printf("Erro ao abrir arquivo");
		exit(1);
	}

	Aluno * elemento;
	elemento = criar_lista();


	if (elemento == NULL) {
		printf("erro ao alocar memora");
	}

	int i = 0;
	char tempnome [51];//coloque errado *
	char tempsobrenome[51];
	int idade = 0;
	int matricula = 0;

	while (fscanf(arq, " %s %s %d %d", tempnome, tempsobrenome, &idade, &matricula)==4) {//faltou & e a iqualdade a 4
		char* nome = (char*)malloc(sizeof(char) * (strlen(tempnome) + strlen(tempsobrenome) + 2));

		strcpy(nome, tempnome);
		strcat(nome, " ");
		strcat(nome, tempsobrenome);

		elemento = insere_lista(elemento, nome, idade, matricula);
	}

	return elemento;
}

Aluno * criar_lista(void) {
	return NULL;
}


Aluno* insere_lista(Aluno* e, char * nome, int idade, int matricula) {
	Aluno* novo;

	novo = (Aluno*)malloc(sizeof(Aluno));
	
	if (novo == NULL) {
		printf("Erro ao alocar memora");
		exit(1);
	}

	strcpy(novo->nome, nome);
	novo->idade = idade;
	novo->matricula = matricula;
	novo->proximo = e;

	return novo;
}

void salvararqbin(Aluno * e) {

	FILE* arqB;
	arqB = fopen("estudantes.dat", "wb");

	if (arqB == NULL) {
		printf("Erro ao abrir arquivo");
		exit(1);
	}


	while (e != NULL) {
		fwrite(e, sizeof(Aluno), 1, arqB);

		e = e->proximo;
	}


	fclose(arqB);

}

void imprimelista(Aluno * e) {
	while (e != NULL) {
		printf("%s ", e->nome);
		printf("%d ", e->idade);
		printf("%d\n", e->matricula);
		e = e->proximo;
	}
}


void saida() {
	int resp2 = -1;
	int resp = -1;
	Aluno* aluno;

	aluno = criarlistaencadeada();//havia esquecido do ()

	if (aluno == NULL) {//esqueci
		printf("Erro ao alocar memoria");
		exit(1);
	}


	printf("Digite 1 se quiser exibir a lista;\nDigite 0 se quiser salvar em arquivo binario");
	scanf("%d", &resp);//esqueci de &

	if (resp == 1) {
		imprimelista(aluno);
	}
	else if (resp == 0) {
		salvararqbin(aluno);
	}
	else {
		printf("Entrada invalida quer tentar novamente?\n Digite 1 para sim e 0 para não");
		scanf("%d", &resp2);
		if (resp2 == 1) {
			saida();
		}
	}

	free(aluno);
	return 0;
}