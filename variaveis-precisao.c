#include <stdio.h>
#include <stdlib.h>
 
int main() {
    // Configuração do console para UTF-8
    system("chcp 65001");
    // Exemplo de variáveis com precisão diferente
    // Tipos de dados com precisão diferente
    double preciseNumber = 3.141592653589793;
    long double veryPreciseNumber = 3.14159265358979323846;

 
    printf("Número preciso (double): %.15f\n", preciseNumber);
    printf("Número muito preciso (long double): %.21Lf\n", veryPreciseNumber);
 

    return 0;
}