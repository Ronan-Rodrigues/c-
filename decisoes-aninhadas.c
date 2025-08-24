#include <stdio.h>
#include <stdlib.h>

int main() {

  system("chcp 65001"); // Corrige as acentuações  
  int idade;
  float renda;

  /*
  printf("Digite a sua idade: ");
  scanf("%d", &idade);
  printf("Digite a sua renda mensal: \n");
  scanf("%f", &renda);

  if (idade < 18 || idade > 60) {
    if (renda < 2000.0) {
      printf("Você está qualificado para o desconto especial\n");
    } else {
      printf("Você não está qualificado para o desconto devido à renda\n");
    }
  } else {
    printf("Você não está qualificado para o desconto devido à idade\n");
  }


  int idade, dependentes;
  float renda;

  printf("Digite a sua idade: \n");
  scanf("%d", &idade);
  printf("Digite a sua renda mensal: \n");
  scanf("%f", &renda);
  printf("Digite o número de dependentes: \n");
  scanf("%d", &dependentes);

  if (idade >= 18 && idade <= 65) {
    if (renda < 3000.0) {
      if (dependentes > 2) {
        printf("Você está qualificado para os benefícios sociais\n");
      } else {
        printf("Você não está qualificado para os benefícios devido ao número de dependentes\n");
      }
    } else {
      printf("Você não está qualificado para os benefícios devido à renda\n");
    }
  } else {
    printf("Você não está qualificado para os benefícios devido à idade\n");
  }
*/
  
  int numero = 0;
  printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero > 0) {
        if (numero % 2 == 0) {
            printf("O número é positivo e par.\n");
        } else {
            printf("O número é positivo e ímpar.\n");
        }
    } else if (numero < 0) {
        printf("O número é negativo.\n");
    } else {
        printf("O número é zero.\n");
    }



  return 0;
}


