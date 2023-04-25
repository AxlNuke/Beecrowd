// Faça um programa que aloque 1 lista encadeada e inclua nessa lista todos os números primos entre 1 e 100.
// No mesmo programa utilize uma lista duplamente ligada que possua todos os números ímpares entre 50 e 100.

// Mostre na tela os valores que estão presentes nas 2 listas ao mesmo tempo.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista_encadeada_simples {
    int quantidade_de_itens;
    struct item_encadeado_simples *inicio;
} lista_encadeada_simples;

typedef struct item_encadeado_simples {
    int valor;
    struct item_encadeado_simples *proximo_item;
} item_encadeado_simples;

typedef struct lista_duplamente_encadeada {
    int quantidade_de_itens;
    struct item_duplamente_encadeado *inicio;
    struct item_duplamente_encadeado *final;
} lista_duplamente_encadeada;

typedef struct item_duplamente_encadeado {
    int valor;
    struct item_duplamente_encadeado *item_anterior;
    struct item_duplamente_encadeado *proximo_item;
} item_duplamente_encadeado;

bool eh_primo(int valor_a_ser_verificado);
lista_encadeada_simples *criar_lista_encadeada_simples();
lista_duplamente_encadeada *criar_lista_duplamente_encadeada();
item_encadeado_simples *criar_item_encadeado_simples();
item_duplamente_encadeado *criar_item_duplamente_encadeado();
void adicionar_primos_na_lista_encadeada_simples(lista_encadeada_simples lista);
void adicionar_primos_na_lista_duplamente_encadeada(lista_duplamente_encadeada lista);

int main() {
    return 0;
}

bool eh_primo(int valor_a_ser_verificado) {
    int eh_primo = true, nao_eh_primo = false;
    int metade_do_valor_a_ser_verificado = valor_a_ser_verificado / 2;

    for (int i = 2; i <= metade_do_valor_a_ser_verificado; i++) {
        if (valor_a_ser_verificado % i == 0) {
            return nao_eh_primo;
        }
    }

    return eh_primo;
}

lista_encadeada_simples *criar_lista_encadeada_simples() {
    lista_encadeada_simples *nova_lista;
    nova_lista = (lista_encadeada_simples*)calloc(1, sizeof(lista_encadeada_simples));
    return nova_lista;
}

lista_duplamente_encadeada *criar_lista_duplamente_encadeada() {
    lista_duplamente_encadeada *nova_lista;
    nova_lista = (lista_duplamente_encadeada*)calloc(1, sizeof(lista_duplamente_encadeada));
    return nova_lista;
}

item_encadeado_simples *criar_item_encadeado_simples() {
    item_encadeado_simples *novo_item;
    novo_item = (item_encadeado_simples*)calloc(1, sizeof(item_encadeado_simples));
    return novo_item;
}

item_duplamente_encadeado *criar_item_duplamente_encadeado() {
    item_duplamente_encadeado *novo_item;
    novo_item = (item_duplamente_encadeado*)calloc(1, sizeof(item_duplamente_encadeado));
    return novo_item;
}

void adicionar_primos_na_lista_encadeada_simples(lista_encadeada_simples lista);
void adicionar_primos_na_lista_duplamente_encadeada(lista_duplamente_encadeada lista);