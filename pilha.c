#include <stdio.h>
#include<stdlib.h>
#define TAM 5

//variavael global
int pilha[TAM];

//empilhar
void push(int p[], int t, int v){
    int i;
    for (i=0; i<t; i++){
        if (p[i]==0){
            p[i] = v; 
            return;
        }
    }
    printf("\nPilha cheia!\n");
}
//desempilhar
void pop(int p[], int t){
     int i;
     for (i=t-1; i > 0; i--){
        if(p[0]==0){
            printf("pilha vazia!");
            return;
        }
        while(p[i]==0){
            i--;
            }
            p[i]=0;
            return;
        }
        
    }
//listar

void listar(int f[], int t){
    int i;
    printf("\nValores da pilha:\n");
    if (f[0]==0){
        printf("\nPilha vazia!\n");
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
int buscar(int p[], int t, int ch){
    int i;
    for (i=0; i<t; i++){ 
            if (p[i]==ch){
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
        printf("\nEstrutura de dados: Pilha. Escolha uma opção:\n");
        printf("\n1. Adicionar item\n2. Retirar item\n3. Listar itens da fila\n4. Buscar\n5. Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        
            case 1:
                printf("\nDigite o Valor: \n");
                scanf("%d", &valor);
                push(pilha, TAM, valor);
            break;
        
            case 2:
                pop(pilha, TAM);
            break;
        
            case 3:
                listar(pilha, TAM);
            break;
            
            case 4:
                printf("\nQual o item que você busca?\n");
                scanf("%d", &chave);
                posicao = buscar(pilha, TAM, chave);
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
