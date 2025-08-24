#include <stdio.h>
#include <stdlib.h>

int main() {
    // Configuração do console para UTF-8
    system("chcp 65001");
    // Exemplo de operadores relacionais
    // Operadores relacionais em C são usados para comparar valores
    // e retornam um valor booleano (1 para verdadeiro, 0 para falso)
    int a = 10;
    int b = 20;

    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);

    printf("***************************************\n");
    // Comparação entre diferentes tipos de dados
    int x = 5;
    float y = 5.0;
    char c = 'a';

    printf("x >= y: %d\n", x >= y);
    printf("x == y: %d\n", x == y);
    printf("x != y: %d\n", x != y);
    
    // Comparação de um inteiro com um caractere
    printf("x >= c: %d\n", x >= c);
    printf("O valor ASCCI de %c é: %d\n", c, c);


    return 0;
}