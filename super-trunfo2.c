#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CARTAS 100

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular os indicadores derivados
void calcularIndicadores(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

// Função para exibir os dados da carta
void exibirCarta(Carta c) {
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", c.pibPerCapita);
}

// Função que conta quantas cartas já existem para um estado
int contarCartasPorEstado(Carta cartas[], int total, const char estado[]) {
    int contador = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(cartas[i].estado, estado) == 0) {
            contador++;
        }
    }
    return contador;
}

// Função para cadastrar uma carta via entrada do usuário
void cadastrarCarta(Carta *carta, Carta cartas[], int totalCartas) {
    printf("\n=== Cadastro da Carta %d ===\n", totalCartas + 1);

    printf("Estado (sigla): ");
    scanf(" %2s", carta->estado);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Gera o código automaticamente
    int numero = contarCartasPorEstado(cartas, totalCartas, carta->estado) + 1;
    sprintf(carta->codigo, "%s%03d", carta->estado, numero);

    // Calcula os indicadores derivados
    calcularIndicadores(carta);
}

int main() {
    system("chcp 65001");
    Carta cartas[MAX_CARTAS];
    int totalCartas = 0;

    // Cadastro de duas cartas
    cadastrarCarta(&cartas[totalCartas], cartas, totalCartas);
    totalCartas++;

    cadastrarCarta(&cartas[totalCartas], cartas, totalCartas);
    totalCartas++;

    // Exibe as cartas
    printf("\n=== Carta 1 ===\n");
    exibirCarta(cartas[0]);

    printf("=== Carta 2 ===\n");
    exibirCarta(cartas[1]);

    // Comparação pelo atributo escolhido: PIB per capita
    printf("Comparação de cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s: %.2f\n", cartas[0].nomeCidade, cartas[0].pibPerCapita);
    printf("Carta 2 - %s: %.2f\n", cartas[1].nomeCidade, cartas[1].pibPerCapita);

    // Lógica de decisão
    if (cartas[0].pibPerCapita > cartas[1].pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cartas[0].nomeCidade);
    } else if (cartas[1].pibPerCapita > cartas[0].pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cartas[1].nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
