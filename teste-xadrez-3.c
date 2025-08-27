#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 8

// Inicializa o tabuleiro com peças padrão
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    char linhaPretas[] = {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'};
    char linhaBrancas[] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'};

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = ' ';

    for (int j = 0; j < TAM; j++) {
        tabuleiro[0][j] = linhaPretas[j];
        tabuleiro[1][j] = 'p';
        tabuleiro[6][j] = 'P';
        tabuleiro[7][j] = linhaBrancas[j];
    }
}

// Imprime o tabuleiro com coordenadas
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n    A   B   C   D   E   F   G   H\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < TAM; i++) {
        int linhaXadrez = TAM - i;
        printf("%d |", linhaXadrez);
        for (int j = 0; j < TAM; j++)
            printf(" %c |", tabuleiro[i][j]);
        printf(" %d\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    A   B   C   D   E   F   G   H\n");
}

// Converte coordenadas
int coordCol(char letra) { return toupper(letra) - 'A'; }
int coordLin(char numero) { return TAM - (numero - '0'); }
int dentroDoTabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM;
}

// Verifica se a casa está ocupada por aliado
int casaOcupadaPorAliado(char tabuleiro[TAM][TAM], int linha, int coluna) {
    return isupper(tabuleiro[linha][coluna]);
}

// Lista movimentos válidos da peça
void listarMovimentosValidos(char tabuleiro[TAM][TAM], char peca, int linha, int coluna) {
    printf("\nMovimentos válidos para %c em %c%d:\n", peca, 'A' + coluna, TAM - linha);
    int i, j;

    switch (peca) {
        case 'P':
            if (dentroDoTabuleiro(linha - 1, coluna) && tabuleiro[linha - 1][coluna] == ' ')
                printf("- %c%d\n", 'A' + coluna, TAM - (linha - 1));
            if (linha == 6 && tabuleiro[linha - 1][coluna] == ' ' && tabuleiro[linha - 2][coluna] == ' ')
                printf("- %c%d\n", 'A' + coluna, TAM - (linha - 2));
            if (dentroDoTabuleiro(linha - 1, coluna + 1) && !casaOcupadaPorAliado(tabuleiro, linha - 1, coluna + 1))
                printf("- %c%d\n", 'A' + (coluna + 1), TAM - (linha - 1));
            if (dentroDoTabuleiro(linha - 1, coluna - 1) && !casaOcupadaPorAliado(tabuleiro, linha - 1, coluna - 1))
                printf("- %c%d\n", 'A' + (coluna - 1), TAM - (linha - 1));
            break;

        case 'T':
            for (i = linha - 1; i >= 0 && tabuleiro[i][coluna] == ' '; i--)
                printf("- %c%d\n", 'A' + coluna, TAM - i);
            for (i = linha + 1; i < TAM && tabuleiro[i][coluna] == ' '; i++)
                printf("- %c%d\n", 'A' + coluna, TAM - i);
            for (j = coluna - 1; j >= 0 && tabuleiro[linha][j] == ' '; j--)
                printf("- %c%d\n", 'A' + j, TAM - linha);
            for (j = coluna + 1; j < TAM && tabuleiro[linha][j] == ' '; j++)
                printf("- %c%d\n", 'A' + j, TAM - linha);
            break;

        case 'B':
            for (i = 1; dentroDoTabuleiro(linha - i, coluna + i) && tabuleiro[linha - i][coluna + i] == ' '; i++)
                printf("- %c%d\n", 'A' + (coluna + i), TAM - (linha - i));
            for (i = 1; dentroDoTabuleiro(linha - i, coluna - i) && tabuleiro[linha - i][coluna - i] == ' '; i++)
                printf("- %c%d\n", 'A' + (coluna - i), TAM - (linha - i));
            for (i = 1; dentroDoTabuleiro(linha + i, coluna + i) && tabuleiro[linha + i][coluna + i] == ' '; i++)
                printf("- %c%d\n", 'A' + (coluna + i), TAM - (linha + i));
            for (i = 1; dentroDoTabuleiro(linha + i, coluna - i) && tabuleiro[linha + i][coluna - i] == ' '; i++)
                printf("- %c%d\n", 'A' + (coluna - i), TAM - (linha + i));
            break;

        case 'D':
            listarMovimentosValidos(tabuleiro, 'T', linha, coluna);
            listarMovimentosValidos(tabuleiro, 'B', linha, coluna);
            break;

        case 'R':
            for (i = -1; i <= 1; i++) {
                for (j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    int nl = linha + i;
                    int nc = coluna + j;
                    if (dentroDoTabuleiro(nl, nc) && !casaOcupadaPorAliado(tabuleiro, nl, nc))
                        printf("- %c%d\n", 'A' + nc, TAM - nl);
                }
            }
            break;

        case 'C':
            {
                int movimentos[8][2] = {
                    {-2, +1}, {-2, -1}, {+2, +1}, {+2, -1},
                    {-1, +2}, {+1, +2}, {-1, -2}, {+1, -2}
                };
                for (i = 0; i < 8; i++) {
                    int nl = linha + movimentos[i][0];
                    int nc = coluna + movimentos[i][1];
                    if (dentroDoTabuleiro(nl, nc) && !casaOcupadaPorAliado(tabuleiro, nl, nc))
                        printf("- %c%d\n", 'A' + nc, TAM - nl);
                }
            }
            break;
    }
}

int main() {
    system("chcp 65001 < null"); //UTF8
    char tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    char origem[3];
    int continuar = 1;

    while (continuar) {
        imprimirTabuleiro(tabuleiro);

        printf("\nDigite a posição da peça (ex: E2): ");
        scanf("%s", origem);

        int colOrigem = coordCol(origem[0]);
        int linOrigem = coordLin(origem[1]);
        char peca = tabuleiro[linOrigem][colOrigem];

        if (!isupper(peca)) {
            printf("Só é permitido mover peças brancas (maiúsculas).\n");
            continue;
        }

        listarMovimentosValidos(tabuleiro, peca, linOrigem, colOrigem);

        char destino[3];
        printf("\nDigite a posição de destino (ex: E4): ");
        scanf("%s", destino);

        int colDestino = coordCol(destino[0]);
        int linDestino = coordLin(destino[1]);

        if (!dentroDoTabuleiro(linDestino, colDestino)) {
            printf("Destino fora do tabuleiro.\n");
            continue;
        }

                if (casaOcupadaPorAliado(tabuleiro, linDestino, colDestino)) {
            printf("Destino ocupado por peça aliada. Movimento inválido.\n");
            continue;
        }

        tabuleiro[linDestino][colDestino] = peca;
        tabuleiro[linOrigem][colOrigem] = ' ';
        printf("\nMover de %s para %s\n", origem, destino);

        imprimirTabuleiro(tabuleiro);

        printf("\nDeseja continuar? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
    }

    return 0;
}
