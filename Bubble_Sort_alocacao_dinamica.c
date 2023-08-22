    /****************************************************
    Praticando Bubble Sort
    *****************************************************/ 
    #include <stdio.h>
    #include <stdlib.h>
    
    // Definindo a estrutura
    struct Elemento {
        int valor;
    };
    
    // Função para trocar dois elementos
    void trocar(struct Elemento *a, struct Elemento *b) {
        struct Elemento temp = *a;
        *a = *b;
        *b = temp;
    }
    
    // Função de ordenação Bubble Sort
    void bubbleSort(struct Elemento *array, int tamanho) {
        int i, j;
        for (i = 0; i < tamanho; i++) {
            for (j = 0; j < tamanho - 1; j++) {
                if (array[j].valor > array[j + 1].valor) {
                    trocar(&array[j], &array[j + 1]);
                }
            }
        }
    }
    
    int main() {
        int tamanho;
        
        printf("Digite o tamanho do array: ");
        scanf("%d", &tamanho);
        
        // Alocação dinâmica de um array de estruturas Elemento
        struct Elemento *array = (struct Elemento *)malloc(tamanho * sizeof(struct Elemento));
        
        if (array == NULL) {
            printf("Erro de alocação de memória\n");
            return 1;
        }
        
        // Preencha o array com valores
        printf("Digite os elementos do array:\n");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &array[i].valor);
        }
    
        // Chame a função bubbleSort para ordenar o array
        bubbleSort(array, tamanho);
    
        // Imprima o array ordenado
        printf("Array ordenado:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", array[i].valor);
        }
        printf("\n");
    
        // Libere a memória alocada
        free(array);
        
        return 0;
    }
