#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct livro {
	char titulo[51];
	char nome[51];
	int ano;
	struct livro* prox;
};

typedef struct livro Livro;

Livro * inicializar_lista();
Livro* inserir_livro(Livro* prox, char* titulo, char* nome, int ano);
Livro* criar_lista();
void exibir_lista(Livro* lista);
int livros_apos_ano(int ano, Livro* lista);
Livro* livro_mais_recente(Livro* lista);
void liberar_memoria(Livro* lista);
void saida();


int main(void) {
	saida();

	return 0;
}

Livro * inicializar_lista() {
	return NULL;
}

Livro* inserir_livro(Livro* prox, char* titulo, char* nome, int ano) {
	Livro* novo;
	novo = (Livro*)malloc(sizeof(Livro));

	if (novo == NULL) {
		printf("Erro ao alocar memoria");
		exit(1);
	}

	strcpy(novo->titulo, titulo);
	strcpy(novo->nome, nome);
	novo->ano = ano;
	novo->prox = prox;

	return novo;
}

Livro * criar_lista() {
	FILE* arq;
	arq = fopen("livros.txt", "r");

	if (arq == NULL) {
		printf("Erro ao abrir arquivo");
		exit(2);
	}


	Livro* lista;
	lista = inicializar_lista();


	char tempnome[51];
	char temptitulo[51];
	int tempano=0;
	while (fscanf(arq, " %[^;]; %[^;]; %d", temptitulo, tempnome, &tempano) == 3) {
		lista = inserir_livro(lista, temptitulo, tempnome, tempano);
	}
	fclose(arq);
	return lista;
}


void exibir_lista(Livro* lista) {
	int i = 1;
	while (lista != NULL) {
		printf("Dados do Livro %d\n",i);
		printf("Titulo %s\n", lista->titulo);
		printf("O autor(a) foi %s\n", lista->nome);
		printf("O ano de lançamento foi %d\n", lista->ano);

		lista = lista->prox;
		i++;
	}
}


int livros_apos_ano(int ano,Livro * lista) {
	int cont = 0;
	while (lista != NULL) {
		if (lista->ano > ano) {
			cont++;
		}
		lista =lista->prox;
	}
	return cont;
}

Livro* livro_mais_recente(Livro * lista) {
	Livro* recente = lista;


	while (lista != NULL) {
		if (lista->ano > recente->ano) {
			recente = lista;
		}
		lista = lista->prox;
	}

	return recente;
}

void liberar_memoria(Livro* lista) {

	Livro* temp;
	while (lista != NULL) {
		temp = lista->prox;
		free(lista);
		lista = temp;

	}
}

void saida() {
	Livro* livros = criar_lista();
	Livro* recente;
	int resp1 = -1, resp2 = -1;
	int ano, posano;

	printf("Digite 1 se quiser Exibir todos os livros na tela.\n Digite 2 se quiser Exibir o número de livros publicados após um ano\nDigite 3 se quiser Exibir o título e autor do livro mais recente");
	scanf("%d", &resp1);

	if(resp1 == 1){
		exibir_lista(livros);
	}
	else if(resp1 == 2) {
		printf("Digite o ano que deseja usar como parametro");
		scanf("%d", &ano);

		posano = livros_apos_ano(ano, livros);
		printf("Número de livros publicados após o ano %d: %d\n", ano, posano);  // Correção: Exibido o resultado para o usuário

	}
	else if (resp1 == 3) {
		recente = livro_mais_recente(livros);

		printf("O livro mais recente é :\n");
		printf("%s, de %s\n", recente->titulo,recente->nome);
	}
	else {
		while (resp2 != 1 && resp2 != 0) {
			printf("resposta invalida deseja\nDeseja tentar novamente\n dite 1 para sim e 0 para não\n");
			scanf("%d", &resp2);

			if (resp2==1) {
				saida();
			}
		}
	}

	liberar_memoria(livros);
}