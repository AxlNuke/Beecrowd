#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
void remover_item_da_lista(lista_encadeada* lista, int valor);
int mostrar_opções();
void apertar_qualquer_tecla_para_continuar();

int main() {

    int estado_do_programa;
    int parar_programa = 0;

    do {
        mostrar_opções();
    } while (estado_do_programa != parar_programa);
    
    // lista_encadeada* nova_lista;
    // int continuar_programa = 0;

    // if (opcao_selecionada == 1) {
    //     nova_lista = criar_lista_encadeada();
    //     printf("Lista criada com sucesso!\n");
    // } else {
    //     printf("Opcao invalida!\n");
    // }

    // apertar_qualquer_tecla_para_continuar();

    // printf("CRIADOR DE LISTAS\nEscolha uma opcao:\n1 - Adicionar item no inicio da lista\n2 - Adicionar item no final da lista\n3 - Remover item\n");
    // scanf("%d", &opcao_selecionada);
    // system("cls");

    // switch (opcao_selecionada) {
    // case 1:
    //     int item_a_ser_adicionado;
    //     printf("Digite o valor do item a ser adicionado:\n");
    //     scanf("%d", item_a_ser_adicionado);
    //     adicionar_item_inicio_lista(nova_lista, item_a_ser_adicionado);
    //     printf("Item adicionado com sucesso no começo da lista;")
    //     break;
    // default:
    //     printf("Opcao invalida!\n");
    //     break;
    // }

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
        auxiliar->proximo_item = novo_item;
    }

    lista->quantidade_itens++;
}

void remover_item_da_lista(lista_encadeada* lista, int valor) {
    
    if (lista->inicio == NULL) {
        return;
    }
}

void apertar_qualquer_tecla_para_continuar() {
    printf("\nPressione qualquer tecla para continuar...\n");
    getch();
    system("cls");
}

int mostrar_opções() {
    int opcao_selecionada;
    printf("CRIADOR DE LISTAS\nEscolha uma opcao:\n1 - Criar Lista\n2 - Adicionar item no inicio da lista\n3 - Adicionar item no final da lista\n4 - Remover item\n5 - Mostrar lista\n\n0 - Terminar programa\n");
    scanf("%d", &opcao_selecionada);
    system("cls");
    return opcao_selecionada;
}