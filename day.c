#include <stdio.h>

int main() {
    int total_dias, anos, meses, dias;
    scanf("%d", &total_dias);
    anos = total_dias / 365;
    total_dias -= anos * 365;
    meses = total_dias / 30;
    total_dias -= meses * 30;
    dias = total_dias;
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
    return 0;
}