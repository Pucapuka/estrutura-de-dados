TFila *novo;

//Declaração da variavel que irá a coleção encadeada
TFila *ultimo;

TFila *inicial(){
    //1.alocar memória
    novo = malloc(sizeof(TFila));
    //2.definir o campo next como null
    novo->next = NULL;
    //3. definir o campo prev como null
    novo->prev = NULL;
    //guardar o endereço na sentinela primeiro
    primeiro = novo;
    return novo;
}

TFila *proximos(){
    //1.alocar memória
    novo = malloc(sizeof(TFila));

    //2.definir o campo next como null
    novo->next = NULL;
    //3.encadear
    ultimo = primeiro;
    while (ultimo->next != NULL){
        ultimo = ultimo->next;
    }
    ultimo->next = novo; 
    novo->prev = ultimo; 
    return novo;
}

void listar(){
    TFila * ultimo = primeiro;
    printf("\n\nListando\n\n");
    while (ultimo != NULL){
        printf("%d ", ultimo->dado);
        ultimo = ultimo->next;
    }
}

//melhoria na inteligência do código
TFila *new (){
    if (primeiro == NULL)
       return inicial();
    else
        return proximos();
}
