#include <stdio.h>
#include <stdlib.h>

int main() {
    // Controle de estoque de produtos
    system("chcp 65001");
    // Exemplo de controle de estoque
    // Variáveis para armazenar informações do produto
    char produtoA[30] = "Produto A";
    char produtoB[30] = "Produto B";
    
    unsigned int estoqueA = 1000; // Quantidade inicial do produto A
    unsigned int estoqueB = 2000;  // Quantidade inicial do produto B

    float precoA = 29.99; // Preço do produto A
    float precoB = 49.99; // Preço do produto B
    
    unsigned int estoqueminimoA = 500; // Estoque mínimo do produto A
    unsigned int estoqueminimoB = 2500; // Estoque mínimo do produto B

    double valorTotalA; 
    double valorTotalB; 

    int resultadoA, resultadoB;

    printf("Produto: %s tem estoque %u e o valor unitario R$ %.2f\n", produtoA, estoqueA, precoA);
    printf("\nProduto: %s tem estoque %u e o valor unitario R$ %.2f\n", produtoB, estoqueB, precoB);
    printf("\n\n");
    // Verifica se o estoque do produto A está abaixo do mínimo
    resultadoA = estoqueA > estoqueminimoA;
    resultadoB = estoqueB > estoqueminimoB;

    printf("O produto %s tem estoque minino de %d\n", produtoA, resultadoA);
    printf("O produto %s tem estoque minino de %d\n", produtoB, resultadoB);

    // Calcula o valor total do estoque de cada produto
    valorTotalA = estoqueA * precoA;
    valorTotalB = estoqueB * precoB;

    printf("\nValor total do estoque de %s: R$ %.2f\n", produtoA, valorTotalA);
    printf("Valor total do estoque de %s: R$ %.2f\n", produtoB, valorTotalB);
    printf("\n");
    // Verifica se o estoque do produto A é maior que o estoque do produto B
    if (estoqueA > estoqueB) {
        printf("O produto %s tem mais estoque que o produto %s\n", produtoA, produtoB);
    } else if (estoqueA < estoqueB) {
        printf("O produto %s tem mais estoque que o produto %s\n", produtoB, produtoA);
    } else {
        printf("Os produtos %s e %s têm o mesmo estoque.\n", produtoA, produtoB);
    }

}