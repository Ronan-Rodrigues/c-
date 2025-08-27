#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 8

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    // Limpa o tabuleiro
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    // Jogador 2 (pretas) - linhas 0 e 1
    char linhaPretas[] = {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'};
    for (int j = 0; j < TAM; j++) {
        tabuleiro[0][j] = linhaPretas[j]; // linha 8
        tabuleiro[1][j] = 'p';            // linha 7
    }

    // Jogador 1 (brancas) - linhas 6 e 7
    char linhaBrancas[] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'};
    for (int j = 0; j < TAM; j++) {
        tabuleiro[6][j] = 'P';            // linha 2
        tabuleiro[7][j] = linhaBrancas[j]; // linha 1
    }
}

void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n    A   B   C   D   E   F   G   H\n");
    printf("  +---+---+---+---+---+---+---+---+\n");

    for (int i = 0; i < TAM; i++) {
        int linhaXadrez = TAM - i;
        printf("%d |", linhaXadrez);
        for (int j = 0; j < TAM; j++) {
            printf(" %c |", tabuleiro[i][j]);
        }
        printf(" %d\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }

    printf("    A   B   C   D   E   F   G   H\n");
}

void limparTabuleiro(char tabuleiro[TAM][TAM]) {
    inicializarTabuleiro(tabuleiro); // substitui a limpeza por reinicialização
}

void moverCavalo(char tabuleiro[TAM][TAM], int linha, int coluna, char direcao[30], char peca) {
    int novaLinha = linha;
    int novaColuna = coluna;

    printf("\nCavalo vai se mover para %s\n", direcao);

    if (strcmp(direcao, "cima-direita") == 0) {
        novaLinha -= 2;
        novaColuna += 1;
        printf("Cavalo andou 2 casas para cima\n");
        printf("Cavalo andou 1 casa para direita\n");
    } else if (strcmp(direcao, "cima-esquerda") == 0) {
        novaLinha -= 2;
        novaColuna -= 1;
        printf("Cavalo andou 2 casas para cima\n");
        printf("Cavalo andou 1 casa para esquerda\n");
    } else if (strcmp(direcao, "baixo-direita") == 0) {
        novaLinha += 2;
        novaColuna += 1;
        printf("Cavalo andou 2 casas para baixo\n");
        printf("Cavalo andou 1 casa para direita\n");
    } else if (strcmp(direcao, "baixo-esquerda") == 0) {
        novaLinha += 2;
        novaColuna -= 1;
        printf("Cavalo andou 2 casas para baixo\n");
        printf("Cavalo andou 1 casa para esquerda\n");
    } else if (strcmp(direcao, "direita-cima") == 0) {
        novaLinha -= 1;
        novaColuna += 2;
        printf("Cavalo andou 1 casa para cima\n");
        printf("Cavalo andou 2 casas para direita\n");
    } else if (strcmp(direcao, "direita-baixo") == 0) {
        novaLinha += 1;
        novaColuna += 2;
        printf("Cavalo andou 1 casa para baixo\n");
        printf("Cavalo andou 2 casas para direita\n");
    } else if (strcmp(direcao, "esquerda-cima") == 0) {
        novaLinha -= 1;
        novaColuna -= 2;
        printf("Cavalo andou 1 casa para cima\n");
        printf("Cavalo andou 2 casas para esquerda\n");
    } else if (strcmp(direcao, "esquerda-baixo") == 0) {
        novaLinha += 1;
        novaColuna -= 2;
        printf("Cavalo andou 1 casa para baixo\n");
        printf("Cavalo andou 2 casas para esquerda\n");
    } else {
        printf("Direção inválida!\n");
        return;
    }

    if (novaLinha >= 0 && novaLinha < TAM && novaColuna >= 0 && novaColuna < TAM) {
        tabuleiro[linha][coluna] = '.';
        tabuleiro[novaLinha][novaColuna] = peca;
        printf("=======================\n");
        printf("Fim do movimento do Cavalo\n\n");
    } else {
        printf("Movimento inválido! Fora do tabuleiro.\n");
    }
}

void moverPeca(char tabuleiro[TAM][TAM], int linha, int coluna, char direcao[30], int casas, char peca) {
    int novaLinha = linha;
    int novaColuna = coluna;

    char* nomePeca =
        (peca == 'P') ? "Peão" :
        (peca == 'T') ? "Torre" :
        (peca == 'B') ? "Bispo" :
        (peca == 'Q') ? "Rainha" :
        (peca == 'R') ? "Rei" : "Peça";

    printf("\n%s vai se mover %d casa(s) para %s\n", nomePeca, casas, direcao);

    for (int i = 0; i < casas; i++) {
        if (strcmp(direcao, "cima") == 0) novaLinha--;
        else if (strcmp(direcao, "baixo") == 0) novaLinha++;
        else if (strcmp(direcao, "direita") == 0) novaColuna++;
        else if (strcmp(direcao, "esquerda") == 0) novaColuna--;
        else if (strcmp(direcao, "diagonal-cima-direita") == 0) {
            novaLinha--;
            novaColuna++;
        }
        else if (strcmp(direcao, "diagonal-cima-esquerda") == 0) {
            novaLinha--;
            novaColuna--;
        }
        else if (strcmp(direcao, "diagonal-baixo-direita") == 0) {
            novaLinha++;
            novaColuna++;
        }
        else if (strcmp(direcao, "diagonal-baixo-esquerda") == 0) {
            novaLinha++;
            novaColuna--;
        }

        printf("%s andou 1 casa para %s\n", nomePeca, direcao);
    }

    if (novaLinha >= 0 && novaLinha < TAM && novaColuna >= 0 && novaColuna < TAM) {
        tabuleiro[linha][coluna] = '.';
        tabuleiro[novaLinha][novaColuna] = peca;
        printf("=======================\n");
        printf("Fim do movimento da %s\n\n", nomePeca);
    } else {
        printf("Movimento inválido! Fora do tabuleiro.\n");
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    limparTabuleiro(tabuleiro);

    int linha = 4, coluna = 4;
    char peca;
    int casas;
    char direcao[30];
    int opcao;

    do {
        limparTabuleiro(tabuleiro);
        printf("\nEscolha a peça:\n");
        printf("P - Peão\nT - Torre\nB - Bispo\nQ - Rainha\nC - Cavalo\nR - Rei\nEscolha: ");
        scanf(" %c", &peca);
        peca = toupper(peca);
        tabuleiro[linha][coluna] = peca;

        if (peca == 'C') {
            char* direcoesCavalo[] = {
                "cima-direita", "cima-esquerda", "baixo-direita", "baixo-esquerda",
                "direita-cima", "direita-baixo", "esquerda-cima", "esquerda-baixo"
            };
            int escolha;
            printf("\nMovimentos do Cavalo:\n");
            for (int i = 0; i < 8; i++) {
                printf("%d. %s\n", i + 1, direcoesCavalo[i]);
            }
            printf("Escolha a direção: ");
            scanf("%d", &escolha);
            if (escolha >= 1 && escolha <= 8) {
                strcpy(direcao, direcoesCavalo[escolha - 1]);
                moverCavalo(tabuleiro, linha, coluna, direcao, peca);
            } else {
                printf("Direção inválida!\n");
                continue;
            }
        } else {
            int escolha;
            if (peca == 'P') {
                char* direcoesPeao[] = {
                    "baixo", "diagonal-baixo-direita", "diagonal-baixo-esquerda"
                };
                printf("\nMovimentos do Peão:\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s\n", i + 1, direcoesPeao[i]);
                }
                printf("Escolha a direção: ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= 3) {
                    strcpy(direcao, direcoesPeao[escolha - 1]);
                    casas = (escolha == 1) ? 2 : 1;
                } else {
                    printf("Direção inválida!\n");
                    continue;
                }
                        } else if (peca == 'T') {
                char* direcoesTorre[] = {"cima", "baixo", "esquerda", "direita"};
                printf("\nMovimentos da Torre:\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d. %s\n", i + 1, direcoesTorre[i]);
                }
                printf("Escolha a direção: ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= 4) {
                    strcpy(direcao, direcoesTorre[escolha - 1]);
                    printf("Casas (1 a 7): ");
                    scanf("%d", &casas);
                } else {
                    printf("Direção inválida!\n");
                    continue;
                }
            } else if (peca == 'B') {
                char* direcoesBispo[] = {
                    "diagonal-cima-direita", "diagonal-cima-esquerda",
                    "diagonal-baixo-direita", "diagonal-baixo-esquerda"
                };
                printf("\nMovimentos do Bispo:\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d. %s\n", i + 1, direcoesBispo[i]);
                }
                printf("Escolha a direção: ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= 4) {
                    strcpy(direcao, direcoesBispo[escolha - 1]);
                    printf("Casas (1 a 7): ");
                    scanf("%d", &casas);
                } else {
                    printf("Direção inválida!\n");
                    continue;
                }
            } else if (peca == 'Q') {
                char* direcoesRainha[] = {
                    "cima", "baixo", "esquerda", "direita",
                    "diagonal-cima-direita", "diagonal-cima-esquerda",
                    "diagonal-baixo-direita", "diagonal-baixo-esquerda"
                };
                printf("\nMovimentos da Rainha:\n");
                for (int i = 0; i < 8; i++) {
                    printf("%d. %s\n", i + 1, direcoesRainha[i]);
                }
                printf("Escolha a direção: ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= 8) {
                    strcpy(direcao, direcoesRainha[escolha - 1]);
                    printf("Casas (1 a 7): ");
                    scanf("%d", &casas);
                } else {
                    printf("Direção inválida!\n");
                    continue;
                }
            } else if (peca == 'R') {
                char* direcoesRei[] = {
                    "cima", "baixo", "esquerda", "direita",
                    "diagonal-cima-direita", "diagonal-cima-esquerda",
                    "diagonal-baixo-direita", "diagonal-baixo-esquerda"
                };
                printf("\nMovimentos do Rei:\n");
                for (int i = 0; i < 8; i++) {
                    printf("%d. %s\n", i + 1, direcoesRei[i]);
                }
                printf("Escolha a direção: ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= 8) {
                    strcpy(direcao, direcoesRei[escolha - 1]);
                    casas = 1;
                } else {
                    printf("Direção inválida!\n");
                    continue;
                }
            }

            moverPeca(tabuleiro, linha, coluna, direcao, casas, peca);
        }

        imprimirTabuleiro(tabuleiro);

        printf("\nDeseja continuar? (1 - Sim, 0 - Não): ");
        scanf("%d", &opcao);
    } while (opcao != 0);

    return 0;

}