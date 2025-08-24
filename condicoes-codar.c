#include <stdio.h>
#include <stdlib.h>

int main() {
    // Estruturas de decisão em C
    system("chcp 65001");

    // Variaveis
    float temperatura, umidade;
    unsigned int estoque, estoqueminimo;
    estoqueminimo = 500; // Estoque mínimo

    // Entrada de dados
    printf("Digite a temperatura atual (em °C): \n");
    scanf("%f", &temperatura);
    printf("Digite a umidade atual (em %%): \n");
    scanf("%f", &umidade);
    printf("Digite a quantidade em estoque: \n");
    scanf("%u", &estoque);

 /*   if (temperatura > 30.0 && umidade < 30.0) {
        printf("Alerta: Condições de calor extremo e baixa umidade!\n");
    } else if (temperatura < 0.0) {
        printf("Alerta: Condições de congelamento!\n");
    } else {
        printf("Condições normais.\n");
    }
*/
    if (temperatura > 30.0) {
        printf("Alerta: Temperatura está alta!\n");
    } else {
        printf("Temperatura está dentro dos parâmetros.\n");
    }

    if (umidade > 50 ){
        printf("Alerta: Umidade está alta!\n");
    } else {
        printf("Umidade está dentro dos parâmetros.\n");
    }


    if (estoque < estoqueminimo) {
        printf("Alerta: Estoque baixo! Reabastecimento necessário.\n");
    } else if (estoque == estoqueminimo) {
        printf("Atenção: Estoque no nível mínimo.\n");
    } else {
        printf("Estoque está dentro dos parâmetros.\n");
    }
/*

    if (estoque < estoqueminimo) {
        printf("Alerta: Estoque baixo! Reabastecimento necessário.\n");
    } else {
        printf("Estoque está dentro dos parâmetros.\n");
    }
*/
    return 0;    
}