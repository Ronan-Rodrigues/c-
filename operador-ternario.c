#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001"); // Corrige as acentuações

    int idade;
    printf("Digite a sua idade: \n");
    scanf("%d", &idade);

    idade >= 18 ?
        (idade <= 60 ? printf("Você é um adulto!\n") : printf("Você é um idoso!\n")) :
        (idade >= 12 ? printf("Você é um adolescente!\n") : printf("Você é uma criança!\n"));
}