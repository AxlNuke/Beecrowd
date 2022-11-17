#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, x, conta = 0;

    scanf("%d", &x);

    for(i = 1; i <= x; i++) {
        printf("%d %d %d PUM\n", conta+1, conta+2, conta+3);
        conta = conta + 4;
    }

    return 0;
}