#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int valor;
    struct item* proximo_item;
} item;

typedef struct lista_encadeada {
    int quantidade_itens;
    item* inicio;
} lista_encadeada;

lista_encadeada* criar_lista_encadeada();
item* criar_item();
void adicionar_item_inicio_lista(lista_encadeada* lista, int valor);
void adicionar_item_final_lista(lista_encadeada* lista, int valor);

int main() {

    item* primeiro;
    item* segundo;

    primeiro = (item*)calloc(1, sizeof(item));
    segundo = (item*)calloc(1, sizeof(item));

    primeiro->valor = 1;
    primeiro->proximo_item = segundo;

    segundo->valor = 22;
    segundo->proximo_item = NULL;    

    printf("%d, %d\n", primeiro->valor, primeiro->proximo_item);
    printf("%d, %d\n", segundo->valor, segundo->proximo_item);

    return 0;
}

lista_encadeada* criar_lista_encadeada() {

    lista_encadeada* nova_lista;
    nova_lista = (lista_encadeada*)calloc(1, sizeof(lista_encadeada));

    return nova_lista;
}

item* criar_item() {

    item* novo_item;
    novo_item = (item*)calloc(1, sizeof(item));

    return novo_item;
}

void adicionar_item_inicio_lista(lista_encadeada* lista, int valor) {

    item* novo_item = criar_item();

    novo_item->valor = valor;
    
    if (lista->inicio == NULL) {
        lista->inicio = novo_item;
    } else {
        novo_item->proximo_item = lista->inicio;
        lista->inicio = novo_item;
    }

    lista->quantidade_itens++;
}

void adicionar_item_final_lista(lista_encadeada* lista, int valor) {
    
    item* novo_item = criar_item();

    novo_item->valor = valor;

    if (lista->inicio == NULL) {
        lista->inicio = novo_item;
    } else {
        item* auxiliar = lista->inicio;
        while (auxiliar != NULL) {
            auxiliar = auxiliar->proximo_item;
        }
        novo_item->proximo_item = auxiliar;
    }


}