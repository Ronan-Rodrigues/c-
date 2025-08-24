#include <stdio.h>
#include <stdlib.h>


int main() {
    system("chcp 65001"); // Corrige as acentuações

    //Exmplo de uso de estruturas de repetição imprindindo números pares de 0 a 100

    for (int pares = 0; pares <=100; pares ++){
        if(pares % 2 == 0){
            printf("Imprimindo numeros pares de 0 a 100 = %d\n", pares);
        }
    }
    
    for (int impares = 0; impares <=100; impares ++){
        if(impares % 2 != 0){
            printf("Imprimindo numeros impares de 0 a 100 = %d\n", impares);
        }
    }

    //Exemplo de uso de estrutura de repetição while
    //Imprimindo números pares e ímpares de 0 a 100
    
    int x = 0;
    while (x <= 100){
        if(x % 2 == 0){
            printf("Imprimindo numeros pares de 0 a 100 = %d\n", x);
        }
        x++;
    }

    int w = 0;
    while (w <= 100){
        if(w % 2 != 0){
            printf("Imprimindo numeros impares de 0 a 100 = %d\n", w);
        }
        w++;
    }

    //Exemplo de uso de estrutura de repetição do while
    //Imprimindo números pares e ímpares de 0 a 100
    int y = 0;
    do{
        if(y % 2 == 0){
            printf("Imprimindo numeros pares de 0 a 100 = %d\n", y);
        }
        y++;
    }while(y <= 100);

    do
    {
        if(y % 2 != 0){
            printf("Imprimindo numeros impares de 0 a 100 = %d\n", y);
        }
        y++;
    }while(y <= 100);
    
    //Exemplo de uso de estrutura de repetição com condição de saída
    //O programa só encerra quando o usuário digitar um número par
    int numero;

    do
    {

    printf("Digite um número par para sair do programa: ");
    scanf("%d", &numero);
    
    if (numero % 2 == 0) {
        printf("Você digitou um número par. Saindo do programa...\n");
    } else {
        printf("Número ímpar digitado. O programa continuará em execução.\n");
    }
    } while (numero % 2 != 0);

    printf("Voce digitou o número par %d e o programa foi encerrado.\n", numero);
    
    
 
    //Exemplo de tabuada
    //Com entrada do usuário

    int numero,i;
    printf("Digite um número para ver a tabuada: ");
    scanf("%d", &numero);
    printf("Tabuada do %d:\n", numero);

    for(i = 0; i <= 10; i++)
    {
        printf("%d x %d = %d\n", numero, i, numero * i);
        
    }

    //Exemplo de tabuada do 1 ao 10
    
    printf("Tabuada do 1 ao 10:\n");
    

   int tabuada[10];

    for (int num = 1; num <= 10; num++) {
        printf("Tabuada do %d:\n", num);
        for (int i = 0; i < 10; i++) {
            tabuada[i] = num * (i + 1);
            printf("%d x %d = %d\n", num, i + 1, tabuada[i]);
        }
        printf("================================\n");
    }

    

        printf("Tabuada do 1:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 1 * (i + 1);
        printf("1 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");
    printf("Tabuada do 2:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 2 * (i + 1);
        printf("2 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");

    printf("Tabuada do 3:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 3 * (i + 1);
        printf("3 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");
    printf("Tabuada do 4:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 4 * (i + 1);
        printf("4 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");
    printf("Tabuada do 5:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 5 * (i + 1);
        printf("5 x %d = %d\n", i + 1, tabuada[i]);
    }   
    printf("================================\n");
    printf("Tabuada do 6:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 6 * (i + 1);
        printf("6 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");
    printf("Tabuada do 7:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 7 * (i + 1);
        printf("7 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");
    printf("Tabuada do 8:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 8 * (i + 1);
        printf("8 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");
    printf("Tabuada do 9:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 9 * (i + 1);
        printf("9 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");
    printf("Tabuada do 10:\n");
    for (int i = 0; i < 10; i++) {
        tabuada[i] = 10 * (i + 1);
        printf("10 x %d = %d\n", i + 1, tabuada[i]);
    }
    printf("================================\n");
    return 0;
 
}
