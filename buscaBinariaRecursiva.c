#include <stdio.h>
#include <stdlib.h>
#define TAM 10


int array[TAM] = {1, 5, 8, 16, 22, 34, 39, 41, 50, 63};


int buscaBinaria(int array[], int inicio, int fim, int key) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2; //enquanto a lista tiver mais de um elemento


        if (key == array[meio]) {
            return meio;  // Elemento encontrado
        } else if (key < array[meio]) {
            return buscaBinaria(array, inicio, meio - 1, key);  // Busca na metade esquerda
        } else {
            return buscaBinaria(array, meio + 1, fim, key);  // Busca na metade direita
        }
    }


    return -1;  // Elemento não encontrado
}


int main() {
    int dado, busca;


    printf("Busca binária com recursividade\n\n");
    printf("Qual valor você procura?\n");
    scanf("%d", &dado);
    printf("Localizando...\n");


    busca = buscaBinaria(array, 0, TAM - 1, dado);


    if (busca == -1) {
        printf("Item não encontrado\n");
    } else {
        printf("Item encontrado na posição %d.\n", busca);
    }


    return 0;
}





