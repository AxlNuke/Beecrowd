#include <stdio.h>
#include <stdlib.h>

int main() {

    double a, b, m, media;

    scanf("%lf", &a);
    scanf("%lf", &b);

    m = (a * 3.5) + (b * 7.5);
    media = m / 11;

    printf("MEDIA = %.5lf\n", media);

    return 0;
}