/******************************************************************************

implementação selection sort - esse método de ordenação é o oposto do bubble sort,  
pegando o menor elemento e o trazendo para a menor posição.

Essa implementação será a com algoritmo estável (que não move o elemento que já estaria em sua posição final)

Para verificar a estabilidade, só descomentar a função teste, chamada dentro da função selection_sort.
*******************************************************************************/
#include <stdio.h>
#define TAMANHO 10

int array[TAMANHO] = {2,1,4,5,3,7, 6, 8,10,9};

void teste(int array[], int tamanho){
    printf("\n\n");
    for (int j = 0; j < tamanho; j++){
        printf("%d ", array[j]);
    }
    printf("\n\n");
}

void selection_sort(int array[], int tamanho){
    int aux, j, i, k;
    
    for (j = 0; j < tamanho-1; j++){
        for (i = 1; i<tamanho; i++){
            if(array[i]<array[i-1]){
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
            }
            //teste(array, TAMANHO);
        }
    }
    
}

int main()
{
    int i;
    
    
    for(i = 0; i<TAMANHO; i++){
        printf("%d ", array[i]);
    }
    
    selection_sort(array, TAMANHO);
    
    printf("\n\n");
    
    for(i = 0; i<TAMANHO; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}
