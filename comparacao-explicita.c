#include <stdio.h>
#include <stdlib.h>

int main() {
    // Configuração do console para UTF-8
    system("chcp 65001");
    // Comparação explícita entre diferentes tipos de dados

    int num1 = 10;
    float num2 = 10.3;

    int comparison;

    // comparison = num1 == num2; // Comparação implicita sem conversão
    printf("num1 == num2: %d\n", num1 == num2);
    printf("num1 >= num2: %d\n", num1 >= num2);
   
   
    int comparison1;

    //int comparison1 = num1 == (int)num2; // Comparação com conversão explícita
    printf("num1 == num2: %d\n", num1 == (int)num2);
    printf("num1 >= num2: %d\n", num1 >= (int)num2);


    return 0;
}