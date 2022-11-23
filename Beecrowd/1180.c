#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, menor, pos;
    scanf("%d", &n);
    int vetor[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    menor = vetor[0];
    pos = 0;

    for (i = 1; i < n; i++) {
        if (menor > vetor[i]) {
            menor = vetor[i];
            pos = i;
        }
    }

    printf("Menor valor: %d\nPosicao: %d\n", menor, pos);

    return 0;
}