#include <stdio.h>

int main() {
    #ifdef _WIN32
        printf("Sistema operacional: Windows (32 ou 64 bits)\n");
    #elif __linux__
        printf("Sistema operacional: Linux\n");
    #elif __APPLE__
        printf("Sistema operacional: macOS\n");
    #else
        printf("Sistema operacional desconhecido\n");
    #endif

    return 0;
}
