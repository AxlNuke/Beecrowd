#include <stdio.h>
#include <stdlib.h>

int triangulo(int a, int b, int c);

int main() {
    int a, b, c, d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (triangulo(a, b, c) || triangulo(b, c, d) || triangulo(a, c, d) || triangulo(a, b, d)) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    return 0;
}

int triangulo(int a, int b, int c) {
    if (a+b>c && a+c>b && b+c>a) {
        return 1;
    } else {
        return 0;
    }
}