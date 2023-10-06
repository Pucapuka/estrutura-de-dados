#include <stdio.h>
#include <stdlib.h>

typedef struct SFila{
    int dado;
    struct SFila * next;
} TFila;

//Sentinela
TFila * fila = NULL;


void primeiro(int info){
    fila = malloc(sizeof(TFila));
    fila->dado = info;
    fila->next = NULL;
}

void proximos(int info){
    TFila * novo = malloc(sizeof(TFila));
    TFila * ultimo;

    novo->dado = info;
    novo->next = NULL;

    ultimo = fila;
    while (ultimo->next != NULL){
        ultimo = ultimo->next;
    }

    ultimo->next = novo;
}

void enqueue(int info){
    if (fila == NULL)
        primeiro(info);
    else
        proximos(info);
}

void listar(){
    if (fila == NULL){
        printf("A fila está vazia\n");
        return;
    }

    TFila * ultimo;
    printf("\n\nValores da lista\n");
    ultimo = fila;
    do {
        printf("%d ",ultimo->dado);
        ultimo = ultimo->next;
    } while (ultimo != NULL);
}

 

