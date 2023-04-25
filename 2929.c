#include <stdio.h>
#include <stdlib.h>

typedef struct lista_encadeada {
    struct item *inicio;
} lista_encadeada;

typedef struct item {
    int valor;
    struct item *proximo_item;
} item;

lista_encadeada *criar_lista();
item *criar_item();
void adicionar_item_na_pilha(lista_encadeada *pilha, int valor_a_ser_adicionado);
void retirar_item_da_pilha(lista_encadeada *pilha);
void mostrar_menor_valor_da_pilha(lista_encadeada *pilha);

int main() {
    return 0;
}

lista_encadeada *criar_lista() {
    lista_encadeada *nova_lista;
    nova_lista = (lista_encadeada*)calloc(1, sizeof(lista_encadeada));
    return nova_lista;
}

item *criar_item() {
    item *novo_item;
    novo_item = (item*)calloc(1, sizeof(item));
    return novo_item;
};

void adicionar_item_na_pilha(lista_encadeada *pilha, int valor_a_ser_adicionado) {
    item *novo_item = criar_item();
    novo_item->valor = valor_a_ser_adicionado;

    if (pilha->inicio == NULL) {
        pilha->inicio == novo_item;
    } else {
        novo_item->proximo_item = pilha->inicio;
        pilha->inicio = novo_item;
    }
}

void retirar_item_da_pilha(lista_encadeada *pilha) {
    if (pilha->inicio == NULL) {
        printf("EMPTY\n");
    } else {

    }
}

void mostrar_menor_valor_da_pilha(lista_encadeada *pilha);