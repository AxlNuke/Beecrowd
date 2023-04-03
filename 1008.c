#include <stdio.h>
#include <stdlib.h>

int main() {

    int num, horas;
    float valor, sal;

    scanf("%d", &num);
    scanf("%d", &horas);
    scanf("%f", &valor);

    sal = valor * horas;

    printf("NUMBER = %d\nSALARY = U$ %.2f\n", num, sal);

    return 0;
}