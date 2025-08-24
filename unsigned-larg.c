#include <stdio.h>
#include <stdlib.h>
 
int main() {
    // Configuração do console para UTF-8
    system("chcp 65001");
    // Exemplo de variáveis com tipos diferentes
    unsigned long int largePositiveNumber = 4000000000;
    unsigned int PositiveNumber = 4000000000;
    long int largeNumber = 4000000000;
    int Number = 4000000000;

    printf("Número positivo grande: %lu\n", largePositiveNumber);//4000000000
    printf("Número positivo: %u\n",  PositiveNumber);//4000000000
    printf("Número grande: %ld\n", largeNumber);//4000000000
    printf("Número: %d\n", Number);//-294967296
 
    return 0;
}