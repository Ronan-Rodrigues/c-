#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CARTAS 81
#define EPSILON 0.0001

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

void calcularIndicadores(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao;
}

void exibirCarta(Carta c) {
    printf("\n📍 Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("Código: %s\n", c.codigo);
}

float obterValorPorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidadePopulacional;
        case 5: return c.pibPerCapita;
        case 6: return c.pontosTuristicos;
        default: return -1;
    }
}

const char* nomeAtributo(int a) {
    switch (a) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Populacional";
        case 5: return "PIB per capita";
        case 6: return "Pontos Turísticos";
        default: return "Desconhecido";
    }
}

void mostrarMenuAtributos() {
    printf("\nEscolha 3 atributos para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("6 - Pontos Turísticos\n");
}

int compararAtributo(float valor1, float valor2, int atributo) {
    printf("\n🔍 Comparando atributo %s:\n", nomeAtributo(atributo));
    printf("  Valor da Carta 1: %.2f\n", valor1);
    printf("  Valor da Carta 2: %.2f\n", valor2);

    if (atributo == 4) {
        if (valor1 + EPSILON < valor2) return 1;
        else if (valor2 + EPSILON < valor1) return 2;
        else return 0;
    } else {
        if (valor1 > valor2 + EPSILON) return 1;
        else if (valor2 > valor1 + EPSILON) return 2;
        else return 0;
    }
}

void exibirResultado(int vencedor, Carta c1, Carta c2, int a1, int a2, int a3) {
    printf("\n=== Resultado da Comparação ===\n");

    float v1a1 = obterValorPorAtributo(c1, a1);
    float v2a1 = obterValorPorAtributo(c2, a1);
    float v1a2 = obterValorPorAtributo(c1, a2);
    float v2a2 = obterValorPorAtributo(c2, a2);
    float v1a3 = obterValorPorAtributo(c1, a3);
    float v2a3 = obterValorPorAtributo(c2, a3);

    printf("\n🔹 %s:\n", nomeAtributo(a1));
    printf("  %s: %.2f\n", c1.nomeCidade, v1a1);
    printf("  %s: %.2f\n", c2.nomeCidade, v2a1);

    printf("\n🔹 %s:\n", nomeAtributo(a2));
    printf("  %s: %.2f\n", c1.nomeCidade, v1a2);
    printf("  %s: %.2f\n", c2.nomeCidade, v2a2);

    printf("\n🔹 %s:\n", nomeAtributo(a3));
    printf("  %s: %.2f\n", c1.nomeCidade, v1a3);
    printf("  %s: %.2f\n", c2.nomeCidade, v2a3);

    printf("\n🏆 Resultado Final:\n");
    if (vencedor == 1)
        printf("  Carta 1 (%s) venceu!\n\n", c1.nomeCidade);
    else if (vencedor == 2)
        printf("  Carta 2 (%s) venceu!\n\n", c2.nomeCidade);
    else
        printf("  🤝 Empate entre as cartas!\n\n");
}

int buscarPorCodigo(Carta cartas[], int total, const char codigo[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(cartas[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

void listarCidadesDoEstado(Carta cartas[], int total, const char sigla[]) {
    printf("\n📍 Cidades disponíveis no estado %s:\n", sigla);
    for (int i = 0; i < total; i++) {
        if (strcmp(cartas[i].estado, sigla) == 0) {
            printf("  Código: %s | Cidade: %s\n", cartas[i].codigo, cartas[i].nomeCidade);
        }
    }
}

int determinarVencedorPorAtributos(Carta c1, Carta c2, int atributos[], int totalAtributos) {
    int pontos1 = 0;
    int pontos2 = 0;

    for (int i = 0; i < totalAtributos; i++) {
        int atributo = atributos[i];
        float valor1 = obterValorPorAtributo(c1, atributo);
        float valor2 = obterValorPorAtributo(c2, atributo);
        int resultado = compararAtributo(valor1, valor2, atributo);

        if (resultado == 1) pontos1++;
        else if (resultado == 2) pontos2++;
    }

    if (pontos1 > pontos2) return 1;
    else if (pontos2 > pontos1) return 2;
    else return 0;
}

void inicializarBanco(Carta cartas[]) {
    Carta base[] = {
        {"SP", "SP001", "São Paulo", 11895578, 1521, 85, 80},
        {"SP", "SP002", "Campinas", 1213792, 795, 70, 75},
        {"RJ", "RJ001", "Rio de Janeiro", 6729894, 1200, 90, 100},
        {"RJ", "RJ002", "Niterói", 515317, 133, 60, 85}
        // Adicione mais cidades conforme necessário
    };

    int total = sizeof(base) / sizeof(base[0]);
    for (int i = 0; i < total; i++) {
        cartas[i] = base[i];
        calcularIndicadores(&cartas[i]);
    }
}

int main() {
    system("chcp 65001");

    Carta cartas[MAX_CARTAS];
    inicializarBanco(cartas);

    int opcao;
    do {
        printf("\n=== Menu Principal ===\n");
        printf("1 - Listar cidades por estado\n");
        printf("2 - Comparar duas cidades\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char sigla[3];
                printf("\nDigite a sigla do estado (ex: SP): ");
                scanf(" %2s", sigla);
                for (int i = 0; i < strlen(sigla); i++) {
                    sigla[i] = toupper(sigla[i]);
                }
                listarCidadesDoEstado(cartas, MAX_CARTAS, sigla);
                break;
            }

            case 2: {
                char sigla1[3], sigla2[3];
                char codigo1[10], codigo2[10];
                int i1, i2;

                printf("\nDigite a sigla do primeiro estado (ex: SP): ");
                scanf(" %2s", sigla1);
                for (int i = 0; i < strlen(sigla1); i++) {
                    sigla1[i] = toupper(sigla1[i]);
                }
                listarCidadesDoEstado(cartas, MAX_CARTAS, sigla1);
                printf("Digite o código da cidade desejada do estado %s: ", sigla1);
                scanf(" %9s", codigo1);
                i1 = buscarPorCodigo(cartas, MAX_CARTAS, codigo1);

                                printf("\nDigite a sigla do segundo estado (ex: RJ): ");
                scanf(" %2s", sigla2);
                for (int i = 0; i < strlen(sigla2); i++) {
                    sigla2[i] = toupper(sigla2[i]);
                }
                listarCidadesDoEstado(cartas, MAX_CARTAS, sigla2);
                printf("Digite o código da cidade desejada do estado %s: ", sigla2);
                scanf(" %9s", codigo2);
                i2 = buscarPorCodigo(cartas, MAX_CARTAS, codigo2);

                if (i1 == -1 || i2 == -1) {
                    printf("\n❌ Código de cidade não encontrado. Verifique os códigos digitados.\n");
                    break;
                }

                printf("\n=== Cartas Selecionadas ===\n");
                exibirCarta(cartas[i1]);
                exibirCarta(cartas[i2]);

                printf("\n=== Comparação de Atributos ===\n");
                mostrarMenuAtributos();

                int atributo1, atributo2, atributo3;
                printf("Escolha o primeiro atributo (1-6): ");
                scanf("%d", &atributo1);
                printf("Escolha o segundo atributo (1-6): ");
                scanf("%d", &atributo2);
                printf("Escolha o terceiro atributo (1-6): ");
                scanf("%d", &atributo3);

                if (atributo1 < 1 || atributo1 > 6 ||
                    atributo2 < 1 || atributo2 > 6 ||
                    atributo3 < 1 || atributo3 > 6 ||
                    atributo1 == atributo2 || atributo1 == atributo3 || atributo2 == atributo3) {
                    printf("\n❌ Atributos inválidos ou repetidos. Tente novamente.\n");
                    break;
                }

                int atributos[3] = {atributo1, atributo2, atributo3};
                int vencedor = determinarVencedorPorAtributos(cartas[i1], cartas[i2], atributos, 3);
                exibirResultado(vencedor, cartas[i1], cartas[i2], atributo1, atributo2, atributo3);
                break;
            }

            case 0:
                printf("\n👋 Encerrando o programa. Até mais!\n");
                break;

            default:
                printf("\n❌ Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
