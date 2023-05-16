#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    int quantidade_de_itens;
    struct item *topo;
} pilha;

typedef struct item {
    char caractere;
    struct item *proximo_item;
} item;

pilha *criar_pilha();
item *criar_item();
void adicionar_item_na_pilha(pilha *pilha_atual, char caractere);
void retirar_item_da_pilha(pilha *pilha_atual);
int pilha_de_parenteses_eh_valido(const char *expressao);

int main() {
    int i;
    char expressao_de_entrada[1001];
    
    while (scanf("%s", expressao_de_entrada) != EOF) {
        if (pilha_de_parenteses_eh_valido(expressao_de_entrada)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}

pilha *criar_pilha() {
    pilha *nova_pilha = (pilha*)calloc(1, sizeof(pilha));
    return nova_pilha;
}

item *criar_item() {
    item *novo_item = (item*)calloc(1, sizeof(item));
    return novo_item;
}

void adicionar_item_na_pilha(pilha *pilha_atual, char caractere) {
    item *novo_item = criar_item();

    if (pilha_atual->topo == NULL) {
        pilha_atual->topo = novo_item;
    } else {
        novo_item->proximo_item = pilha_atual->topo;
        pilha_atual->topo = novo_item;
    }

    pilha_atual->quantidade_de_itens++;
}

void retirar_item_da_pilha(pilha *pilha_atual) {
    if (pilha_atual->topo == NULL) {
        return;
    }
    
    item *auxiliar = pilha_atual->topo;
    pilha_atual->topo = auxiliar->proximo_item;
    free(auxiliar);

    pilha_atual->quantidade_de_itens--;
}

int pilha_de_parenteses_eh_valido(const char *expressao) {
    int i;
    int tamanho_da_expressao = strlen(expressao);
    pilha *pilha_de_parenteses = criar_pilha();

    for (i = 0; i < tamanho_da_expressao; i++) {
        if (expressao[i] == '(') {
            adicionar_item_na_pilha(pilha_de_parenteses, '(');
        } else if (expressao[i] == ')') {
            if (pilha_de_parenteses->quantidade_de_itens == 0) {
                return 0;
            }
            retirar_item_da_pilha(pilha_de_parenteses);
        }
    }

    return pilha_de_parenteses->quantidade_de_itens == 0;
}
