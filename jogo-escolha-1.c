#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // Necessário para toupper
#include <string.h>

int main() {
    system("chcp 65001"); // corrige as acentuações

    int numeroJogador, numeroComputador, resultado;
    char tipoComparacao;

    resultado = 0; // Inicializa o resultado como 0

    printf("*** Jogo de Adivinhação ***\n");
    printf("Escolha uma opção:\n"); 
    printf("M. Maior\n");
    printf("N. Menor\n");
    printf("I. Igual\n");
    printf("Escolha uma opção: (ex: I para Igual.) ");
    scanf(" %c", &tipoComparacao);
   tipoComparacao = toupper(tipoComparacao); // Converte para maiúsculo
    if (tipoComparacao != 'M' && tipoComparacao != 'N' && tipoComparacao != 'I') {
        printf("Opção inválida. Tente novamente.\n");
        return 1; // Encerra o programa
    }
    printf("Digite um número entre 1 e 100: ");
    scanf("%d", &numeroJogador);
    if (numeroJogador < 1 || numeroJogador > 100) {
        printf("Número inválido. Tente novamente.\n");
        return 1; // Encerra o programa
    }
    srand(time(0)); // Inicializa o gerador de números aleatórios
    numeroComputador = rand() % 100 + 1; // Gera um número entre 1 e 100
    printf("Número secreto gerado pelo computador: %d\n", numeroComputador);
   // printf("Você escolheu: %c\n", tipoComparacao);

   
    
    switch (tipoComparacao) {
    case 'M':
    case 'm':
        resultado = (numeroJogador > numeroComputador) ? 1 : -1; // Jogador venceu se o número for maior
        printf("Você escolheu Maior.\n");
     //   printf("Resultado: %s\n", (resultado == 1) ? "Você venceu!" : "Você perdeu.");
        break;
    {
    case 'N':
    case 'n':
        resultado = (numeroJogador < numeroComputador) ? 1 : -1; // Jogador venceu se o número for menor
        printf("Você escolheu Menor.\n");
     //   printf("Resultado: %s\n", (resultado == 1) ? "Você venceu!" : "Você perdeu.");
        break;
    case 'I':
    case 'i':
        resultado = (numeroJogador == numeroComputador) ? 1 : -1; // Jogador venceu se o número for igual
        printf("Você escolheu Igual.\n");
      //  printf("Resultado: %s\n", (resultado == 1) ? "Você venceu!" : "Você perdeu.");
        break;
    
    default:
        printf("Opção inválida. Tente novamente.\n");
        return 1; // Encerra o programa
        break;
    }
       
}
 printf("Resultado: %s\n", (resultado == 1) ? "Você venceu!" : "Você perdeu.");
 
}