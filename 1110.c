#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int valor;
    struct item* proximo;
} Item;

int novo_item_no_final(Item* anterior){   
}

int main() {

    Item* primeiro = NULL;

    primeiro = (Item*)malloc(sizeof(Item));

    scanf("%d", &primeiro->valor;);
    primeiro->proximo = NULL; 

    printf("%d, %d\n", primeiro->valor, primeiro->proximo);
    return 0;
}