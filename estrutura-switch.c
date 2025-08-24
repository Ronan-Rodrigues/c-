#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001"); // Corrige as acentuações

    printf("Bem-vindo ao sistema bancário!\n");
    printf("================================\n");

    // Exemplo de uso de operadores lógicos
  int opcao;

  printf("Escolha uma opção:\n");
  printf("1. Verificar saldo\n");
  printf("2. Fazer depósito\n");
  printf("3. Fazer saque\n");
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      printf("Saldo atual: R$ 1.000,00\n");
      break;
    case 2:
      printf("Depósito realizado com sucesso\n");
      break;
    case 3:
      printf("Saque realizado com sucesso\n");
      break;
    default:
      printf("Opção inválida\n");
  }

  // Exemplo de uso de switch-case
  printf("Escolha um dia da semana (1-7):\n");
    printf("1. Domingo\n");
    printf("2. Segunda-feira\n");
    printf("3. Terça-feira\n");
    printf("4. Quarta-feira\n");
    printf("5. Quinta-feira\n");
    printf("6. Sexta-feira\n");
    printf("7. Sábado\n");
    scanf("%d", &opcao);
    printf("Você escolheu a opção: %d\n", opcao);
    printf("================================\n");
    
  int dia = 3;

  switch (dia) {
    case 1:
      printf("Domingo\n");
      break;
    case 2:
      printf("Segunda-feira\n");
      break;
    case 3:
      printf("Terça-feira\n");
      break;
    case 4:
      printf("Quarta-feira\n");
      break;
    case 5:
      printf("Quinta-feira\n");
      break;
    case 6:
      printf("Sexta-feira\n");
      break;
    case 7:
      printf("Sábado\n");
      break;
    default:
      printf("Dia inválido\n");
  }

    printf("================================\n");

    return 0;

  return 0;
}