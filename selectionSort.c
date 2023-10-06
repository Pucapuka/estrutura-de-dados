#include "filaEncadeada.h"


#define TAM 5

int vetor[TAM] = {1,2,3,5,4};

int trocas = 0;
int passos = 0;



void selectionSort(int v[], int tamanho){
	int i,j,temp;
	for (i = 0; i < tamanho - 1; i++){
		for (j = i + 1; j < tamanho; j++){
			if (v[j] < v[i]){
				trocas++;
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}

void selectionSortE(int v[], int tamanho){
	int i,j,temp, menor;
	for (i = 0; i < tamanho - 1; i++){
		menor = i;
		for (j = i + 1; j < tamanho; j++){
			if (v[j] < v[menor]){
				menor = j;
			}
		}
		trocas++;
		temp = v[i];
		v[i] = v[menor];
		v[menor] = temp;
	}
}



// void listar(int v[], int tamanho){
// 	int i;
// 	printf("\n\nListando\n\n");
// 	for (i = 0; i < tamanho; i++){
// 		printf("%d ", v[i]);
// 	}
// }

void selectionSortD(TFila * primeiro){
	int temp;
	TFila * atual, * ultimo;
	for (atual = primeiro; atual->next != NULL; atual = atual->next){
		for (ultimo = atual->next; ultimo != NULL; ultimo = ultimo->next){
			if (ultimo->dado < atual->dado){
				trocas++;
				temp = atual->dado;
				atual->dado = ultimo->dado;
				ultimo->dado = temp;
			}
		}
	}
}

void selectionSortDE(TFila * primeiro){
	int temp;
	TFila * atual, * ultimo, *menor, *maior;
	for (atual = primeiro; atual->next != NULL; atual = atual->next){
		menor = atual;
		for (ultimo = atual->next; ultimo != NULL; ultimo = ultimo->next){
			if (ultimo->dado < menor->dado){
				menor = ultimo;
			}
		}
		trocas++;
		temp = atual->dado;
		atual->dado = menor->dado;
		menor->dado = temp;
	}
}

int main(){

	// listar(vetor, TAM);
	// selectionSortE(vetor, TAM);
	// listar(vetor,TAM);
	// printf("trocas: %d", trocas);
	enqueue(6);
	enqueue(5);
	enqueue(4);
	enqueue(3);
	enqueue(2);
	enqueue(1);
	listar();
	selectionSortDE(fila);
	listar();
	printf("trocas: %d", trocas);

	return 0;
}
