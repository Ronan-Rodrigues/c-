#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    system("chcp 65001"); // Corrige as acentuações

    int opcao,numerosecreto, chute, jogarNovamente;;

    printf("*** Menu principal ***:\n");
    printf("***********************\n");
    printf("1. Inicia o jogo\n");
    printf("2. Regras do jogo\n");
    printf("3. Sair\n");
   printf("***********************\n");
 
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            srand(time(0)); // Inicializa o gerador de números aleatórios
            numerosecreto = rand() % 10 + 1; // Gera um número secreto entre 1 e 10
     
            printf("Iniciando o jogo...\n");
            printf("Bem-vindo ao jogo! Tente adivinhar o número secreto entre 1 e 10.\n");
            printf("Escolha um numero de 1 a 10: ");
            scanf("%d", &chute);
            if (chute == numerosecreto) {
                printf("Parabéns! Você acertou o número secreto: %d\n", numerosecreto);
            } else {
                printf("Você errou! O número secreto era: %d\n", numerosecreto);
            }
            printf("Fim do jogo!\n");
            printf("Deseja jogar novamente? (1 - Sim, 0 - Não): ");
           
            scanf("%d", &jogarNovamente);
            if (jogarNovamente) {
                main(); // Reinicia o jogo
            } else {
                printf("Obrigado por jogar!\n");
                return 0; // Encerra o programa
            }   
            break;
        case 2:
            printf("Regras do jogo:\n");
            printf("1. Você deve adivinhar um número secreto entre 1 e 10.\n");
            printf("2. Se você acertar, ganha o jogo.\n");
            printf("3. Se errar, o jogo termina e você descobre o número secreto.\n");
            printf("Boa sorte!\n");
            break;
        case 3:
            printf("Saindo do jogo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
}