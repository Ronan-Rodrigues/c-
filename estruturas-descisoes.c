#include <stdio.h>
#include <stdlib.h>

int main() {
    // Estruturas de decisão em C
    system("chcp 65001");
    int numero = 16;

    printf("******************************************\n");
    // Verifica se o número é maior, menor ou igual a 15
    if (numero > 15) {
        printf("O número é maior que 15.\n");
    } else if (numero < 15) {
        printf("O número é menor que 15.\n");
    } else {
        printf("O número é igual a 15.\n");
    }
    printf("******************************************\n");
    // Verifica se o número é par ou ímpar
    if(numero % 2 == 0) {
        printf("O número %d é par.\n", numero);
    } else {
        printf("O número %d é ímpar.\n", numero);
    }
     printf("******************************************\n");

    return 0;
}