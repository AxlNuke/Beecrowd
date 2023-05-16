#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char caractere;
    struct no* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha* pilha, char caractere) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->caractere = caractere;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

char desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        return '\0';
    }

    No* topoAnterior = pilha->topo;
    char caractere = topoAnterior->caractere;
    pilha->topo = topoAnterior->proximo;
    free(topoAnterior);
    return caractere;
}

int contarDiamantes(const char* expressao) {
    Pilha* pilha = criarPilha();
    int diamantes = 0;
    int i;

    for (i = 0; i < strlen(expressao); i++) {
        char caractere = expressao[i];

        if (caractere == '<') {
            empilhar(pilha, caractere);
        } else if (caractere == '>') {
            if (desempilhar(pilha) == '<') {
                diamantes++;
            }
        }
    }

    free(pilha);
    return diamantes;
}

int main() {
    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        char expressao[1001];
        scanf("%s", expressao);

        int resultado = contarDiamantes(expressao);
        printf("%d\n", resultado);
    }

    return 0;
}