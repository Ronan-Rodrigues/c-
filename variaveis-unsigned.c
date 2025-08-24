#include <stdio.h>
#include <stdlib.h>
 
int main() {
    // Configuração do console para UTF-8
    system("chcp 65001");

    int signedNumber = 3000000000; // Este valor excede o limite de um int normal
    unsigned int unsignedNumber = 3000000000;
 
    printf("Número com sinal: %d\n", signedNumber);
    printf("Número sem sinal: %u\n", unsignedNumber);
 
    return 0;
}