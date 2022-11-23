#include <stdio.h>
#include <stdlib.h>

int eh_primo(int x);

int main(){
    int i, n, x;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (eh_primo(x) == 1) {
            printf("%d eh primo\n", x);
        } else {
            printf("%d nao eh primo\n", x);
        }
    }

    return 0;
}

int eh_primo(int x) {
    int i;
    if (x <= 1) {
        return 0;
    } else {
        for (i = 2; i <= x/2; i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }    
}