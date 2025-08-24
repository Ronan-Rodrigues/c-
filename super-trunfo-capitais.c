#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_CAPITAIS 27

// Estrutura para armazenar os dados de cada capital
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib_per_capita;
    float densidade;
    float renda_per_capita;
    int pontos_turisticos;
} Capital;

// Função para imprimir os dados de uma capital
void imprimirCapital(Capital c) {
    printf("📍 %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB per capita: R$ %.2f\n", c.pib_per_capita);
    printf("Densidade: %.2f hab/km²\n", c.densidade);
    printf("Renda per capita: R$ %.2f\n", c.renda_per_capita);
    printf("Pontos turísticos: %d\n\n", c.pontos_turisticos);
}

int main() {
    // Configuração do console para UTF-8
    system("chcp 65001");
    // Array com os dados das capitais
    Capital capitais[NUM_CAPITAIS] = {
        {"São Paulo", 11895578, 1521, 85000, 7825, 4500, 80},
        {"Rio de Janeiro", 6729894, 1200, 55000, 5608, 3800, 100},
        {"Brasília", 2982818, 5802, 47800, 514, 4200, 40},
        {"Fortaleza", 2574412, 313, 25000, 8227, 2500, 50},
        {"Salvador", 2568928, 693, 30000, 3708, 2800, 70},
        {"Belo Horizonte", 2416339, 331, 40000, 7300, 3500, 45},
        {"Manaus", 2279686, 11401, 35000, 200, 3000, 35},
        {"Curitiba", 1829225, 434, 45000, 4214, 3800, 50},
        {"Recife", 1587707, 218, 38000, 7290, 3200, 60},
        {"Goiânia", 1494599, 739, 42000, 2023, 3400, 25},
        {"Belém", 1398531, 1059, 30000, 1321, 2600, 40},
        {"Porto Alegre", 1389322, 496, 48000, 2800, 3900, 45},
        {"São Luís", 1088057, 831, 28000, 1309, 2400, 35},
        {"Maceió", 994464, 511, 32000, 1946, 2700, 40},
        {"Campo Grande", 954537, 8096, 40000, 118, 3500, 20},
        {"Teresina", 902644, 1392, 27000, 648, 2300, 18},
        {"João Pessoa", 888679, 211, 35000, 4210, 3000, 35},
        {"Natal", 785368, 170, 33000, 4620, 2900, 40},
        {"Cuiabá", 682932, 3538, 38000, 193, 3400, 25},
        {"Aracaju", 628849, 182, 30000, 3456, 2800, 30},
        {"Florianópolis", 576361, 675, 50000, 854, 4000, 60},
        {"Porto Velho", 514873, 34082, 32000, 15, 2600, 15},
        {"Macapá", 487200, 6563, 28000, 74, 2400, 20},
        {"Boa Vista", 470169, 5686, 30000, 83, 2500, 18},
        {"Rio Branco", 387852, 8835, 29000, 44, 2400, 18},
        {"Vitória", 342800, 93, 55000, 3686, 4200, 35},
        {"Palmas", 323625, 2218, 35000, 146, 3000, 25}
    };

    // Exemplo: imprimir todas as capitais
    for (int i = 0; i < NUM_CAPITAIS; i++) {
        imprimirCapital(capitais[i]);
    }

    return 0;
}
