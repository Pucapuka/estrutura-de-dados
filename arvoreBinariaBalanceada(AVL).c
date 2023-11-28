//crie em C uma árvore binária de busca balanceada(AVL) que use rotações simples e rotações duplas

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq, *dir;
    short altura; //poderia ser tipo int, mas quero usar pouca memória
}No;

//função para criação do no "x"
No *novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 0;
    }else
        printf("\nErro ao alocar nó\n");
    return novo;
}

//função que retorna o maior dentre dois valores a e b (altura de dois nós da árvore)
short maior(short a, short b){
    return (a > b)? a : b;
}

//retorna a altura de um nó ou -1 case ele seja null
short alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}


//calcula e retorna o fator de balanceamento de um nó
short fatorDeBalanceamento(No *no){
    if(no)
        return(alturaDoNo(no->esq) - alturaDoNo(no->dir));
    else
        return 0;
}

//função para rotação à esquerda (r é raiz, f é filho)
No *rotacaoEsq(No *r){
    No *y, *f;

    y = r->dir;
    f = y->esq;
    y -> esq = r;
    r -> dir = f;
    r -> altura = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
    y -> altura = maior(alturaDoNo(y->esq), alturaDoNo(y->dir)) + 1;
    
    return y;
}

//função para rotação à direita
No *rotacaoDir(No *r){
    No *y, *f;
    y = r->esq;
    f = y->dir;
    y->dir = r;
    r->esq = f;
    r->altura = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
    y->altura = maior(alturaDoNo(y->esq), alturaDoNo(y->dir)) + 1;
    
    return y;
}

//Rotações duplas
//Direita-Esquerda
No *rotacaoDirEsq(No *r){
    r->dir = rotacaoDir(r->dir);
    return rotacaoEsq(r);
}

//Esquerda-Direita
No *rotacaoEsqDir(No *r){
    r->esq = rotacaoEsq(r->esq);
    return rotacaoDir(r);
}

/*Função para realizar o balanceamento da árore após uma inserção ou remoção. Ela recebe o nó que está
desbalanceado e retorna a nova raiz após o balanceamento*/
No* balancear(No *raiz){
    short fb = fatorDeBalanceamento(raiz);
    //rotação à esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->dir) <= 0)
        raiz = rotacaoEsq(raiz);
    //rotação à direita
    else if(fb > 1 && fatorDeBalanceamento(raiz->esq) >= 0)
        raiz = rotacaoDir(raiz);
    //rotação dupla à esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->esq) < 0)
        raiz = rotacaoEsqDir(raiz);
    //rotação dupla à direita
    else if(fb < -1 && fatorDeBalanceamento(raiz -> dir) > 0)
        raiz = rotacaoDirEsq(raiz);
    
    return raiz;
}

//função para inserir dados na árvore
No* inserir(No *raiz, int dado){
    if(raiz == NULL){
        return novoNo(dado);
    }else{ //inserção à esquerda ou à direita
        if(dado < raiz->valor)
            raiz->esq = inserir(raiz->esq, dado);
        else if(dado > raiz->valor)
            raiz->dir = inserir(raiz->dir, dado);
        else
            printf("\nInserção não realizada!\nO elemento %d não existe\n", dado);
    }

    //recalcula a altura de todos os nós entre a rauz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir))+1;

    //verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);
    return raiz;
}



//Função para remover um nó
No *remover(No *raiz, int key){
    if(raiz == NULL){
        printf("Valor não encontrado!\n");
        return NULL;
    }else{//procura o nó a ser removido
        if(raiz->valor == key){
            if(raiz->esq == NULL && raiz->dir == NULL){//remove nós sem filhos(folhas)
                free(raiz);
                printf("Elemento folha removido: %d\n", key);
                return NULL;
            }else{//remove os nós com 2 filhos
                if(raiz->esq != NULL && raiz->dir != NULL){
                    No *aux = raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->valor = aux->valor;
                    aux->valor = key;
                    printf("Elemento trocado: %d \n", key);
                    raiz -> esq = remover(raiz->esq, key);
                    return raiz;
                }
                else{//remove nós com 1 filho
                    No *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    printf("Elemento com 1 filho removido = %d \n", key);
                    return aux;
                }
            }
        }else{
            if(key < raiz->valor)
                raiz->esq = remover(raiz->esq, key);
            else
                raiz->dir = remover(raiz->dir, key);
    }
    
    //recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz -> altura = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;

    //verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}

//imprime Árvore Binária Balanceada
void imprimir(No *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->dir, nivel + 1);
        printf("\n\n");
        for(i = 0; i < nivel ; i++)
            printf("\t");
        printf("%d", raiz->valor);
        imprimir(raiz->esq, nivel + 1);
    }
}

int main(){
    int opcao, valor;
    No *raiz = NULL;

    do{
        printf("\n\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 0:
                printf("Saindo...");
                break;
            case 1:
                printf("\tDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("\tDigite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;
            case 3:
                imprimir(raiz, 1);
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    }while(opcao !=0);

return 0;
}
