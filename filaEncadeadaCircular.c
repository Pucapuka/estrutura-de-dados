https://wagnergaspar.com/como-implementar-uma-lista-circular-lista-encadeada-circular/ (para ajudar)

//implementando uma fila encadeada circular

/*
A fila encadeada segue o padrão de FIFO da estrutura de dados. É circular devido o ponteiro da última posição 
apontar para o endereço do primeiro. É encadeada por estar ligada as outras por nós, formando cadeias e ter número 
"ilimitado" de adição de elementos.
*/ 

#include <stdio.h>

/*
primeiro,cria-se uma struct do tipo no,contendo o dado(inteiro no caso) e um ponteiro
do mesmo tipo para apontar o endereço do próximo a posteriori. O nome do tipo dessa- struct será No.
*/ 
typedef struct no{
        int dado;
        struct no *proximo;
    }No;
    
/*
cria-se uma struct para a fila com 2 ponteiros do tipo No para indicar inicio e fim e um inteiro para 
indicar o tamanho. O nome to tipo dessa struct será referido como Fila.
*/    
typedef struct fila{
    No *inicio;
    No *fim;
    int tamanho;
}Fila;


/*
Procedimento para criar uma fila
*/

void criarFila(Fila *fila){ //um ponteiro "fila" que apontará para os endereços dentro da struct Fila
    fila -> inicio = NULL;
    fila -> fim = NULL;
    fila -> tamanho = 0;
}

/*
procedimento para apontar para o primeiro item da fila (como é circular), utilizando dois parâmetros:
um ponteiro, que aponta para a fila, e um valor.
*/
void inserirNoInicio(Fila *fila, int valor){
    No *novo = malloc (sizeof(No)); //novo aponta para o último elemento da fila (o tamanho total do No)

    if (novo){  //se estiver no último da fila
        novo -> dado = valor; //o dado (apontado pelo novo) recebe o valor do parâmetro (para não se perder)
        novo -> proximo = fila -> inicio; //aí, sim,o último elemento pode apontar para o início.
        fila -> inicio = novo; //e novo se torna o início da fila.
        if (fila -> fim == NULL){ //se o fim for nulo (indicando fila vazia),
            fila -> fim = novo; //fim aponta para o novo no
            fila -> fim -> proximo = fila -> inicio //fim aponta para o inicio
            fila -> tamanho ++; //e o "tamanho" da fila aumenta. 
        }else {
            printf("\nErro ao alocar memória!\n");
        }
        
    }
    
}

void inserirNoFim (Fila *fila, int valor){
    
    No *aux, *novo = malloc(sizeof(No)); //dois ponteiros que apontam para o endereço da struct No
    
    if (novo){
        novo -> dado = valor;
        
        if (fila -> inicio == NULL){ //Se o intem inserido for o primeiro
            fila -> inicio = novo;
            fila -> fim = novo;
            fila -> fim -> proximo = fila -> inicio;
        }else{
            fila -> fim -> proximo = novo;
            fila -> fim = novo;
            novo -> proximo = fila -> inicio; //poderia se utilizar fila -> fim -> proximo = fila -> inicio
        }
        fila -> tamanho ++;
    }else{
        printf("\nErro ao alocar memória!\n");
    }
}

//procedimento para enfileirar

void enqueue(Fila *fila, int valor){
    No *aux, *novo = malloc(sizeof(No));
    
    if(novo){
        novo -> dado = valor;
        if (fila -> dado == NULL){
            inserirNoInicio(fila, valor);
        }else if(novo -> dado < fila -> inicio -> dado){
            inserirNoInicio(fila,valor){
            }else{
                aux = fila -> inicio;
                while(aux -> proximo != fila -> inicio && novo -> dado > aux -> proximo -> valor)
                    aux = aux -> proximo;
                if(aux -> proximo == fila -> inicio)
                    inserirNoFim(fila, valor);
                else{
                    novo -> proximo = aux -> proximo;
                    aux -> proximo = novo;
                    lista -> tamanho++;
                }
            }
        }
    }else
        printf("\nErro ao alocar memória!\n");
}


int main()
{
    
   
    
    printf("Hello World");

    return 0;
}
