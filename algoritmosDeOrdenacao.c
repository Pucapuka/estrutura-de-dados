#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void bubbleSort(int array[], int tam){
    int aux, i, j;
    for(i = 0; i < tam; i++){
        for(j=1; j < (tam-i); j++){
            if(array[j-1]>array[j]){
                aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;
            }   
        }
    }
}

void selectionSort(int array[], int tam){
    int aux, min, index, i, j;
    for (i = 0; i < tam-1; i++){
        index = i;
        min = array[i];
        for(j = i+1; j < tam; j++){
            if(array[j]<array[index]){
                index = j;
                min = array[j];
            }
        }
        aux = array[index];
        array[index] = array[i];
        array[i] = aux;

    }

}


void insertionSort(int array[], int tam){
    int i, j, key;

    for (i = 1; i < tam; i++){
        key = array[i];
        j = i-1;
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
}


//trabalhando quick sort

int partition (int v[], int inicio, int fim){
	int pivo = v[fim];
	int menores = inicio - 1;
	int atual, temp;

	for(atual = inicio; atual < fim; atual++){
		if (v[atual] < pivo){
			menores++;
			temp = v[atual];
			v[atual] = v[menores];
			v[menores] = temp;
		}
	}
	int meio = menores + 1;
	
	temp = v[fim];
	v[fim] = v[meio];
	v[meio] = temp;
	return meio;
}

void quickSort(int v[], int inicio, int fim){
	if (inicio >= fim)
		return;

	int meio = partition(v,inicio,fim);
	quickSort(v,inicio, meio - 1);
	quickSort(v,meio + 1, fim);
}


int main(){

    int array[TAM] = {10,9,8,7,6,5,4,3,2,1};
    int i;

    printf("\nListando array antes de ordenar\n");
    for(i=0; i<TAM; i++){
        printf("%d ", array[i]);
    }
    printf("\nListando array após ordenar\n");
    //insertionSort(array, TAM); //para os outros algoritmos
    quickSort(array, 0, TAM-1); //para o quick sort
    for(i=0; i<TAM; i++){
        printf("%d ", array[i]);
    }


    return 0;
}
