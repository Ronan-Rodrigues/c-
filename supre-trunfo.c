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

int main() {
    system("chcp 65001");
    // Cadastro das cartas
    Carta carta1 = {
        "SP", "C001", "São Paulo", 12300000, 1521.11, 700000.00, 15
    };

    Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro", 6000000, 1182.30, 400000.00, 12
    };

    // Calcula os indicadores
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibe as cartas
    printf("=== Carta 1 ===\n");
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
