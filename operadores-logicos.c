#include <stdio.h>
#include <stdlib.h>


int main() {
    system("chcp 65001"); // Corrige as acentuações

  // Exemplo de uso de operadores lógicos
    printf("Operadores Lógicos em C\n");
    printf("================================\n");
    int a = 1, b = 20;

    if (a > 2 && b < 15) {
        printf("A é maior que 5 e B é menor que 15\n");
    } else if (a < 5 || b > 15) {
        printf("A é menor que 5 ou B é maior que 15\n");
    } else {
        printf("Nenhuma das condições foi atendida\n");
    }

    if (!(a == 3)) {
        printf("A não é igual a 3\n");
    } else {
        printf("A é igual a 3\n");
    }

    printf("================================\n");

    if (!a) {
        printf("A é zero\n");
    } else {
        printf("A não é zero\n");
    }





  int x = 5;
  int y = 10;
  int z = 1;

  if (x > 0 && y < 0 || z == 0) {
    printf("A condição é verdadeira\n");
  } else {
    printf("A condição é falsa\n");
  }




  int idade = 20;
  float altura = 1.65;

  if (idade >= 18 && idade <= 30 && altura >= 1.70) {
      printf("Você pode entrar no parque de diversões.\n");
  } else {
      printf("Você não atende aos requisitos para entrar no parque de diversões.\n");
  }


  return 0;
}


/*Operadores	Associatividade
() []	            esquerda para a direita
! - ++ --	        direita para a esquerda
* / %	            esquerda para a direita
+ -	                esquerda para a direita
< <= > >=	        esquerda para a direita
== !=	            esquerda para a direita
&&	                esquerda para a direita
||	                esquerda para a direita
= += -= *= /= %=	direita para a esquerda
,	                esquerda para a direita*/
