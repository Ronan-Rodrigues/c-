#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define NUM_CARTAS 10
#define EPSILON 0.0001

typedef struct {
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular os indicadores derivados
void calcularIndicadores(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao;
}

// Função para obter o valor de um atributo
float obterValorPorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidadePopulacional;
        case 5: return c.pibPerCapita;
        default: return 0;
    }
}

// Função para comparar dois valores de atributo
int compararAtributo(float valor1, float valor2, int atributo) {
    if (atributo == 4) { // Densidade: menor é melhor
        if (valor1 + EPSILON < valor2) return 1;
        else if (valor2 + EPSILON < valor1) return 2;
        else return 0;
    } else { // Outros: maior é melhor
        if (valor1 > valor2 + EPSILON) return 1;
        else if (valor2 > valor1 + EPSILON) return 2;
        else return 0;
    }
}

// Função para decidir o vencedor com base nos dois atributos
int calcularVencedor(int resultado1, int resultado2) {
    if (resultado1 == resultado2) return resultado1;
    if (resultado1 == 0) return resultado2;
    if (resultado2 == 0) return resultado1;
    return 0; // Empate
}

// Função para imprimir os dados de uma carta
void imprimirCarta(Carta c) {
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f R$\n", c.pibPerCapita);
    printf("-----------------------------\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Carta cartas[NUM_CARTAS] = {
        {"São Paulo", 12300000, 1521.11, 700.0},
        {"Rio de Janeiro", 6748000, 1182.3, 400.0},
        {"Belo Horizonte", 2527000, 331.4, 105.0},
        {"Curitiba", 1963000, 434.9, 90.0},
        {"Porto Alegre", 1485000, 496.8, 85.0},
        {"Recife", 1653000, 218.5, 75.0},
        {"Fortaleza", 2687000, 313.8, 80.0},
        {"Salvador", 2887000, 692.8, 95.0},
        {"Brasília", 3057000, 5802.0, 130.0},
        {"Manaus", 2213000, 11401.1, 70.0}
    };

    // Calcula os indicadores derivados
    for (int i = 0; i < NUM_CARTAS; i++) {
        calcularIndicadores(&cartas[i]);
    }

    // Exemplo de comparação entre duas cartas
    int i1 = 0; // São Paulo
    int i2 = 1; // Rio de Janeiro
    int atributo1 = 1; // População
    int atributo2 = 5; // PIB per capita

    float valor1_attr1 = obterValorPorAtributo(cartas[i1], atributo1);
    float valor2_attr1 = obterValorPorAtributo(cartas[i2], atributo1);
    float valor1_attr2 = obterValorPorAtributo(cartas[i1], atributo2);
    float valor2_attr2 = obterValorPorAtributo(cartas[i2], atributo2);

    int resultado1 = compararAtributo(valor1_attr1, valor2_attr1, atributo1);
    int resultado2 = compararAtributo(valor1_attr2, valor2_attr2, atributo2);

    int vencedor = calcularVencedor(resultado1, resultado2);

    printf("Comparando %s vs %s\n", cartas[i1].nomeCidade, cartas[i2].nomeCidade);
    printf("Atributo %d: %.2f vs %.2f → Resultado: %d\n", atributo1, valor1_attr1, valor2_attr1, resultado1);
    printf("Atributo %d: %.2f vs %.2f → Resultado: %d\n", atributo2, valor1_attr2, valor2_attr2, resultado2);

    if (vencedor == 1)
        printf("🏆 Vencedor: %s\n", cartas[i1].nomeCidade);
    else if (vencedor == 2)
        printf("🏆 Vencedor: %s\n", cartas[i2].nomeCidade);
    else
        printf("🤝 Empate!\n");

    return 0;
}
