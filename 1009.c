#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char nome[64];
    double salario, vendas, total;

    scanf("%s", nome);
    scanf("%lf", &salario);
    scanf("%lf", &vendas);

    total = salario + (vendas * 0.15);

    printf("TOTAL = R$ %.2f\n", total);

    return 0;
}