#include <stdio.h>

typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

int main() {
    Carta c1, c2;
    int op1, op2, pontos1 = 0, pontos2 = 0;

    // Cadastro rápido
    printf("Cadastro Carta 1 (Cidade Populacao Area PIB PontosTuristicos): ");
    scanf(" %s %s %s %d %f %f %d", c1.estado, c1.codigo, c1.cidade,
          &c1.populacao, &c1.area, &c1.pib, &c1.pontosTuristicos);

    printf("Cadastro Carta 2 (Cidade Populacao Area PIB PontosTuristicos): ");
    scanf(" %s %s %s %d %f %f %d", c2.estado, c2.codigo, c2.cidade,
          &c2.populacao, &c2.area, &c2.pib, &c2.pontosTuristicos);

    printf("\nEscolha dois atributos para comparar:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n");

    printf("Primeiro atributo: ");
    scanf("%d", &op1);
    printf("Segundo atributo: ");
    scanf("%d", &op2);

    // Função comparativa inline com operador ternário
    switch(op1) {
        case 1: pontos1 += (c1.populacao > c2.populacao) ? 1 : 0;
                pontos2 += (c2.populacao > c1.populacao) ? 1 : 0; break;
        case 2: pontos1 += (c1.area > c2.area) ? 1 : 0;
                pontos2 += (c2.area > c1.area) ? 1 : 0; break;
        case 3: pontos1 += (c1.pib > c2.pib) ? 1 : 0;
                pontos2 += (c2.pib > c1.pib) ? 1 : 0; break;
        case 4: pontos1 += (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 0;
                pontos2 += (c2.pontosTuristicos > c1.pontosTuristicos) ? 1 : 0; break;
    }

    switch(op2) {
        case 1: pontos1 += (c1.populacao > c2.populacao) ? 1 : 0;
                pontos2 += (c2.populacao > c1.populacao) ? 1 : 0; break;
        case 2: pontos1 += (c1.area > c2.area) ? 1 : 0;
                pontos2 += (c2.area > c1.area) ? 1 : 0; break;
        case 3: pontos1 += (c1.pib > c2.pib) ? 1 : 0;
                pontos2 += (c2.pib > c1.pib) ? 1 : 0; break;
        case 4: pontos1 += (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 0;
                pontos2 += (c2.pontosTuristicos > c1.pontosTuristicos) ? 1 : 0; break;
    }

    printf("\nResultado final:\n");
    if (pontos1 > pontos2)
        printf("Vencedor: %s (%s)\n", c1.cidade, c1.codigo);
    else if (pontos2 > pontos1)
        printf("Vencedor: %s (%s)\n", c2.cidade, c2.codigo);
    else
        printf("Empate!\n");

    return 0;
}
