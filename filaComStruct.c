#include <stdio.h>
#include <stdlib.h>

struct Fila {
	int tamanho;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; 
}; 

void criarFila( struct Fila *f, int t ) { 

	f->tamanho = t;
	f->dados = (float*) malloc (f->tamanho * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 

}

void enqueue(struct Fila *f, int v) {

	if(f->ultimo == f->tamanho-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int dequeue( struct Fila *f ) { // pega o item do comeÃ§o da fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->tamanho)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila estÃ¡ vazia

	return (f->nItens==0);

}

int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila estÃ¡ cheia

	return (f->nItens == f->tamanho);
}

void listarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%.2f\n",f->dados[i++]);

		if (i == f->tamanho)
			i=0;

	}
	printf("\n\n");

}

void main () {

	int opcao, tam;
	float valor;
	struct Fila umaFila;

	// cria a fila
	printf("\nTamanho da fila? ");
	scanf("%d",&tam);
	criarFila(&umaFila, tam);

	// apresenta menu
	while( 1 ){

		printf("\nMenu:\n1 - Inserir item\n2 - Remover item\n3 - Listar Fila\n0 - Sair\n\nEscolha uma opcao: ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // insere elemento
				if (estaCheia(&umaFila)){

					printf("\nFila Cheia!!!\n\n");

				}
				else {

					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					enqueue(&umaFila,valor);

				}

				break;

			case 2: // remove elemento
				if (estaVazia(&umaFila)){

					printf("\nFila vazia!!!\n\n");

				}
				else {

					valor = dequeue(&umaFila);
					printf("\nO item %.0f foi removido com sucesso.\n\n", valor) ; 

				}
				break;

				case 3: // mostrar fila
					if (estaVazia(&umaFila)){

						printf("\nFila vazia!!!\n\n");

					}
					else {

						printf("\nConteudo da fila:\n");
						listarFila(&umaFila);

					}
					break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}
}
