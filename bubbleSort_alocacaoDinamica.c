#include "filaEncadeada.h"

#define TAM 1000
#define FALSE 0
#define TRUE 1

int vetor[TAM];// = {5,4,3,2,1};

int trocas = 0;
int passos = 0;

void bubbleSort(int v[], int tamanho){
	int i,temp,j;
	int isOrdened = TRUE;
	for (j = 0; j < tamanho - 1; j++){
		for (i = 0; i < tamanho - (j + 1); i++){
			passos++;
			if (v[i] > v[i + 1]){
				trocas++;
				isOrdened = FALSE;
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
		if (isOrdened)
			return;
	}
}

// void listar(int v[], int tamanho){
// 	int i;
// 	printf("\n\nListando\n\n");
// 	for (i = 0; i < tamanho; i++){
// 		printf("%d ", v[i]);
// 	}
// }

void bubbleSortD(TFila * primeiro){
	int temp;
	TFila * atual, * ultimo;
	for (ultimo = primeiro; ultimo != NULL; ultimo = ultimo->next){
		for (atual = primeiro; atual->next != NULL; atual = atual->next){
			if (atual->dado > atual->next->dado){
				temp = atual->dado;
				atual->dado = atual->next->dado;
				atual->next->dado = temp;
			}
		}
	}
}

int main(){

	// int i = TAM;

	// while (--i > 0)
	// 	vetor[i] = TAM - i;

	// listar(vetor, TAM);
	// bubbleSort(vetor, TAM);
	// listar(vetor,TAM);
	// printf("Passos: %d    trocas: %d",passos, trocas);

	enqueue(5);
	enqueue(4);
	enqueue(3);
	enqueue(2);
	enqueue(1);
	listar();
	bubbleSortD(fila);
	listar();

	return 0;
}


