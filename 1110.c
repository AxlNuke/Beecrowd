#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int valor;
    struct item* proximo;
} Item;

int main() {

    Item* primeiro = NULL;
    Item* segundo = NULL;

    primeiro = (Item*)malloc(sizeof(Item));
    segundo = (Item*)malloc(sizeof(Item));

    primeiro->valor = 1;
    primeiro->proximo = segundo;

    segundo->valor = 22;
    segundo->proximo = NULL;    


    printf("%d, %d\n", primeiro->valor, primeiro->proximo);
    printf("%d, %d\n", segundo->valor, segundo->proximo);
    return 0;
}