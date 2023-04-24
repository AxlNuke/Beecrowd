#include <stdio.h>
#include <stdlib.h>

int eh_primo(int numero_a_ser_verificado) {
    int eh_primo = 1, nao_eh_primo = 0;
    int metade_do_numero_a_ser_verificado = numero_a_ser_verificado / 2;

    for (int i = 2; i <= metade_do_numero_a_ser_verificado; i++) {
        if (numero_a_ser_verificado % i == 0) {
            return nao_eh_primo;
        }
    }
    return eh_primo;
}