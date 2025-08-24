#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

#define MAX_CARTAS 100

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

struct Memoria {
    char *dados;
    size_t tamanho;
};

size_t escreverCallback(void *conteudo, size_t tamanho, size_t nmemb, void *usuario) {
    size_t total = tamanho * nmemb;
    struct Memoria *mem = (struct Memoria *)usuario;

    char *ptr = realloc(mem->dados, mem->tamanho + total + 1);
    if (ptr == NULL) return 0;

    mem->dados = ptr;
    memcpy(&(mem->dados[mem->tamanho]), conteudo, total);
    mem->tamanho += total;
    mem->dados[mem->tamanho] = 0;

    return total;
}

int buscarDadosCidade(Carta *carta) {
    CURL *curl;
    CURLcode res;
    struct Memoria resposta;
    resposta.dados = malloc(1);
    resposta.tamanho = 0;

    char url[300];
    sprintf(url, "https://servicodados.ibge.gov.br/api/v1/localidades/municipios?nome=%s", carta->nomeCidade);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, escreverCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&resposta);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "Erro na requisição: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            free(resposta.dados);
            return 0;
        }

        cJSON *json = cJSON_Parse(resposta.dados);
        if (!json || !cJSON_IsArray(json)) {
            printf("Erro ao interpretar JSON.\n");
            cJSON_Delete(json);
            curl_easy_cleanup(curl);
            free(resposta.dados);
            return 0;
        }

        cJSON *cidade = cJSON_GetArrayItem(json, 0);
        cJSON *nome = cJSON_GetObjectItem(cidade, "nome");
        cJSON *microrregiao = cJSON_GetObjectItem(cidade, "microrregiao");
        cJSON *mesorregiao = cJSON_GetObjectItem(microrregiao, "mesorregiao");
        cJSON *UF = cJSON_GetObjectItem(mesorregiao, "UF");
        cJSON *sigla = cJSON_GetObjectItem(UF, "sigla");

        if (nome && sigla) {
            strcpy(carta->nomeCidade, nome->valuestring);
            strcpy(carta->estado, sigla->valuestring);
        }

        cJSON_Delete(json);
        curl_easy_cleanup(curl);
        free(resposta.dados);
        return 1;
    }

    return 0;
}

void calcularIndicadores(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

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

int contarCartasPorEstado(Carta cartas[], int total, const char estado[]) {
    int contador = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(cartas[i].estado, estado) == 0) {
            contador++;
        }
    }
    return contador;
}

void cadastrarCarta(Carta *carta, Carta cartas[], int totalCartas) {
    printf("\n=== Cadastro da Carta %d ===\n", totalCartas + 1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    if (!buscarDadosCidade(carta)) {
        printf("Erro ao buscar dados da cidade.\n");
        return;
    }

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    int numero = contarCartasPorEstado(cartas, totalCartas, carta->estado) + 1;
    sprintf(carta->codigo, "%s%03d", carta->estado, numero);

    calcularIndicadores(carta);
}

int main() {
    Carta cartas[MAX_CARTAS];
    int totalCartas = 0;

    cadastrarCarta(&cartas[totalCartas], cartas, totalCartas);
    totalCartas++;

    cadastrarCarta(&cartas[totalCartas], cartas, totalCartas);
    totalCartas++;

    printf("\n=== Carta 1 ===\n");
    exibirCarta(cartas[0]);

    printf("=== Carta 2 ===\n");
    exibirCarta(cartas[1]);

    printf("Comparação de cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s: %.2f\n", cartas[0].nomeCidade, cartas[0].pibPerCapita);
    printf("Carta 2 - %s: %.2f\n", cartas[1].nomeCidade, cartas[1].pibPerCapita);

    if (cartas[0].pibPerCapita > cartas[1].pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cartas[0].nomeCidade);
    } else if (cartas[1].pibPerCapita > cartas[0].pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cartas[1].nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
