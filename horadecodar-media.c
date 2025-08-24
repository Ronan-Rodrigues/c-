#include <stdio.h>
#include <stdlib.h> 

int main() {
    system("chcp 65001");
    float n1, n2, media;
    
    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    

    
    media = (n1 + n2) / 2.0;
    
    printf("A média das notas é: %.2f\n", media);
    
    return 0;
}