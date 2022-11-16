#include <stdio.h>
#include <stdlib.h>

int leitura(int m, int n);
void troca(int *x, int *y);

int main() {

    int m=1, n=1, sum=0;

    while  (leitura(m, n)) {

        sum = 0;
        scanf("%d %d", &m, &n);

        if (leitura(m, n)) {
            if (m > n) troca(&m, &n);

            for (int i = m; i <= n; i++) {
                printf("%d ", i);
                sum = sum + i;
            }
            printf("Sum=%d\n", sum);
        }
    }    

    return 0;
}

int leitura(int m, int n) {

    if (m <= 0 || n <= 0) return 0;
    
    return 1;
}

void troca(int *x, int *y) {
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}