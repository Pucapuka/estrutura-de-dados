//implementando uma fila encadeada circular

/*
A fila encadeada segue o padrão de FIFO da estrutura de dados. É circular devido o ponteiro da última posição 
apontar para o endereço do primeiro. É encadeada por estar ligada as outras por nós, formando cadeias e ter número 
"ilimitado" de adição de elementos.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct Queue {
    No* posterior;
    No* anterior;
} Queue;

Queue* CriarFila() {
    Queue* fila = (Queue*)malloc(sizeof(Queue));
    fila->posterior = NULL;
    fila->anterior = NULL;
    return fila;
}

void enfileirar(Queue* fila, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    
    if (fila->posterior == NULL) {  // Fila vazia
        fila->posterior = novo;
        fila->anterior = novo;
        novo->proximo = novo;  // Circular
    } else {
        novo->proximo = fila->posterior;
        fila->anterior->proximo = novo;
        fila->anterior = novo;
    }
    
    printf("O valor %d foi enfileirado com sucesso.\n", valor);
}

int remover(Queue* fila) {
    if (fila->posterior == NULL) {
        printf("A fila está vazia.\n");
        return -1;
    }
    
    int valor_removido;
    
    if (fila->posterior == fila->anterior) {  // Último elemento na fila
        valor_removido = fila->posterior->dado;
        free(fila->posterior);
        fila->posterior = NULL;
        fila->anterior = NULL;
    } else {
        No* temp = fila->posterior;
        valor_removido = temp->dado;
        fila->posterior = fila->posterior->proximo;
        fila->anterior->proximo = fila->posterior;
        free(temp);
    }
    
    printf("O valor %d foi removido da fila.\n", valor_removido);
    return valor_removido;
}

void listar(Queue* fila) {
    if (fila->posterior == NULL) {
        printf("A fila está vazia.\n");
        return;
    }
    
    No* temp = fila->posterior;
    
    printf("\nItens fila: \n");
    do {
        printf("%d ", temp->dado);
        temp = temp->proximo;
    } while (temp != fila->posterior);
    
    printf("\n");
}

int buscar(Queue* fila, int valor) {

    if (fila->posterior == NULL) {
        printf("A fila está vazia.\n");
        return 0;
    }
    
    No* temp = fila->posterior;
    int posicao = 1;

    do {
        if (temp->dado == valor) {
            printf("O valor %d foi encontrado na posicao %d.\n", valor, posicao);
            return 1;
        }
        
        temp = temp->proximo;
        posicao ++;

    } while (temp != fila->posterior);
    
    printf("O valor %d não foi encontrado na fila.\n", valor);
    return 0;
}

// Função principal
int main() {
    int choice, valor;
    Queue *fila = CriarFila();

    while (true) {
        // Menu de opções
        printf("\n-----------------------\n");
        printf("Fila Encadeada Circular");
        printf("\n-----------------------\n");
        printf("\nOpções:\n");
        
        printf("0. Sair\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar fila\n");
        printf("4. Buscar item\n");
        
        scanf("%d", &choice);

        //trabalhando as opções uma a uma
        switch (choice){
            case 1:
                printf("Adicionar o item: ");
                scanf("%d", &valor);
                enfileirar(fila, valor);
                break;

            case 2:
                printf("Removendo...\n");
                remover(fila);
                break;

            case 3:
                listar(fila);
                break;

            case 4:
                printf("Qual item você busca?\n");
                scanf("%d", &valor);
                buscar(fila, valor);
            
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
