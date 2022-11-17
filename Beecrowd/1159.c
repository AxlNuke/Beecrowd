#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, x, soma, soma2;

    scanf("%d", &x);

    while (x > 0) {
        if (x%2 == 0) {
            soma = x*5 + 20;
            printf("%d\n", soma);
        } else {
            soma2 = x+1;
            soma = soma2*5 + 20;
            printf("%d\n", soma);
        }
        scanf("%d", &x);        
    }

    return 0;
}