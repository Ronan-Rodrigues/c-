#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    system("chcp 65001");// Corrige as acentuações

    int escolhajogador, escolhaComputador, jogarNovamente;

    printf("*** Jogo Jokempo ***\n");
    printf("***********************\n");    
    printf("*** Menu principal ***:\n");
    printf("***********************\n");
    printf("Escolha uma opção:\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("4. Regras do jogo\n");
    printf("3. Sair\n");
    printf("***********************\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolhajogador);

    switch (escolhajogador) {
        case 1:
            printf("Você escolheu Pedra\n");
            break;
        case 2:
            printf("Você escolheu Papel\n");
            break;
        case 3:
            printf("Você escolheu Tesoura\n");
            break;
        case 4:
            printf("Regras do jogo:\n");
            printf("1. Pedra vence Tesoura\n");
            printf("2. Tesoura vence Papel\n");
            printf("3. Papel vence Pedra\n");
            printf("Boa sorte!\n");
            break;
        case 5:
            printf("Saindo do jogo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
    if (escolhajogador >= 1 && escolhajogador <= 3) {
        srand(time(0)); // Inicializa o gerador de números aleatórios
        escolhaComputador = rand() % 3 + 1; // Gera um número entre 1 e 3

        printf("Computador escolheu: ");
        switch (escolhaComputador) {
            case 1:
                printf("Pedra\n");
                break;
            case 2:
                printf("Papel\n");
                break;
            case 3:
                printf("Tesoura\n");
                break;
        }

        if (escolhajogador == escolhaComputador) {
            printf("Empate!\n");
        } else if ((escolhajogador == 1 && escolhaComputador == 3) ||
                   (escolhajogador == 2 && escolhaComputador == 1) ||
                   (escolhajogador == 3 && escolhaComputador == 2)) {
            printf("Você venceu!\n");
        } else {
            printf("Computador venceu!\n");
        }

        printf("Deseja jogar novamente? (1 - Sim, 0 - Não): ");
        scanf("%d", &jogarNovamente);
        if (jogarNovamente) {
            main(); // Reinicia o jogo
        } else {
            printf("Obrigado por jogar!\n");
            return 0; // Encerra o programa
        }
    }

}