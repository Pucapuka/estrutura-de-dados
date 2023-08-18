/******************************************************************************

Bubble Sort

*******************************************************************************/
#include <stdio.h>
#define size 5


void bubbleSort (int vet[]){
    int i, j, aux;
    for(i=0; i<size; i++){
        for (j=0; j<size-1; j++){
            if(vet[j]>vet[j+1]){
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
            }
        }
        
    }    
}

int main (){
    
  int i, vetor[size];

  printf
    ("\n-------------\nBubble Sort\n-------------\n Insira os valores do vetor\n");

  for (int i = 0; i < size; i++)
    {
      printf ("%d: ", i + 1);
      scanf ("%d", &vetor[i]);
    }

  printf ("Vetor antes de ordenar: ");
  for (int i = 0; i < size; i++)
    {
      printf ("%d ", vetor[i]);
    }

    bubbleSort(vetor);

  printf ("Vetor ordenado: ");
  for (int i = 0; i < size; i++)
    {
      printf ("%d ", vetor[i]);
    }

  return 0;
}
