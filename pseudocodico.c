#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");

    printf("Digite um número: ");
    int numero,resultado;

    scanf("%d", &numero);
    
    resultado = numero/2;

    printf("O resultado da divisão por 2 é: %d\n", resultado);

    if (numero % 2 == 0) {
        printf("O número %d é par.\n", numero);
    } else {
        printf("O número %d é ímpar.\n", numero);
    }
    return 0;

}
