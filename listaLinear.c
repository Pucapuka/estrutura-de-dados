/*Implemente uma lista em C que, após inserir ordenadamente 10 elementos, indica em qual posição o 11° deverá ser inserido*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 11 //tamanho máximo 11, pois o enunciado menciona o 11°

Int listaLinear[]; //variável global para a lista linear

//procedimento para inserir ordenadamente os 10 itens
void inserirOrdenadamente10(int lista[], int tamanho, int info){
	int i;
for (i=0; i<tamanho-1; i++){
	if(lista[i]==0){
		lista[i]=info;
}
}
return;
}

//procedimento para inserir o próximo item, indicando qual será a posição
void inserirItem(int lista[], int tamanho, int info){
	int i;
	for (i=0; i<tamanho; i++){
		if (lista[i]==0){
		lista[i]=info;
		printf(“\nO valor %d será inserido na posição %d\n”, lista[i], i);
}
}
return;

//não foi pedido no enunciado, mas é bom ter uma opção remover
void removerItem(int lista[], int tamanho, int key){
	int i;
for (i=0; i<tamanho; i++){
	if (lista[i]==key){
		lista[i]=0;
		printf(“Item %d removido.”, key);
}
}
return;
}

void listar(int lista[], int tamanho){
	for (i=0; i<tamanho; i++){
	if (lista[i]!=0){
		printf(“\n%d\n”,lista[i]);
	}
	printf(“\n”);
	}
}


Int main(){
	Int opcao, valor, chave;
while(1){
		printf(“\nLista Linerar. Escolha uma opção:\n”);
		printf(“\n1. Inserir itens em ordem\n2. Inserir item avulso\n3. Remover item\n4. Listar itens\n0. Sair;\n”)
		scanf(“%d”, &opcao);
		
		switch(opcao){
		case 1:
			printf(“Digite o valor: ”);
			scanf(“%d”, &valor);
			inserirOrdenadamente10(listaLinear, MAX, valor);
break;

case 2:
printf(“Digite o valor: ”);
			scanf(“%d”, &valor);
inserirItem(listaLinear, MAX, valor);
break;
case 3:
	listar(listaLinear, MAX);
	printf(“Qual item você quer remover?”);
	removerItem(listaLinear, MAX, chave);
	break;
case 4:
	listar(listaLinear, MAX);
	break;
case 0:
	exit(0);
		}
	}
return 0;
}
