#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// Função para cadastrar uma carta via entrada do usuário
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);
    printf("Estado (sigla): ");
    scanf(" %2s", carta->estado);

    printf("Código da carta: ");
    scanf(" %9s", carta->codigo);

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

    // Calcula os indicadores derivados
    calcularIndicadores(carta);
}

int main() {
    system("chcp 65001");
    // Variáveis para armazenar as cartas
    Carta carta1, carta2;

    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibe as cartas
    printf("\n=== Carta 1 ===\n");
    exibirCarta(carta1);

    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Comparação pelo atributo escolhido: PIB per capita
    printf("Comparação de cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s: %.2f\n", carta1.nomeCidade, carta1.pibPerCapita);
    printf("Carta 2 - %s: %.2f\n", carta2.nomeCidade, carta2.pibPerCapita);

    // Lógica de decisão
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
