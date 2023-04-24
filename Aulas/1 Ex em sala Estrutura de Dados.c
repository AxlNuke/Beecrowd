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
void adicionar_um_item_inicio_lista(lista_encadeada *lista, int valor);
void remover_item_da_lista(lista_encadeada *lista);
int mostrar_opcoes();
void apertar_qualquer_tecla_para_continuar();
void mostrar_lista(lista_encadeada *lista);
item *buscar_item_na_lista(lista_encadeada *lista, int valor);
void escolher_e_buscar_item_na_lista(lista_encadeada *lista);
void bubblesort(lista_encadeada *lista);
void adicionar_itens_aleatorios_na_lista(lista_encadeada *lista, int quantidade_de_itens_a_serem_adicionados);
void opcoes_de_adicionar_itens_na_lista(lista_encadeada *lista);


int main() {

    int estado_atual_do_programa = -1, parar_programa = 0;
    lista_encadeada *pilha = criar_lista_encadeada();

    while (estado_atual_do_programa != parar_programa) {

        estado_atual_do_programa = mostrar_opcoes();

        switch (estado_atual_do_programa) {
        case 0:
            printf("Encerrando programa.\n");
            break;
        case 1:
            opcoes_de_adicionar_itens_na_lista(pilha);
            break;
        case 2:
            remover_item_da_lista(pilha);
            break;
        case 3:
            escolher_e_buscar_item_na_lista(pilha);
            break;
        case 4:
            mostrar_lista(pilha);
            break;
        case 5:
            bubblesort(pilha);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
        apertar_qualquer_tecla_para_continuar();
    }

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

void adicionar_um_item_inicio_lista(lista_encadeada *lista, int valor) {

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

    if (lista->inicio == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    item *auxiliar = lista->inicio;
    lista->inicio = auxiliar->proximo_item;
    free(auxiliar);
    lista->quantidade_itens--;
    printf("Item removido com sucesso!\n");
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
    if (lista->inicio == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Mostrando pilha com %d valores:\n", lista->quantidade_itens);
    item *item_a_mostrar = lista->inicio;
    while (item_a_mostrar != NULL) {
        printf("%d ", item_a_mostrar->valor);
        item_a_mostrar = item_a_mostrar->proximo_item;
    }
    printf("\n");
}

void escolher_e_buscar_item_na_lista(lista_encadeada *lista) {
    int valor_a_ser_buscado;
    item *item_encontrado;

    if (lista->inicio == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Digite um valor a ser buscado na pilha:\n");
    scanf("%d", &valor_a_ser_buscado);
    item_encontrado = buscar_item_na_lista(lista, valor_a_ser_buscado);
    if (item_encontrado == NULL) {
        printf("Valor %d nao foi encontrado na pilha!\n", valor_a_ser_buscado);
    } else {
        printf("Valor %d foi encontrado na pilha!\n", item_encontrado->valor);
    }
}

item *buscar_item_na_lista(lista_encadeada *lista, int valor) {
    item *item_atual = lista->inicio;

    while (item_atual != NULL) {
        if (item_atual->valor == valor) {
            return item_atual;
        }
        item_atual = item_atual->proximo_item;
    }

    return NULL;
}

void adicionar_itens_aleatorios_na_lista(lista_encadeada *lista, int quantidade_de_itens_a_serem_adicionados) {
    int valor_aleatorio, valor_aleatorio_maximo;

    printf("Qual valor maximo voce quer que possa ser escolhido aleatoriamente?\n");
    scanf("%d", &valor_aleatorio_maximo);
    system("cls");

    if (valor_aleatorio_maximo <= 0) {
        printf("Escolha um valor maior que 0.\n");
        return;
    }

    for (int i = 0; i < quantidade_de_itens_a_serem_adicionados; i++) {
        valor_aleatorio = rand() % valor_aleatorio_maximo + 1;
        adicionar_item_inicio_lista(lista, valor_aleatorio);
    }
    printf("Valores aleatorios adicionados com sucesso.\n");
}

void opcoes_de_adicionar_itens_na_lista(lista_encadeada *lista) {
    int valor_a_ser_adicionado, quantidade_de_itens_a_serem_adicionados, sim_ou_nao;

    printf("Digite quantos itens voce quer adicionar:\n");
    scanf("%d", &quantidade_de_itens_a_serem_adicionados);
    system("cls");

    if (quantidade_de_itens_a_serem_adicionados <= 0) {
        printf("Selecione um valor valido.\n");
        return;
    }

    printf("Deseja que os valores sejam aleatorios?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%d", &sim_ou_nao);
    system("cls");

    switch (sim_ou_nao) {
    case 1:
        adicionar_itens_aleatorios_na_lista(lista, quantidade_de_itens_a_serem_adicionados);
        break;
    case 2:
        for (int i = 0; i < quantidade_de_itens_a_serem_adicionados; i++) {
            printf("Digite o %d valor: ", i+1);
            scanf("%d", &valor_a_ser_adicionado);
            adicionar_item_inicio_lista(lista, valor_a_ser_adicionado);
        }
        system("cls");
        printf("Valores adicionados com sucesso.\n");
        break;
    default:
        system("cls");
        printf("Opcao invalida.\n");
        break;
        }
}

void bubblesort(lista_encadeada *lista) {
    item *aux1, *aux2;
    int guarda_valor;

    if (lista->inicio == NULL)  {
        printf("Pilha Vazia!\n");
        return;
    }

    for (aux1 = lista->inicio; aux1 != NULL; aux1 = aux1->proximo_item) {
        for (aux2 = aux1->proximo_item; aux2 != NULL; aux2 = aux2->proximo_item) {
            if (aux1->valor > aux2->valor) {
                guarda_valor = aux1->valor;
                aux1->valor = aux2->valor;
                aux2->valor = guarda_valor;
            }
        }
    }

    printf("Pilha organizada usando Bubble Sort!\n");
}