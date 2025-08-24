#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h> 

int main() {
    system("chcp 65001"); // Corrige as acentuações

    int opcao, numeroComputador, chute, jogarNovamente;
    char escolhaJogador;

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
            numeroComputador = rand() % 100 + 1; // Gera um número secreto entre 1 e 10
     
            printf("Iniciando o jogo...\n");
            printf("Bem-vindo ao jogo! Tente adivinhar se o número secreto é maior, menor ou igual.\n");
            printf("Escolha uma opção:\n");
            printf("M. Maior\n");
            printf("N. Menor\n");
            printf("I. Igual\n");
            printf("Escolha uma opção: ");
            scanf(" %c", &escolhaJogador);

            escolhaJogador = toupper(escolhaJogador); // Converte para maiúsculo
            printf("Você escolheu: %c\n", escolhaJogador);

            if (escolhaJogador != 'M' && escolhaJogador != 'N' && escolhaJogador != 'I') {
                printf("Opção inválida. Tente novamente.\n");
                return 1; // Encerra o programa
            }
            printf("Escolha um numero de 1 a 100: ");
            scanf("%d", &chute);

            if (chute < 1 || chute > 100) {
                printf("Número inválido. Tente novamente.\n");
                return 1; // Encerra o programa
            }
            if ((escolhaJogador == 'M' && chute > numeroComputador) || (escolhaJogador == 'N' && chute < numeroComputador) ||
                (escolhaJogador == 'I' && chute == numeroComputador)) {
                printf("Parabéns! Você acertou o número secreto: %d\n", numeroComputador);
            } else {
                printf("Você errou! O número secreto era: %d\n", numeroComputador);
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
            printf("1. Você deve tentar adivinhar se o número escolhido pelo computador é maior, menor ou igual ao seu entre 1 e 100.\n");
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