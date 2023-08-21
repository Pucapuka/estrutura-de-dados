/****************************************************
Praticando Bubble Sort
*****************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct Vet {
    No* posterior;
    No* anterior;
} Vet;

Vet* criarVetor() {
    Vet* vetor = (Vet*)malloc(sizeof(Vet));
    vetor->posterior = NULL;
    vetor->anterior = NULL;
    return vetor;
}

void adicionarItem(Vet* item, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    
    if (item->posterior == NULL) {  // Fila vazia
        item->posterior = novo;
        item->anterior = novo;
        novo->proximo = novo;  // Circular
    } else {
        novo->proximo = item->posterior;
        item->anterior->proximo = novo;
        item->anterior = novo;
    }
    
    printf("O valor %d foi adicionado com sucesso.\n", valor);
}

int removerItem(Vet* item) {
    if (item->posterior == NULL) {
        printf("O vetor está vazio.\n");
        return -1;
    }
    
    int valor_removido;
    
    if (item->posterior == item->anterior) {  // Último elemento no vetor
        valor_removido = item->posterior->dado;
        free(item->posterior);
        item->posterior = NULL;
        item->anterior = NULL;
    } else {
        No* temp = item->posterior;
        valor_removido = temp->dado;
        item->posterior = item->posterior->proximo;
        item->anterior->proximo = item->posterior;
        free(temp);
    }
    
    printf("O valor %d foi removido do vetor.\n", valor_removido);
    return valor_removido;
}

void listar(Vet* item) {
    if (item->posterior == NULL) {
        printf("Não há elementos no vetor.\n");
        return;
    }
    
    No* temp = item->posterior;
    
    printf("\nItens no vetor: \n");
    do {
        printf("%d ", temp->dado);
        temp = temp->proximo;
    } while (temp != item->posterior);
    
    printf("\n");
}

void bubbleSort(Vet* item){
    int i,j;
    if (item -> posterior == NULL){
        printf("\nLista vazia\n");
        return;
    }
    No* n = (No*)malloc(sizeof(No));
    No* aux = NULL;
    
    for(item->anterior; item->posterior=NULL; item->posterior->proximo){
        if(item->posterior->dado<item->anterior->dado){
        aux = item->posterior;
        item->posterior = item->anterior;
        item->anterior = aux;
        free(aux);
        }
 
    }
}

// Função principal
int main() {
    int opcao, valor;
    Vet *item = criarVetor();

    while (true) {
        // Menu de opções
        printf("\n------------------------------------\n");
        printf("Ordenação de elementos - Bubble Sort");
        printf("\n------------------------------------\n");
        printf("\nOpções:\n");
        
        printf("0. Sair\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar fila\n");
        printf("4. Ordenar (Bubble Sort)\n");
        
        scanf("%d", &opcao);

        //trabalhando as opções uma a uma
        switch (opcao){
            case 1:
                printf("Adicionar o item: ");
                scanf("%d", &valor);
                adicionarItem(item, valor);
                break;

            case 2:
                printf("Removendo...\n");
                removerItem(item);
                break;

            case 3:
                listar(item);
                break;

            case 4:
                bubbleSort(item);
                break;
            
            case 0:
                printf("Saindo...");
                exit(0);
            
            default:
                printf("Opção inválida");
                break;
        }
    }
    return 0;
}
