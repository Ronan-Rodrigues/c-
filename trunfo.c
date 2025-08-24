/*
Código desenvolvido por: Ronan Teixeira Rodrigues
Prática de programação em C - Jogo Super Trunfo
Data da Criação 11/08/2025
Nível básico - Cadastramento de 2 cartas 
*/

#include <stdio.h>
#include <string.h>
//#include <locale.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");
  //  setlocale(LC_ALL, "");

    //Variaveis  das cartas
  char *estado[2], *codigocarta[2], *nomecidade[2];
  int populacao[2], pontos[2], carta[2];
  float area[2], pib[2],densidade[2], pibpercapita[2]; 

//Carta Nº 1
  carta[0] = 1;
  estado[0] = "A";
  codigocarta[0] = "A01";
  nomecidade[0] = "SAO PAULO";
  populacao[0] = 12325000.00;
  area[0] = 1521.11;
  pib[0] = 69928000.00; // PIB em bilhões de reais
  pontos[0] = 50;

  densidade[0] = populacao[0] / area[0];
  pibpercapita[0] = pib[0] / populacao[0];

  //Carta Nº 2
  carta[1] = 2;
  estado[1] = "M";
  codigocarta[1] = "M01";
  nomecidade[1] = "RIO DE JANEIRO";
  populacao[1] = 6748000.00;
  area[1] = 1200.25;
  pib[1] = 30050000.00; // PIB em bilhões de reais
  pontos[1] = 30;

  densidade[1] = populacao[1] / area[1];
  pibpercapita[1] = pib[1] / populacao[1];

printf("\n");
printf("====================================\n");
printf("\n");  
printf("Super Trunfo - Jogo de Cartas\n");
printf("Cartas Cadastradas:\n");
printf("\n");
printf("====================================\n"); 
printf("Carta %d\n", carta[0]);
printf("Estado: %s\n", estado[0]);
printf("Código: %s\n", codigocarta[0]);
printf("Nome da Cidade: %s\n", nomecidade[0]);
printf("População: %d\n", populacao[0]);
printf("Área: %.2f km² \n", area[0]);
printf("PIB: %.2f bilhões de reais \n", pib[0]);
printf("Número de Pontos Turísticos: %d\n", pontos[0]);
printf("Densidade Populacional: %.2f hab/km² \n", densidade[0]);
printf("PIB per capita: %.2f reais \n", pibpercapita[0]);

printf("\n");
printf("====================================\n");
printf("Carta %d\n", carta[1]);
printf("Estado: %s\n", estado[1]);
printf("Código: %s\n", codigocarta[1]);
printf("Nome da Cidade: %s\n", nomecidade[1]);
printf("População: %d\n", populacao[1]);
printf("Área: %.2f km² \n", area[1]);
printf("PIB: %.2f bilhões de reais \n", pib[1]);
printf("Número de Pontos Turísticos: %d\n", pontos[1]);
printf("Densidade Populacional: %.2f hab/km² \n", densidade[1]);
printf("PIB per capita: %.2f reais \n", pibpercapita[1]);
printf("\n");
printf("====================================\n");
    
}


/*
Tipos de Dados e seus Intervalos
Os tipos de dados em C e seus intervalos são:
Tipo	Intervalo de valores
int	-2,147,483,648 a 2,147,483,647
unsigned int	0 a 4,294,967,295
char	-128 a 127
unsigned char	0 a 255

*/