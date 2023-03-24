#include<stdio.h>
#include<stdlib.h>
#define TAM 5

typedef struct{
    int inicio;
    int dados[TAM];
    int fim;
} filaCircular;


void listar(filaCircular f, int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
    printf("%d \n", f.dados[i]);
    }
}

void enqueue(filaCircular f, int tamanho, int chave){
    int i;
    for (i=0; i<tamanho; i++){
        f.dados[i] = chave;
        if(i>=tamanho){
            printf("A fila esta cheia! Digite 0 e pressione enter.");
            return;
        }
    }
}

void dequeue(filaCircular f, int tamanho){
    int i;
    for (i=0; i<tamanho-1; i++){
        f.dados[i]=f.dados[i+1];
    }
    f.dados[tamanho-1]=0;
}

int buscar(filaCircular f, int tamanho, int chave){
    int i;
    for (i = 0; i < tamanho; i++){
        if (f.dados[i] == chave)
            return i;
    }

    return -1;
}

int main(int argc, char**argv, filaCircular fila){
int leitura, chave, posicao, opcao;

    printf("Estudo de estrutura de dados em C \nEscolha uma opcao:\n\n1. Adicionar item\n2. Listar\n3. Tirar item\n4. Buscar item\n5. Sair");
    scanf("%d",&opcao);
    switch(opcao){

        case 1:

            while (1){
            printf("Digite o valor desejado para ser adicionado a fila circular:");
            scanf("%d", &leitura);
            if (leitura == 0){
            break;
            }
            enqeueue(fila, TAM, leitura);
        break;
        }
        case 2:

            listar(fila, TAM);
        break;

        case 3:
            dequeue(fila, TAM);
        break;

        case 4:
            printf("Qual o valor que voce procura?");
            scanf("%d", &chave);
            posicao = buscar(fila, TAM, chave);
            if (posicao==-1){
                printf("Valor nao encontrado!");
            } 
            else{
                printf("O valor esta na posicao %d.\n\n",posicao);
                }
    
        break;

        case 5:
            printf("Saindo...");
        return;
    }

    return(EXIT_SUCCESS);
}
