#include <stdio.h>

int main() {
    int idade = 25;
    printf("Idade: %d\n", idade);
    float altura = 1.75;
    printf("Altura: %.2f\n", altura);
    char nome[] = "João";
    printf("Nome: %s\n", nome);
    double peso = 70.5;
    printf("Peso: %.1f\n", peso);
    char inicial = 'J';
    printf("Inicial: %c\n", inicial);
    int ano_nascimento = 1998;
    printf("Ano de Nascimento: %d\n", ano_nascimento);
    int numero = 42;
    printf("Número: %d\n", numero);
    printf("Hello, World!\n");

    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Idade lida: %d\n", idade);

}

/*
A seguir, você tem uma lista dos principais especificadores utilizados:

 
%d: Imprime um inteiro no formato decimal.
 
%i: Equivalente a %d.
 
%f: Imprime um número de ponto flutuante no formato padrão.
 
%e: Imprime um número de ponto flutuante na notação científica.
 
%c: Imprime um único caractere.
 
%s: Imprime uma cadeia (string) de caracteres.

*/