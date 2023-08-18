/******************************************************************************

Bubble Sort - Alocação Dinâmica

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define size 5

struct Vet{
  int tamanho;
  int dado;
  int primeiro;
  int ultimo
  int numItens; 
}

void criarVetor(struct Vet *v, int t){
    v-> tamanho = t;
    v-> dado = (int*)malloc(v->tamanho*sizeof(int));
    v-> primeiro = 0;
    v-> ultimo = -1;
    v-> numItens = 0;
}

void adicionarItemAoVetor(struct Vet *v, int d){
    if(v-> ultimo == v->tamanho-1);
        v-> ultimo = -1;
        
    v-> ultimo ++;
    v-> dado[v->ultimo] = d;
    f-> numItens ++;
}

void estaVazia(struct Vet *v){
    return (v-> numItens==0);
}

void estaCheia(struct Vet *v){
    return (v-> numItens== f->tamanho);
}

void listarItens(struct Vet *v){
    int cont, i;
    
    for (cont=0, i= v-> primeiro; cont< v-> itens; cont++){
        printf("%d ", v-> dado[i++]);
        
        if(i == v-> tamanho)
            i=0;
    }
    printf("\n\n");
    
}


void bubbleSort (struct Vet *v){
    for(v-> primeiro; v->ultimo == NULL ; v->proximo){
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
    
    int opcao, tam, valor;
	struct Vet vetor;

	// cria o vetor
	printf("\nTamanho do vetor? ");
	scanf("%d",&tam);
	criarVetor(&vetor, tam);
   
   while(1){ 
    //menu
    printf
    ("\n-------------\nBubble Sort\n-------------\n Escolha uma opção\n");
    printf("\nMenu:\n1 - Inserir item ao Vetor\n2 - Listar Vetor\n 3- Ordenar (Bubble Sort) 0 - Sair\n\nEscolha uma opcao: ");
		scanf("%d", &opcao);
	
	switch(opcao){

			case 0: exit(0);

			case 1: // insere elemento
				if (estaCheia(&vetor)){

					printf("\nArray Cheia!!!\n\n");

				}
				else {

					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					adicionarItemAoVetor(&vetor,valor);

				}

				break;

			case 2: // listar
				
					if (estaVazia(&vetor)){

						printf("\nArray vazia!!!\n\n");

					}
					else {

						printf("\nConteudo do vetor:\n");
						listarItens(&vetor);

					}
					break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
   }
  

  return 0;
}
