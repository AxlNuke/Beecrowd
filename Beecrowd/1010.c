#include <stdio.h>
#include <stdlib.h>

int main() {

    int c1, n1, c2, n2;
    float v1, v2, r1, r2;

    scanf("%d %d %f", &c1, &n1, &v1);
    scanf("%d %d %f", &c2, &n2, &v2);

    r1 = n1 * v1;
    r2 = n2 * v2;

    printf("VALOR A PAGAR: R$ %.2f\n", r1 + r2);    

    return 0;
}