#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct item {
    int valor;
    struct item *proximo_item;
} item;

typedef struct lista_encadeada {
    int quantidade_itens;
    item *inicio;
} lista_encadeada;

lista_encadeada *criar_lista_encadeada();
item *criar_item();
void adicionar_item_inicio_lista(lista_encadeada *lista, int valor);
void remover_item_da_lista(lista_encadeada *lista);
int mostrar_opcoes();
void apertar_qualquer_tecla_para_continuar();
void mostrar_lista(lista_encadeada *lista);
int buscar_item_na_lista(lista_encadeada *lista, int valor);
void bubblesort(lista_encadeada *pilha);


int main() {

    int estado_do_programa;
    int parar_programa = 0;
    lista_encadeada *pilha = criar_lista_encadeada();
    int valor_a_ser_adicionado, valor_a_ser_buscado, valor_encontrado;

    do {
        estado_do_programa = mostrar_opcoes();

        switch (estado_do_programa) {
        case 0:
            printf("Encerrando programa!\n");
            break;
        case 1:
                printf("Digite um valor a ser adicionado:\n");
                scanf("%d", &valor_a_ser_adicionado);
                if (valor_a_ser_adicionado == 0) {
                    printf("O valor não pode ser nulo.\n");
                } else {
                    adicionar_item_inicio_lista(pilha, valor_a_ser_adicionado);
                    printf("Valor adicionado com sucesso na pilha!\n");
                }
            break;
        case 2:
            if (pilha->inicio == NULL) {
                printf("Pilha vazia!\n");
            } else {
                remover_item_da_lista(pilha);
                printf("Item removido com sucesso!\n");
            }
            break;
        case 3:
            if (pilha->inicio == NULL) {
                printf("Pilha vazia!\n");
            } else {
                printf("Digite um valor a ser buscado na pilha:\n");
                scanf("%d", &valor_a_ser_buscado);
                valor_encontrado = buscar_item_na_lista(pilha, valor_a_ser_buscado);
                if (valor_encontrado == 0) {
                    printf("Valor %d nao existe na pilha!\n", valor_a_ser_buscado);
                } else {
                    printf("Valor %d foi encontrado na pilha!\n", valor_a_ser_buscado);
                }
            }
            break;
        case 4:
            if (pilha->inicio == NULL) {
                printf("Pilha vazia!\n");
            } else {
                printf("Mostrando pilha com %d valores:\n", pilha->quantidade_itens);
                mostrar_lista(pilha);
                printf("\n");
            }
            break;
        case 5:
            bubblesort(pilha);
            printf("Pilha organizada usando Bubble Sort!\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
        apertar_qualquer_tecla_para_continuar();
    } while (estado_do_programa != parar_programa);

    return 0;
}

lista_encadeada *criar_lista_encadeada() {

    lista_encadeada *nova_lista;
    nova_lista = (lista_encadeada*)calloc(1, sizeof(lista_encadeada));

    return nova_lista;
}

item *criar_item() {

    item *novo_item;
    novo_item = (item*)calloc(1, sizeof(item));

    return novo_item;
}

void adicionar_item_inicio_lista(lista_encadeada *lista, int valor) {

    item *novo_item = criar_item();

    novo_item->valor = valor;
    
    if (lista->inicio == NULL) {
        lista->inicio = novo_item;
    } else {
        novo_item->proximo_item = lista->inicio;
        lista->inicio = novo_item;
    }

    lista->quantidade_itens++;
}

void remover_item_da_lista(lista_encadeada *lista) {
    item *auxiliar = lista->inicio;
    lista->inicio = auxiliar->proximo_item;
    free(auxiliar);
}

void apertar_qualquer_tecla_para_continuar() {
    printf("\nPressione qualquer tecla para continuar...\n");
    getch();
    system("cls");
}

int mostrar_opcoes() {
    int opcao_selecionada;
    printf("PILHA\n");
    printf("Escolha uma opcao:\n");
    printf("1 - Adicionar item\n");
    printf("2 - Remover item\n");
    printf("3 - Buscar item\n");
    printf("4 - Mostrar pilha\n");
    printf("5 - Organizar pilha usando (BubbleSort)\n");
    printf("\n0 - Terminar programa\n");
    scanf("%d", &opcao_selecionada);
    system("cls");
    return opcao_selecionada;
}

void mostrar_lista(lista_encadeada *lista) {
    item *item_a_mostrar = lista->inicio;
    while (item_a_mostrar != NULL) {
        printf("%d ", item_a_mostrar->valor);
        item_a_mostrar = item_a_mostrar->proximo_item;
    }
}

int buscar_item_na_lista(lista_encadeada *lista, int valor) {
    item *item_atual = lista->inicio;
    while (item_atual != NULL) {
        if (item_atual->valor == valor) {
            return item_atual->valor;
        }
        item_atual = item_atual->proximo_item;
    }
    return 0;
}

void bubblesort(lista_encadeada *lista) {
    if (lista->inicio == NULL)  {
        printf("Pilha Vazia!"); }
    item *aux1, *aux2;
    int guarda_valor;
    for (aux1 = lista->inicio; aux1 != NULL; aux1 = aux1->proximo_item) {
        for (aux2 = aux1->proximo_item; aux2 != NULL; aux2 = aux2->proximo_item) {
            if (aux1->valor > aux2->valor) {
                guarda_valor = aux1->valor;
                aux1->valor = aux2->valor;
                aux2->valor = guarda_valor;
            }
        }
    }
}