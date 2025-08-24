#include <stdio.h>

int main() {
    int idade, matricula;
    float altura; 
    char nome[50];
    
    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    printf("Digite seu nome: \n");
    scanf("%s", nome);

    printf("Digite sua matrícula: \n");
    scanf("%d", &matricula);

    printf("Aluno: %s\ - Matricula: %d\n", nome, matricula);
    printf("Idade: %d anos - Altura: %.2f", idade, altura);
  

    return 0;
}