#include <stdio.h>
#include<stdlib.h>
#define TAM 5

//variavael global
int fila[TAM];

//enfileirar
void enqueue(int f[], int t, int v){
    int i;
    for (i=0; i<t; i++){
        if (f[i]==0){
            f[i] = v; 
            return;
        }
    }
    printf("\nFila cheia!\n");
}
//desenfileirar
void dequeue(int f[], int t){
     int i;
     for (i=0; i < t-1; i++){
         f[i]=f[i+1];
     }
     f[t-1]=0;
}
//listar

void listar(int f[], int t){
    int i;
    printf("\nValores da fila:\n");
    if (f[0]==0){
        printf("\nFila vazia!\n");
        return;
    }
    for (i=0; i < t; i++){
        if (f[i]==0){
            return;
        }
        printf("%d\n", f[i]);
    }
    return;
}

//buscar
int buscar(int f[], int t, int ch){
    int i;
    for (i=0; i<t; i++){ 
            if (f[i]==ch){
                return i;
            }
        }
    return -1;    
}

int main()
{
    int opcao = 0;
    int valor, chave, posicao;
    
    while(opcao!=5){
        printf("\nEstrutura de dados: Fila. Escolha uma opção:\n");
        printf("\n1. Adicionar item\n2. Retirar item\n3. Listar itens da fila\n4. Buscar\n5. Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        
            case 1:
                printf("\nDigite o Valor: \n");
                scanf("%d", &valor);
                enqueue(fila, TAM, valor);
            break;
        
            case 2:
                dequeue(fila, TAM);
            break;
        
            case 3:
                listar(fila, TAM);
            break;
            
            case 4:
                printf("\nQual o item que você busca?\n");
                scanf("%d", &chave);
                posicao = buscar(fila, TAM, chave);
                if (posicao == -1){
                printf("\nItem não consta na fila.\n");
                }else{
                    printf("\nO item %d está na posição %d\n", chave, posicao);
                }
            break;
            
            case 5:
            exit(0);
        }
    }

    return 0;
}
