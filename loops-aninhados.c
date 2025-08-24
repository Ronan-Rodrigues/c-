#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Necessário para toupper
#include <time.h> // Necessário para funções de tempo
#include <string.h> // Necessário para manipulação de strings

int main() {
    // Declaração de variáveis
    int i, j;
    char letra;

        for(i = 1; i <= 5; i++) {

            letra = 'A';

            for(j = 1; j <= i; j++) {
               
                printf("%c ", letra);
                letra++; // Incrementa para a próxima letra
            }
            printf("\n"); // Nova linha após cada linha da pirâmide
            
        }
/*
    // Loop aninhado para imprimir a tabuada de 1 a 10
    for (i = 1; i <= 10; i++) {
        printf("taboada do %d \n", i);
        for (j = 0; j <= 10; j++) {
            
            printf("%d ", i * j); // Imprime o produto de i e j
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }

*/


    return 0;
}