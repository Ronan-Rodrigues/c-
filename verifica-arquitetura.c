#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");
    #ifdef _WIN32
        printf("Sistema operacional: Windows \n");
    #elif __linux__
        printf("Sistema operacional: Linux\n");
    #elif __APPLE__
        printf("Sistema operacional: macOS\n");
    #else
        printf("Sistema operacional desconhecido\n");
    #endif



    #ifdef _WIN64
        printf("Arquitetura: 64 bits\n");
    #elif _WIN32
        printf("Arquitetura: 32 bits\n");
    #elif __x86_64__ || __ppc64__
        printf("Arquitetura: 64 bits\n");
    #else
        printf("Arquitetura: 32 bits\n");
    #endif

    printf("Verificação de arquitetura concluída.\n");

    return 0;
}