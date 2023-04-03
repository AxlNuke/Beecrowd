#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, x = 0;

    scanf("%d", &x);

    while (x > 0) {
        printf("1");
        for (i = 2; i <= x; i++) {
            printf(" %d", i);
        }
        printf("\n");
        scanf("%d", &x);
    }

    return 0;
}