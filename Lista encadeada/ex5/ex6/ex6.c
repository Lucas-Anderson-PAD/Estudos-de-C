#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int codigo;
    char nome[100];
    float preco;
    struct Produto* prox;
} Produto;

Produto* inicializar_produto();
Produto* inserir_produto(Produto* lista, int codigo, const char* nome, float preco);
Produto* inserir_produtos_no_lista(Produto* lista);
void salvar_produtos_em_arquivo(Produto* lista, const char* nomearqB);
Produto* carregar_produtos_do_arquivo(const char* nomearqB);
Produto* excluir_produto(Produto* lista, int codigo);
void liberar_lista(Produto* lista);
void exibir_produtos(Produto* lista);
Produto* interacao_excluir_produto(Produto* lista);
void menu_principal();

int main() {
    menu_principal();
    return 0;
}

void menu_principal() {
    const char* nomearqB = "produtos.dat";
    Produto* lista = NULL;
    int opcao;

    do {
        printf("\nOpções:\n1: Exibir lista\n2: Adicionar produtos\n3: Excluir produto\n-1: Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            lista = carregar_produtos_do_arquivo(nomearqB);
            exibir_produtos(lista);
            liberar_lista(lista);
        }
        else if (opcao == 2) {
            lista = carregar_produtos_do_arquivo(nomearqB);
            lista = inserir_produtos_no_lista(lista);
            salvar_produtos_em_arquivo(lista, nomearqB);
            liberar_lista(lista);
        }
        else if (opcao == 3) {
            lista = carregar_produtos_do_arquivo(nomearqB);
            lista = interacao_excluir_produto(lista);
            salvar_produtos_em_arquivo(lista, nomearqB);
            liberar_lista(lista);
        }
        else if (opcao != -1) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != -1);
}

Produto* inicializar_produto() {
    return NULL;
}

Produto* inserir_produto(Produto* lista, int codigo, const char* nome, float preco) {
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    novo->preco = preco;
    novo->prox = lista;
    return novo;
}

Produto* inserir_produtos_no_lista(Produto* lista) {
    int codigo;
    char nome[100];
    float preco;

    while (1) {
        printf("Digite o código do produto ou -1 para finalizar: ");
        scanf("%d", &codigo);
        if (codigo == -1) break;

        printf("Nome do produto: ");
        scanf("%s", nome);
        printf("Preço do produto: ");
        scanf("%f", &preco);

        lista = inserir_produto(lista, codigo, nome, preco);
    }
    return lista;
}

void salvar_produtos_em_arquivo(Produto* lista, const char* nomearqB) {
    FILE* arquivo;
    int opcao;

    printf("Deseja sobrescrever (1) ou adicionar (2) os produtos no arquivo? ");
    scanf("%d", &opcao);
    arquivo = fopen(nomearqB, (opcao == 1) ? "wb" : "ab");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Produto* atual = lista;
    while (atual) {
        fwrite(atual, sizeof(Produto), 1, arquivo);
        atual = atual->prox;
    }
    fclose(arquivo);
}

Produto* carregar_produtos_do_arquivo(const char* nomearqB) {
    FILE* arquivo = fopen(nomearqB, "rb");
    if (!arquivo) {
        printf("Arquivo de produtos não encontrado.\n");
        return NULL;
    }

    Produto* lista = NULL;
    Produto temp;
    while (fread(&temp, sizeof(Produto), 1, arquivo) == 1) {
        lista = inserir_produto(lista, temp.codigo, temp.nome, temp.preco);
    }
    fclose(arquivo);
    return lista;
}

Produto* excluir_produto(Produto* lista, int codigo) {
    Produto* atual = lista;
    Produto* anterior = NULL;

    while (atual && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual) return lista; // Produto não encontrado

    if (!anterior) {
        lista = atual->prox; // Remover o primeiro da lista
    }
    else {
        anterior->prox = atual->prox;
    }
    free(atual);
    return lista;
}

Produto* interacao_excluir_produto(Produto* lista) {
    int codigo;

    while (1) {
        printf("Código do produto a excluir ou -1 para finalizar: ");
        scanf("%d", &codigo);
        if (codigo == -1) break;

        lista = excluir_produto(lista, codigo);
    }
    return lista;
}

void liberar_lista(Produto* lista) {
    Produto* temp;
    while (lista) {
        temp = lista->prox;
        free(lista);
        lista = temp;
    }
}

void exibir_produtos(Produto* lista) {
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nProdutos no Banco de Dados:\n");
    Produto* atual = lista;
    while (atual) {
        printf("Código: %d\nNome: %s\nPreço: R$%.2f\n", atual->codigo, atual->nome, atual->preco);
        printf("----------------------------------------\n");
        atual = atual->prox;
    }
}
