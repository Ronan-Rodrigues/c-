#include <stdio.h>
#include <stdlib.h>
 
int main() {
    // Configuração do console para UTF-8
    system("chcp 65001");
    // Exemplo de variáveis com tipos diferentes
    int regularNumber = 2147483647; // Valor máximo de int
    long int bigNumber = 2147483647;
    long long int bigbigNumber = 2147483647;
 
    printf("Número regular (int): %d\n", regularNumber);
    printf("Número grande (long int): %ld\n", bigNumber);
 
    bigNumber = 2147483648; // Valor maior que o máximo de int
    printf("Número grande atualizado (long int): %ld\n", bigNumber);

    bigbigNumber = 2147483648; // Valor maior que o máximo de int
    printf("Número grande atualizado (long long int): %lld\n", 
bigbigNumber);


    return 0;
}