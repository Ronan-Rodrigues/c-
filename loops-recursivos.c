#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Necessário para toupper
#include <time.h> // Necessário para funções de tempo
#include <string.h> // Necessário para manipulação de strings


// Definição de procedimentos
void contagemRegressiva(int n){
    if (n > 0){
        printf("%d \n", n); //Imprimi o valor atual de n
        contagemRegressiva(n -1); //Retira 1 do valor n
    }

}

void contagemDecrecente(int n){
    if (n > 0){
        printf("%d \n", n); //Imprimi o valor atual de n
        contagemDecrecente(n -1); //Retira 1 do valor n
    }

}

void contagemCrescente(int n){
    if (n > 0){
        contagemCrescente(n -1); //Retira 1 do valor n
         printf("%d \n", n); //Imprimi o valor atual de n
    }

}

int main() {
system("chcp 65001 > null"); // Define UTF-8 no terminal do Windows

    //Variavel que sera usada na função contagemRegressiva como parametro n
    int numero, opcao;
/*
    printf("Insira um numero para a contagem regressiva:\n");
    scanf("%d", &numero);

    printf("Valor definido: %d\n",numero);
    printf("Contagem regressiva...\n");
    //Chama a função contagemRegressiva e passa a variavel numero como parametro n
    contagemRegressiva(numero);
*/

    //iniciando o menu de opção
    printf("Iniciando o programa de contagem crescente e decrecente\n");
    printf("Escolha a opção: 1 ou 2 \n");
    printf("1. Crescente \n");
    printf("2. Decrescente \n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        //iniciando a contagem crescente
        printf("Insira um numero para a contagem crescente:\n");
        scanf("%d", &numero);
        printf("Valor definido: %d\n",numero);
        printf("Contagem crescente...\n");
        contagemCrescente(numero);
        break;
    case 2:
        //iniciando a contagem decrescente
        printf("Insira um numero para a contagem Decrescente:\n");
        scanf("%d", &numero);
        printf("Valor definido: %d\n",numero);
        printf("Contagem Decrescente...\n");        
        contagemDecrecente(numero);
        break;
    default:
        //Opcao invalida!
        printf("Opção Inválida! Escolha 1 ou 2");
        break;
    }

    return 0;
}