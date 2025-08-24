#include <stdio.h>
#include <stdlib.h>

// Logica do jogo de xadrez
// Torre anda 5 casas para a direita
// Bispo anda 5 casas na diagonal para a direita para cima
// Rainha anda 8 casas para a esquerda
// Cavalo anda 3 casas em L para cima 2 casas para direita uma casa

int main(){
    int torre = 0;
    int bispo = 1; 
    int rainha = 1;
    int cavalo = 1;
    int movimento = 1;

    printf("Iniciando o jogo de xadrez \n");
    printf("================================\n");
   
    for(torre = 1; torre < 6; torre++){
        printf("Torre andou para a direita \n", torre);
      
    }
    printf("================================\n");
    printf("Fim do movimento da torre \n");
    printf("Torre andou para direita %d casas \n", torre - 1);
    printf("================================\n");

    while (bispo < 6){
        bispo ++;
        printf("Bispo andou para direita \n", bispo);
        printf("Bispo andou para cima \n", bispo);
    }
  
    printf("================================\n");
    printf("Fim do movimento do bispo \n");
    printf("Bispo andou na diagonal direita e para cima %d casas \n", bispo - 1);
    printf("================================\n");
    

    do
    {
        printf("Rainha andou para esquerda \n");
        rainha ++;
    } while (rainha < 9);
    printf("================================\n");
    printf("Fim do movimento da rainha \n");
    printf("Rainha andou para esquerda %d casas \n", rainha - 1);
    printf("================================\n");

    while (movimento --){
        for(cavalo = 1; cavalo < 3; cavalo++){
            printf("Cavalo andou para cima \n", cavalo);
        } 
            printf("Cavalo andou para direita \n", cavalo);
            printf("================================\n");
            printf("final do movimento do cavalo \n");
            printf("Cavalo andou para cima 2 casas e para direita 1 casa \n");
        }

    printf("================================\n");
    printf("Fim do jogo de xadrez \n");




    return 0;



}