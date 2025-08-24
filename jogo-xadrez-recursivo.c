#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Necessário para toupper
#include <time.h> // Necessário para funções de tempo
#include <string.h> // Necessário para manipulação de strings

// Logica do jogo de xadrez

// Torre anda 5 casas para a direita
// Bispo anda 5 casas na diagonal para a direita para cima
// Rainha anda 8 casas para a esquerda
// Cavalo anda 3 casas em L para cima 2 casas para direita uma casa

// Definição de procedimentos
//Movimenta torre
void moveTorre(int movimentoT){
    if(movimentoT > 0){
        printf("Torre 1 movimento para direita! \n");
        moveTorre(movimentoT - 1);
    }else{
        printf("=====================================\n");
        printf("Fim do movimento da torre!\n\n");
    }
}
//Movimenta bispo
void moveBispo(int movimentoB, int lado){
    if(movimentoB != 0){
//        printf("%d," "%d \n", movimentoB, lado);
        printf("Bispo 1 movimento para cima! \n");
        moveBispo(movimentoB - 1, lado);

    } else if(movimentoB == 0 && lado != 0) {

        printf("Bispo 1 movimento para direita! \n");
        moveBispo(movimentoB, lado -1);
    } else {
        printf("=====================================\n");
        printf("Fim do movimento do Bispo!\n\n");            
        printf("=====================================\n");
        
    }
}


//Movimenta rainha
void moveRainha(int movimentoR){
    if(movimentoR > 0){
        printf("Rainha 1 movimento para esquerda! \n");
        moveRainha(movimentoR -1);
    } else {
        printf("=====================================\n");
        printf("Fim do movimento da Rainha! \n\n");
    }
}
//Movimenta cavalo
void moveCavalo(int movimentoC, int lado){
 if(movimentoC != 0){
//        printf("%d," "%d \n", movimentoB, lado);
        printf("Cavalo 1 movimento para cima! \n");
        moveCavalo(movimentoC - 1, lado);

    } else if(movimentoC == 0 && lado != 0) {

        printf("Cavalo 1 movimento para direita! \n");
        moveCavalo(movimentoC, lado -1);
    } else {
        printf("=====================================\n");
        printf("Fim do movimento do Cavalo!\n");            
        printf("=====================================\n\n");
        
    }
}



int main() {
system("chcp 65001 > null"); // Define UTF-8 no terminal do Windows
    
    //Declaração de variaveis 
    int opcoe;


    //iniciando o jogo de xadrez...
    printf("=====================================\n");
    printf("iniciando o jogo de xadrez...\n");
    printf("=====================================\n");
    printf("Escolha qual peça deseja movimentar:\n");
    printf("=====================================\n");
    printf("1. Torre \n");
    printf("2. Bispo \n");
    printf("3. Rainha \n");
    printf("4. Cavalo \n");
    printf("=====================================\n");
    scanf("%d", &opcoe); // Entrada do usuario para escolha da peça

    if (opcoe > 0 && opcoe < 5){
        
    switch (opcoe)
    {
    case 1:
        printf("=====================================\n");
        printf("A Opção escolhida foi Torre \n"); 
        printf("=====================================\n");
        moveTorre(5);

        break;
    case 2:
        printf("=====================================\n");
        printf("A Opção escolhida foi Bispo \n"); 
        printf("=====================================\n");
        moveBispo(5,5);
        break;
    case 3:
        printf("=====================================\n");
        printf("A Opção escolhida foi Rainha \n");
        printf("=====================================\n");
        moveRainha(8);
        
        break;
    case 4:
        printf("=====================================\n");
        printf("A Opção escolhida foi Cavalo \n"); 
        printf("=====================================\n");   
        moveCavalo(3,2);     
        break;

    default:
        printf("=====================================\n");
        printf("Opção Inválida! Escolha de 1 a 4");
        printf("=====================================\n");
        break;
    }

    

    return 0;
    }
}