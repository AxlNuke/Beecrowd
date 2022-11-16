#include <stdio.h>
#include <stdlib.h>

int main() {

    double a, a2, x;

    scanf("%lf", &a);

    a2 = a*a;
    x = 3.14159 * a2;

    printf("A=%.4lf\n", x);

    return 0;
}